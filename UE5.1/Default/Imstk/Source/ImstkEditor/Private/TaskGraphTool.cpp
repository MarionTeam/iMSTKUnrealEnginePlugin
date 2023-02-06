// Fill out your copyright notice in the Description page of Project Settings.


#include "TaskGraphTool.h"
#include "Editor/UnrealEd/Public/Kismet2/BlueprintEditorUtils.h"
#include "TaskGraph.h"
#include "AssetRegistry/AssetRegistryModule.h"
#include "UObject/Package.h"
#include "UObject/SavePackage.h"
#include "Styling/AppStyle.h"


#define LOCTEXT_NAMESPACE "TaskGraphTool"
class TaskGraphToolCommands : public TCommands<TaskGraphToolCommands>
{
public:

	TaskGraphToolCommands()
		: TCommands<TaskGraphToolCommands>(
			TEXT("TaskGraphTool"), // Context name for fast lookup
			FText::FromString("Task Graph Tool"), // Context name for displaying
			NAME_None,   // No parent context
			FAppStyle::GetAppStyleSetName() // Icon Style Set
			)
	{
	}

	virtual void RegisterCommands() override
	{
		UI_COMMAND(OpenTaskGraph, "Open Task Graph", "Test Open Task Graph", EUserInterfaceActionType::Button, FInputGesture());

	}

public:
	TSharedPtr<FUICommandInfo> OpenTaskGraph;
};

void TaskGraphTool::MapCommands()
{
	const auto& Commands = TaskGraphToolCommands::Get();

	CommandList->MapAction(
		Commands.OpenTaskGraph,
		FExecuteAction::CreateSP(this, &TaskGraphTool::OpenTaskGraph),
		FCanExecuteAction());
}

void TaskGraphTool::OnStartupModule()
{
	CommandList = MakeShareable(new FUICommandList);
	TaskGraphToolCommands::Register();
	MapCommands();
	FImstkEditorModule::Get().AddMenuExtension(
		FMenuExtensionDelegate::CreateRaw(this, &TaskGraphTool::MakeMenuEntry),
		FName("Task_Graph"),
		CommandList);
}

void TaskGraphTool::OnShutdownModule()
{
	TaskGraphToolCommands::Unregister();
}

void TaskGraphTool::MakeMenuEntry(FMenuBuilder& menuBuilder)
{
	menuBuilder.AddMenuEntry(TaskGraphToolCommands::Get().OpenTaskGraph);
}

void TaskGraphTool::OpenTaskGraph()
{
	// Currently doesnt actually open the task graph, but creates the asset for it
	FString AssetPath = FPaths::ProjectContentDir();
	FString AssetName = GEditor->GetEditorWorldContext().World()->GetMapName();
	FString FilePath = FString::Printf(TEXT("%s%s%S"), *AssetPath.Append("TaskGraphs/"), *AssetName, ".uasset");
	UTaskGraph* TaskGraph;

	if (!FPaths::FileExists(FilePath)) {
		FString PackagePath = TEXT("/Game/TaskGraphs/") + AssetName;

		UPackage* Package = CreatePackage(*PackagePath);
		TaskGraph = NewObject<UTaskGraph>(Package, UTaskGraph::StaticClass(), *AssetName, EObjectFlags::RF_Public | EObjectFlags::RF_Standalone);

		FAssetRegistryModule::AssetCreated(TaskGraph);
		TaskGraph->MarkPackageDirty();

		FSavePackageArgs SavePackageArgs = { nullptr, nullptr, EObjectFlags::RF_Standalone ,0U, false, true, true, FDateTime::MinValue(), GError };

		bool IsSuccessful = UPackage::SavePackage(Package, TaskGraph, *FilePath, SavePackageArgs);

		UE_LOG(LogClass, Log, TEXT("File created"));
	}
	else {
		FSoftObjectPath AssetReference(TEXT("/Game/TaskGraphs/") + AssetName);
		TaskGraph = Cast<UTaskGraph>(AssetReference.TryLoad());
		UE_LOG(LogClass, Log, TEXT("File already exists"));
	}
	
}

#undef LOCTEXT_NAMESPACE