// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <EdGraphUtilities.h>
#include <EdGraph/EdGraphNode.h>

/** \file TaskGraphNodeFactory.h
 *  \brief Node factory for the iMSTK task graph
 *  \details 
 */
class FTaskGraphNodeFactory : public FGraphPanelNodeFactory
{
public:
	virtual TSharedPtr<class SGraphNode> CreateNode(UEdGraphNode* Node) const override;
};
