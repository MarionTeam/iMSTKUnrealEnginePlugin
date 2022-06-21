// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Imstk/Public/InflatableModel.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeInflatableModel() {}
// Cross Module References
	IMSTK_API UClass* Z_Construct_UClass_UInflatableModel_NoRegister();
	IMSTK_API UClass* Z_Construct_UClass_UInflatableModel();
	IMSTK_API UClass* Z_Construct_UClass_UPBDModel();
	UPackage* Z_Construct_UPackage__Script_Imstk();
// End Cross Module References
	void UInflatableModel::StaticRegisterNativesUInflatableModel()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UInflatableModel);
	UClass* Z_Construct_UClass_UInflatableModel_NoRegister()
	{
		return UInflatableModel::StaticClass();
	}
	struct Z_Construct_UClass_UInflatableModel_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UInflatableModel_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UPBDModel,
		(UObject* (*)())Z_Construct_UPackage__Script_Imstk,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UInflatableModel_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "InflatableModel.h" },
		{ "ModuleRelativePath", "Public/InflatableModel.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UInflatableModel_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UInflatableModel>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UInflatableModel_Statics::ClassParams = {
		&UInflatableModel::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x00B000A4u,
		METADATA_PARAMS(Z_Construct_UClass_UInflatableModel_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UInflatableModel_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UInflatableModel()
	{
		if (!Z_Registration_Info_UClass_UInflatableModel.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UInflatableModel.OuterSingleton, Z_Construct_UClass_UInflatableModel_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UInflatableModel.OuterSingleton;
	}
	template<> IMSTK_API UClass* StaticClass<UInflatableModel>()
	{
		return UInflatableModel::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UInflatableModel);
	struct Z_CompiledInDeferFile_FID_HostProject_Plugins_Imstk_Source_Imstk_Public_InflatableModel_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_Imstk_Source_Imstk_Public_InflatableModel_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UInflatableModel, UInflatableModel::StaticClass, TEXT("UInflatableModel"), &Z_Registration_Info_UClass_UInflatableModel, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UInflatableModel), 988700439U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_Imstk_Source_Imstk_Public_InflatableModel_h_2089698289(TEXT("/Script/Imstk"),
		Z_CompiledInDeferFile_FID_HostProject_Plugins_Imstk_Source_Imstk_Public_InflatableModel_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HostProject_Plugins_Imstk_Source_Imstk_Public_InflatableModel_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
