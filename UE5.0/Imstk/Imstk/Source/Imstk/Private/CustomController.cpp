// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomController.h"
#include "MathUtil.h"
#include "ImstkSubsystem.h"
#include "RBDModel.h"
#include "iMSTK-5.0/imstkLineMesh.h"
#include "iMSTK-5.0/imstkRigidBodyModel2.h"
#include "iMSTK-5.0/imstkRbdConstraint.h"
#include "iMSTK-5.0/imstkCollisionUtils.h"

#include "Kismet/GameplayStatics.h"
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
	// Create a line mesh tool that can be controlled
	std::shared_ptr<imstk::Geometry> ToolGeom;

	if (ToolGeometry == EToolGeometry::LineMeshTool) {
		ToolGeom = std::make_shared<imstk::LineMesh>();
		std::shared_ptr<imstk::VecDataArray<double, 3>> VertPtr = std::make_shared<imstk::VecDataArray<double, 3>>(2);
		(*VertPtr)[0] = UMathUtil::ToImstkVec3(Vertex1);
		(*VertPtr)[1] = UMathUtil::ToImstkVec3(Vertex2);
		std::shared_ptr<imstk::VecDataArray<int, 2>> IndicesPtr = std::make_shared<imstk::VecDataArray<int, 2>>(1);
		(*IndicesPtr)[0] = imstk::Vec2i(0, 1);
		std::dynamic_pointer_cast<imstk::LineMesh>(ToolGeom)->initialize(VertPtr, IndicesPtr);
	}
	else if (ToolGeometry == EToolGeometry::SphereTool) {
		// TODO: Sphere for vertex grasp not working
		std::shared_ptr <imstk::Sphere> SphereGeom = std::make_shared<imstk::Sphere>();
		SphereGeom->setRadius(Radius);

		ToolGeom = SphereGeom;
	}
	else if (ToolGeometry == EToolGeometry::CapsuleTool) {
		std::shared_ptr <imstk::Capsule> CapsuleGeom = std::make_shared<imstk::Capsule>();
		CapsuleGeom->setRadius(Radius);
		CapsuleGeom->setLength(Length);
		ToolGeom = CapsuleGeom;
	}

	ToolObj = std::make_shared<imstk::RigidObject2>("ToolObj");
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
	ToolObj->getRigidBody()->m_initPos = UMathUtil::ToImstkVec3(GetOwner()->GetActorLocation());

	SubsystemInstance->ActiveScene->addSceneObject(ToolObj);

	Super::bIsInitialized = true;
}

void UCustomController::UpdateImstkPosRot(FVector WorldPos, FQuat Orientation, FVector WorldDir, UDynamicalModel* PlaneActor)
{
	imstk::Vec3d Position;
	if (PlaneActor) {
		std::shared_ptr<imstk::Plane> Plane = std::dynamic_pointer_cast<imstk::Plane>(PlaneActor->GetImstkGeometry());

		if (Plane) {
			imstk::Vec3d IntersectPoint = imstk::Vec3d::Zero();
			if (imstk::CollisionUtils::testRayToPlane(UMathUtil::ToImstkVec3(WorldPos), UMathUtil::ToImstkVec3(WorldDir), Plane->getPosition(), Plane->getNormal(), IntersectPoint))
			{
				Position = IntersectPoint;
			}
			else {
				// No hit for ray
			}
		}
		else {
			//ERROR

			Super::bIsInitialized = false;
			return;
		}
	}
	else {
		Position = UMathUtil::ToImstkVec3(WorldPos);
	}

	// TODO: Should probably change to edit the position and orientation rather than creating new each time

	imstk::Quatd rot = UMathUtil::ToImstkQuat(Orientation);
	ToolObj->getRigidBody()->m_orientation = new imstk::Quatd(rot);
	ToolObj->getRigidBody()->m_pos = new imstk::Vec3d(Position);

	if (GEngine && bPrintImstkPos)
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, UMathUtil::ToUnrealFVec(ToolObj->getRigidBody()->getPosition()).ToString());
}

void UCustomController::UpdateUnrealPosRot()
{
	GetOwner()->SetActorLocation(UMathUtil::ToUnrealFVec(ToolObj->getRigidBody()->getPosition()));

	FQuat rot = UMathUtil::ToUnrealFQuat(ToolObj->getRigidBody()->getOrientation());
	GetOwner()->SetActorRotation(rot);
}

void UCustomController::MoveControllerToLocation(FVector Location, FQuat Orientation, bool bUpdateUnrealPosRot)
{
	UpdateImstkPosRot(Location, Orientation);
	if (bUpdateUnrealPosRot)
		UpdateUnrealPosRot();
}

void UCustomController::MoveControllerToRaycastOnPlane(FVector RayStart, FVector RayDir, FQuat Orientation, UDynamicalModel* PlaneActor, bool bUpdateUnrealPosRot)
{
	UpdateImstkPosRot(RayStart, Orientation, RayDir, PlaneActor);
	if (bUpdateUnrealPosRot)
		UpdateUnrealPosRot();
}


void UCustomController::BeginVertexGrasp()
{
	if (ToolPicking) {
		if (GraspType == EGraspType::VertexGrasp) {
			ToolPicking->beginVertexGrasp(std::dynamic_pointer_cast<imstk::AnalyticalGeometry>(ToolObj->getCollidingGeometry()));
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
	if (ToolPicking) {
		 if (GraspType == EGraspType::RayPointGrasp) {
			ToolPicking->beginRayPointGrasp(std::dynamic_pointer_cast<imstk::AnalyticalGeometry>(ToolObj->getCollidingGeometry()), UMathUtil::ToImstkVec3(RayStart), UMathUtil::ToImstkVec3(RayDir));
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
	if (ToolPicking)
		ToolPicking->endGrasp();
}

void UCustomController::BeginStitch()
{
	if (Stitching) {
		std::shared_ptr<imstk::LineMesh> ToolGeom = std::dynamic_pointer_cast<imstk::LineMesh>(ToolObj->getCollidingGeometry());
		const imstk::Vec3d& Vert1 = ToolGeom->getVertexPosition(0);
		const imstk::Vec3d& Vert2 = ToolGeom->getVertexPosition(1);

		//if (GEngine)
			//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "Stitching between " + UMathUtil::ToUnrealFVec(Vert1).ToString() + " and " + UMathUtil::ToUnrealFVec(Vert2).ToString());

		Stitching->beginStitch(Vert1, (Vert2 - Vert1).normalized());
	}
}

void UCustomController::UnInit()
{
	Super::UnInit();
	ToolPicking.reset();
}
