// Fill out your copyright notice in the Description page of Project Settings.


#include "TetrahedralMeshImporterFactory.h"
#include "TetrahedralMeshAsset.h"
#include "RawMesh.h"
#include "MathUtil.h"
#include "MeshDescription.h"
#include "AssetRegistry/AssetRegistryModule.h"
#include "imstkMeshIO.h"
#include "imstkTetrahedralMesh.h"
#include "imstkSurfaceMesh.h"

UTetrahedralMeshImporterFactory::UTetrahedralMeshImporterFactory(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	Formats.Add(FString(TEXT("vtk;")) + NSLOCTEXT("UImstkGeometryImporterFactory", "FormatVtk", "Vtk File").ToString());
	Formats.Add(FString(TEXT("vtu;")) + NSLOCTEXT("UImstkGeometryImporterFactory", "FormatVtu", "Vtu File").ToString());
	Formats.Add(FString(TEXT("vtp;")) + NSLOCTEXT("UImstkGeometryImporterFactory", "FormatVtp", "Vtp File").ToString());
	Formats.Add(FString(TEXT("stl;")) + NSLOCTEXT("UImstkGeometryImporterFactory", "FormatStl", "Stl File").ToString());
	Formats.Add(FString(TEXT("ply;")) + NSLOCTEXT("UImstkGeometryImporterFactory", "FormatPly", "Ply File").ToString());
	Formats.Add(FString(TEXT("veg;")) + NSLOCTEXT("UImstkGeometryImporterFactory", "FormatVeg", "Veg File").ToString());
	Formats.Add(FString(TEXT("msh;")) + NSLOCTEXT("UImstkGeometryImporterFactory", "FormatVeg", "Msh File").ToString());

	SupportedClass = UTetrahedralMeshAsset::StaticClass();
	
	bCreateNew = false;
	bEditorImport = true;
}

//TODO: Maybe make a menu pop up to decide some of the choices here (such as smoothing masks etc)
UObject* UTetrahedralMeshImporterFactory::FactoryCreateFile(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, const FString& Filename, const TCHAR* Parms, FFeedbackContext* Warn, bool& bOutOperationCanceled)
{
	UTetrahedralMeshAsset* TetMeshAsset = nullptr;

	// Import file into imstk first to extract data
	std::shared_ptr<imstk::PointSet> ImportedPointSet = imstk::MeshIO::read<imstk::PointSet>(std::string(TCHAR_TO_UTF8(*Filename)));
	std::shared_ptr<imstk::SurfaceMesh> SurfaceMesh;

	if (ImportedPointSet->getTypeName() == "TetrahedralMesh") {
		// Create TetrahedralMeshAsset
		std::shared_ptr<imstk::TetrahedralMesh> TetMesh = std::dynamic_pointer_cast<imstk::TetrahedralMesh>(ImportedPointSet);

		// Rotate by -90 degrees on x axis to orient with obj imports
		TetMesh->rotate(imstk::Vec3d(1.0, 0.0, 0.0), -3.14/2, imstk::Geometry::TransformType::ApplyToData);

		FString TetAssetStr = InName.ToString();
		TetAssetStr.Append("_volume");
		FName TetAssetName = FName(*TetAssetStr);

		TetMeshAsset = NewObject<UTetrahedralMeshAsset>(InParent, InClass, TetAssetName, Flags);

		if (TetMeshAsset)
			TetMeshAsset->SetTetrahedralMesh(TetMesh);
		SurfaceMesh = TetMesh->extractSurfaceMesh();
	}
	else if (ImportedPointSet->getTypeName() == "SurfaceMesh")
	{
		SurfaceMesh = std::dynamic_pointer_cast<imstk::SurfaceMesh>(ImportedPointSet);
	}
	else if (ImportedPointSet->getTypeName() == "ImageData")
	{
		std::shared_ptr<imstk::ImageData> ImageData = std::dynamic_pointer_cast<imstk::ImageData>(ImportedPointSet)->cast(IMSTK_DOUBLE);

		FString Str = InName.ToString();
		Str.Append("_ImageData");
		FName ImageDataAssetName = FName(*Str);
		UImageDataAsset* ImageDataAsset = NewObject<UImageDataAsset>(InParent, InClass, ImageDataAssetName, Flags);
		
		ImageDataAsset->SetImageData(ImageData);

		return ImageDataAsset;
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

	// Create static mesh based on the imported values
	UPackage* Package = CreatePackage(*PackagePath);

	UStaticMesh* StaticMesh = NewObject<UStaticMesh>(Package, NewName, RF_Public | RF_Standalone);
	if (StaticMesh) {
		FRawMesh RawMesh;

		TArray<UMaterialInterface*> MeshMaterials;
		MeshMaterials.Add(UMaterial::GetDefaultMaterial(MD_Surface));

		imstk::VecDataArray<double, 3>& Vertices = *SurfaceMesh->getVertexPositions();
		for (int i = 0; i < Vertices.size(); i++) {
			// Avoid using Math util function to maintain vertex positions on import
			RawMesh.VertexPositions.Add(FVector3f(Vertices[i].x(), Vertices[i].z(), Vertices[i].y()));
		}

		// TODO: THIS IS UNTESTED (not sure which of the files contain texture information)
		std::shared_ptr<imstk::VecDataArray<float, 2>> ImstkTCoordsPtr = SurfaceMesh->getVertexTCoords();

		imstk::VecDataArray<float, 2>& ImstkTCoords = *ImstkTCoordsPtr;
		if (ImstkTCoordsPtr) {
			for (int i = 0; i < ImstkTCoords.size(); i++) {
				RawMesh.WedgeTexCoords->Add(FVector2f(ImstkTCoords[i][0], ImstkTCoords[i][1]));
			}
		}

		imstk::VecDataArray<int,3>& Indices = *SurfaceMesh->getTriangleIndices().get();
		for (int i = 0; i < SurfaceMesh->getNumTriangles(); i++) {
			imstk::Vec3i Index = Indices[i];
			RawMesh.WedgeIndices.Add(Index.x());
			RawMesh.WedgeIndices.Add(Index.y());
			RawMesh.WedgeIndices.Add(Index.z());

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


		// Model Configuration
		SourceModel.BuildSettings.bRecomputeNormals = true;
		SourceModel.BuildSettings.bRecomputeTangents = true;
		SourceModel.BuildSettings.bUseMikkTSpace = false;
		SourceModel.BuildSettings.bGenerateLightmapUVs = true;
		//SourceModel.BuildSettings.bBuildAdjacencyBuffer = false;
		SourceModel.BuildSettings.bBuildReversedIndexBuffer = false;
		SourceModel.BuildSettings.bUseFullPrecisionUVs = false;
		SourceModel.BuildSettings.bUseHighPrecisionTangentBasis = false;

		TArray<FText> BuildErrors;
		StaticMesh->Build(true, &BuildErrors);

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
