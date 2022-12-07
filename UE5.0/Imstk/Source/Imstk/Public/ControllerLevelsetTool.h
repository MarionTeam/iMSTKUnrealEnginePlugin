// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ControllerTool.h"
#include "ControllerLevelsetTool.generated.h"

/**
 * 
 */
UCLASS()
class IMSTK_API UControllerLevelsetTool : public UControllerTool
{
	GENERATED_BODY()

public:
	virtual EControllerObjectType Init(UImstkController* Controller, const FControllerToolFilter& ToolFilter) override;

	virtual bool CreateInteraction(UDynamicalModel* OtherObject) override;
};
