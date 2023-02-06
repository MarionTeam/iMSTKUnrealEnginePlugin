// Fill out your copyright notice in the Description page of Project Settings.


#include "ControllerBurningTool.h"
#include "ImstkSubsystem.h"
#include "ImstkController.h"
#include "ConnectiveTissue.h"
#include "imstkBurnable.h"

EControllerObjectType UControllerBurningTool::Init(UImstkController* Controller, const FControllerToolFilter& ToolFilter)
{
	SubsystemInstance = Controller->GetWorld()->GetGameInstance()->GetSubsystem<UImstkSubsystem>();

	ControllerComponent = Controller;

	// Set the tool's variables from the struct
	ControllerToolFilter = ToolFilter;

	bIsInitialized = true;

	return EControllerObjectType::PbdToolObject;
}


std::shared_ptr<imstk::SceneObject> UControllerBurningTool::CreateInteraction(UDynamicalModel* OtherObject)
{
	UConnectiveTissue* Connective = Cast<UConnectiveTissue>(OtherObject);
	if (Connective) {
		auto Burnable = std::make_shared<imstk::Burnable>();
		Connective->ImstkCollidingObject->addComponent(Burnable);

		auto Burner = std::make_shared<imstk::Burner>();
		Burner->addObject(std::dynamic_pointer_cast<imstk::PbdObject>(Connective->ImstkCollidingObject));
		Burner->setWattage(ControllerToolFilter.BurningToolStruct.Wattage);

		std::dynamic_pointer_cast<imstk::PbdObject>(ControllerComponent->GetToolObj())->addComponent(Burner);
		ToolBurners.Add(Burner);

		ControllerComponent->GetToolObj()->initialize();
		SubsystemInstance->ActiveScene->initialize();
	}
	else {

	}

	return nullptr;
}

bool UControllerBurningTool::Execute()
{
	// Will always return true if there is an interaction present
	bool Burned = false;
	if (bIsInitialized) {
		if (ToolBurners.Num() > 0) {
			for (auto Burner : ToolBurners) {
				Burner->start();
				Burned = true;
			}
		}
		else {
			SubsystemInstance->LogToUnrealAndImstk("ToolBurners not assigned", FColor::Red);
		}
	}
	return Burned;
}

bool UControllerBurningTool::Release()
{
	// Will always return true if there is an interaction present
	bool Ended = false;
	if (bIsInitialized) {
		if (ToolBurners.Num() > 0) {
			for (auto Burner : ToolBurners) {
				Burner->stop();
				Ended = true;
			}
		}
		else {
			SubsystemInstance->LogToUnrealAndImstk("ToolBurners not assigned", FColor::Red);
		}
	}
	return Ended;
}

void UControllerBurningTool::UnInit()
{
	Super::UnInit();
	for (auto Burner : ToolBurners)
		Burner.reset();
	ToolBurners.Empty();
}
