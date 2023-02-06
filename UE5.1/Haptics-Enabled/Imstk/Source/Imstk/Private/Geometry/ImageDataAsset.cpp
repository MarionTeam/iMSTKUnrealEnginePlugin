// Fill out your copyright notice in the Description page of Project Settings.


#include "ImageDataAsset.h"
#include "MathUtil.h"

void UImageDataAsset::SetImageData(std::shared_ptr<imstk::ImageData> Input)
{
	Spacing = UMathUtil::ToUnrealFVec(Input->getSpacing(), false);

	Origin = UMathUtil::ToUnrealFVec(Input->getOrigin(), false);

	Dimensions = UMathUtil::ToUnrealFVec(Input->getDimensions(), false);

	ImageComponents = Input->getNumComponents();
	imstk::DataArray<double> ImstkScalars = *std::dynamic_pointer_cast<imstk::DataArray<double>>(Input->getScalars()->cast(IMSTK_DOUBLE)).get();

	for (int i = 0; i < ImstkScalars.size(); i++) {
		Scalars.Add(ImstkScalars[i]);
	}
}

std::shared_ptr<imstk::ImageData> UImageDataAsset::GetImageData() {

	std::shared_ptr<imstk::ImageData> Output = std::make_shared<imstk::ImageData>();
	Output->setSpacing(UMathUtil::ToImstkVec3d(Spacing, false));
	Output->setOrigin(UMathUtil::ToImstkVec3d(Origin, false));

	std::shared_ptr<imstk::DataArray<double>> ImstkScalars = std::make_shared<imstk::DataArray<double>>();
	for (double Val : Scalars) {
		ImstkScalars->push_back(Val);
	}

	Output->setScalars(ImstkScalars, ImageComponents, UMathUtil::ToImstkVec3i(Dimensions, false).data());

	return Output;
}