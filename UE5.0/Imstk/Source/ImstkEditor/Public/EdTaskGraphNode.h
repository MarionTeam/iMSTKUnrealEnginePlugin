// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EdGraph/EdGraphNode.h"
#include "TaskGraph.h"
#include "EdTaskGraphNode.generated.h"

/** \file EdTaskGraphNode.h
 *  \brief Representation of the task graph node in the editor
 *  \details 
 */
UCLASS()
class IMSTKEDITOR_API UEdTaskGraphNode : public UEdGraphNode
{
	GENERATED_BODY()

public:
	UEdTaskGraphNode();
	virtual ~UEdTaskGraphNode();
	virtual void AllocateDefaultPins() override;

	virtual UEdGraphPin* GetInputPin() const;
	virtual UEdGraphPin* GetOutputPin() const;

	FTaskGraphNode TaskGraphNode;
};
