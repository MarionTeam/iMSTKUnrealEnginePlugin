// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Imstk/Public/PBDThread.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePBDThread() {}
// Cross Module References
	IMSTK_API UClass* Z_Construct_UClass_UPBDThread_NoRegister();
	IMSTK_API UClass* Z_Construct_UClass_UPBDThread();
	IMSTK_API UClass* Z_Construct_UClass_UDeformableModel();
	UPackage* Z_Construct_UPackage__Script_Imstk();
	ENGINE_API UClass* Z_Construct_UClass_USplineComponent_NoRegister();
// End Cross Module References
	void UPBDThread::StaticRegisterNativesUPBDThread()
	{
	}
	UClass* Z_Construct_UClass_UPBDThread_NoRegister()
	{
		return UPBDThread::StaticClass();
	}
	struct Z_Construct_UClass_UPBDThread_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bUseBendConstraint_MetaData[];
#endif
		static void NewProp_bUseBendConstraint_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bUseBendConstraint;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_BendStiffness_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_BendStiffness;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SplineComponent_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_SplineComponent;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UPBDThread_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UDeformableModel,
		(UObject* (*)())Z_Construct_UPackage__Script_Imstk,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPBDThread_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Imstk" },
		{ "Comment", "/**\n *   \n */" },
		{ "HideCategories", "General|Geometry" },
		{ "IncludePath", "PBDThread.h" },
		{ "ModuleRelativePath", "Public/PBDThread.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPBDThread_Statics::NewProp_bUseBendConstraint_MetaData[] = {
		{ "Category", "Constraints" },
		{ "ModuleRelativePath", "Public/PBDThread.h" },
	};
#endif
	void Z_Construct_UClass_UPBDThread_Statics::NewProp_bUseBendConstraint_SetBit(void* Obj)
	{
		((UPBDThread*)Obj)->bUseBendConstraint = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UPBDThread_Statics::NewProp_bUseBendConstraint = { "bUseBendConstraint", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UPBDThread), &Z_Construct_UClass_UPBDThread_Statics::NewProp_bUseBendConstraint_SetBit, METADATA_PARAMS(Z_Construct_UClass_UPBDThread_Statics::NewProp_bUseBendConstraint_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UPBDThread_Statics::NewProp_bUseBendConstraint_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPBDThread_Statics::NewProp_BendStiffness_MetaData[] = {
		{ "Category", "Constraints" },
		{ "EditCondition", "bUseBendConstraint" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/PBDThread.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UPBDThread_Statics::NewProp_BendStiffness = { "BendStiffness", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UPBDThread, BendStiffness), METADATA_PARAMS(Z_Construct_UClass_UPBDThread_Statics::NewProp_BendStiffness_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UPBDThread_Statics::NewProp_BendStiffness_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPBDThread_Statics::NewProp_SplineComponent_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/PBDThread.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UPBDThread_Statics::NewProp_SplineComponent = { "SplineComponent", nullptr, (EPropertyFlags)0x0010000000080008, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UPBDThread, SplineComponent), Z_Construct_UClass_USplineComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UPBDThread_Statics::NewProp_SplineComponent_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UPBDThread_Statics::NewProp_SplineComponent_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UPBDThread_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPBDThread_Statics::NewProp_bUseBendConstraint,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPBDThread_Statics::NewProp_BendStiffness,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPBDThread_Statics::NewProp_SplineComponent,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UPBDThread_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPBDThread>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UPBDThread_Statics::ClassParams = {
		&UPBDThread::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UPBDThread_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UPBDThread_Statics::PropPointers),
		0,
		0x00B000A4u,
		METADATA_PARAMS(Z_Construct_UClass_UPBDThread_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UPBDThread_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UPBDThread()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UPBDThread_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UPBDThread, 635155940);
	template<> IMSTK_API UClass* StaticClass<UPBDThread>()
	{
		return UPBDThread::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UPBDThread(Z_Construct_UClass_UPBDThread, &UPBDThread::StaticClass, TEXT("/Script/Imstk"), TEXT("UPBDThread"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UPBDThread);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
