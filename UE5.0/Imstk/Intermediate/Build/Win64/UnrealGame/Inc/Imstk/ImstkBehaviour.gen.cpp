// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Imstk/Public/ImstkBehaviour.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeImstkBehaviour() {}
// Cross Module References
	IMSTK_API UClass* Z_Construct_UClass_UImstkBehaviour_NoRegister();
	IMSTK_API UClass* Z_Construct_UClass_UImstkBehaviour();
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
	UPackage* Z_Construct_UPackage__Script_Imstk();
// End Cross Module References
	void UImstkBehaviour::StaticRegisterNativesUImstkBehaviour()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UImstkBehaviour);
	UClass* Z_Construct_UClass_UImstkBehaviour_NoRegister()
	{
		return UImstkBehaviour::StaticClass();
	}
	struct Z_Construct_UClass_UImstkBehaviour_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UImstkBehaviour_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UActorComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_Imstk,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UImstkBehaviour_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/** \\file ImstkBehaviour.h\n *  \\brief Abstract class for all Imstk Actor Components that need to be initialized\n *  \\details Classes that use this include dynamical models, interactions, etc.\n */" },
		{ "IncludePath", "ImstkBehaviour.h" },
		{ "ModuleRelativePath", "Public/ImstkBehaviour.h" },
		{ "ToolTip", "\\file ImstkBehaviour.h\n\\brief Abstract class for all Imstk Actor Components that need to be initialized\n\\details Classes that use this include dynamical models, interactions, etc." },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UImstkBehaviour_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UImstkBehaviour>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UImstkBehaviour_Statics::ClassParams = {
		&UImstkBehaviour::StaticClass,
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
		0x00B000A5u,
		METADATA_PARAMS(Z_Construct_UClass_UImstkBehaviour_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UImstkBehaviour_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UImstkBehaviour()
	{
		if (!Z_Registration_Info_UClass_UImstkBehaviour.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UImstkBehaviour.OuterSingleton, Z_Construct_UClass_UImstkBehaviour_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UImstkBehaviour.OuterSingleton;
	}
	template<> IMSTK_API UClass* StaticClass<UImstkBehaviour>()
	{
		return UImstkBehaviour::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UImstkBehaviour);
	struct Z_CompiledInDeferFile_FID_HostProject_Plugins_Imstk_Source_Imstk_Public_ImstkBehaviour_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_Imstk_Source_Imstk_Public_ImstkBehaviour_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UImstkBehaviour, UImstkBehaviour::StaticClass, TEXT("UImstkBehaviour"), &Z_Registration_Info_UClass_UImstkBehaviour, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UImstkBehaviour), 1422785822U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_Imstk_Source_Imstk_Public_ImstkBehaviour_h_2651140189(TEXT("/Script/Imstk"),
		Z_CompiledInDeferFile_FID_HostProject_Plugins_Imstk_Source_Imstk_Public_ImstkBehaviour_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HostProject_Plugins_Imstk_Source_Imstk_Public_ImstkBehaviour_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
