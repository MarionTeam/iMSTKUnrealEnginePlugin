// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "imstkImageData.h"
#include "ImageDataAsset.generated.h"

/** \file ImageDataAsset.h
 *  \brief Stores the information required to generate ImageData
 *  \details
 */
UCLASS()
class IMSTK_API UImageDataAsset : public UObject
{
	GENERATED_BODY()

public:
	/** Converts the ImageData from iMSTK and stores them in Unreal
	* @param Input The tetrahedral mesh to extract info from
	* @return None
	*/
	void SetImageData(std::shared_ptr<imstk::ImageData> Input);

	/** Generates ImageData from the stored values and returns it
	* @return The generated iMSTK ImageData
	*/
	std::shared_ptr<imstk::ImageData> GetImageData();

	// Spacing of the image data
	UPROPERTY(EditAnywhere, Category = "iMSTK")
		FVector Spacing;

	// Origin of the image data
	UPROPERTY(EditAnywhere, Category = "iMSTK")
		FVector Origin;

	// Dimensions of the image data
	UPROPERTY(EditAnywhere, Category = "iMSTK")
		FVector Dimensions;

	// Scalars of the image data
	UPROPERTY(EditAnywhere, Category = "iMSTK")
		TArray<double> Scalars;

	// Number of image components of the image data
	UPROPERTY(EditAnywhere, Category = "iMSTK")
		int ImageComponents;

	
};
