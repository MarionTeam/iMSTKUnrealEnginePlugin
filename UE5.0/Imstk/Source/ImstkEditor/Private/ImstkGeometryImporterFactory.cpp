// Fill out your copyright notice in the Description page of Project Settings.


#include "ImstkGeometryImporterFactory.h"
#include "TetrahedralMeshAsset.h"
#include "RawMesh.h"
#include "MathUtil.h"
#include "MeshDescription.h"
#include "AssetRegistry/AssetRegistryModule.h"
#include "iMSTK-5.0/imstkMeshIO.h"
#include "iMSTK-5.0/imstkTetrahedralMesh.h"
#include "iMSTK-5.0/imstkSurfaceMesh.h"

UImstkGeometryImporterFactory::UImstkGeometryImporterFactory(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	Formats.Add(FString(TEXT("vtk;")) + NSLOCTEXT("UImstkGeometryImporterFactory", "FormatVtk", "Vtk File").ToString());
	Formats.Add(FString(TEXT("vtu;")) + NSLOCTEXT("UImstkGeometryImporterFactory", "FormatVtu", "Vtu File").ToString());
	Formats.Add(FString(TEXT("vtp;")) + NSLOCTEXT("UImstkGeometryImporterFactory", "FormatVtp", "Vtp File").ToString());
	Formats.Add(FString(TEXT("stl;")) + NSLOCTEXT("UImstkGeometryImporterFactory", "FormatStl", "Stl File").ToString());
	Formats.Add(FString(TEXT("ply;")) + NSLOCTEXT("UImstkGeometryImporterFactory", "FormatPly", "Ply File").ToString());
	Formats.Add(FString(TEXT("veg;")) + NSLOCTEXT("UImstkGeometryImporterFactory", "FormatVeg", "Veg File").ToString());
	SupportedClass = UTetrahedralMeshAsset::StaticClass();
	bCreateNew = false;
	bEditorImport = true;
}

//TODO: Maybe make a menu pop up to decide some of the choices here (such as smoothing masks etc)
UObject* UImstkGeometryImporterFactory::FactoryCreateFile(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, const FString& Filename, const TCHAR* Parms, FFeedbackContext* Warn, bool& bOutOperationCanceled)
{
	//UE_LOG(LogTemp, Log, TEXT("%s %s"), *Filename, *InParent->GetName());
	UTetrahedralMeshAsset* TetMeshAsset = nullptr;

	// Import file into imstk first to extract data
	std::shared_ptr<imstk::PointSet> ImportedPointSet = imstk::MeshIO::read<imstk::PointSet>(std::string(TCHAR_TO_UTF8(*Filename)));
	std::shared_ptr<imstk::SurfaceMesh> SurfaceMesh;

	if (ImportedPointSet->getTypeName() == "TetrahedralMesh") {

		// Create TetrahedralMeshAsset
		std::shared_ptr<imstk::TetrahedralMesh> TetMesh = std::dynamic_pointer_cast<imstk::TetrahedralMesh>(ImportedPointSet);

		TetMeshAsset = NewObject<UTetrahedralMeshAsset>(InParent, InClass, InName, Flags);

		if (TetMeshAsset)
			TetMeshAsset->SetTetrahedralMesh(TetMesh);
		SurfaceMesh = TetMesh->extractSurfaceMesh();
	}
	else if (ImportedPointSet->getTypeName() == "SurfaceMesh")
	{
		SurfaceMesh = std::dynamic_pointer_cast<imstk::SurfaceMesh>(ImportedPointSet);
	}
	else
	{
		// TODO: Unity has stuff for Line mesh as well but not sure if that can be done because all meshes are triangle based
		return nullptr;
	}

	FString Str = InName.ToString();
	Str.Append("_SurfaceMesh");
	FName NewName = FName(*Str);

	FString Path;
	FString File;
	FString Extension;
	FPaths::Split(InParent->GetName(), Path, File, Extension);
	FString PackagePath = Path + "/" + NewName.ToString();
	//UE_LOG(LogTemp, Log, TEXT("%s"), *PackagePath);

	// Create static mesh based on the imported values
	UPackage* Package = CreatePackage(*PackagePath);

	UStaticMesh* StaticMesh = NewObject<UStaticMesh>(Package, NewName, RF_Public | RF_Standalone);
	if (StaticMesh) {
		FRawMesh RawMesh;

		TArray<UMaterialInterface*> MeshMaterials;
		MeshMaterials.Add(UMaterial::GetDefaultMaterial(MD_Surface));


		// TEST MESH FOR A BASIC TRIANGLE
		/*RawMesh.VertexPositions.Add(FVector(0, 0, 0));
		RawMesh.VertexPositions.Add(FVector(1, 0, 0));
		RawMesh.VertexPositions.Add(FVector(1, 1, 0));

		RawMesh.WedgeIndices.Add(0);
		RawMesh.WedgeIndices.Add(1);
		RawMesh.WedgeIndices.Add(2);

		RawMesh.WedgeTexCoords->Add(FVector2D(0, 0));
		RawMesh.WedgeTexCoords->Add(FVector2D(0, 0));
		RawMesh.WedgeTexCoords->Add(FVector2D(0, 0));
		RawMesh.FaceMaterialIndices.Add(0);
		RawMesh.FaceSmoothingMasks.Add(0);
		RawMesh.WedgeTangentX.Add(FVector(0, 0, 0));
		RawMesh.WedgeTangentX.Add(FVector(0, 0, 0));
		RawMesh.WedgeTangentX.Add(FVector(0, 0, 0));
		RawMesh.WedgeTangentY.Add(FVector(0, 0, 0));
		RawMesh.WedgeTangentY.Add(FVector(0, 0, 0));
		RawMesh.WedgeTangentY.Add(FVector(0, 0, 0));
		RawMesh.WedgeTangentZ.Add(FVector(0, 0, 0));
		RawMesh.WedgeTangentZ.Add(FVector(0, 0, 0));
		RawMesh.WedgeTangentZ.Add(FVector(0, 0, 0));*/

		imstk::VecDataArray<double, 3>& Vertices = *SurfaceMesh->getVertexPositions();
		for (int i = 0; i < Vertices.size(); i++) {
			RawMesh.VertexPositions.Add(FVector3f(UMathUtil::ToUnrealFVec(Vertices[i])));
		}

		imstk::VecDataArray<int, 3>& Indices = *SurfaceMesh->getTriangleIndices();
		//UE_LOG(LogTemp, Log, TEXT("Is indices null: %s"), (SurfaceMesh->getTriangleIndices() == nullptr ? TEXT("true") : TEXT("false")));
		SurfaceMesh->flipNormals();
		//imstk::VecDataArray<double, 3>& Tangents = *SurfaceMesh->getCellTangents().get();
		//UE_LOG(LogTemp, Warning, TEXT("Tangents: %s"), (SurfaceMesh->getCellTangents() == nullptr ? TEXT("true") : TEXT("false")));

		// TODO: THIS IS UNTESTED (not sure which of the files contain texture information)
		std::shared_ptr<imstk::VecDataArray<float, 2>> ImstkTCoordsPtr = SurfaceMesh->getVertexTCoords();

		imstk::VecDataArray<float, 2>& ImstkTCoords = *ImstkTCoordsPtr;
		if (ImstkTCoordsPtr) {
			for (int i = 0; i < ImstkTCoords.size(); i++) {
				RawMesh.WedgeTexCoords->Add(FVector2f(ImstkTCoords[i][0], ImstkTCoords[i][1]));
			}
		}


		for (int i = 0; i < Indices.size(); i++) {
			RawMesh.WedgeIndices.Add(Indices[i][0]);
			RawMesh.WedgeIndices.Add(Indices[i][1]);
			RawMesh.WedgeIndices.Add(Indices[i][2]);

			RawMesh.WedgeTangentX.Add(FVector3f::ZeroVector);
			RawMesh.WedgeTangentX.Add(FVector3f::ZeroVector);
			RawMesh.WedgeTangentX.Add(FVector3f::ZeroVector);

			RawMesh.WedgeTangentY.Add(FVector3f::ZeroVector);
			RawMesh.WedgeTangentY.Add(FVector3f::ZeroVector);
			RawMesh.WedgeTangentY.Add(FVector3f::ZeroVector);

			RawMesh.WedgeTangentZ.Add(FVector3f::ZeroVector);
			RawMesh.WedgeTangentZ.Add(FVector3f::ZeroVector);
			RawMesh.WedgeTangentZ.Add(FVector3f::ZeroVector);

			if (!ImstkTCoordsPtr) {
				RawMesh.WedgeTexCoords->Add(FVector2f(0, 0));
				RawMesh.WedgeTexCoords->Add(FVector2f(0, 0));
				RawMesh.WedgeTexCoords->Add(FVector2f(0, 0));
			}

			RawMesh.FaceMaterialIndices.Add(0);
			RawMesh.FaceSmoothingMasks.Add(0xFFFFFFFF);
			// For no smoothing of faces
			//RawMesh.FaceSmoothingMasks.Add(0);
		}

		StaticMesh->PreEditChange(nullptr);
		FStaticMeshSourceModel& SourceModel = StaticMesh->AddSourceModel();
		SourceModel.SaveRawMesh(RawMesh);
		/*
		for (UMaterialInterface* Material : MeshMaterials)
		{
			StaticMesh->StaticMaterials.Add(FStaticMaterial(Material));
		}
		*/

		// Model Configuration
		SourceModel.BuildSettings.bRecomputeNormals = true;
		SourceModel.BuildSettings.bRecomputeTangents = true;
		SourceModel.BuildSettings.bUseMikkTSpace = false;
		SourceModel.BuildSettings.bGenerateLightmapUVs = true;
		//SourceModel.BuildSettings.bBuildAdjacencyBuffer = false;
		SourceModel.BuildSettings.bBuildReversedIndexBuffer = false;
		SourceModel.BuildSettings.bUseFullPrecisionUVs = false;
		SourceModel.BuildSettings.bUseHighPrecisionTangentBasis = false;


		//UE_LOG(LogTemp, Log, TEXT("Is RawMesh valid: %s"), (RawMesh.IsValid() ? TEXT("true") : TEXT("false")));

		// Processing the StaticMesh
		//StaticMesh->ImportVersion = EImportStaticMeshVersion::LastVersion;
		//StaticMesh->CreateBodySetup();
		//StaticMesh->SetLightingGuid();
		// 
		TArray<FText> BuildErrors;
		StaticMesh->Build(true, &BuildErrors);
		//StaticMesh->PostEditChange();

		FAssetRegistryModule::AssetCreated(StaticMesh);
		Package->MarkPackageDirty();
	}



	bOutOperationCanceled = false;
	if (ImportedPointSet->getTypeName() == "TetrahedralMesh") 
	{
		return TetMeshAsset;
	}
	else 
	{
		return StaticMesh;
	}
}
