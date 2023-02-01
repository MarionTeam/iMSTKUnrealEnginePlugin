// Fill out your copyright notice in the Description page of Project Settings.


#include "ControllerCuttingTool.h"
#include "ImstkController.h"
#include "ImstkSubsystem.h"

EControllerObjectType UControllerCuttingTool::Init(UImstkController* Controller, const FControllerToolFilter& ToolFilter)
{
	SubsystemInstance = Controller->GetWorld()->GetGameInstance()->GetSubsystem<UImstkSubsystem>();
	if (Controller->ToolGeomFilter.GeomType != EGeometryType::SurfaceMesh) {
		SubsystemInstance->LogToUnrealAndImstk("Error: Geometry type not implemented for cutting controllers for " + Controller->GetName());
		return EControllerObjectType::Null;
	}

	ControllerComponent = Controller;

	ControllerToolFilter = ToolFilter;

	bIsInitialized = true;

	return EControllerObjectType::PbdToolObject;
}

std::shared_ptr<imstk::SceneObject> UControllerCuttingTool::CreateInteraction(UDynamicalModel* OtherObject)
{
	if (std::shared_ptr<imstk::PbdObject> PBDObject = std::dynamic_pointer_cast<imstk::PbdObject>(OtherObject->ImstkCollidingObject)) {
		std::shared_ptr<imstk::PbdObjectCutting> Cutting = std::make_shared<imstk::PbdObjectCutting>(PBDObject, ControllerComponent->GetToolObj());
		//if (PBD->bCleanMesh) {
		//	/*std::shared_ptr<imstk::SurfaceMeshCut> SMC = std::make_shared<imstk::SurfaceMeshCut>();
		//	SMC->setInputMesh(std::dynamic_pointer_cast<imstk::SurfaceMesh>(PBD->PbdObject->getVisualGeometry()));
		//	SMC->setCutGeometry(Controller->GetToolObj()->getCollidingGeometry());
		//	SMC->setEpsilon(Controller->CutEpsilon);
		//	SMC->update();
		//	Controller->AddCutting(SMC, PBD->PbdObject);*/
		//	Controller->AddCutObject(PBD->PbdObject);
		//}
		Cutting->setEpsilon(ControllerToolFilter.CuttingToolStruct.CutEpsilon);
		Cuttings.Add(Cutting);

		SubsystemInstance->LogToUnrealAndImstk("Interaction created between " + FString(OtherObject->ImstkCollidingObject->getName().c_str()) + " and " + FString(ControllerComponent->GetToolObj()->getName().c_str()));
		return Cutting;
	}
	else {
		SubsystemInstance->LogToUnrealAndImstk("Model must be deformable. Cutting interaction could not be created between " + FString(OtherObject->ImstkCollidingObject->getName().c_str()) + " " + FString(ControllerComponent->GetToolObj()->getName().c_str()) + ".");
		return nullptr;
	}
}


bool UControllerCuttingTool::Execute()
{
	bool Cut = false;
	if (Cuttings.Num() > 0) {
		if (ControllerComponent->ToolGeomFilter.GeomType = EGeometryType::SurfaceMesh) {
			for (std::shared_ptr<imstk::PbdObjectCutting> Cutting : Cuttings) {
				Cutting->apply();
				Cut = true;
			}

			//for (std::shared_ptr<imstk::PbdObject> Obj : CutObjects) {
			//	std::shared_ptr<imstk::PbdModel> pbdModel = Obj->getPbdModel();

			//	imstk::SurfaceMeshCut SMC;
			//	auto SurfMesh = std::dynamic_pointer_cast<imstk::SurfaceMesh>(Obj->getVisualGeometry());

			//	SMC.setInputMesh(std::dynamic_pointer_cast<imstk::SurfaceMesh>(SurfMesh));
			//	SMC.setCutGeometry(ToolObj->getCollidingGeometry());
			//	SMC.setEpsilon(CutEpsilon);
			//	SMC.update();
			//	std::shared_ptr<imstk::SurfaceMesh> NewMesh = SMC.getOutputMesh();

			//	SurfMesh->setInitialVertexPositions(std::make_shared<imstk::VecDataArray<double, 3>>(*NewMesh->getInitialVertexPositions()));
			//	SurfMesh->setVertexPositions(std::make_shared<imstk::VecDataArray<double, 3>>(*NewMesh->getVertexPositions()));
			//	SurfMesh->setTriangleIndices(std::make_shared<imstk::VecDataArray<int, 3>>(*NewMesh->getTriangleIndices()));
			//	SurfMesh->postModified();

			//	// Remap the new geometry
			//	std::shared_ptr<imstk::PointwiseMap> Map = std::make_shared<imstk::PointwiseMap>(std::dynamic_pointer_cast<imstk::SurfaceMesh>(Obj->getPhysicsGeometry()), std::dynamic_pointer_cast<imstk::SurfaceMesh>(Obj->getVisualGeometry()));
			//	Map->setTolerance(0.00000001 * UMathUtil::GetScale());
			//	Map->compute();
			//	Obj->setPhysicsToVisualMap(Map);
			//	Obj->setCollidingToVisualMap(Map);
			//}

			//for (const TPair<std::shared_ptr<imstk::SurfaceMeshCut>, std::shared_ptr<imstk::PbdObject> >& CuttingPair : VisualMeshCuttings)
			//{
			//	CuttingPair.Key->update();
			//	CuttingPair.Value->setVisualGeometry(CuttingPair.Key->getOutputMesh());

			//	// Remap the new geometry
			//	std::shared_ptr<imstk::PointwiseMap> Map = std::make_shared<imstk::PointwiseMap>(CuttingPair.Value->getCollidingGeometry(), CuttingPair.Value->getVisualGeometry());
			//	Map->setTolerance(0.00000001 * UMathUtil::GetScale());
			//	Map->update();
			//	//std::shared_ptr<imstk::GeometryMap> Map = PbdObject->getPhysicsToVisualMap();
			//	//Map->update();
			//	CuttingPair.Value->setPhysicsToVisualMap(Map);
			//	CuttingPair.Value->setCollidingToVisualMap(Map);
			//}
		}
	}
	else {
		SubsystemInstance->LogToUnrealAndImstk("Cutting not assigned");
	}
	return Cut;
}

void UControllerCuttingTool::UnInit() {
	Super::UnInit();
	for (auto Cut : Cuttings)
		Cut.reset();
	Cuttings.Empty();
}
