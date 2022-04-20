// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Imstk/Public/ImstkMouseController.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeImstkMouseController() {}
// Cross Module References
	IMSTK_API UClass* Z_Construct_UClass_UImstkMouseController_NoRegister();
	IMSTK_API UClass* Z_Construct_UClass_UImstkMouseController();
	IMSTK_API UClass* Z_Construct_UClass_UImstkController();
	UPackage* Z_Construct_UPackage__Script_Imstk();
// End Cross Module References
	void UImstkMouseController::StaticRegisterNativesUImstkMouseController()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UImstkMouseController);
	UClass* Z_Construct_UClass_UImstkMouseController_NoRegister()
	{
		return UImstkMouseController::StaticClass();
	}
	struct Z_Construct_UClass_UImstkMouseController_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Offset_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Offset;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Mass_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Mass;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UImstkMouseController_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UImstkController,
		(UObject* (*)())Z_Construct_UPackage__Script_Imstk,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UImstkMouseController_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Imstk" },
		{ "Comment", "/** \\file ImstkMouseController.h\n *  \\brief Component to attach to objects that can be controlled using the mouse\n *  \\details Currently very basic and will only generate a line mesh of a specific size. Primarily used for testing purposes.\n */" },
		{ "IncludePath", "ImstkMouseController.h" },
		{ "ModuleRelativePath", "Public/ImstkMouseController.h" },
		{ "ToolTip", "\\file ImstkMouseController.h\n\\brief Component to attach to objects that can be controlled using the mouse\n\\details Currently very basic and will only generate a line mesh of a specific size. Primarily used for testing purposes." },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UImstkMouseController_Statics::NewProp_Offset_MetaData[] = {
		{ "Category", "General" },
		{ "ModuleRelativePath", "Public/ImstkMouseController.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UImstkMouseController_Statics::NewProp_Offset = { "Offset", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UImstkMouseController, Offset), METADATA_PARAMS(Z_Construct_UClass_UImstkMouseController_Statics::NewProp_Offset_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UImstkMouseController_Statics::NewProp_Offset_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UImstkMouseController_Statics::NewProp_Mass_MetaData[] = {
		{ "Category", "General" },
		{ "ModuleRelativePath", "Public/ImstkMouseController.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UImstkMouseController_Statics::NewProp_Mass = { "Mass", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UImstkMouseController, Mass), METADATA_PARAMS(Z_Construct_UClass_UImstkMouseController_Statics::NewProp_Mass_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UImstkMouseController_Statics::NewProp_Mass_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UImstkMouseController_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UImstkMouseController_Statics::NewProp_Offset,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UImstkMouseController_Statics::NewProp_Mass,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UImstkMouseController_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UImstkMouseController>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UImstkMouseController_Statics::ClassParams = {
		&UImstkMouseController::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UImstkMouseController_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UImstkMouseController_Statics::PropPointers),
		0,
		0x00B000A4u,
		METADATA_PARAMS(Z_Construct_UClass_UImstkMouseController_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UImstkMouseController_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UImstkMouseController()
	{
		if (!Z_Registration_Info_UClass_UImstkMouseController.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UImstkMouseController.OuterSingleton, Z_Construct_UClass_UImstkMouseController_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UImstkMouseController.OuterSingleton;
	}
	template<> IMSTK_API UClass* StaticClass<UImstkMouseController>()
	{
		return UImstkMouseController::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UImstkMouseController);
	struct Z_CompiledInDeferFile_FID_HostProject_Plugins_Imstk_Source_Imstk_Public_ImstkMouseController_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_Imstk_Source_Imstk_Public_ImstkMouseController_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UImstkMouseController, UImstkMouseController::StaticClass, TEXT("UImstkMouseController"), &Z_Registration_Info_UClass_UImstkMouseController, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UImstkMouseController), 2479705215U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_Imstk_Source_Imstk_Public_ImstkMouseController_h_224775076(TEXT("/Script/Imstk"),
		Z_CompiledInDeferFile_FID_HostProject_Plugins_Imstk_Source_Imstk_Public_ImstkMouseController_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HostProject_Plugins_Imstk_Source_Imstk_Public_ImstkMouseController_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
