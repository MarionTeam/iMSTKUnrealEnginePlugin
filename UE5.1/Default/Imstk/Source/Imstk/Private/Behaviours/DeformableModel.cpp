// Fill out your copyright notice in the Description page of Project Settings.


#include "DeformableModel.h"

#include "imstkPbdModel.h"
#include "imstkSelectEnclosedPoints.h"
#include "MeshDescription.h"


void UDeformableModel::InitializeComponent()
{
	Super::InitializeComponent();
}

// Called when the game starts or when spawned
void UDeformableModel::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void UDeformableModel::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UDeformableModel::UpdateModel()
{
}

void UDeformableModel::ProcessBoundaryConditions()
{
	if (BoundaryConditionActors.Num() < 1)
		return;

	// If there were fixed nodes set in the editor, do not override with boundary conditions
	if (FixedNodes.Num() > 0) {
		for(AActor* Actor : BoundaryConditionActors)
			Actor->Destroy();
		return;
	}

	FixedNodes.Empty();

	// Get the mesh from the assigned variable
	for (AActor* Actor : BoundaryConditionActors) {
		if (!Actor) 
			continue;
		
		UStaticMeshComponent* BoundaryMeshComp = (UStaticMeshComponent*)Actor->GetComponentByClass(UStaticMeshComponent::StaticClass());
		if (!BoundaryMeshComp) {
			SubsystemInstance->LogToUnrealAndImstk("No mesh attached to Bounding Actor for " + Owner->GetName(), FColor::Red);
			continue;
		}
		if (!BoundaryMeshComp->GetStaticMesh()) {
			SubsystemInstance->LogToUnrealAndImstk("No mesh attached to static mesh component of Bounding Actor for " + Owner->GetName(), FColor::Red);
			continue;
		}

		FStaticMeshRenderData* BoundaryRenderData = BoundaryMeshComp->GetStaticMesh()->GetRenderData();

		if (!BoundaryMeshComp->GetStaticMesh()->bAllowCPUAccess) 
			FMessageLog("PIE").Warning(FText::FromString("'Allow CPU Access' is not enabled for " + BoundaryMeshComp->GetStaticMesh()->GetFName().ToString() + ". This is required to access static mesh data in the packaged game."));
		

		// TODO: this could be made into a util function that creates an imstk mesh based on unreal values
		FPositionVertexBuffer* VertexBuffer = &BoundaryRenderData->LODResources[0].VertexBuffers.PositionVertexBuffer;
		FRawStaticIndexBuffer* IndexBuffer = &BoundaryRenderData->LODResources[0].IndexBuffer;

		// Get vertices and indices in the mesh and set those values in the imstk mesh
		TArray<FVector> Vertices;
		for (uint32 i = 0; i < VertexBuffer->GetNumVertices(); i++) {
			Vertices.Add(FVector(VertexBuffer->VertexPosition(i)));
		}
		TArray<int> Indices;
		for (int32 i = 0; i < IndexBuffer->GetNumIndices(); i++) {
			Indices.Add(IndexBuffer->GetIndex(i));
		}

		std::shared_ptr<imstk::SurfaceMesh> BoundaryMeshGeom = std::make_shared<imstk::SurfaceMesh>();
		// Create the geometry in iMSTK and make it reflect Unreal
		BoundaryMeshGeom->initialize(UMathUtil::ToImstkVecDataArray3d(Vertices, true), UMathUtil::ToImstkVecDataArray3i(Indices));
		BoundaryMeshGeom->scale(UMathUtil::ToImstkVec3d(Actor->GetActorScale(), false), imstk::Geometry::TransformType::ApplyToData);
		BoundaryMeshGeom->rotate(UMathUtil::ToImstkQuat(Actor->GetActorRotation().Quaternion()), imstk::Geometry::TransformType::ApplyToData);
		BoundaryMeshGeom->updatePostTransformData();
		BoundaryMeshGeom->translate(UMathUtil::ToImstkVec3d(Actor->GetActorLocation(), true), imstk::Geometry::TransformType::ApplyToData);

		std::shared_ptr<imstk::SelectEnclosedPoints> EnclosedPoints = std::make_shared<imstk::SelectEnclosedPoints>();

		EnclosedPoints->setInputMesh(BoundaryMeshGeom);
		EnclosedPoints->setInputPoints(std::dynamic_pointer_cast<imstk::PointSet>(PbdObject->getPhysicsGeometry()));
		EnclosedPoints->setUsePruning(false);
		EnclosedPoints->update();


		imstk::DataArray<unsigned char>& IsInside = *EnclosedPoints->getIsInsideMask().get();

		// Adds the fixed vertices to the list
		for (int i = 0; i < IsInside.size(); i++) {
			if (IsInside[i] && !bInverseBoundary)
				FixedNodes.Add(i);
			else if (!IsInside[i] && bInverseBoundary)
				FixedNodes.Add(i);

		}

		// Remove the boundary condition actors
		Actor->Destroy();
	}
}

void UDeformableModel::SetFixedVerts(TArray<int> NewFixedVerts) 
{
	PbdObject->getPbdBody()->fixedNodeIds.clear();
	for (const int Num : NewFixedVerts) {
		PbdObject->getPbdBody()->fixedNodeIds.push_back(Num);
	}
	PbdObject->initialize();
}

void UDeformableModel::UnInit()
{
	Super::UnInit();
	PbdObject.reset();
}
