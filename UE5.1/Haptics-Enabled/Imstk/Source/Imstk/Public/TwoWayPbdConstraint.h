// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ImstkConstraint.h"
#include "PBDThread.h"
#include "Suturing/NeedleObject.h"
#include "TwoWayPbdConstraint.generated.h"

/** \file TwoWayPbdConstraint.h
 *  \brief Creates a two way constraint between a PBDThread (line mesh) and a needle object
 *  \details Allows the needle to be pulled by the thread in the constraint
 */
UCLASS(BlueprintType)
class IMSTK_API UTwoWayPbdConstraint : public UImstkConstraint
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "iMSTK|Constraint")
		virtual void Init() override;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "iMSTK")
		UPBDThread* Thread;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "iMSTK")
		UNeedleObject* NeedleObj;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "iMSTK")
		double RestLength;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "iMSTK")
		double Compliance = 0.0000001;
};
