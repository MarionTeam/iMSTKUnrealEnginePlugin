// Fill out your copyright notice in the Description page of Project Settings.


#include "TaskGraphAssetTypeActions.h"
#include "TaskGraphAssetEditor.h"
#include "TaskGraph.h"

#define LOCTEXT_NAMESPACE "TaskGraphAssetTypeActions"

FTaskGraphAssetTypeActions::FTaskGraphAssetTypeActions(EAssetTypeCategories::Type InAssetCategory) : MyAssetCategory(InAssetCategory)
{
}

void FTaskGraphAssetTypeActions::OpenAssetEditor(const TArray<UObject*>& InObjects, TSharedPtr<class IToolkitHost> EditWithinLevelEditor)
{
	const EToolkitMode::Type Mode = EditWithinLevelEditor.IsValid() ? EToolkitMode::WorldCentric : EToolkitMode::Standalone;

	for (auto ObjIt = InObjects.CreateConstIterator(); ObjIt; ++ObjIt)
	{
		if (UTaskGraph* Graph = Cast<UTaskGraph>(*ObjIt))
		{
			TSharedRef<FTaskGraphAssetEditor> NewGraphEditor(new FTaskGraphAssetEditor());
			NewGraphEditor->InitTaskGraphAssetEditor(Mode, EditWithinLevelEditor, Graph);
		}
	}
}

// TODO: Not sure if these are necessary
FText FTaskGraphAssetTypeActions::GetName() const
{
	return LOCTEXT("FTaskGraphAssetTypeActionsName", "Task Graph");
}

UClass* FTaskGraphAssetTypeActions::GetSupportedClass() const
{
	return UTaskGraph::StaticClass();
}

FColor FTaskGraphAssetTypeActions::GetTypeColor() const
{
	return FColor(129, 196, 115);
}

uint32 FTaskGraphAssetTypeActions::GetCategories()
{
	return MyAssetCategory;
}

#undef LOCTEXT_NAMESPACE