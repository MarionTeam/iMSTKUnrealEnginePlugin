// Fill out your copyright notice in the Description page of Project Settings.


#include "ControllerNeedleTool.h"
#include "ImstkController.h"
#include "SuturingController.h"
#include "imstkPuncturable.h"

// Currently can not handle ray point grasps
EControllerObjectType UControllerNeedleTool::Init(UImstkController* Controller, const FControllerToolFilter& ToolFilter)
{
	SubsystemInstance = Controller->GetWorld()->GetGameInstance()->GetSubsystem<UImstkSubsystem>();
	
	// Set up only for SuturingController currently
	if (!Cast<USuturingController>(Controller)) {
		SubsystemInstance->LogToUnrealAndImstk("Error: Could not initialize " + Controller->GetName() + ". Controller must be a SuturingController to use a needle interaction.", FColor::Red);
		return EControllerObjectType::Null;
	}

	ControllerComponent = Controller;

	bIsInitialized = true;
	return EControllerObjectType::RigidToolObject;
}

std::shared_ptr<imstk::SceneObject> UControllerNeedleTool::CreateInteraction(UDynamicalModel* OtherObject)
{
	if (Cast<UDeformableModel>(OtherObject)) {
		OtherObject->ImstkCollidingObject->addComponent<imstk::Puncturable>();

		USuturingController* SuturCont = Cast<USuturingController>(ControllerComponent);
		auto SutureInteraction = std::make_shared<NeedleInteraction>(std::dynamic_pointer_cast<imstk::PbdObject>(OtherObject->ImstkCollidingObject), SuturCont->Needle, std::dynamic_pointer_cast<imstk::PbdObject>(SuturCont->Thread->ImstkCollidingObject));
		SubsystemInstance->ActiveScene->addInteraction(SutureInteraction);
		SuturCont->SetNeedleInteraction(SutureInteraction);

		SubsystemInstance->LogToUnrealAndImstk("Interaction created between " + FString(OtherObject->ImstkCollidingObject->getName().c_str()) + " and " + FString(ControllerComponent->GetToolObj()->getName().c_str()), FColor::Green);

		return SutureInteraction;
	}
	else {
		SubsystemInstance->LogToUnrealAndImstk("Wrong model types, Model1 must be a deformable model. Suturing interaction could not be created between " + FString(OtherObject->ImstkCollidingObject->getName().c_str()) + " " + FString(ControllerComponent->GetToolObj()->getName().c_str()) + ".", FColor::Red);
		return nullptr;
	}
}