// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DeformableModel.h"
#include "Components/SplineComponent.h"
#include "imstkLineMesh.h"
#include "PBDThread.generated.h"

/** \file PBDThread.h
 *  \brief Uses a spline component attached to the actor to simulate a thread object in iMSTK
 *  \details A spline component must be attached to the actor. Visualization can be done using spline meshes in Unreal.
 */
UCLASS(ClassGroup = (Imstk), meta = (BlueprintSpawnableComponent), hidecategories = ("iMSTK|Geometry"))
class IMSTK_API UPBDThread : public UDeformableModel
{
	GENERATED_BODY()


public:
	UPBDThread();

	// Zeros the tangents for the spine in Unreal 
    // TODO: maybe remove this option
	UPROPERTY(EditAnywhere, Category = "iMSTK")
		bool bZeroTangents = false;

	UPROPERTY(EditAnywhere, Category = "iMSTK|Constraints")
		bool bUseBendConstraint = false;
	UPROPERTY(EditAnywhere, meta = (EditCondition = "bUseBendConstraint", EditConditionHides), Category = "iMSTK|Constraints")
		float BendStiffness = 0.0;

	// Spline component attached to the Actor
	UPROPERTY()
		USplineComponent* SplineComponent;

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


	/** Moves the specified vertex on the thread to the location. Note: Node on thread may need to be fixed for intended behaviour in iMSTK
	* @param VertIndex Vertex to move
	* @param Pos Position to move the vertex to
	* @return None
	*/
	UFUNCTION(BlueprintCallable, Category = "iMSTK|PBDThread")
		void MoveVertexToLocation(int VertIndex, FVector Pos);

protected:
	// TODO: Convert to use colliding geom
	std::shared_ptr<imstk::LineMesh> VisualGeom;

public:
	virtual void UnInit() override;
};
