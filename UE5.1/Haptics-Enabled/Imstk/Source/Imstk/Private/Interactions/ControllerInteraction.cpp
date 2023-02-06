// Fill out your copyright notice in the Description page of Project Settings.


#include "ControllerInteraction.h"
#include "ImstkSubsystem.h"

void UControllerInteraction::Init()
{
	UImstkSubsystem* SubsystemInstance = GetWorld()->GetGameInstance()->GetSubsystem<UImstkSubsystem>();
	if (Model1 == nullptr) {
		SubsystemInstance->LogToUnrealAndImstk("Model1 is not assigned in controller interaction", FColor::Red);
		return;
	}
	else if (Controller == nullptr) {
		SubsystemInstance->LogToUnrealAndImstk("Controller is not assigned in controller interaction", FColor::Red);
		return;
	}

	if (!Model1->IsInitialized() || !Controller->IsInitialized())
		return;

	Interactions.Empty();

	for (auto ControllerTool : Controller->ControllerTools) {
		auto NewInteraction = ControllerTool->CreateInteraction(Model1);
		if (NewInteraction)
			Interactions.Add(NewInteraction);
	}
	if (Interactions.Num() > 0)
		Model1->AddInteraction(this);
	return;
}

void UControllerInteraction::UnInit() {
	for (auto ControllerTool : Controller->ControllerTools) {
		ControllerTool->UnInit();
	}


	for (auto Interaction : Interactions)
		Interaction->reset();
	Interactions.Empty();
}