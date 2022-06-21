// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "ImstkBehaviour.h"
#include "ImstkInteraction.h"
//#include "ImstkController.h"
#include "imstkSceneManager.h"
#include "imstkScene.h"
#include "imstkRigidBodyModel2.h"

#include "imstkPbdObjectCutting.h"

#include "ImstkSubsystem.generated.h"

//#define CHECK_NULL(Pointer, LogClass, Message) if(Pointer) UE_LOG(LogClass, Error, TEXT(Message)); return

class UDeformableModel;
class UImstkController;

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

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "General")
		float TickInterval = 0.01;

	// Values to be set as defaults in the manager for imstk
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "General")
		int RigidBodyMaxIterations;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "General")
		FVector Gravity;

	// How scaled down the Imstk scene is in comparison to Unreal. By default 1/100th because Unreal is in cm and Imstk is in m
	UPROPERTY(BlueprintReadWrite, Meta = (ClampMin = "1"), VisibleAnywhere, Category = "General")
		int SceneScale = 100;

	// All ImstkBehaviours attached to objects in Unreal, used to initialize the objects
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "General")
		TArray<UImstkBehaviour*> AllBehaviours;

	// All ImstkInteractions in Unreal, used to initialize the imstk interactions between objects
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "General")
		TArray<UImstkInteraction*> AllInteractions;

	// 
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "General")
		TArray <UImstkController*> AllControllers;

	bool IsSubsystemInitialized();

	virtual void Deinitialize() override;

	/*bool TEMP = false;

	UFUNCTION(BlueprintCallable, Category = "iMSTKSubsystem")
		void ImstkTest();
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "General")
		FVector PlaneNorm;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "General")
		FVector PlanePos;
	std::shared_ptr<imstk::PbdObjectCutting> Cutting;
	std::shared_ptr<imstk::PbdObject> clothObj;

	UFUNCTION(BlueprintCallable, Category = "iMSTKSubsystem")
		void CutTest();*/
};
