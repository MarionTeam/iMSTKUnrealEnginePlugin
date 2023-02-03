// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EdGraph/EdGraphSchema.h"
#include "TaskGraphSchema.generated.h"

/** \file TaskGraphSchema.h
 *  \brief Schema for the iMSTK task graph
 *  \details
 */
UCLASS()
class IMSTKEDITOR_API UTaskGraphSchema : public UEdGraphSchema
{
	GENERATED_BODY()

public:
	virtual const FPinConnectionResponse CanCreateConnection(const UEdGraphPin* A, const UEdGraphPin* B) const override;
	virtual class FConnectionDrawingPolicy* CreateConnectionDrawingPolicy(int32 InBackLayerID, int32 InFrontLayerID, float InZoomFactor, const FSlateRect& InClippingRect, class FSlateWindowElementList& InDrawElements, class UEdGraph* InGraphObj) const override;
};
