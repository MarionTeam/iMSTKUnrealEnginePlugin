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
#include "GeometryFilter.h"
#include "ImstkController.generated.h"

class UImstkSubsystem;

// Geometry of the tool
UENUM()
enum EToolGeometry
{
	LineMeshTool,
	SphereTool,
	CapsuleTool,
	SurfaceMeshTool
};

// Type of grasp for the tool
UENUM(BlueprintType)
enum EGraspType
{
	RayPointGrasp,
	VertexGrasp,
	CellGrasp
};

// Type of tool
UENUM(BlueprintType)
enum EToolType
{
	GraspingTool,
	StitchingTool,
	CollidingTool,
	CuttingTool,
	LevelSetTool
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

	// Pointer to the iMSTK subsystem
	UPROPERTY()
		UImstkSubsystem* SubsystemInstance;

	bool bIsInitialized = false;

	// iMSTK Rigid object of the tool
	std::shared_ptr<imstk::RigidObject2> ToolObj;

	// Array containing grasping interactions
	TArray<std::shared_ptr<imstk::PbdObjectGrasping>> ToolPickings;

	// Array containing stitching interactions
	TArray<std::shared_ptr<imstk::PbdObjectStitching>> Stitchings;

	// Array containing cutting interactions
	TArray<std::shared_ptr<imstk::PbdObjectCutting>> Cuttings;

	// Array containing collision interactions
	TArray<std::shared_ptr<imstk::CollisionInteraction>> Collisions;

	// Static mesh component for surface mesh tools. Must be assigned within construction of the blueprint
	UPROPERTY()
		UStaticMeshComponent* MeshComp;


public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	virtual void InitializeComponent() override;

	UFUNCTION(BlueprintCallable, Category = "Imstk")
		bool IsInitialized();

	// Geometry of the tool
	/*UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ToolSettings")
		TEnumAsByte<EToolGeometry> ToolGeometry;*/

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "General|Advanced")
		FGeometryFilter ToolGeomFilter;

	// Type of tool. Determines the action performed by the tool
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "General|Advanced")
		TEnumAsByte<EToolType> ToolType;

	// Type of grasp performed by the tool
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (EditCondition = "ToolType == EToolType::GraspingTool", EditConditionHides), Category = "General|Advanced")
		TEnumAsByte<EGraspType> GraspType;

	// Stiffness of the grasp performed by the tool
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (EditCondition = "ToolType == EToolType::GraspingTool", EditConditionHides), Category = "General|Advanced")
		float GraspStiffness = 1.0;

	// TODO: Do not pick auto! Change to remove auto from collision types?
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (EditCondition = "GraspType == EGraspType::CellGrasp && ToolType == EToolType::GraspingTool", EditConditionHides), Category = "General|Advanced")
		TEnumAsByte<ECollisionInteractionType> GraspCollisionType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (EditCondition = "ToolType == EToolType::CuttingTool", EditConditionHides), Category = "General|Advanced")
		float CutEpsilon = 1.0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (EditCondition = "ToolType == EToolType::LevelSetTool", EditConditionHides, ClampMin = "0.01"), Category = "General|Advanced")
		float VelocityScaling = 1.0;

	/** Setter for the static mesh component. Required to be set in the construction of the blueprint for surface mesh tools.
	* @param InputMeshComp Static mesh component to be set
	* @return None
	*/
	UFUNCTION(BlueprintCallable, Category = "Imstk")
		void SetStaticMeshComp(UStaticMeshComponent* InputMeshComp);

	/** Disables the collisions of the object in iMSTK
	* @return None
	*/
	UFUNCTION(BlueprintCallable, Category = "Imstk")
		void DisableAllCollisions();

	/** Enables the collisions of the object in iMSTK
	* @return None
	*/
	UFUNCTION(BlueprintCallable, Category = "Imstk")
		void EnableAllCollisions();

	/** Initializes the controller in imstk
	* @return None
	*/
	virtual void InitController();

	/** Returns the rigid object for the tool
	* @return Rigid object for the tool
	*/
	std::shared_ptr<imstk::RigidObject2> GetToolObj();

	/** Adds a grasping interaction to the tool. Multiple can be assigned to grasp more than one object
	* @param InputPicking Grasping interaction to be added to the tool
	* @return None
	*/
	void AddToolPicking(std::shared_ptr<imstk::PbdObjectGrasping> InputPicking);

	/** Adds a stitching interaction to the tool. Multiple can be assigned to stitch more than one object
	* @param InputStitch Stitching interaction to be added to the tool
	* @return None
	*/
	void AddStitching(std::shared_ptr<imstk::PbdObjectStitching> InputStitch);

	/** Adds a cutting interaction to the tool. Multiple can be assigned to cut more than one object
	* @param InputCutting Cutting interaction to be added to the tool
	* @return None
	*/
	void AddCutting(std::shared_ptr<imstk::PbdObjectCutting> InputCutting);

	/** Adds a Collision interaction to the tool. Multiple can be assigned to collide with more than one object. Array is used to disable and enable the collisions
	* @param InputCollision Collision interaction to be added to the tool
	* @return None
	*/
	void AddCollision(std::shared_ptr<imstk::CollisionInteraction> InputCollision);

	/** Calculates and returns the scale applied to Unreal's basic shapes in order to have the same shape as iMSTK's geometry
	* @return FVector - Scale of the geometry or zero vector if not implemented
	*/
	UFUNCTION(BlueprintCallable, Category = "iMSTK")
		FVector GetGeomScale();

	/** Returns the amount the geometry is offset within iMSTK
	* @return FVector - Offset of the geometry or zero vector if not implemented
	*/
	UFUNCTION(BlueprintCallable, Category = "iMSTK")
		FVector GetGeomOffset();
public:
	// Called from the subsystem to clear shared pointers
	virtual void UnInit();
};
