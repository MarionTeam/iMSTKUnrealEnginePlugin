// Fill out your copyright notice in the Description page of Project Settings.


#include "TetrahedralMeshAsset.h"
#include "iMSTK-5.0/imstkSurfaceMesh.h"
#include "MathUtil.h"

void UTetrahedralMeshAsset::SetTetrahedralMesh(std::shared_ptr<imstk::TetrahedralMesh> Input) {
	// Extract the values from imstk and and store in arrays
	Vertices = UMathUtil::ToUnrealFVecArray(Input->getVertexPositions());
	for (int i = 0; i < Input->getNumTetrahedra(); i++) {
			imstk::Vec4i TriangleIndices = Input->getTetrahedronIndices(i);
			Indices.Add(TriangleIndices.x());
			Indices.Add(TriangleIndices.y());
			Indices.Add(TriangleIndices.z());
			Indices.Add(TriangleIndices.w());
	}
	//Indices = UMathUtil::ToUnrealUIntArray(Input->getTetrahedraIndices());
}

std::shared_ptr<imstk::TetrahedralMesh> UTetrahedralMeshAsset::GetTetrahedralMesh() {
	// Convert the stored values back into an imstk tetrahedral mesh
	std::shared_ptr<imstk::TetrahedralMesh> Output = std::make_shared<imstk::TetrahedralMesh>();
	Output->initialize(UMathUtil::ToImstkVecDataArray3d(Vertices), UMathUtil::ToImstkVecDataArray4i(Indices));
	return Output;
}