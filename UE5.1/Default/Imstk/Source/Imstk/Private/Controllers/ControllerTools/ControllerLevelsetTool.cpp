// Fill out your copyright notice in the Description page of Project Settings.


#include "ControllerLevelsetTool.h"
#include "ImstkController.h"
#include "ImstkSubsystem.h"
#include "imstkRigidObjectLevelSetCollision.h"
#include "imstkRigidBodyCH.h"
#include "imstkLevelSetCH.h"
#include "LevelSetModel.h"


EControllerObjectType UControllerLevelsetTool::Init(UImstkController* Controller, const FControllerToolFilter& ToolFilter)
{
	SubsystemInstance = Controller->GetWorld()->GetGameInstance()->GetSubsystem<UImstkSubsystem>();

	ControllerComponent = Controller;

	ControllerToolFilter = ToolFilter;

	bIsInitialized = true;

	return EControllerObjectType::RigidToolObject;
}

std::shared_ptr<imstk::SceneObject> UControllerLevelsetTool::CreateInteraction(UDynamicalModel* OtherObject)
{
	if (std::shared_ptr<LevelSetObject> LevelSet = std::dynamic_pointer_cast<LevelSetObject>(OtherObject->ImstkCollidingObject)) {
		std::shared_ptr<imstk::RigidObjectLevelSetCollision> interaction = std::make_shared<imstk::RigidObjectLevelSetCollision>(std::dynamic_pointer_cast<imstk::RigidObject2>(ControllerComponent->GetToolObj()), LevelSet);
		{
			auto colHandlerA = std::dynamic_pointer_cast<imstk::RigidBodyCH>(interaction->getCollisionHandlingA());
			colHandlerA->setUseFriction(ControllerToolFilter.LevelsetToolStruct.bUseFriction);
			colHandlerA->setBaumgarteStabilization(ControllerToolFilter.LevelsetToolStruct.Stiffness); // inelastic collision

			auto colHandlerB = std::dynamic_pointer_cast<imstk::LevelSetCH>(interaction->getCollisionHandlingB());
			colHandlerB->setLevelSetVelocityScaling(ControllerToolFilter.LevelsetToolStruct.VelocityScaling);
			colHandlerB->setKernel(3, 1.0);
			colHandlerB->setUseProportionalVelocity(true);
		}

		SubsystemInstance->ActiveScene->addInteraction(interaction);
		SubsystemInstance->LogToUnrealAndImstk("Interaction created between " + FString(OtherObject->ImstkCollidingObject->getName().c_str()) + " and " + FString(ControllerComponent->GetToolObj()->getName().c_str()), FColor::Green);
		return interaction;
	}
	else {
		SubsystemInstance->LogToUnrealAndImstk("Model must be a LevelSet model. LevelSet interaction could not be created between " + FString(OtherObject->ImstkCollidingObject->getName().c_str()) + " " + FString(ControllerComponent->GetToolObj()->getName().c_str()) + ".", FColor::Red);
		return nullptr;
	}
}
