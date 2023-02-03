// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DeformableModel.h"
#include "Components/SplineComponent.h"
#include "Components/SplineMeshComponent.h"
#include "ConnectiveTissue.generated.h"

USTRUCT()
struct FSplineLineMeshData
{
	GENERATED_BODY()

	UPROPERTY()
		USplineComponent* SplineComp;

	UPROPERTY()
		int IndexA;
	UPROPERTY()
		int IndexB;

	FSplineLineMeshData(){}
	FSplineLineMeshData(USplineComponent* NewSplineComp, int NewIndexA, int NewIndexB) {
		SplineComp = NewSplineComp;
		IndexA = NewIndexA;
		IndexB = NewIndexB;
	}
};

/** \file ConnectiveTissue.h
 *  \brief Creates connective tissue strands between two PBD models
 *  \details Using this component, especially with high segments per strand and strands per face can cause significant performance impacts. When starting the game there is a lot of overhead for this creating the splines and spline meshes causing the game to stall when starting.
 */
UCLASS(ClassGroup = (Imstk), meta = (BlueprintSpawnableComponent), hidecategories = ("iMSTK|Geometry"))
class IMSTK_API UConnectiveTissue : public UDeformableModel
{
	GENERATED_BODY()

public:
	virtual void InitializeComponent() override;

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	virtual void Init() override;

	virtual void UpdateModel() override;

	// One deformable model the connective tissue is generated between
	UPROPERTY(EditAnywhere, Category = "iMSTK|ConnectiveTissue")
		AActor* PBDActorA;

	// One deformable model the connective tissue is generated between
	UPROPERTY(EditAnywhere, Category = "iMSTK|ConnectiveTissue")
		AActor* PBDActorB;

	// Static mesh that is generated along the spline
	UPROPERTY(EditAnywhere, Category = "iMSTK|ConnectiveTissue|Spline")
		UStaticMesh* SplineMesh;

	// Forward direction of the spine mesh
	UPROPERTY(EditAnywhere, Category = "iMSTK|ConnectiveTissue|Spline")
		TEnumAsByte<ESplineMeshAxis::Type> ForwardAxis;

	// Material for the spline mesh
	UPROPERTY(EditAnywhere, Category = "iMSTK|ConnectiveTissue|Spline")
		class UMaterialInterface* SplineMeshMaterial;

	// Maximum distance the connective tissue is made. Warning: Increasing can significantly impact performance
	UPROPERTY(EditAnywhere, Meta = (ClampMin = "0"), Category = "iMSTK|ConnectiveTissue")
		float MaxDistance = 100;

	// Number of strands per face on the deformable models. Warning: Increasing can significantly impact performance
	UPROPERTY(EditAnywhere, Meta = (ClampMin = "0"), Category = "iMSTK|ConnectiveTissue")
		float StrandsPerFace = 2;

	// Number of segments on each strand between the deformable models. Warning: Increasing can significantly impact performance
	UPROPERTY(EditAnywhere, Meta = (ClampMin = "0"), Category = "iMSTK|ConnectiveTissue")
		int SegmentsPerStrand = 2;

	// Whether or not the tissue is tearable. Note: Do partitioning must be set to false
	UPROPERTY(EditAnywhere, Category = "iMSTK|ConnectiveTissue")
		bool bIsTearable = false;

	// The strain the tissue can take before failing
	UPROPERTY(EditAnywhere, meta = (EditCondition = "bIsTearable", EditConditionHides), BlueprintReadWrite, Category = "iMSTK|ConnectiveTissue")
		float MaxStrain = 0.5;

	// Whether or not the tissue is burnable. Note: Do partitioning must be set to false
	UPROPERTY(EditAnywhere, Category = "iMSTK|ConnectiveTissue")
		bool bIsBurnable = false;


protected:
	UPROPERTY()
		TArray<FSplineLineMeshData> Splines;

	UPROPERTY()
		TArray<USplineMeshComponent*> SplineMeshes;

private:
	std::shared_ptr<imstk::LineMesh> VisualGeom;

	void InitSplines();

	bool bSplinesInitialized = false;

public:
	virtual void UnInit() override;
};
