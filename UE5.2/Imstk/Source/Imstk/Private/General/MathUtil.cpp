// Fill out your copyright notice in the Description page of Project Settings.

#include "MathUtil.h"

int UMathUtil::Scale = 100;

imstk::Vec3d UMathUtil::ToImstkVec3d(const FVector InputVec, const bool IsScaled)
{
	int Scaling = IsScaled ? Scale : 1;

	return imstk::Vec3d(InputVec.X / Scaling, InputVec.Z / Scaling, InputVec.Y / Scaling);
}

imstk::Vec3d UMathUtil::ToImstkVec3d(const FVector3f InputVec, const bool IsScaled)
{
	int Scaling = IsScaled ? Scale : 1;

	return imstk::Vec3d(InputVec.X / Scaling, InputVec.Z / Scaling, InputVec.Y / Scaling);
}

imstk::Vec3i UMathUtil::ToImstkVec3i(const FVector InputVec, const bool IsScaled)
{
	int Scaling = IsScaled ? Scale : 1;

	return imstk::Vec3i(InputVec.X / Scaling, InputVec.Z / Scaling, InputVec.Y / Scaling);
}

imstk::Vec3i UMathUtil::ToImstkVec3i(const FIntVector InputVec, const bool IsScaled)
{
	int Scaling = IsScaled ? Scale : 1;

	return imstk::Vec3i(InputVec.X / Scaling, InputVec.Z / Scaling, InputVec.Y / Scaling);
}

FVector UMathUtil::ToUnrealFVec(const imstk::Vec3i InputVec, const bool IsScaled)
{
	int Scaling = IsScaled ? Scale : 1;

	return FVector(InputVec.x() * Scaling, InputVec.z() * Scaling, InputVec.y() * Scaling);
}

FVector UMathUtil::ToUnrealFVec(const imstk::Vec3d InputVec, const bool IsScaled)
{
	int Scaling = IsScaled ? Scale : 1;

	return FVector(InputVec.x() * Scaling, InputVec.z() * Scaling, InputVec.y() * Scaling);
}

FVector UMathUtil::ToUnrealFVec(const imstk::Vec3f InputVec, const bool IsScaled)
{
	int Scaling = IsScaled ? Scale : 1;

	return FVector(InputVec.x() * Scaling, InputVec.z() * Scaling, InputVec.y() * Scaling);
}

imstk::Quatd UMathUtil::ToImstkQuat(const FQuat InputQuat)
{
	return imstk::Quatd(InputQuat.W, -InputQuat.X, -InputQuat.Z, -InputQuat.Y);
}

FQuat UMathUtil::ToUnrealFQuat(const imstk::Quatd InputQuat)
{
	return FQuat(-InputQuat.x(), -InputQuat.z(), -InputQuat.y(), InputQuat.w());
}


std::shared_ptr<imstk::VecDataArray<double, 3>> UMathUtil::ToImstkVecDataArray3d(const TArray<FVector> InputArray, const bool IsScaled)
{
	std::shared_ptr<imstk::VecDataArray<double, 3>> Output = std::make_shared<imstk::VecDataArray<double, 3>>();
	for (FVector Vector : InputArray) {
		Output->push_back(ToImstkVec3d(Vector, IsScaled));
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

TArray<int32> UMathUtil::ToUnrealIntArray(const std::shared_ptr<imstk::VecDataArray<int, 3>> InputArray)
{
	TArray<int32> Output;

	imstk::VecDataArray<int, 3>& Arr = *InputArray.get();
	for (int i = 0; i < Arr.size(); i++) {
		Output.Add(Arr[i][0]);
		Output.Add(Arr[i][1]);
		Output.Add(Arr[i][2]);
	}

	return Output;
}



TArray<FVector> UMathUtil::ToUnrealFVecArray(const std::shared_ptr<imstk::VecDataArray<double, 3>> InputArray, const bool IsScaled)
{
	TArray<FVector> Output;

	imstk::VecDataArray<double, 3>& Arr = *InputArray.get();

	for (int i = 0; i < Arr.size(); i++) {
		Output.Add(ToUnrealFVec(Arr[i], IsScaled));
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

void UMathUtil::SetScale(int InScale) 
{
	Scale = InScale;
}
int UMathUtil::GetScale()
{
	return Scale;
}