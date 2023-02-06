// Fill out your copyright notice in the Description page of Project Settings.

#include "ControllerToolFilter.h"
#include "ControllerGraspingTool.h"
#include "ControllerCollisionTool.h"
#include "ControllerStitchingTool.h"
#include "ControllerCuttingTool.h"
#include "ControllerTetrahedralCuttingTool.h"
#include "ControllerLevelsetTool.h"
#include "ControllerBurningTool.h"

UControllerTool* FControllerToolFilter::CreateTool() {
	switch (ToolType)
	{
	case EToolType::GraspingTool:
		return NewObject<UControllerGraspingTool>();
	case EToolType::StitchingTool :
		return NewObject<UControllerStitchingTool>();
	case EToolType::CollidingTool:
		return NewObject<UControllerCollisionTool>();
	case EToolType::CuttingTool:
		return NewObject<UControllerCuttingTool>();
	case EToolType::LevelSetTool:
		return NewObject<UControllerLevelsetTool>();
	case EToolType::TetrahedralCuttingTool:
		return NewObject<UControllerTetrahedralCuttingTool>();
	case EToolType::BurningTool:
		return NewObject<UControllerBurningTool>();
	default:
		return nullptr;
	}
}