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
	// Mass of the PBDModel
	UPROPERTY(EditAnywhere, Category = "iMSTK")
		double Mass = 1.0;

	UPROPERTY(EditAnywhere, Category = "iMSTK|PbdModel")
		double LinearDampingCoefficient = 0.01;

	UPROPERTY(EditAnywhere, Category = "iMSTK|PbdModel")
		double AngularDampingCoefficient = 0.01;

	// Number of iterations of the PBDModel
	UPROPERTY(EditAnywhere, meta = (EditCondition = "!bSharedModel", EditConditionHides), Category = "iMSTK|PBDModel")
		int ModelIterations = 1;

	UPROPERTY(EditAnywhere, Category = "iMSTK|Constraints")
		bool bUseDistanceConstraint = false;
	UPROPERTY(EditAnywhere, meta = (EditCondition = "bUseDistanceConstraint", EditConditionHides), Category = "iMSTK|Constraints")
		float DistanceConstraint = 0.0;

	UPROPERTY(EditAnywhere, Category = "iMSTK|Constraints")
		bool bUseConstantDensityConstraint = false;
	UPROPERTY(EditAnywhere, meta = (EditCondition = "bUseConstantDensityConstraint", EditConditionHides), Category = "iMSTK|Constraints")
		float ConstantDensityConstraint = 0.0;

	UPROPERTY(EditAnywhere, Category = "iMSTK|Constraints")
		bool bUseAreaConstraint = false;
	UPROPERTY(EditAnywhere, meta = (EditCondition = "bUseAreaConstraint", EditConditionHides), Category = "iMSTK|Constraints")
		float AreaConstraint = 0.0;

	/** Fixes the listed vertices on the PBDModel. If assigned, the boundary conditions will be ignored*/
	UPROPERTY(EditAnywhere, Category = "iMSTK|Boundaries")
		TArray<int> FixedNodes;
	/** Vertices of the model within these actors will be fixed. These actors will be destroyed when starting the game*/
	UPROPERTY(EditAnywhere, Category = "iMSTK|Boundaries")
		TArray<AActor*> BoundaryConditionActors;
	/** Inverts the actor boundaries and fixes all vertices that are not in the actor's mesh*/
	UPROPERTY(EditAnywhere, Category = "iMSTK|Boundaries")
		bool bInverseBoundary;

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void InitializeComponent() override;

	/** Updates the mesh's vertices in Unreal to visualize the scene in imstk
	* @return None
	*/
	virtual void UpdateModel();

	// 
	std::shared_ptr<imstk::PbdObject> PbdObject;

	/** Sets an array of vertex indices to be fixed on the deformable model
	* @params NewFixedVerts Array of integers containing the indices of the vertices to be fixed
	* @return None
	*/
	UFUNCTION(BlueprintCallable, Category = "iMSTK|DeformableModel")
		virtual void SetFixedVerts(TArray<int> NewFixedVerts);

protected:
	/** Helper function that determines which vertices are within the boundary condition actors to fix.
	* @return None
	*/
	void ProcessBoundaryConditions();

public:
	virtual void UnInit() override;
};
