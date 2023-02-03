// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ImstkController.h"

#include "imstkPbdObjectController.h"

//#include "CoreMinimal.h"
//#include "ImstkController.h"
//#include "imstkRigidObject2.h"
#include "HapticController.generated.h"

UENUM(BlueprintType)
enum EHapticControllerPreset
{
	HapticCollidingPreset,
	HapticGraspingPreset,
	HapticCuttingPreset,
	HapticStitchingPreset,
	HapticLevelSetPreset
};

/** \file HapticController.h
 *  \brief Controller for haptic devices
 *  \details Attach to an actor to enable controls with a haptic device
 */
UCLASS(ClassGroup = (Imstk), meta = (BlueprintSpawnableComponent))
class IMSTK_API UHapticController : public UImstkController
{
	GENERATED_BODY()

public:
	virtual void PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent);

	UPROPERTY(EditAnywhere, Category = "iMSTK")
		TEnumAsByte<EHapticControllerPreset> Preset = EHapticControllerPreset::HapticCollidingPreset;

	UPROPERTY(EditAnywhere, Category = "iMSTK|RigidBody")
		FVector RBPos = FVector::Zero();
	UPROPERTY(EditAnywhere, Meta = (ClampMin = "0"), Category = "iMSTK|RigidBody")
		double RBMass = 1;
	UPROPERTY(EditAnywhere, Meta = (ClampMin = "0"), Category = "iMSTK|RigidBody")
		double RBInertiaMultiplier = 1;

	UPROPERTY(EditAnywhere, Meta = (ClampMin = "0"), Category = "iMSTK|Force")
		double TranslationScaling = 1.0;
	UPROPERTY(EditAnywhere, Meta = (ClampMin = "0"), Category = "iMSTK|Force")
		double LinearKs = 8000000.0;
	UPROPERTY(EditAnywhere, Meta = (ClampMin = "0"), Category = "iMSTK|Force")
		double AngularKs = 10000.0;
	UPROPERTY(EditAnywhere, Meta = (ClampMin = "0"), Category = "iMSTK|Force")
		double ForceScaling = 0.0000075;
	UPROPERTY(EditAnywhere, Category = "iMSTK|Force")
		bool bUseCriticalDamping = true;
	UPROPERTY(EditAnywhere, Category = "iMSTK|Force")
		bool bUseForceSmoothening = true;
	UPROPERTY(EditAnywhere, Meta = (ClampMin = "0"), Category = "iMSTK|Force")
		int SmoothingKernelSize = 15;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ClampMin = "1", EditCondition = "ToolType == EToolType::LevelSetTool", EditConditionHides), Category = "iMSTK|RBDModel")
		int MaxNumIterations = 8;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ClampMin = "0", EditCondition = "ToolType == EToolType::LevelSetTool", EditConditionHides), Category = "iMSTK|RBDModel")
		double VelocityDamping = 1.0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ClampMin = "0", EditCondition = "ToolType == EToolType::LevelSetTool", EditConditionHides), Category = "iMSTK|RBDModel")
		double AngularVelocityDamping = 1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ClampMin = "1", EditCondition = "ToolType == EToolType::LevelSetTool", EditConditionHides), Category = "iMSTK|RBDModel")
		int MaxNumConstraints = 40;

	// Called before Begin Play
	virtual void InitializeComponent() override;

	/** Initializes the controller in imstk
	* @return None
	*/
	virtual void InitController() override;

	/** Moves the object to the location in the imstk scene
	* @return None
	*/
	UFUNCTION(BlueprintCallable, Category = "iMSTK|HapticController")
		void UpdateUnrealPosRot();

	/** Initializes the action for the tool with the inputted button
	* @param Button Int corresponding to the haptic button to be pressed to perform the action
	* @return None
	*/
	UFUNCTION(BlueprintCallable, Category = "iMSTK|HapticController")
		void InitAction(EToolType ToolType, const int Button = 1);


	// For testing forces on haptic device
	// Note: requires collision interactions on ControllerCollisionTool.h to be public
	/*UFUNCTION(BlueprintCallable, Category = "iMSTK|HapticController")
		void PrintForces();
	std::shared_ptr<imstk::PbdObjectController> TempController;*/

protected:
	bool bIsPbdTool = false;
	std::shared_ptr<imstk::PbdObject> PbdToolObj;
	std::shared_ptr<imstk::RigidObject2> RigidToolObj;
	std::shared_ptr<imstk::DeviceClient> DeviceClient;

	UPROPERTY()
		FQuat OrientationOffset = FQuat::Identity;

private:
	int GraspingButton;
	int CuttingButton;

	UPROPERTY()
		TArray<int> ActionButtons;
	UPROPERTY()
		TArray<TEnumAsByte<EToolType>> ToolTypes;

public:
	virtual void UnInit() override;
};

