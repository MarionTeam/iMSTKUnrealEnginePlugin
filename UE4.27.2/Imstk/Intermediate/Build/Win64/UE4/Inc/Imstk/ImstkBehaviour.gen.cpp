// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Imstk/Public/ImstkBehaviour.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
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
	UClass* Z_Construct_UClass_UImstkBehaviour_NoRegister()
	{
		return UImstkBehaviour::StaticClass();
	}
	struct Z_Construct_UClass_UImstkBehaviour_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UImstkBehaviour_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UActorComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_Imstk,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UImstkBehaviour_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/** \\file ImstkBehaviour.h\n *  \\brief Abstract class for all Imstk Actor Components that need to be initialized\n *  \\details Classes that use this include dynamical models, interactions, etc.\n */" },
		{ "IncludePath", "ImstkBehaviour.h" },
		{ "ModuleRelativePath", "Public/ImstkBehaviour.h" },
		{ "ToolTip", "\\file ImstkBehaviour.h\n\\brief Abstract class for all Imstk Actor Components that need to be initialized\n\\details Classes that use this include dynamical models, interactions, etc." },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UImstkBehaviour_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UImstkBehaviour>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UImstkBehaviour_Statics::ClassParams = {
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
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UImstkBehaviour_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UImstkBehaviour, 4036368932);
	template<> IMSTK_API UClass* StaticClass<UImstkBehaviour>()
	{
		return UImstkBehaviour::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UImstkBehaviour(Z_Construct_UClass_UImstkBehaviour, &UImstkBehaviour::StaticClass, TEXT("/Script/Imstk"), TEXT("UImstkBehaviour"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UImstkBehaviour);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
