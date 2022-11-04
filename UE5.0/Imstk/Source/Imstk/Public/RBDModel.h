// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DynamicalModel.h"
#include "imstkRigidObject2.h"

#include "RBDModel.generated.h"

/** \file RBDModel.h
 *  \brief Rigid body model to attach to an actor in Unreal to mark as an object to add into Imstk simulation
 *  \details Has variables available in editor and blueprint to set the default values of the object in Imstk. Updates position and rotation of the Unreal model to match the Imstk simulation.
 */
UCLASS(ClassGroup = (Imstk), meta = (BlueprintSpawnableComponent))
class IMSTK_API URBDModel : public UDynamicalModel
{
	GENERATED_BODY()

public:
	// Mass of the rigid object set in editor
	UPROPERTY(EditAnywhere, Category = "iMSTK")
		double Mass = 1.0;

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void InitializeComponent() override;

	virtual void PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent);

	UPROPERTY(EditAnywhere, Category = "iMSTK")
		TEnumAsByte<EDefaultModelPreset> Preset = EDefaultModelPreset::SurfaceMeshPreset;

	/** Initializes the rigid object that is defined in editor through the geometry filter
	* @return None
	*/
	virtual void Init() override;

protected:
	
	/** Called during TickComponent to move the Unreal object in order to match the Imstk simulation
	* @return None.
	*/
	void UpdatePosRot();

	// Object is created during Init and used in Imstk simulation
	std::shared_ptr<imstk::RigidObject2> RigidObject;

public:
	virtual void UnInit() override;
};
