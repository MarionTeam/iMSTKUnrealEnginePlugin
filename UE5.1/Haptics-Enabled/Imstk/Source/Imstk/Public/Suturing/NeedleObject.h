// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PbdModel.h"
#include "imstkPbdObject.h"

#include "NeedleObject.generated.h"

/** \file NeedleObject.h
 *  \brief Attach to a blank actor to create a needle 
 *  \details
 */
UCLASS(ClassGroup = (Imstk), meta = (BlueprintSpawnableComponent))
class IMSTK_API UNeedleObject : public UPBDModel
{
	GENERATED_BODY()

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void InitializeComponent() override;

	/** Initializes the object that is defined in editor through the geometry filter
	* @return None
	*/
	virtual void Init() override;

	/** Returns a vertex's position on the line mesh of the needle
	* @param Vert Integer for the vertex position to be returned
	* @return FVector containing the position of the input vertex in unreal space
	*/
	UFUNCTION(BlueprintCallable, Category = "iMSTK|Needle")
		FVector GetVertexPosition(int Vert = 0);

protected:
	// Object is created during Init and used in Imstk simulation
	std::shared_ptr<imstk::PbdObject> Needle;

	UPROPERTY()
		UProceduralMeshComponent* ProcMeshComp;

public:
	virtual void UnInit() override;
};
