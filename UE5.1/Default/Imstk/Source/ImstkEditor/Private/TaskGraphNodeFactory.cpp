// Fill out your copyright notice in the Description page of Project Settings.


#include "TaskGraphNodeFactory.h"
#include <EdGraph/EdGraphNode.h>
#include "STaskGraphNode.h"
#include "EdTaskGraphNode.h"

TSharedPtr<class SGraphNode> FTaskGraphNodeFactory::CreateNode(UEdGraphNode* Node) const
{
	if (UEdTaskGraphNode* EdTaskGraphNode = Cast<UEdTaskGraphNode>(Node))
		return SNew(STaskGraphNode, EdTaskGraphNode);
	return nullptr;
}