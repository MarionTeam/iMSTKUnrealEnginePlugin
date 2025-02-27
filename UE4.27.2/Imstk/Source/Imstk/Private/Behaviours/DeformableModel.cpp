// Fill out your copyright notice in the Description page of Project Settings.


#include "DeformableModel.h"

#include "iMSTK-5.0/imstkPbdModel.h"
#include "iMSTK-5.0/imstkSelectEnclosedPoints.h"
#include "iMSTK-5.0/imstkOneToOneMap.h"
#include "iMSTK-5.0/imstkTetrahedralMesh.h"

// TODO: Normals get flipped seemingly at random. It seems to work as it is but kind of hard to predict
//
//void UDeformableModel::OnRegister()
//{
//	Super::OnRegister();
//
//	// This will hide for all dynamical models
//	/*
//	Enum->SetMetaData(TEXT("Hidden"), TEXT(""), 0);
//	Enum->SetMetaData(TEXT("Hidden"), TEXT(""), 2);
//	Enum->SetMetaData(TEXT("Hidden"), TEXT(""), 3);
//	*/
//}
//
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
		UStaticMeshComponent* BoundaryMeshComp = (UStaticMeshComponent*)Actor->GetComponentByClass(UStaticMeshComponent::StaticClass());
		if (!BoundaryMeshComp) {
			UE_LOG(LogTemp, Error, TEXT("No Mesh attached to Boundary Condition Actor for %s"), *Owner->GetName());
			return;
		}

		UStaticMesh* BoundaryMesh = BoundaryMeshComp->GetStaticMesh();

		// TODO: this could be made into a util function that creates an imstk mesh based on unreal values
		FPositionVertexBuffer* VertexBuffer = &BoundaryMesh->GetRenderData()->LODResources[0].VertexBuffers.PositionVertexBuffer;
		FRawStaticIndexBuffer* IndexBuffer = &BoundaryMesh->GetRenderData()->LODResources[0].IndexBuffer;

		std::shared_ptr<imstk::SurfaceMesh> BoundaryMeshGeom = std::make_shared<imstk::SurfaceMesh>();

		// Get vertices and indices in the mesh and set those values in the imstk mesh
		TArray<FVector> Vertices;
		for (uint32 i = 0; i < VertexBuffer->GetNumVertices(); i++) {
			Vertices.Add(VertexBuffer->VertexPosition(i));
		}
		TArray<int> Indices;
		for (int32 i = 0; i < IndexBuffer->GetNumIndices(); i++) {
			Indices.Add(IndexBuffer->GetIndex(i));
		}
		BoundaryMeshGeom->initialize(UMathUtil::ToImstkVecDataArray3d(Vertices), UMathUtil::ToImstkVecDataArray3i(Indices));
		BoundaryMeshGeom->scale(UMathUtil::ToImstkVec3(Actor->GetActorScale()), imstk::Geometry::TransformType::ApplyToData);
		BoundaryMeshGeom->rotate(UMathUtil::ToImstkQuat(Actor->GetActorRotation().Quaternion()), imstk::Geometry::TransformType::ApplyToData);
		BoundaryMeshGeom->updatePostTransformData();
		BoundaryMeshGeom->translate(UMathUtil::ToImstkVec3(Actor->GetActorLocation()), imstk::Geometry::TransformType::ApplyToData);

		std::shared_ptr<imstk::SelectEnclosedPoints> EnclosedPoints = std::make_shared<imstk::SelectEnclosedPoints>();

		EnclosedPoints->setInputMesh(BoundaryMeshGeom);
		EnclosedPoints->setInputPoints(std::dynamic_pointer_cast<imstk::PointSet>(PbdObject->getPhysicsGeometry()));
		EnclosedPoints->setUsePruning(false);
		EnclosedPoints->update();


		imstk::DataArray<unsigned char>& IsInside = *EnclosedPoints->getIsInsideMask().get();

		for (int i = 0; i < IsInside.size(); i++) {
			if (IsInside[i] && !bInverseBoundary)
				FixedNodes.Add(i);
			else if (!IsInside[i] && bInverseBoundary)
				FixedNodes.Add(i);

		}

		Actor->Destroy();
	}
}

void UDeformableModel::UnInit()
{
	Super::UnInit();
	PbdObject.reset();
}
