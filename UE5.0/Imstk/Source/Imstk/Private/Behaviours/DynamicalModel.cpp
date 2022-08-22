// Fill out your copyright notice in the Description page of Project Settings.


#include "DynamicalModel.h"
#include "KismetProceduralMeshLibrary.h"

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
		Owner->SetActorEnableCollision(false);
		SubsystemInstance = GetWorld()->GetGameInstance()->GetSubsystem<UImstkSubsystem>();
	}
}

std::shared_ptr<imstk::Geometry> UDynamicalModel::GetImstkGeometry()
{
	// If already created return cached value
	if (Geometry)
		return Geometry;

	// Initialize imstk geometry
	Geometry = GeomFilter.Init(this);
	if (!Geometry) {
		UE_LOG(LogTemp, Error, TEXT("Imstk geometry for %s could not be created"), *Owner->GetName());
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

void UDynamicalModel::UnInit()
{
	Super::UnInit();
	Geometry.reset();
	ImstkCollidingObject.reset();
}
