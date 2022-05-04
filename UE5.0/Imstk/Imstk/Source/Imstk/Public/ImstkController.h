// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
//#include "ImstkSubsystem.h"
//#include "RBDModel.h"
#include "iMSTK-5.0/imstkRigidObject2.h"
#include "iMSTK-5.0/imstkPbdObjectStitching.h"
#include "iMSTK-5.0/imstkPbdRigidObjectGrasping.h"
#include "ImstkController.generated.h"

class UImstkSubsystem;

UENUM()
enum EToolGeometry
{
	LineMeshTool,
	SphereTool,
	CapsuleTool
};

UENUM()
enum EGraspType
{
	RayPointGrasp,
	VertexGrasp
};

UENUM()
enum EToolType
{
	GraspingTool,
	StitchingTool,
	CollidingTool
};


/** \file ImstkController.h
 *  \brief Abstract class for object in imstk that can be controlled by the user
 *  \details 
 */
UCLASS(Abstract)
class IMSTK_API UImstkController : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UImstkController();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY()
		UImstkSubsystem* SubsystemInstance;

	bool bIsInitialized = false;
	std::shared_ptr<imstk::RigidObject2> ToolObj;

	std::shared_ptr<imstk::PbdObjectGrasping> ToolPicking;

	std::shared_ptr<imstk::PbdObjectStitching> Stitching;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	virtual void InitializeComponent() override;

	UFUNCTION(BlueprintCallable, Category = "Imstk")
		bool IsInitialized();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "General")
		TEnumAsByte<EToolGeometry> ToolGeometry;

	// TODO: If you set as true with a spheretool then change geometry it will be hidden but still set to true
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (EditCondition = "ToolGeometry == EToolGeometry::SphereTool || ToolGeometry == EToolGeometry::CapsuleTool", EditConditionHides), Category = "General")
		bool bGraspingTool = false;

	UPROPERTY(EditAnywhere, meta = (EditCondition = "bGraspingTool && ToolGeometry == EToolGeometry::SphereTool || ToolGeometry == EToolGeometry::CapsuleTool", EditConditionHides), Category = "General")
		TEnumAsByte<EGraspType> GraspType;

	UPROPERTY(EditAnywhere, meta = (EditCondition = "bGraspingTool && ToolGeometry == EToolGeometry::SphereTool || ToolGeometry == EToolGeometry::CapsuleTool", EditConditionHides), Category = "General")
		float GraspStiffness = 0.0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (EditCondition = "ToolGeometry == EToolGeometry::LineMeshTool", EditConditionHides), Category = "General")
		bool bStitchingTool = false;

	//std::shared_ptr<imstk::PbdObjectStitching> Stitching;

	/** Initializes the controller in imstk
	* @return None
	*/
	virtual void InitController();

	std::shared_ptr<imstk::RigidObject2> GetToolObj();

	void SetToolPicking(std::shared_ptr<imstk::PbdObjectGrasping> Picking);

	void SetStitching(std::shared_ptr<imstk::PbdObjectStitching> Stitching);

protected:
	// TODO: Maybe separate into different tool types (stitching tool as a separate class)
	UPROPERTY(EditAnywhere, meta = (EditCondition = "ToolGeometry == EToolGeometry::LineMeshTool", EditConditionHides), Category = "General")
		FVector Vertex1;
	UPROPERTY(EditAnywhere, meta = (EditCondition = "ToolGeometry == EToolGeometry::LineMeshTool", EditConditionHides), Category = "General")
		FVector Vertex2;
	UPROPERTY(EditAnywhere, meta = (ClampMin = "0.01", EditCondition = "ToolGeometry == EToolGeometry::SphereTool || ToolGeometry == EToolGeometry::CapsuleTool", EditConditionHides), Category = "General")
		float Radius = 1;
	UPROPERTY(EditAnywhere, meta = (ClampMin = "0.01", EditCondition = " ToolGeometry == EToolGeometry::CapsuleTool", EditConditionHides), Category = "General")
		float Length = 1;

public:
	virtual void UnInit();
};
