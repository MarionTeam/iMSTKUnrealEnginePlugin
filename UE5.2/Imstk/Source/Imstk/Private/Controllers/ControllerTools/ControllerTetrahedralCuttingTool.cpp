// Fill out your copyright notice in the Description page of Project Settings.


#include "ControllerTetrahedralCuttingTool.h"
#include "ImstkController.h"
#include "ImstkSubsystem.h"


EControllerObjectType UControllerTetrahedralCuttingTool::Init(UImstkController* Controller, const FControllerToolFilter& ToolFilter)
{
	SubsystemInstance = Controller->GetWorld()->GetGameInstance()->GetSubsystem<UImstkSubsystem>();
	if (Controller->ToolGeomFilter.GeomType != EGeometryType::Plane) {
		SubsystemInstance->LogToUnrealAndImstk("Error: Geometry type not implemented for tetrahedral cutting controllers for " + Controller->GetName(), FColor::Red);
		return EControllerObjectType::Null;
	}

	ControllerComponent = Controller;

	ControllerToolFilter = ToolFilter;

	bIsInitialized = true;

	return EControllerObjectType::PbdToolObject;
}

std::shared_ptr<imstk::SceneObject> UControllerTetrahedralCuttingTool::CreateInteraction(UDynamicalModel* OtherObject)
{
	if (std::shared_ptr<imstk::PbdObject> PBDObject = std::dynamic_pointer_cast<imstk::PbdObject>(OtherObject->ImstkCollidingObject)) {
		std::shared_ptr<imstk::PbdObjectCellRemoval> CellRemoval = std::make_shared<imstk::PbdObjectCellRemoval>(PBDObject);
		TetCuttings.Add(CellRemoval);
		CutObjects.Add(Cast<UPBDModel>(OtherObject));

		SubsystemInstance->LogToUnrealAndImstk("Interaction created between " + FString(OtherObject->ImstkCollidingObject->getName().c_str()) + " and " + FString(ControllerComponent->GetToolObj()->getName().c_str()), FColor::Green);
		return CellRemoval;
	}
	else {
		SubsystemInstance->LogToUnrealAndImstk("Model must be deformable. Tetrahedral cutting interaction could not be created between " + FString(OtherObject->ImstkCollidingObject->getName().c_str()) + " " + FString(ControllerComponent->GetToolObj()->getName().c_str()) + ".", FColor::Red);
		return nullptr;
	}
}


bool UControllerTetrahedralCuttingTool::Execute()
{
	bool bRemovedAny = false;
	if (TetCuttings.Num() > 0) {
		auto ToolGeom = std::dynamic_pointer_cast<imstk::SurfaceMesh>(ControllerComponent->GetToolObj()->getCollidingGeometry());

		for (int j = 0; j < CutObjects.Num(); j++) {
			bool bRemoved = false;
			if (!CutObjects[j] || !CutObjects[j]->PbdObject)
				continue;
			std::shared_ptr<imstk::TetrahedralMesh> TissueMesh = std::dynamic_pointer_cast<imstk::TetrahedralMesh>(CutObjects[j]->PbdObject->getPhysicsGeometry());

			// TODO: hardcoded for plane in this direction
			// Default config of the tool is pointing downwards on y
			const imstk::Mat3d Rot = ToolGeom->getRotation();
			const imstk::Vec3d Forward = (Rot * imstk::Vec3d(0.0, 0.0, 1.0)).normalized();
			const imstk::Vec3d Left = (Rot * imstk::Vec3d(1.0, 0.0, 0.0)).normalized();
			const imstk::Vec3d N = (Rot * imstk::Vec3d(0.0, 1.0, 0.0)).normalized();

			const imstk::Vec3d PlanePos = ToolGeom->getTranslation();
			const imstk::Vec3d PlaneNormal = N;
			const double PlaneHalfWidth = ControllerToolFilter.TetrahedralCuttingToolStruct.PlaneWidth * 0.5;

			std::shared_ptr<imstk::VecDataArray<double, 3>> TissueVerticesPtr = TissueMesh->getVertexPositions();
			std::shared_ptr<imstk::VecDataArray<int, 4>> TissueIndicesPtr = TissueMesh->getCells();
			imstk::VecDataArray<double, 3>& TissueVertices = *TissueVerticesPtr;
			imstk::VecDataArray<int, 4>& TissueIndices = *TissueIndicesPtr;

			// Compute which tets should be removed
			for (int i = 0; i < TissueIndices.size(); i++)
			{
				imstk::Vec4i& tet = TissueIndices[i];
				std::array<imstk::Vec3d, 4> TetVerts;
				TetVerts[0] = TissueVertices[tet[0]];
				TetVerts[1] = TissueVertices[tet[1]];
				TetVerts[2] = TissueVertices[tet[2]];
				TetVerts[3] = TissueVertices[tet[3]];

				if (SplitTest(TetVerts, PlanePos, Left, PlaneHalfWidth, Forward, PlaneHalfWidth, N))
				{
					TetCuttings[j]->removeCellOnApply(i);
					bRemoved = bRemovedAny = true;
				}
			}
			TetCuttings[j]->apply();

			if (bRemoved) {
				CutObjects[j]->UpdateVisualFromTet();
			}
		}
	}
	else {
		SubsystemInstance->LogToUnrealAndImstk("TetCut not assigned", FColor::Red);
	}

	return bRemovedAny;
}

bool UControllerTetrahedralCuttingTool::SplitTest(const std::array<imstk::Vec3d, 4>& InputTetVerts,
	const imstk::Vec3d& PlaneOrigin,
	const imstk::Vec3d& U, const double Width,
	const imstk::Vec3d& V, const double Height,
	const imstk::Vec3d& N)
{
	bool  side[4];
	imstk::Vec3d proj[4];
	int   outCount = 0; // Num vertices that lie in front of plane
	int   inCount = 0; // Num vertices that lie behind plane
	for (int i = 0; i < 4; i++)
	{
		const imstk::Vec3d& vert = InputTetVerts[i];
		proj[i][2] = (vert - PlaneOrigin).dot(N);
		if (proj[i][2] >= 0)
		{
			outCount++;
			side[i] = false;
		}
		if (proj[i][2] < 0)
		{
			side[i] = true;
			inCount++;
		}
	}
	// If all vertices lie on one side then it's not intersecting
	if (outCount == 0 || inCount == 0)
	{
		return false;
	}

	// Next cull by projection of bounds on plane (in a SAT manner)
	imstk::Vec2d min = imstk::Vec2d(IMSTK_DOUBLE_MAX, IMSTK_DOUBLE_MAX);
	imstk::Vec2d max = imstk::Vec2d(IMSTK_DOUBLE_MIN, IMSTK_DOUBLE_MIN);
	for (int i = 0; i < 4; i++)
	{
		// Project onto the basis of the plane
		const imstk::Vec3d& vert = InputTetVerts[i];
		proj[i][0] = (vert - PlaneOrigin).dot(U);
		proj[i][1] = (vert - PlaneOrigin).dot(V);

		min[0] = std::min(proj[i][0], min[0]);
		max[0] = std::max(proj[i][0], max[0]);

		min[1] = std::min(proj[i][1], min[1]);
		max[1] = std::max(proj[i][1], max[1]);
	}

	// If either range is not intersecting then the plane is not within the
	// bounds of the finite plane/quad
	if (!IsIntersect(min[0], max[0], -Width, Width)
		|| !IsIntersect(min[1], max[1], -Height, Height))
	{
		return false;
	}

	return true;
}


bool UControllerTetrahedralCuttingTool::IsIntersect(const double A, const double B, const double C, const double D) {
	return ((A <= D && A >= C) || (C <= B && C >= A)) ? true : false;
}

void UControllerTetrahedralCuttingTool::UnInit() {
	Super::UnInit();
	for (auto Cut : TetCuttings)
		Cut.reset();
	TetCuttings.Empty();
	CutObjects.Empty();
}