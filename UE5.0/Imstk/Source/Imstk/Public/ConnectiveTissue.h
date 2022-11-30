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

/**
 * Using this component, especially with high segments per strand and strands per face can cause significant performance impacts. When starting the game there is a lot of overhead for this creating the splines and spline meshes causing the game to stall when starting.
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

	UPROPERTY(EditAnywhere, Category = "iMSTK|ConnectiveTissue")
		AActor* PBDActorA;

	UPROPERTY(EditAnywhere, Category = "iMSTK|ConnectiveTissue")
		AActor* PBDActorB;

	UPROPERTY(EditAnywhere, Category = "iMSTK|ConnectiveTissue|Spline")
		UStaticMesh* SplineMesh;

	UPROPERTY(EditAnywhere, Category = "iMSTK|ConnectiveTissue|Spline")
		TEnumAsByte<ESplineMeshAxis::Type> ForwardAxis;

	UPROPERTY(EditAnywhere, Category = "iMSTK|ConnectiveTissue|Spline")
		class UMaterialInterface* SplineMeshMaterial;

	UPROPERTY(EditAnywhere, Meta = (ClampMin = "0"), Category = "iMSTK|ConnectiveTissue")
		float MaxDistance = 10;

	// Warning: Increasing can significantly impact performance
	UPROPERTY(EditAnywhere, Meta = (ClampMin = "0"), Category = "iMSTK|ConnectiveTissue")
		float StrandsPerFace = 2;

	// Warning: Increasing can significantly impact performance
	UPROPERTY(EditAnywhere, Meta = (ClampMin = "0"), Category = "iMSTK|ConnectiveTissue")
		int SegmentsPerStrand = 2;

	UPROPERTY(EditAnywhere, Category = "iMSTK|ConnectiveTissue")
		bool bIsTearable = false;

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
