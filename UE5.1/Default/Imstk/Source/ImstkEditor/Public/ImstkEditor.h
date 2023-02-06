// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"
#include <IAssetTools.h>
#include <EdGraphUtilities.h>

class IImstkModuleListenerInterface
{
public:
	virtual void OnStartupModule() {};
	virtual void OnShutdownModule() {};
};

class FImstkEditorModule : public IModuleInterface
{
public:
	void StartupModule() override;

	void ShutdownModule() override;

	void AddModuleListeners();

protected:
	TArray<TSharedRef<IImstkModuleListenerInterface>> ModuleListeners;

public:
	void AddMenuExtension(const FMenuExtensionDelegate& extensionDelegate, FName extensionHook, const TSharedPtr<FUICommandList>& CommandList = NULL, EExtensionHook::Position position = EExtensionHook::Before);
	TSharedRef<FWorkspaceItem> GetMenuRoot() { return MenuRoot; };

	static inline FImstkEditorModule& Get()
	{
		return FModuleManager::LoadModuleChecked<FImstkEditorModule>("ImstkEditor");
	}

protected:
	TSharedPtr<FExtensibilityManager> LevelEditorMenuExtensibilityManager;
	TSharedPtr<FExtender> MenuExtender;

	static TSharedRef<FWorkspaceItem> MenuRoot;

	void MakePulldownMenu(FMenuBarBuilder& menuBuilder);
	void FillPulldownMenu(FMenuBuilder& menuBuilder);

	TArray< TSharedPtr<IAssetTypeActions> > CreatedAssetTypeActions;
	EAssetTypeCategories::Type TaskGraphAssetCategoryBit;

	TSharedPtr<FGraphPanelNodeFactory> TaskGraphNodeFactory;
};
