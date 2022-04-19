// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Imstk/Public/TetrahedralMeshAsset.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeTetrahedralMeshAsset() {}
// Cross Module References
	IMSTK_API UClass* Z_Construct_UClass_UTetrahedralMeshAsset_NoRegister();
	IMSTK_API UClass* Z_Construct_UClass_UTetrahedralMeshAsset();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	UPackage* Z_Construct_UPackage__Script_Imstk();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
// End Cross Module References
	void UTetrahedralMeshAsset::StaticRegisterNativesUTetrahedralMeshAsset()
	{
	}
	UClass* Z_Construct_UClass_UTetrahedralMeshAsset_NoRegister()
	{
		return UTetrahedralMeshAsset::StaticClass();
	}
	struct Z_Construct_UClass_UTetrahedralMeshAsset_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Vertices_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Vertices_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_Vertices;
		static const UE4CodeGen_Private::FUInt32PropertyParams NewProp_Indices_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Indices_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_Indices;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UTetrahedralMeshAsset_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_Imstk,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UTetrahedralMeshAsset_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/** \\file TetrahedralMeshAsset.h\n *  \\brief Stores the vertices and indices of a tetrahedral mesh and outputs an imstk tetrahedral mesh\n *  \\details \n */" },
		{ "IncludePath", "TetrahedralMeshAsset.h" },
		{ "ModuleRelativePath", "Public/TetrahedralMeshAsset.h" },
		{ "ToolTip", "\\file TetrahedralMeshAsset.h\n\\brief Stores the vertices and indices of a tetrahedral mesh and outputs an imstk tetrahedral mesh\n\\details" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_UTetrahedralMeshAsset_Statics::NewProp_Vertices_Inner = { "Vertices", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UTetrahedralMeshAsset_Statics::NewProp_Vertices_MetaData[] = {
		{ "Category", "General" },
		{ "Comment", "//protected:\n" },
		{ "ModuleRelativePath", "Public/TetrahedralMeshAsset.h" },
		{ "ToolTip", "protected:" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UTetrahedralMeshAsset_Statics::NewProp_Vertices = { "Vertices", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UTetrahedralMeshAsset, Vertices), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_UTetrahedralMeshAsset_Statics::NewProp_Vertices_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UTetrahedralMeshAsset_Statics::NewProp_Vertices_MetaData)) };
	const UE4CodeGen_Private::FUInt32PropertyParams Z_Construct_UClass_UTetrahedralMeshAsset_Statics::NewProp_Indices_Inner = { "Indices", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::UInt32, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UTetrahedralMeshAsset_Statics::NewProp_Indices_MetaData[] = {
		{ "Category", "General" },
		{ "ModuleRelativePath", "Public/TetrahedralMeshAsset.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UTetrahedralMeshAsset_Statics::NewProp_Indices = { "Indices", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UTetrahedralMeshAsset, Indices), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_UTetrahedralMeshAsset_Statics::NewProp_Indices_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UTetrahedralMeshAsset_Statics::NewProp_Indices_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UTetrahedralMeshAsset_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UTetrahedralMeshAsset_Statics::NewProp_Vertices_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UTetrahedralMeshAsset_Statics::NewProp_Vertices,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UTetrahedralMeshAsset_Statics::NewProp_Indices_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UTetrahedralMeshAsset_Statics::NewProp_Indices,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UTetrahedralMeshAsset_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UTetrahedralMeshAsset>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UTetrahedralMeshAsset_Statics::ClassParams = {
		&UTetrahedralMeshAsset::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UTetrahedralMeshAsset_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UTetrahedralMeshAsset_Statics::PropPointers),
		0,
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UTetrahedralMeshAsset_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UTetrahedralMeshAsset_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UTetrahedralMeshAsset()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UTetrahedralMeshAsset_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UTetrahedralMeshAsset, 3840345250);
	template<> IMSTK_API UClass* StaticClass<UTetrahedralMeshAsset>()
	{
		return UTetrahedralMeshAsset::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UTetrahedralMeshAsset(Z_Construct_UClass_UTetrahedralMeshAsset, &UTetrahedralMeshAsset::StaticClass, TEXT("/Script/Imstk"), TEXT("UTetrahedralMeshAsset"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UTetrahedralMeshAsset);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
