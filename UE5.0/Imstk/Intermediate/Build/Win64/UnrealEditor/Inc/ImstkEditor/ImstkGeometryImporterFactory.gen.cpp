// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ImstkEditor/Public/ImstkGeometryImporterFactory.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeImstkGeometryImporterFactory() {}
// Cross Module References
	IMSTKEDITOR_API UClass* Z_Construct_UClass_UImstkGeometryImporterFactory_NoRegister();
	IMSTKEDITOR_API UClass* Z_Construct_UClass_UImstkGeometryImporterFactory();
	UNREALED_API UClass* Z_Construct_UClass_UFactory();
	UPackage* Z_Construct_UPackage__Script_ImstkEditor();
// End Cross Module References
	void UImstkGeometryImporterFactory::StaticRegisterNativesUImstkGeometryImporterFactory()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UImstkGeometryImporterFactory);
	UClass* Z_Construct_UClass_UImstkGeometryImporterFactory_NoRegister()
	{
		return UImstkGeometryImporterFactory::StaticClass();
	}
	struct Z_Construct_UClass_UImstkGeometryImporterFactory_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UImstkGeometryImporterFactory_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UFactory,
		(UObject* (*)())Z_Construct_UPackage__Script_ImstkEditor,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UImstkGeometryImporterFactory_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/** \\file ImstkGeometryImporterFactory.h\n *  \\brief Factory class to create assets when importing meshs to be used for imstk\n *  \\details Currently works with .vtk, .vtu, .vtp, .stl, .ply, .veg\n */" },
		{ "HideCategories", "Object" },
		{ "IncludePath", "ImstkGeometryImporterFactory.h" },
		{ "ModuleRelativePath", "Public/ImstkGeometryImporterFactory.h" },
		{ "ToolTip", "\\file ImstkGeometryImporterFactory.h\n\\brief Factory class to create assets when importing meshs to be used for imstk\n\\details Currently works with .vtk, .vtu, .vtp, .stl, .ply, .veg" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UImstkGeometryImporterFactory_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UImstkGeometryImporterFactory>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UImstkGeometryImporterFactory_Statics::ClassParams = {
		&UImstkGeometryImporterFactory::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x000000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UImstkGeometryImporterFactory_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UImstkGeometryImporterFactory_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UImstkGeometryImporterFactory()
	{
		if (!Z_Registration_Info_UClass_UImstkGeometryImporterFactory.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UImstkGeometryImporterFactory.OuterSingleton, Z_Construct_UClass_UImstkGeometryImporterFactory_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UImstkGeometryImporterFactory.OuterSingleton;
	}
	template<> IMSTKEDITOR_API UClass* StaticClass<UImstkGeometryImporterFactory>()
	{
		return UImstkGeometryImporterFactory::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UImstkGeometryImporterFactory);
	struct Z_CompiledInDeferFile_FID_HostProject_Plugins_Imstk_Source_ImstkEditor_Public_ImstkGeometryImporterFactory_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_Imstk_Source_ImstkEditor_Public_ImstkGeometryImporterFactory_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UImstkGeometryImporterFactory, UImstkGeometryImporterFactory::StaticClass, TEXT("UImstkGeometryImporterFactory"), &Z_Registration_Info_UClass_UImstkGeometryImporterFactory, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UImstkGeometryImporterFactory), 707171953U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_Imstk_Source_ImstkEditor_Public_ImstkGeometryImporterFactory_h_2911868615(TEXT("/Script/ImstkEditor"),
		Z_CompiledInDeferFile_FID_HostProject_Plugins_Imstk_Source_ImstkEditor_Public_ImstkGeometryImporterFactory_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HostProject_Plugins_Imstk_Source_ImstkEditor_Public_ImstkGeometryImporterFactory_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
