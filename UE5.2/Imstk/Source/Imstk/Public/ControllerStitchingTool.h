// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ControllerTool.h"
#include "imstkPbdObjectStitching.h"
#include "ControllerStitchingTool.generated.h"

/** \file ControllerStitchingTool.h
 *  \brief Object for a stitching tool
 *  \details Initializes the tool and creates the interactions between an object and the tool
 */
UCLASS()
class IMSTK_API UControllerStitchingTool : public UControllerTool
{
	GENERATED_BODY()

public:
	/** Initializes the stitching controller tool and tells the controller which type of tool to generate
	* @param Controller - The controller the tool is attached to
	* @param ToolFilter - The tool filter of the controller for this particular tool
	* @return EControllerObjectType - Returns the type of tool the controller must create for the tool to be functional
	*/
	virtual EControllerObjectType Init(UImstkController* Controller, const FControllerToolFilter& ToolFilter) override;

	/** Initializes the stitching interaction
	* @param OtherObject - The other object in the interaction
	* @return std::shared_ptr<imstk::SceneObject> The generated interaction or nullptr if there was an error in generation
	*/
	virtual std::shared_ptr<imstk::SceneObject> CreateInteraction(UDynamicalModel* OtherObject) override;

	/** Executes each stitch
	* @return bool - True if stitched, false if not stitched
	*/
	virtual bool Execute() override;

	virtual void UnInit() override;

protected:
	// Each stitching interaction generated with this tool
	TArray<std::shared_ptr<imstk::PbdObjectStitching>> Stitchings;
};
