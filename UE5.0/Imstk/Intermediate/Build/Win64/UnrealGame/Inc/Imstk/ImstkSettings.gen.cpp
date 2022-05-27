// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Imstk/Public/ImstkSettings.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeImstkSettings() {}
// Cross Module References
	IMSTK_API UClass* Z_Construct_UClass_UImstkSettings_NoRegister();
	IMSTK_API UClass* Z_Construct_UClass_UImstkSettings();
	DEVELOPERSETTINGS_API UClass* Z_Construct_UClass_UDeveloperSettings();
	UPackage* Z_Construct_UPackage__Script_Imstk();
// End Cross Module References
	void UImstkSettings::StaticRegisterNativesUImstkSettings()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UImstkSettings);
	UClass* Z_Construct_UClass_UImstkSettings_NoRegister()
	{
		return UImstkSettings::StaticClass();
	}
	struct Z_Construct_UClass_UImstkSettings_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bUseRealtime_MetaData[];
#endif
		static void NewProp_bUseRealtime_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bUseRealtime;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bLoggerActive_MetaData[];
#endif
		static void NewProp_bLoggerActive_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bLoggerActive;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bDebuggingActive_MetaData[];
#endif
		static void NewProp_bDebuggingActive_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bDebuggingActive;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bWriteTaskGraph_MetaData[];
#endif
		static void NewProp_bWriteTaskGraph_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bWriteTaskGraph;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UImstkSettings_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UDeveloperSettings,
		(UObject* (*)())Z_Construct_UPackage__Script_Imstk,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UImstkSettings_Statics::Class_MetaDataParams[] = {
		{ "Category", "Holds settings for iMSTK" },
		{ "Comment", "/** \\file ImstkSettings.h\n *  \\brief Provides settings in editor for imstk\n *  \\details Has settings for imstk logging and debugging messages in unreal\n */" },
		{ "IncludePath", "ImstkSettings.h" },
		{ "ModuleRelativePath", "Public/ImstkSettings.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
		{ "ToolTip", "\\file ImstkSettings.h\n\\brief Provides settings in editor for imstk\n\\details Has settings for imstk logging and debugging messages in unreal" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UImstkSettings_Statics::NewProp_bUseRealtime_MetaData[] = {
		{ "Category", "General" },
		{ "ModuleRelativePath", "Public/ImstkSettings.h" },
		{ "Tooltip", "If true, deformable models will update their timesteps to line up with Unreal." },
	};
#endif
	void Z_Construct_UClass_UImstkSettings_Statics::NewProp_bUseRealtime_SetBit(void* Obj)
	{
		((UImstkSettings*)Obj)->bUseRealtime = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UImstkSettings_Statics::NewProp_bUseRealtime = { "bUseRealtime", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UImstkSettings), &Z_Construct_UClass_UImstkSettings_Statics::NewProp_bUseRealtime_SetBit, METADATA_PARAMS(Z_Construct_UClass_UImstkSettings_Statics::NewProp_bUseRealtime_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UImstkSettings_Statics::NewProp_bUseRealtime_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UImstkSettings_Statics::NewProp_bLoggerActive_MetaData[] = {
		{ "Category", "Debugging" },
		{ "ModuleRelativePath", "Public/ImstkSettings.h" },
		{ "Tooltip", "If true, the iMSTK logger will be written to." },
	};
#endif
	void Z_Construct_UClass_UImstkSettings_Statics::NewProp_bLoggerActive_SetBit(void* Obj)
	{
		((UImstkSettings*)Obj)->bLoggerActive = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UImstkSettings_Statics::NewProp_bLoggerActive = { "bLoggerActive", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UImstkSettings), &Z_Construct_UClass_UImstkSettings_Statics::NewProp_bLoggerActive_SetBit, METADATA_PARAMS(Z_Construct_UClass_UImstkSettings_Statics::NewProp_bLoggerActive_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UImstkSettings_Statics::NewProp_bLoggerActive_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UImstkSettings_Statics::NewProp_bDebuggingActive_MetaData[] = {
		{ "Category", "Debugging" },
		{ "ModuleRelativePath", "Public/ImstkSettings.h" },
		{ "Tooltip", "If true, debugging information will be provided in Unreal." },
	};
#endif
	void Z_Construct_UClass_UImstkSettings_Statics::NewProp_bDebuggingActive_SetBit(void* Obj)
	{
		((UImstkSettings*)Obj)->bDebuggingActive = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UImstkSettings_Statics::NewProp_bDebuggingActive = { "bDebuggingActive", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UImstkSettings), &Z_Construct_UClass_UImstkSettings_Statics::NewProp_bDebuggingActive_SetBit, METADATA_PARAMS(Z_Construct_UClass_UImstkSettings_Statics::NewProp_bDebuggingActive_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UImstkSettings_Statics::NewProp_bDebuggingActive_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UImstkSettings_Statics::NewProp_bWriteTaskGraph_MetaData[] = {
		{ "Category", "Debugging" },
		{ "ModuleRelativePath", "Public/ImstkSettings.h" },
		{ "Tooltip", "If true, generates a task graph of the imstk scene." },
	};
#endif
	void Z_Construct_UClass_UImstkSettings_Statics::NewProp_bWriteTaskGraph_SetBit(void* Obj)
	{
		((UImstkSettings*)Obj)->bWriteTaskGraph = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UImstkSettings_Statics::NewProp_bWriteTaskGraph = { "bWriteTaskGraph", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UImstkSettings), &Z_Construct_UClass_UImstkSettings_Statics::NewProp_bWriteTaskGraph_SetBit, METADATA_PARAMS(Z_Construct_UClass_UImstkSettings_Statics::NewProp_bWriteTaskGraph_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UImstkSettings_Statics::NewProp_bWriteTaskGraph_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UImstkSettings_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UImstkSettings_Statics::NewProp_bUseRealtime,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UImstkSettings_Statics::NewProp_bLoggerActive,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UImstkSettings_Statics::NewProp_bDebuggingActive,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UImstkSettings_Statics::NewProp_bWriteTaskGraph,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UImstkSettings_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UImstkSettings>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UImstkSettings_Statics::ClassParams = {
		&UImstkSettings::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UImstkSettings_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UImstkSettings_Statics::PropPointers),
		0,
		0x001000A6u,
		METADATA_PARAMS(Z_Construct_UClass_UImstkSettings_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UImstkSettings_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UImstkSettings()
	{
		if (!Z_Registration_Info_UClass_UImstkSettings.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UImstkSettings.OuterSingleton, Z_Construct_UClass_UImstkSettings_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UImstkSettings.OuterSingleton;
	}
	template<> IMSTK_API UClass* StaticClass<UImstkSettings>()
	{
		return UImstkSettings::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UImstkSettings);
	struct Z_CompiledInDeferFile_FID_HostProject_Plugins_Imstk_Source_Imstk_Public_ImstkSettings_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_Imstk_Source_Imstk_Public_ImstkSettings_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UImstkSettings, UImstkSettings::StaticClass, TEXT("UImstkSettings"), &Z_Registration_Info_UClass_UImstkSettings, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UImstkSettings), 996625117U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_Imstk_Source_Imstk_Public_ImstkSettings_h_3439154510(TEXT("/Script/Imstk"),
		Z_CompiledInDeferFile_FID_HostProject_Plugins_Imstk_Source_Imstk_Public_ImstkSettings_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HostProject_Plugins_Imstk_Source_Imstk_Public_ImstkSettings_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
