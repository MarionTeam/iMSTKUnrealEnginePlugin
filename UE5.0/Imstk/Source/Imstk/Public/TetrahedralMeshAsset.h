// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "iMSTK-5.0/imstkTetrahedralMesh.h"
#include "TetrahedralMeshAsset.generated.h"

/** \file TetrahedralMeshAsset.h
 *  \brief Stores the vertices and indices of a tetrahedral mesh and outputs an imstk tetrahedral mesh
 *  \details 
 */
UCLASS()
class IMSTK_API UTetrahedralMeshAsset : public UObject
{
	GENERATED_BODY()

public:
	/** Converts the arrays from imstk to Unreal for Vertices and Indices of the tetrahedral mesh for serialization within the asset
	* @return None
	*/
	void SetTetrahedralMesh(std::shared_ptr<imstk::TetrahedralMesh> Input);

	/** Converts the stored Unreal arrays and generates and returns an imstk tetrahedral mesh
	* @return None
	*/
	std::shared_ptr<imstk::TetrahedralMesh> GetTetrahedralMesh();
	//protected:
	UPROPERTY(EditAnywhere, Category = "General")
		TArray<FVector> Vertices;
	UPROPERTY(EditAnywhere, Category = "General")
		TArray<uint32> Indices;
	// TODO: Maybe try to cache a mesh and return that instead of creating on each run (would only matter for the editor)
	//std::shared_ptr<imstk::TetrahedralMesh> TetMesh;
};
