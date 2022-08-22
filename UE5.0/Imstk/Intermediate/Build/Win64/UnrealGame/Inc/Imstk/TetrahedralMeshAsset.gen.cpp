// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Imstk/Public/TetrahedralMeshAsset.h"
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
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UTetrahedralMeshAsset);
	UClass* Z_Construct_UClass_UTetrahedralMeshAsset_NoRegister()
	{
		return UTetrahedralMeshAsset::StaticClass();
	}
	struct Z_Construct_UClass_UTetrahedralMeshAsset_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Vertices_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Vertices_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_Vertices;
		static const UECodeGen_Private::FUInt32PropertyParams NewProp_Indices_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Indices_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_Indices;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UTetrahedralMeshAsset_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_Imstk,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UTetrahedralMeshAsset_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/** \\file TetrahedralMeshAsset.h\n *  \\brief Stores the vertices and indices of a tetrahedral mesh and outputs an imstk tetrahedral mesh\n *  \\details \n */" },
		{ "IncludePath", "TetrahedralMeshAsset.h" },
		{ "ModuleRelativePath", "Public/TetrahedralMeshAsset.h" },
		{ "ToolTip", "\\file TetrahedralMeshAsset.h\n\\brief Stores the vertices and indices of a tetrahedral mesh and outputs an imstk tetrahedral mesh\n\\details" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UTetrahedralMeshAsset_Statics::NewProp_Vertices_Inner = { "Vertices", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UTetrahedralMeshAsset_Statics::NewProp_Vertices_MetaData[] = {
		{ "Category", "General" },
		{ "Comment", "// Vertex positions of the tetrahedral mesh\n" },
		{ "ModuleRelativePath", "Public/TetrahedralMeshAsset.h" },
		{ "ToolTip", "Vertex positions of the tetrahedral mesh" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UTetrahedralMeshAsset_Statics::NewProp_Vertices = { "Vertices", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UTetrahedralMeshAsset, Vertices), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_UTetrahedralMeshAsset_Statics::NewProp_Vertices_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UTetrahedralMeshAsset_Statics::NewProp_Vertices_MetaData)) };
	const UECodeGen_Private::FUInt32PropertyParams Z_Construct_UClass_UTetrahedralMeshAsset_Statics::NewProp_Indices_Inner = { "Indices", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::UInt32, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UTetrahedralMeshAsset_Statics::NewProp_Indices_MetaData[] = {
		{ "Category", "General" },
		{ "Comment", "// Tetrehedra indices of the mesh\n" },
		{ "ModuleRelativePath", "Public/TetrahedralMeshAsset.h" },
		{ "ToolTip", "Tetrehedra indices of the mesh" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UTetrahedralMeshAsset_Statics::NewProp_Indices = { "Indices", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UTetrahedralMeshAsset, Indices), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_UTetrahedralMeshAsset_Statics::NewProp_Indices_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UTetrahedralMeshAsset_Statics::NewProp_Indices_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UTetrahedralMeshAsset_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UTetrahedralMeshAsset_Statics::NewProp_Vertices_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UTetrahedralMeshAsset_Statics::NewProp_Vertices,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UTetrahedralMeshAsset_Statics::NewProp_Indices_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UTetrahedralMeshAsset_Statics::NewProp_Indices,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UTetrahedralMeshAsset_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UTetrahedralMeshAsset>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UTetrahedralMeshAsset_Statics::ClassParams = {
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
		if (!Z_Registration_Info_UClass_UTetrahedralMeshAsset.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UTetrahedralMeshAsset.OuterSingleton, Z_Construct_UClass_UTetrahedralMeshAsset_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UTetrahedralMeshAsset.OuterSingleton;
	}
	template<> IMSTK_API UClass* StaticClass<UTetrahedralMeshAsset>()
	{
		return UTetrahedralMeshAsset::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UTetrahedralMeshAsset);
	struct Z_CompiledInDeferFile_FID_HostProject_Plugins_Imstk_Source_Imstk_Public_TetrahedralMeshAsset_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_Imstk_Source_Imstk_Public_TetrahedralMeshAsset_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UTetrahedralMeshAsset, UTetrahedralMeshAsset::StaticClass, TEXT("UTetrahedralMeshAsset"), &Z_Registration_Info_UClass_UTetrahedralMeshAsset, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UTetrahedralMeshAsset), 4261535019U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_Imstk_Source_Imstk_Public_TetrahedralMeshAsset_h_2973543499(TEXT("/Script/Imstk"),
		Z_CompiledInDeferFile_FID_HostProject_Plugins_Imstk_Source_Imstk_Public_TetrahedralMeshAsset_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HostProject_Plugins_Imstk_Source_Imstk_Public_TetrahedralMeshAsset_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
