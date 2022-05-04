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
	DEFINE_FUNCTION(UImstkBehaviour::execIsInitialized)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->IsInitialized();
		P_NATIVE_END;
	}
	void UImstkBehaviour::StaticRegisterNativesUImstkBehaviour()
	{
		UClass* Class = UImstkBehaviour::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "IsInitialized", &UImstkBehaviour::execIsInitialized },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UImstkBehaviour_IsInitialized_Statics
	{
		struct ImstkBehaviour_eventIsInitialized_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UImstkBehaviour_IsInitialized_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((ImstkBehaviour_eventIsInitialized_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UImstkBehaviour_IsInitialized_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(ImstkBehaviour_eventIsInitialized_Parms), &Z_Construct_UFunction_UImstkBehaviour_IsInitialized_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UImstkBehaviour_IsInitialized_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UImstkBehaviour_IsInitialized_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UImstkBehaviour_IsInitialized_Statics::Function_MetaDataParams[] = {
		{ "Category", "Imstk" },
		{ "ModuleRelativePath", "Public/ImstkBehaviour.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UImstkBehaviour_IsInitialized_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UImstkBehaviour, nullptr, "IsInitialized", nullptr, nullptr, sizeof(Z_Construct_UFunction_UImstkBehaviour_IsInitialized_Statics::ImstkBehaviour_eventIsInitialized_Parms), Z_Construct_UFunction_UImstkBehaviour_IsInitialized_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UImstkBehaviour_IsInitialized_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UImstkBehaviour_IsInitialized_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UImstkBehaviour_IsInitialized_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UImstkBehaviour_IsInitialized()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UImstkBehaviour_IsInitialized_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UImstkBehaviour);
	UClass* Z_Construct_UClass_UImstkBehaviour_NoRegister()
	{
		return UImstkBehaviour::StaticClass();
	}
	struct Z_Construct_UClass_UImstkBehaviour_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
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
	const FClassFunctionLinkInfo Z_Construct_UClass_UImstkBehaviour_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UImstkBehaviour_IsInitialized, "IsInitialized" }, // 2313281206
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
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
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
		{ Z_Construct_UClass_UImstkBehaviour, UImstkBehaviour::StaticClass, TEXT("UImstkBehaviour"), &Z_Registration_Info_UClass_UImstkBehaviour, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UImstkBehaviour), 1437815233U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_Imstk_Source_Imstk_Public_ImstkBehaviour_h_3984964698(TEXT("/Script/Imstk"),
		Z_CompiledInDeferFile_FID_HostProject_Plugins_Imstk_Source_Imstk_Public_ImstkBehaviour_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HostProject_Plugins_Imstk_Source_Imstk_Public_ImstkBehaviour_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
