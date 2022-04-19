// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Imstk/Public/ControllerInteraction.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
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
	UClass* Z_Construct_UClass_UControllerInteraction_NoRegister()
	{
		return UControllerInteraction::StaticClass();
	}
	struct Z_Construct_UClass_UControllerInteraction_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Controller_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Controller;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UControllerInteraction_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UCollisionInteraction,
		(UObject* (*)())Z_Construct_UPackage__Script_Imstk,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UControllerInteraction_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/** \\file ControllerInteraction.h\n *  \\brief Class used to create and represent interaction between controller and object\n *  \\details  Can be created in blueprint to make the imstk collision interaction and initialize using the imstk subsystem. Requires model1 and controller to be set. Collision type may be left as auto automatically determine the collision type.\n */" },
		{ "IncludePath", "ControllerInteraction.h" },
		{ "ModuleRelativePath", "Public/ControllerInteraction.h" },
		{ "ToolTip", "\\file ControllerInteraction.h\n\\brief Class used to create and represent interaction between controller and object\n\\details  Can be created in blueprint to make the imstk collision interaction and initialize using the imstk subsystem. Requires model1 and controller to be set. Collision type may be left as auto automatically determine the collision type." },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UControllerInteraction_Statics::NewProp_Controller_MetaData[] = {
		{ "Category", "Collision Interaction" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/ControllerInteraction.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UControllerInteraction_Statics::NewProp_Controller = { "Controller", nullptr, (EPropertyFlags)0x00100000000a000d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UControllerInteraction, Controller), Z_Construct_UClass_UImstkController_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UControllerInteraction_Statics::NewProp_Controller_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UControllerInteraction_Statics::NewProp_Controller_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UControllerInteraction_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UControllerInteraction_Statics::NewProp_Controller,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UControllerInteraction_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UControllerInteraction>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UControllerInteraction_Statics::ClassParams = {
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
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UControllerInteraction_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UControllerInteraction, 479892236);
	template<> IMSTK_API UClass* StaticClass<UControllerInteraction>()
	{
		return UControllerInteraction::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UControllerInteraction(Z_Construct_UClass_UControllerInteraction, &UControllerInteraction::StaticClass, TEXT("/Script/Imstk"), TEXT("UControllerInteraction"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UControllerInteraction);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
