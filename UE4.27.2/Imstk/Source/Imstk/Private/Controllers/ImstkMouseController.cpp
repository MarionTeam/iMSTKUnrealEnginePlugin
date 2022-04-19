// Fill out your copyright notice in the Description page of Project Settings.


#include "ImstkMouseController.h"
#include "MathUtil.h"
#include "ImstkSubsystem.h"
#include "RBDModel.h"
#include "iMSTK-5.0/imstkLineMesh.h"
#include "iMSTK-5.0/imstkRigidBodyModel2.h"
#include "iMSTK-5.0/imstkRbdConstraint.h"

#include "Kismet/GameplayStatics.h"
#include "GameFramework/PlayerController.h"


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
	std::shared_ptr<imstk::LineMesh> ToolGeom = std::make_shared<imstk::LineMesh>();
	std::shared_ptr<imstk::VecDataArray<double, 3>> VertPtr = std::make_shared<imstk::VecDataArray<double, 3>>(2);
	(*VertPtr)[0] = imstk::Vec3d(0.0, 0.0, -25.0);
	(*VertPtr)[1] = imstk::Vec3d(0.0, 0.0, 25.0);
	std::shared_ptr<imstk::VecDataArray<int, 2>> IndicesPtr = std::make_shared<imstk::VecDataArray<int, 2>>(1);
	(*IndicesPtr)[0] = imstk::Vec2i(0, 1);
	ToolGeom->initialize(VertPtr, IndicesPtr);

	ToolObj = std::make_shared<imstk::RigidObject2>("ToolObj");
	ToolObj->setCollidingGeometry(ToolGeom);
	ToolObj->setPhysicsGeometry(ToolGeom);

	// Configure the model
	std::shared_ptr<imstk::RigidBodyModel2> RbdModel = std::make_shared<imstk::RigidBodyModel2>();
	RbdModel->getConfig()->m_gravity = imstk::Vec3d::Zero();
	RbdModel->getConfig()->m_maxNumIterations = 7;
	RbdModel->getConfig()->m_velocityDamping = 0.95;
	RbdModel->getConfig()->m_angularVelocityDamping = 1.0;
	RbdModel->getConfig()->m_maxNumConstraints = 40;
	ToolObj->setDynamicalModel(RbdModel);

	ToolObj->getRigidBody()->m_mass = Mass;
	ToolObj->getRigidBody()->m_intertiaTensor = imstk::Mat3d::Identity() * 10000.0;
	ToolObj->getRigidBody()->m_initPos = UMathUtil::ToImstkVec3(GetOwner()->GetActorLocation());

	SubsystemInstance->ActiveScene->addSceneObject(ToolObj);

	Super::bIsInitialized = true;
}

void UImstkMouseController::UpdateImstkForce(FVector WorldPos)
{
	// Taken from PBDTissueContactExample
	imstk::Vec3d fS = (UMathUtil::ToImstkVec3(WorldPos) - ToolObj->getRigidBody()->getPosition()) * 2000.0; // Spring force
	imstk::Vec3d fD = -ToolObj->getRigidBody()->getVelocity() * 100.0; // Spring damping
	(*ToolObj->getRigidBody()->m_force) += (fS + fD); 
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
		
		//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, WorldPosition.ToString());
		WorldPosition = WorldPosition + WorldDirection * Offset;
		//GetOwner()->SetActorLocation(WorldPosition);
		UpdateImstkForce(WorldPosition);
		UpdateUnrealPos();


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

void UImstkMouseController::UnInit()
{
	Super::UnInit();
}


