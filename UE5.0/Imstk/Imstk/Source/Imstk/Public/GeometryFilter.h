// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "iMSTK-5.0/imstkGeometry.h"
#include "iMSTK-5.0/imstkSphere.h"
#include "iMSTK-5.0/imstkCapsule.h"
#include "iMSTK-5.0/imstkCylinder.h"
#include "iMSTK-5.0/imstkSurfaceMesh.h"
#include "iMSTK-5.0/imstkOrientedBox.h"
#include "iMSTK-5.0/imstkPlane.h"
#include "MathUtil.h"

#include "Components/StaticMeshComponent.h"
#include "Engine/StaticMesh.h"
#include "Rendering/PositionVertexBuffer.h"
#include "ProceduralMeshComponent.h"
#include "RawIndexBuffer.h"

#include "GeometryFilter.generated.h"

/** \file GeometryFilter.h
 *  \brief Defines the structs and enum used in the geometry filter
 *  \details Geometry structs should be moved to another class
 */

 // Enum that defines the geometry types provided by imstk
UENUM()
enum EGeometryType
{
	Sphere,
	SurfaceMesh,
	Capsule,
	Cylinder,
	PointSet,
	OrientedBox,
	Plane
};

USTRUCT(BlueprintType)
struct FGeometryTypeStruct
{
	GENERATED_BODY()
		// Hidden value that corresponds to the enum value
		UPROPERTY()
		int EnumVal = 0;

	/** Creates and returns Imstk geometry using parameters and editor values.
	* @return std::shared_ptr<imstk::Geometry> - Created Imstk geometry
	*/
	std::shared_ptr<imstk::Geometry> Init(FVector Position, FQuat Rotation) const {
		return nullptr;
	}
};

// TODO: Move this into its own classes for geometry?

USTRUCT(BlueprintType)
struct FSphereGeomStruct : public FGeometryTypeStruct
{
	GENERATED_BODY()

		int EnumVal = 0;

	UPROPERTY(EditAnywhere, Category = "General")
		double Radius;

	/** Creates an Imstk sphere using the provided parameters and editor values.
	* @return std::shared_ptr<imstk::Geometry> - Created Imstk geometry
	*/
	std::shared_ptr<imstk::Geometry> Init(AActor* Actor) const {
		std::shared_ptr<imstk::Sphere> SphereGeom = std::make_shared<imstk::Sphere>();

		//SphereGeom->setPosition(UMathUtil::ToImstkVec3(Actor->GetActorLocation()));
		SphereGeom->setRadius(Radius);
		//SphereGeom->setRotation(UMathUtil::ToImstkQuat(Actor->GetActorRotation().Quaternion()));
		SphereGeom->updatePostTransformData();
		return SphereGeom;
	}

	FSphereGeomStruct()
	{
		//Radius = 0;
	}
};

USTRUCT(BlueprintType)
struct FSurfaceMeshGeomStruct : public FGeometryTypeStruct
{
	GENERATED_BODY()

		int EnumVal = 1;

	UPROPERTY(EditAnywhere, Category = "General")
		bool bFlipNormals;

	/** Creates an Imstk surface mesh using the provided parameters and editor values.
	* @return std::shared_ptr<imstk::Geometry> - Created Imstk geometry
	*/
	std::shared_ptr<imstk::Geometry> Init(AActor* Actor) const {
		std::shared_ptr<imstk::SurfaceMesh> MeshGeom = std::make_shared<imstk::SurfaceMesh>();
		//TCHAR_TO_UTF8(*(Actor->GetName() + "_geom"))

		UStaticMeshComponent* StaticMeshComp = (UStaticMeshComponent*)Actor->GetComponentByClass(UStaticMeshComponent::StaticClass());
		UProceduralMeshComponent* ProcMeshComp = (UProceduralMeshComponent*)Actor->GetComponentByClass(UProceduralMeshComponent::StaticClass());
		if (StaticMeshComp) {
			// Get vertices and indices from static mesh and create imstk geometry
			FPositionVertexBuffer* VertexBuffer = &StaticMeshComp->GetStaticMesh()->GetRenderData()->LODResources[0].VertexBuffers.PositionVertexBuffer;
			FRawStaticIndexBuffer* IndexBuffer = &StaticMeshComp->GetStaticMesh()->GetRenderData()->LODResources[0].IndexBuffer;

			/*for (int32 i = 0; i < IndexBuffer->GetNumIndices(); i++) {
				UE_LOG(LogTemp, Warning, TEXT("%s"), *(VertexBuffer->VertexPosition(i).ToString()));
				UE_LOG(LogTemp, Warning, TEXT("%s"), *(FString::FromInt(IndexBuffer->GetIndex(i))));
			}

			UE_LOG(LogTemp, Warning, TEXT("%s"), *(FString::FromInt(IndexBuffer->GetNumIndices())));*/

			// Get vertices and indices in the mesh and set those values in the imstk mesh
			TArray<FVector> Vertices;
			for (uint32 i = 0; i < VertexBuffer->GetNumVertices(); i++) {
				Vertices.Add(FVector(VertexBuffer->VertexPosition(i)));
			}

			// TODO: Could change this to array view?
			TArray<int> Indices;
			for (int32 i = 0; i < IndexBuffer->GetNumIndices(); i++) {
				Indices.Add(IndexBuffer->GetIndex(i));
			}
			MeshGeom->initialize(UMathUtil::ToImstkVecDataArray3d(Vertices), UMathUtil::ToImstkVecDataArray3i(Indices));
			if (bFlipNormals)
				MeshGeom->flipNormals();
			MeshGeom->scale(UMathUtil::ToImstkVec3(Actor->GetActorScale()), imstk::Geometry::TransformType::ApplyToData);
			MeshGeom->updatePostTransformData();
			// Not sure if this line is required, however it causes all the vertices to be removed except one
			//MeshGeom->setRotation(UMathUtil::ToImstkQuat(Actor->GetActorRotation().Quaternion()));

			//for (int i = 0; i < MeshGeom->getNumVertices(); i++) {
			//	imstk::Vec3d Vert = MeshGeom->getVertexPosition(i);
			//	UE_LOG(LogTemp, Warning, TEXT("%s"), *("X: " + FString::SanitizeFloat(Vert.x()) + " Y: " + FString::SanitizeFloat(Vert.y()) + " Z: " + FString::SanitizeFloat(Vert.z())));
			//	//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, "X: " + FString::SanitizeFloat(Vert.x()) + " Y: " + FString::SanitizeFloat(Vert.y()) + " Z: " + FString::SanitizeFloat(Vert.z()));
			//}
			return MeshGeom;
		}
		else if (ProcMeshComp) {
			// Get vertices and indices from procedural mesh and create imstk geometry
			TArray<FProcMeshVertex> VertexBuffer = ProcMeshComp->GetProcMeshSection(0)->ProcVertexBuffer;
			TArray<uint32> IndexBuffer = ProcMeshComp->GetProcMeshSection(0)->ProcIndexBuffer;

			// Get vertices and indices in the mesh and set those values in the imstk mesh
			TArray<FVector> Vertices;
			for (int32 i = 0; i < VertexBuffer.Num(); i++) {
				Vertices.Add(VertexBuffer[i].Position);
			}

			// TODO: Could change this to array view?
			TArray<int> Indices;
			for (int32 i = 0; i < IndexBuffer.Num(); i++) {
				Indices.Add(IndexBuffer[i]);
			}

			MeshGeom->initialize(UMathUtil::ToImstkVecDataArray3d(Vertices), UMathUtil::ToImstkVecDataArray3i(Indices));

			if (bFlipNormals)
				MeshGeom->flipNormals();
			MeshGeom->scale(UMathUtil::ToImstkVec3(Actor->GetActorScale()), imstk::Geometry::TransformType::ApplyToData);
			MeshGeom->updatePostTransformData();
			return MeshGeom;

		}
		else {
			// ERROR
			return nullptr;
		}
	}

	FSurfaceMeshGeomStruct()
	{

	}
};

USTRUCT(BlueprintType)
struct FCapsuleGeomStruct : public FGeometryTypeStruct
{
	GENERATED_BODY()

		int EnumVal = 2;

	UPROPERTY(EditAnywhere, Meta = (ClampMin = "0.01"), Category = "General")
		double Radius = 0.01;;
	UPROPERTY(EditAnywhere, Meta = (ClampMin = "0.01"), Category = "General")
		double Length = 0.01;;

	/** Creates an Imstk capsule using the provided parameters and editor values.
	* @return std::shared_ptr<imstk::Geometry> - Created Imstk geometry
	*/
	std::shared_ptr<imstk::Geometry> Init(AActor* Actor) const {
		std::shared_ptr<imstk::Capsule> CapsuleGeom = std::make_shared<imstk::Capsule>();

		//CapsuleGeom->setPosition(UMathUtil::ToImstkVec3(Actor->GetActorLocation()));
		CapsuleGeom->setRadius(Radius);
		CapsuleGeom->setLength(Length);
		//CapsuleGeom->setOrientation(UMathUtil::ToImstkQuat(Actor->GetActorRotation().Quaternion()));
		CapsuleGeom->updatePostTransformData();
		return CapsuleGeom;
	}

	FCapsuleGeomStruct()
	{
		//Radius = 0;
	}
};

USTRUCT(BlueprintType)
struct FCylinderGeomStruct : public FGeometryTypeStruct
{
	GENERATED_BODY()

		int EnumVal = 3;

	UPROPERTY(EditAnywhere, Meta = (ClampMin = "0.01"), Category = "General")
		double Radius = 0.01;
	UPROPERTY(EditAnywhere, Meta = (ClampMin = "0.01"), Category = "General")
		double Length = 0.01;

	/** Creates an Imstk Cylinder using the provided parameters and editor values.
	* @return std::shared_ptr<imstk::Geometry> - Created Imstk geometry
	*/
	std::shared_ptr<imstk::Geometry> Init(AActor* Actor) const {
		std::shared_ptr<imstk::Cylinder> CylinderGeom = std::make_shared<imstk::Cylinder>();

		//CylinderGeom->setPosition(UMathUtil::ToImstkVec3(Actor->GetActorLocation()));
		CylinderGeom->setRadius(Radius);
		CylinderGeom->setLength(Length);
		//CylinderGeom->setOrientation(UMathUtil::ToImstkQuat(Actor->GetActorRotation().Quaternion()));
		CylinderGeom->updatePostTransformData();
		return CylinderGeom;
	}

	FCylinderGeomStruct()
	{

	}
};

USTRUCT(BlueprintType)
struct FPointSetGeomStruct : public FGeometryTypeStruct
{
	GENERATED_BODY()

		int EnumVal = 4;

	/** Creates an Imstk point set using the provided parameters and editor values.
	* @return std::shared_ptr<imstk::Geometry> - Created Imstk geometry
	*/
	std::shared_ptr<imstk::Geometry> Init(AActor* Actor) const {
		std::shared_ptr<imstk::PointSet> MeshGeom = std::make_shared<imstk::PointSet>();

		UStaticMeshComponent* StaticMeshComp = (UStaticMeshComponent*)Actor->GetComponentByClass(UStaticMeshComponent::StaticClass());
		UProceduralMeshComponent* ProcMeshComp = (UProceduralMeshComponent*)Actor->GetComponentByClass(UProceduralMeshComponent::StaticClass());
		if (StaticMeshComp) {
			FPositionVertexBuffer* VertexBuffer = &StaticMeshComp->GetStaticMesh()->GetRenderData()->LODResources[0].VertexBuffers.PositionVertexBuffer;

			// Get vertices and indices in the mesh and set those values in the imstk mesh
			TArray<FVector> Vertices;
			for (uint32 i = 0; i < VertexBuffer->GetNumVertices(); i++) {
				Vertices.Add(FVector(VertexBuffer->VertexPosition(i)));
			}

			MeshGeom->initialize(UMathUtil::ToImstkVecDataArray3d(Vertices));
			MeshGeom->scale(UMathUtil::ToImstkVec3(Actor->GetActorScale()), imstk::Geometry::TransformType::ApplyToData);
			MeshGeom->updatePostTransformData();
			//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, FString(MeshGeom->getName().c_str()));
			return MeshGeom;
		}
		else if (ProcMeshComp) {

			TArray<FProcMeshVertex> VertexBuffer = ProcMeshComp->GetProcMeshSection(0)->ProcVertexBuffer;

			// Get vertices and indices in the mesh and set those values in the imstk mesh
			TArray<FVector> Vertices;
			for (int32 i = 0; i < VertexBuffer.Num(); i++) {
				Vertices.Add(VertexBuffer[i].Position);
			}

			MeshGeom->initialize(UMathUtil::ToImstkVecDataArray3d(Vertices));
			MeshGeom->scale(UMathUtil::ToImstkVec3(Actor->GetActorScale()), imstk::Geometry::TransformType::ApplyToData);
			MeshGeom->updatePostTransformData();
			//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, FString(MeshGeom->getName().c_str()));
			return MeshGeom;

		}
		else {
			// ERROR
			return nullptr;
		}
	}

	FPointSetGeomStruct()
	{

	}
};


USTRUCT(BlueprintType)
struct FOrientedBoxGeomStruct : public FGeometryTypeStruct
{
	GENERATED_BODY()

		int EnumVal = 5;

	UPROPERTY(EditAnywhere, Category = "General")
		FVector Extents;

	/** Creates an Imstk Oriented Box using the provided parameters and editor values.
	* @return std::shared_ptr<imstk::Geometry> - Created Imstk geometry
	*/
	std::shared_ptr<imstk::Geometry> Init(AActor* Actor) const {
		std::shared_ptr<imstk::OrientedBox> BoxGeom = std::make_shared<imstk::OrientedBox>();
		BoxGeom->setExtents(UMathUtil::ToImstkVec3(Extents));

		//BoxGeom->scale(UMathUtil::ToImstkVec3(Actor->GetActorScale()), imstk::Geometry::TransformType::ApplyToData);
		//BoxGeom->rotate(UMathUtil::ToImstkQuat(Actor->GetActorRotation().Quaternion()), imstk::Geometry::TransformType::ApplyToData);
		//BoxGeom->translate(UMathUtil::ToImstkVec3(Actor->GetActorLocation()), imstk::Geometry::TransformType::ApplyToData);
		//BoxGeom->updatePostTransformData();
		return BoxGeom;
	}

	FOrientedBoxGeomStruct()
	{

	}
};

USTRUCT(BlueprintType)
struct FPlaneGeomStruct : public FGeometryTypeStruct
{
	GENERATED_BODY()

		int EnumVal = 6;

	UPROPERTY(EditAnywhere, Category = "General")
		FVector Normal;

	/** Creates an Imstk Plane using the provided parameters and editor values.
	* @return std::shared_ptr<imstk::Geometry> - Created Imstk geometry
	*/
	std::shared_ptr<imstk::Geometry> Init(AActor* Actor) const {
		std::shared_ptr<imstk::Plane> PlaneGeom = std::make_shared<imstk::Plane>();
		PlaneGeom->setNormal(UMathUtil::ToImstkVec3(Normal));

		//BoxGeom->scale(UMathUtil::ToImstkVec3(Actor->GetActorScale()), imstk::Geometry::TransformType::ApplyToData);
		//BoxGeom->rotate(UMathUtil::ToImstkQuat(Actor->GetActorRotation().Quaternion()), imstk::Geometry::TransformType::ApplyToData);
		//BoxGeom->translate(UMathUtil::ToImstkVec3(Actor->GetActorLocation()), imstk::Geometry::TransformType::ApplyToData);
		//BoxGeom->updatePostTransformData();
		return PlaneGeom;
	}

	FPlaneGeomStruct()
	{

	}
};


USTRUCT(BlueprintType)
struct FGeometryFilter
{
	GENERATED_BODY()

		UPROPERTY(EditAnywhere, Category = "General")
		TEnumAsByte<EGeometryType> GeomType;

	// TODO: These structures being visible from other classes is not great
	// Structs for each shape that can be created in Imstk
	UPROPERTY(EditAnywhere, meta = (EditCondition = "GeomType == EGeometryType::Sphere", EditConditionHides), Category = "General")
		FSphereGeomStruct SphereStruct;

	UPROPERTY(EditAnywhere, meta = (EditCondition = "GeomType == EGeometryType::SurfaceMesh", EditConditionHides), Category = "General")
		FSurfaceMeshGeomStruct MeshStruct;

	UPROPERTY(EditAnywhere, meta = (EditCondition = "GeomType == EGeometryType::Capsule", EditConditionHides), Category = "General")
		FCapsuleGeomStruct CapsuleStruct;

	UPROPERTY(EditAnywhere, meta = (EditCondition = "GeomType == EGeometryType::Cylinder", EditConditionHides), Category = "General")
		FCapsuleGeomStruct CylinderStruct;

	UPROPERTY(EditAnywhere, meta = (EditCondition = "GeomType == EGeometryType::PointSet", EditConditionHides), Category = "General")
		FPointSetGeomStruct PointSetStruct;

	UPROPERTY(EditAnywhere, meta = (EditCondition = "GeomType == EGeometryType::OrientedBox", EditConditionHides), Category = "General")
		FOrientedBoxGeomStruct OrientedBoxStruct;

	UPROPERTY(EditAnywhere, meta = (EditCondition = "GeomType == EGeometryType::Plane", EditConditionHides), Category = "General")
		FPlaneGeomStruct PlaneStruct;

	/** Creates Imstk geometry of the type selected in editor using the values provided
	* @return std::shared_ptr<imstk::Geometry> - Created Imstk geometry
	*/
	std::shared_ptr<imstk::Geometry> Init(AActor* Actor)
	{
		switch (GeomType)
		{
		case 0:
			return SphereStruct.Init(Actor);
		case 1:
			return MeshStruct.Init(Actor);
		case 2:
			return CapsuleStruct.Init(Actor);
		case 3:
			return CylinderStruct.Init(Actor);
		case 4:
			return PointSetStruct.Init(Actor);
		case 5:
			return OrientedBoxStruct.Init(Actor);
		case 6:
			return PlaneStruct.Init(Actor);
		}
		return nullptr;
	}

	//UPROPERTY(EditAnywhere)
	//	FGeometryTypeStruct GeomStruct;

	//// Call when editor values change to update the shown structure
	//void Update()
	//{
	//	// Delete the existing struct
	//	//delete(&GeomStruct);

	//	// Create the new struct
	//	if (GeomStruct.EnumVal != GeomType) {
	//		switch (GeomStruct.EnumVal)
	//		{
	//			case 1:
	//				GeomStruct = FSphereGeomStruct();
	//				break;
	//			case 2:
	//				GeomStruct = FCubeGeomStruct();
	//				break;
	//			default:
	//				break;
	//		}

	//	}
	//}

	/** Default constructor.
	* @return None
	*/
	FGeometryFilter()
	{
		// Default to sphere
		GeomType = EGeometryType::Sphere;
		//GeomStruct = FSphereGeomStruct();
	}
};