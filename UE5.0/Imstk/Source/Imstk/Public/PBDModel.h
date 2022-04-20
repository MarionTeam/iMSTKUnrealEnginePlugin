// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DeformableModel.h"
#include "TetrahedralMeshAsset.h"
#include "iMSTK-5.0/imstkSurfaceMesh.h"
#include "PBDModel.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Imstk), meta = (BlueprintSpawnableComponent))
class IMSTK_API UPBDModel : public UDeformableModel
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category = "General")
		//bool TetrahedralMesh;
		UTetrahedralMeshAsset* TetrahedralMesh;

	UPROPERTY(EditAnywhere, meta = (EditCondition = "TetrahedralMesh == nullptr", EditConditionHides), Category = "Constraints")
		bool bUseDihedralConstraint = false;
	UPROPERTY(EditAnywhere, meta = (EditCondition = "bUseDihedralConstraint && TetrahedralMesh == nullptr", EditConditionHides), Category = "Constraints")
		float DihedralConstraint = 0.0;

	UPROPERTY(EditAnywhere, meta = (EditCondition = "TetrahedralMesh != nullptr", EditConditionHides), Category = "Constraints")
		bool bUseVolumeConstraint = false;
	UPROPERTY(EditAnywhere, meta = (EditCondition = "bUseVolumeConstraint && TetrahedralMesh != nullptr", EditConditionHides), Category = "Constraints")
		float VolumeConstraint = 0.0;

	UPROPERTY(EditAnywhere, meta = (EditCondition = "TetrahedralMesh != nullptr", EditConditionHides), Category = "Constraints")
		bool bUseFEMConstraint = false;
	UPROPERTY(EditAnywhere, meta = (EditCondition = "bUseFEMConstraint && TetrahedralMesh != nullptr", EditConditionHides), Category = "Constraints")
		float YoungsModulus = 0.0;
	UPROPERTY(EditAnywhere, meta = (EditCondition = "bUseFEMConstraint && TetrahedralMesh != nullptr", EditConditionHides), Category = "Constraints")
		float PossionsRatio = 0.0;
	UPROPERTY(EditAnywhere, meta = (EditCondition = "bUseFEMConstraint && TetrahedralMesh != nullptr", EditConditionHides), Category = "Constraints")
		TEnumAsByte<FemConstraintMaterial> MaterialType = FemConstraintMaterial::StVK;

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void InitializeComponent() override;

	/** Initializes the geometry and the PBD model for the deformable model
	* @return None
	*/
	virtual void Init() override;

protected:
	UPROPERTY()
		UProceduralMeshComponent* MeshComp;

	std::shared_ptr<imstk::SurfaceMesh> MeshGeom;

	/** Updates the mesh's vertices in Unreal to visualize the scene in imstk
	* @return None
	*/
	virtual void UpdateModel() override;
	
};
