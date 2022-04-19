// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ImstkController.h"
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
	void UpdateImstkForce(FVector WorldPos);

	/** Helper function that moves the object to the location in the imstk scene
	* @return None
	*/
	void UpdateUnrealPos();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "General")
		float Offset = 200;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "General")
		float Mass = 0.2;

public:
	virtual void UnInit() override;
};
