// Fill out your copyright notice in the Description page of Project Settings.


#include "TetrahedralMeshAsset.h"
#include "MathUtil.h"

void UTetrahedralMeshAsset::SetTetrahedralMesh(std::shared_ptr<imstk::TetrahedralMesh> Input) {
	// Extract the values from imstk and and store in arrays
	Vertices = UMathUtil::ToUnrealFVecArray(Input->getVertexPositions());
	Indices = UMathUtil::ToUnrealUIntArray(Input->getTetrahedraIndices());
}

std::shared_ptr<imstk::TetrahedralMesh> UTetrahedralMeshAsset::GetTetrahedralMesh() {
	// Convert the stored values back into an imstk tetrahedral mesh
	std::shared_ptr<imstk::TetrahedralMesh> Output = std::make_shared<imstk::TetrahedralMesh>();
	Output->initialize(UMathUtil::ToImstkVecDataArray3d(Vertices), UMathUtil::ToImstkVecDataArray4i(Indices));
	return Output;
}