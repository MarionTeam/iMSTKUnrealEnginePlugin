// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "ImstkBehaviour.h"
#include "ImstkInteraction.h"
#include "ImstkConstraint.h"
#include "imstkSceneManager.h"
#include "imstkScene.h"
#include "imstkRigidBodyModel2.h"
#include "imstkPbdModel.h"

// Async
#include "Chaos/SimCallbackInput.h"
#include "Chaos/SimCallbackObject.h"
#include "Physics/Experimental/PhysScene_Chaos.h"

#include "ImstkSubsystem.generated.h"

class UDeformableModel;
class UImstkController;


struct FImstkSubsystemAsyncInput : public Chaos::FSimCallbackInput
{
	UImstkSubsystem* SubsystemInstance;
	// Required method
	void Reset()
	{
	}
};

// Output from the physics thread
struct FImstkSubsystemAsyncOutput : public Chaos::FSimCallbackOutput
{
	// Required method
	void Reset()
	{
	}
};

class FImstkSubsystemAsyncCallback : public Chaos::TSimCallbackObject<FImstkSubsystemAsyncInput, FImstkSubsystemAsyncOutput> {
	virtual void OnPreSimulate_Internal() override;

	// Not used.
	virtual void OnContactModification_Internal(Chaos::FCollisionContactModifier& Modifier) override;
};


/** \file ImstkSubsystem.h
 *  \brief Subsystem to manage and initialize Imstk.
 *  \details Creates the Imstk scene manager, scene and rigidbody model as well as initializing all imstk behaviours assigned in Unreal.
 */
UCLASS()
class IMSTK_API UImstkSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	/** Default constructor.
	* @return None
	*/
	UImstkSubsystem();
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	/** Function to initialize required managers for Imstk and then initialize all Imstk behaviours.
	* @return None
	*/
	UFUNCTION(BlueprintCallable, Category = "iMSTK|Subsystem")
		void ImstkInit();

	/** Toggles the iMSTK simulation to pause/play
	* @return None
	*/
	UFUNCTION(BlueprintCallable, Category = "iMSTK|Subsystem")
		void ToggleSimulation();

	/** Returns true if the simulation is paused
	* @return True if the simulation is paused
	*/
	UFUNCTION(BlueprintCallable, Category = "iMSTK|Subsystem")
		bool IsSimulationPaused();

	/** Updates the scene and progresses by the amount of time provided if using realtime, else will use the assigned TickInterval
	* @param DeltaTime - The amount of time to progress the scene
	* @return None
	*/
	UFUNCTION(BlueprintCallable, Category = "iMSTK|Subsystem")
		void UpdateSimulation(float DeltaTime);

	/** Logs a message to both Unreal and Imstk
	* @param Message The message to be logged
	* @return None
	*/
	UFUNCTION(BlueprintCallable, Category = "iMSTK|Subsystem")
		void LogToUnrealAndImstk(FString Message, FColor Color);

	/** Reinitializes the active scene
	* @return None
	*/
	UFUNCTION(BlueprintCallable, Category = "iMSTK|Subsystem")
		void ReInitScene();

protected:
	bool bIsCreateOnRunning = false;

	// Used to tick the Subsystem only if system is initialized properly
	bool bIsInitialized = false;

	// Keep track of whether the scene in iMSTK is paused
	bool bIsPaused = false;

	float TimeRemaining = 0;

	// Array of deformable models to assign the deltatimes of the models if using real time
	TArray<UDeformableModel*> DeformableModels;

public:
	// Required for iMSTK scene and interactions
	std::shared_ptr<imstk::SceneManager> SceneManager;
	std::shared_ptr<imstk::RigidBodyModel2> RigidBodyModel;
	std::shared_ptr<imstk::PbdModel> PbdModel;
	std::shared_ptr<imstk::Scene> ActiveScene;

	// Fixed deltatime of the iMSTK scene if realtime is not set. Note: if using async physics the editor must be run twice to update the value change
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "iMSTK")
		float TickInterval = 0.01;

	UPROPERTY(BlueprintReadWrite, Meta = (ClampMin = "0"), VisibleAnywhere, Category = "iMSTK|PbdModel")
		float PbdModelDt = 0.01;

	UPROPERTY(BlueprintReadWrite, Meta = (ClampMin = "0"), VisibleAnywhere, Category = "iMSTK|PbdModel")
		float LinearDampingCoeff = 0.01;

	UPROPERTY(BlueprintReadWrite, Meta = (ClampMin = "0"), VisibleAnywhere, Category = "iMSTK|PbdModel")
		float AngularDampingCoeff = 0.01;

	UPROPERTY(BlueprintReadWrite, Meta = (ClampMin = "1"), VisibleAnywhere, Category = "iMSTK|PbdModel")
		int PbdModelIterations = 5;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "iMSTK|PbdModel")
		bool bDoPartitioning = true;

	// Maximum number of iterations for rigid bodies
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "iMSTK")
		int RigidBodyMaxIterations;

	// Default gravity of objects in the scene. Can be overwritten on most components
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "iMSTK")
		FVector Gravity;

	// How scaled down the Imstk scene is in comparison to Unreal. By default 1/100th because Unreal is in cm and Imstk is in m
	UPROPERTY(BlueprintReadWrite, Meta = (ClampMin = "0.00001"), VisibleAnywhere, Category = "iMSTK")
		float SceneScale = 100;

	// All ImstkBehaviours attached to objects in Unreal, used to initialize the objects
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "iMSTK")
		TArray<UImstkBehaviour*> AllBehaviours;

	// All ImstkInteractions in Unreal, used to initialize the imstk interactions between objects
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "iMSTK")
		TArray<UImstkInteraction*> AllInteractions;

	// All ImstkControllers in Unreal, used to initialize imstk controllers
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "iMSTK")
		TArray <UImstkController*> AllControllers;

	// All ImstkConstraints that need to be initialized separately
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "iMSTK")
		TArray <UImstkConstraint*> AllConstraints;

	/** Returns true if scene, interactions and controllers have all been initialized properly
	* @return True if subsystem is initialized
	*/
	bool IsSubsystemInitialized();

	virtual void Deinitialize() override;

public:
	void AsyncScenePreTick(FPhysScene* PhysScene, float DeltaTime);

private:
	// For async
	FImstkSubsystemAsyncCallback* AsyncObject;
	FPhysScene_Chaos* AsyncScene;
	FDelegateHandle OnAsyncScenePreTickHandle;
};
