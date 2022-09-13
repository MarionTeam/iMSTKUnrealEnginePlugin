// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Imstk/Public/StaticModel.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeStaticModel() {}
// Cross Module References
	IMSTK_API UClass* Z_Construct_UClass_UStaticModel_NoRegister();
	IMSTK_API UClass* Z_Construct_UClass_UStaticModel();
	IMSTK_API UClass* Z_Construct_UClass_UDynamicalModel();
	UPackage* Z_Construct_UPackage__Script_Imstk();
	IMSTK_API UEnum* Z_Construct_UEnum_Imstk_EDefaultModelPreset();
// End Cross Module References
	void UStaticModel::StaticRegisterNativesUStaticModel()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UStaticModel);
	UClass* Z_Construct_UClass_UStaticModel_NoRegister()
	{
		return UStaticModel::StaticClass();
	}
	struct Z_Construct_UClass_UStaticModel_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Preset_MetaData[];
#endif
		static const UECodeGen_Private::FBytePropertyParams NewProp_Preset;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UStaticModel_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UDynamicalModel,
		(UObject* (*)())Z_Construct_UPackage__Script_Imstk,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UStaticModel_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Imstk" },
		{ "Comment", "/** \\file StaticModel.h\n *  \\brief Components for static models in imstk\n *  \\details Attach to models in Unreal to initialize them in imstk \n */" },
		{ "IncludePath", "StaticModel.h" },
		{ "ModuleRelativePath", "Public/StaticModel.h" },
		{ "ToolTip", "\\file StaticModel.h\n\\brief Components for static models in imstk\n\\details Attach to models in Unreal to initialize them in imstk" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UStaticModel_Statics::NewProp_Preset_MetaData[] = {
		{ "Category", "General" },
		{ "ModuleRelativePath", "Public/StaticModel.h" },
	};
#endif
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UStaticModel_Statics::NewProp_Preset = { "Preset", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UStaticModel, Preset), Z_Construct_UEnum_Imstk_EDefaultModelPreset, METADATA_PARAMS(Z_Construct_UClass_UStaticModel_Statics::NewProp_Preset_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UStaticModel_Statics::NewProp_Preset_MetaData)) }; // 2990222660
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UStaticModel_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UStaticModel_Statics::NewProp_Preset,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UStaticModel_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UStaticModel>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UStaticModel_Statics::ClassParams = {
		&UStaticModel::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UStaticModel_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UStaticModel_Statics::PropPointers),
		0,
		0x00B000A4u,
		METADATA_PARAMS(Z_Construct_UClass_UStaticModel_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UStaticModel_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UStaticModel()
	{
		if (!Z_Registration_Info_UClass_UStaticModel.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UStaticModel.OuterSingleton, Z_Construct_UClass_UStaticModel_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UStaticModel.OuterSingleton;
	}
	template<> IMSTK_API UClass* StaticClass<UStaticModel>()
	{
		return UStaticModel::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UStaticModel);
	struct Z_CompiledInDeferFile_FID_HostProject_Plugins_Imstk_Source_Imstk_Public_StaticModel_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_Imstk_Source_Imstk_Public_StaticModel_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UStaticModel, UStaticModel::StaticClass, TEXT("UStaticModel"), &Z_Registration_Info_UClass_UStaticModel, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UStaticModel), 422091121U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_Imstk_Source_Imstk_Public_StaticModel_h_1426264641(TEXT("/Script/Imstk"),
		Z_CompiledInDeferFile_FID_HostProject_Plugins_Imstk_Source_Imstk_Public_StaticModel_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HostProject_Plugins_Imstk_Source_Imstk_Public_StaticModel_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
