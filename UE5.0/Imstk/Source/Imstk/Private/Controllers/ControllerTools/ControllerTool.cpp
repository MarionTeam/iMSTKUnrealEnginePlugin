// Fill out your copyright notice in the Description page of Project Settings.


#include "ControllerTool.h"

UControllerTool::UControllerTool()
{
	 
}

EControllerObjectType UControllerTool::Init(UImstkController* Controller, const FControllerToolFilter& ToolFilter)
{
	return EControllerObjectType::Null;
}

std::shared_ptr<imstk::SceneObject> UControllerTool::CreateInteraction(UDynamicalModel* OtherObject)
{
	return nullptr;
}

bool UControllerTool::IsInitialized()
{
	return bIsInitialized;
}

// TODO: return unimplemented if running from this class
bool UControllerTool::Execute()
{
	return false;
}

bool UControllerTool::Release()
{
	return false;
}

void UControllerTool::UnInit() 
{

}

