// Fill out your copyright notice in the Description page of Project Settings.


#include "DynamicalModel.h"
#include "KismetProceduralMeshLibrary.h"
#include "CollisionInteraction.h"


void UDynamicalModel::InitializeComponent()
{
	Super::InitializeComponent();

	// Check if game is in play mode (required because InitializeComponent() is run when creating a blueprint of the object)
	if (GetWorld() && GetWorld()->GetGameInstance()) {
		// Set variables to use during execution
		Owner = GetOwner();
		UStaticMeshComponent* MeshComp = (UStaticMeshComponent*)Owner->GetComponentByClass(UStaticMeshComponent::StaticClass());

		if (MeshComp)
			MeshComp->SetMobility(EComponentMobility::Type::Movable);
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
		SubsystemInstance->LogToUnrealAndImstk("Imstk geometry for %s could not be created " + Owner->GetName(), FColor::Red);
		return nullptr;
	}
	return Geometry;

}

void UDynamicalModel::ConvertStaticToProceduralMesh(UStaticMeshComponent* StaticMesh, UProceduralMeshComponent* ProcMesh)
{
	if (!StaticMesh->GetStaticMesh()->bAllowCPUAccess) {
		FMessageLog("PIE").Warning(FText::FromString("'Allow CPU Access' is not enabled for " + StaticMesh->GetStaticMesh().GetFName().ToString() + ". This is required to access static mesh data in the packaged game."));
	}
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

		for (int j = 0; j < Interactions[i]->Interactions.Num(); j++) {
			SubsystemInstance->ActiveScene->removeSceneObject(Interactions[i]->Interactions[j]);
			SubsystemInstance->AllInteractions.Remove(Interactions[i]);
			Interactions[i]->UnInit();
		}
	}
	Interactions.Empty();

	// Remove object from scene and reinitialize the scene
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

int UDynamicalModel::GetNumTriangles()
{
	std::shared_ptr<imstk::SurfaceMesh> MeshGeom = std::dynamic_pointer_cast<imstk::SurfaceMesh>(ImstkCollidingObject->getVisualGeometry());
	if (MeshGeom)
		return MeshGeom->getNumTriangles();
	else
		return -1;
}

TArray<int32> UDynamicalModel::GetTriangleIndices()
{
	std::shared_ptr<imstk::SurfaceMesh> MeshGeom = std::dynamic_pointer_cast<imstk::SurfaceMesh>(ImstkCollidingObject->getVisualGeometry());
	TArray<int32> Indices;
	if(MeshGeom)
		Indices = UMathUtil::ToUnrealIntArray(MeshGeom->getTriangleIndices());
	
	return Indices;
}

int UDynamicalModel::GetNumVertices()
{
	std::shared_ptr<imstk::PointSet> MeshGeom = std::dynamic_pointer_cast<imstk::PointSet>(ImstkCollidingObject->getVisualGeometry());
	if (MeshGeom)
		return MeshGeom->getNumVertices();
	else
		return -1;
}

TArray<FVector> UDynamicalModel::GetVertexPositions()
{
	std::shared_ptr<imstk::PointSet> MeshGeom = std::dynamic_pointer_cast<imstk::PointSet>(ImstkCollidingObject->getVisualGeometry());
	TArray<FVector> Verts;
	if (MeshGeom)
		Verts = UMathUtil::ToUnrealFVecArray(MeshGeom->getVertexPositions(), true);

	return Verts;
}

void UDynamicalModel::UnInit()
{
	Super::UnInit();
	Geometry.reset();
	ImstkCollidingObject.reset();
}
