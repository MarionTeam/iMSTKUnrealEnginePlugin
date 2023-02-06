// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ImstkConstraint.generated.h"

/** \file ImstkConstraint.h
 *  \brief Abstract class for constraints in iMSTK
 *  \details
 */
UCLASS(Abstract, BlueprintType)
class IMSTK_API UImstkConstraint : public UObject
{
	GENERATED_BODY()
	
public:
	/** 
	* @return None
	*/
	virtual void Init() {};
};
