// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SlateBasics.h"
#include "SlateExtras.h"
#include "Editor/LevelEditor/Public/LevelEditor.h"
#include "Editor/PropertyEditor/Public/PropertyEditing.h"
#include "IAssetTypeActions.h"
#include "ImstkEditor.h"

/**
 * 
 */
class TaskGraphTool : public IImstkModuleListenerInterface, public TSharedFromThis<TaskGraphTool>
{
public:
    virtual ~TaskGraphTool() {}

    virtual void OnStartupModule() override;
    virtual void OnShutdownModule() override;

    void MakeMenuEntry(FMenuBuilder& menuBuilder);

protected:
    TSharedPtr<FUICommandList> CommandList;

    void MapCommands();

    // UI Command functions
    void OpenTaskGraph();
};
