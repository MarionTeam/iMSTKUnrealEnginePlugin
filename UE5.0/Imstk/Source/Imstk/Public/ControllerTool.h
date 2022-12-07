// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ImstkSubsystem.h"
#include "ControllerToolFilter.h"
#include "DynamicalModel.h"
#include "ControllerTool.generated.h"

//class UControllerGraspingTool;
class UImstkController;

UENUM()
enum EControllerObjectType
{
	Null,
	RigidToolObject,
	PbdToolObject
};

/**
 * 
 */
UCLASS()
class IMSTK_API UControllerTool : public UObject
{
	GENERATED_BODY()

public:
	virtual EControllerObjectType Init(UImstkController* Controller, const FControllerToolFilter& ToolFilter);

	virtual bool CreateInteraction(UDynamicalModel* OtherObject);

	UControllerTool();

	virtual bool IsInitialized();

	virtual bool Execute();

	virtual bool Release();

	virtual void UnInit();

	FControllerToolFilter ControllerToolFilter;

protected:
	bool bIsInitialized = false;

	UPROPERTY()
		UImstkController* ControllerComponent;
	UPROPERTY()
		UImstkSubsystem* SubsystemInstance;
};
