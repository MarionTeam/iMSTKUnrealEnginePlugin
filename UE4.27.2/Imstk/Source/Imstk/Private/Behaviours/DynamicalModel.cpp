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

// TODO: change some of the naming (confusing to call it getcollidinggeometry when it returns geometry and not colliding object, etc)
std::shared_ptr<imstk::Geometry> UDynamicalModel::GetCollidingGeometry()
{
	// If already created return cached value
	if (Geometry)
		return Geometry;

	// Initialize imstk geometry
	//bIsGeomCreated = true;
	Geometry = GeomFilter.Init(Owner);
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

void UDynamicalModel::UnInit()
{
	Super::UnInit();
	Geometry.reset();
	ImstkCollidingObject.reset();
}
