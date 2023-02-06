// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ImstkInteraction.h"
#include "ImstkController.h"
#include "PortHoleInteraction.generated.h"

/** \file PortHoleInteraction.h
 *  \brief Interaction for restricting object movement around a port hole
 *  \details
 */
UCLASS(BlueprintType)
class IMSTK_API UPortHoleInteraction : public UImstkInteraction
{
	GENERATED_BODY()

public:
	/** Initializes the interaction within iMSTK between the set models set on the PortHoleInteraction
	* @return None
	*/
	UFUNCTION(BlueprintCallable, Category = "iMSTK|Interaction")
		virtual void Init() override;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "iMSTK|Port Hole Interaction")
		UImstkController* Controller;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "iMSTK|Port Hole Interaction")
		AActor* PortHoleActor;
	
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "iMSTK|Port Hole Interaction")
		float Compliance = 0.000001;
};
