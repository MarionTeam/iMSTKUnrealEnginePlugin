// Fill out your copyright notice in the Description page of Project Settings.


#include "DynamicalModel.h"
#include "KismetProceduralMeshLibrary.h"
#include "CollisionInteraction.h"


void UDynamicalModel::InitializeComponent()
{
	Super::InitializeComponent();

	// Check if game is in play mode (required because InitializeComponent() is run when creating a blueprint of the object
	if (GetWorld() && GetWorld()->GetGameInstance()) {
		// Set variables to use during execution
		Owner = GetOwner();
		UStaticMeshComponent* MeshComp = (UStaticMeshComponent*)Owner->GetComponentByClass(UStaticMeshComponent::StaticClass());

		if (MeshComp)
			MeshComp->SetMobility(EComponentMobility::Type::Movable);
		//Owner->SetActorEnableCollision(false);
		SubsystemInstance = GetWorld()->GetGameInstance()->GetSubsystem<UImstkSubsystem>();
	}
}

TArray<UCollisionInteraction*> UDynamicalModel::GetInteractions()
{
	return Interactions;
}

void UDynamicalModel::AddInteraction(UCollisionInteraction* Interaction)
{
	Interactions.Add(Interaction);
}

std::shared_ptr<imstk::Geometry> UDynamicalModel::GetImstkGeometry()
{
	// If already created return cached value
	if (Geometry)
		return Geometry;

	// Initialize imstk geometry
	Geometry = GeomFilter.Init(this);
	if (!Geometry) {
		SubsystemInstance->LogToUnrealAndImstk("Imstk geometry for %s could not be created " + Owner->GetName());
		return nullptr;
	}
	return Geometry;

}

void UDynamicalModel::ConvertStaticToProceduralMesh(UStaticMeshComponent* StaticMesh, UProceduralMeshComponent* ProcMesh)
{
	StaticMesh->GetStaticMesh()->bAllowCPUAccess = true;
	UKismetProceduralMeshLibrary::CopyProceduralMeshFromStaticMeshComponent(StaticMesh, 0, ProcMesh, false);
}

FVector UDynamicalModel::GetGeomScale()
{
	return GeomFilter.GetGeomScale();
}

FVector UDynamicalModel::GetGeomOffset()
{
	return GeomFilter.GetGeomOffset();
}

void UDynamicalModel::RemoveFromScene()
{
	// Remove all interactions
	for (int i = 0; i < Interactions.Num(); i++) {
		//TArray<std::shared_ptr<imstk::SceneObject>> ToReset;

		for (int j = 0; j < Interactions[i]->Interactions.Num(); j++) {
			SubsystemInstance->ActiveScene->removeSceneObject(Interactions[i]->Interactions[j]);
			SubsystemInstance->AllInteractions.Remove(Interactions[i]);
			//ToReset.Add(Interactions[i]->Interactions[j]);
			//Interactions[i]->Interactions[j].reset();
			Interactions[i]->UnInit();
		}



		/*for (auto ImstkInteraction : Interactions[i]->Interactions) {
			SubsystemInstance->ActiveScene->removeSceneObject(ImstkInteraction);
			SubsystemInstance->AllInteractions.Remove(Interactions[i]);

			ImstkInteraction.reset();
			Interactions[i]->UnInit();
		}*/
	}
	Interactions.Empty();

	SubsystemInstance->ActiveScene->removeSceneObject(ImstkCollidingObject);
	SubsystemInstance->ActiveScene->initialize();
	SubsystemInstance->AllBehaviours.Remove(this);
	bIsInitialized = false;
	SetComponentTickEnabled(false);
	UnInit();
}

FVector UDynamicalModel::GetGeometryPosition()
{
	return UMathUtil::ToUnrealFVec(ImstkCollidingObject->getCollidingGeometry()->getCenter(), true);
}

void UDynamicalModel::AddToScene() 
{
	bDelayInit = false;
	Init();
}

void UDynamicalModel::UnInit()
{
	Super::UnInit();
	Geometry.reset();
	ImstkCollidingObject.reset();
}
