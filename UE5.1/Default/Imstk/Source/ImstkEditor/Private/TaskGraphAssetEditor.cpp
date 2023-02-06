// Fill out your copyright notice in the Description page of Project Settings.


#include "TaskGraphAssetEditor.h"
#include "Editor/UnrealEd/Public/Kismet2/BlueprintEditorUtils.h"
#include "Framework/Commands/GenericCommands.h"
#include "GraphEditorActions.h"
#include <EdGraph/EdGraphNode.h>
#include "STaskGraphNode.h"
#include "SGraphPanel.h"
#include "Kismet/GameplayStatics.h"
#include "TaskGraphSchema.h"
#include "Styling/AppStyle.h"


#define LOCTEXT_NAMESPACE "TaskGraphAssetEditor"

FTaskGraphAssetEditor::FTaskGraphAssetEditor()
{
}

FTaskGraphAssetEditor::~FTaskGraphAssetEditor()
{
}

void FTaskGraphAssetEditor::InitTaskGraphAssetEditor(const EToolkitMode::Type Mode, const TSharedPtr< IToolkitHost >& InitToolkitHost, UTaskGraph* Graph)
{
	// Create graph
	TaskGraph = Graph;

	TaskGraph->EdGraph = CastChecked<UEdGraph>(FBlueprintEditorUtils::CreateNewGraph(TaskGraph, NAME_None, UEdGraph::StaticClass(), UTaskGraphSchema::StaticClass()));
	TaskGraph->EdGraph->bAllowDeletion = false;
	const UEdGraphSchema* Schema = TaskGraph->EdGraph->GetSchema();
	Schema->CreateDefaultNodesForGraph(*TaskGraph->EdGraph);

	FGenericCommands::Register();
	FGraphEditorCommands::Register();

	// Create window for graph
	const TSharedRef<FTabManager::FLayout> StandaloneDefaultLayout = FTabManager::NewLayout("TaskGraph_Layout")
		->AddArea
		(
			FTabManager::NewPrimaryArea()->SetOrientation(Orient_Vertical)
			->Split
			(
				FTabManager::NewSplitter()->SetOrientation(Orient_Horizontal)->SetSizeCoefficient(0.9f)
				->Split
				(
					FTabManager::NewStack()
					->SetSizeCoefficient(0.65f)
					->AddTab(FName("Viewport"), ETabState::OpenedTab)->SetHideTabWell(true)
				)
			)
		);
	FAssetEditorToolkit::InitAssetEditor(Mode, InitToolkitHost, FName("TaskGraphEditorApp"), StandaloneDefaultLayout, true, true, TaskGraph, false);

	RegenerateMenusAndToolbars();

	CreateNodes();
	CreateEdges();
}

void FTaskGraphAssetEditor::RegisterTabSpawners(const TSharedRef<FTabManager>& InTabManager)
{
	WorkspaceMenuCategory = InTabManager->AddLocalWorkspaceMenuCategory(LOCTEXT("WorkspaceMenu_TaskGraphEditor", "Task Graph Editor"));
	auto WorkspaceMenuCategoryRef = WorkspaceMenuCategory.ToSharedRef();

	FAssetEditorToolkit::RegisterTabSpawners(InTabManager);

	InTabManager->RegisterTabSpawner(FName("Viewport"), FOnSpawnTab::CreateSP(this, &FTaskGraphAssetEditor::SpawnViewport))
		.SetDisplayName(LOCTEXT("GraphCanvasTab", "Viewport"))
		.SetGroup(WorkspaceMenuCategoryRef)
		.SetIcon(FSlateIcon(FAppStyle::GetAppStyleSetName(), "GraphEditor.EventGraph_16x"));
}

void FTaskGraphAssetEditor::UnregisterTabSpawners(const TSharedRef<FTabManager>& InTabManager)
{
	FAssetEditorToolkit::UnregisterTabSpawners(InTabManager);

	InTabManager->UnregisterTabSpawner(FName("Viewport"));
}

TSharedRef<SDockTab> FTaskGraphAssetEditor::SpawnViewport(const FSpawnTabArgs& Args)
{
	FGraphAppearanceInfo AppearanceInfo;
	AppearanceInfo.CornerText = LOCTEXT("AppearanceCornerText_TaskGraph", "Task Graph");

	ViewportWidget = SNew(SGraphEditor)
		.IsEditable(true)
		.Appearance(AppearanceInfo)
		.GraphToEdit(TaskGraph->EdGraph)
		.AutoExpandActionMenu(true)
		.ShowGraphStateOverlay(false);

	check(Args.GetTabId() == FName("Viewport"));

	TSharedRef<SDockTab> SpawnedTab = SNew(SDockTab)
		.Label(LOCTEXT("ViewportTab_Title", "Viewport"));

	if (ViewportWidget.IsValid())
	{
		SpawnedTab->SetContent(ViewportWidget.ToSharedRef());
	}

	return SpawnedTab;
}

void FTaskGraphAssetEditor::CreateNodes()
{
	CachedNodes.Empty();
	CachedNodes.SetNum(TaskGraph->Nodes.Num());
	TArray<bool> Visited;
	Visited.SetNum(TaskGraph->Nodes.Num());

	Visited[TaskGraph->SourceIndex] = true;
	TQueue<int> Queue;
	Queue.Enqueue(TaskGraph->SourceIndex);

	// Temporarily set width to using number of characters
	// TODO: Find a way to move nodes based on size of previous node?

	TMap<int, int> OffsetMap;
	TMap<int, int> PreviousWidth;

	// Put into layer of highest depth parent +1 and position nodes in each layer
	while (!Queue.IsEmpty()) {
		int CurIndex;
		Queue.Dequeue(CurIndex);
		UEdTaskGraphNode* NewNode = NewObject<UEdTaskGraphNode>(TaskGraph->EdGraph, UEdTaskGraphNode::StaticClass(), NAME_None, RF_Transactional);
		TaskGraph->EdGraph->AddNode(NewNode);
		NewNode->AllocateDefaultPins();
		CachedNodes[CurIndex] = NewNode;

		if (!OffsetMap.Contains(TaskGraph->Nodes[CurIndex].DisplayDepth))
			OffsetMap.Add(TaskGraph->Nodes[CurIndex].DisplayDepth, 0);

		if (!PreviousWidth.Contains(TaskGraph->Nodes[CurIndex].DisplayDepth))
			PreviousWidth.Add(TaskGraph->Nodes[CurIndex].DisplayDepth, 0);

		NewNode->NodePosX = PreviousWidth[TaskGraph->Nodes[CurIndex].DisplayDepth] + OffsetMap[TaskGraph->Nodes[CurIndex].DisplayDepth]++;
		NewNode->NodePosY = 150 * TaskGraph->Nodes[CurIndex].DisplayDepth;
		NewNode->TaskGraphNode = TaskGraph->Nodes[CurIndex];

		SNew(STaskGraphNode, NewNode);
		PreviousWidth[TaskGraph->Nodes[CurIndex].DisplayDepth] += TaskGraph->Nodes[CurIndex].Name.Len() * 10;


		for (int Child : TaskGraph->Nodes[CurIndex].ChildNodeIndices) {
			if (!Visited[Child]) {
				Visited[Child] = true;
				Queue.Enqueue(Child);

			}
		}
	}
}

void FTaskGraphAssetEditor::CreateEdges() 
{
	TArray<bool> Visited;
	Visited.SetNum(TaskGraph->Nodes.Num());

	Visited[TaskGraph->SourceIndex] = true;
	TQueue<int> Queue;
	Queue.Enqueue(TaskGraph->SourceIndex);
	TaskGraph->EdGraph->GetSchema()->TryCreateConnection(CachedNodes[35]->GetInputPin(), CachedNodes[9]->GetOutputPin());

	// Dfs to create each edge in the graph
	while (!Queue.IsEmpty()) {
		int CurIndex;
		Queue.Dequeue(CurIndex);

		for (int Child : TaskGraph->Nodes[CurIndex].ChildNodeIndices) {
			TaskGraph->EdGraph->GetSchema()->TryCreateConnection(CachedNodes[Child]->GetInputPin(), CachedNodes[CurIndex]->GetOutputPin());
			if (!Visited[Child]) {
				Visited[Child] = true;
				Queue.Enqueue(Child);
			}
		}
	}
	
}

FLinearColor FTaskGraphAssetEditor::GetWorldCentricTabColorScale() const
{
	return FLinearColor::White;
}

FName FTaskGraphAssetEditor::GetToolkitFName() const
{
	return FName("FTaskGraphEditor");
}

FText FTaskGraphAssetEditor::GetBaseToolkitName() const
{
	return LOCTEXT("TaskGraphAssetEditorAppLabel", "Task Graph Editor");
}

FString FTaskGraphAssetEditor::GetWorldCentricTabPrefix() const
{
	return TEXT("TaskGraphEditor");
}

void FTaskGraphAssetEditor::AddReferencedObjects(FReferenceCollector& Collector)
{
	Collector.AddReferencedObject(TaskGraph);
	Collector.AddReferencedObject(TaskGraph->EdGraph);
}

#undef LOCTEXT_NAMESPACE