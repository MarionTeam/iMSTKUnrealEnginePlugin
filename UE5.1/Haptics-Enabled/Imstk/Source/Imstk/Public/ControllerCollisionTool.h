// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ControllerTool.h"
#include "imstkPbdObjectCollision.h"
#include "ControllerCollisionTool.generated.h"

/** \file ControllerCollisionTool.h
 *  \brief Object for a colliding tool
 *  \details Initializes the tool and creates the interactions between an object and the tool
 */
UCLASS()
class IMSTK_API UControllerCollisionTool : public UControllerTool
{
	GENERATED_BODY()

public:
	/** Initializes the colliding controller tool and tells the controller which type of tool to generate
	* @param Controller - The controller the tool is attached to
	* @param ToolFilter - The tool filter of the controller for this particular tool
	* @return EControllerObjectType - Returns the type of tool the controller must create for the tool to be functional
	*/
	virtual EControllerObjectType Init(UImstkController* Controller, const FControllerToolFilter& ToolFilter) override;

	/** Initializes the collision interaction
	* @param OtherObject - The object the tool will collide with
	* @return std::shared_ptr<imstk::SceneObject> The generated interaction or nullptr if there was an error in generation
	*/
	virtual std::shared_ptr<imstk::SceneObject> CreateInteraction(UDynamicalModel* OtherObject) override;

	// TODO: Temporarily public for testing forces on haptic device 
	// Array containing cutting interactions
	TArray<std::shared_ptr<imstk::PbdObjectCollision>> Collisions;

protected:
	
};
