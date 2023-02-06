// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "imstkTaskGraph.h"
#include "TaskGraph.generated.h"

USTRUCT(BlueprintType)
struct IMSTK_API FTaskGraphNode
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY()
		FString Name;

	UPROPERTY()
		int Index;

	UPROPERTY()
		int DisplayDepth;

	UPROPERTY()
		FLinearColor Color;

	UPROPERTY()
		TArray<int> ChildNodeIndices;
	UPROPERTY()
		TArray<int> ParentNodeIndices;

	FTaskGraphNode() {};
	FTaskGraphNode(int Index, FString Name, FLinearColor Color) : Name(Name), Index(Index), Color(Color) {};
};

/** \file TaskGraph.h
 *  \brief Representation of an iMSTK task graph
 *  \details 
 */
UCLASS(Blueprintable)
class IMSTK_API UTaskGraph : public UObject
{
	GENERATED_BODY()

public:
	UTaskGraph();
	virtual ~UTaskGraph();

#if WITH_EDITORONLY_DATA
	UEdGraph* EdGraph;
	UPROPERTY()
		TArray<FTaskGraphNode> Nodes;

	UPROPERTY()
		int SourceIndex;

	UPROPERTY()
		int SinkIndex;

	void Clear();
#endif
};
