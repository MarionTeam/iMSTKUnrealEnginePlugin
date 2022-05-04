// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ImstkController.h"
#include "DynamicalModel.h"
#include "ImstkMouseController.generated.h"


/** \file ImstkMouseController.h
 *  \brief Component to attach to objects that can be controlled using the mouse
 *  \details Currently very basic and will only generate a line mesh of a specific size. Primarily used for testing purposes.
 */
UCLASS(ClassGroup = (Imstk), meta = (BlueprintSpawnableComponent))
class IMSTK_API UImstkMouseController : public UImstkController
{
	GENERATED_BODY()

public:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	virtual void InitializeComponent() override;

	virtual void InitController() override;
protected:
	/** Helper function that updates the object in imstk with force from the mouse
	* @param WorldPos - New world position of the mouse cursor
	* @return None
	*/
	void UpdateImstkPos(FVector WorldPos, FVector WorldDir);

	/** Helper function that moves the object to the location in the imstk scene
	* @return None
	*/
	void UpdateUnrealPos();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (EditCondition = "bGraspingTool", EditConditionHides), Category = "General")
		bool bRayToPlane = false;
	UPROPERTY(EditAnywhere, meta = (EditCondition = "bRayToPlane", EditConditionHides), Category = "General")
		AActor* PlaneModel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "General")
		float Offset = 200;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "General")
		float Mass = 0.2;

	// TODO: Rename begin grasp
	UFUNCTION(BlueprintCallable, Category = "Imstk")
		void BeginVertexGrasp();

	UFUNCTION(BlueprintCallable, Category = "Imstk")
		void EndVertexGrasp();	

	UFUNCTION(BlueprintCallable, Category = "Imstk")
		void BeginStitch();
	
public:
	virtual void UnInit() override;
};
