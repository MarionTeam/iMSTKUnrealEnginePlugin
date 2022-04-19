// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DeformableModel.h"
#include "Components/SplineComponent.h"
#include "iMSTK-5.0/imstkLineMesh.h"
#include "PBDThread.generated.h"

/**
 *   
 */
UCLASS(ClassGroup = (Imstk), meta = (BlueprintSpawnableComponent), hidecategories = ("General|Geometry"))
class IMSTK_API UPBDThread : public UDeformableModel
{
	GENERATED_BODY()


public:
	UPROPERTY(EditAnywhere, Category = "Constraints")
		bool bUseBendConstraint = false;
	UPROPERTY(EditAnywhere, meta = (EditCondition = "bUseBendConstraint", EditConditionHides), Category = "Constraints")
		float BendStiffness = 0.0;

	UPROPERTY()
		USplineComponent* SplineComponent;
	//UPROPERTY(EditAnywhere, meta = (EditCondition = "bUseBendConstraint", EditConditionHides), Category = "Constraints")
		//int BendStride = 1;

	/** Initializes the geometry and the PBD model for the deformable model
	* @return None
	*/
	virtual void Init() override;

	virtual void InitializeComponent() override;

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	/** Updates the mesh's vertices in Unreal to visualize the scene in imstk
	* @return None
	*/
	virtual void UpdateModel() override;

protected:
	// TODO: Move stuff like this and MeshGeom in pbdModel into dynamical model and make a GetVisualGeom() function
	std::shared_ptr<imstk::LineMesh> VisualGeom;

public:
	virtual void UnInit() override;
};
