// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ImstkSubsystem.h"
#include "ControllerToolFilter.h"
#include "DynamicalModel.h"
#include "ControllerTool.generated.h"

class UImstkController;

UENUM()
enum EControllerObjectType
{
	Null,
	RigidToolObject,
	PbdToolObject
};

/** \file ControllerTool.h
 *  \brief Abstract class for the each tool type
 *  \details Initializes the tool and creates the interactions between an object and the tool
 */
UCLASS(Abstract)
class IMSTK_API UControllerTool : public UObject
{
	GENERATED_BODY()

public:
	/** Initializes the controller tool and tells the controller which type of tool to generate
	* @param Controller - The controller the tool is attached to
	* @param ToolFilter - The tool filter of the controller for this particular tool
	* @return EControllerObjectType - Returns the type of tool the controller must create for the tool to be functional
	*/
	virtual EControllerObjectType Init(UImstkController* Controller, const FControllerToolFilter& ToolFilter);

	/** Initializes the interaction for the tool
	* @param OtherObject - The other object in the interaction
	* @return std::shared_ptr<imstk::SceneObject> The generated interaction if it exists or nullptr
	*/
	virtual std::shared_ptr<imstk::SceneObject> CreateInteraction(UDynamicalModel* OtherObject);

	UControllerTool();

	/** Getter for IsInitialized
	* @return bool - True if initialized, false if not initialized
	*/
	virtual bool IsInitialized();

	/** Executes each interaction created
	* @return bool - True if interaction executed, false if not executed
	*/
	virtual bool Execute();

	/** Releases each interaction created if relevant
	* @return bool - True if interaction executed, false if not executed
	*/
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
