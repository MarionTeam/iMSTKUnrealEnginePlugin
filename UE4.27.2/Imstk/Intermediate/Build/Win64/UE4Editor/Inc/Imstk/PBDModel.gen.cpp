// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Imstk/Public/PBDModel.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePBDModel() {}
// Cross Module References
	IMSTK_API UClass* Z_Construct_UClass_UPBDModel_NoRegister();
	IMSTK_API UClass* Z_Construct_UClass_UPBDModel();
	IMSTK_API UClass* Z_Construct_UClass_UDeformableModel();
	UPackage* Z_Construct_UPackage__Script_Imstk();
	IMSTK_API UClass* Z_Construct_UClass_UTetrahedralMeshAsset_NoRegister();
	IMSTK_API UEnum* Z_Construct_UEnum_Imstk_FemConstraintMaterial();
	PROCEDURALMESHCOMPONENT_API UClass* Z_Construct_UClass_UProceduralMeshComponent_NoRegister();
// End Cross Module References
	void UPBDModel::StaticRegisterNativesUPBDModel()
	{
	}
	UClass* Z_Construct_UClass_UPBDModel_NoRegister()
	{
		return UPBDModel::StaticClass();
	}
	struct Z_Construct_UClass_UPBDModel_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_TetrahedralMesh_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_TetrahedralMesh;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bUseDihedralConstraint_MetaData[];
#endif
		static void NewProp_bUseDihedralConstraint_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bUseDihedralConstraint;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_DihedralConstraint_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_DihedralConstraint;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bUseVolumeConstraint_MetaData[];
#endif
		static void NewProp_bUseVolumeConstraint_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bUseVolumeConstraint;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_VolumeConstraint_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_VolumeConstraint;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bUseFEMConstraint_MetaData[];
#endif
		static void NewProp_bUseFEMConstraint_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bUseFEMConstraint;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_YoungsModulus_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_YoungsModulus;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_PossionsRatio_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_PossionsRatio;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MaterialType_MetaData[];
#endif
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_MaterialType;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MeshComp_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_MeshComp;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UPBDModel_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UDeformableModel,
		(UObject* (*)())Z_Construct_UPackage__Script_Imstk,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPBDModel_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Imstk" },
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "PBDModel.h" },
		{ "ModuleRelativePath", "Public/PBDModel.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPBDModel_Statics::NewProp_TetrahedralMesh_MetaData[] = {
		{ "Category", "General" },
		{ "Comment", "//bool TetrahedralMesh;\n" },
		{ "ModuleRelativePath", "Public/PBDModel.h" },
		{ "ToolTip", "bool TetrahedralMesh;" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UPBDModel_Statics::NewProp_TetrahedralMesh = { "TetrahedralMesh", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UPBDModel, TetrahedralMesh), Z_Construct_UClass_UTetrahedralMeshAsset_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UPBDModel_Statics::NewProp_TetrahedralMesh_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UPBDModel_Statics::NewProp_TetrahedralMesh_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPBDModel_Statics::NewProp_bUseDihedralConstraint_MetaData[] = {
		{ "Category", "Constraints" },
		{ "EditCondition", "TetrahedralMesh == nullptr" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/PBDModel.h" },
	};
#endif
	void Z_Construct_UClass_UPBDModel_Statics::NewProp_bUseDihedralConstraint_SetBit(void* Obj)
	{
		((UPBDModel*)Obj)->bUseDihedralConstraint = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UPBDModel_Statics::NewProp_bUseDihedralConstraint = { "bUseDihedralConstraint", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UPBDModel), &Z_Construct_UClass_UPBDModel_Statics::NewProp_bUseDihedralConstraint_SetBit, METADATA_PARAMS(Z_Construct_UClass_UPBDModel_Statics::NewProp_bUseDihedralConstraint_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UPBDModel_Statics::NewProp_bUseDihedralConstraint_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPBDModel_Statics::NewProp_DihedralConstraint_MetaData[] = {
		{ "Category", "Constraints" },
		{ "EditCondition", "bUseDihedralConstraint && TetrahedralMesh == nullptr" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/PBDModel.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UPBDModel_Statics::NewProp_DihedralConstraint = { "DihedralConstraint", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UPBDModel, DihedralConstraint), METADATA_PARAMS(Z_Construct_UClass_UPBDModel_Statics::NewProp_DihedralConstraint_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UPBDModel_Statics::NewProp_DihedralConstraint_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPBDModel_Statics::NewProp_bUseVolumeConstraint_MetaData[] = {
		{ "Category", "Constraints" },
		{ "EditCondition", "TetrahedralMesh != nullptr" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/PBDModel.h" },
	};
#endif
	void Z_Construct_UClass_UPBDModel_Statics::NewProp_bUseVolumeConstraint_SetBit(void* Obj)
	{
		((UPBDModel*)Obj)->bUseVolumeConstraint = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UPBDModel_Statics::NewProp_bUseVolumeConstraint = { "bUseVolumeConstraint", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UPBDModel), &Z_Construct_UClass_UPBDModel_Statics::NewProp_bUseVolumeConstraint_SetBit, METADATA_PARAMS(Z_Construct_UClass_UPBDModel_Statics::NewProp_bUseVolumeConstraint_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UPBDModel_Statics::NewProp_bUseVolumeConstraint_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPBDModel_Statics::NewProp_VolumeConstraint_MetaData[] = {
		{ "Category", "Constraints" },
		{ "EditCondition", "bUseVolumeConstraint && TetrahedralMesh != nullptr" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/PBDModel.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UPBDModel_Statics::NewProp_VolumeConstraint = { "VolumeConstraint", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UPBDModel, VolumeConstraint), METADATA_PARAMS(Z_Construct_UClass_UPBDModel_Statics::NewProp_VolumeConstraint_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UPBDModel_Statics::NewProp_VolumeConstraint_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPBDModel_Statics::NewProp_bUseFEMConstraint_MetaData[] = {
		{ "Category", "Constraints" },
		{ "EditCondition", "TetrahedralMesh != nullptr" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/PBDModel.h" },
	};
#endif
	void Z_Construct_UClass_UPBDModel_Statics::NewProp_bUseFEMConstraint_SetBit(void* Obj)
	{
		((UPBDModel*)Obj)->bUseFEMConstraint = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UPBDModel_Statics::NewProp_bUseFEMConstraint = { "bUseFEMConstraint", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UPBDModel), &Z_Construct_UClass_UPBDModel_Statics::NewProp_bUseFEMConstraint_SetBit, METADATA_PARAMS(Z_Construct_UClass_UPBDModel_Statics::NewProp_bUseFEMConstraint_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UPBDModel_Statics::NewProp_bUseFEMConstraint_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPBDModel_Statics::NewProp_YoungsModulus_MetaData[] = {
		{ "Category", "Constraints" },
		{ "EditCondition", "bUseFEMConstraint && TetrahedralMesh != nullptr" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/PBDModel.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UPBDModel_Statics::NewProp_YoungsModulus = { "YoungsModulus", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UPBDModel, YoungsModulus), METADATA_PARAMS(Z_Construct_UClass_UPBDModel_Statics::NewProp_YoungsModulus_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UPBDModel_Statics::NewProp_YoungsModulus_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPBDModel_Statics::NewProp_PossionsRatio_MetaData[] = {
		{ "Category", "Constraints" },
		{ "EditCondition", "bUseFEMConstraint && TetrahedralMesh != nullptr" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/PBDModel.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UPBDModel_Statics::NewProp_PossionsRatio = { "PossionsRatio", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UPBDModel, PossionsRatio), METADATA_PARAMS(Z_Construct_UClass_UPBDModel_Statics::NewProp_PossionsRatio_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UPBDModel_Statics::NewProp_PossionsRatio_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPBDModel_Statics::NewProp_MaterialType_MetaData[] = {
		{ "Category", "Constraints" },
		{ "EditCondition", "bUseFEMConstraint && TetrahedralMesh != nullptr" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/PBDModel.h" },
	};
#endif
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UClass_UPBDModel_Statics::NewProp_MaterialType = { "MaterialType", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UPBDModel, MaterialType), Z_Construct_UEnum_Imstk_FemConstraintMaterial, METADATA_PARAMS(Z_Construct_UClass_UPBDModel_Statics::NewProp_MaterialType_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UPBDModel_Statics::NewProp_MaterialType_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPBDModel_Statics::NewProp_MeshComp_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/PBDModel.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UPBDModel_Statics::NewProp_MeshComp = { "MeshComp", nullptr, (EPropertyFlags)0x0020080000080008, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UPBDModel, MeshComp), Z_Construct_UClass_UProceduralMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UPBDModel_Statics::NewProp_MeshComp_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UPBDModel_Statics::NewProp_MeshComp_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UPBDModel_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPBDModel_Statics::NewProp_TetrahedralMesh,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPBDModel_Statics::NewProp_bUseDihedralConstraint,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPBDModel_Statics::NewProp_DihedralConstraint,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPBDModel_Statics::NewProp_bUseVolumeConstraint,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPBDModel_Statics::NewProp_VolumeConstraint,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPBDModel_Statics::NewProp_bUseFEMConstraint,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPBDModel_Statics::NewProp_YoungsModulus,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPBDModel_Statics::NewProp_PossionsRatio,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPBDModel_Statics::NewProp_MaterialType,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPBDModel_Statics::NewProp_MeshComp,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UPBDModel_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPBDModel>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UPBDModel_Statics::ClassParams = {
		&UPBDModel::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UPBDModel_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UPBDModel_Statics::PropPointers),
		0,
		0x00B000A4u,
		METADATA_PARAMS(Z_Construct_UClass_UPBDModel_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UPBDModel_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UPBDModel()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UPBDModel_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UPBDModel, 3411584415);
	template<> IMSTK_API UClass* StaticClass<UPBDModel>()
	{
		return UPBDModel::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UPBDModel(Z_Construct_UClass_UPBDModel, &UPBDModel::StaticClass, TEXT("/Script/Imstk"), TEXT("UPBDModel"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UPBDModel);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
