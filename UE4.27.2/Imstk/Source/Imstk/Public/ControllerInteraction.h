// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CollisionInteraction.h"
#include "ImstkController.h"
#include "ControllerInteraction.generated.h"

/** \file ControllerInteraction.h
 *  \brief Class used to create and represent interaction between controller and object
 *  \details  Can be created in blueprint to make the imstk collision interaction and initialize using the imstk subsystem. Requires model1 and controller to be set. Collision type may be left as auto automatically determine the collision type.
 */
UCLASS()
class IMSTK_API UControllerInteraction : public UCollisionInteraction
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Collision Interaction")
		UImstkController* Controller;

	/** Initializes the interaction between model and controller
	* @return None
	*/
	virtual void Init() override;
};
