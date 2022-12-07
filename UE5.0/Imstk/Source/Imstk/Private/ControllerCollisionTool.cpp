// Fill out your copyright notice in the Description page of Project Settings.


#include "ControllerCollisionTool.h"
#include "ImstkController.h"

#include "imstkRigidObjectCollision.h"
#include "imstkRigidObject2.h"
#include "imstkPbdObjectCollision.h"

// Currently can not handle ray point grasps
EControllerObjectType UControllerCollisionTool::Init(UImstkController* Controller, const FControllerToolFilter& ToolFilter)
{
	SubsystemInstance = Controller->GetWorld()->GetGameInstance()->GetSubsystem<UImstkSubsystem>();
	
	ControllerComponent = Controller;

	ControllerToolFilter = ToolFilter;

	bIsInitialized = true;
	return EControllerObjectType::PbdToolObject;
}

bool UControllerCollisionTool::CreateInteraction(UDynamicalModel* OtherObject)
{
	//std::shared_ptr<imstk::PbdObjectCollision> Interaction = std::make_shared<imstk::PbdObjectCollision>(std::dynamic_pointer_cast<imstk::PbdObject>(OtherObject), ControllerComponent->GetToolObj());
	//Interaction->setFriction(ControllerToolFilter->CollisionToolStruct.Friction);
	//Interaction->setRestitution(ControllerToolFilter->CollisionToolStruct.Restitution);
	//Interaction->setRigidBodyCompliance(ControllerToolFilter->CollisionToolStruct.RigidBodyCompliance);
	//Interaction->setDeformableStiffnessA(ControllerToolFilter->CollisionToolStruct.Stiffness);
	//Interaction->setDeformableStiffnessB(ControllerToolFilter->CollisionToolStruct.Stiffness);
	////Interaction->setUseCorrectVelocity(false);
	//SubsystemInstance->ActiveScene->addInteraction(Interaction);

	//if (std::shared_ptr<imstk::RigidObject2> RigidObject = std::dynamic_pointer_cast<imstk::RigidObject2>(OtherObject))
	//{
	//	std::shared_ptr<imstk::RigidObjectCollision> Interaction = std::make_shared<imstk::RigidObjectCollision>(ControllerComponent->GetToolObj(), RigidObject);
	//	Interaction->setFriction(ControllerToolFilter->CollisionToolStruct.Friction);
	//	Interaction->setBaumgarteStabilization(ControllerToolFilter->CollisionToolStruct.Stiffness);
	//	//std::dynamic_pointer_cast<imstk::MeshToMeshBruteForceCD>(Interaction->getCollisionDetection())->setGenerateEdgeEdgeContacts(true);
	//	SubsystemInstance->ActiveScene->addInteraction(Interaction);
	//	//Controller->AddCollision(Interaction);
	//}
	if (std::shared_ptr<imstk::PbdObject> DeformableObj = std::dynamic_pointer_cast<imstk::PbdObject>(OtherObject->ImstkCollidingObject))
	{
		std::shared_ptr<imstk::PbdObjectCollision> Interaction = std::make_shared<imstk::PbdObjectCollision>(DeformableObj, ControllerComponent->GetToolObj());
		Interaction->setFriction(ControllerToolFilter.CollisionToolStruct.Friction);
		Interaction->setRestitution(ControllerToolFilter.CollisionToolStruct.Restitution);
		Interaction->setRigidBodyCompliance(ControllerToolFilter.CollisionToolStruct.RigidBodyCompliance);
		Interaction->setDeformableStiffnessA(ControllerToolFilter.CollisionToolStruct.Stiffness);
		Interaction->setDeformableStiffnessB(ControllerToolFilter.CollisionToolStruct.Stiffness);
		//Interaction->setUseCorrectVelocity(false);
		SubsystemInstance->ActiveScene->addInteraction(Interaction);
		Collisions.Add(Interaction);
		//Controller->AddCollision(Interaction);
	}
	else {
		SubsystemInstance->LogToUnrealAndImstk("Creating interaction between " + FString(OtherObject->ImstkCollidingObject->getName().c_str()) + " and " + FString(ControllerComponent->GetToolObj()->getName().c_str()) + " failed");
		return false;
	}

	SubsystemInstance->LogToUnrealAndImstk("Interaction created between " + FString(OtherObject->ImstkCollidingObject->getName().c_str()) + " and " + FString(ControllerComponent->GetToolObj()->getName().c_str()));

	return true;
}