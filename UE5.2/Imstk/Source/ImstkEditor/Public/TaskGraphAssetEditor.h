// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TaskGraph.h"

/** \file TaskGraphAssetEditor.h
 *  \brief Asset editor for the iMSTK task graph
 *  \details 
 */
class IMSTKEDITOR_API FTaskGraphAssetEditor : public FAssetEditorToolkit, public FNotifyHook, public FGCObject
{
public:
	FTaskGraphAssetEditor();
	virtual ~FTaskGraphAssetEditor();

	void InitTaskGraphAssetEditor(const EToolkitMode::Type Mode, const TSharedPtr< IToolkitHost >& InitToolkitHost, UTaskGraph* Graph);

	virtual void RegisterTabSpawners(const TSharedRef<FTabManager>& TabManager) override;
	virtual void UnregisterTabSpawners(const TSharedRef<FTabManager>& TabManager) override;

	// Inherited via FAssetEditorToolkit
	virtual FLinearColor GetWorldCentricTabColorScale() const override;
	virtual FName GetToolkitFName() const override;
	virtual FText GetBaseToolkitName() const override;
	virtual FString GetWorldCentricTabPrefix() const override;

	// Inherited via FGCObject
	virtual void AddReferencedObjects(FReferenceCollector& Collector) override;

protected:
	TSharedRef<SDockTab> SpawnViewport(const FSpawnTabArgs& Args);

	UTaskGraph* TaskGraph;
	TSharedPtr<SGraphEditor> ViewportWidget;

	void CreateNodes();
	void CreateEdges();

	TArray<UEdTaskGraphNode*> CachedNodes;
};
