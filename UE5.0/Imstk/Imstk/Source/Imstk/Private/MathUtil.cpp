// Fill out your copyright notice in the Description page of Project Settings.


#include "MathUtil.h"


imstk::Vec3d UMathUtil::ToImstkVec3(const FVector InputVec)
{
	return imstk::Vec3d(InputVec.X, InputVec.Y, InputVec.Z);
}

FVector UMathUtil::ToUnrealFVec(const imstk::Vec3d InputVec)
{
	return FVector(InputVec.x(), InputVec.y(), InputVec.z());
}

imstk::Quatd UMathUtil::ToImstkQuat(const FQuat InputQuat)
{
	return imstk::Quatd(InputQuat.W, InputQuat.X, InputQuat.Y, InputQuat.Z);
}

FQuat UMathUtil::ToUnrealFQuat(const imstk::Quatd InputQuat)
{
	return FQuat(InputQuat.x(), InputQuat.y(), InputQuat.z(), InputQuat.w());
}

// TODO: Add errors if arrays are not divisible by 3
std::shared_ptr<imstk::VecDataArray<double, 3>> UMathUtil::ToImstkVecDataArray3d(const TArray<FVector> InputArray)
{
	std::shared_ptr<imstk::VecDataArray<double, 3>> Output = std::make_shared<imstk::VecDataArray<double, 3>>();
	for (FVector Vector : InputArray) {
		Output->push_back(ToImstkVec3(Vector));
	}
	return Output;
}

std::shared_ptr<imstk::VecDataArray<int, 3>> UMathUtil::ToImstkVecDataArray3i(const TArray<int> InputArray)
{
	if (InputArray.Num() % 3 != 0) {
		UE_LOG(LogTemp, Error, TEXT("Input array is not a multiple of 3"));
		return nullptr;
	}

	std::shared_ptr<imstk::VecDataArray<int, 3>> Output = std::make_shared<imstk::VecDataArray<int, 3>>();
	for (int i = 0; i < InputArray.Num(); i += 3) {
		Output->push_back(imstk::Vec3i(InputArray[i], InputArray[i + 1], InputArray[i + 2]));
	}
	return Output;
}

std::shared_ptr<imstk::VecDataArray<int, 4>> UMathUtil::ToImstkVecDataArray4i(const TArray<uint32> InputArray)
{
	if (InputArray.Num() % 4 != 0) {
		UE_LOG(LogTemp, Error, TEXT("Input array is not a multiple of 4"));
		return nullptr;
	}

	std::shared_ptr<imstk::VecDataArray<int, 4>> Output = std::make_shared<imstk::VecDataArray<int, 4>>();
	for (int i = 0; i < InputArray.Num(); i += 4) {
		Output->push_back(imstk::Vec4i(InputArray[i], InputArray[i + 1], InputArray[i + 2], InputArray[i + 3]));
	}
	return Output;
}

TArray<uint32> UMathUtil::ToUnrealUIntArray(const std::shared_ptr<imstk::VecDataArray<int, 3>> InputArray)
{
	TArray<uint32> Output;

	imstk::VecDataArray<int, 3>& Arr = *InputArray.get();
	for (int i = 0; i < Arr.size(); i++) {
		Output.Add(Arr[i][0]);
		Output.Add(Arr[i][1]);
		Output.Add(Arr[i][2]);
	}

	return Output;
}
TArray<uint32> UMathUtil::ToUnrealUIntArray(const std::shared_ptr<imstk::VecDataArray<int, 4>> InputArray)
{
	TArray<uint32> Output;

	imstk::VecDataArray<int, 4>& Arr = *InputArray.get();
	for (int i = 0; i < Arr.size(); i++) {
		Output.Add(Arr[i][0]);
		Output.Add(Arr[i][1]);
		Output.Add(Arr[i][2]);
		Output.Add(Arr[i][3]);
	}

	return Output;
}



TArray<FVector> UMathUtil::ToUnrealFVecArray(const std::shared_ptr<imstk::VecDataArray<double, 3>> InputArray)
{
	TArray<FVector> Output;

	imstk::VecDataArray<double, 3>& Arr = *InputArray.get();

	for (int i = 0; i < Arr.size(); i++) {
		Output.Add(ToUnrealFVec(Arr[i]));
	}


	return Output;
}

TArray<FVector2D> UMathUtil::ToUnrealFVecArray2D(const std::shared_ptr<imstk::VecDataArray<double, 3>> InputArray)
{
	TArray<FVector2D> Output;

	imstk::VecDataArray<double, 3>& Arr = *InputArray.get();

	for (int i = 0; i < Arr.size(); i++) {
		Output.Add(FVector2D(Arr[i].x(), Arr[i].y()));
	}

	return Output;
}

imstk::Mat4d UMathUtil::ToImstkMat4d(const FMatrix Input)
{
	imstk::Mat4d Output = imstk::Mat4d();

	for (int c = 0; c < 4; c++) {
		FVector Col = Input.GetColumn(c);
		for (int r = 0; r < 4; r++) {
			Output(r, c) = Col[r];
		}
	}

	return Output;
}