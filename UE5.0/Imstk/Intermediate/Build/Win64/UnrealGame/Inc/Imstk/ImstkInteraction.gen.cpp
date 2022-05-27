// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Imstk/Public/ImstkInteraction.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeImstkInteraction() {}
// Cross Module References
	IMSTK_API UClass* Z_Construct_UClass_UImstkInteraction_NoRegister();
	IMSTK_API UClass* Z_Construct_UClass_UImstkInteraction();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	UPackage* Z_Construct_UPackage__Script_Imstk();
// End Cross Module References
	void UImstkInteraction::StaticRegisterNativesUImstkInteraction()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UImstkInteraction);
	UClass* Z_Construct_UClass_UImstkInteraction_NoRegister()
	{
		return UImstkInteraction::StaticClass();
	}
	struct Z_Construct_UClass_UImstkInteraction_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UImstkInteraction_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_Imstk,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UImstkInteraction_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/** \\file ImstkInteraction.h\n *  \\brief Abstract class for Imstk interactions\n *  \\details Provides a function for initializing the interaction. Can be overridden in child classes to create the interaction in imstk\n */" },
		{ "IncludePath", "ImstkInteraction.h" },
		{ "ModuleRelativePath", "Public/ImstkInteraction.h" },
		{ "ToolTip", "\\file ImstkInteraction.h\n\\brief Abstract class for Imstk interactions\n\\details Provides a function for initializing the interaction. Can be overridden in child classes to create the interaction in imstk" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UImstkInteraction_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UImstkInteraction>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UImstkInteraction_Statics::ClassParams = {
		&UImstkInteraction::StaticClass,
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
		0x001000A1u,
		METADATA_PARAMS(Z_Construct_UClass_UImstkInteraction_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UImstkInteraction_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UImstkInteraction()
	{
		if (!Z_Registration_Info_UClass_UImstkInteraction.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UImstkInteraction.OuterSingleton, Z_Construct_UClass_UImstkInteraction_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UImstkInteraction.OuterSingleton;
	}
	template<> IMSTK_API UClass* StaticClass<UImstkInteraction>()
	{
		return UImstkInteraction::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UImstkInteraction);
	struct Z_CompiledInDeferFile_FID_HostProject_Plugins_Imstk_Source_Imstk_Public_ImstkInteraction_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_Imstk_Source_Imstk_Public_ImstkInteraction_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UImstkInteraction, UImstkInteraction::StaticClass, TEXT("UImstkInteraction"), &Z_Registration_Info_UClass_UImstkInteraction, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UImstkInteraction), 1738596207U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_Imstk_Source_Imstk_Public_ImstkInteraction_h_2470591562(TEXT("/Script/Imstk"),
		Z_CompiledInDeferFile_FID_HostProject_Plugins_Imstk_Source_Imstk_Public_ImstkInteraction_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HostProject_Plugins_Imstk_Source_Imstk_Public_ImstkInteraction_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
