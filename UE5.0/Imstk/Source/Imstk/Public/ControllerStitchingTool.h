// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ControllerTool.h"
#include "imstkPbdObjectStitching.h"
#include "ControllerStitchingTool.generated.h"

/**
 * 
 */
UCLASS()
class IMSTK_API UControllerStitchingTool : public UControllerTool
{
	GENERATED_BODY()

public:
	virtual EControllerObjectType Init(UImstkController* Controller, const FControllerToolFilter& ToolFilter) override;

	virtual bool CreateInteraction(UDynamicalModel* OtherObject) override;

	virtual bool Execute() override;

	virtual void UnInit() override;

protected:
	TArray<std::shared_ptr<imstk::PbdObjectStitching>> Stitchings;
};
