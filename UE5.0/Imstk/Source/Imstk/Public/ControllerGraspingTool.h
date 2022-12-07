// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ControllerTool.h"
#include "imstkPbdObjectGrasping.h"
#include "ControllerGraspingTool.generated.h"

/**
 * 
 */
UCLASS()
class IMSTK_API UControllerGraspingTool : public UControllerTool
{
	GENERATED_BODY()

public:
	virtual EControllerObjectType Init(UImstkController* Controller, const FControllerToolFilter& ToolFilter) override;

	virtual bool CreateInteraction(UDynamicalModel* OtherObject) override;

	virtual bool Execute() override;

	virtual bool Release() override;

	virtual void UnInit() override;
	

	/** Adds a grasping interaction to the tool. Multiple can be assigned to grasp more than one object
	* @param InputPicking Grasping interaction to be added to the tool
	* @return None
	*/
	//void AddToolPicking(std::shared_ptr<imstk::PbdObjectGrasping> InputPicking);

protected:
	// Array containing grasping interactions
	TArray<std::shared_ptr<imstk::PbdObjectGrasping>> ToolPickings;
};
