// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
//#include "ImstkSubsystem.h"
//#include "RBDModel.h"
#include "iMSTK-5.0/imstkRigidObject2.h"
#include "iMSTK-5.0/imstkPbdObjectStitching.h"
#include "iMSTK-5.0/imstkPbdRigidObjectGrasping.h"
#include "iMSTK-5.0/imstkPbdObjectCutting.h"
#include "ImstkController.generated.h"

class UImstkSubsystem;

UENUM()
enum EToolGeometry
{
	LineMeshTool,
	SphereTool,
	CapsuleTool,
	SurfaceMeshTool
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
	CollidingTool,
	CuttingTool
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

	TArray<std::shared_ptr<imstk::PbdObjectGrasping>> ToolPickings;

	TArray<std::shared_ptr<imstk::PbdObjectStitching>> Stitchings;
	
	TArray<std::shared_ptr<imstk::PbdObjectCutting>> Cuttings;

	UPROPERTY()
		UStaticMeshComponent* MeshComp;
	

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	virtual void InitializeComponent() override;

	UFUNCTION(BlueprintCallable, Category = "Imstk")
		bool IsInitialized();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ToolSettings")
		TEnumAsByte<EToolGeometry> ToolGeometry;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ToolSettings")
		TEnumAsByte<EToolType> ToolType;

	/*UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (EditCondition = "ToolGeometry == EToolGeometry::SphereTool || ToolGeometry == EToolGeometry::CapsuleTool", EditConditionHides), Category = "ToolSettings")
		bool bGraspingTool = false;*/

	UPROPERTY(EditAnywhere, meta = (EditCondition = "ToolType == EToolType::GraspingTool", EditConditionHides), Category = "ToolSettings")
		TEnumAsByte<EGraspType> GraspType;

	UPROPERTY(EditAnywhere, meta = (EditCondition = "ToolType == EToolType::GraspingTool", EditConditionHides), Category = "ToolSettings")
		float GraspStiffness = 0.0;

	/*UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (EditCondition = "ToolGeometry == EToolGeometry::LineMeshTool", EditConditionHides), Category = "ToolSettings")
		bool bStitchingTool = false;*/

	/*UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (EditCondition = "ToolGeometry == EToolGeometry::SurfaceMeshTool", EditConditionHides), Category = "ToolSettings")
		bool bCuttingTool = false;*/

	UFUNCTION(BlueprintCallable, Category = "Imstk")
		void SetStaticMeshComp(UStaticMeshComponent* InputMeshComp);


	/** Initializes the controller in imstk
	* @return None
	*/
	virtual void InitController();

	std::shared_ptr<imstk::RigidObject2> GetToolObj();

	void AddToolPicking(std::shared_ptr<imstk::PbdObjectGrasping> Picking);

	void AddStitching(std::shared_ptr<imstk::PbdObjectStitching> InputStitch);

	void AddCutting(std::shared_ptr<imstk::PbdObjectCutting> InputCutting);

	

protected:
	// TODO: Maybe separate into different tool types (stitching tool as a separate class)
	UPROPERTY(EditAnywhere, meta = (EditCondition = "ToolGeometry == EToolGeometry::LineMeshTool", EditConditionHides), Category = "ToolSettings")
		FVector Vertex1;
	UPROPERTY(EditAnywhere, meta = (EditCondition = "ToolGeometry == EToolGeometry::LineMeshTool", EditConditionHides), Category = "ToolSettings")
		FVector Vertex2;
	UPROPERTY(EditAnywhere, meta = (ClampMin = "0.01", EditCondition = "ToolGeometry == EToolGeometry::SphereTool || ToolGeometry == EToolGeometry::CapsuleTool", EditConditionHides), Category = "ToolSettings")
		float Radius = 1;
	UPROPERTY(EditAnywhere, meta = (ClampMin = "0.01", EditCondition = " ToolGeometry == EToolGeometry::CapsuleTool", EditConditionHides), Category = "ToolSettings")
		float Length = 1;

public:
	virtual void UnInit();
};
