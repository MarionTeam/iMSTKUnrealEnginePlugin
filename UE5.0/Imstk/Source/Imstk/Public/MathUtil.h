// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "iMSTK-5.0/imstkMath.h"
#include "iMSTK-5.0/imstkVecDataArray.h"
#include "MathUtil.generated.h"

/** \file MathUtil.h
 *  \brief Provides static functions that convert between Imstk and Unreal structures
 *  \details Converts Vectors, Quaternions...
 */
UCLASS()
class IMSTK_API UMathUtil : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	/** Converts Unreal FVector to Imstk Vec3d
	* @return imstk::Vec3d
	*/
	static imstk::Vec3d ToImstkVec3(const FVector InputVec);

	/** Converts Imstk Vec3d to Unreal FVector
	* @return FVector
	*/
	static FVector ToUnrealFVec(const imstk::Vec3d InputVec);

	/** Converts Unreal FQuat to Imstk Quatd
	* @return imstk::Quatd
	*/
	static imstk::Quatd ToImstkQuat(const FQuat InputQuat);

	/** Converts Imstk Quatd to Unreal FQuat
	* @return FQuat
	*/
	static FQuat ToUnrealFQuat(const imstk::Quatd InputQuat);

	/** Converts a TArray of FVectors from Unreal to a VecDataArray using 3 doubles
	* @return std::shared_ptr<imstk::VecDataArray<double, 3>>
	*/
	static std::shared_ptr<imstk::VecDataArray<double, 3>> ToImstkVecDataArray3d(const TArray<FVector> InputArray);

	/** Converts a TArray of integers from Unreal to a VecDataArray using 3 integers
	* @return std::shared_ptr<imstk::VecDataArray<int, 3>>
	*/
	static std::shared_ptr<imstk::VecDataArray<int, 3>> ToImstkVecDataArray3i(const TArray<int> InputArray);

	/** Converts a TArray of uint32 from Unreal to a VecDataArray using 4 integers
	* @return std::shared_ptr<imstk::VecDataArray<int, 4>>
	*/
	static std::shared_ptr<imstk::VecDataArray<int, 4>> ToImstkVecDataArray4i(const TArray<uint32> InputArray);

	/** Converts an imstk VecDataArray of 3 integers into a TArray of uint32
	* @return TArray<uint32>
	*/
	static TArray<uint32> ToUnrealUIntArray(const std::shared_ptr<imstk::VecDataArray<int, 3>> InputArray);

	/** Converts an imstk VecDataArray of 4 integers into a TArray of uint32
	* @return TArray<uint32>
	*/
	static TArray<uint32> ToUnrealUIntArray(const std::shared_ptr<imstk::VecDataArray<int, 4>> InputArray);

	/** Converts an imstk VecDataArray of 3 doubles into a TArray of FVectors
	* @return TArray<FVector>
	*/
	static TArray<FVector> ToUnrealFVecArray(const std::shared_ptr <imstk::VecDataArray<double, 3>> InputArray);

	/** Converts an imstk VecDataArray of 3 integers into a TArray FVector2Ds
	* @return TArray<uint32>
	*/
	static TArray<FVector2D> ToUnrealFVecArray2D(const std::shared_ptr <imstk::VecDataArray<double, 3>> InputArray);

	/** Not fully implemented!!!
	* @return imstk::Mat4d
	*/
	static imstk::Mat4d ToImstkMat4d(const FMatrix Input);
};




