// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ImstkEditor/Public/ImstkGeometryImporterFactory.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
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
	UClass* Z_Construct_UClass_UImstkGeometryImporterFactory_NoRegister()
	{
		return UImstkGeometryImporterFactory::StaticClass();
	}
	struct Z_Construct_UClass_UImstkGeometryImporterFactory_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UImstkGeometryImporterFactory_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UFactory,
		(UObject* (*)())Z_Construct_UPackage__Script_ImstkEditor,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UImstkGeometryImporterFactory_Statics::Class_MetaDataParams[] = {
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
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UImstkGeometryImporterFactory_Statics::ClassParams = {
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
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UImstkGeometryImporterFactory_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UImstkGeometryImporterFactory, 182154960);
	template<> IMSTKEDITOR_API UClass* StaticClass<UImstkGeometryImporterFactory>()
	{
		return UImstkGeometryImporterFactory::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UImstkGeometryImporterFactory(Z_Construct_UClass_UImstkGeometryImporterFactory, &UImstkGeometryImporterFactory::StaticClass, TEXT("/Script/ImstkEditor"), TEXT("UImstkGeometryImporterFactory"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UImstkGeometryImporterFactory);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
