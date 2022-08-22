// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DynamicalModel.h"
#include "ProceduralMeshComponent.h"
#include "imstkPbdObject.h"

#include "DeformableModel.generated.h"

// Create same enum for Fem Material type to expose it in editor
UENUM()
enum FemConstraintMaterial
{
	Linear,
	Corotation,
	StVK,
	NeoHookean
};

/** \file DeformableModel.h
 *  \brief Component used to turn the actor it is attached to into a deformable model in imstk
 *  \details Must have either a static or procedural mesh attached to the actor. Static meshes will be converted to procedural. Can attach a tetrahedral mesh to use volumetric constraints.
 */
UCLASS(Abstract)
class IMSTK_API UDeformableModel : public UDynamicalModel
{
	GENERATED_BODY()

public:
	//UPROPERTY(EditAnywhere, Category = "General")
	//	//bool TetrahedralMesh;
	//	UTetrahedralMeshAsset* TetrahedralMesh;

	// Mass of the PBDModel
	UPROPERTY(EditAnywhere, Category = "General")
		double Mass = 1.0;

	// Viscous damping coefficient of the PBDModel
	UPROPERTY(EditAnywhere, Category = "General")
		double ViscousDampingCoeff = 0.01;

	// Number of iterations of the PBDModel
	UPROPERTY(EditAnywhere, Category = "General")
		int ModelIterations = 1;

	// Contact stiffness of the PBDmodel
	UPROPERTY(EditAnywhere, Category = "General")
		double ContactStiffness = 1.0;

	UPROPERTY(EditAnywhere, Category = "Constraints")
		bool bUseDistanceConstraint = false;
	UPROPERTY(EditAnywhere, meta = (EditCondition = "bUseDistanceConstraint", EditConditionHides), Category = "Constraints")
		float DistanceConstraint = 0.0;

	/*UPROPERTY(EditAnywhere, meta = (EditCondition = "TetrahedralMesh == nullptr", EditConditionHides), Category = "Constraints")
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
		TEnumAsByte<FemConstraintMaterial> MaterialType = FemConstraintMaterial::StVK;*/

	UPROPERTY(EditAnywhere, Category = "Constraints")
		bool bUseConstantDensityConstraint = false;
	UPROPERTY(EditAnywhere, meta = (EditCondition = "bUseConstantDensityConstraint", EditConditionHides), Category = "Constraints")
		float ConstantDensityConstraint = 0.0;

	UPROPERTY(EditAnywhere, Category = "Constraints")
		bool bUseAreaConstraint = false;
	UPROPERTY(EditAnywhere, meta = (EditCondition = "bUseAreaConstraint", EditConditionHides), Category = "Constraints")
		float AreaConstraint = 0.0;

	/** Fixes the listed vertices on the PBDModel. If assigned, the boundary conditions will be ignored*/
	UPROPERTY(EditAnywhere, Category = "Boundaries")
		TArray<int> FixedNodes;
	/** Vertices of the model within these actors will be fixed. These actors will be destroyed when starting the game*/
	UPROPERTY(EditAnywhere, Category = "Boundaries")
		TArray<AActor*> BoundaryConditionActors;
	/** Inverts the actor boundaries and fixes all vertices that are not in the actor's mesh*/
	UPROPERTY(EditAnywhere, Category = "Boundaries")
		bool bInverseBoundary;

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void InitializeComponent() override;

	/** Initializes the geometry and the PBD model for the deformable model
	* @return None
	*/
	//virtual void Init() override;

	/** Updates the mesh's vertices in Unreal to visualize the scene in imstk
	* @return None
	*/
	virtual void UpdateModel();

	// 
	std::shared_ptr<imstk::PbdObject> PbdObject;

	//virtual void OnRegister() override;

protected:
	/** Helper function that determines which vertices are within the boundary condition actors to fix.
	* @return None
	*/
	void ProcessBoundaryConditions();

public:
	virtual void UnInit() override;
};
