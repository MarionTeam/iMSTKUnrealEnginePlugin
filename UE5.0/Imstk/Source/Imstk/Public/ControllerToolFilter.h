// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ControllerToolFilter.generated.h"

// Type of tool
UENUM(BlueprintType)
enum EToolType
{
	GraspingTool,
	StitchingTool,
	CollidingTool,
	CuttingTool,
	LevelSetTool,
	TetrahedralCuttingTool
};

UENUM(BlueprintType)
enum EGraspType
{
	RayPointGrasp,
	VertexGrasp,
	CellGrasp
};

USTRUCT(BlueprintType)
struct FControllerGraspingToolStruct
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Meta = (ClampMin = "0"), BlueprintReadWrite, Category = "iMSTK|ToolSettings")
		double GraspStiffness = 1.0;

	UPROPERTY(EditAnywhere, Meta = (ClampMin = "0"), BlueprintReadWrite, Category = "iMSTK|ToolSettings")
		double GraspCompliance = 0.0001;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "iMSTK|ToolSettings")
		bool bRigidTool = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "iMSTK|ToolSettings")
		TEnumAsByte<EGraspType> GraspType = EGraspType::VertexGrasp;
};

USTRUCT(BlueprintType)
struct FControllerStitchingToolStruct
{
	GENERATED_BODY()

};

USTRUCT(BlueprintType)
struct FControllerCollisionToolStruct
{
	GENERATED_BODY()

		UPROPERTY(EditAnywhere, Meta = (ClampMin = "0"), BlueprintReadWrite, Category = "iMSTK|ToolSettings")
		double Friction = 0.0;

	UPROPERTY(EditAnywhere, Meta = (ClampMin = "0"), BlueprintReadWrite, Category = "iMSTK|ToolSettings")
		double Stiffness = 1.0;

	UPROPERTY(EditAnywhere, Meta = (ClampMin = "0"), BlueprintReadWrite, Category = "iMSTK|ToolSettings")
		double RigidBodyCompliance = 0.0;

	UPROPERTY(EditAnywhere, Meta = (ClampMin = "0"), BlueprintReadWrite, Category = "iMSTK|ToolSettings")
		double Restitution = 0.0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "iMSTK|ToolSettings")
		bool bUseCorrectVelocity = true;
};

USTRUCT(BlueprintType)
struct FControllerCuttingToolStruct
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "iMSTK|ToolSettings")
		double CutEpsilon = 1.0;
};

USTRUCT(BlueprintType)
struct FControllerLevelsetToolStruct
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "iMSTK|ToolSettings")
		bool bUseFriction = false;

	UPROPERTY(EditAnywhere, Meta = (ClampMin = "0"), BlueprintReadWrite, Category = "iMSTK|ToolSettings")
		double Stiffness = 0.5;

	UPROPERTY(EditAnywhere, Meta = (ClampMin = "0"), BlueprintReadWrite, Category = "iMSTK|ToolSettings")
		double VelocityScaling = 1.0;
};

USTRUCT(BlueprintType)
struct FControllerTetrahedralCuttingToolStruct
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Meta = (ClampMin = "0"), BlueprintReadWrite, Category = "iMSTK|ToolSettings")
		double PlaneWidth = 0.0;
};

class UControllerTool;
/**
 * 
 */
USTRUCT(BlueprintType)
struct FControllerToolFilter
{
	GENERATED_BODY()

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "iMSTK")
		TEnumAsByte<EToolType> ToolType;

	// Structs for each shape that can be created in Imstk
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (EditCondition = "ToolType == EToolType::GraspingTool", EditConditionHides), Category = "iMSTK")
		FControllerGraspingToolStruct GraspingToolStruct;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (EditCondition = "ToolType == EToolType::StitchingTool", EditConditionHides), Category = "iMSTK")
		FControllerStitchingToolStruct StitchingToolStruct;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (EditCondition = "ToolType == EToolType::CollidingTool", EditConditionHides), Category = "iMSTK")
		FControllerCollisionToolStruct CollisionToolStruct;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (EditCondition = "ToolType == EToolType::CuttingTool", EditConditionHides), Category = "iMSTK")
		FControllerCuttingToolStruct CuttingToolStruct;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (EditCondition = "ToolType == EToolType::LevelsetTool", EditConditionHides), Category = "iMSTK")
		FControllerLevelsetToolStruct LevelsetToolStruct;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (EditCondition = "ToolType == EToolType::TetrahedralCuttingTool", EditConditionHides), Category = "iMSTK")
		FControllerTetrahedralCuttingToolStruct TetrahedralCuttingToolStruct;

	UControllerTool* CreateTool();


};


