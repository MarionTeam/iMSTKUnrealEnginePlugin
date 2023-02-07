// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ImstkController.h"
#include "PBDThread.h"

#include "NeedleObject.h"
#include "NeedleInteraction.h"

#include "SuturingController.generated.h"


 /** \file SuturingController.h
  *  \brief Creates a needle and thread controller. Requires a PBD thread to be attached to the actor
  *  \details Creates the Imstk scene manager, scene and rigidbody model as well as initializing all imstk behaviours assigned in Unreal.
  * Note: Needle only works with iMSTK scene scale set to ~100 since it is currently always the same size within the iMSTK scene and is scaled up/down for Unreal
  */
UCLASS(ClassGroup = (Imstk), meta = (BlueprintSpawnableComponent), hidecategories = ("iMSTK|ControllerType"))
class IMSTK_API USuturingController : public UImstkController
{
	GENERATED_BODY()

public:
	virtual void InitializeComponent() override;
	virtual void InitController() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "iMSTK")
		double InertiaTensorMultiplier = 10000;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "iMSTK")
		double Mass = 1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "iMSTK")
		double ForceThreshold = 0.0001;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "iMSTK|Force")
		bool bForceTool = false;
	
	// Material of the ghost model for the needle
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (EditCondition = "bForceTool", EditConditionHides), Category = "iMSTK|Force")
		UMaterial* GhostMaterial;

	std::shared_ptr<imstk::RigidObject2> Needle;

	// Required to be set in the construction blueprint
	UPROPERTY()
		UPBDThread* Thread;

	/** Setter for the thread attached to the needle. Required to be set in the construction of the blueprint.
	* @param InputMeshComp Static mesh component to be set
	* @return None
	*/
	UFUNCTION(BlueprintCallable, Category = "iMSTK|SuturingController")
		void SetThread(UPBDThread* Input);

	/** Stitch along the thread attached to the needle
	* @return None
	*/
	UFUNCTION(BlueprintCallable, Category = "iMSTK|SuturingController")
		void Stitch();

	// Procedural mesh component created and attached to the object to visualize the needle
	UPROPERTY()
		UProceduralMeshComponent* ProcMeshComp;

	// Procedural mesh component created and attached if the controller is set to use force. Used to visualize the ghost of the tool
	UPROPERTY()
		UProceduralMeshComponent* GhostMeshComp;

	/** Moves the needle and attached thread to the given position and orientation
	* @param Location Position to move the needle to
	* @param Orientation Orientation to move the needle to
	* @return None
	*/
	UFUNCTION(BlueprintCallable, Category = "iMSTK|SuturingController")
		void MoveNeedleToLocation(FVector Location, FQuat Orientation);

	UFUNCTION(BlueprintCallable, Category = "iMSTK|SuturingController")
		virtual void UpdateUnrealPosRot();

	/** Sets the needle interaction on the controller for stitching
	* @param Input inputted needle interaction
	* @return None
	*/
	void SetNeedleInteraction(std::shared_ptr<NeedleInteraction> Input);

	UPROPERTY(EditAnywhere, meta = (EditCondition = "bForceTool", EditConditionHides), BlueprintReadWrite, Category = "iMSTK|Force")
		bool bIgnoreAngularForce = true;

	// Spring force of the force applied to the tool
	UPROPERTY(EditAnywhere, meta = (EditCondition = "bForceTool && bIgnoreAngularForce", EditConditionHides), BlueprintReadWrite, Category = "iMSTK|Force")
		float SpringForce = 10000;

	// Spring damping of the force applied to the tool
	UPROPERTY(EditAnywhere, meta = (EditCondition = "bForceTool && bIgnoreAngularForce", EditConditionHides), BlueprintReadWrite, Category = "iMSTK|Force")
		float DamperForce = 100;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (EditCondition = "bForceTool", EditConditionHides), Category = "iMSTK|Force")
		double LinearKs = 8000000.0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (EditCondition = "bForceTool", EditConditionHides), Category = "iMSTK|Force")
		double AngularKs = 10000.0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (EditCondition = "bForceTool", EditConditionHides), Category = "iMSTK|Force")
		double LinearKd = 10000.0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (EditCondition = "bForceTool", EditConditionHides), Category = "iMSTK|Force")
		double AngularKd = 300.0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (EditCondition = "bForceTool", EditConditionHides), Category = "iMSTK|Force")
		double ForceScaling = 1;

	UPROPERTY(EditAnywhere, Meta = (ClampMin = "0"), Category = "iMSTK|Force")
		double TranslationScaling = 1.0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "iMSTK|Force")
		bool bUseCriticalDamping = true;
	UPROPERTY(EditAnywhere, Category = "iMSTK|Force")
		bool bUseForceSmoothening = true;
	UPROPERTY(EditAnywhere, Meta = (ClampMin = "0"), Category = "iMSTK|Force")
		int SmoothingKernelSize = 15;

	imstk::Vec3d AngularSpringForce = imstk::Vec3d::Zero();
	imstk::Vec3d AngularDamperForce = imstk::Vec3d::Zero();

protected:
	/** Updates the position and rotation of the object in iMSTK to the position given. If the controller is a force tool then applies a force to the position rather than directly setting it.
	* @param Location Position to move the needle to
	* @param Orientation Orientation to move the needle to
	* @return None
	*/
	virtual void UpdateImstkPosRot(FVector Location, FQuat Orientation);
	
	// Cached line mesh of the needle object
	std::shared_ptr<imstk::LineMesh> NeedleLineMesh;

	std::shared_ptr<NeedleInteraction> SutureInteraction;

public:
	virtual void UnInit() override;
};
