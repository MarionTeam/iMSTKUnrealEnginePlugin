// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DynamicalModel.h"
#include "StaticModel.generated.h"

/** \file StaticModel.h
 *  \brief Components for static models in imstk
 *  \details Attach to models in Unreal to initialize them in imstk 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class IMSTK_API UStaticModel : public UDynamicalModel
{
	GENERATED_BODY()

public:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void InitializeComponent() override;

	/** Initializes the static colliding object in imstk and adds it to the scene
	* @return None
	*/
	virtual void Init() override;
};
