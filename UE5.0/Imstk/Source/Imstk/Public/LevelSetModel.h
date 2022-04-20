// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DynamicalModel.h"
#include "ProceduralMeshComponent.h"
#include "iMSTK-5.0/imstkLevelSetDeformableObject.h"
#include "LevelSetModel.generated.h"

/**
 * 
 */
//UCLASS(ClassGroup = (Imstk), meta = (BlueprintSpawnableComponent))
UCLASS()
class IMSTK_API ULevelSetModel : public UDynamicalModel
{
	GENERATED_BODY()
	
public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void InitializeComponent() override;

	/** Initializes the rigid object that is defined in editor through the geometry filter
	* @return None
	*/
	virtual void Init() override;

protected:
	UPROPERTY()
		UProceduralMeshComponent* MeshComp;

	void UpdateModel();

	std::shared_ptr<imstk::LevelSetDeformableObject> LevelsetObj;
};
