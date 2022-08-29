// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Imstk/Public/ImageDataAsset.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeImageDataAsset() {}
// Cross Module References
	IMSTK_API UClass* Z_Construct_UClass_UImageDataAsset_NoRegister();
	IMSTK_API UClass* Z_Construct_UClass_UImageDataAsset();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	UPackage* Z_Construct_UPackage__Script_Imstk();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
// End Cross Module References
	void UImageDataAsset::StaticRegisterNativesUImageDataAsset()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UImageDataAsset);
	UClass* Z_Construct_UClass_UImageDataAsset_NoRegister()
	{
		return UImageDataAsset::StaticClass();
	}
	struct Z_Construct_UClass_UImageDataAsset_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Spacing_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Spacing;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Origin_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Origin;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Dimensions_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Dimensions;
		static const UECodeGen_Private::FDoublePropertyParams NewProp_Scalars_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Scalars_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_Scalars;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ImageComponents_MetaData[];
#endif
		static const UECodeGen_Private::FUnsizedIntPropertyParams NewProp_ImageComponents;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UImageDataAsset_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_Imstk,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UImageDataAsset_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/** \\file ImageDataAsset.h\n *  \\brief Stores the information required to generate ImageData\n *  \\details\n */" },
		{ "IncludePath", "ImageDataAsset.h" },
		{ "ModuleRelativePath", "Public/ImageDataAsset.h" },
		{ "ToolTip", "\\file ImageDataAsset.h\n\\brief Stores the information required to generate ImageData\n\\details" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UImageDataAsset_Statics::NewProp_Spacing_MetaData[] = {
		{ "Category", "General" },
		{ "Comment", "// Spacing of the image data\n" },
		{ "ModuleRelativePath", "Public/ImageDataAsset.h" },
		{ "ToolTip", "Spacing of the image data" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UImageDataAsset_Statics::NewProp_Spacing = { "Spacing", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UImageDataAsset, Spacing), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UClass_UImageDataAsset_Statics::NewProp_Spacing_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UImageDataAsset_Statics::NewProp_Spacing_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UImageDataAsset_Statics::NewProp_Origin_MetaData[] = {
		{ "Category", "General" },
		{ "Comment", "// Origin of the image data\n" },
		{ "ModuleRelativePath", "Public/ImageDataAsset.h" },
		{ "ToolTip", "Origin of the image data" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UImageDataAsset_Statics::NewProp_Origin = { "Origin", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UImageDataAsset, Origin), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UClass_UImageDataAsset_Statics::NewProp_Origin_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UImageDataAsset_Statics::NewProp_Origin_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UImageDataAsset_Statics::NewProp_Dimensions_MetaData[] = {
		{ "Category", "General" },
		{ "Comment", "// Dimensions of the image data\n" },
		{ "ModuleRelativePath", "Public/ImageDataAsset.h" },
		{ "ToolTip", "Dimensions of the image data" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UImageDataAsset_Statics::NewProp_Dimensions = { "Dimensions", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UImageDataAsset, Dimensions), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UClass_UImageDataAsset_Statics::NewProp_Dimensions_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UImageDataAsset_Statics::NewProp_Dimensions_MetaData)) };
	const UECodeGen_Private::FDoublePropertyParams Z_Construct_UClass_UImageDataAsset_Statics::NewProp_Scalars_Inner = { "Scalars", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Double, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UImageDataAsset_Statics::NewProp_Scalars_MetaData[] = {
		{ "Category", "General" },
		{ "Comment", "// Scalars of the image data\n" },
		{ "ModuleRelativePath", "Public/ImageDataAsset.h" },
		{ "ToolTip", "Scalars of the image data" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UImageDataAsset_Statics::NewProp_Scalars = { "Scalars", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UImageDataAsset, Scalars), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_UImageDataAsset_Statics::NewProp_Scalars_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UImageDataAsset_Statics::NewProp_Scalars_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UImageDataAsset_Statics::NewProp_ImageComponents_MetaData[] = {
		{ "Category", "General" },
		{ "Comment", "// Number of image components of the image data\n" },
		{ "ModuleRelativePath", "Public/ImageDataAsset.h" },
		{ "ToolTip", "Number of image components of the image data" },
	};
#endif
	const UECodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_UImageDataAsset_Statics::NewProp_ImageComponents = { "ImageComponents", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UImageDataAsset, ImageComponents), METADATA_PARAMS(Z_Construct_UClass_UImageDataAsset_Statics::NewProp_ImageComponents_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UImageDataAsset_Statics::NewProp_ImageComponents_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UImageDataAsset_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UImageDataAsset_Statics::NewProp_Spacing,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UImageDataAsset_Statics::NewProp_Origin,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UImageDataAsset_Statics::NewProp_Dimensions,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UImageDataAsset_Statics::NewProp_Scalars_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UImageDataAsset_Statics::NewProp_Scalars,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UImageDataAsset_Statics::NewProp_ImageComponents,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UImageDataAsset_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UImageDataAsset>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UImageDataAsset_Statics::ClassParams = {
		&UImageDataAsset::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UImageDataAsset_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UImageDataAsset_Statics::PropPointers),
		0,
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UImageDataAsset_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UImageDataAsset_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UImageDataAsset()
	{
		if (!Z_Registration_Info_UClass_UImageDataAsset.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UImageDataAsset.OuterSingleton, Z_Construct_UClass_UImageDataAsset_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UImageDataAsset.OuterSingleton;
	}
	template<> IMSTK_API UClass* StaticClass<UImageDataAsset>()
	{
		return UImageDataAsset::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UImageDataAsset);
	struct Z_CompiledInDeferFile_FID_HostProject_Plugins_Imstk_Source_Imstk_Public_ImageDataAsset_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_Imstk_Source_Imstk_Public_ImageDataAsset_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UImageDataAsset, UImageDataAsset::StaticClass, TEXT("UImageDataAsset"), &Z_Registration_Info_UClass_UImageDataAsset, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UImageDataAsset), 1210950520U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_Imstk_Source_Imstk_Public_ImageDataAsset_h_165965114(TEXT("/Script/Imstk"),
		Z_CompiledInDeferFile_FID_HostProject_Plugins_Imstk_Source_Imstk_Public_ImageDataAsset_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HostProject_Plugins_Imstk_Source_Imstk_Public_ImageDataAsset_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
