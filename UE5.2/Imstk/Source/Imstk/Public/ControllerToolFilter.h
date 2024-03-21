// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ControllerToolFilter.generated.h"

/** \file ControllerToolFilter.h
 *  \brief Exposes parameters for tools to the editor for the user to set
 *  \details
 */

// Type of tool
UENUM(BlueprintType)
enum EToolType
{
	GraspingTool,
	StitchingTool,
	CollidingTool,
	CuttingTool,
	LevelSetTool,
	TetrahedralCuttingTool,
	BurningTool
};

UENUM(BlueprintType)
enum EGraspType
{
	VertexGrasp,
	CellGrasp
};

USTRUCT(BlueprintType)
struct FControllerGraspingToolStruct
{
	GENERATED_BODY()

	// Stiffness of the grasp, 0-1 value that alters the step size in the solver
	UPROPERTY(EditAnywhere, Meta = (ClampMin = "0"), BlueprintReadWrite, Category = "iMSTK|ToolSettings")
		double GraspStiffness = 1.0;

	// Compliance of the grasp
	UPROPERTY(EditAnywhere, Meta = (ClampMin = "0"), BlueprintReadWrite, Category = "iMSTK|ToolSettings")
		double GraspCompliance = 0.0001;

	// Set the tool to a rigid model (defaults to PBD)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "iMSTK|ToolSettings")
		bool bRigidTool = false;

	// Grasp is unaffected by the forces of the object that it is grasping
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "iMSTK|ToolSettings")
		bool bOneWayGrasping = false;

	// Type of grasp
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (EditCondition = "!bOneWayGrasping", EditConditionHides), Category = "iMSTK|ToolSettings")
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

	// Friction for interactions with this controller
	UPROPERTY(EditAnywhere, Meta = (ClampMin = "0"), BlueprintReadWrite, Category = "iMSTK|ToolSettings")
		double Friction = 0.0;

	// Stiffness for interactions with this controller
	UPROPERTY(EditAnywhere, Meta = (ClampMin = "0"), BlueprintReadWrite, Category = "iMSTK|ToolSettings")
		double Stiffness = 1.0;

	// Rigid body compliance for interactions with this controller
	UPROPERTY(EditAnywhere, Meta = (ClampMin = "0"), BlueprintReadWrite, Category = "iMSTK|ToolSettings")
		double RigidBodyCompliance = 0.0;

	// Restitution for interactions with this controller
	UPROPERTY(EditAnywhere, Meta = (ClampMin = "0"), BlueprintReadWrite, Category = "iMSTK|ToolSettings")
		double Restitution = 0.0;

	// Set the tool to a rigid model (defaults to PBD)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "iMSTK|ToolSettings")
		bool bRigidTool = false;

	// Disables calculations for certain forces including but not limited to friction. Disabling can help with collision issues
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "iMSTK|ToolSettings")
		bool bUseCorrectVelocity = true;
};

USTRUCT(BlueprintType)
struct FControllerCuttingToolStruct
{
	GENERATED_BODY()

	// Epsilon of the cut. Determines how lenient the boundaries of the cut are
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "iMSTK|ToolSettings")
		double CutEpsilon = 1.0;
};

USTRUCT(BlueprintType)
struct FControllerLevelsetToolStruct
{
	GENERATED_BODY()

	// Whether or not collision between the tool and levelset model will use friction
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "iMSTK|ToolSettings")
		bool bUseFriction = false;

	// Stiffness of the collision
	UPROPERTY(EditAnywhere, Meta = (ClampMin = "0"), BlueprintReadWrite, Category = "iMSTK|ToolSettings")
		double Stiffness = 0.5;

	// Velocity scaling of the levelset tool. Increasing this value will increase the speed at which the levelset is cut
	UPROPERTY(EditAnywhere, Meta = (ClampMin = "0"), BlueprintReadWrite, Category = "iMSTK|ToolSettings")
		double VelocityScaling = 1.0;
};

USTRUCT(BlueprintType)
struct FControllerTetrahedralCuttingToolStruct
{
	GENERATED_BODY()

	// Size of the plane. Note: 1 is the default editor plane size
	UPROPERTY(EditAnywhere, Meta = (ClampMin = "0"), BlueprintReadWrite, Category = "iMSTK|ToolSettings")
		double PlaneWidth = 1;
};

USTRUCT(BlueprintType)
struct FControllerBurningToolStruct
{
	GENERATED_BODY()

	// Strength of the burning tool
	UPROPERTY(EditAnywhere, Meta = (ClampMin = "10", ClampMax = "200"), BlueprintReadWrite, Category = "iMSTK|ToolSettings")
		double Wattage = 50;
	// On time from 0-1 where 1 is on fully and any value less than 1 is the percent of on time (e.g. 0.8 = 80% on time). This is used to represent the percent of damage that goes into cutting vs cauterizing
	UPROPERTY(EditAnywhere, Meta = (ClampMin = "0", ClampMax = "1"), BlueprintReadWrite, Category = "iMSTK|ToolSettings")
		double OnTime = 0.5;

};

class UControllerTool;

USTRUCT(BlueprintType)
struct FControllerToolFilter
{
	GENERATED_BODY()

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "iMSTK")
		TEnumAsByte<EToolType> ToolType;

	// Structs for each Tool that can be created in Imstk
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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (EditCondition = "ToolType == EToolType::BurningTool", EditConditionHides), Category = "iMSTK")
		FControllerBurningToolStruct BurningToolStruct;

	UControllerTool* CreateTool();


};


