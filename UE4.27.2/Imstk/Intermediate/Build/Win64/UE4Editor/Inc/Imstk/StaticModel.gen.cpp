// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Imstk/Public/StaticModel.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeStaticModel() {}
// Cross Module References
	IMSTK_API UClass* Z_Construct_UClass_UStaticModel_NoRegister();
	IMSTK_API UClass* Z_Construct_UClass_UStaticModel();
	IMSTK_API UClass* Z_Construct_UClass_UDynamicalModel();
	UPackage* Z_Construct_UPackage__Script_Imstk();
// End Cross Module References
	void UStaticModel::StaticRegisterNativesUStaticModel()
	{
	}
	UClass* Z_Construct_UClass_UStaticModel_NoRegister()
	{
		return UStaticModel::StaticClass();
	}
	struct Z_Construct_UClass_UStaticModel_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UStaticModel_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UDynamicalModel,
		(UObject* (*)())Z_Construct_UPackage__Script_Imstk,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UStaticModel_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Custom" },
		{ "Comment", "/** \\file StaticModel.h\n *  \\brief Components for static models in imstk\n *  \\details Attach to models in Unreal to initialize them in imstk \n */" },
		{ "IncludePath", "StaticModel.h" },
		{ "ModuleRelativePath", "Public/StaticModel.h" },
		{ "ToolTip", "\\file StaticModel.h\n\\brief Components for static models in imstk\n\\details Attach to models in Unreal to initialize them in imstk" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UStaticModel_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UStaticModel>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UStaticModel_Statics::ClassParams = {
		&UStaticModel::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_UStaticModel_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UStaticModel_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UStaticModel()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UStaticModel_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UStaticModel, 2976586943);
	template<> IMSTK_API UClass* StaticClass<UStaticModel>()
	{
		return UStaticModel::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UStaticModel(Z_Construct_UClass_UStaticModel, &UStaticModel::StaticClass, TEXT("/Script/Imstk"), TEXT("UStaticModel"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UStaticModel);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
