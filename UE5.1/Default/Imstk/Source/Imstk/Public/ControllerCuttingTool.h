// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ControllerTool.h"
#include "imstkPbdObjectCutting.h"
#include "ControllerCuttingTool.generated.h"

/** \file ControllerCuttingTool.h
 *  \brief Object for a cutting tool
 *  \details Initializes the tool and creates the interactions between an object and the tool
 */
UCLASS()
class IMSTK_API UControllerCuttingTool : public UControllerTool
{
	GENERATED_BODY()

public:
	/** Initializes the cutting controller tool and tells the controller which type of tool to generate
	* @param Controller - The controller the tool is attached to
	* @param ToolFilter - The tool filter of the controller for this particular tool
	* @return EControllerObjectType - Returns the type of tool the controller must create for the tool to be functional
	*/
	virtual EControllerObjectType Init(UImstkController* Controller, const FControllerToolFilter& ToolFilter) override;

	/** Initializes the cutting interaction
	* @param OtherObject - The object to be cut
	* @return std::shared_ptr<imstk::SceneObject> The generated interaction or nullptr if there was an error in generation
	*/
	virtual std::shared_ptr<imstk::SceneObject> CreateInteraction(UDynamicalModel* OtherObject) override;

	/** Executes each cut
	* @return bool - True if cut, false if not cut
	*/
	virtual bool Execute() override;

	virtual void UnInit() override;

protected:
	// Array containing cutting interactions
	TArray<std::shared_ptr<imstk::PbdObjectCutting>> Cuttings;
};
