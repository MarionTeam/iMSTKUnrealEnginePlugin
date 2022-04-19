// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
//#include "ImstkSubsystem.h"
//#include "RBDModel.h"
#include "iMSTK-5.0/imstkRigidObject2.h"
#include "ImstkController.generated.h"

class UImstkSubsystem;

/** \file ImstkController.h
 *  \brief Abstract class for object in imstk that can be controlled by the user
 *  \details 
 */
UCLASS(Abstract)
class IMSTK_API UImstkController : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UImstkController();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY()
		UImstkSubsystem* SubsystemInstance;

	bool bIsInitialized = false;
	std::shared_ptr<imstk::RigidObject2> ToolObj;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	virtual void InitializeComponent() override;

	/** Initializes the controller in imstk
	* @return None
	*/
	virtual void InitController();

	std::shared_ptr<imstk::RigidObject2> GetToolObj();

	virtual void UnInit();

};
