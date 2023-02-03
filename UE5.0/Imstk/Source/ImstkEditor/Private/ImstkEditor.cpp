// Copyright Epic Games, Inc. All Rights Reserved.

#include "ImstkEditor.h"
#include "LevelEditor.h"
#include "TaskGraphTool.h"
#include "TaskGraphAssetTypeActions.h"
#include "TaskGraphNodeFactory.h"

#define LOCTEXT_NAMESPACE "FImstkEditorModule"

void FImstkEditorModule::StartupModule()
{
	//// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	if (!IsRunningCommandlet())
	{
		FLevelEditorModule& LevelEditorModule = FModuleManager::LoadModuleChecked<FLevelEditorModule>("LevelEditor");
		LevelEditorMenuExtensibilityManager = LevelEditorModule.GetMenuExtensibilityManager();
		MenuExtender = MakeShareable(new FExtender);
		MenuExtender->AddMenuBarExtension("Window", EExtensionHook::After, NULL, FMenuBarExtensionDelegate::CreateRaw(this, &FImstkEditorModule::MakePulldownMenu));
		LevelEditorMenuExtensibilityManager->AddExtender(MenuExtender);
	}

	// For multiple modules, but currently not in use
	if (!IsRunningCommandlet())
	{
		AddModuleListeners();
		for (int32 i = 0; i < ModuleListeners.Num(); ++i)
		{
			ModuleListeners[i]->OnStartupModule();
		}
	}

	TaskGraphNodeFactory = MakeShareable(new FTaskGraphNodeFactory());
	FEdGraphUtilities::RegisterVisualNodeFactory(TaskGraphNodeFactory);

	IAssetTools& AssetTools = FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools").Get();
	TaskGraphAssetCategoryBit = AssetTools.RegisterAdvancedAssetCategory(FName(TEXT("TaskGraph")), LOCTEXT("TaskGraphAssetCategory", "TaskGraph"));
	TSharedRef<IAssetTypeActions> Action = MakeShareable(new FTaskGraphAssetTypeActions(TaskGraphAssetCategoryBit));

	AssetTools.RegisterAssetTypeActions(Action);
	CreatedAssetTypeActions.Add(Action);
}

void FImstkEditorModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
	for (int32 i = 0; i < ModuleListeners.Num(); ++i)
	{
		ModuleListeners[i]->OnShutdownModule();
	}

	if (FModuleManager::Get().IsModuleLoaded("AssetTools"))
	{
		IAssetTools& AssetTools = FModuleManager::GetModuleChecked<FAssetToolsModule>("AssetTools").Get();
		for (int32 Index = 0; Index < CreatedAssetTypeActions.Num(); ++Index)
		{
			AssetTools.UnregisterAssetTypeActions(CreatedAssetTypeActions[Index].ToSharedRef());
		}
	}

	if (TaskGraphNodeFactory.IsValid())
	{
		FEdGraphUtilities::UnregisterVisualNodeFactory(TaskGraphNodeFactory);
		TaskGraphNodeFactory.Reset();
	}
}

TSharedRef<FWorkspaceItem> FImstkEditorModule::MenuRoot = FWorkspaceItem::NewGroup(FText::FromString("Menu Root"));


void FImstkEditorModule::AddMenuExtension(const FMenuExtensionDelegate& extensionDelegate, FName extensionHook, const TSharedPtr<FUICommandList>& CommandList, EExtensionHook::Position position)
{
	MenuExtender->AddMenuExtension(extensionHook, position, CommandList, extensionDelegate);
}

void FImstkEditorModule::MakePulldownMenu(FMenuBarBuilder& menuBuilder)
{

}

void FImstkEditorModule::FillPulldownMenu(FMenuBuilder& menuBuilder)
{

}

void FImstkEditorModule::AddModuleListeners()
{
	ModuleListeners.Add(MakeShareable(new TaskGraphTool));
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FImstkEditorModule, ImstkEditor)