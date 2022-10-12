// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ImstkController.h"
#include "DynamicalModel.h"

#include "imstkPbdObject.h"

#include "CustomController.generated.h"

UENUM(BlueprintType)
enum EControllerPreset
{
	CollidingPreset,
	GraspingPreset,
	CuttingPreset,
	StitchingPreset,
	LevelSetPreset
};

/** \file CustomController.h
 *  \brief Customizable controller to move an object within the iMSTK scene
 *  \details
 */
UCLASS(ClassGroup = (Imstk), meta = (BlueprintSpawnableComponent))
class IMSTK_API UCustomController : public UImstkController
{
	GENERATED_BODY()

public:
	UCustomController();

	virtual void PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent);

	UPROPERTY(EditAnywhere, Category = "General")
		TEnumAsByte<EControllerPreset> Preset = EControllerPreset::CollidingPreset;

	virtual void InitializeComponent() override;

	/** Initializes the controller in imstk
	* @return None
	*/
	virtual void InitController() override;

	/** Moves the iMSTK object to the inputted location and orientation. Moves the Unreal Actor that the component is attached to to the specified location if bUpdateUnrealPosRot is set.
	* @param Location - The Unreal position to move the controller to
	* @param Orientation - The Unreal orientation to move the controller to
	* @param bUpdateUnrealPosRot - Updates the position and rotation of the Unreal Actor if true
	* @return None
	*/
	UFUNCTION(BlueprintCallable, Category = "Imstk")
		void MoveControllerToLocation(FVector Location, FQuat Orientation, bool bUpdateUnrealPosRot = true);

	/** Projects a ray with the specified start and direction onto the supplied plane to find a point of intersection and moves the iMSTK object to that location.
	* Moves the Unreal Actor that the component is attached to to the specified location if bUpdateUnrealPosRot is set.
	* @param Location - The Unreal position to move the controller to
	* @param Orientation - The Unreal orientation to move the controller to
	* @param bUpdateUnrealPosRot - Updates the position and rotation of the Unreal Actor if true
	* @return The intersection location between the projected ray and the plane
	*/
	UFUNCTION(BlueprintCallable, Category = "Imstk")
		FVector MoveControllerToRaycastOnPlane(FVector RayStart, FVector RayDir, FQuat Orientation, UDynamicalModel* PlaneActor, bool bUpdateUnrealPosRot = true);

protected:
	/** Helper function that updates the object in imstk the WorldPos, or a location on the plane determined by a raycast from the WorlPos in the
	* direction of WorldDir if the PlaneActor is provided
	* @param WorldPos - New world position of the mouse cursor or if a PlaneActor is provided, the starting point of the ray
	* @param WorldDir - Direction of the raycast if relevant
	* @param PlaneActor* - Pointer to a DynamicalModel that contains the plane to raycast onto
	* @return FVector - The position of the object in imstk
	*/
	FVector UpdateImstkPosRot(FVector WorldPos, FQuat Orientation, FVector WorldDir = FVector::ZeroVector, UDynamicalModel* PlaneActor = nullptr);

	/** Helper function that moves the object to the location in the imstk scene
	* @return None
	*/
	void UpdateUnrealPosRot();

	/** Starts a vertex grasp if the tool is set to a grasping tool and a PbdObjectGrasping interaction are set on the controller
	* @return None
	*/
	UFUNCTION(BlueprintCallable, Category = "Imstk")
		void BeginVertexGrasp();

	/** Starts a cell grasp if the tool is set to a grasping tool and a PbdObjectGrasping interaction are set on the controller
	* @return None
	*/
	UFUNCTION(BlueprintCallable, Category = "Imstk")
		void BeginCellGrasp();

	/** Starts a ray point grasp from RayStart in the direction provided if the tool is set to a grasping tool and a PbdObjectGrasping interaction are set on the controller
	* @param RayStart Starting point of the ray
	* @param RayDir Direction of the ray to be cast
	* @return None
	*/
	UFUNCTION(BlueprintCallable, Category = "Imstk")
		void BeginRayPointGrasp(FVector RayStart, FVector RayDir);

	/** Ends the current grasp
	* @return None
	*/
	UFUNCTION(BlueprintCallable, Category = "Imstk")
		void EndGrasp();

	/** Creates a stitching interaction between the two vertices of the line mesh tool. Requires geometry to be set to a LineMeshTool.
	* @return None
	*/
	UFUNCTION(BlueprintCallable, Category = "Imstk")
		void BeginStitch();

	/** Applies the cut for each PbdObjectCutting interaction on the controller. Requires geometry to be set to a SurfaceMeshTool.
	* @return None
	*/
	UFUNCTION(BlueprintCallable, Category = "Imstk")
		void BeginCut();

	// Mass of the object in iMSTK
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "General")
		float Mass = 0.2;

	//TODO: set default values for these
	// Velocity damping of the tool's rigid body in iMSTK
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "General|Advanced")
		float VelocityDamping = 1.0;

	// Angular velocity damping of the tool's rigid body in iMSTK
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "General|Advanced")
		float AngularVelocityDamping = 1.0;

	// Maximum iterations of the tool's rigid body in iMSTK
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "General|Advanced")
		int MaxNumIterations = 8;

	// Maximum constraints of the tool's rigid body in iMSTK
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "General|Advanced")
		int MaxNumConstraints = 40;

	// Inertia tensor of the tool's rigid body in iMSTK
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (ClampMin = "0.01"), Category = "General|Advanced")
		float InertiaTensorMultiplier = 1.0;

	// Moves the tool using force rather than moving directly to the position given
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "General|Advanced")
		bool bForceTool = false;

	// Material of the ghost models 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (EditCondition = "bForceTool", EditConditionHides), Category = "General|Advanced")
		UMaterial* GhostMaterial;

	/** Sets the components used for the ghost object on force tools
	* @param SceneComponent - Pointer to the empty parent USceneComponent that holds the UStaticMeshComponents
	* @param StaticMeshComponents - Array of pointers to UStaticMeshComponents that represent the ghost model
	*/
	UFUNCTION(BlueprintCallable, Category = "Imstk")
		void SetGhostComponents(USceneComponent* SceneComponent, TArray<UStaticMeshComponent*> StaticMeshComponents);

	UPROPERTY(EditAnywhere, meta = (EditCondition = "bForceTool", EditConditionHides), BlueprintReadWrite, Category = "General|Advanced|ForceTool")
		bool bIgnoreAngularForce = true;

	// Spring force of the force applied to the tool
	UPROPERTY(EditAnywhere, meta = (EditCondition = "bForceTool && bIgnoreAngularForce", EditConditionHides), BlueprintReadWrite, Category = "General|Advanced|ForceTool")
		float SpringForce = 10000;

	// Spring damping of the force applied to the tool
	UPROPERTY(EditAnywhere, meta = (EditCondition = "bForceTool && bIgnoreAngularForce", EditConditionHides), BlueprintReadWrite, Category = "General|Advanced|ForceTool")
		float DamperForce = 100;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (EditCondition = "bForceTool && !bIgnoreAngularForce", EditConditionHides), Category = "General|Advanced|ForceTool")
		FVector LinearKs = FVector(8000000.0, 8000000.0, 8000000.0);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (EditCondition = "bForceTool && !bIgnoreAngularForce", EditConditionHides), Category = "General|Advanced|ForceTool")
		FVector AngularKs = FVector(10000.0, 10000.0, 10000.0);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (EditCondition = "bForceTool && !bIgnoreAngularForce", EditConditionHides), Category = "General|Advanced|ForceTool")
		double LinearKd = 10000.0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (EditCondition = "bForceTool && !bIgnoreAngularForce", EditConditionHides), Category = "General|Advanced|ForceTool")
		double AngularKd = 300.0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (EditCondition = "bForceTool && !bIgnoreAngularForce", EditConditionHides), Category = "General|Advanced|ForceTool")
		double ForceScale = 1;

	UFUNCTION(BlueprintCallable, Category = "Imstk")
		FVector GetControlleriMSTKPosition();

	//imstk::Vec3d SpringForce = imstk::Vec3d::Zero();
	//imstk::Vec3d DamperForce = imstk::Vec3d::Zero();

	imstk::Vec3d AngularSpringForce = imstk::Vec3d::Zero();
	imstk::Vec3d AngularDamperForce = imstk::Vec3d::Zero();

	// Prints the position of the object to the screen
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Debugging")
		bool bPrintImstkPos = false;

	// Pointer to the empty parent USceneComponent that holds the UStaticMeshComponents. This is what will be moved around the scene to preserve offsets on the UStaticMeshComponents
	UPROPERTY()
		USceneComponent* GhostSceneComp;

	// Array of pointers to UStaticMeshComponents that represent the ghost model
	UPROPERTY()
		TArray<UStaticMeshComponent*> GhostMeshes;

public:
	virtual void UnInit() override;

};
