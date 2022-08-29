// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Imstk/Public/GeometryFilter.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGeometryFilter() {}
// Cross Module References
	IMSTK_API UEnum* Z_Construct_UEnum_Imstk_EGeometryType();
	UPackage* Z_Construct_UPackage__Script_Imstk();
	IMSTK_API UScriptStruct* Z_Construct_UScriptStruct_FMeshDataStruct();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	IMSTK_API UScriptStruct* Z_Construct_UScriptStruct_FGeometryTypeStruct();
	IMSTK_API UScriptStruct* Z_Construct_UScriptStruct_FSphereGeomStruct();
	IMSTK_API UScriptStruct* Z_Construct_UScriptStruct_FSurfaceMeshGeomStruct();
	IMSTK_API UScriptStruct* Z_Construct_UScriptStruct_FCapsuleGeomStruct();
	IMSTK_API UScriptStruct* Z_Construct_UScriptStruct_FCylinderGeomStruct();
	IMSTK_API UScriptStruct* Z_Construct_UScriptStruct_FPointSetGeomStruct();
	IMSTK_API UScriptStruct* Z_Construct_UScriptStruct_FOrientedBoxGeomStruct();
	IMSTK_API UScriptStruct* Z_Construct_UScriptStruct_FPlaneGeomStruct();
	IMSTK_API UScriptStruct* Z_Construct_UScriptStruct_FLineMeshGeomStruct();
	IMSTK_API UScriptStruct* Z_Construct_UScriptStruct_FGeometryFilter();
// End Cross Module References
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_EGeometryType;
	static UEnum* EGeometryType_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_EGeometryType.OuterSingleton)
		{
			Z_Registration_Info_UEnum_EGeometryType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_Imstk_EGeometryType, Z_Construct_UPackage__Script_Imstk(), TEXT("EGeometryType"));
		}
		return Z_Registration_Info_UEnum_EGeometryType.OuterSingleton;
	}
	template<> IMSTK_API UEnum* StaticEnum<EGeometryType>()
	{
		return EGeometryType_StaticEnum();
	}
	struct Z_Construct_UEnum_Imstk_EGeometryType_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_Imstk_EGeometryType_Statics::Enumerators[] = {
		{ "Sphere", (int64)Sphere },
		{ "SurfaceMesh", (int64)SurfaceMesh },
		{ "Capsule", (int64)Capsule },
		{ "Cylinder", (int64)Cylinder },
		{ "PointSet", (int64)PointSet },
		{ "OrientedBox", (int64)OrientedBox },
		{ "Plane", (int64)Plane },
		{ "LineMesh", (int64)LineMesh },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_Imstk_EGeometryType_Statics::Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Capsule.Name", "Capsule" },
		{ "Comment", "/** \\file GeometryFilter.h\n *  \\brief Defines the structs and enum used in the geometry filter\n *  \\details\n */// Enum that defines the geometry types provided by imstk\n" },
		{ "Cylinder.Name", "Cylinder" },
		{ "LineMesh.Name", "LineMesh" },
		{ "ModuleRelativePath", "Public/GeometryFilter.h" },
		{ "OrientedBox.Name", "OrientedBox" },
		{ "Plane.Name", "Plane" },
		{ "PointSet.Name", "PointSet" },
		{ "Sphere.Name", "Sphere" },
		{ "SurfaceMesh.Name", "SurfaceMesh" },
		{ "ToolTip", "\\file GeometryFilter.h\n\\brief Defines the structs and enum used in the geometry filter\n\\details\n// Enum that defines the geometry types provided by imstk" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_Imstk_EGeometryType_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_Imstk,
		nullptr,
		"EGeometryType",
		"EGeometryType",
		Z_Construct_UEnum_Imstk_EGeometryType_Statics::Enumerators,
		UE_ARRAY_COUNT(Z_Construct_UEnum_Imstk_EGeometryType_Statics::Enumerators),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::Regular,
		METADATA_PARAMS(Z_Construct_UEnum_Imstk_EGeometryType_Statics::Enum_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UEnum_Imstk_EGeometryType_Statics::Enum_MetaDataParams))
	};
	UEnum* Z_Construct_UEnum_Imstk_EGeometryType()
	{
		if (!Z_Registration_Info_UEnum_EGeometryType.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EGeometryType.InnerSingleton, Z_Construct_UEnum_Imstk_EGeometryType_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_EGeometryType.InnerSingleton;
	}
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_MeshDataStruct;
class UScriptStruct* FMeshDataStruct::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_MeshDataStruct.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_MeshDataStruct.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FMeshDataStruct, Z_Construct_UPackage__Script_Imstk(), TEXT("MeshDataStruct"));
	}
	return Z_Registration_Info_UScriptStruct_MeshDataStruct.OuterSingleton;
}
template<> IMSTK_API UScriptStruct* StaticStruct<FMeshDataStruct>()
{
	return FMeshDataStruct::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FMeshDataStruct_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
		static const UECodeGen_Private::FStructPropertyParams NewProp_Verts_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Verts_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_Verts;
		static const UECodeGen_Private::FIntPropertyParams NewProp_Indices_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Indices_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_Indices;
		static const UECodeGen_Private::FStructPropertyParams NewProp_Normals_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Normals_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_Normals;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FMeshDataStruct_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/GeometryFilter.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FMeshDataStruct_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FMeshDataStruct>();
	}
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FMeshDataStruct_Statics::NewProp_Verts_Inner = { "Verts", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FMeshDataStruct_Statics::NewProp_Verts_MetaData[] = {
		{ "Category", "General" },
		{ "ModuleRelativePath", "Public/GeometryFilter.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FMeshDataStruct_Statics::NewProp_Verts = { "Verts", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FMeshDataStruct, Verts), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UScriptStruct_FMeshDataStruct_Statics::NewProp_Verts_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMeshDataStruct_Statics::NewProp_Verts_MetaData)) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FMeshDataStruct_Statics::NewProp_Indices_Inner = { "Indices", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FMeshDataStruct_Statics::NewProp_Indices_MetaData[] = {
		{ "Category", "General" },
		{ "ModuleRelativePath", "Public/GeometryFilter.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FMeshDataStruct_Statics::NewProp_Indices = { "Indices", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FMeshDataStruct, Indices), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UScriptStruct_FMeshDataStruct_Statics::NewProp_Indices_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMeshDataStruct_Statics::NewProp_Indices_MetaData)) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FMeshDataStruct_Statics::NewProp_Normals_Inner = { "Normals", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FMeshDataStruct_Statics::NewProp_Normals_MetaData[] = {
		{ "Category", "General" },
		{ "ModuleRelativePath", "Public/GeometryFilter.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FMeshDataStruct_Statics::NewProp_Normals = { "Normals", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FMeshDataStruct, Normals), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UScriptStruct_FMeshDataStruct_Statics::NewProp_Normals_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMeshDataStruct_Statics::NewProp_Normals_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FMeshDataStruct_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMeshDataStruct_Statics::NewProp_Verts_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMeshDataStruct_Statics::NewProp_Verts,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMeshDataStruct_Statics::NewProp_Indices_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMeshDataStruct_Statics::NewProp_Indices,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMeshDataStruct_Statics::NewProp_Normals_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMeshDataStruct_Statics::NewProp_Normals,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FMeshDataStruct_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_Imstk,
		nullptr,
		&NewStructOps,
		"MeshDataStruct",
		sizeof(FMeshDataStruct),
		alignof(FMeshDataStruct),
		Z_Construct_UScriptStruct_FMeshDataStruct_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMeshDataStruct_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FMeshDataStruct_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMeshDataStruct_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FMeshDataStruct()
	{
		if (!Z_Registration_Info_UScriptStruct_MeshDataStruct.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_MeshDataStruct.InnerSingleton, Z_Construct_UScriptStruct_FMeshDataStruct_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_MeshDataStruct.InnerSingleton;
	}
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_GeometryTypeStruct;
class UScriptStruct* FGeometryTypeStruct::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_GeometryTypeStruct.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_GeometryTypeStruct.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FGeometryTypeStruct, Z_Construct_UPackage__Script_Imstk(), TEXT("GeometryTypeStruct"));
	}
	return Z_Registration_Info_UScriptStruct_GeometryTypeStruct.OuterSingleton;
}
template<> IMSTK_API UScriptStruct* StaticStruct<FGeometryTypeStruct>()
{
	return FGeometryTypeStruct::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FGeometryTypeStruct_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FGeometryTypeStruct_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/GeometryFilter.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FGeometryTypeStruct_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FGeometryTypeStruct>();
	}
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FGeometryTypeStruct_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_Imstk,
		nullptr,
		&NewStructOps,
		"GeometryTypeStruct",
		sizeof(FGeometryTypeStruct),
		alignof(FGeometryTypeStruct),
		nullptr,
		0,
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FGeometryTypeStruct_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGeometryTypeStruct_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FGeometryTypeStruct()
	{
		if (!Z_Registration_Info_UScriptStruct_GeometryTypeStruct.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_GeometryTypeStruct.InnerSingleton, Z_Construct_UScriptStruct_FGeometryTypeStruct_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_GeometryTypeStruct.InnerSingleton;
	}

static_assert(std::is_polymorphic<FSphereGeomStruct>() == std::is_polymorphic<FGeometryTypeStruct>(), "USTRUCT FSphereGeomStruct cannot be polymorphic unless super FGeometryTypeStruct is polymorphic");

	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_SphereGeomStruct;
class UScriptStruct* FSphereGeomStruct::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_SphereGeomStruct.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_SphereGeomStruct.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FSphereGeomStruct, Z_Construct_UPackage__Script_Imstk(), TEXT("SphereGeomStruct"));
	}
	return Z_Registration_Info_UScriptStruct_SphereGeomStruct.OuterSingleton;
}
template<> IMSTK_API UScriptStruct* StaticStruct<FSphereGeomStruct>()
{
	return FSphereGeomStruct::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FSphereGeomStruct_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Radius_MetaData[];
#endif
		static const UECodeGen_Private::FDoublePropertyParams NewProp_Radius;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_GeometryOffset_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_GeometryOffset;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSphereGeomStruct_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/GeometryFilter.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FSphereGeomStruct_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FSphereGeomStruct>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSphereGeomStruct_Statics::NewProp_Radius_MetaData[] = {
		{ "Category", "General" },
		{ "ClampMin", "0.01" },
		{ "ModuleRelativePath", "Public/GeometryFilter.h" },
	};
#endif
	const UECodeGen_Private::FDoublePropertyParams Z_Construct_UScriptStruct_FSphereGeomStruct_Statics::NewProp_Radius = { "Radius", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Double, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSphereGeomStruct, Radius), METADATA_PARAMS(Z_Construct_UScriptStruct_FSphereGeomStruct_Statics::NewProp_Radius_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSphereGeomStruct_Statics::NewProp_Radius_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSphereGeomStruct_Statics::NewProp_GeometryOffset_MetaData[] = {
		{ "Category", "General" },
		{ "ModuleRelativePath", "Public/GeometryFilter.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FSphereGeomStruct_Statics::NewProp_GeometryOffset = { "GeometryOffset", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSphereGeomStruct, GeometryOffset), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UScriptStruct_FSphereGeomStruct_Statics::NewProp_GeometryOffset_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSphereGeomStruct_Statics::NewProp_GeometryOffset_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FSphereGeomStruct_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSphereGeomStruct_Statics::NewProp_Radius,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSphereGeomStruct_Statics::NewProp_GeometryOffset,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FSphereGeomStruct_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_Imstk,
		Z_Construct_UScriptStruct_FGeometryTypeStruct,
		&NewStructOps,
		"SphereGeomStruct",
		sizeof(FSphereGeomStruct),
		alignof(FSphereGeomStruct),
		Z_Construct_UScriptStruct_FSphereGeomStruct_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSphereGeomStruct_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FSphereGeomStruct_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSphereGeomStruct_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FSphereGeomStruct()
	{
		if (!Z_Registration_Info_UScriptStruct_SphereGeomStruct.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_SphereGeomStruct.InnerSingleton, Z_Construct_UScriptStruct_FSphereGeomStruct_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_SphereGeomStruct.InnerSingleton;
	}

static_assert(std::is_polymorphic<FSurfaceMeshGeomStruct>() == std::is_polymorphic<FGeometryTypeStruct>(), "USTRUCT FSurfaceMeshGeomStruct cannot be polymorphic unless super FGeometryTypeStruct is polymorphic");

	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_SurfaceMeshGeomStruct;
class UScriptStruct* FSurfaceMeshGeomStruct::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_SurfaceMeshGeomStruct.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_SurfaceMeshGeomStruct.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FSurfaceMeshGeomStruct, Z_Construct_UPackage__Script_Imstk(), TEXT("SurfaceMeshGeomStruct"));
	}
	return Z_Registration_Info_UScriptStruct_SurfaceMeshGeomStruct.OuterSingleton;
}
template<> IMSTK_API UScriptStruct* StaticStruct<FSurfaceMeshGeomStruct>()
{
	return FSurfaceMeshGeomStruct::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FSurfaceMeshGeomStruct_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bFlipNormals_MetaData[];
#endif
		static void NewProp_bFlipNormals_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bFlipNormals;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSurfaceMeshGeomStruct_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/GeometryFilter.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FSurfaceMeshGeomStruct_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FSurfaceMeshGeomStruct>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSurfaceMeshGeomStruct_Statics::NewProp_bFlipNormals_MetaData[] = {
		{ "Category", "General" },
		{ "ModuleRelativePath", "Public/GeometryFilter.h" },
	};
#endif
	void Z_Construct_UScriptStruct_FSurfaceMeshGeomStruct_Statics::NewProp_bFlipNormals_SetBit(void* Obj)
	{
		((FSurfaceMeshGeomStruct*)Obj)->bFlipNormals = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FSurfaceMeshGeomStruct_Statics::NewProp_bFlipNormals = { "bFlipNormals", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(FSurfaceMeshGeomStruct), &Z_Construct_UScriptStruct_FSurfaceMeshGeomStruct_Statics::NewProp_bFlipNormals_SetBit, METADATA_PARAMS(Z_Construct_UScriptStruct_FSurfaceMeshGeomStruct_Statics::NewProp_bFlipNormals_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSurfaceMeshGeomStruct_Statics::NewProp_bFlipNormals_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FSurfaceMeshGeomStruct_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSurfaceMeshGeomStruct_Statics::NewProp_bFlipNormals,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FSurfaceMeshGeomStruct_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_Imstk,
		Z_Construct_UScriptStruct_FGeometryTypeStruct,
		&NewStructOps,
		"SurfaceMeshGeomStruct",
		sizeof(FSurfaceMeshGeomStruct),
		alignof(FSurfaceMeshGeomStruct),
		Z_Construct_UScriptStruct_FSurfaceMeshGeomStruct_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSurfaceMeshGeomStruct_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FSurfaceMeshGeomStruct_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSurfaceMeshGeomStruct_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FSurfaceMeshGeomStruct()
	{
		if (!Z_Registration_Info_UScriptStruct_SurfaceMeshGeomStruct.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_SurfaceMeshGeomStruct.InnerSingleton, Z_Construct_UScriptStruct_FSurfaceMeshGeomStruct_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_SurfaceMeshGeomStruct.InnerSingleton;
	}

static_assert(std::is_polymorphic<FCapsuleGeomStruct>() == std::is_polymorphic<FGeometryTypeStruct>(), "USTRUCT FCapsuleGeomStruct cannot be polymorphic unless super FGeometryTypeStruct is polymorphic");

	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_CapsuleGeomStruct;
class UScriptStruct* FCapsuleGeomStruct::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_CapsuleGeomStruct.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_CapsuleGeomStruct.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FCapsuleGeomStruct, Z_Construct_UPackage__Script_Imstk(), TEXT("CapsuleGeomStruct"));
	}
	return Z_Registration_Info_UScriptStruct_CapsuleGeomStruct.OuterSingleton;
}
template<> IMSTK_API UScriptStruct* StaticStruct<FCapsuleGeomStruct>()
{
	return FCapsuleGeomStruct::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FCapsuleGeomStruct_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Radius_MetaData[];
#endif
		static const UECodeGen_Private::FDoublePropertyParams NewProp_Radius;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Length_MetaData[];
#endif
		static const UECodeGen_Private::FDoublePropertyParams NewProp_Length;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_GeometryOffset_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_GeometryOffset;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FCapsuleGeomStruct_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/GeometryFilter.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FCapsuleGeomStruct_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FCapsuleGeomStruct>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FCapsuleGeomStruct_Statics::NewProp_Radius_MetaData[] = {
		{ "Category", "General" },
		{ "ClampMin", "0.01" },
		{ "ModuleRelativePath", "Public/GeometryFilter.h" },
	};
#endif
	const UECodeGen_Private::FDoublePropertyParams Z_Construct_UScriptStruct_FCapsuleGeomStruct_Statics::NewProp_Radius = { "Radius", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Double, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FCapsuleGeomStruct, Radius), METADATA_PARAMS(Z_Construct_UScriptStruct_FCapsuleGeomStruct_Statics::NewProp_Radius_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCapsuleGeomStruct_Statics::NewProp_Radius_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FCapsuleGeomStruct_Statics::NewProp_Length_MetaData[] = {
		{ "Category", "General" },
		{ "ClampMin", "0.01" },
		{ "ModuleRelativePath", "Public/GeometryFilter.h" },
	};
#endif
	const UECodeGen_Private::FDoublePropertyParams Z_Construct_UScriptStruct_FCapsuleGeomStruct_Statics::NewProp_Length = { "Length", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Double, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FCapsuleGeomStruct, Length), METADATA_PARAMS(Z_Construct_UScriptStruct_FCapsuleGeomStruct_Statics::NewProp_Length_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCapsuleGeomStruct_Statics::NewProp_Length_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FCapsuleGeomStruct_Statics::NewProp_GeometryOffset_MetaData[] = {
		{ "Category", "General" },
		{ "ModuleRelativePath", "Public/GeometryFilter.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FCapsuleGeomStruct_Statics::NewProp_GeometryOffset = { "GeometryOffset", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FCapsuleGeomStruct, GeometryOffset), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UScriptStruct_FCapsuleGeomStruct_Statics::NewProp_GeometryOffset_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCapsuleGeomStruct_Statics::NewProp_GeometryOffset_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FCapsuleGeomStruct_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCapsuleGeomStruct_Statics::NewProp_Radius,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCapsuleGeomStruct_Statics::NewProp_Length,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCapsuleGeomStruct_Statics::NewProp_GeometryOffset,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FCapsuleGeomStruct_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_Imstk,
		Z_Construct_UScriptStruct_FGeometryTypeStruct,
		&NewStructOps,
		"CapsuleGeomStruct",
		sizeof(FCapsuleGeomStruct),
		alignof(FCapsuleGeomStruct),
		Z_Construct_UScriptStruct_FCapsuleGeomStruct_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCapsuleGeomStruct_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FCapsuleGeomStruct_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCapsuleGeomStruct_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FCapsuleGeomStruct()
	{
		if (!Z_Registration_Info_UScriptStruct_CapsuleGeomStruct.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_CapsuleGeomStruct.InnerSingleton, Z_Construct_UScriptStruct_FCapsuleGeomStruct_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_CapsuleGeomStruct.InnerSingleton;
	}

static_assert(std::is_polymorphic<FCylinderGeomStruct>() == std::is_polymorphic<FGeometryTypeStruct>(), "USTRUCT FCylinderGeomStruct cannot be polymorphic unless super FGeometryTypeStruct is polymorphic");

	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_CylinderGeomStruct;
class UScriptStruct* FCylinderGeomStruct::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_CylinderGeomStruct.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_CylinderGeomStruct.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FCylinderGeomStruct, Z_Construct_UPackage__Script_Imstk(), TEXT("CylinderGeomStruct"));
	}
	return Z_Registration_Info_UScriptStruct_CylinderGeomStruct.OuterSingleton;
}
template<> IMSTK_API UScriptStruct* StaticStruct<FCylinderGeomStruct>()
{
	return FCylinderGeomStruct::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FCylinderGeomStruct_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Radius_MetaData[];
#endif
		static const UECodeGen_Private::FDoublePropertyParams NewProp_Radius;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Length_MetaData[];
#endif
		static const UECodeGen_Private::FDoublePropertyParams NewProp_Length;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_GeometryOffset_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_GeometryOffset;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FCylinderGeomStruct_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/GeometryFilter.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FCylinderGeomStruct_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FCylinderGeomStruct>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FCylinderGeomStruct_Statics::NewProp_Radius_MetaData[] = {
		{ "Category", "General" },
		{ "ClampMin", "0.01" },
		{ "ModuleRelativePath", "Public/GeometryFilter.h" },
	};
#endif
	const UECodeGen_Private::FDoublePropertyParams Z_Construct_UScriptStruct_FCylinderGeomStruct_Statics::NewProp_Radius = { "Radius", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Double, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FCylinderGeomStruct, Radius), METADATA_PARAMS(Z_Construct_UScriptStruct_FCylinderGeomStruct_Statics::NewProp_Radius_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCylinderGeomStruct_Statics::NewProp_Radius_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FCylinderGeomStruct_Statics::NewProp_Length_MetaData[] = {
		{ "Category", "General" },
		{ "ClampMin", "0.01" },
		{ "ModuleRelativePath", "Public/GeometryFilter.h" },
	};
#endif
	const UECodeGen_Private::FDoublePropertyParams Z_Construct_UScriptStruct_FCylinderGeomStruct_Statics::NewProp_Length = { "Length", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Double, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FCylinderGeomStruct, Length), METADATA_PARAMS(Z_Construct_UScriptStruct_FCylinderGeomStruct_Statics::NewProp_Length_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCylinderGeomStruct_Statics::NewProp_Length_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FCylinderGeomStruct_Statics::NewProp_GeometryOffset_MetaData[] = {
		{ "Category", "General" },
		{ "ModuleRelativePath", "Public/GeometryFilter.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FCylinderGeomStruct_Statics::NewProp_GeometryOffset = { "GeometryOffset", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FCylinderGeomStruct, GeometryOffset), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UScriptStruct_FCylinderGeomStruct_Statics::NewProp_GeometryOffset_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCylinderGeomStruct_Statics::NewProp_GeometryOffset_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FCylinderGeomStruct_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCylinderGeomStruct_Statics::NewProp_Radius,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCylinderGeomStruct_Statics::NewProp_Length,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCylinderGeomStruct_Statics::NewProp_GeometryOffset,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FCylinderGeomStruct_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_Imstk,
		Z_Construct_UScriptStruct_FGeometryTypeStruct,
		&NewStructOps,
		"CylinderGeomStruct",
		sizeof(FCylinderGeomStruct),
		alignof(FCylinderGeomStruct),
		Z_Construct_UScriptStruct_FCylinderGeomStruct_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCylinderGeomStruct_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FCylinderGeomStruct_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCylinderGeomStruct_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FCylinderGeomStruct()
	{
		if (!Z_Registration_Info_UScriptStruct_CylinderGeomStruct.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_CylinderGeomStruct.InnerSingleton, Z_Construct_UScriptStruct_FCylinderGeomStruct_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_CylinderGeomStruct.InnerSingleton;
	}

static_assert(std::is_polymorphic<FPointSetGeomStruct>() == std::is_polymorphic<FGeometryTypeStruct>(), "USTRUCT FPointSetGeomStruct cannot be polymorphic unless super FGeometryTypeStruct is polymorphic");

	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_PointSetGeomStruct;
class UScriptStruct* FPointSetGeomStruct::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_PointSetGeomStruct.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_PointSetGeomStruct.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FPointSetGeomStruct, Z_Construct_UPackage__Script_Imstk(), TEXT("PointSetGeomStruct"));
	}
	return Z_Registration_Info_UScriptStruct_PointSetGeomStruct.OuterSingleton;
}
template<> IMSTK_API UScriptStruct* StaticStruct<FPointSetGeomStruct>()
{
	return FPointSetGeomStruct::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FPointSetGeomStruct_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPointSetGeomStruct_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/GeometryFilter.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FPointSetGeomStruct_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FPointSetGeomStruct>();
	}
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FPointSetGeomStruct_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_Imstk,
		Z_Construct_UScriptStruct_FGeometryTypeStruct,
		&NewStructOps,
		"PointSetGeomStruct",
		sizeof(FPointSetGeomStruct),
		alignof(FPointSetGeomStruct),
		nullptr,
		0,
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FPointSetGeomStruct_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPointSetGeomStruct_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FPointSetGeomStruct()
	{
		if (!Z_Registration_Info_UScriptStruct_PointSetGeomStruct.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_PointSetGeomStruct.InnerSingleton, Z_Construct_UScriptStruct_FPointSetGeomStruct_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_PointSetGeomStruct.InnerSingleton;
	}

static_assert(std::is_polymorphic<FOrientedBoxGeomStruct>() == std::is_polymorphic<FGeometryTypeStruct>(), "USTRUCT FOrientedBoxGeomStruct cannot be polymorphic unless super FGeometryTypeStruct is polymorphic");

	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_OrientedBoxGeomStruct;
class UScriptStruct* FOrientedBoxGeomStruct::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_OrientedBoxGeomStruct.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_OrientedBoxGeomStruct.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FOrientedBoxGeomStruct, Z_Construct_UPackage__Script_Imstk(), TEXT("OrientedBoxGeomStruct"));
	}
	return Z_Registration_Info_UScriptStruct_OrientedBoxGeomStruct.OuterSingleton;
}
template<> IMSTK_API UScriptStruct* StaticStruct<FOrientedBoxGeomStruct>()
{
	return FOrientedBoxGeomStruct::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FOrientedBoxGeomStruct_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Extents_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Extents;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FOrientedBoxGeomStruct_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/GeometryFilter.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FOrientedBoxGeomStruct_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FOrientedBoxGeomStruct>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FOrientedBoxGeomStruct_Statics::NewProp_Extents_MetaData[] = {
		{ "Category", "General" },
		{ "ModuleRelativePath", "Public/GeometryFilter.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FOrientedBoxGeomStruct_Statics::NewProp_Extents = { "Extents", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FOrientedBoxGeomStruct, Extents), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UScriptStruct_FOrientedBoxGeomStruct_Statics::NewProp_Extents_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOrientedBoxGeomStruct_Statics::NewProp_Extents_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FOrientedBoxGeomStruct_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOrientedBoxGeomStruct_Statics::NewProp_Extents,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FOrientedBoxGeomStruct_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_Imstk,
		Z_Construct_UScriptStruct_FGeometryTypeStruct,
		&NewStructOps,
		"OrientedBoxGeomStruct",
		sizeof(FOrientedBoxGeomStruct),
		alignof(FOrientedBoxGeomStruct),
		Z_Construct_UScriptStruct_FOrientedBoxGeomStruct_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOrientedBoxGeomStruct_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FOrientedBoxGeomStruct_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOrientedBoxGeomStruct_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FOrientedBoxGeomStruct()
	{
		if (!Z_Registration_Info_UScriptStruct_OrientedBoxGeomStruct.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_OrientedBoxGeomStruct.InnerSingleton, Z_Construct_UScriptStruct_FOrientedBoxGeomStruct_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_OrientedBoxGeomStruct.InnerSingleton;
	}

static_assert(std::is_polymorphic<FPlaneGeomStruct>() == std::is_polymorphic<FGeometryTypeStruct>(), "USTRUCT FPlaneGeomStruct cannot be polymorphic unless super FGeometryTypeStruct is polymorphic");

	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_PlaneGeomStruct;
class UScriptStruct* FPlaneGeomStruct::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_PlaneGeomStruct.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_PlaneGeomStruct.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FPlaneGeomStruct, Z_Construct_UPackage__Script_Imstk(), TEXT("PlaneGeomStruct"));
	}
	return Z_Registration_Info_UScriptStruct_PlaneGeomStruct.OuterSingleton;
}
template<> IMSTK_API UScriptStruct* StaticStruct<FPlaneGeomStruct>()
{
	return FPlaneGeomStruct::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FPlaneGeomStruct_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Normal_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Normal;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPlaneGeomStruct_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/GeometryFilter.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FPlaneGeomStruct_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FPlaneGeomStruct>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPlaneGeomStruct_Statics::NewProp_Normal_MetaData[] = {
		{ "Category", "General" },
		{ "ModuleRelativePath", "Public/GeometryFilter.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FPlaneGeomStruct_Statics::NewProp_Normal = { "Normal", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FPlaneGeomStruct, Normal), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UScriptStruct_FPlaneGeomStruct_Statics::NewProp_Normal_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPlaneGeomStruct_Statics::NewProp_Normal_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FPlaneGeomStruct_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPlaneGeomStruct_Statics::NewProp_Normal,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FPlaneGeomStruct_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_Imstk,
		Z_Construct_UScriptStruct_FGeometryTypeStruct,
		&NewStructOps,
		"PlaneGeomStruct",
		sizeof(FPlaneGeomStruct),
		alignof(FPlaneGeomStruct),
		Z_Construct_UScriptStruct_FPlaneGeomStruct_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPlaneGeomStruct_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FPlaneGeomStruct_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPlaneGeomStruct_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FPlaneGeomStruct()
	{
		if (!Z_Registration_Info_UScriptStruct_PlaneGeomStruct.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_PlaneGeomStruct.InnerSingleton, Z_Construct_UScriptStruct_FPlaneGeomStruct_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_PlaneGeomStruct.InnerSingleton;
	}

static_assert(std::is_polymorphic<FLineMeshGeomStruct>() == std::is_polymorphic<FGeometryTypeStruct>(), "USTRUCT FLineMeshGeomStruct cannot be polymorphic unless super FGeometryTypeStruct is polymorphic");

	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_LineMeshGeomStruct;
class UScriptStruct* FLineMeshGeomStruct::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_LineMeshGeomStruct.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_LineMeshGeomStruct.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FLineMeshGeomStruct, Z_Construct_UPackage__Script_Imstk(), TEXT("LineMeshGeomStruct"));
	}
	return Z_Registration_Info_UScriptStruct_LineMeshGeomStruct.OuterSingleton;
}
template<> IMSTK_API UScriptStruct* StaticStruct<FLineMeshGeomStruct>()
{
	return FLineMeshGeomStruct::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FLineMeshGeomStruct_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
		static const UECodeGen_Private::FStructPropertyParams NewProp_Vertices_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Vertices_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_Vertices;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FLineMeshGeomStruct_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/GeometryFilter.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FLineMeshGeomStruct_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FLineMeshGeomStruct>();
	}
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FLineMeshGeomStruct_Statics::NewProp_Vertices_Inner = { "Vertices", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FLineMeshGeomStruct_Statics::NewProp_Vertices_MetaData[] = {
		{ "Category", "General" },
		{ "ModuleRelativePath", "Public/GeometryFilter.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FLineMeshGeomStruct_Statics::NewProp_Vertices = { "Vertices", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FLineMeshGeomStruct, Vertices), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UScriptStruct_FLineMeshGeomStruct_Statics::NewProp_Vertices_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FLineMeshGeomStruct_Statics::NewProp_Vertices_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FLineMeshGeomStruct_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FLineMeshGeomStruct_Statics::NewProp_Vertices_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FLineMeshGeomStruct_Statics::NewProp_Vertices,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FLineMeshGeomStruct_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_Imstk,
		Z_Construct_UScriptStruct_FGeometryTypeStruct,
		&NewStructOps,
		"LineMeshGeomStruct",
		sizeof(FLineMeshGeomStruct),
		alignof(FLineMeshGeomStruct),
		Z_Construct_UScriptStruct_FLineMeshGeomStruct_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FLineMeshGeomStruct_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FLineMeshGeomStruct_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FLineMeshGeomStruct_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FLineMeshGeomStruct()
	{
		if (!Z_Registration_Info_UScriptStruct_LineMeshGeomStruct.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_LineMeshGeomStruct.InnerSingleton, Z_Construct_UScriptStruct_FLineMeshGeomStruct_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_LineMeshGeomStruct.InnerSingleton;
	}
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_GeometryFilter;
class UScriptStruct* FGeometryFilter::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_GeometryFilter.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_GeometryFilter.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FGeometryFilter, Z_Construct_UPackage__Script_Imstk(), TEXT("GeometryFilter"));
	}
	return Z_Registration_Info_UScriptStruct_GeometryFilter.OuterSingleton;
}
template<> IMSTK_API UScriptStruct* StaticStruct<FGeometryFilter>()
{
	return FGeometryFilter::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FGeometryFilter_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_GeomType_MetaData[];
#endif
		static const UECodeGen_Private::FBytePropertyParams NewProp_GeomType;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SphereStruct_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_SphereStruct;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MeshStruct_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_MeshStruct;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CapsuleStruct_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_CapsuleStruct;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CylinderStruct_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_CylinderStruct;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_PointSetStruct_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_PointSetStruct;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OrientedBoxStruct_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_OrientedBoxStruct;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_PlaneStruct_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_PlaneStruct;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_LineMeshStruct_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_LineMeshStruct;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FGeometryFilter_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/GeometryFilter.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FGeometryFilter_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FGeometryFilter>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FGeometryFilter_Statics::NewProp_GeomType_MetaData[] = {
		{ "Category", "General" },
		{ "ModuleRelativePath", "Public/GeometryFilter.h" },
	};
#endif
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FGeometryFilter_Statics::NewProp_GeomType = { "GeomType", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FGeometryFilter, GeomType), Z_Construct_UEnum_Imstk_EGeometryType, METADATA_PARAMS(Z_Construct_UScriptStruct_FGeometryFilter_Statics::NewProp_GeomType_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGeometryFilter_Statics::NewProp_GeomType_MetaData)) }; // 86236413
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FGeometryFilter_Statics::NewProp_SphereStruct_MetaData[] = {
		{ "Category", "General" },
		{ "EditCondition", "GeomType == EGeometryType::Sphere" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/GeometryFilter.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FGeometryFilter_Statics::NewProp_SphereStruct = { "SphereStruct", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FGeometryFilter, SphereStruct), Z_Construct_UScriptStruct_FSphereGeomStruct, METADATA_PARAMS(Z_Construct_UScriptStruct_FGeometryFilter_Statics::NewProp_SphereStruct_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGeometryFilter_Statics::NewProp_SphereStruct_MetaData)) }; // 3879012486
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FGeometryFilter_Statics::NewProp_MeshStruct_MetaData[] = {
		{ "Category", "General" },
		{ "EditCondition", "GeomType == EGeometryType::SurfaceMesh" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/GeometryFilter.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FGeometryFilter_Statics::NewProp_MeshStruct = { "MeshStruct", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FGeometryFilter, MeshStruct), Z_Construct_UScriptStruct_FSurfaceMeshGeomStruct, METADATA_PARAMS(Z_Construct_UScriptStruct_FGeometryFilter_Statics::NewProp_MeshStruct_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGeometryFilter_Statics::NewProp_MeshStruct_MetaData)) }; // 17117586
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FGeometryFilter_Statics::NewProp_CapsuleStruct_MetaData[] = {
		{ "Category", "General" },
		{ "EditCondition", "GeomType == EGeometryType::Capsule" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/GeometryFilter.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FGeometryFilter_Statics::NewProp_CapsuleStruct = { "CapsuleStruct", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FGeometryFilter, CapsuleStruct), Z_Construct_UScriptStruct_FCapsuleGeomStruct, METADATA_PARAMS(Z_Construct_UScriptStruct_FGeometryFilter_Statics::NewProp_CapsuleStruct_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGeometryFilter_Statics::NewProp_CapsuleStruct_MetaData)) }; // 2861642361
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FGeometryFilter_Statics::NewProp_CylinderStruct_MetaData[] = {
		{ "Category", "General" },
		{ "EditCondition", "GeomType == EGeometryType::Cylinder" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/GeometryFilter.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FGeometryFilter_Statics::NewProp_CylinderStruct = { "CylinderStruct", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FGeometryFilter, CylinderStruct), Z_Construct_UScriptStruct_FCylinderGeomStruct, METADATA_PARAMS(Z_Construct_UScriptStruct_FGeometryFilter_Statics::NewProp_CylinderStruct_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGeometryFilter_Statics::NewProp_CylinderStruct_MetaData)) }; // 3341961288
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FGeometryFilter_Statics::NewProp_PointSetStruct_MetaData[] = {
		{ "Category", "General" },
		{ "EditCondition", "GeomType == EGeometryType::PointSet" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/GeometryFilter.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FGeometryFilter_Statics::NewProp_PointSetStruct = { "PointSetStruct", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FGeometryFilter, PointSetStruct), Z_Construct_UScriptStruct_FPointSetGeomStruct, METADATA_PARAMS(Z_Construct_UScriptStruct_FGeometryFilter_Statics::NewProp_PointSetStruct_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGeometryFilter_Statics::NewProp_PointSetStruct_MetaData)) }; // 3919939220
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FGeometryFilter_Statics::NewProp_OrientedBoxStruct_MetaData[] = {
		{ "Category", "General" },
		{ "EditCondition", "GeomType == EGeometryType::OrientedBox" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/GeometryFilter.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FGeometryFilter_Statics::NewProp_OrientedBoxStruct = { "OrientedBoxStruct", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FGeometryFilter, OrientedBoxStruct), Z_Construct_UScriptStruct_FOrientedBoxGeomStruct, METADATA_PARAMS(Z_Construct_UScriptStruct_FGeometryFilter_Statics::NewProp_OrientedBoxStruct_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGeometryFilter_Statics::NewProp_OrientedBoxStruct_MetaData)) }; // 1045054720
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FGeometryFilter_Statics::NewProp_PlaneStruct_MetaData[] = {
		{ "Category", "General" },
		{ "EditCondition", "GeomType == EGeometryType::Plane" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/GeometryFilter.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FGeometryFilter_Statics::NewProp_PlaneStruct = { "PlaneStruct", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FGeometryFilter, PlaneStruct), Z_Construct_UScriptStruct_FPlaneGeomStruct, METADATA_PARAMS(Z_Construct_UScriptStruct_FGeometryFilter_Statics::NewProp_PlaneStruct_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGeometryFilter_Statics::NewProp_PlaneStruct_MetaData)) }; // 1030131400
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FGeometryFilter_Statics::NewProp_LineMeshStruct_MetaData[] = {
		{ "Category", "General" },
		{ "EditCondition", "GeomType == EGeometryType::LineMesh" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/GeometryFilter.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FGeometryFilter_Statics::NewProp_LineMeshStruct = { "LineMeshStruct", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FGeometryFilter, LineMeshStruct), Z_Construct_UScriptStruct_FLineMeshGeomStruct, METADATA_PARAMS(Z_Construct_UScriptStruct_FGeometryFilter_Statics::NewProp_LineMeshStruct_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGeometryFilter_Statics::NewProp_LineMeshStruct_MetaData)) }; // 471779539
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FGeometryFilter_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGeometryFilter_Statics::NewProp_GeomType,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGeometryFilter_Statics::NewProp_SphereStruct,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGeometryFilter_Statics::NewProp_MeshStruct,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGeometryFilter_Statics::NewProp_CapsuleStruct,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGeometryFilter_Statics::NewProp_CylinderStruct,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGeometryFilter_Statics::NewProp_PointSetStruct,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGeometryFilter_Statics::NewProp_OrientedBoxStruct,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGeometryFilter_Statics::NewProp_PlaneStruct,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGeometryFilter_Statics::NewProp_LineMeshStruct,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FGeometryFilter_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_Imstk,
		nullptr,
		&NewStructOps,
		"GeometryFilter",
		sizeof(FGeometryFilter),
		alignof(FGeometryFilter),
		Z_Construct_UScriptStruct_FGeometryFilter_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGeometryFilter_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FGeometryFilter_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGeometryFilter_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FGeometryFilter()
	{
		if (!Z_Registration_Info_UScriptStruct_GeometryFilter.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_GeometryFilter.InnerSingleton, Z_Construct_UScriptStruct_FGeometryFilter_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_GeometryFilter.InnerSingleton;
	}
	struct Z_CompiledInDeferFile_FID_HostProject_Plugins_Imstk_Source_Imstk_Public_GeometryFilter_h_Statics
	{
		static const FEnumRegisterCompiledInInfo EnumInfo[];
		static const FStructRegisterCompiledInInfo ScriptStructInfo[];
	};
	const FEnumRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_Imstk_Source_Imstk_Public_GeometryFilter_h_Statics::EnumInfo[] = {
		{ EGeometryType_StaticEnum, TEXT("EGeometryType"), &Z_Registration_Info_UEnum_EGeometryType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 86236413U) },
	};
	const FStructRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_Imstk_Source_Imstk_Public_GeometryFilter_h_Statics::ScriptStructInfo[] = {
		{ FMeshDataStruct::StaticStruct, Z_Construct_UScriptStruct_FMeshDataStruct_Statics::NewStructOps, TEXT("MeshDataStruct"), &Z_Registration_Info_UScriptStruct_MeshDataStruct, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FMeshDataStruct), 3288538142U) },
		{ FGeometryTypeStruct::StaticStruct, Z_Construct_UScriptStruct_FGeometryTypeStruct_Statics::NewStructOps, TEXT("GeometryTypeStruct"), &Z_Registration_Info_UScriptStruct_GeometryTypeStruct, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FGeometryTypeStruct), 2946192539U) },
		{ FSphereGeomStruct::StaticStruct, Z_Construct_UScriptStruct_FSphereGeomStruct_Statics::NewStructOps, TEXT("SphereGeomStruct"), &Z_Registration_Info_UScriptStruct_SphereGeomStruct, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FSphereGeomStruct), 3879012486U) },
		{ FSurfaceMeshGeomStruct::StaticStruct, Z_Construct_UScriptStruct_FSurfaceMeshGeomStruct_Statics::NewStructOps, TEXT("SurfaceMeshGeomStruct"), &Z_Registration_Info_UScriptStruct_SurfaceMeshGeomStruct, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FSurfaceMeshGeomStruct), 17117586U) },
		{ FCapsuleGeomStruct::StaticStruct, Z_Construct_UScriptStruct_FCapsuleGeomStruct_Statics::NewStructOps, TEXT("CapsuleGeomStruct"), &Z_Registration_Info_UScriptStruct_CapsuleGeomStruct, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FCapsuleGeomStruct), 2861642361U) },
		{ FCylinderGeomStruct::StaticStruct, Z_Construct_UScriptStruct_FCylinderGeomStruct_Statics::NewStructOps, TEXT("CylinderGeomStruct"), &Z_Registration_Info_UScriptStruct_CylinderGeomStruct, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FCylinderGeomStruct), 3341961288U) },
		{ FPointSetGeomStruct::StaticStruct, Z_Construct_UScriptStruct_FPointSetGeomStruct_Statics::NewStructOps, TEXT("PointSetGeomStruct"), &Z_Registration_Info_UScriptStruct_PointSetGeomStruct, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FPointSetGeomStruct), 3919939220U) },
		{ FOrientedBoxGeomStruct::StaticStruct, Z_Construct_UScriptStruct_FOrientedBoxGeomStruct_Statics::NewStructOps, TEXT("OrientedBoxGeomStruct"), &Z_Registration_Info_UScriptStruct_OrientedBoxGeomStruct, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FOrientedBoxGeomStruct), 1045054720U) },
		{ FPlaneGeomStruct::StaticStruct, Z_Construct_UScriptStruct_FPlaneGeomStruct_Statics::NewStructOps, TEXT("PlaneGeomStruct"), &Z_Registration_Info_UScriptStruct_PlaneGeomStruct, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FPlaneGeomStruct), 1030131400U) },
		{ FLineMeshGeomStruct::StaticStruct, Z_Construct_UScriptStruct_FLineMeshGeomStruct_Statics::NewStructOps, TEXT("LineMeshGeomStruct"), &Z_Registration_Info_UScriptStruct_LineMeshGeomStruct, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FLineMeshGeomStruct), 471779539U) },
		{ FGeometryFilter::StaticStruct, Z_Construct_UScriptStruct_FGeometryFilter_Statics::NewStructOps, TEXT("GeometryFilter"), &Z_Registration_Info_UScriptStruct_GeometryFilter, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FGeometryFilter), 76715730U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_Imstk_Source_Imstk_Public_GeometryFilter_h_1596122225(TEXT("/Script/Imstk"),
		nullptr, 0,
		Z_CompiledInDeferFile_FID_HostProject_Plugins_Imstk_Source_Imstk_Public_GeometryFilter_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HostProject_Plugins_Imstk_Source_Imstk_Public_GeometryFilter_h_Statics::ScriptStructInfo),
		Z_CompiledInDeferFile_FID_HostProject_Plugins_Imstk_Source_Imstk_Public_GeometryFilter_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HostProject_Plugins_Imstk_Source_Imstk_Public_GeometryFilter_h_Statics::EnumInfo));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
