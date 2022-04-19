// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Imstk/Public/ImstkInteraction.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
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
	UClass* Z_Construct_UClass_UImstkInteraction_NoRegister()
	{
		return UImstkInteraction::StaticClass();
	}
	struct Z_Construct_UClass_UImstkInteraction_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UImstkInteraction_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_Imstk,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UImstkInteraction_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/** \\file ImstkInteraction.h\n *  \\brief Abstract class for Imstk interactions\n *  \\details Provides a function for initializing the interaction. Can be overridden in child classes to create the interaction in imstk\n */" },
		{ "IncludePath", "ImstkInteraction.h" },
		{ "ModuleRelativePath", "Public/ImstkInteraction.h" },
		{ "ToolTip", "\\file ImstkInteraction.h\n\\brief Abstract class for Imstk interactions\n\\details Provides a function for initializing the interaction. Can be overridden in child classes to create the interaction in imstk" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UImstkInteraction_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UImstkInteraction>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UImstkInteraction_Statics::ClassParams = {
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
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UImstkInteraction_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UImstkInteraction, 3139213944);
	template<> IMSTK_API UClass* StaticClass<UImstkInteraction>()
	{
		return UImstkInteraction::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UImstkInteraction(Z_Construct_UClass_UImstkInteraction, &UImstkInteraction::StaticClass, TEXT("/Script/Imstk"), TEXT("UImstkInteraction"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UImstkInteraction);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
