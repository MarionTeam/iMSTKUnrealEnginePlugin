// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
//#include "ImstkSubsystem.h"
//#include "RBDModel.h"
#include "imstkRigidObject2.h"
#include "imstkPbdObjectStitching.h"
#include "imstkPbdRigidObjectGrasping.h"
#include "imstkPbdObjectCutting.h"
#include "CollisionInteraction.h"
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
	VertexGrasp,
	CellGrasp
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
class IMSTK_API UImstkController : public USceneComponent
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

	TArray<std::shared_ptr<imstk::CollisionInteraction>> Collisions;

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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (EditCondition = "ToolType == EToolType::GraspingTool", EditConditionHides), Category = "ToolSettings")
		TEnumAsByte<EGraspType> GraspType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (EditCondition = "ToolType == EToolType::GraspingTool", EditConditionHides), Category = "ToolSettings")
		float GraspStiffness = 0.0;


	// TODO: Do not pick auto! Change to remove auto from collision types
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (EditCondition = "GraspType == EGraspType::CellGrasp && ToolType == EToolType::GraspingTool", EditConditionHides), Category = "ToolSettings")
		TEnumAsByte<ECollisionInteractionType> GraspCollisionType;

	/*UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (EditCondition = "ToolGeometry == EToolGeometry::LineMeshTool", EditConditionHides), Category = "ToolSettings")
		bool bStitchingTool = false;*/

	/*UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (EditCondition = "ToolGeometry == EToolGeometry::SurfaceMeshTool", EditConditionHides), Category = "ToolSettings")
		bool bCuttingTool = false;*/

	UFUNCTION(BlueprintCallable, Category = "Imstk")
		void SetStaticMeshComp(UStaticMeshComponent* InputMeshComp);

	UFUNCTION(BlueprintCallable, Category = "Imstk")
		void DisableAllCollisions();

	UFUNCTION(BlueprintCallable, Category = "Imstk")
		void EnableAllCollisions();


	/** Initializes the controller in imstk
	* @return None
	*/
	virtual void InitController();

	std::shared_ptr<imstk::RigidObject2> GetToolObj();

	void AddToolPicking(std::shared_ptr<imstk::PbdObjectGrasping> InputPicking);

	void AddStitching(std::shared_ptr<imstk::PbdObjectStitching> InputStitch);

	void AddCutting(std::shared_ptr<imstk::PbdObjectCutting> InputCutting);

	void AddCollision(std::shared_ptr<imstk::CollisionInteraction> InputCollision);

protected:
	// TODO: Maybe separate into different tool types (stitching tool as a separate class)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (EditCondition = "ToolGeometry == EToolGeometry::LineMeshTool", EditConditionHides), Category = "ToolSettings")
		FVector Vertex1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (EditCondition = "ToolGeometry == EToolGeometry::LineMeshTool", EditConditionHides), Category = "ToolSettings")
		FVector Vertex2;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ClampMin = "0.01", EditCondition = "ToolGeometry == EToolGeometry::SphereTool || ToolGeometry == EToolGeometry::CapsuleTool", EditConditionHides), Category = "ToolSettings")
		float Radius = 1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ClampMin = "0.01", EditCondition = " ToolGeometry == EToolGeometry::CapsuleTool", EditConditionHides), Category = "ToolSettings")
		float Length = 1;

	// Shifts the origin of the capsule to this position (origin of capsule geometry defaults to center of capsule)
	UPROPERTY(EditAnywhere, meta = (EditCondition = "ToolGeometry == EToolGeometry::CapsuleTool", EditConditionHides), Category = "ToolSettings")
		FVector GeometryOffset;

public:
	virtual void UnInit();
};
