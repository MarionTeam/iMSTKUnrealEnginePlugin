// Fill out your copyright notice in the Description page of Project Settings.


#include "EdTaskGraphNode.h"

UEdTaskGraphNode::UEdTaskGraphNode()
{
	bCanRenameNode = true;
}

UEdTaskGraphNode::~UEdTaskGraphNode()
{

}

void UEdTaskGraphNode::AllocateDefaultPins()
{
	CreatePin(EGPD_Input, "MultipleNodes", FName(), TEXT("In"));
	CreatePin(EGPD_Output, "MultipleNodes", FName(), TEXT("Out"));
}

UEdGraphPin* UEdTaskGraphNode::GetInputPin() const
{
	return Pins[0];
}

UEdGraphPin* UEdTaskGraphNode::GetOutputPin() const
{
	return Pins[1];
}