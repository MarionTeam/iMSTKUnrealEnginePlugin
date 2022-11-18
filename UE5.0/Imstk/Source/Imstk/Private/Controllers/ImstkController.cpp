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

bool UImstkController::IsInitialized()
{
	return bIsInitialized;
}

void UImstkController::DisableAllCollisions()
{
	for (std::shared_ptr<imstk::CollisionInteraction> Collision : Collisions) {
		Collision->setEnabled(false);
	}
}

void UImstkController::EnableAllCollisions()
{
	for (std::shared_ptr<imstk::CollisionInteraction> Collision : Collisions) {
		Collision->setEnabled(true);
	}
}


void UImstkController::AddToolPicking(std::shared_ptr<imstk::PbdObjectGrasping> InputPicking)
{
	this->ToolPickings.Add(InputPicking);
}

void UImstkController::AddStitching(std::shared_ptr<imstk::PbdObjectStitching> InputStitch)
{
	this->Stitchings.Add(InputStitch);
}

void UImstkController::AddCutting(std::shared_ptr<imstk::PbdObjectCutting> InputCutting)
{
	this->Cuttings.Add(InputCutting);
}

void UImstkController::AddCutObject(std::shared_ptr<imstk::PbdObject> InputObject)
{
	this->CutObjects.Add(InputObject);
}

void UImstkController::AddCollision(std::shared_ptr<imstk::CollisionInteraction> InputCollision)
{
	this->Collisions.Add(InputCollision);
}

void UImstkController::AddTetCutting(std::shared_ptr<imstk::PbdObjectCellRemoval> InputCutting)
{
	this->TetCuttings.Add(InputCutting);
}

void UImstkController::AddTetObject(UPBDModel* InputObject)
{
	this->TetObjects.Add(InputObject);
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
	for (std::shared_ptr<imstk::PbdObjectGrasping> ToolPicking : ToolPickings) {
		ToolPicking.reset();
	}
	for (std::shared_ptr<imstk::PbdObjectStitching> Stitching : Stitchings) {
		Stitching.reset();
	}
	for (std::shared_ptr<imstk::PbdObjectCutting> Cutting : Cuttings) {
		Cutting.reset();
	}
	for (std::shared_ptr<imstk::CollisionInteraction> Collision : Collisions) {
		Collision.reset();
	}
}
