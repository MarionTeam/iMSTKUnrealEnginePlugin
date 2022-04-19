// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Imstk/Public/ImstkSettings.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
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
	UClass* Z_Construct_UClass_UImstkSettings_NoRegister()
	{
		return UImstkSettings::StaticClass();
	}
	struct Z_Construct_UClass_UImstkSettings_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bUseRealtime_MetaData[];
#endif
		static void NewProp_bUseRealtime_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bUseRealtime;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bLoggerActive_MetaData[];
#endif
		static void NewProp_bLoggerActive_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bLoggerActive;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bDebuggingActive_MetaData[];
#endif
		static void NewProp_bDebuggingActive_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bDebuggingActive;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bWriteTaskGraph_MetaData[];
#endif
		static void NewProp_bWriteTaskGraph_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bWriteTaskGraph;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UImstkSettings_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UDeveloperSettings,
		(UObject* (*)())Z_Construct_UPackage__Script_Imstk,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UImstkSettings_Statics::Class_MetaDataParams[] = {
		{ "Category", "Holds settings for iMSTK" },
		{ "Comment", "/** \\file ImstkSettings.h\n *  \\brief Provides settings in editor for imstk\n *  \\details Has settings for imstk logging and debugging messages in unreal\n */" },
		{ "IncludePath", "ImstkSettings.h" },
		{ "ModuleRelativePath", "Public/ImstkSettings.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
		{ "ToolTip", "\\file ImstkSettings.h\n\\brief Provides settings in editor for imstk\n\\details Has settings for imstk logging and debugging messages in unreal" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UImstkSettings_Statics::NewProp_bUseRealtime_MetaData[] = {
		{ "Category", "General" },
		{ "ModuleRelativePath", "Public/ImstkSettings.h" },
		{ "Tooltip", "If true, deformable models will update their timesteps to line up with Unreal." },
	};
#endif
	void Z_Construct_UClass_UImstkSettings_Statics::NewProp_bUseRealtime_SetBit(void* Obj)
	{
		((UImstkSettings*)Obj)->bUseRealtime = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UImstkSettings_Statics::NewProp_bUseRealtime = { "bUseRealtime", nullptr, (EPropertyFlags)0x0010000000004001, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UImstkSettings), &Z_Construct_UClass_UImstkSettings_Statics::NewProp_bUseRealtime_SetBit, METADATA_PARAMS(Z_Construct_UClass_UImstkSettings_Statics::NewProp_bUseRealtime_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UImstkSettings_Statics::NewProp_bUseRealtime_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UImstkSettings_Statics::NewProp_bLoggerActive_MetaData[] = {
		{ "Category", "Debugging" },
		{ "ModuleRelativePath", "Public/ImstkSettings.h" },
		{ "Tooltip", "If true, the iMSTK logger will be written to." },
	};
#endif
	void Z_Construct_UClass_UImstkSettings_Statics::NewProp_bLoggerActive_SetBit(void* Obj)
	{
		((UImstkSettings*)Obj)->bLoggerActive = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UImstkSettings_Statics::NewProp_bLoggerActive = { "bLoggerActive", nullptr, (EPropertyFlags)0x0010000000004001, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UImstkSettings), &Z_Construct_UClass_UImstkSettings_Statics::NewProp_bLoggerActive_SetBit, METADATA_PARAMS(Z_Construct_UClass_UImstkSettings_Statics::NewProp_bLoggerActive_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UImstkSettings_Statics::NewProp_bLoggerActive_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UImstkSettings_Statics::NewProp_bDebuggingActive_MetaData[] = {
		{ "Category", "Debugging" },
		{ "ModuleRelativePath", "Public/ImstkSettings.h" },
		{ "Tooltip", "If true, debugging information will be provided in Unreal." },
	};
#endif
	void Z_Construct_UClass_UImstkSettings_Statics::NewProp_bDebuggingActive_SetBit(void* Obj)
	{
		((UImstkSettings*)Obj)->bDebuggingActive = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UImstkSettings_Statics::NewProp_bDebuggingActive = { "bDebuggingActive", nullptr, (EPropertyFlags)0x0010000000004001, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UImstkSettings), &Z_Construct_UClass_UImstkSettings_Statics::NewProp_bDebuggingActive_SetBit, METADATA_PARAMS(Z_Construct_UClass_UImstkSettings_Statics::NewProp_bDebuggingActive_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UImstkSettings_Statics::NewProp_bDebuggingActive_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UImstkSettings_Statics::NewProp_bWriteTaskGraph_MetaData[] = {
		{ "Category", "Debugging" },
		{ "ModuleRelativePath", "Public/ImstkSettings.h" },
		{ "Tooltip", "If true, generates a task graph of the imstk scene." },
	};
#endif
	void Z_Construct_UClass_UImstkSettings_Statics::NewProp_bWriteTaskGraph_SetBit(void* Obj)
	{
		((UImstkSettings*)Obj)->bWriteTaskGraph = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UImstkSettings_Statics::NewProp_bWriteTaskGraph = { "bWriteTaskGraph", nullptr, (EPropertyFlags)0x0010000000004001, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UImstkSettings), &Z_Construct_UClass_UImstkSettings_Statics::NewProp_bWriteTaskGraph_SetBit, METADATA_PARAMS(Z_Construct_UClass_UImstkSettings_Statics::NewProp_bWriteTaskGraph_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UImstkSettings_Statics::NewProp_bWriteTaskGraph_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UImstkSettings_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UImstkSettings_Statics::NewProp_bUseRealtime,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UImstkSettings_Statics::NewProp_bLoggerActive,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UImstkSettings_Statics::NewProp_bDebuggingActive,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UImstkSettings_Statics::NewProp_bWriteTaskGraph,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UImstkSettings_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UImstkSettings>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UImstkSettings_Statics::ClassParams = {
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
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UImstkSettings_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UImstkSettings, 1738763701);
	template<> IMSTK_API UClass* StaticClass<UImstkSettings>()
	{
		return UImstkSettings::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UImstkSettings(Z_Construct_UClass_UImstkSettings, &UImstkSettings::StaticClass, TEXT("/Script/Imstk"), TEXT("UImstkSettings"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UImstkSettings);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
