// Fill out your copyright notice in the Description page of Project Settings.


#include "TetrahedralMeshAsset.h"
#include "imstkSurfaceMesh.h"
#include "MathUtil.h"

void UTetrahedralMeshAsset::SetTetrahedralMesh(std::shared_ptr<imstk::TetrahedralMesh> Input) {
	// TODO: make sure this inputs the mesh correctly
	// Extract the values from imstk and and store in arrays
	//Vertices = UMathUtil::ToUnrealFVecArray(Input->getVertexPositions(), false);
	
	// Store tet mesh without flipped y and z to maintain surface mesh orientation (since it is flipped on return) and have tet mesh line up in imstk
	std::shared_ptr<imstk::VecDataArray<double, 3>> CurVerts = Input->getVertexPositions();

	for (int i = 0; i < Input->getNumVertices(); i++) {
		imstk::Vec3d Vector = Input->getVertexPosition(i);
		Vertices.Add(FVector(Vector.x(), Vector.z(), Vector.y()));
	}
	
	Indices = UMathUtil::ToUnrealUIntArray(Input->getTetrahedraIndices());

	/*imstk::VecDataArray<int, 4> TetIndices = *Input->getTetrahedraIndices();
	for (int i = 0; i < Input->getNumTetrahedra(); i++) {
		imstk::Vec4i Tetrahedra = TetIndices[i];
		Indices.Add(Tetrahedra[0]);
		Indices.Add(Tetrahedra[1]);
		Indices.Add(Tetrahedra[3]);
		Indices.Add(Tetrahedra[2]);
	}*/

}

std::shared_ptr<imstk::TetrahedralMesh> UTetrahedralMeshAsset::GetTetrahedralMesh() {
	// Convert the stored values back into an imstk tetrahedral mesh
	std::shared_ptr<imstk::TetrahedralMesh> Output = std::make_shared<imstk::TetrahedralMesh>();
	Output->initialize(UMathUtil::ToImstkVecDataArray3d(Vertices, true), UMathUtil::ToImstkVecDataArray4i(Indices));
	return Output;
}