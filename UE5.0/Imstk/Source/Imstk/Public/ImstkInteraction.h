// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ImstkInteraction.generated.h"

/** \file ImstkInteraction.h
 *  \brief Abstract class for Imstk interactions
 *  \details Provides a function for initializing the interaction. Can be overridden in child classes to create the interaction in imstk
 */
UCLASS(Abstract)
class IMSTK_API UImstkInteraction : public UObject
{
	GENERATED_BODY()
public:
	/** Initialize interaction in imstk and add to the scene in the imstk subsystem
	* @return None
	*/
	virtual void Init();

	virtual void UnInit();
};
