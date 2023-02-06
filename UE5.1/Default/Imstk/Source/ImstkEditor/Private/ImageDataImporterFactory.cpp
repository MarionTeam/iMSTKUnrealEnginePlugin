// Fill out your copyright notice in the Description page of Project Settings.


#include "ImageDataImporterFactory.h"
#include "ImageDataAsset.h"
#include "MathUtil.h"
#include "AssetRegistry/AssetRegistryModule.h"
#include "imstkMeshIO.h"

UImageDataImporterFactory::UImageDataImporterFactory(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	Formats.Add(FString(TEXT("nii;")) + NSLOCTEXT("UImstkGeometryImporterFactory", "FormatNii", "Nii File").ToString());
	Formats.Add(FString(TEXT("dcm;")) + NSLOCTEXT("UImstkGeometryImporterFactory", "FormatDcm", "Dcm File").ToString());
	Formats.Add(FString(TEXT("nrrd;")) + NSLOCTEXT("UImstkGeometryImporterFactory", "FormatNrrd", "Nrrd File").ToString());
	Formats.Add(FString(TEXT("mhd;")) + NSLOCTEXT("UImstkGeometryImporterFactory", "FormatMhd", "Mhd File").ToString());
	SupportedClass = UImageDataAsset::StaticClass();
	bCreateNew = false;
	bEditorImport = true;
}

//TODO: Maybe make a menu pop up to decide some of the choices here
UObject* UImageDataImporterFactory::FactoryCreateFile(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, const FString& Filename, const TCHAR* Parms, FFeedbackContext* Warn, bool& bOutOperationCanceled)
{

	// Import file into imstk first to extract data
	std::shared_ptr<imstk::PointSet> ImportedPointSet = imstk::MeshIO::read<imstk::PointSet>(std::string(TCHAR_TO_UTF8(*Filename)));

	if (ImportedPointSet->getTypeName() == "ImageData")
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
		
		return nullptr;
	}
}
