// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <EdGraphUtilities.h>
#include <EdGraph/EdGraphNode.h>

/**
 * 
 */
class FTaskGraphNodeFactory : public FGraphPanelNodeFactory
{
public:
	virtual TSharedPtr<class SGraphNode> CreateNode(UEdGraphNode* Node) const override;
};
