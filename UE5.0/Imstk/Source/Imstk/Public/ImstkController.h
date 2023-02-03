// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "imstkDynamicObject.h"
#include "GeometryFilter.h"
#include "ControllerTool.h"
#include "ControllerToolFilter.h"

#include "ImstkController.generated.h"

class UImstkSubsystem;

/** \file ImstkController.h
 *  \brief Abstract class for object in imstk that can be controlled by the user
 *  \details
 */
UCLASS(Abstract)
class IMSTK_API UImstkController : public USceneComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UImstkController();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	// Pointer to the iMSTK subsystem
	UPROPERTY()
		UImstkSubsystem* SubsystemInstance;

	bool bIsInitialized = false;

	// iMSTK Rigid object of the tool
	std::shared_ptr<imstk::DynamicObject> ToolObj;

	// Static mesh component for surface mesh tools. Must be assigned within construction of the blueprint
	UPROPERTY()
		UStaticMeshComponent* MeshComp;


public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	virtual void InitializeComponent() override;

	UFUNCTION(BlueprintCallable, Category = "iMSTK")
		bool IsInitialized();

	// Geometry of the tool
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "iMSTK")
		FGeometryFilter ToolGeomFilter;

	/** Disables the collisions of the object in iMSTK
	* @return None
	*/
	UFUNCTION(BlueprintCallable, Category = "iMSTK|Controller")
		bool ExecuteInteractions(TEnumAsByte<EToolType> ExecuteType);

	UFUNCTION(BlueprintCallable, Category = "iMSTK|Controller")
		bool ReleaseInteractions(TEnumAsByte<EToolType> ReleaseType);

	/** Setter for the static mesh component. Required to be set in the construction of the blueprint for surface mesh tools.
	* @param InputMeshComp Static mesh component to be set
	* @return None
	*/
	UFUNCTION(BlueprintCallable, Category = "iMSTK|Controller")
		void SetStaticMeshComp(UStaticMeshComponent* InputMeshComp);

	/** Initializes the controller in imstk
	* @return None
	*/
	virtual void InitController();

	/** Returns the rigid object for the tool
	* @return Rigid object for the tool
	*/
	std::shared_ptr<imstk::DynamicObject> GetToolObj();

	void SetToolObj(std::shared_ptr<imstk::DynamicObject> NewToolObj);

	/** Calculates and returns the scale applied to Unreal's basic shapes in order to have the same shape as iMSTK's geometry
	* @return FVector - Scale of the geometry or zero vector if not implemented
	*/
	UFUNCTION(BlueprintCallable, Category = "iMSTK|Controller")
		FVector GetGeomScale();

	/** Returns the amount the geometry is offset within iMSTK
	* @return FVector - Offset of the geometry or zero vector if not implemented
	*/
	UFUNCTION(BlueprintCallable, Category = "iMSTK|Controller")
		FVector GetGeomOffset();


public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "iMSTK|ControllerType")
		TArray<FControllerToolFilter> ControllerFilters;

	UPROPERTY()
		TArray<UControllerTool*> ControllerTools;

public:
	// Called from the subsystem to clear shared pointers
	virtual void UnInit();
};
