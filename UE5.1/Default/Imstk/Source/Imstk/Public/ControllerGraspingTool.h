// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ControllerTool.h"
#include "imstkPbdObjectGrasping.h"
#include "ControllerGraspingTool.generated.h"


/** \file ControllerGraspingTool.h
 *  \brief Object for a grasping tool
 *  \details Initializes the tool and creates the interactions between an object and the tool
 */
UCLASS()
class IMSTK_API UControllerGraspingTool : public UControllerTool
{
	GENERATED_BODY()

public:
	/** Initializes the grasping controller tool and tells the controller which type of tool to generate
	* @param Controller - The controller the tool is attached to
	* @param ToolFilter - The tool filter of the controller for this particular tool
	* @return EControllerObjectType - Returns the type of tool the controller must create for the tool to be functional
	*/
	virtual EControllerObjectType Init(UImstkController* Controller, const FControllerToolFilter& ToolFilter) override;

	/** Initializes the grasping interaction
	* @param OtherObject - The object to be grasped
	* @return std::shared_ptr<imstk::SceneObject> The generated interaction or nullptr if there was an error in generation
	*/
	virtual std::shared_ptr<imstk::SceneObject> CreateInteraction(UDynamicalModel* OtherObject) override;

	/** Executes each grasp
	* @return bool - True if grasped, false if not grasped
	*/
	virtual bool Execute() override;

	/** Release each grasp
	* @return bool - True if grasp released, false if grasp not released
	*/
	virtual bool Release() override;

	virtual void UnInit() override;

protected:
	// Array containing grasping interactions
	TArray<std::shared_ptr<imstk::PbdObjectGrasping>> ToolPickings;
};
