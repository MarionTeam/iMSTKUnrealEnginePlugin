// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Imstk/Public/PBDModel.h"
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
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UPBDModel);
	UClass* Z_Construct_UClass_UPBDModel_NoRegister()
	{
		return UPBDModel::StaticClass();
	}
	struct Z_Construct_UClass_UPBDModel_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_TetrahedralMesh_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_TetrahedralMesh;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bUseDihedralConstraint_MetaData[];
#endif
		static void NewProp_bUseDihedralConstraint_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bUseDihedralConstraint;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DihedralConstraint_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_DihedralConstraint;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bUseVolumeConstraint_MetaData[];
#endif
		static void NewProp_bUseVolumeConstraint_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bUseVolumeConstraint;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_VolumeConstraint_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_VolumeConstraint;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bUseFEMConstraint_MetaData[];
#endif
		static void NewProp_bUseFEMConstraint_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bUseFEMConstraint;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_YoungsModulus_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_YoungsModulus;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_PossionsRatio_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_PossionsRatio;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MaterialType_MetaData[];
#endif
		static const UECodeGen_Private::FBytePropertyParams NewProp_MaterialType;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bGenerateSurfaceFromTetrahedral_MetaData[];
#endif
		static void NewProp_bGenerateSurfaceFromTetrahedral_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bGenerateSurfaceFromTetrahedral;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MeshComp_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_MeshComp;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UPBDModel_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UDeformableModel,
		(UObject* (*)())Z_Construct_UPackage__Script_Imstk,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPBDModel_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Imstk" },
		{ "Comment", "/** \\file PBDModel.h\n *  \\brief Position based dynamics model to attach to an actor in Unreal to mark as an object to add into iMSTK.\n *  \\details Has variables available in editor and blueprint to set the default values of the object in iMSTK. Converts attached static mesh or procedural mesh into a PBDModel in iMSTK. \n *\x09\x09     Attaches a procedural mesh to the object if it does not exist and updates the positions of the vertices to correspond with iMSTK. Can also be used to model tetrahedral meshes.\n */" },
		{ "IncludePath", "PBDModel.h" },
		{ "ModuleRelativePath", "Public/PBDModel.h" },
		{ "ToolTip", "\\file PBDModel.h\n\\brief Position based dynamics model to attach to an actor in Unreal to mark as an object to add into iMSTK.\n\\details Has variables available in editor and blueprint to set the default values of the object in iMSTK. Converts attached static mesh or procedural mesh into a PBDModel in iMSTK.\n                Attaches a procedural mesh to the object if it does not exist and updates the positions of the vertices to correspond with iMSTK. Can also be used to model tetrahedral meshes." },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPBDModel_Statics::NewProp_TetrahedralMesh_MetaData[] = {
		{ "Category", "General" },
		{ "Comment", "// Tetrahedral mesh asset to be used for the PBDModel.Can be generated by importing tetrahedral mesh files into Unreal. Should match the surface mesh attached to the actor\n" },
		{ "ModuleRelativePath", "Public/PBDModel.h" },
		{ "ToolTip", "Tetrahedral mesh asset to be used for the PBDModel.Can be generated by importing tetrahedral mesh files into Unreal. Should match the surface mesh attached to the actor" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UPBDModel_Statics::NewProp_TetrahedralMesh = { "TetrahedralMesh", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UPBDModel, TetrahedralMesh), Z_Construct_UClass_UTetrahedralMeshAsset_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UPBDModel_Statics::NewProp_TetrahedralMesh_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UPBDModel_Statics::NewProp_TetrahedralMesh_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPBDModel_Statics::NewProp_bUseDihedralConstraint_MetaData[] = {
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
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UPBDModel_Statics::NewProp_bUseDihedralConstraint = { "bUseDihedralConstraint", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UPBDModel), &Z_Construct_UClass_UPBDModel_Statics::NewProp_bUseDihedralConstraint_SetBit, METADATA_PARAMS(Z_Construct_UClass_UPBDModel_Statics::NewProp_bUseDihedralConstraint_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UPBDModel_Statics::NewProp_bUseDihedralConstraint_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPBDModel_Statics::NewProp_DihedralConstraint_MetaData[] = {
		{ "Category", "Constraints" },
		{ "EditCondition", "bUseDihedralConstraint && TetrahedralMesh == nullptr" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/PBDModel.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UPBDModel_Statics::NewProp_DihedralConstraint = { "DihedralConstraint", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UPBDModel, DihedralConstraint), METADATA_PARAMS(Z_Construct_UClass_UPBDModel_Statics::NewProp_DihedralConstraint_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UPBDModel_Statics::NewProp_DihedralConstraint_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPBDModel_Statics::NewProp_bUseVolumeConstraint_MetaData[] = {
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
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UPBDModel_Statics::NewProp_bUseVolumeConstraint = { "bUseVolumeConstraint", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UPBDModel), &Z_Construct_UClass_UPBDModel_Statics::NewProp_bUseVolumeConstraint_SetBit, METADATA_PARAMS(Z_Construct_UClass_UPBDModel_Statics::NewProp_bUseVolumeConstraint_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UPBDModel_Statics::NewProp_bUseVolumeConstraint_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPBDModel_Statics::NewProp_VolumeConstraint_MetaData[] = {
		{ "Category", "Constraints" },
		{ "EditCondition", "bUseVolumeConstraint && TetrahedralMesh != nullptr" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/PBDModel.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UPBDModel_Statics::NewProp_VolumeConstraint = { "VolumeConstraint", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UPBDModel, VolumeConstraint), METADATA_PARAMS(Z_Construct_UClass_UPBDModel_Statics::NewProp_VolumeConstraint_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UPBDModel_Statics::NewProp_VolumeConstraint_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPBDModel_Statics::NewProp_bUseFEMConstraint_MetaData[] = {
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
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UPBDModel_Statics::NewProp_bUseFEMConstraint = { "bUseFEMConstraint", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UPBDModel), &Z_Construct_UClass_UPBDModel_Statics::NewProp_bUseFEMConstraint_SetBit, METADATA_PARAMS(Z_Construct_UClass_UPBDModel_Statics::NewProp_bUseFEMConstraint_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UPBDModel_Statics::NewProp_bUseFEMConstraint_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPBDModel_Statics::NewProp_YoungsModulus_MetaData[] = {
		{ "Category", "Constraints" },
		{ "EditCondition", "bUseFEMConstraint && TetrahedralMesh != nullptr" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/PBDModel.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UPBDModel_Statics::NewProp_YoungsModulus = { "YoungsModulus", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UPBDModel, YoungsModulus), METADATA_PARAMS(Z_Construct_UClass_UPBDModel_Statics::NewProp_YoungsModulus_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UPBDModel_Statics::NewProp_YoungsModulus_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPBDModel_Statics::NewProp_PossionsRatio_MetaData[] = {
		{ "Category", "Constraints" },
		{ "EditCondition", "bUseFEMConstraint && TetrahedralMesh != nullptr" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/PBDModel.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UPBDModel_Statics::NewProp_PossionsRatio = { "PossionsRatio", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UPBDModel, PossionsRatio), METADATA_PARAMS(Z_Construct_UClass_UPBDModel_Statics::NewProp_PossionsRatio_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UPBDModel_Statics::NewProp_PossionsRatio_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPBDModel_Statics::NewProp_MaterialType_MetaData[] = {
		{ "Category", "Constraints" },
		{ "EditCondition", "bUseFEMConstraint && TetrahedralMesh != nullptr" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/PBDModel.h" },
	};
#endif
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UPBDModel_Statics::NewProp_MaterialType = { "MaterialType", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UPBDModel, MaterialType), Z_Construct_UEnum_Imstk_FemConstraintMaterial, METADATA_PARAMS(Z_Construct_UClass_UPBDModel_Statics::NewProp_MaterialType_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UPBDModel_Statics::NewProp_MaterialType_MetaData)) }; // 2062938130
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPBDModel_Statics::NewProp_bGenerateSurfaceFromTetrahedral_MetaData[] = {
		{ "Category", "General" },
		{ "Comment", "// Generate a new surface mesh from the tetrahedral mesh. Simulation may be more accurate, but most material information will be lost\n" },
		{ "EditCondition", "TetrahedralMesh != nullptr" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/PBDModel.h" },
		{ "ToolTip", "Generate a new surface mesh from the tetrahedral mesh. Simulation may be more accurate, but most material information will be lost" },
	};
#endif
	void Z_Construct_UClass_UPBDModel_Statics::NewProp_bGenerateSurfaceFromTetrahedral_SetBit(void* Obj)
	{
		((UPBDModel*)Obj)->bGenerateSurfaceFromTetrahedral = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UPBDModel_Statics::NewProp_bGenerateSurfaceFromTetrahedral = { "bGenerateSurfaceFromTetrahedral", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UPBDModel), &Z_Construct_UClass_UPBDModel_Statics::NewProp_bGenerateSurfaceFromTetrahedral_SetBit, METADATA_PARAMS(Z_Construct_UClass_UPBDModel_Statics::NewProp_bGenerateSurfaceFromTetrahedral_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UPBDModel_Statics::NewProp_bGenerateSurfaceFromTetrahedral_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPBDModel_Statics::NewProp_MeshComp_MetaData[] = {
		{ "Comment", "// Procedural mesh component attached to the actor (will be generated if one is not attached)\n" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/PBDModel.h" },
		{ "ToolTip", "Procedural mesh component attached to the actor (will be generated if one is not attached)" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UPBDModel_Statics::NewProp_MeshComp = { "MeshComp", nullptr, (EPropertyFlags)0x0020080000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UPBDModel, MeshComp), Z_Construct_UClass_UProceduralMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UPBDModel_Statics::NewProp_MeshComp_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UPBDModel_Statics::NewProp_MeshComp_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UPBDModel_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPBDModel_Statics::NewProp_TetrahedralMesh,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPBDModel_Statics::NewProp_bUseDihedralConstraint,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPBDModel_Statics::NewProp_DihedralConstraint,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPBDModel_Statics::NewProp_bUseVolumeConstraint,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPBDModel_Statics::NewProp_VolumeConstraint,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPBDModel_Statics::NewProp_bUseFEMConstraint,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPBDModel_Statics::NewProp_YoungsModulus,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPBDModel_Statics::NewProp_PossionsRatio,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPBDModel_Statics::NewProp_MaterialType,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPBDModel_Statics::NewProp_bGenerateSurfaceFromTetrahedral,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPBDModel_Statics::NewProp_MeshComp,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UPBDModel_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPBDModel>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UPBDModel_Statics::ClassParams = {
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
		if (!Z_Registration_Info_UClass_UPBDModel.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UPBDModel.OuterSingleton, Z_Construct_UClass_UPBDModel_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UPBDModel.OuterSingleton;
	}
	template<> IMSTK_API UClass* StaticClass<UPBDModel>()
	{
		return UPBDModel::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UPBDModel);
	struct Z_CompiledInDeferFile_FID_HostProject_Plugins_Imstk_Source_Imstk_Public_PBDModel_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_Imstk_Source_Imstk_Public_PBDModel_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UPBDModel, UPBDModel::StaticClass, TEXT("UPBDModel"), &Z_Registration_Info_UClass_UPBDModel, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UPBDModel), 3407809905U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_Imstk_Source_Imstk_Public_PBDModel_h_2082425441(TEXT("/Script/Imstk"),
		Z_CompiledInDeferFile_FID_HostProject_Plugins_Imstk_Source_Imstk_Public_PBDModel_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HostProject_Plugins_Imstk_Source_Imstk_Public_PBDModel_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
