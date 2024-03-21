// Fill out your copyright notice in the Description page of Project Settings.


#include "TaskGraphSchema.h"
#include "TaskGraphConnectionDrawingPolicy.h"

#define LOCTEXT_NAMESPACE "TaskGraphSchema"
class FConnectionDrawingPolicy* UTaskGraphSchema::CreateConnectionDrawingPolicy(int32 InBackLayerID, int32 InFrontLayerID, float InZoomFactor, const FSlateRect& InClippingRect, class FSlateWindowElementList& InDrawElements, class UEdGraph* InGraphObj) const
{
	return new FTaskGraphConnectionDrawingPolicy(InBackLayerID, InFrontLayerID, InZoomFactor, InClippingRect, InDrawElements, InGraphObj);
}

const FPinConnectionResponse UTaskGraphSchema::CanCreateConnection(const UEdGraphPin* A, const UEdGraphPin* B) const 
{
	return FPinConnectionResponse(CONNECT_RESPONSE_MAKE, LOCTEXT("PinConnect", "Connect nodes"));
}
#undef LOCTEXT_NAMESPACE