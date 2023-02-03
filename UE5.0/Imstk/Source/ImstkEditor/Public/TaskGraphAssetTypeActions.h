// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AssetTypeActions_Base.h"

/** \file TaskGraphAssetTypeActions.h
 *  \brief Asset actions for the iMSTK task graph
 *  \details 
 */
class IMSTKEDITOR_API FTaskGraphAssetTypeActions : public FAssetTypeActions_Base
{
public:
	FTaskGraphAssetTypeActions(EAssetTypeCategories::Type InAssetCategory);
	virtual void OpenAssetEditor(const TArray<UObject*>& InObjects, TSharedPtr<class IToolkitHost> EditWithinLevelEditor = TSharedPtr<IToolkitHost>()) override;

private:
	EAssetTypeCategories::Type MyAssetCategory;

	// Inherited via FAssetTypeActions_Base
	virtual FText GetName() const override;
	virtual UClass* GetSupportedClass() const override;
	virtual FColor GetTypeColor() const override;
	virtual uint32 GetCategories() override;
};
