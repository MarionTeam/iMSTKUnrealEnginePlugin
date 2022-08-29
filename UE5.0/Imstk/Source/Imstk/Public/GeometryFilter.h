// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "imstkGeometry.h"
#include "imstkSphere.h"
#include "imstkCapsule.h"
#include "imstkCylinder.h"
#include "imstkSurfaceMesh.h"
#include "imstkOrientedBox.h"
#include "imstkPlane.h"
#include "imstkLineMesh.h"
#include "MathUtil.h"

#include "Components/StaticMeshComponent.h"
#include "Engine/StaticMesh.h"
#include "Rendering/PositionVertexBuffer.h"
#include "ProceduralMeshComponent.h"
#include "RawIndexBuffer.h"

#include "GeometryFilter.generated.h"

class UImstkController;
class UDynamicalModel;

/** \file GeometryFilter.h
 *  \brief Defines the structs and enum used in the geometry filter
 *  \details
 */

 // Enum that defines the geometry types provided by imstk
UENUM(BlueprintType)
enum EGeometryType
{
	Sphere,
	SurfaceMesh,
	Capsule,
	Cylinder,
	PointSet,
	OrientedBox,
	Plane,
	LineMesh
};

USTRUCT(BlueprintType)
struct FMeshDataStruct
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "General")
		TArray<FVector> Verts;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "General")
		TArray<int32> Indices;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "General")
		TArray<FVector> Normals;

};

USTRUCT(BlueprintType)
struct FGeometryTypeStruct
{
	GENERATED_BODY()

	/** Creates and returns Imstk geometry using parameters and editor values.
	* @return std::shared_ptr<imstk::Geometry> - Created Imstk geometry
	*/
	virtual std::shared_ptr<imstk::Geometry> Init() const {
		return nullptr;
	}

	virtual std::shared_ptr<imstk::Geometry> Init(UDynamicalModel* Model) const {
		return nullptr;
	}

	virtual std::shared_ptr<imstk::Geometry> Init(UImstkController* Controller) const {
		return nullptr;
	}

	/** Calculates and returns the scale applied to Unreal's basic shapes in order to have the same shape as iMSTK's geometry
	* @return FVector - Scale of the geometry, or zero vector if not implemented
	*/
	virtual FVector GetGeomScale(){ return FVector::ZeroVector; }
};


USTRUCT(BlueprintType)
struct FSphereGeomStruct : public FGeometryTypeStruct
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (ClampMin = "0.01"), Category = "General")
		double Radius;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, BlueprintReadWrite, Category = "General")
		FVector GeometryOffset;

	FSphereGeomStruct() { Radius = 1; GeometryOffset = FVector::ZeroVector; };

	/** Creates an Imstk sphere using the provided parameters and editor values.
	* @return std::shared_ptr<imstk::Geometry> - Created Imstk geometry
	*/
	virtual std::shared_ptr<imstk::Geometry> Init() const override;

	virtual FVector GetGeomScale() override;
};

USTRUCT(BlueprintType)
struct FSurfaceMeshGeomStruct : public FGeometryTypeStruct
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "General")
		bool bFlipNormals;

	FSurfaceMeshGeomStruct() { bFlipNormals = false; };

	/** Creates an Imstk surface mesh using the provided parameters and editor values.
	* @param Model The DynamicalModel in Unreal
	* @return std::shared_ptr<imstk::Geometry> - Created Imstk geometry
	*/
	virtual std::shared_ptr<imstk::Geometry> Init(UDynamicalModel* Model) const override;

	/** Creates an Imstk surface mesh using the provided parameters and editor values.
	* @param Controller The Controller in Unreal
	* @return std::shared_ptr<imstk::Geometry> - Created Imstk geometry
	*/
	virtual std::shared_ptr<imstk::Geometry> Init(UImstkController* Controller) const override;

	virtual FVector GetGeomScale() override;
};

USTRUCT(BlueprintType)
struct FCapsuleGeomStruct : public FGeometryTypeStruct
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (ClampMin = "0.01"), Category = "General")
		double Radius = 0.01;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (ClampMin = "0.01"), Category = "General")
		double Length = 0.01;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "General")
		FVector GeometryOffset;

	FCapsuleGeomStruct() { Radius = 1; Length = 1; GeometryOffset = FVector::ZeroVector; };

	/** Creates an Imstk capsule using the provided parameters and editor values.
	* @return std::shared_ptr<imstk::Geometry> - Created Imstk geometry
	*/
	virtual std::shared_ptr<imstk::Geometry> Init() const override;

	virtual FVector GetGeomScale() override;
};

USTRUCT(BlueprintType)
struct FCylinderGeomStruct : public FGeometryTypeStruct
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (ClampMin = "0.01"), Category = "General")
		double Radius = 0.01;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (ClampMin = "0.01"), Category = "General")
		double Length = 0.01;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "General")
		FVector GeometryOffset;

	FCylinderGeomStruct() { Radius = 1; Length = 1; GeometryOffset = FVector::ZeroVector; };

	/** Creates an Imstk Cylinder using the provided parameters and editor values.
	* @return std::shared_ptr<imstk::Geometry> - Created Imstk geometry
	*/
	virtual std::shared_ptr<imstk::Geometry> Init() const override;

	virtual FVector GetGeomScale() override;
};

USTRUCT(BlueprintType)
struct FPointSetGeomStruct : public FGeometryTypeStruct
{
	GENERATED_BODY()

	FPointSetGeomStruct() {};

	/** Creates an Imstk surface mesh using the provided parameters and editor values.
	* @param Model The DynamicalModel in Unreal
	* @return std::shared_ptr<imstk::Geometry> - Created Imstk geometry
	*/
	virtual std::shared_ptr<imstk::Geometry> Init(UDynamicalModel* Model) const override;

	/** Creates an Imstk surface mesh using the provided parameters and editor values.
	* @param Controller The Controller in Unreal
	* @return std::shared_ptr<imstk::Geometry> - Created Imstk geometry
	*/
	virtual std::shared_ptr<imstk::Geometry> Init(UImstkController* Controller) const override;

	virtual FVector GetGeomScale() override;
};


USTRUCT(BlueprintType)
struct FOrientedBoxGeomStruct : public FGeometryTypeStruct
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "General")
		FVector Extents;

	FOrientedBoxGeomStruct() { Extents = FVector::ZeroVector; };

	/** Creates an Imstk Oriented Box using the provided parameters and editor values.
	* @return std::shared_ptr<imstk::Geometry> - Created Imstk geometry
	*/
	virtual std::shared_ptr<imstk::Geometry> Init() const override;

	virtual FVector GetGeomScale() override;
};

USTRUCT(BlueprintType)
struct FPlaneGeomStruct : public FGeometryTypeStruct
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "General")
		FVector Normal;

	FPlaneGeomStruct() { Normal = FVector::ZeroVector; };

	/** Creates an Imstk Plane using the provided parameters and editor values.
	* @return std::shared_ptr<imstk::Geometry> - Created Imstk geometry
	*/
	virtual std::shared_ptr<imstk::Geometry> Init() const override;

	virtual FVector GetGeomScale() override;
};

USTRUCT(BlueprintType)
struct FLineMeshGeomStruct : public FGeometryTypeStruct
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "General")
		TArray<FVector> Vertices;

	FLineMeshGeomStruct() {};

	/** Creates an Imstk Plane using the provided parameters and editor values.
	* @return std::shared_ptr<imstk::Geometry> - Created Imstk geometry
	*/
	virtual std::shared_ptr<imstk::Geometry> Init() const override;

	virtual FVector GetGeomScale() override;
};


USTRUCT(BlueprintType)
struct FGeometryFilter
{
	GENERATED_BODY()

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "General")
		TEnumAsByte<EGeometryType> GeomType;

	// Structs for each shape that can be created in Imstk
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (EditCondition = "GeomType == EGeometryType::Sphere", EditConditionHides), Category = "General")
		FSphereGeomStruct SphereStruct;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (EditCondition = "GeomType == EGeometryType::SurfaceMesh", EditConditionHides), Category = "General")
		FSurfaceMeshGeomStruct MeshStruct;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (EditCondition = "GeomType == EGeometryType::Capsule", EditConditionHides), Category = "General")
		FCapsuleGeomStruct CapsuleStruct;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (EditCondition = "GeomType == EGeometryType::Cylinder", EditConditionHides), Category = "General")
		FCylinderGeomStruct CylinderStruct;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (EditCondition = "GeomType == EGeometryType::PointSet", EditConditionHides), Category = "General")
		FPointSetGeomStruct PointSetStruct;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (EditCondition = "GeomType == EGeometryType::OrientedBox", EditConditionHides), Category = "General")
		FOrientedBoxGeomStruct OrientedBoxStruct;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (EditCondition = "GeomType == EGeometryType::Plane", EditConditionHides), Category = "General")
		FPlaneGeomStruct PlaneStruct;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (EditCondition = "GeomType == EGeometryType::LineMesh", EditConditionHides), Category = "General")
		FLineMeshGeomStruct LineMeshStruct;

public:

	/** Default constructor.
	* @return None
	*/
	FGeometryFilter();

	/** Creates Imstk geometry of the type selected in editor using the values provided
	* @param Actor Owning actor in Unreal
	* @return std::shared_ptr<imstk::Geometry> - Created Imstk geometry
	*/
	std::shared_ptr<imstk::Geometry> Init(UDynamicalModel* Model);

	std::shared_ptr<imstk::Geometry> Init(UImstkController* Controller);

	/** Calculates and returns the scale applied to Unreal's basic shapes in order to have the same shape as iMSTK's geometry
	* @return FVector - Scale of the geometry or zero vector if not implemented
	*/
	FVector GetGeomScale();

	/** Returns the amount the geometry is offset within iMSTK 
	* @return FVector - Offset of the geometry or zero vector if not implemented
	*/
	FVector GetGeomOffset();
};