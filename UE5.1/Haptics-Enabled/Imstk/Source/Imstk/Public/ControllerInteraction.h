// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CollisionInteraction.h"
#include "ImstkController.h"
#include "ControllerInteraction.generated.h"

/** \file ControllerInteraction.h
 *  \brief Class used to create and represent an interaction between controller and object
 *  \details Can be created in blueprint to make the iMSTK collision interaction and initialized using the iMSTK subsystem. Requires Model1 and Controller to be set. Collision type may be left as auto to automatically determine the collision type.
 *           Note: Model2 does not need to be set
 */
UCLASS()
class IMSTK_API UControllerInteraction : public UCollisionInteraction
{
	GENERATED_BODY()

public:
	// Controller in the interaction 
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "iMSTK|Controller Interaction")
		UImstkController* Controller;

	/** Initializes the interaction between model and controller
	* @return None
	*/
	virtual void Init() override;

	virtual void UnInit() override;
};
