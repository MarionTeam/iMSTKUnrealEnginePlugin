// Fill out your copyright notice in the Description page of Project Settings.


#include "ImstkMouseController.h"
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
void UImstkMouseController::InitializeComponent()
{
	Super::InitializeComponent();

	// Make the subsystem tick first to update the imstk scene before updating the rigid body in unreal
	if (GetWorld() && GetWorld()->GetGameInstance())
		AddTickPrerequisiteActor((AActor*)SubsystemInstance);

}

void UImstkMouseController::InitController()
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
	RbdModel->getConfig()->m_maxNumIterations = 8;
	RbdModel->getConfig()->m_velocityDamping = 1.0;
	RbdModel->getConfig()->m_angularVelocityDamping = 1.0;
	RbdModel->getConfig()->m_maxNumConstraints = 40;
	ToolObj->setDynamicalModel(RbdModel);

	ToolObj->getRigidBody()->m_mass = Mass;
	ToolObj->getRigidBody()->m_intertiaTensor = imstk::Mat3d::Identity() * 10.0;
	ToolObj->getRigidBody()->m_initPos = UMathUtil::ToImstkVec3(GetOwner()->GetActorLocation());

	SubsystemInstance->ActiveScene->addSceneObject(ToolObj);

	Super::bIsInitialized = true;
}

void UImstkMouseController::UpdateImstkPos(FVector WorldPos, FVector WorldDir)
{
	if (bRayToPlane) {
		std::shared_ptr<imstk::Plane> Plane = std::dynamic_pointer_cast<imstk::Plane>(((UDynamicalModel*)PlaneModel->GetComponentByClass(UDynamicalModel::StaticClass()))->GetImstkGeometry());

		if (Plane) {
			imstk::Vec3d IntersectPoint = imstk::Vec3d::Zero();
			if (imstk::CollisionUtils::testRayToPlane(UMathUtil::ToImstkVec3(WorldPos), UMathUtil::ToImstkVec3(WorldDir), Plane->getPosition(), Plane->getNormal(), IntersectPoint))
			{
				imstk::Vec3d fS = (IntersectPoint - ToolObj->getRigidBody()->getPosition()) * 2000; // Spring force
				imstk::Vec3d fD = -ToolObj->getRigidBody()->getVelocity() * 100.0; // Spring damping
				(*ToolObj->getRigidBody()->m_force) += (fS + fD);
			}
		}
		else {
			//ERROR

			Super::bIsInitialized = false;
		}
	}
	else {
		// Taken from PBDTissueContactExample
		imstk::Vec3d fS = (UMathUtil::ToImstkVec3(WorldPos) - ToolObj->getRigidBody()->getPosition()) * 2000.0; // Spring force
		imstk::Vec3d fD = -ToolObj->getRigidBody()->getVelocity() * 100.0; // Spring damping
		(*ToolObj->getRigidBody()->m_force) += (fS + fD);
	}
}

void UImstkMouseController::UpdateUnrealPos()
{
	GetOwner()->SetActorLocation(UMathUtil::ToUnrealFVec(ToolObj->getRigidBody()->getPosition()));
}

void UImstkMouseController::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	if (Super::bIsInitialized) {
		FVector WorldPosition;
		FVector WorldDirection;
		UGameplayStatics::GetPlayerController(GetWorld(), 0)->DeprojectMousePositionToWorld(WorldPosition, WorldDirection);

		//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, WorldDirection.ToString());
		WorldPosition = WorldPosition + WorldDirection * Offset;
		UpdateImstkPos(WorldPosition, WorldDirection);
		UpdateUnrealPos();

		//DrawDebugLine(GetWorld(), WorldPosition, WorldPosition + WorldDirection * 100, FColor::Blue, false, 0, 0, 1);


		/*
		float MouseX;
		float MouseY;
		UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetMousePosition(MouseX, MouseY);

		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("X: ") + FString::SanitizeFloat(MouseX) + TEXT(" Y: ") + FString::SanitizeFloat(MouseY));
		FVector WorldPosition = FVector(MouseX, 0, MouseY);
		GetOwner()->SetActorLocation(WorldPosition);
		
		*/
	}
}

void UImstkMouseController::BeginVertexGrasp() 
{
	if (ToolPicking) {
		if (GraspType == EGraspType::VertexGrasp) {
			ToolPicking->beginVertexGrasp(std::dynamic_pointer_cast<imstk::AnalyticalGeometry>(ToolObj->getCollidingGeometry()));
		}
		else if (GraspType == EGraspType::RayPointGrasp) {
			FVector WorldPosition;
			FVector WorldDirection;
			UGameplayStatics::GetPlayerController(GetWorld(), 0)->DeprojectMousePositionToWorld(WorldPosition, WorldDirection);
			//WorldPosition = WorldPosition + WorldDirection.Normalize() * Offset;
			ToolPicking->beginRayPointGrasp(std::dynamic_pointer_cast<imstk::AnalyticalGeometry>(ToolObj->getCollidingGeometry()), UMathUtil::ToImstkVec3(WorldPosition), UMathUtil::ToImstkVec3(WorldDirection));
		}	
	}
	else {
		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "ToolPicking not assigned");
		UE_LOG(LogTemp, Error, TEXT("ToolPicking not assigned"));
	}
}

void UImstkMouseController::EndVertexGrasp()
{
	if (ToolPicking)
		ToolPicking->endGrasp();
}

void UImstkMouseController::BeginStitch()
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

void UImstkMouseController::UnInit()
{
	Super::UnInit();
	ToolPicking.reset();
}

