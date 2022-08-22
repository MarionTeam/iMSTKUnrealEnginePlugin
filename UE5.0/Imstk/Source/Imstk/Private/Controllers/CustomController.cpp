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

#include "DrawDebugHelpers.h"

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
		ToolGeomFilter.GeomType != EGeometryType::LineMesh && ToolGeomFilter.GeomType != EGeometryType::SurfaceMesh) {
		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "Error: Geometry type not implemented for controllers. Please select sphere, capsule, line mesh or surface mesh");
		UE_LOG(LogTemp, Error, TEXT("Error: Geometry type not implemented for controllers. Please select sphere, capsule, line mesh or surface mesh"));;
		//SubsystemInstance->AllControllers.Remove(this); // This causes an error since it removes from the for loop it resides in
		return;
	}

	// Check if the selected geometry type matches the tool type
	if ((ToolType == EToolType::GraspingTool && (ToolGeomFilter.GeomType != EGeometryType::Sphere && ToolGeomFilter.GeomType != EGeometryType::Capsule)) ||
		(ToolType == EToolType::StitchingTool && ToolGeomFilter.GeomType != EGeometryType::LineMesh) ||
		(ToolType == EToolType::CuttingTool && ToolGeomFilter.GeomType != EGeometryType::SurfaceMesh)) {
		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "Error: Controller type to Geometry mismatch");
		UE_LOG(LogTemp, Error, TEXT("Controller type to Geometry mismatch"));;
		//SubsystemInstance->AllControllers.Remove(this); // This causes an error since it removes from the for loop it resides in
		return;
	}

	std::shared_ptr<imstk::Geometry> ToolGeom = ToolGeomFilter.Init(this);

	// Only scale for surface mesh tools
	// TODO: if there are multiple static meshes attached to controller it will only get the first
	if (ToolGeomFilter.GeomType == EGeometryType::SurfaceMesh) {
		TArray<USceneComponent*> Components;
		GetChildrenComponents(true, Components);
		for (USceneComponent* Comp : Components) {
			if (MeshComp = (UStaticMeshComponent*)Comp)
				ToolGeom->scale(UMathUtil::ToImstkVec3(MeshComp->GetComponentScale(), false), imstk::Geometry::TransformType::ApplyToData);
			break;
		}
	}

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
	ToolObj->setDynamicalModel(RbdModel);

	ToolObj->getRigidBody()->m_mass = Mass;
	ToolObj->getRigidBody()->m_intertiaTensor = imstk::Mat3d::Identity() * InertiaTensorMultiplier;
	ToolObj->getRigidBody()->setInitPos(UMathUtil::ToImstkVec3(GetComponentLocation(), true));
	ToolObj->getRigidBody()->setInitOrientation(UMathUtil::ToImstkQuat(GetComponentRotation().Quaternion()));

	SubsystemInstance->ActiveScene->addSceneObject(ToolObj);

	if (GhostMaterial && GhostSceneComp) {
		auto* MaterialInstance = UMaterialInstanceDynamic::Create(GhostMaterial, GhostMaterial);
		for (UStaticMeshComponent* Mesh : GhostMeshes)
			Mesh->SetMaterial(0, MaterialInstance);
	}

	Super::bIsInitialized = true;
}

FVector UCustomController::UpdateImstkPosRot(FVector WorldPos, FQuat Orientation, FVector WorldDir, UDynamicalModel* PlaneActor)
{
	imstk::Vec3d Position = UMathUtil::ToImstkVec3(WorldPos, true);
	if (!bForceTool) {
		if (PlaneActor) {
			std::shared_ptr<imstk::Plane> Plane = std::dynamic_pointer_cast<imstk::Plane>(PlaneActor->GetImstkGeometry());

			if (Plane) {
				imstk::Vec3d IntersectPoint = imstk::Vec3d::Zero();
				if (imstk::CollisionUtils::testRayToPlane(UMathUtil::ToImstkVec3(WorldPos, true), UMathUtil::ToImstkVec3(WorldDir, true), Plane->getPosition(), Plane->getNormal(), IntersectPoint))
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
		ToolObj->getRigidBody()->m_orientation = new imstk::Quatd(UMathUtil::ToImstkQuat(Orientation));
		ToolObj->getRigidBody()->m_pos = new imstk::Vec3d(Position);
	}
	else
	{
		if (GhostSceneComp) {
			GhostSceneComp->SetWorldLocation(WorldPos);
			GhostSceneComp->SetWorldRotation(Orientation);
		}

		// TODO: update this to the force movement version in suturing controller
		imstk::Vec3d fS = (UMathUtil::ToImstkVec3(WorldPos, true) - ToolObj->getRigidBody()->getPosition()) * SpringForce; // Spring force
		imstk::Vec3d fD = -ToolObj->getRigidBody()->getVelocity() * SpringDamping; // Spring damping
		(*ToolObj->getRigidBody()->m_force) += (fS + fD);

		ToolObj->getRigidBody()->m_orientation = new imstk::Quatd(UMathUtil::ToImstkQuat(Orientation));
	}


	if (GEngine && bPrintImstkPos) {
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, UMathUtil::ToUnrealFVec(ToolObj->getRigidBody()->getPosition(), true).ToString());
	}

	return UMathUtil::ToUnrealFVec(Position, true);
}

void UCustomController::UpdateUnrealPosRot()
{
	// Since mesh comp and controller can have different orientations, only orient the controller to update and keep rotation offset for the mesh component
	if (MeshComp) {
		SetWorldLocationAndRotation(UMathUtil::ToUnrealFVec(ToolObj->getRigidBody()->getPosition(), true), UKismetMathLibrary::ComposeRotators(UMathUtil::ToUnrealFQuat(ToolObj->getRigidBody()->getOrientation()).Rotator(), (MeshComp->GetRelativeRotation() * -1)));
		return;
	}
	SetWorldLocationAndRotation(UMathUtil::ToUnrealFVec(ToolObj->getRigidBody()->getPosition(), true), UMathUtil::ToUnrealFQuat(ToolObj->getRigidBody()->getOrientation()));
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
				ToolPicking->beginCellGrasp(std::dynamic_pointer_cast<imstk::AnalyticalGeometry>(ToolObj->getCollidingGeometry()), std::string(TCHAR_TO_UTF8(*UEnum::GetValueAsString(GraspCollisionType))));
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
				ToolPicking->beginRayPointGrasp(std::dynamic_pointer_cast<imstk::AnalyticalGeometry>(ToolObj->getCollidingGeometry()), UMathUtil::ToImstkVec3(RayStart, true), UMathUtil::ToImstkVec3(RayDir, true));
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
		}
	}
}

void UCustomController::SetGhostComponents(USceneComponent* SceneComponent, TArray<UStaticMeshComponent*> StaticMeshComponents)
{
	GhostSceneComp = SceneComponent;
	GhostMeshes = StaticMeshComponents;
}

void UCustomController::UnInit()
{
	Super::UnInit();


}
