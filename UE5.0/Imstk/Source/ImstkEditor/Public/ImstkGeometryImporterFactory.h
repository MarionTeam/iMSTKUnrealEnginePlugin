// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Factories/Factory.h"
#include "ImstkGeometryImporterFactory.generated.h"

/** \file ImstkGeometryImporterFactory.h
 *  \brief Factory class to create assets when importing meshs to be used for imstk
 *  \details Currently works with .vtk, .vtu, .vtp, .stl, .ply, .veg
 */
UCLASS(hidecategories = Object)
class UImstkGeometryImporterFactory : public UFactory
{
	GENERATED_UCLASS_BODY()
	
public:
	/** Creates a static mesh using imported file. Will also generate a TetrahedralMeshAsset if the imported mesh is tetrahedral
	* @return UObject*
	*/
	virtual UObject* FactoryCreateFile(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, const FString& Filename, const TCHAR* Parms, FFeedbackContext* Warn, bool& bOutOperationCanceled) override;
};
