// Fill out your copyright notice in the Description page of Project Settings.


#include "ImstkController.h"
#include "ImstkSubsystem.h"


void UImstkController::InitializeComponent()
{
	Super::InitializeComponent();

	if (GetWorld() && GetWorld()->GetGameInstance()) {
		GetOwner()->Tags.Add(FName("ImstkController"));
		this->ComponentTags.Add(FName("ImstkController"));

		SubsystemInstance = GetWorld()->GetGameInstance()->GetSubsystem<UImstkSubsystem>();

		TArray<UActorComponent*> StaticMeshes;
		GetOwner()->GetComponents(UStaticMeshComponent::StaticClass(), StaticMeshes);

		for (UActorComponent* StaticMeshComp : StaticMeshes)
			((UStaticMeshComponent*)StaticMeshComp)->SetMobility(EComponentMobility::Type::Movable);
	}

}

// Sets default values for this component's properties
UImstkController::UImstkController()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	bWantsInitializeComponent = true;
	// ...
}


// Called when the game starts
void UImstkController::BeginPlay()
{
	Super::BeginPlay();

	// ...

}


// Called every frame
void UImstkController::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}


void UImstkController::InitController()
{
	
}

std::shared_ptr<imstk::DynamicObject> UImstkController::GetToolObj()
{
	return ToolObj;
}

void UImstkController::SetToolObj(std::shared_ptr<imstk::DynamicObject> NewToolObj)
{
	ToolObj = NewToolObj;
}

bool UImstkController::IsInitialized()
{
	return bIsInitialized;
}

bool UImstkController::ExecuteInteractions(TEnumAsByte<EToolType> ExecuteType)
{
	bool Executed = false;
	for (auto Tool : ControllerTools)
	{
		if (Tool->ControllerToolFilter.ToolType == ExecuteType)
			Executed = Tool->Execute();
	}
	return Executed;
}

bool UImstkController::ReleaseInteractions(TEnumAsByte<EToolType> ReleaseType)
{
	bool Released = false;
	for (auto Tool : ControllerTools)
	{
		if (Tool->ControllerToolFilter.ToolType == ReleaseType)
			Released = Tool->Release();
	}
	return Released;
}

void UImstkController::SetStaticMeshComp(UStaticMeshComponent* InputMeshComp)
{
	this->MeshComp = InputMeshComp;
}

FVector UImstkController::GetGeomScale()
{
	return ToolGeomFilter.GetGeomScale();
}

FVector UImstkController::GetGeomOffset()
{
	return ToolGeomFilter.GetGeomOffset();
}

void UImstkController::UnInit()
{
	ToolObj.reset();
	
	for (auto Tool : ControllerTools) {
		Tool->UnInit();
	}
}
