// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ImstkBehaviour.h"
#include "GeometryFilter.h"
#include "ImstkSubsystem.h"
#include "imstkCollidingObject.h"
#include "DynamicalModel.generated.h"

UENUM(BlueprintType)
enum EDefaultModelPreset
{
	SurfaceMeshPreset,
	SpherePreset,
	CapsulePreset,
	CylinderPreset,
	PointSetPreset,
	OrientedBoxPreset,
	PlanePreset,
	LineMeshPreset
};

class UCollisionInteraction;
/** \file DynamicalModel.h
 *  \brief Abstract class to model any object that is added to the Imstk scene
 *  \details Contains a geometry filter to convert between Unreal and Imstk objects
 */
UCLASS(Abstract)
class IMSTK_API UDynamicalModel : public UImstkBehaviour
{
	GENERATED_BODY()
public:
	/** Creates and returns the geometry of the model
	* @return std::shared_ptr<imstk::Geometry> - The colliding geometry created by the Geometry filter
	*/
	virtual std::shared_ptr<imstk::Geometry> GetImstkGeometry();

	// The colliding object created and assigned in child classes
	std::shared_ptr<imstk::CollidingObject> ImstkCollidingObject;

	virtual void InitializeComponent() override;

	UPROPERTY(EditAnywhere, Category = "iMSTK|Model")
		bool bSharedModel = false;

	// Set the object to have separate gravity from the rest of the scene in iMSTK
	UPROPERTY(EditAnywhere, meta = (EditCondition = "!bSharedModel", EditConditionHides), Category = "iMSTK|Model")
		bool bIndividualGravity = false;
	UPROPERTY(EditAnywhere, meta = (EditCondition = "bIndividualGravity && !bSharedModel", EditConditionHides), Category = "iMSTK|Model")
		FVector Gravity;

	// Set the object to have a separate time step from the rest of the scene in iMSTK
	UPROPERTY(EditAnywhere, meta = (EditCondition = "!bSharedModel", EditConditionHides), Category = "iMSTK|Model")
		bool bIndividualDT = false;
	UPROPERTY(EditAnywhere, meta = (EditCondition = "bIndividualDT && !bSharedModel", EditConditionHides, ClampMin = "0"), Category = "iMSTK|Model")
		double IndividualDT = 0.01;

	// Geometry of the model
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "iMSTK|Geometry")
		FGeometryFilter GeomFilter;

	TArray<UCollisionInteraction*> GetInteractions();

	void AddInteraction(UCollisionInteraction* Interaction);

	// If set to true creates the object but does not add it to the scene (must be manually added)
	UPROPERTY(EditAnywhere, Category = "iMSTK|Other")
		bool bDelayInit = false;

	/** Initializes the model and adds it to the scene
	* @return None
	*/
	UFUNCTION(BlueprintCallable, Category = "iMSTK|DynamicalModel")
		void AddToScene();

	/** Gets the center of the colliding geometry in iMSTK in Unreal space
	* @return FVector containing the position of the geometry
	*/
	UFUNCTION(BlueprintCallable, Category = "iMSTK|DynamicalModel")
		FVector GetGeometryPosition();

protected:
	// References to the owning object
	UPROPERTY()
		AActor* Owner;

	// Reference to the imstk subsystem
	UPROPERTY()
		UImstkSubsystem* SubsystemInstance;

	UPROPERTY()
		TArray<UCollisionInteraction*> Interactions;

	// Cached geometry for when GetCollidingGeometry is called
	std::shared_ptr<imstk::Geometry> Geometry;

	// TODO: Maybe add this to a geometry util class
	/** Converts the static mesh attached to the model into a procedural mesh
	* @param StaticMesh - Pointer to the static mesh that will be converted to procedural
	* @param ProcMesh - Pointer to the created procedural mesh
	* @return None
	*/
	void ConvertStaticToProceduralMesh(UStaticMeshComponent* StaticMesh, UProceduralMeshComponent* ProcMesh);

public:
	// Called from the subsystem to clear shared pointers
	virtual void UnInit() override;

	// Print the location of the object converted to Unreal from iMSTK
	UPROPERTY(EditAnywhere, Category = "iMSTK|Debugging")
		bool bPrintPositionInformation = false;

	/** Calculates and returns the scale applied to Unreal's basic shapes in order to have the same shape as iMSTK's geometry
	* @return FVector - Scale of the geometry or zero vector if not implemented
	*/
	UFUNCTION(BlueprintCallable, Category = "iMSTK|DynamicalModel")
		FVector GetGeomScale();

	/** Returns the amount the geometry is offset within iMSTK
	* @return FVector - Offset of the geometry or zero vector if not implemented
	*/
	UFUNCTION(BlueprintCallable, Category = "iMSTK|DynamicalModel")
		FVector GetGeomOffset();

	/** Removes the object and all interactions involving the object from the scene and uninits it
	* @return None
	*/
	UFUNCTION(BlueprintCallable, Category = "iMSTK|DynamicalModel")
		virtual void RemoveFromScene();
};
