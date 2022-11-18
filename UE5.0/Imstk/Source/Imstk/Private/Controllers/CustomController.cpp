// Fill out your copyright notice in the Description page of Project Settings.

#include "CustomController.h"
#include "MathUtil.h"
#include "ImstkSubsystem.h"
#include "RBDModel.h"
#include "imstkLineMesh.h"
#include "imstkRigidBodyModel2.h"
#include "imstkRbdConstraint.h"
#include "imstkCollisionUtils.h"

#include "imstkGeometryUtilities.h"
#include "imstkPbdModel.h"

#include "Materials/MaterialInstanceDynamic.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "GameFramework/PlayerController.h"

#include "imstkPointwiseMap.h"
#include "imstkPbdConstraintContainer.h"
#include "imstkPbdSolver.h"

#include "imstkTetrahedralMesh.h"

#include "DrawDebugHelpers.h"

void UCustomController::PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent)
{
	FName PropertyName = (PropertyChangedEvent.Property != NULL) ? PropertyChangedEvent.Property->GetFName() : NAME_None;

	if (PropertyName == GET_MEMBER_NAME_CHECKED(UCustomController, Preset)) {
		switch (Preset)
		{
		case 0:
			ToolGeomFilter.GeomType = EGeometryType::Capsule;
			ToolGeomFilter.CapsuleStruct.Radius = 12.5;
			ToolGeomFilter.CapsuleStruct.Length = 50;
			ToolType = EToolType::CollidingTool;
			break;
		case 1:
			ToolGeomFilter.GeomType = EGeometryType::Capsule;
			ToolGeomFilter.CapsuleStruct.Radius = 12.5;
			ToolGeomFilter.CapsuleStruct.Length = 50;
			ToolType = EToolType::GraspingTool;
			GraspStiffness = 1.0;
			GraspType = EGraspType::CellGrasp;
			//GraspCollisionType = ECollisionInteractionType::PointSetToCapsuleCD;
			bForceTool = true;
			break;
		case 2:
			ToolGeomFilter.GeomType = EGeometryType::SurfaceMesh;
			ToolType = EToolType::CuttingTool;
			break;
		case 3:
			ToolGeomFilter.GeomType = EGeometryType::LineMesh;
			ToolGeomFilter.LineMeshStruct.Vertices.Empty();
			ToolGeomFilter.LineMeshStruct.Vertices.Add(FVector(0, 0, 0));
			ToolGeomFilter.LineMeshStruct.Vertices.Add(FVector(0, 0, 50));
			ToolType = EToolType::StitchingTool;
			break;
		case 4:
			ToolGeomFilter.GeomType = EGeometryType::SurfaceMesh;
			ToolType = EToolType::LevelSetTool;
			bForceTool = true;
			SpringForce = 1000;
			DamperForce = 10;
			bIgnoreAngularForce = true;
			break;
		default:
			return;
		}
	}
}
UCustomController::UCustomController() : UImstkController()
{
	ToolGeomFilter.GeomType = EGeometryType::Capsule;
	ToolGeomFilter.CapsuleStruct.Radius = 12.5;
	ToolGeomFilter.CapsuleStruct.Length = 50;
	ToolType = EToolType::CollidingTool;
}

// Called before Begin Play
void UCustomController::InitializeComponent()
{
	Super::InitializeComponent();

	// Turn off ticking for this component
	if (GetWorld() && GetWorld()->GetGameInstance())
		this->SetComponentTickEnabled(false);
}

void UCustomController::InitController()
{
	Super::InitController();

	if (ToolGeomFilter.GeomType != EGeometryType::Sphere && ToolGeomFilter.GeomType != EGeometryType::Capsule &&
		ToolGeomFilter.GeomType != EGeometryType::LineMesh && ToolGeomFilter.GeomType != EGeometryType::SurfaceMesh &&
		ToolGeomFilter.GeomType != EGeometryType::Plane) {
		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "Error: Geometry type not implemented for controllers. Please select sphere, capsule, line mesh or surface mesh");
		UE_LOG(LogTemp, Error, TEXT("Error: Geometry type not implemented for controllers. Please select sphere, capsule, line mesh or surface mesh"));;
		//SubsystemInstance->AllControllers.Remove(this); // This causes an error since it removes from the for loop it resides in
		return;
	}

	// Check if the selected geometry type matches the tool type
	if ((ToolType == EToolType::GraspingTool && (ToolGeomFilter.GeomType != EGeometryType::Sphere && ToolGeomFilter.GeomType != EGeometryType::Capsule)) ||
		(ToolType == EToolType::StitchingTool && ToolGeomFilter.GeomType != EGeometryType::LineMesh) ||
		(ToolType == EToolType::CuttingTool && ToolGeomFilter.GeomType != EGeometryType::SurfaceMesh) ||
		(ToolType == EToolType::TetrahedralCuttingTool && ToolGeomFilter.GeomType != EGeometryType::Plane)) {
		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "Error: Controller type to Geometry mismatch");
		UE_LOG(LogTemp, Error, TEXT("Error: Controller type to Geometry mismatch"));;
		//SubsystemInstance->AllControllers.Remove(this); // This causes an error since it removes from the for loop it resides in
		return;
	}

	std::shared_ptr<imstk::Geometry> ToolGeom = ToolGeomFilter.Init(this);

	// Only scale for surface mesh tools
	// TODO: if there are multiple static meshes attached to controller it will only get the first
	if (ToolGeomFilter.GeomType == EGeometryType::SurfaceMesh) {
		TArray<USceneComponent*> Components;
		GetChildrenComponents(false, Components);
		for (USceneComponent* Comp : Components) {
			if (Comp->IsA(UStaticMeshComponent::StaticClass())) {
				MeshComp = (UStaticMeshComponent*)Comp;
				ToolGeom->scale(UMathUtil::ToImstkVec3d(MeshComp->GetComponentScale(), false), imstk::Geometry::TransformType::ApplyToData);
				break;
			}
		}
	}
	if (ToolType != EToolType::TetrahedralCuttingTool) {
		ToolObj = std::make_shared<imstk::RigidObject2>(TCHAR_TO_UTF8(*this->GetName()));
		ToolObj->setVisualGeometry(ToolGeom);
		ToolObj->setCollidingGeometry(ToolGeom);
		ToolObj->setPhysicsGeometry(ToolGeom);

		// Configure the model
		std::shared_ptr<imstk::RigidBodyModel2> RbdModel = std::make_shared<imstk::RigidBodyModel2>();
		RbdModel->getConfig()->m_gravity = imstk::Vec3d::Zero();
		RbdModel->getConfig()->m_maxNumIterations = MaxNumIterations;
		RbdModel->getConfig()->m_velocityDamping = VelocityDamping;
		RbdModel->getConfig()->m_angularVelocityDamping = AngularVelocityDamping;
		RbdModel->getConfig()->m_maxNumConstraints = MaxNumConstraints;

		RigidToolObj = std::dynamic_pointer_cast<imstk::RigidObject2>(ToolObj);

		RigidToolObj->setDynamicalModel(RbdModel);

		RigidToolObj->getRigidBody()->m_mass = Mass;
		RigidToolObj->getRigidBody()->m_intertiaTensor = imstk::Mat3d::Identity() * InertiaTensorMultiplier;
		RigidToolObj->getRigidBody()->setInitPos(UMathUtil::ToImstkVec3d(GetComponentLocation(), true));

		if (MeshComp)
			RigidToolObj->getRigidBody()->setInitOrientation(UMathUtil::ToImstkQuat(MeshComp->GetComponentRotation().Quaternion()));
		else
			RigidToolObj->getRigidBody()->setInitOrientation(UMathUtil::ToImstkQuat(GetComponentRotation().Quaternion()));

		if (GhostMaterial && GhostSceneComp) {
			auto* MaterialInstance = UMaterialInstanceDynamic::Create(GhostMaterial, GhostMaterial);
			for (UStaticMeshComponent* Mesh : GhostMeshes)
				Mesh->SetMaterial(0, MaterialInstance);
		}
	}
	else {
		// TODO: this is hard coded for only tissue cut with a plane

		std::shared_ptr<imstk::Plane> PlaneGeom = std::dynamic_pointer_cast<imstk::Plane>(ToolGeom);
		PlaneGeom->setWidth(Super::PlaneWidth);
		std::shared_ptr<imstk::SurfaceMesh> SurfGeom = imstk::GeometryUtils::toSurfaceMesh(PlaneGeom);

		PbdToolObj = std::make_shared<imstk::PbdObject>(TCHAR_TO_UTF8(*this->GetName()));
		ToolObj = PbdToolObj;

		ToolObj->setVisualGeometry(SurfGeom);
		ToolObj->setCollidingGeometry(SurfGeom);
		ToolObj->setPhysicsGeometry(SurfGeom);
		ToolObj->setDynamicalModel(SubsystemInstance->PbdModel);

		PbdToolObj->getPbdBody()->setRigid(
			imstk::Vec3d(0.0, 0.0, 0.0),         // Position
			Mass,                                // Mass
			imstk::Quatd::Identity(),            // Orientation
			imstk::Mat3d::Identity() * 1);       // Inertia
	}

	SubsystemInstance->ActiveScene->addSceneObject(ToolObj);

	Super::bIsInitialized = true;
}

FVector UCustomController::UpdateImstkPosRot(FVector WorldPos, FQuat Orientation, FVector WorldDir, UDynamicalModel* PlaneActor)
{
	imstk::Vec3d Position = UMathUtil::ToImstkVec3d(WorldPos, true);
	if (!bForceTool) {
		if (PlaneActor) {
			std::shared_ptr<imstk::Plane> Plane = std::dynamic_pointer_cast<imstk::Plane>(PlaneActor->GetImstkGeometry());

			if (Plane) {
				imstk::Vec3d IntersectPoint = imstk::Vec3d::Zero();
				if (imstk::CollisionUtils::testRayToPlane(UMathUtil::ToImstkVec3d(WorldPos, true), UMathUtil::ToImstkVec3d(WorldDir, true), Plane->getPosition(), Plane->getNormal(), IntersectPoint))
				{
					Position = IntersectPoint;
				}
				else {
					// No hit for ray
					return FVector::ZeroVector;
				}
			}
			else {
				//ERROR

				Super::bIsInitialized = false;
				return FVector::ZeroVector;
			}
		}

		// TODO: Should probably change to edit the position and orientation rather than creating new each time
		if (RigidToolObj) {
			RigidToolObj->getRigidBody()->m_orientation = new imstk::Quatd(UMathUtil::ToImstkQuat(Orientation));
			RigidToolObj->getRigidBody()->m_pos = new imstk::Vec3d(Position);
		}
		else if (PbdToolObj) {
			(*PbdToolObj->getPbdBody()->vertices)[0] = Position;
			(*PbdToolObj->getPbdBody()->orientations)[0] = UMathUtil::ToImstkQuat(Orientation);
		}
	}
	else
	{
		if (GhostSceneComp) {
			GhostSceneComp->SetWorldLocation(WorldPos);
			GhostSceneComp->SetWorldRotation(Orientation);
		}

		if (bIgnoreAngularForce) {
			// TODO: update this to the force movement version in suturing controller
			imstk::Vec3d fS = (UMathUtil::ToImstkVec3d(WorldPos, true) - RigidToolObj->getRigidBody()->getPosition()) * SpringForce; // Spring force
			imstk::Vec3d fD = -RigidToolObj->getRigidBody()->getVelocity() * DamperForce; // Spring damping
			(*RigidToolObj->getRigidBody()->m_force) += (fS + fD);

			RigidToolObj->getRigidBody()->m_orientation = new imstk::Quatd(UMathUtil::ToImstkQuat(Orientation));
		}
		else {
			const imstk::Vec3d& CurrPos = RigidToolObj->getRigidBody()->getPosition();
			const imstk::Quatd& CurrOrientation = RigidToolObj->getRigidBody()->getOrientation();
			const imstk::Vec3d& CurrVelocity = RigidToolObj->getRigidBody()->getVelocity();
			const imstk::Vec3d& CurrAngularVelocity = RigidToolObj->getRigidBody()->getAngularVelocity();
			imstk::Vec3d& CurrForce = *RigidToolObj->getRigidBody()->m_force;
			imstk::Vec3d& CurrTorque = *RigidToolObj->getRigidBody()->m_torque;

			const imstk::Vec3d& DevicePos = UMathUtil::ToImstkVec3d(WorldPos, true);
			const imstk::Quatd& DeviceOrientation = UMathUtil::ToImstkQuat(Orientation);
			const imstk::Vec3d& DeviceOffset = imstk::Vec3d(0.0, 0.0, 0.0);

			// If using critical damping automatically compute kd
			{
				//const double Mass = ToolObj->getRigidBody()->getMass();
				const double MaxLinearKs = UMathUtil::ToImstkVec3d(LinearKs, true).maxCoeff();
				LinearKd = 2.0 * std::sqrt(Mass * MaxLinearKs);

				const imstk::Mat3d Inertia = RigidToolObj->getRigidBody()->getIntertiaTensor();
				// Currently kd is not a 3d vector though it could be.
				// So here we make an approximation. Either:
				//  - Use one colums eigenvalue (maxCoeff)
				//  - cbrt(eigenvalue0*eigenvalue1*eigenvalue2). (det)
				// Both may behave weird on anistropic Inertia tensors
				//const double InertiaScale = Inertia.eigenvalues().real().maxCoeff();
				const double InertiaScale = std::cbrt(Inertia.determinant());
				const double MaxAngularKs = UMathUtil::ToImstkVec3d(AngularKs, true).maxCoeff();
				AngularKd = 2.0 * std::sqrt(InertiaScale * MaxAngularKs);
			}

			// If kd > 2 * sqrt(Mass * ks); The system is overdamped (may be intentional)
			// If kd < 2 * sqrt(Mass * ks); The system is underdamped (never intended)

			// Uses non-relative force
			{
				// Compute force
				imstk::Vec3d SForce = UMathUtil::ToImstkVec3d(LinearKs, true).cwiseProduct(DevicePos - CurrPos - DeviceOffset);
				imstk::Vec3d DForce = LinearKd * (-CurrVelocity - CurrAngularVelocity.cross(DeviceOffset));
				imstk::Vec3d Force = SForce + DForce;

				// Computer torque
				const imstk::Quatd Dq = DeviceOrientation * CurrOrientation.inverse();
				const imstk::Rotd  AngleAxes = imstk::Rotd(Dq);
				AngularSpringForce = DeviceOffset.cross(Force) + UMathUtil::ToImstkVec3d(AngularKs, true).cwiseProduct(AngleAxes.axis() * AngleAxes.angle());
				AngularDamperForce = AngularKd * -CurrAngularVelocity;
				imstk::Vec3d Torque = AngularSpringForce + AngularDamperForce;

				CurrForce += Force * ForceScale;
				CurrTorque += Torque * ForceScale;
			}
		}

	}


	if (GEngine && bPrintImstkPos) {
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, UMathUtil::ToUnrealFVec(RigidToolObj->getRigidBody()->getPosition(), true).ToString());
	}

	return UMathUtil::ToUnrealFVec(Position, true);
}

void UCustomController::UpdateUnrealPosRot()
{
	// Since mesh comp and controller can have different orientations, only orient the controller to update and keep rotation offset for the mesh component
	if (MeshComp) {
		MeshComp->SetWorldLocationAndRotation(UMathUtil::ToUnrealFVec(RigidToolObj->getRigidBody()->getPosition(), true), UMathUtil::ToUnrealFQuat(RigidToolObj->getRigidBody()->getOrientation()).Rotator());
		return;
	}
	if (RigidToolObj)
		SetWorldLocationAndRotation(UMathUtil::ToUnrealFVec(RigidToolObj->getRigidBody()->getPosition(), true), UMathUtil::ToUnrealFQuat(RigidToolObj->getRigidBody()->getOrientation()));
	else if(PbdToolObj)
		SetWorldLocationAndRotation(UMathUtil::ToUnrealFVec((*PbdToolObj->getPbdBody()->vertices)[0], true), UMathUtil::ToUnrealFQuat((*PbdToolObj->getPbdBody()->orientations)[0]));
	/*GetOwner()->SetActorLocation(UMathUtil::ToUnrealFVec(ToolObj->getRigidBody()->getPosition(), true));
	GetOwner()->SetActorRotation(UMathUtil::ToUnrealFQuat(ToolObj->getRigidBody()->getOrientation()));*/
}

void UCustomController::MoveControllerToLocation(FVector Location, FQuat Orientation, bool bUpdateUnrealPosRot)
{
	if (!Super::bIsInitialized)
		return;

	UpdateImstkPosRot(Location, Orientation);
	if (bUpdateUnrealPosRot)
		UpdateUnrealPosRot();
}

FVector UCustomController::MoveControllerToRaycastOnPlane(FVector RayStart, FVector RayDir, FQuat Orientation, UDynamicalModel* PlaneActor, bool bUpdateUnrealPosRot)
{
	FVector ImstkPos = UpdateImstkPosRot(RayStart, Orientation, RayDir, PlaneActor);
	if (bUpdateUnrealPosRot)
		UpdateUnrealPosRot();

	return ImstkPos;
}


void UCustomController::BeginVertexGrasp()
{
	if (ToolPickings.Num() > 0) {
		if (GraspType == EGraspType::VertexGrasp) {
			for (std::shared_ptr<imstk::PbdObjectGrasping> ToolPicking : ToolPickings) {
				ToolPicking->beginVertexGrasp(std::dynamic_pointer_cast<imstk::AnalyticalGeometry>(ToolObj->getCollidingGeometry()));
			}
		}
	}
	else {
		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "ToolPicking not assigned");
		UE_LOG(LogTemp, Error, TEXT("ToolPicking not assigned"));
	}
}

void UCustomController::BeginCellGrasp()
{
	if (ToolPickings.Num() > 0) {
		if (GraspType == EGraspType::CellGrasp) {
			for (std::shared_ptr<imstk::PbdObjectGrasping> ToolPicking : ToolPickings) {
				ToolPicking->beginCellGrasp(std::dynamic_pointer_cast<imstk::AnalyticalGeometry>(ToolObj->getCollidingGeometry()));
			}
		}
	}
	else {
		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "ToolPicking not assigned");
		UE_LOG(LogTemp, Error, TEXT("ToolPicking not assigned"));
	}
}

void UCustomController::BeginRayPointGrasp(FVector RayStart, FVector RayDir)
{
	if (ToolPickings.Num() > 0) {
		if (GraspType == EGraspType::RayPointGrasp) {
			for (std::shared_ptr<imstk::PbdObjectGrasping> ToolPicking : ToolPickings) {
				ToolPicking->beginRayPointGrasp(std::dynamic_pointer_cast<imstk::AnalyticalGeometry>(ToolObj->getCollidingGeometry()), UMathUtil::ToImstkVec3d(RayStart, true), UMathUtil::ToImstkVec3d(RayDir, true));
			}
		}
	}
	else {
		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "ToolPicking not assigned");
		UE_LOG(LogTemp, Error, TEXT("ToolPicking not assigned"));
	}
}

void UCustomController::EndGrasp()
{
	if (ToolPickings.Num() > 0) {
		for (std::shared_ptr<imstk::PbdObjectGrasping> ToolPicking : ToolPickings) {
			ToolPicking->endGrasp();
		}
	}
}

void UCustomController::BeginStitch()
{
	if (Stitchings.Num() > 0) {
		if (ToolGeomFilter.GeomType = EGeometryType::LineMesh) {
			std::shared_ptr<imstk::LineMesh> ToolGeom = std::dynamic_pointer_cast<imstk::LineMesh>(ToolObj->getCollidingGeometry());

			for (std::shared_ptr<imstk::PbdObjectStitching> Stitching : Stitchings) {
				for (int i = 1; i < ToolGeom->getNumVertices(); i++) {
					Stitching->beginStitch(ToolGeom->getVertexPosition(i - 1), (ToolGeom->getVertexPosition(i) - ToolGeom->getVertexPosition(i - 1)).normalized(), (ToolGeom->getVertexPosition(i) - ToolGeom->getVertexPosition(i - 1)).norm());
				}
			}
		}
	}
}

void UCustomController::BeginCut()
{
	if (Cuttings.Num() > 0) {
		if (ToolGeomFilter.GeomType = EGeometryType::SurfaceMesh) {
			for (std::shared_ptr<imstk::PbdObjectCutting> Cutting : Cuttings) {
				Cutting->apply();
			}

			for (std::shared_ptr<imstk::PbdObject> Obj : CutObjects) {
				std::shared_ptr<imstk::PbdModel> pbdModel = Obj->getPbdModel();

				imstk::SurfaceMeshCut SMC;
				auto SurfMesh = std::dynamic_pointer_cast<imstk::SurfaceMesh>(Obj->getVisualGeometry());

				SMC.setInputMesh(std::dynamic_pointer_cast<imstk::SurfaceMesh>(SurfMesh));
				SMC.setCutGeometry(ToolObj->getCollidingGeometry());
				SMC.setEpsilon(CutEpsilon);
				SMC.update();
				std::shared_ptr<imstk::SurfaceMesh> NewMesh = SMC.getOutputMesh();

				SurfMesh->setInitialVertexPositions(std::make_shared<imstk::VecDataArray<double, 3>>(*NewMesh->getInitialVertexPositions()));
				SurfMesh->setVertexPositions(std::make_shared<imstk::VecDataArray<double, 3>>(*NewMesh->getVertexPositions()));
				SurfMesh->setTriangleIndices(std::make_shared<imstk::VecDataArray<int, 3>>(*NewMesh->getTriangleIndices()));
				SurfMesh->postModified();

				// Remap the new geometry
				std::shared_ptr<imstk::PointwiseMap> Map = std::make_shared<imstk::PointwiseMap>(std::dynamic_pointer_cast<imstk::SurfaceMesh>(Obj->getPhysicsGeometry()), std::dynamic_pointer_cast<imstk::SurfaceMesh>(Obj->getVisualGeometry()));
				Map->setTolerance(0.00000001 * UMathUtil::GetScale());
				Map->compute();
				Obj->setPhysicsToVisualMap(Map);
				Obj->setCollidingToVisualMap(Map);
			}

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
}

bool UCustomController::BeginTetrahedralCut()
{
	auto ToolGeom = std::dynamic_pointer_cast<imstk::SurfaceMesh>(ToolObj->getCollidingGeometry());
	bool bRemovedAny = false;

	for (int j = 0; j < TetObjects.Num(); j++) {
		bool bRemoved = false;
		auto TissueMesh = std::dynamic_pointer_cast<imstk::TetrahedralMesh>(TetObjects[j]->PbdObject->getPhysicsGeometry());

		// TODO: hardcoded for plane in this direction
		// Default config of the tool is pointing downwards on y
		const imstk::Mat3d Rot = ToolGeom->getRotation();
		const imstk::Vec3d Forward = (Rot * imstk::Vec3d(0.0, 0.0, 1.0)).normalized();
		const imstk::Vec3d Left = (Rot * imstk::Vec3d(1.0, 0.0, 0.0)).normalized();
		const imstk::Vec3d N = (Rot * imstk::Vec3d(0.0, 1.0, 0.0)).normalized();

		const imstk::Vec3d PlanePos = ToolGeom->getTranslation();
		const imstk::Vec3d PlaneNormal = N;
		const double PlaneHalfWidth = Super::PlaneWidth * 0.5;

		std::shared_ptr<imstk::VecDataArray<double, 3>> TissueVerticesPtr = TissueMesh->getVertexPositions();
		std::shared_ptr<imstk::VecDataArray<int, 4>> TissueIndicesPtr = TissueMesh->getCells();
		imstk::VecDataArray<double, 3>& TissueVertices = *TissueVerticesPtr;
		imstk::VecDataArray<int, 4>& TissueIndices = *TissueIndicesPtr;

		// Compute which tets should be removed
		//std::unordered_set<int> RemovedTets;
		for (int i = 0; i < TissueIndices.size(); i++)
		{
			imstk::Vec4i& tet = TissueIndices[i];
			std::array<imstk::Vec3d, 4> TetVerts;
			TetVerts[0] = TissueVertices[tet[0]];
			TetVerts[1] = TissueVertices[tet[1]];
			TetVerts[2] = TissueVertices[tet[2]];
			TetVerts[3] = TissueVertices[tet[3]];

			if (SplitTest(TetVerts, PlanePos, Left, PlaneHalfWidth, Forward, PlaneHeight, N))
			{
				TetCuttings[j]->removeCellOnApply(i);
				bRemoved = true;
				bRemovedAny = true;
			}
		}
		TetCuttings[j]->apply();

		if (bRemoved) {
			TetObjects[j]->UpdateVisualFromTet();
		}
	}

	return bRemovedAny;
}

bool UCustomController::SplitTest(const std::array<imstk::Vec3d, 4>& InputTetVerts,
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

bool UCustomController::IsIntersect(const double A, const double B, const double C, const double D) {
	return ((A <= D && A >= C) || (C <= B && C >= A)) ? true : false;
}

FVector UCustomController::GetControlleriMSTKPosition()
{
	return UMathUtil::ToUnrealFVec(RigidToolObj->getRigidBody()->getPosition(), true);
}

void UCustomController::SetGhostComponents(USceneComponent* SceneComponent, TArray<UStaticMeshComponent*> StaticMeshComponents)
{
	GhostSceneComp = SceneComponent;
	GhostMeshes = StaticMeshComponents;
}

void UCustomController::UnInit()
{
	Super::UnInit();
	RigidToolObj.reset();
}
