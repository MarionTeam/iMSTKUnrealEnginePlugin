// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ControllerTool.h"
#include "imstkBurner.h"
#include "ControllerBurningTool.generated.h"

/** \file ControllerBurningTool.h
 *  \brief Object for a burning tool. Requires a collision interaction to also be initialized
 *  \details Initializes the tool and creates the interactions between an object and the tool
 */
UCLASS()
class IMSTK_API UControllerBurningTool : public UControllerTool
{
	GENERATED_BODY()

public:
	/** Initializes the burning controller tool and tells the controller which type of tool to generate
	* @param Controller - The controller the tool is attached to
	* @param ToolFilter - The tool filter of the controller for this particular tool
	* @return EControllerObjectType - Returns the type of tool the controller must create for the tool to be functional
	*/
	virtual EControllerObjectType Init(UImstkController* Controller, const FControllerToolFilter& ToolFilter) override;

	/** Attaches a burner component to the tool
	* @param OtherObject - The object the tool will burn. Currently must be connective tissue
	* @return std::shared_ptr<imstk::SceneObject> The generated interaction or nullptr if there was an error in generation
	*/
	virtual std::shared_ptr<imstk::SceneObject> CreateInteraction(UDynamicalModel* OtherObject) override;

	/** Executes the burners
	* @return bool - True if burner started, false if burner not started
	*/
	virtual bool Execute() override;

	/** Releases the burners
	* @return bool - True if burner stopped, false if burner not stopped
	*/
	virtual bool Release() override;

	virtual void UnInit() override;

protected:
	// Array containing burner components
	TArray<std::shared_ptr<imstk::Burner>> ToolBurners;
};
