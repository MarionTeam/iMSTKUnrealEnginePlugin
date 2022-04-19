// Fill out your copyright notice in the Description page of Project Settings.


#include "ControllerInteraction.h"

#include "DeformableModel.h"
#include "RBDModel.h"
#include "StaticModel.h"
#include "iMSTK-5.0/imstkPBDObjectCollision.h"
#include "iMSTK-5.0/imstkRigidObjectCollision.h"
#include "iMSTK-5.0/imstkLineMesh.h"
//#include "iMSTK-5.0/imstkMeshToMeshBruteForceCD.h"
#include "ImstkSubsystem.h"
#include "ImstkSettings.h"

void UControllerInteraction::Init()
{
	if (Model1 == nullptr) {
		UE_LOG(LogTemp, Error, TEXT("%s"), ("Model1 is not assigned in collision interaction"));
		return;
	}
	else if (Controller == nullptr) {
		UE_LOG(LogTemp, Error, TEXT("%s"), ("Controller is not assigned in collision interaction"));
		return;
	}

	// Determine the collision type if set to auto
	if (CollisionType == CollisionInteractionType::Auto)
		CollisionType = GetAutoCollisionType(Controller->GetToolObj()->getCollidingGeometry(), Model1->GetCollidingGeometry());

	// If GetAutoCollisionType returns Auto, then collision type was not found. Therefore return
	if (CollisionType == CollisionInteractionType::Auto)
		return;

	// Create interaction and add to scene
	UImstkSubsystem* SubsystemInstance = GetWorld()->GetGameInstance()->GetSubsystem<UImstkSubsystem>();
	if (Cast<URBDModel>(Model1) || Cast<UStaticModel>(Model1))
	{
		std::shared_ptr<imstk::RigidObjectCollision> Interaction = std::make_shared<imstk::RigidObjectCollision>(Controller->GetToolObj(), std::dynamic_pointer_cast<imstk::RigidObject2>(Model1->ImstkCollidingObject), std::string(TCHAR_TO_UTF8(*UEnum::GetValueAsString(CollisionType))));
		Interaction->setFriction(Friction);
		Interaction->setStiffness(Stiffness);
		//std::dynamic_pointer_cast<imstk::MeshToMeshBruteForceCD>(Interaction->getCollisionDetection())->setGenerateEdgeEdgeContacts(true);
		SubsystemInstance->ActiveScene->addInteraction(Interaction);
	}
	else if (Cast<UDeformableModel>(Model1))
	{
		std::shared_ptr<imstk::PbdObjectCollision> Interaction = std::make_shared<imstk::PbdObjectCollision>(std::dynamic_pointer_cast<imstk::PbdObject>(Model1->ImstkCollidingObject), Controller->GetToolObj(), std::string(TCHAR_TO_UTF8(*UEnum::GetValueAsString(CollisionType))));
		Interaction->setFriction(Friction);
		Interaction->setRestitution(0);
		// TODO: not sure if this is needed (says default is true), but its done in some of the examples
		//std::dynamic_pointer_cast<imstk::MeshToMeshBruteForceCD>(Interaction->getCollisionDetection())->setGenerateEdgeEdgeContacts(true);
		SubsystemInstance->ActiveScene->addInteraction(Interaction);
	}
	else {
		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "Initializing interaction between " + FString(Model1->ImstkCollidingObject->getName().c_str()) + " and " + FString(Controller->GetToolObj()->getName().c_str()) + " failed");
		UE_LOG(LogTemp, Error, TEXT("Initializing interaction between %s and %s failed"), Model1->ImstkCollidingObject->getName().c_str(), Controller->GetToolObj()->getName().c_str());
		return;
	}
	if (UImstkSettings::IsDebugging()) {
		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, "Interaction Initialized: " + FString(Model1->ImstkCollidingObject->getName().c_str()) + " " + FString(Controller->GetToolObj()->getName().c_str()));
	}
}