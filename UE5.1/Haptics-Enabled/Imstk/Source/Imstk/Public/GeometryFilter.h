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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "iMSTK")
		TArray<FVector> Verts;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "iMSTK")
		TArray<int32> Indices;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "iMSTK")
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

	virtual ~FGeometryTypeStruct() {};
};


USTRUCT(BlueprintType)
struct FSphereGeomStruct : public FGeometryTypeStruct
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (ClampMin = "0.01"), Category = "iMSTK")
		double Radius;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, BlueprintReadWrite, Category = "iMSTK")
		FVector GeometryOffset;

	FSphereGeomStruct() { Radius = 50; GeometryOffset = FVector::ZeroVector; };

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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "iMSTK")
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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (ClampMin = "0.01"), Category = "iMSTK")
		double Radius = 0.01;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (ClampMin = "0.01"), Category = "iMSTK")
		double Length = 0.01;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "iMSTK")
		FVector GeometryOffset;

	FCapsuleGeomStruct() { Radius = 12.5; Length = 50; GeometryOffset = FVector::ZeroVector; };

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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (ClampMin = "0.01"), Category = "iMSTK")
		double Radius = 0.01;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (ClampMin = "0.01"), Category = "iMSTK")
		double Length = 0.01;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "iMSTK")
		FVector GeometryOffset;

	FCylinderGeomStruct() { Radius = 12.5; Length = 50; GeometryOffset = FVector::ZeroVector; };

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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "iMSTK")
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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "iMSTK")
		FVector Normal;

	FPlaneGeomStruct() { Normal = FVector(0,0,1); };

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
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "iMSTK")
		TArray<FVector> Vertices;

	FLineMeshGeomStruct() { Vertices = TArray<FVector>(); };

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

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "iMSTK")
		TEnumAsByte<EGeometryType> GeomType;

	// Structs for each shape that can be created in Imstk
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (EditCondition = "GeomType == EGeometryType::Sphere", EditConditionHides), Category = "iMSTK")
		FSphereGeomStruct SphereStruct;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (EditCondition = "GeomType == EGeometryType::SurfaceMesh", EditConditionHides), Category = "iMSTK")
		FSurfaceMeshGeomStruct MeshStruct;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (EditCondition = "GeomType == EGeometryType::Capsule", EditConditionHides), Category = "iMSTK")
		FCapsuleGeomStruct CapsuleStruct;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (EditCondition = "GeomType == EGeometryType::Cylinder", EditConditionHides), Category = "iMSTK")
		FCylinderGeomStruct CylinderStruct;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (EditCondition = "GeomType == EGeometryType::PointSet", EditConditionHides), Category = "iMSTK")
		FPointSetGeomStruct PointSetStruct;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (EditCondition = "GeomType == EGeometryType::OrientedBox", EditConditionHides), Category = "iMSTK")
		FOrientedBoxGeomStruct OrientedBoxStruct;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (EditCondition = "GeomType == EGeometryType::Plane", EditConditionHides), Category = "iMSTK")
		FPlaneGeomStruct PlaneStruct;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (EditCondition = "GeomType == EGeometryType::LineMesh", EditConditionHides), Category = "iMSTK")
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