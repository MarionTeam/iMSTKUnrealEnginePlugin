// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Imstk/Public/DynamicalModel.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeDynamicalModel() {}
// Cross Module References
	IMSTK_API UClass* Z_Construct_UClass_UDynamicalModel_NoRegister();
	IMSTK_API UClass* Z_Construct_UClass_UDynamicalModel();
	IMSTK_API UClass* Z_Construct_UClass_UImstkBehaviour();
	UPackage* Z_Construct_UPackage__Script_Imstk();
	IMSTK_API UScriptStruct* Z_Construct_UScriptStruct_FGeometryFilter();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	IMSTK_API UClass* Z_Construct_UClass_UImstkSubsystem_NoRegister();
// End Cross Module References
	void UDynamicalModel::StaticRegisterNativesUDynamicalModel()
	{
	}
	UClass* Z_Construct_UClass_UDynamicalModel_NoRegister()
	{
		return UDynamicalModel::StaticClass();
	}
	struct Z_Construct_UClass_UDynamicalModel_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_GeomFilter_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_GeomFilter;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Owner_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Owner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SubsystemInstance_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_SubsystemInstance;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bPrintPositionInformation_MetaData[];
#endif
		static void NewProp_bPrintPositionInformation_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bPrintPositionInformation;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UDynamicalModel_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UImstkBehaviour,
		(UObject* (*)())Z_Construct_UPackage__Script_Imstk,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDynamicalModel_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/** \\file DynamicalModel.h\n *  \\brief Abstract class to model any object that is added to the Imstk scene\n *  \\details Contains a geometry filter to convert between Unreal and Imstk objects\n */" },
		{ "IncludePath", "DynamicalModel.h" },
		{ "ModuleRelativePath", "Public/DynamicalModel.h" },
		{ "ToolTip", "\\file DynamicalModel.h\n\\brief Abstract class to model any object that is added to the Imstk scene\n\\details Contains a geometry filter to convert between Unreal and Imstk objects" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDynamicalModel_Statics::NewProp_GeomFilter_MetaData[] = {
		{ "Category", "General|Geometry" },
		{ "ModuleRelativePath", "Public/DynamicalModel.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_UDynamicalModel_Statics::NewProp_GeomFilter = { "GeomFilter", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UDynamicalModel, GeomFilter), Z_Construct_UScriptStruct_FGeometryFilter, METADATA_PARAMS(Z_Construct_UClass_UDynamicalModel_Statics::NewProp_GeomFilter_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UDynamicalModel_Statics::NewProp_GeomFilter_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDynamicalModel_Statics::NewProp_Owner_MetaData[] = {
		{ "Comment", "// References to the owning object and imstk subsystem\n" },
		{ "ModuleRelativePath", "Public/DynamicalModel.h" },
		{ "ToolTip", "References to the owning object and imstk subsystem" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UDynamicalModel_Statics::NewProp_Owner = { "Owner", nullptr, (EPropertyFlags)0x0020080000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UDynamicalModel, Owner), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UDynamicalModel_Statics::NewProp_Owner_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UDynamicalModel_Statics::NewProp_Owner_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDynamicalModel_Statics::NewProp_SubsystemInstance_MetaData[] = {
		{ "ModuleRelativePath", "Public/DynamicalModel.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UDynamicalModel_Statics::NewProp_SubsystemInstance = { "SubsystemInstance", nullptr, (EPropertyFlags)0x0020080000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UDynamicalModel, SubsystemInstance), Z_Construct_UClass_UImstkSubsystem_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UDynamicalModel_Statics::NewProp_SubsystemInstance_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UDynamicalModel_Statics::NewProp_SubsystemInstance_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDynamicalModel_Statics::NewProp_bPrintPositionInformation_MetaData[] = {
		{ "Category", "General" },
		{ "ModuleRelativePath", "Public/DynamicalModel.h" },
	};
#endif
	void Z_Construct_UClass_UDynamicalModel_Statics::NewProp_bPrintPositionInformation_SetBit(void* Obj)
	{
		((UDynamicalModel*)Obj)->bPrintPositionInformation = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UDynamicalModel_Statics::NewProp_bPrintPositionInformation = { "bPrintPositionInformation", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UDynamicalModel), &Z_Construct_UClass_UDynamicalModel_Statics::NewProp_bPrintPositionInformation_SetBit, METADATA_PARAMS(Z_Construct_UClass_UDynamicalModel_Statics::NewProp_bPrintPositionInformation_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UDynamicalModel_Statics::NewProp_bPrintPositionInformation_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UDynamicalModel_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDynamicalModel_Statics::NewProp_GeomFilter,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDynamicalModel_Statics::NewProp_Owner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDynamicalModel_Statics::NewProp_SubsystemInstance,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDynamicalModel_Statics::NewProp_bPrintPositionInformation,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UDynamicalModel_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDynamicalModel>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UDynamicalModel_Statics::ClassParams = {
		&UDynamicalModel::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UDynamicalModel_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UDynamicalModel_Statics::PropPointers),
		0,
		0x00B000A5u,
		METADATA_PARAMS(Z_Construct_UClass_UDynamicalModel_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UDynamicalModel_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UDynamicalModel()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UDynamicalModel_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UDynamicalModel, 1372572191);
	template<> IMSTK_API UClass* StaticClass<UDynamicalModel>()
	{
		return UDynamicalModel::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UDynamicalModel(Z_Construct_UClass_UDynamicalModel, &UDynamicalModel::StaticClass, TEXT("/Script/Imstk"), TEXT("UDynamicalModel"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UDynamicalModel);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
