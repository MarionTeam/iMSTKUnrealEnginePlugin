// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Imstk/Public/GeometryFilter.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGeometryFilter() {}
// Cross Module References
	IMSTK_API UEnum* Z_Construct_UEnum_Imstk_EGeometryType();
	UPackage* Z_Construct_UPackage__Script_Imstk();
	IMSTK_API UScriptStruct* Z_Construct_UScriptStruct_FGeometryFilter();
	IMSTK_API UScriptStruct* Z_Construct_UScriptStruct_FSphereGeomStruct();
	IMSTK_API UScriptStruct* Z_Construct_UScriptStruct_FSurfaceMeshGeomStruct();
	IMSTK_API UScriptStruct* Z_Construct_UScriptStruct_FCapsuleGeomStruct();
	IMSTK_API UScriptStruct* Z_Construct_UScriptStruct_FPointSetGeomStruct();
	IMSTK_API UScriptStruct* Z_Construct_UScriptStruct_FOrientedBoxGeomStruct();
	IMSTK_API UScriptStruct* Z_Construct_UScriptStruct_FPlaneGeomStruct();
	IMSTK_API UScriptStruct* Z_Construct_UScriptStruct_FGeometryTypeStruct();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	IMSTK_API UScriptStruct* Z_Construct_UScriptStruct_FCylinderGeomStruct();
// End Cross Module References
	static UEnum* EGeometryType_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_Imstk_EGeometryType, Z_Construct_UPackage__Script_Imstk(), TEXT("EGeometryType"));
		}
		return Singleton;
	}
	template<> IMSTK_API UEnum* StaticEnum<EGeometryType>()
	{
		return EGeometryType_StaticEnum();
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_EGeometryType(EGeometryType_StaticEnum, TEXT("/Script/Imstk"), TEXT("EGeometryType"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_Imstk_EGeometryType_Hash() { return 449908725U; }
	UEnum* Z_Construct_UEnum_Imstk_EGeometryType()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_Imstk();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("EGeometryType"), 0, Get_Z_Construct_UEnum_Imstk_EGeometryType_Hash(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "Sphere", (int64)Sphere },
				{ "SurfaceMesh", (int64)SurfaceMesh },
				{ "Capsule", (int64)Capsule },
				{ "Cylinder", (int64)Cylinder },
				{ "PointSet", (int64)PointSet },
				{ "OrientedBox", (int64)OrientedBox },
				{ "Plane", (int64)Plane },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "Capsule.Name", "Capsule" },
				{ "Comment", "/** \\file GeometryFilter.h\n *  \\brief Defines the structs and enum used in the geometry filter\n *  \\details Geometry structs should be moved to another class\n */// Enum that defines the geometry types provided by imstk\n" },
				{ "Cylinder.Name", "Cylinder" },
				{ "ModuleRelativePath", "Public/GeometryFilter.h" },
				{ "OrientedBox.Name", "OrientedBox" },
				{ "Plane.Name", "Plane" },
				{ "PointSet.Name", "PointSet" },
				{ "Sphere.Name", "Sphere" },
				{ "SurfaceMesh.Name", "SurfaceMesh" },
				{ "ToolTip", "\\file GeometryFilter.h\n\\brief Defines the structs and enum used in the geometry filter\n\\details Geometry structs should be moved to another class\n// Enum that defines the geometry types provided by imstk" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_Imstk,
				nullptr,
				"EGeometryType",
				"EGeometryType",
				Enumerators,
				UE_ARRAY_COUNT(Enumerators),
				RF_Public|RF_Transient|RF_MarkAsNative,
				EEnumFlags::None,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				(uint8)UEnum::ECppForm::Regular,
				METADATA_PARAMS(Enum_MetaDataParams, UE_ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
class UScriptStruct* FGeometryFilter::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern IMSTK_API uint32 Get_Z_Construct_UScriptStruct_FGeometryFilter_Hash();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FGeometryFilter, Z_Construct_UPackage__Script_Imstk(), TEXT("GeometryFilter"), sizeof(FGeometryFilter), Get_Z_Construct_UScriptStruct_FGeometryFilter_Hash());
	}
	return Singleton;
}
template<> IMSTK_API UScriptStruct* StaticStruct<FGeometryFilter>()
{
	return FGeometryFilter::StaticStruct();
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FGeometryFilter(FGeometryFilter::StaticStruct, TEXT("/Script/Imstk"), TEXT("GeometryFilter"), false, nullptr, nullptr);
static struct FScriptStruct_Imstk_StaticRegisterNativesFGeometryFilter
{
	FScriptStruct_Imstk_StaticRegisterNativesFGeometryFilter()
	{
		UScriptStruct::DeferCppStructOps<FGeometryFilter>(FName(TEXT("GeometryFilter")));
	}
} ScriptStruct_Imstk_StaticRegisterNativesFGeometryFilter;
	struct Z_Construct_UScriptStruct_FGeometryFilter_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_GeomType_MetaData[];
#endif
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_GeomType;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SphereStruct_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_SphereStruct;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MeshStruct_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_MeshStruct;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CapsuleStruct_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_CapsuleStruct;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CylinderStruct_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_CylinderStruct;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_PointSetStruct_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_PointSetStruct;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OrientedBoxStruct_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_OrientedBoxStruct;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_PlaneStruct_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_PlaneStruct;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FGeometryFilter_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/GeometryFilter.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FGeometryFilter_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FGeometryFilter>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FGeometryFilter_Statics::NewProp_GeomType_MetaData[] = {
		{ "Category", "General" },
		{ "ModuleRelativePath", "Public/GeometryFilter.h" },
	};
#endif
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FGeometryFilter_Statics::NewProp_GeomType = { "GeomType", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FGeometryFilter, GeomType), Z_Construct_UEnum_Imstk_EGeometryType, METADATA_PARAMS(Z_Construct_UScriptStruct_FGeometryFilter_Statics::NewProp_GeomType_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGeometryFilter_Statics::NewProp_GeomType_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FGeometryFilter_Statics::NewProp_SphereStruct_MetaData[] = {
		{ "Category", "General" },
		{ "Comment", "// TODO: These structures being visible from other classes is not great\n// Structs for each shape that can be created in Imstk\n" },
		{ "EditCondition", "GeomType == EGeometryType::Sphere" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/GeometryFilter.h" },
		{ "ToolTip", "TODO: These structures being visible from other classes is not great\nStructs for each shape that can be created in Imstk" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FGeometryFilter_Statics::NewProp_SphereStruct = { "SphereStruct", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FGeometryFilter, SphereStruct), Z_Construct_UScriptStruct_FSphereGeomStruct, METADATA_PARAMS(Z_Construct_UScriptStruct_FGeometryFilter_Statics::NewProp_SphereStruct_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGeometryFilter_Statics::NewProp_SphereStruct_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FGeometryFilter_Statics::NewProp_MeshStruct_MetaData[] = {
		{ "Category", "General" },
		{ "EditCondition", "GeomType == EGeometryType::SurfaceMesh" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/GeometryFilter.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FGeometryFilter_Statics::NewProp_MeshStruct = { "MeshStruct", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FGeometryFilter, MeshStruct), Z_Construct_UScriptStruct_FSurfaceMeshGeomStruct, METADATA_PARAMS(Z_Construct_UScriptStruct_FGeometryFilter_Statics::NewProp_MeshStruct_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGeometryFilter_Statics::NewProp_MeshStruct_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FGeometryFilter_Statics::NewProp_CapsuleStruct_MetaData[] = {
		{ "Category", "General" },
		{ "EditCondition", "GeomType == EGeometryType::Capsule" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/GeometryFilter.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FGeometryFilter_Statics::NewProp_CapsuleStruct = { "CapsuleStruct", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FGeometryFilter, CapsuleStruct), Z_Construct_UScriptStruct_FCapsuleGeomStruct, METADATA_PARAMS(Z_Construct_UScriptStruct_FGeometryFilter_Statics::NewProp_CapsuleStruct_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGeometryFilter_Statics::NewProp_CapsuleStruct_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FGeometryFilter_Statics::NewProp_CylinderStruct_MetaData[] = {
		{ "Category", "General" },
		{ "EditCondition", "GeomType == EGeometryType::Cylinder" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/GeometryFilter.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FGeometryFilter_Statics::NewProp_CylinderStruct = { "CylinderStruct", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FGeometryFilter, CylinderStruct), Z_Construct_UScriptStruct_FCapsuleGeomStruct, METADATA_PARAMS(Z_Construct_UScriptStruct_FGeometryFilter_Statics::NewProp_CylinderStruct_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGeometryFilter_Statics::NewProp_CylinderStruct_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FGeometryFilter_Statics::NewProp_PointSetStruct_MetaData[] = {
		{ "Category", "General" },
		{ "EditCondition", "GeomType == EGeometryType::PointSet" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/GeometryFilter.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FGeometryFilter_Statics::NewProp_PointSetStruct = { "PointSetStruct", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FGeometryFilter, PointSetStruct), Z_Construct_UScriptStruct_FPointSetGeomStruct, METADATA_PARAMS(Z_Construct_UScriptStruct_FGeometryFilter_Statics::NewProp_PointSetStruct_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGeometryFilter_Statics::NewProp_PointSetStruct_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FGeometryFilter_Statics::NewProp_OrientedBoxStruct_MetaData[] = {
		{ "Category", "General" },
		{ "EditCondition", "GeomType == EGeometryType::OrientedBox" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/GeometryFilter.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FGeometryFilter_Statics::NewProp_OrientedBoxStruct = { "OrientedBoxStruct", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FGeometryFilter, OrientedBoxStruct), Z_Construct_UScriptStruct_FOrientedBoxGeomStruct, METADATA_PARAMS(Z_Construct_UScriptStruct_FGeometryFilter_Statics::NewProp_OrientedBoxStruct_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGeometryFilter_Statics::NewProp_OrientedBoxStruct_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FGeometryFilter_Statics::NewProp_PlaneStruct_MetaData[] = {
		{ "Category", "General" },
		{ "EditCondition", "GeomType == EGeometryType::Plane" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/GeometryFilter.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FGeometryFilter_Statics::NewProp_PlaneStruct = { "PlaneStruct", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FGeometryFilter, PlaneStruct), Z_Construct_UScriptStruct_FPlaneGeomStruct, METADATA_PARAMS(Z_Construct_UScriptStruct_FGeometryFilter_Statics::NewProp_PlaneStruct_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGeometryFilter_Statics::NewProp_PlaneStruct_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FGeometryFilter_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGeometryFilter_Statics::NewProp_GeomType,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGeometryFilter_Statics::NewProp_SphereStruct,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGeometryFilter_Statics::NewProp_MeshStruct,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGeometryFilter_Statics::NewProp_CapsuleStruct,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGeometryFilter_Statics::NewProp_CylinderStruct,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGeometryFilter_Statics::NewProp_PointSetStruct,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGeometryFilter_Statics::NewProp_OrientedBoxStruct,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGeometryFilter_Statics::NewProp_PlaneStruct,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FGeometryFilter_Statics::ReturnStructParams = {
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
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FGeometryFilter_Hash();
		UPackage* Outer = Z_Construct_UPackage__Script_Imstk();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("GeometryFilter"), sizeof(FGeometryFilter), Get_Z_Construct_UScriptStruct_FGeometryFilter_Hash(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FGeometryFilter_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FGeometryFilter_Hash() { return 1626842873U; }

static_assert(std::is_polymorphic<FPlaneGeomStruct>() == std::is_polymorphic<FGeometryTypeStruct>(), "USTRUCT FPlaneGeomStruct cannot be polymorphic unless super FGeometryTypeStruct is polymorphic");

class UScriptStruct* FPlaneGeomStruct::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern IMSTK_API uint32 Get_Z_Construct_UScriptStruct_FPlaneGeomStruct_Hash();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FPlaneGeomStruct, Z_Construct_UPackage__Script_Imstk(), TEXT("PlaneGeomStruct"), sizeof(FPlaneGeomStruct), Get_Z_Construct_UScriptStruct_FPlaneGeomStruct_Hash());
	}
	return Singleton;
}
template<> IMSTK_API UScriptStruct* StaticStruct<FPlaneGeomStruct>()
{
	return FPlaneGeomStruct::StaticStruct();
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FPlaneGeomStruct(FPlaneGeomStruct::StaticStruct, TEXT("/Script/Imstk"), TEXT("PlaneGeomStruct"), false, nullptr, nullptr);
static struct FScriptStruct_Imstk_StaticRegisterNativesFPlaneGeomStruct
{
	FScriptStruct_Imstk_StaticRegisterNativesFPlaneGeomStruct()
	{
		UScriptStruct::DeferCppStructOps<FPlaneGeomStruct>(FName(TEXT("PlaneGeomStruct")));
	}
} ScriptStruct_Imstk_StaticRegisterNativesFPlaneGeomStruct;
	struct Z_Construct_UScriptStruct_FPlaneGeomStruct_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Normal_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Normal;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPlaneGeomStruct_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/GeometryFilter.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FPlaneGeomStruct_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FPlaneGeomStruct>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPlaneGeomStruct_Statics::NewProp_Normal_MetaData[] = {
		{ "Category", "General" },
		{ "ModuleRelativePath", "Public/GeometryFilter.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FPlaneGeomStruct_Statics::NewProp_Normal = { "Normal", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FPlaneGeomStruct, Normal), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UScriptStruct_FPlaneGeomStruct_Statics::NewProp_Normal_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPlaneGeomStruct_Statics::NewProp_Normal_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FPlaneGeomStruct_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPlaneGeomStruct_Statics::NewProp_Normal,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FPlaneGeomStruct_Statics::ReturnStructParams = {
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
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FPlaneGeomStruct_Hash();
		UPackage* Outer = Z_Construct_UPackage__Script_Imstk();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("PlaneGeomStruct"), sizeof(FPlaneGeomStruct), Get_Z_Construct_UScriptStruct_FPlaneGeomStruct_Hash(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FPlaneGeomStruct_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FPlaneGeomStruct_Hash() { return 2387544520U; }

static_assert(std::is_polymorphic<FOrientedBoxGeomStruct>() == std::is_polymorphic<FGeometryTypeStruct>(), "USTRUCT FOrientedBoxGeomStruct cannot be polymorphic unless super FGeometryTypeStruct is polymorphic");

class UScriptStruct* FOrientedBoxGeomStruct::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern IMSTK_API uint32 Get_Z_Construct_UScriptStruct_FOrientedBoxGeomStruct_Hash();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FOrientedBoxGeomStruct, Z_Construct_UPackage__Script_Imstk(), TEXT("OrientedBoxGeomStruct"), sizeof(FOrientedBoxGeomStruct), Get_Z_Construct_UScriptStruct_FOrientedBoxGeomStruct_Hash());
	}
	return Singleton;
}
template<> IMSTK_API UScriptStruct* StaticStruct<FOrientedBoxGeomStruct>()
{
	return FOrientedBoxGeomStruct::StaticStruct();
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FOrientedBoxGeomStruct(FOrientedBoxGeomStruct::StaticStruct, TEXT("/Script/Imstk"), TEXT("OrientedBoxGeomStruct"), false, nullptr, nullptr);
static struct FScriptStruct_Imstk_StaticRegisterNativesFOrientedBoxGeomStruct
{
	FScriptStruct_Imstk_StaticRegisterNativesFOrientedBoxGeomStruct()
	{
		UScriptStruct::DeferCppStructOps<FOrientedBoxGeomStruct>(FName(TEXT("OrientedBoxGeomStruct")));
	}
} ScriptStruct_Imstk_StaticRegisterNativesFOrientedBoxGeomStruct;
	struct Z_Construct_UScriptStruct_FOrientedBoxGeomStruct_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Extents_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Extents;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FOrientedBoxGeomStruct_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/GeometryFilter.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FOrientedBoxGeomStruct_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FOrientedBoxGeomStruct>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FOrientedBoxGeomStruct_Statics::NewProp_Extents_MetaData[] = {
		{ "Category", "General" },
		{ "ModuleRelativePath", "Public/GeometryFilter.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FOrientedBoxGeomStruct_Statics::NewProp_Extents = { "Extents", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FOrientedBoxGeomStruct, Extents), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UScriptStruct_FOrientedBoxGeomStruct_Statics::NewProp_Extents_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOrientedBoxGeomStruct_Statics::NewProp_Extents_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FOrientedBoxGeomStruct_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOrientedBoxGeomStruct_Statics::NewProp_Extents,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FOrientedBoxGeomStruct_Statics::ReturnStructParams = {
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
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FOrientedBoxGeomStruct_Hash();
		UPackage* Outer = Z_Construct_UPackage__Script_Imstk();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("OrientedBoxGeomStruct"), sizeof(FOrientedBoxGeomStruct), Get_Z_Construct_UScriptStruct_FOrientedBoxGeomStruct_Hash(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FOrientedBoxGeomStruct_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FOrientedBoxGeomStruct_Hash() { return 1579018018U; }

static_assert(std::is_polymorphic<FPointSetGeomStruct>() == std::is_polymorphic<FGeometryTypeStruct>(), "USTRUCT FPointSetGeomStruct cannot be polymorphic unless super FGeometryTypeStruct is polymorphic");

class UScriptStruct* FPointSetGeomStruct::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern IMSTK_API uint32 Get_Z_Construct_UScriptStruct_FPointSetGeomStruct_Hash();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FPointSetGeomStruct, Z_Construct_UPackage__Script_Imstk(), TEXT("PointSetGeomStruct"), sizeof(FPointSetGeomStruct), Get_Z_Construct_UScriptStruct_FPointSetGeomStruct_Hash());
	}
	return Singleton;
}
template<> IMSTK_API UScriptStruct* StaticStruct<FPointSetGeomStruct>()
{
	return FPointSetGeomStruct::StaticStruct();
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FPointSetGeomStruct(FPointSetGeomStruct::StaticStruct, TEXT("/Script/Imstk"), TEXT("PointSetGeomStruct"), false, nullptr, nullptr);
static struct FScriptStruct_Imstk_StaticRegisterNativesFPointSetGeomStruct
{
	FScriptStruct_Imstk_StaticRegisterNativesFPointSetGeomStruct()
	{
		UScriptStruct::DeferCppStructOps<FPointSetGeomStruct>(FName(TEXT("PointSetGeomStruct")));
	}
} ScriptStruct_Imstk_StaticRegisterNativesFPointSetGeomStruct;
	struct Z_Construct_UScriptStruct_FPointSetGeomStruct_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPointSetGeomStruct_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/GeometryFilter.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FPointSetGeomStruct_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FPointSetGeomStruct>();
	}
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FPointSetGeomStruct_Statics::ReturnStructParams = {
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
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FPointSetGeomStruct_Hash();
		UPackage* Outer = Z_Construct_UPackage__Script_Imstk();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("PointSetGeomStruct"), sizeof(FPointSetGeomStruct), Get_Z_Construct_UScriptStruct_FPointSetGeomStruct_Hash(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FPointSetGeomStruct_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FPointSetGeomStruct_Hash() { return 2412355748U; }

static_assert(std::is_polymorphic<FCylinderGeomStruct>() == std::is_polymorphic<FGeometryTypeStruct>(), "USTRUCT FCylinderGeomStruct cannot be polymorphic unless super FGeometryTypeStruct is polymorphic");

class UScriptStruct* FCylinderGeomStruct::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern IMSTK_API uint32 Get_Z_Construct_UScriptStruct_FCylinderGeomStruct_Hash();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FCylinderGeomStruct, Z_Construct_UPackage__Script_Imstk(), TEXT("CylinderGeomStruct"), sizeof(FCylinderGeomStruct), Get_Z_Construct_UScriptStruct_FCylinderGeomStruct_Hash());
	}
	return Singleton;
}
template<> IMSTK_API UScriptStruct* StaticStruct<FCylinderGeomStruct>()
{
	return FCylinderGeomStruct::StaticStruct();
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FCylinderGeomStruct(FCylinderGeomStruct::StaticStruct, TEXT("/Script/Imstk"), TEXT("CylinderGeomStruct"), false, nullptr, nullptr);
static struct FScriptStruct_Imstk_StaticRegisterNativesFCylinderGeomStruct
{
	FScriptStruct_Imstk_StaticRegisterNativesFCylinderGeomStruct()
	{
		UScriptStruct::DeferCppStructOps<FCylinderGeomStruct>(FName(TEXT("CylinderGeomStruct")));
	}
} ScriptStruct_Imstk_StaticRegisterNativesFCylinderGeomStruct;
	struct Z_Construct_UScriptStruct_FCylinderGeomStruct_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Radius_MetaData[];
#endif
		static const UE4CodeGen_Private::FDoublePropertyParams NewProp_Radius;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Length_MetaData[];
#endif
		static const UE4CodeGen_Private::FDoublePropertyParams NewProp_Length;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FCylinderGeomStruct_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/GeometryFilter.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FCylinderGeomStruct_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FCylinderGeomStruct>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FCylinderGeomStruct_Statics::NewProp_Radius_MetaData[] = {
		{ "Category", "General" },
		{ "ClampMin", "0.01" },
		{ "ModuleRelativePath", "Public/GeometryFilter.h" },
	};
#endif
	const UE4CodeGen_Private::FDoublePropertyParams Z_Construct_UScriptStruct_FCylinderGeomStruct_Statics::NewProp_Radius = { "Radius", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Double, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FCylinderGeomStruct, Radius), METADATA_PARAMS(Z_Construct_UScriptStruct_FCylinderGeomStruct_Statics::NewProp_Radius_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCylinderGeomStruct_Statics::NewProp_Radius_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FCylinderGeomStruct_Statics::NewProp_Length_MetaData[] = {
		{ "Category", "General" },
		{ "ClampMin", "0.01" },
		{ "ModuleRelativePath", "Public/GeometryFilter.h" },
	};
#endif
	const UE4CodeGen_Private::FDoublePropertyParams Z_Construct_UScriptStruct_FCylinderGeomStruct_Statics::NewProp_Length = { "Length", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Double, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FCylinderGeomStruct, Length), METADATA_PARAMS(Z_Construct_UScriptStruct_FCylinderGeomStruct_Statics::NewProp_Length_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCylinderGeomStruct_Statics::NewProp_Length_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FCylinderGeomStruct_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCylinderGeomStruct_Statics::NewProp_Radius,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCylinderGeomStruct_Statics::NewProp_Length,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FCylinderGeomStruct_Statics::ReturnStructParams = {
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
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FCylinderGeomStruct_Hash();
		UPackage* Outer = Z_Construct_UPackage__Script_Imstk();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("CylinderGeomStruct"), sizeof(FCylinderGeomStruct), Get_Z_Construct_UScriptStruct_FCylinderGeomStruct_Hash(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FCylinderGeomStruct_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FCylinderGeomStruct_Hash() { return 3871463752U; }

static_assert(std::is_polymorphic<FCapsuleGeomStruct>() == std::is_polymorphic<FGeometryTypeStruct>(), "USTRUCT FCapsuleGeomStruct cannot be polymorphic unless super FGeometryTypeStruct is polymorphic");

class UScriptStruct* FCapsuleGeomStruct::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern IMSTK_API uint32 Get_Z_Construct_UScriptStruct_FCapsuleGeomStruct_Hash();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FCapsuleGeomStruct, Z_Construct_UPackage__Script_Imstk(), TEXT("CapsuleGeomStruct"), sizeof(FCapsuleGeomStruct), Get_Z_Construct_UScriptStruct_FCapsuleGeomStruct_Hash());
	}
	return Singleton;
}
template<> IMSTK_API UScriptStruct* StaticStruct<FCapsuleGeomStruct>()
{
	return FCapsuleGeomStruct::StaticStruct();
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FCapsuleGeomStruct(FCapsuleGeomStruct::StaticStruct, TEXT("/Script/Imstk"), TEXT("CapsuleGeomStruct"), false, nullptr, nullptr);
static struct FScriptStruct_Imstk_StaticRegisterNativesFCapsuleGeomStruct
{
	FScriptStruct_Imstk_StaticRegisterNativesFCapsuleGeomStruct()
	{
		UScriptStruct::DeferCppStructOps<FCapsuleGeomStruct>(FName(TEXT("CapsuleGeomStruct")));
	}
} ScriptStruct_Imstk_StaticRegisterNativesFCapsuleGeomStruct;
	struct Z_Construct_UScriptStruct_FCapsuleGeomStruct_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Radius_MetaData[];
#endif
		static const UE4CodeGen_Private::FDoublePropertyParams NewProp_Radius;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Length_MetaData[];
#endif
		static const UE4CodeGen_Private::FDoublePropertyParams NewProp_Length;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FCapsuleGeomStruct_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/GeometryFilter.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FCapsuleGeomStruct_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FCapsuleGeomStruct>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FCapsuleGeomStruct_Statics::NewProp_Radius_MetaData[] = {
		{ "Category", "General" },
		{ "ClampMin", "0.01" },
		{ "ModuleRelativePath", "Public/GeometryFilter.h" },
	};
#endif
	const UE4CodeGen_Private::FDoublePropertyParams Z_Construct_UScriptStruct_FCapsuleGeomStruct_Statics::NewProp_Radius = { "Radius", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Double, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FCapsuleGeomStruct, Radius), METADATA_PARAMS(Z_Construct_UScriptStruct_FCapsuleGeomStruct_Statics::NewProp_Radius_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCapsuleGeomStruct_Statics::NewProp_Radius_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FCapsuleGeomStruct_Statics::NewProp_Length_MetaData[] = {
		{ "Category", "General" },
		{ "ClampMin", "0.01" },
		{ "ModuleRelativePath", "Public/GeometryFilter.h" },
	};
#endif
	const UE4CodeGen_Private::FDoublePropertyParams Z_Construct_UScriptStruct_FCapsuleGeomStruct_Statics::NewProp_Length = { "Length", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Double, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FCapsuleGeomStruct, Length), METADATA_PARAMS(Z_Construct_UScriptStruct_FCapsuleGeomStruct_Statics::NewProp_Length_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCapsuleGeomStruct_Statics::NewProp_Length_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FCapsuleGeomStruct_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCapsuleGeomStruct_Statics::NewProp_Radius,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCapsuleGeomStruct_Statics::NewProp_Length,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FCapsuleGeomStruct_Statics::ReturnStructParams = {
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
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FCapsuleGeomStruct_Hash();
		UPackage* Outer = Z_Construct_UPackage__Script_Imstk();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("CapsuleGeomStruct"), sizeof(FCapsuleGeomStruct), Get_Z_Construct_UScriptStruct_FCapsuleGeomStruct_Hash(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FCapsuleGeomStruct_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FCapsuleGeomStruct_Hash() { return 2977771525U; }

static_assert(std::is_polymorphic<FSurfaceMeshGeomStruct>() == std::is_polymorphic<FGeometryTypeStruct>(), "USTRUCT FSurfaceMeshGeomStruct cannot be polymorphic unless super FGeometryTypeStruct is polymorphic");

class UScriptStruct* FSurfaceMeshGeomStruct::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern IMSTK_API uint32 Get_Z_Construct_UScriptStruct_FSurfaceMeshGeomStruct_Hash();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FSurfaceMeshGeomStruct, Z_Construct_UPackage__Script_Imstk(), TEXT("SurfaceMeshGeomStruct"), sizeof(FSurfaceMeshGeomStruct), Get_Z_Construct_UScriptStruct_FSurfaceMeshGeomStruct_Hash());
	}
	return Singleton;
}
template<> IMSTK_API UScriptStruct* StaticStruct<FSurfaceMeshGeomStruct>()
{
	return FSurfaceMeshGeomStruct::StaticStruct();
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FSurfaceMeshGeomStruct(FSurfaceMeshGeomStruct::StaticStruct, TEXT("/Script/Imstk"), TEXT("SurfaceMeshGeomStruct"), false, nullptr, nullptr);
static struct FScriptStruct_Imstk_StaticRegisterNativesFSurfaceMeshGeomStruct
{
	FScriptStruct_Imstk_StaticRegisterNativesFSurfaceMeshGeomStruct()
	{
		UScriptStruct::DeferCppStructOps<FSurfaceMeshGeomStruct>(FName(TEXT("SurfaceMeshGeomStruct")));
	}
} ScriptStruct_Imstk_StaticRegisterNativesFSurfaceMeshGeomStruct;
	struct Z_Construct_UScriptStruct_FSurfaceMeshGeomStruct_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bFlipNormals_MetaData[];
#endif
		static void NewProp_bFlipNormals_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bFlipNormals;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSurfaceMeshGeomStruct_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/GeometryFilter.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FSurfaceMeshGeomStruct_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FSurfaceMeshGeomStruct>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSurfaceMeshGeomStruct_Statics::NewProp_bFlipNormals_MetaData[] = {
		{ "Category", "General" },
		{ "ModuleRelativePath", "Public/GeometryFilter.h" },
	};
#endif
	void Z_Construct_UScriptStruct_FSurfaceMeshGeomStruct_Statics::NewProp_bFlipNormals_SetBit(void* Obj)
	{
		((FSurfaceMeshGeomStruct*)Obj)->bFlipNormals = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FSurfaceMeshGeomStruct_Statics::NewProp_bFlipNormals = { "bFlipNormals", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(FSurfaceMeshGeomStruct), &Z_Construct_UScriptStruct_FSurfaceMeshGeomStruct_Statics::NewProp_bFlipNormals_SetBit, METADATA_PARAMS(Z_Construct_UScriptStruct_FSurfaceMeshGeomStruct_Statics::NewProp_bFlipNormals_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSurfaceMeshGeomStruct_Statics::NewProp_bFlipNormals_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FSurfaceMeshGeomStruct_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSurfaceMeshGeomStruct_Statics::NewProp_bFlipNormals,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FSurfaceMeshGeomStruct_Statics::ReturnStructParams = {
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
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FSurfaceMeshGeomStruct_Hash();
		UPackage* Outer = Z_Construct_UPackage__Script_Imstk();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("SurfaceMeshGeomStruct"), sizeof(FSurfaceMeshGeomStruct), Get_Z_Construct_UScriptStruct_FSurfaceMeshGeomStruct_Hash(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FSurfaceMeshGeomStruct_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FSurfaceMeshGeomStruct_Hash() { return 3929410993U; }

static_assert(std::is_polymorphic<FSphereGeomStruct>() == std::is_polymorphic<FGeometryTypeStruct>(), "USTRUCT FSphereGeomStruct cannot be polymorphic unless super FGeometryTypeStruct is polymorphic");

class UScriptStruct* FSphereGeomStruct::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern IMSTK_API uint32 Get_Z_Construct_UScriptStruct_FSphereGeomStruct_Hash();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FSphereGeomStruct, Z_Construct_UPackage__Script_Imstk(), TEXT("SphereGeomStruct"), sizeof(FSphereGeomStruct), Get_Z_Construct_UScriptStruct_FSphereGeomStruct_Hash());
	}
	return Singleton;
}
template<> IMSTK_API UScriptStruct* StaticStruct<FSphereGeomStruct>()
{
	return FSphereGeomStruct::StaticStruct();
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FSphereGeomStruct(FSphereGeomStruct::StaticStruct, TEXT("/Script/Imstk"), TEXT("SphereGeomStruct"), false, nullptr, nullptr);
static struct FScriptStruct_Imstk_StaticRegisterNativesFSphereGeomStruct
{
	FScriptStruct_Imstk_StaticRegisterNativesFSphereGeomStruct()
	{
		UScriptStruct::DeferCppStructOps<FSphereGeomStruct>(FName(TEXT("SphereGeomStruct")));
	}
} ScriptStruct_Imstk_StaticRegisterNativesFSphereGeomStruct;
	struct Z_Construct_UScriptStruct_FSphereGeomStruct_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Radius_MetaData[];
#endif
		static const UE4CodeGen_Private::FDoublePropertyParams NewProp_Radius;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSphereGeomStruct_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Comment", "// TODO: Move this into its own classes for geometry?\n" },
		{ "ModuleRelativePath", "Public/GeometryFilter.h" },
		{ "ToolTip", "TODO: Move this into its own classes for geometry?" },
	};
#endif
	void* Z_Construct_UScriptStruct_FSphereGeomStruct_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FSphereGeomStruct>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSphereGeomStruct_Statics::NewProp_Radius_MetaData[] = {
		{ "Category", "General" },
		{ "ModuleRelativePath", "Public/GeometryFilter.h" },
	};
#endif
	const UE4CodeGen_Private::FDoublePropertyParams Z_Construct_UScriptStruct_FSphereGeomStruct_Statics::NewProp_Radius = { "Radius", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Double, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSphereGeomStruct, Radius), METADATA_PARAMS(Z_Construct_UScriptStruct_FSphereGeomStruct_Statics::NewProp_Radius_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSphereGeomStruct_Statics::NewProp_Radius_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FSphereGeomStruct_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSphereGeomStruct_Statics::NewProp_Radius,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FSphereGeomStruct_Statics::ReturnStructParams = {
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
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FSphereGeomStruct_Hash();
		UPackage* Outer = Z_Construct_UPackage__Script_Imstk();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("SphereGeomStruct"), sizeof(FSphereGeomStruct), Get_Z_Construct_UScriptStruct_FSphereGeomStruct_Hash(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FSphereGeomStruct_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FSphereGeomStruct_Hash() { return 4020271950U; }
class UScriptStruct* FGeometryTypeStruct::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern IMSTK_API uint32 Get_Z_Construct_UScriptStruct_FGeometryTypeStruct_Hash();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FGeometryTypeStruct, Z_Construct_UPackage__Script_Imstk(), TEXT("GeometryTypeStruct"), sizeof(FGeometryTypeStruct), Get_Z_Construct_UScriptStruct_FGeometryTypeStruct_Hash());
	}
	return Singleton;
}
template<> IMSTK_API UScriptStruct* StaticStruct<FGeometryTypeStruct>()
{
	return FGeometryTypeStruct::StaticStruct();
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FGeometryTypeStruct(FGeometryTypeStruct::StaticStruct, TEXT("/Script/Imstk"), TEXT("GeometryTypeStruct"), false, nullptr, nullptr);
static struct FScriptStruct_Imstk_StaticRegisterNativesFGeometryTypeStruct
{
	FScriptStruct_Imstk_StaticRegisterNativesFGeometryTypeStruct()
	{
		UScriptStruct::DeferCppStructOps<FGeometryTypeStruct>(FName(TEXT("GeometryTypeStruct")));
	}
} ScriptStruct_Imstk_StaticRegisterNativesFGeometryTypeStruct;
	struct Z_Construct_UScriptStruct_FGeometryTypeStruct_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_EnumVal_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_EnumVal;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FGeometryTypeStruct_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/GeometryFilter.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FGeometryTypeStruct_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FGeometryTypeStruct>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FGeometryTypeStruct_Statics::NewProp_EnumVal_MetaData[] = {
		{ "Comment", "// Hidden value that corresponds to the enum value\n" },
		{ "ModuleRelativePath", "Public/GeometryFilter.h" },
		{ "ToolTip", "Hidden value that corresponds to the enum value" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UScriptStruct_FGeometryTypeStruct_Statics::NewProp_EnumVal = { "EnumVal", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FGeometryTypeStruct, EnumVal), METADATA_PARAMS(Z_Construct_UScriptStruct_FGeometryTypeStruct_Statics::NewProp_EnumVal_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGeometryTypeStruct_Statics::NewProp_EnumVal_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FGeometryTypeStruct_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGeometryTypeStruct_Statics::NewProp_EnumVal,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FGeometryTypeStruct_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_Imstk,
		nullptr,
		&NewStructOps,
		"GeometryTypeStruct",
		sizeof(FGeometryTypeStruct),
		alignof(FGeometryTypeStruct),
		Z_Construct_UScriptStruct_FGeometryTypeStruct_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGeometryTypeStruct_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FGeometryTypeStruct_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGeometryTypeStruct_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FGeometryTypeStruct()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FGeometryTypeStruct_Hash();
		UPackage* Outer = Z_Construct_UPackage__Script_Imstk();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("GeometryTypeStruct"), sizeof(FGeometryTypeStruct), Get_Z_Construct_UScriptStruct_FGeometryTypeStruct_Hash(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FGeometryTypeStruct_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FGeometryTypeStruct_Hash() { return 806981104U; }
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
