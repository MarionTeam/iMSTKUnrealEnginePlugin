// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Imstk/Public/ControllerInteraction.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeControllerInteraction() {}
// Cross Module References
	IMSTK_API UClass* Z_Construct_UClass_UControllerInteraction_NoRegister();
	IMSTK_API UClass* Z_Construct_UClass_UControllerInteraction();
	IMSTK_API UClass* Z_Construct_UClass_UCollisionInteraction();
	UPackage* Z_Construct_UPackage__Script_Imstk();
	IMSTK_API UClass* Z_Construct_UClass_UImstkController_NoRegister();
// End Cross Module References
	void UControllerInteraction::StaticRegisterNativesUControllerInteraction()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UControllerInteraction);
	UClass* Z_Construct_UClass_UControllerInteraction_NoRegister()
	{
		return UControllerInteraction::StaticClass();
	}
	struct Z_Construct_UClass_UControllerInteraction_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Controller_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Controller;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UControllerInteraction_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UCollisionInteraction,
		(UObject* (*)())Z_Construct_UPackage__Script_Imstk,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UControllerInteraction_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/** \\file ControllerInteraction.h\n *  \\brief Class used to create and represent interaction between controller and object\n *  \\details  Can be created in blueprint to make the imstk collision interaction and initialize using the imstk subsystem. Requires model1 and controller to be set. Collision type may be left as auto automatically determine the collision type.\n */" },
		{ "IncludePath", "ControllerInteraction.h" },
		{ "ModuleRelativePath", "Public/ControllerInteraction.h" },
		{ "ToolTip", "\\file ControllerInteraction.h\n\\brief Class used to create and represent interaction between controller and object\n\\details  Can be created in blueprint to make the imstk collision interaction and initialize using the imstk subsystem. Requires model1 and controller to be set. Collision type may be left as auto automatically determine the collision type." },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UControllerInteraction_Statics::NewProp_Controller_MetaData[] = {
		{ "Category", "Collision Interaction" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/ControllerInteraction.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UControllerInteraction_Statics::NewProp_Controller = { "Controller", nullptr, (EPropertyFlags)0x00100000000a000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UControllerInteraction, Controller), Z_Construct_UClass_UImstkController_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UControllerInteraction_Statics::NewProp_Controller_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UControllerInteraction_Statics::NewProp_Controller_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UControllerInteraction_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UControllerInteraction_Statics::NewProp_Controller,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UControllerInteraction_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UControllerInteraction>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UControllerInteraction_Statics::ClassParams = {
		&UControllerInteraction::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UControllerInteraction_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UControllerInteraction_Statics::PropPointers),
		0,
		0x009000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UControllerInteraction_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UControllerInteraction_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UControllerInteraction()
	{
		if (!Z_Registration_Info_UClass_UControllerInteraction.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UControllerInteraction.OuterSingleton, Z_Construct_UClass_UControllerInteraction_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UControllerInteraction.OuterSingleton;
	}
	template<> IMSTK_API UClass* StaticClass<UControllerInteraction>()
	{
		return UControllerInteraction::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UControllerInteraction);
	struct Z_CompiledInDeferFile_FID_HostProject_Plugins_Imstk_Source_Imstk_Public_ControllerInteraction_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_Imstk_Source_Imstk_Public_ControllerInteraction_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UControllerInteraction, UControllerInteraction::StaticClass, TEXT("UControllerInteraction"), &Z_Registration_Info_UClass_UControllerInteraction, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UControllerInteraction), 2256498263U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_Imstk_Source_Imstk_Public_ControllerInteraction_h_538200483(TEXT("/Script/Imstk"),
		Z_CompiledInDeferFile_FID_HostProject_Plugins_Imstk_Source_Imstk_Public_ControllerInteraction_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HostProject_Plugins_Imstk_Source_Imstk_Public_ControllerInteraction_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
