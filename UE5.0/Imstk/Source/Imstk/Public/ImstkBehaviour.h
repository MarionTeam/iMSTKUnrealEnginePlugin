// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ImstkBehaviour.generated.h"

/** \file ImstkBehaviour.h
 *  \brief Abstract class for all Imstk Actor Components that need to be initialized
 *  \details Classes that use this include dynamical models, interactions, etc.
 */
UCLASS(Abstract)
class IMSTK_API UImstkBehaviour : public UActorComponent
{
	GENERATED_BODY()
public:
	/** Default constructor.
	* @return None
	*/
	UImstkBehaviour();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	bool bIsInitialized = false;

public:
	virtual void InitializeComponent() override;
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	/** Initializes the Imstk behaviour (Can be overwritten)
	* @return None
	*/
	virtual void Init();

	/** Check if behaviour is initialized in iMSTK. Can be called in blueprint to avoid null references
	* @return True if behaviour is initialized in iMSTK
	*/
	UFUNCTION(BlueprintCallable, Category = "iMSTK")
		bool IsInitialized();

	virtual void UnInit();


};
