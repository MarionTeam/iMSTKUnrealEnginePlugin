// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "ImstkBehaviour.h"
#include "ImstkInteraction.h"
#include "ImstkController.h"
#include "iMSTK-5.0/imstkSceneManager.h"
#include "iMSTK-5.0/imstkScene.h"
#include "iMSTK-5.0/imstkRigidBodyModel2.h"
#include "ImstkSubsystem.generated.h"

//#define CHECK_NULL(Pointer, LogClass, Message) if(Pointer) UE_LOG(LogClass, Error, TEXT(Message)); return

class UDeformableModel;

struct FImstkSubsystemTickFunction : public FTickFunction
{
	UImstkSubsystem* Owner;
	virtual void ExecuteTick(float DeltaTime, ELevelTick TickType, ENamedThreads::Type CurrentThread, const FGraphEventRef& MyCompletionGraphEvent) override;
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
	UFUNCTION(BlueprintCallable, Category = "iMSTKSubsystem")
		void ImstkInit();

	UFUNCTION(BlueprintCallable, Category = "iMSTKSubsystem")
		void ImstkTest();

	UFUNCTION(BlueprintCallable, Category = "iMSTKSubsystem")
		void ToggleSimulation();

	bool IsSimulationPaused();

	FImstkSubsystemTickFunction TickFunction;
	/*
	// From FTickableGameObject
	virtual void Tick(float DeltaTime) override;

	virtual bool IsTickableInEditor() const {
		return false;
	}
	virtual TStatId GetStatId() const override;
	*/

	/** Updates the scene and progresses by the amount of time provided
	* @param DeltaTime - The amount of time to progress the scene
	* @return None
	*/
	UFUNCTION(BlueprintCallable, Category = "iMSTKSubsystem")
		void UpdateSimulation(float DeltaTime);

protected:
	bool bIsCreateOnRunning = false;

	// Used to tick the Subsystem only if system is initialized properly
	bool bIsInitialized = false;

	bool bIsPaused = false;

	TArray<UDeformableModel*> DeformableModels;

public:
	// Required for Imstk's Scene and interactions
	std::shared_ptr<imstk::SceneManager> SceneManager;
	std::shared_ptr<imstk::RigidBodyModel2> RigidBodyModel;
	std::shared_ptr<imstk::Scene> ActiveScene;

	// Values to be set as defaults in the manager for imstk
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "General")
		int RigidBodyMaxIterations;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "General")
		FVector Gravity;

	// All ImstkBehaviours attached to objects in Unreal, used to initialize the objects
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "General")
		TArray<UImstkBehaviour*> AllBehaviours;

	// All ImstkInteractions in Unreal, used to initialize the imstk interactions between objects
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "General")
		TArray<UImstkInteraction*> AllInteractions;

	// Currently only one controller (not sure if imstk allows multiple)
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "General")
		UImstkController* Controller;

	bool IsSubsystemInitialized();

	virtual void Deinitialize() override;

	bool TEMP = false;
};
