// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ImstkController.h"
#include "DynamicalModel.h"

#include "iMSTK-5.0/imstkPbdObject.h"

#include "CustomController.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Imstk), meta = (BlueprintSpawnableComponent))
class IMSTK_API UCustomController : public UImstkController
{
	GENERATED_BODY()

public:
	virtual void InitializeComponent() override;

	virtual void InitController() override;

	UFUNCTION(BlueprintCallable, Category = "Imstk")
		void MoveControllerToLocation(FVector Location,  FQuat Orientation, bool bUpdateUnrealPosRot = true);
	UFUNCTION(BlueprintCallable, Category = "Imstk")
		FVector MoveControllerToRaycastOnPlane(FVector RayStart, FVector RayDir, FQuat Orientation, UDynamicalModel* PlaneActor, bool bUpdateUnrealPosRot = true);

	std::shared_ptr<imstk::PbdObject> clothObj;
	std::shared_ptr<imstk::RigidObject2> cutObj;
protected:
	/** Helper function that updates the object in imstk with force towards the WorldPos, or a location on the plane determined by a raycast from WorlPos in the 
	* direction of WorldDir if the PlaneActor is provided
	* @param WorldPos - New world position of the mouse cursor or if a PlaneActor is provided, the starting point of the ray
	* @param WorldDir - Direction of the raycast
	* @param PlaneActor* - Pointer to a DynamicalModel that contains the plane to raycast onto
	* @return FVector - The position of the object in imstk
	*/
	FVector UpdateImstkPosRot(FVector WorldPos, FQuat Orientation, FVector WorldDir = FVector::ZeroVector, UDynamicalModel* PlaneActor = nullptr);

	/** Helper function that moves the object to the location in the imstk scene
	* @return None
	*/
	void UpdateUnrealPosRot();

	UFUNCTION(BlueprintCallable, Category = "Imstk")
		void BeginVertexGrasp();

	UFUNCTION(BlueprintCallable, Category = "Imstk")
		void BeginRayPointGrasp(FVector RayStart, FVector RayDir);

	UFUNCTION(BlueprintCallable, Category = "Imstk")
		void EndGrasp();

	UFUNCTION(BlueprintCallable, Category = "Imstk")
		void BeginStitch();

	UFUNCTION(BlueprintCallable, Category = "Imstk")
		void BeginCut();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ToolSettings")
		float Mass = 0.2;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ToolSettings")
		float VelocityDamping;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ToolSettings")
		float AngularVelocityDamping;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ToolSettings")
		int MaxNumIterations;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ToolSettings")
		int MaxNumConstraints;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ToolSettings")
		float InertiaTensorMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ToolSettings")
		float SpringForce;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ToolSettings")
		float SpringDamping;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Debugging")
		bool bPrintImstkPos = false;

public:
	virtual void UnInit() override;
	
};
