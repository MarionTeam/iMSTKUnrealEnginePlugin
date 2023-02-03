// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SGraphNode.h"
#include <EdGraph/EdGraphNode.h>

/** \file STaskGraphNode.h
 *  \brief Slate UI for a task graph node
 *  \details 
 */
class IMSTKEDITOR_API STaskGraphNode : public SGraphNode
{
public:
	SLATE_BEGIN_ARGS(STaskGraphNode) {}
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs, UEdTaskGraphNode* InNode);

	virtual void UpdateGraphNode() override;

	virtual FSlateColor GetBorderBackgroundColor() const;

	virtual FSlateColor GetBackgroundColor() const;

	virtual EVisibility GetDragOverMarkerVisibility() const;

	virtual void CreatePinWidgets() override;

};
