// Fill out your copyright notice in the Description page of Project Settings.


#include "ControllerCollisionTool.h"
#include "ImstkController.h"

#include "imstkRigidObjectCollision.h"
#include "imstkRigidObject2.h"
#include "imstkPbdObjectCollision.h"

EControllerObjectType UControllerCollisionTool::Init(UImstkController* Controller, const FControllerToolFilter& ToolFilter)
{
	SubsystemInstance = Controller->GetWorld()->GetGameInstance()->GetSubsystem<UImstkSubsystem>();

	ControllerComponent = Controller;

	ControllerToolFilter = ToolFilter;

	bIsInitialized = true;
	if (ToolFilter.CollisionToolStruct.bRigidTool)
		return EControllerObjectType::RigidToolObject;
	else
		return EControllerObjectType::PbdToolObject;
}

std::shared_ptr<imstk::SceneObject> UControllerCollisionTool::CreateInteraction(UDynamicalModel* OtherObject)
{
	if (ControllerToolFilter.CollisionToolStruct.bRigidTool) {
		if (std::shared_ptr<imstk::RigidObject2> RigidObject = std::dynamic_pointer_cast<imstk::RigidObject2>(OtherObject->ImstkCollidingObject))
		{
			std::shared_ptr<imstk::RigidObjectCollision> Interaction = std::make_shared<imstk::RigidObjectCollision>(std::dynamic_pointer_cast<imstk::RigidObject2>(ControllerComponent->GetToolObj()), RigidObject);
			Interaction->setFriction(ControllerToolFilter.CollisionToolStruct.Friction);
			Interaction->setBaumgarteStabilization(ControllerToolFilter.CollisionToolStruct.Stiffness);

			SubsystemInstance->ActiveScene->addInteraction(Interaction);
			SubsystemInstance->LogToUnrealAndImstk("Interaction created between " + FString(OtherObject->ImstkCollidingObject->getName().c_str()) + " and " + FString(ControllerComponent->GetToolObj()->getName().c_str()), FColor::Green);
			return Interaction;
		}
		else if (std::shared_ptr<imstk::PbdObject> DeformableObj = std::dynamic_pointer_cast<imstk::PbdObject>(OtherObject->ImstkCollidingObject))
		{
			std::shared_ptr<imstk::PbdObjectCollision> Interaction = std::make_shared<imstk::PbdObjectCollision>(DeformableObj, ControllerComponent->GetToolObj());
			Interaction->setFriction(ControllerToolFilter.CollisionToolStruct.Friction);
			Interaction->setRestitution(ControllerToolFilter.CollisionToolStruct.Restitution);
			Interaction->setRigidBodyCompliance(ControllerToolFilter.CollisionToolStruct.RigidBodyCompliance);
			Interaction->setDeformableStiffnessA(ControllerToolFilter.CollisionToolStruct.Stiffness);
			Interaction->setDeformableStiffnessB(ControllerToolFilter.CollisionToolStruct.Stiffness);
			Interaction->setUseCorrectVelocity(ControllerToolFilter.CollisionToolStruct.bUseCorrectVelocity);
			SubsystemInstance->ActiveScene->addInteraction(Interaction);
			Collisions.Add(Interaction);
			SubsystemInstance->LogToUnrealAndImstk("Interaction created between " + FString(OtherObject->ImstkCollidingObject->getName().c_str()) + " and " + FString(ControllerComponent->GetToolObj()->getName().c_str()), FColor::Green);
			return Interaction;
		}
		else {
			SubsystemInstance->LogToUnrealAndImstk("Creating interaction between " + FString(OtherObject->ImstkCollidingObject->getName().c_str()) + " and " + FString(ControllerComponent->GetToolObj()->getName().c_str()) + " failed", FColor::Red);
			return nullptr;
		}
	}
	else {
		std::shared_ptr<imstk::PbdObjectCollision> Interaction = std::make_shared<imstk::PbdObjectCollision>(std::dynamic_pointer_cast<imstk::PbdObject>(ControllerComponent->GetToolObj()), OtherObject->ImstkCollidingObject);
		Interaction->setFriction(ControllerToolFilter.CollisionToolStruct.Friction);
		Interaction->setRestitution(ControllerToolFilter.CollisionToolStruct.Restitution);
		Interaction->setRigidBodyCompliance(ControllerToolFilter.CollisionToolStruct.RigidBodyCompliance);
		Interaction->setDeformableStiffnessA(ControllerToolFilter.CollisionToolStruct.Stiffness);
		Interaction->setDeformableStiffnessB(ControllerToolFilter.CollisionToolStruct.Stiffness);
		Interaction->setUseCorrectVelocity(ControllerToolFilter.CollisionToolStruct.bUseCorrectVelocity);
		SubsystemInstance->ActiveScene->addInteraction(Interaction);
		Collisions.Add(Interaction);
		SubsystemInstance->LogToUnrealAndImstk("Interaction created between " + FString(OtherObject->ImstkCollidingObject->getName().c_str()) + " and " + FString(ControllerComponent->GetToolObj()->getName().c_str()), FColor::Green);

		return Interaction;
	}
}