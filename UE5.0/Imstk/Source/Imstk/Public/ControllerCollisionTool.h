// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ControllerTool.h"
#include "imstkPbdObjectCollision.h"
#include "ControllerCollisionTool.generated.h"

/**
 * 
 */
UCLASS()
class IMSTK_API UControllerCollisionTool : public UControllerTool
{
	GENERATED_BODY()

public:
	virtual EControllerObjectType Init(UImstkController* Controller, const FControllerToolFilter& ToolFilter) override;

	virtual bool CreateInteraction(UDynamicalModel* OtherObject) override;

	//virtual bool Execute() override;

	//virtual bool Release() override;

	TArray<std::shared_ptr<imstk::PbdObjectCollision>> Collisions;

protected:
};
