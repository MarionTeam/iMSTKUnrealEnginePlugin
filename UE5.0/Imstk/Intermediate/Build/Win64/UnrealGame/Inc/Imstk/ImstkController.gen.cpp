// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Imstk/Public/ImstkController.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeImstkController() {}
// Cross Module References
	IMSTK_API UClass* Z_Construct_UClass_UImstkController_NoRegister();
	IMSTK_API UClass* Z_Construct_UClass_UImstkController();
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
	UPackage* Z_Construct_UPackage__Script_Imstk();
	IMSTK_API UClass* Z_Construct_UClass_UImstkSubsystem_NoRegister();
// End Cross Module References
	void UImstkController::StaticRegisterNativesUImstkController()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UImstkController);
	UClass* Z_Construct_UClass_UImstkController_NoRegister()
	{
		return UImstkController::StaticClass();
	}
	struct Z_Construct_UClass_UImstkController_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SubsystemInstance_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_SubsystemInstance;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UImstkController_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UActorComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_Imstk,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UImstkController_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/** \\file ImstkController.h\n *  \\brief Abstract class for object in imstk that can be controlled by the user\n *  \\details \n */" },
		{ "IncludePath", "ImstkController.h" },
		{ "ModuleRelativePath", "Public/ImstkController.h" },
		{ "ToolTip", "\\file ImstkController.h\n\\brief Abstract class for object in imstk that can be controlled by the user\n\\details" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UImstkController_Statics::NewProp_SubsystemInstance_MetaData[] = {
		{ "ModuleRelativePath", "Public/ImstkController.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UImstkController_Statics::NewProp_SubsystemInstance = { "SubsystemInstance", nullptr, (EPropertyFlags)0x0020080000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UImstkController, SubsystemInstance), Z_Construct_UClass_UImstkSubsystem_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UImstkController_Statics::NewProp_SubsystemInstance_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UImstkController_Statics::NewProp_SubsystemInstance_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UImstkController_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UImstkController_Statics::NewProp_SubsystemInstance,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UImstkController_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UImstkController>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UImstkController_Statics::ClassParams = {
		&UImstkController::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UImstkController_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UImstkController_Statics::PropPointers),
		0,
		0x00B000A5u,
		METADATA_PARAMS(Z_Construct_UClass_UImstkController_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UImstkController_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UImstkController()
	{
		if (!Z_Registration_Info_UClass_UImstkController.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UImstkController.OuterSingleton, Z_Construct_UClass_UImstkController_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UImstkController.OuterSingleton;
	}
	template<> IMSTK_API UClass* StaticClass<UImstkController>()
	{
		return UImstkController::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UImstkController);
	struct Z_CompiledInDeferFile_FID_HostProject_Plugins_Imstk_Source_Imstk_Public_ImstkController_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_Imstk_Source_Imstk_Public_ImstkController_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UImstkController, UImstkController::StaticClass, TEXT("UImstkController"), &Z_Registration_Info_UClass_UImstkController, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UImstkController), 1275213735U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_Imstk_Source_Imstk_Public_ImstkController_h_3206455214(TEXT("/Script/Imstk"),
		Z_CompiledInDeferFile_FID_HostProject_Plugins_Imstk_Source_Imstk_Public_ImstkController_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HostProject_Plugins_Imstk_Source_Imstk_Public_ImstkController_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
