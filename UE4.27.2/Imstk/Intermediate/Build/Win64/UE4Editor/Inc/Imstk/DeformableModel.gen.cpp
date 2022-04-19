// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Imstk/Public/DeformableModel.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeDeformableModel() {}
// Cross Module References
	IMSTK_API UEnum* Z_Construct_UEnum_Imstk_FemConstraintMaterial();
	UPackage* Z_Construct_UPackage__Script_Imstk();
	IMSTK_API UClass* Z_Construct_UClass_UDeformableModel_NoRegister();
	IMSTK_API UClass* Z_Construct_UClass_UDeformableModel();
	IMSTK_API UClass* Z_Construct_UClass_UDynamicalModel();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
// End Cross Module References
	static UEnum* FemConstraintMaterial_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_Imstk_FemConstraintMaterial, Z_Construct_UPackage__Script_Imstk(), TEXT("FemConstraintMaterial"));
		}
		return Singleton;
	}
	template<> IMSTK_API UEnum* StaticEnum<FemConstraintMaterial>()
	{
		return FemConstraintMaterial_StaticEnum();
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_FemConstraintMaterial(FemConstraintMaterial_StaticEnum, TEXT("/Script/Imstk"), TEXT("FemConstraintMaterial"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_Imstk_FemConstraintMaterial_Hash() { return 2993790571U; }
	UEnum* Z_Construct_UEnum_Imstk_FemConstraintMaterial()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_Imstk();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("FemConstraintMaterial"), 0, Get_Z_Construct_UEnum_Imstk_FemConstraintMaterial_Hash(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "Linear", (int64)Linear },
				{ "Corotation", (int64)Corotation },
				{ "StVK", (int64)StVK },
				{ "NeoHookean", (int64)NeoHookean },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "Comment", "// Create same enum for Fem Material type to expose it in editor\n" },
				{ "Corotation.Name", "Corotation" },
				{ "Linear.Name", "Linear" },
				{ "ModuleRelativePath", "Public/DeformableModel.h" },
				{ "NeoHookean.Name", "NeoHookean" },
				{ "StVK.Name", "StVK" },
				{ "ToolTip", "Create same enum for Fem Material type to expose it in editor" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_Imstk,
				nullptr,
				"FemConstraintMaterial",
				"FemConstraintMaterial",
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
	void UDeformableModel::StaticRegisterNativesUDeformableModel()
	{
	}
	UClass* Z_Construct_UClass_UDeformableModel_NoRegister()
	{
		return UDeformableModel::StaticClass();
	}
	struct Z_Construct_UClass_UDeformableModel_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Mass_MetaData[];
#endif
		static const UE4CodeGen_Private::FDoublePropertyParams NewProp_Mass;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ViscousDampingCoeff_MetaData[];
#endif
		static const UE4CodeGen_Private::FDoublePropertyParams NewProp_ViscousDampingCoeff;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ContactStiffness_MetaData[];
#endif
		static const UE4CodeGen_Private::FDoublePropertyParams NewProp_ContactStiffness;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bUseDistanceConstraint_MetaData[];
#endif
		static void NewProp_bUseDistanceConstraint_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bUseDistanceConstraint;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_DistanceConstraint_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_DistanceConstraint;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bUseConstantDensityConstraint_MetaData[];
#endif
		static void NewProp_bUseConstantDensityConstraint_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bUseConstantDensityConstraint;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ConstantDensityConstraint_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ConstantDensityConstraint;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bUseAreaConstraint_MetaData[];
#endif
		static void NewProp_bUseAreaConstraint_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bUseAreaConstraint;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_AreaConstraint_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_AreaConstraint;
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_FixedNodes_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_FixedNodes_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_FixedNodes;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_BoundaryConditionActors_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_BoundaryConditionActors_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_BoundaryConditionActors;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bInverseBoundary_MetaData[];
#endif
		static void NewProp_bInverseBoundary_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bInverseBoundary;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UDeformableModel_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UDynamicalModel,
		(UObject* (*)())Z_Construct_UPackage__Script_Imstk,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDeformableModel_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/** \\file DeformableModel.h\n *  \\brief Component used to turn the actor it is attached to into a deformable model in imstk\n *  \\details Must have either a static or procedural mesh attached to the actor. Static meshes will be converted to procedural. Can attach a tetrahedral mesh to use volumetric constraints.\n */" },
		{ "IncludePath", "DeformableModel.h" },
		{ "ModuleRelativePath", "Public/DeformableModel.h" },
		{ "ToolTip", "\\file DeformableModel.h\n\\brief Component used to turn the actor it is attached to into a deformable model in imstk\n\\details Must have either a static or procedural mesh attached to the actor. Static meshes will be converted to procedural. Can attach a tetrahedral mesh to use volumetric constraints." },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDeformableModel_Statics::NewProp_Mass_MetaData[] = {
		{ "Category", "General" },
		{ "Comment", "// PBD model config settings\n" },
		{ "ModuleRelativePath", "Public/DeformableModel.h" },
		{ "ToolTip", "PBD model config settings" },
	};
#endif
	const UE4CodeGen_Private::FDoublePropertyParams Z_Construct_UClass_UDeformableModel_Statics::NewProp_Mass = { "Mass", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Double, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UDeformableModel, Mass), METADATA_PARAMS(Z_Construct_UClass_UDeformableModel_Statics::NewProp_Mass_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UDeformableModel_Statics::NewProp_Mass_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDeformableModel_Statics::NewProp_ViscousDampingCoeff_MetaData[] = {
		{ "Category", "General" },
		{ "ModuleRelativePath", "Public/DeformableModel.h" },
	};
#endif
	const UE4CodeGen_Private::FDoublePropertyParams Z_Construct_UClass_UDeformableModel_Statics::NewProp_ViscousDampingCoeff = { "ViscousDampingCoeff", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Double, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UDeformableModel, ViscousDampingCoeff), METADATA_PARAMS(Z_Construct_UClass_UDeformableModel_Statics::NewProp_ViscousDampingCoeff_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UDeformableModel_Statics::NewProp_ViscousDampingCoeff_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDeformableModel_Statics::NewProp_ContactStiffness_MetaData[] = {
		{ "Category", "General" },
		{ "ModuleRelativePath", "Public/DeformableModel.h" },
	};
#endif
	const UE4CodeGen_Private::FDoublePropertyParams Z_Construct_UClass_UDeformableModel_Statics::NewProp_ContactStiffness = { "ContactStiffness", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Double, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UDeformableModel, ContactStiffness), METADATA_PARAMS(Z_Construct_UClass_UDeformableModel_Statics::NewProp_ContactStiffness_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UDeformableModel_Statics::NewProp_ContactStiffness_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDeformableModel_Statics::NewProp_bUseDistanceConstraint_MetaData[] = {
		{ "Category", "Constraints" },
		{ "ModuleRelativePath", "Public/DeformableModel.h" },
	};
#endif
	void Z_Construct_UClass_UDeformableModel_Statics::NewProp_bUseDistanceConstraint_SetBit(void* Obj)
	{
		((UDeformableModel*)Obj)->bUseDistanceConstraint = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UDeformableModel_Statics::NewProp_bUseDistanceConstraint = { "bUseDistanceConstraint", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UDeformableModel), &Z_Construct_UClass_UDeformableModel_Statics::NewProp_bUseDistanceConstraint_SetBit, METADATA_PARAMS(Z_Construct_UClass_UDeformableModel_Statics::NewProp_bUseDistanceConstraint_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UDeformableModel_Statics::NewProp_bUseDistanceConstraint_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDeformableModel_Statics::NewProp_DistanceConstraint_MetaData[] = {
		{ "Category", "Constraints" },
		{ "EditCondition", "bUseDistanceConstraint" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/DeformableModel.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UDeformableModel_Statics::NewProp_DistanceConstraint = { "DistanceConstraint", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UDeformableModel, DistanceConstraint), METADATA_PARAMS(Z_Construct_UClass_UDeformableModel_Statics::NewProp_DistanceConstraint_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UDeformableModel_Statics::NewProp_DistanceConstraint_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDeformableModel_Statics::NewProp_bUseConstantDensityConstraint_MetaData[] = {
		{ "Category", "Constraints" },
		{ "Comment", "/*UPROPERTY(EditAnywhere, meta = (EditCondition = \"TetrahedralMesh == nullptr\", EditConditionHides), Category = \"Constraints\")\n\x09\x09""bool bUseDihedralConstraint = false;\n\x09UPROPERTY(EditAnywhere, meta = (EditCondition = \"bUseDihedralConstraint && TetrahedralMesh == nullptr\", EditConditionHides), Category = \"Constraints\")\n\x09\x09""float DihedralConstraint = 0.0;\n\n\x09UPROPERTY(EditAnywhere, meta = (EditCondition = \"TetrahedralMesh != nullptr\", EditConditionHides), Category = \"Constraints\")\n\x09\x09""bool bUseVolumeConstraint = false;\n\x09UPROPERTY(EditAnywhere, meta = (EditCondition = \"bUseVolumeConstraint && TetrahedralMesh != nullptr\", EditConditionHides), Category = \"Constraints\")\n\x09\x09""float VolumeConstraint = 0.0;\n\n\x09UPROPERTY(EditAnywhere, meta = (EditCondition = \"TetrahedralMesh != nullptr\", EditConditionHides), Category = \"Constraints\")\n\x09\x09""bool bUseFEMConstraint = false;\n\x09UPROPERTY(EditAnywhere, meta = (EditCondition = \"bUseFEMConstraint && TetrahedralMesh != nullptr\", EditConditionHides), Category = \"Constraints\")\n\x09\x09""float YoungsModulus = 0.0;\n\x09UPROPERTY(EditAnywhere, meta = (EditCondition = \"bUseFEMConstraint && TetrahedralMesh != nullptr\", EditConditionHides), Category = \"Constraints\")\n\x09\x09""float PossionsRatio = 0.0;\n\x09UPROPERTY(EditAnywhere, meta = (EditCondition = \"bUseFEMConstraint && TetrahedralMesh != nullptr\", EditConditionHides), Category = \"Constraints\")\n\x09\x09TEnumAsByte<FemConstraintMaterial> MaterialType = FemConstraintMaterial::StVK;*/" },
		{ "ModuleRelativePath", "Public/DeformableModel.h" },
		{ "ToolTip", "UPROPERTY(EditAnywhere, meta = (EditCondition = \"TetrahedralMesh == nullptr\", EditConditionHides), Category = \"Constraints\")\n               bool bUseDihedralConstraint = false;\n       UPROPERTY(EditAnywhere, meta = (EditCondition = \"bUseDihedralConstraint && TetrahedralMesh == nullptr\", EditConditionHides), Category = \"Constraints\")\n               float DihedralConstraint = 0.0;\n\n       UPROPERTY(EditAnywhere, meta = (EditCondition = \"TetrahedralMesh != nullptr\", EditConditionHides), Category = \"Constraints\")\n               bool bUseVolumeConstraint = false;\n       UPROPERTY(EditAnywhere, meta = (EditCondition = \"bUseVolumeConstraint && TetrahedralMesh != nullptr\", EditConditionHides), Category = \"Constraints\")\n               float VolumeConstraint = 0.0;\n\n       UPROPERTY(EditAnywhere, meta = (EditCondition = \"TetrahedralMesh != nullptr\", EditConditionHides), Category = \"Constraints\")\n               bool bUseFEMConstraint = false;\n       UPROPERTY(EditAnywhere, meta = (EditCondition = \"bUseFEMConstraint && TetrahedralMesh != nullptr\", EditConditionHides), Category = \"Constraints\")\n               float YoungsModulus = 0.0;\n       UPROPERTY(EditAnywhere, meta = (EditCondition = \"bUseFEMConstraint && TetrahedralMesh != nullptr\", EditConditionHides), Category = \"Constraints\")\n               float PossionsRatio = 0.0;\n       UPROPERTY(EditAnywhere, meta = (EditCondition = \"bUseFEMConstraint && TetrahedralMesh != nullptr\", EditConditionHides), Category = \"Constraints\")\n               TEnumAsByte<FemConstraintMaterial> MaterialType = FemConstraintMaterial::StVK;" },
	};
#endif
	void Z_Construct_UClass_UDeformableModel_Statics::NewProp_bUseConstantDensityConstraint_SetBit(void* Obj)
	{
		((UDeformableModel*)Obj)->bUseConstantDensityConstraint = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UDeformableModel_Statics::NewProp_bUseConstantDensityConstraint = { "bUseConstantDensityConstraint", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UDeformableModel), &Z_Construct_UClass_UDeformableModel_Statics::NewProp_bUseConstantDensityConstraint_SetBit, METADATA_PARAMS(Z_Construct_UClass_UDeformableModel_Statics::NewProp_bUseConstantDensityConstraint_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UDeformableModel_Statics::NewProp_bUseConstantDensityConstraint_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDeformableModel_Statics::NewProp_ConstantDensityConstraint_MetaData[] = {
		{ "Category", "Constraints" },
		{ "EditCondition", "bUseConstantDensityConstraint" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/DeformableModel.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UDeformableModel_Statics::NewProp_ConstantDensityConstraint = { "ConstantDensityConstraint", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UDeformableModel, ConstantDensityConstraint), METADATA_PARAMS(Z_Construct_UClass_UDeformableModel_Statics::NewProp_ConstantDensityConstraint_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UDeformableModel_Statics::NewProp_ConstantDensityConstraint_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDeformableModel_Statics::NewProp_bUseAreaConstraint_MetaData[] = {
		{ "Category", "Constraints" },
		{ "ModuleRelativePath", "Public/DeformableModel.h" },
	};
#endif
	void Z_Construct_UClass_UDeformableModel_Statics::NewProp_bUseAreaConstraint_SetBit(void* Obj)
	{
		((UDeformableModel*)Obj)->bUseAreaConstraint = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UDeformableModel_Statics::NewProp_bUseAreaConstraint = { "bUseAreaConstraint", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UDeformableModel), &Z_Construct_UClass_UDeformableModel_Statics::NewProp_bUseAreaConstraint_SetBit, METADATA_PARAMS(Z_Construct_UClass_UDeformableModel_Statics::NewProp_bUseAreaConstraint_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UDeformableModel_Statics::NewProp_bUseAreaConstraint_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDeformableModel_Statics::NewProp_AreaConstraint_MetaData[] = {
		{ "Category", "Constraints" },
		{ "EditCondition", "bUseAreaConstraint" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/DeformableModel.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UDeformableModel_Statics::NewProp_AreaConstraint = { "AreaConstraint", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UDeformableModel, AreaConstraint), METADATA_PARAMS(Z_Construct_UClass_UDeformableModel_Statics::NewProp_AreaConstraint_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UDeformableModel_Statics::NewProp_AreaConstraint_MetaData)) };
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_UDeformableModel_Statics::NewProp_FixedNodes_Inner = { "FixedNodes", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDeformableModel_Statics::NewProp_FixedNodes_MetaData[] = {
		{ "Category", "Boundaries" },
		{ "Comment", "/** If assigned, the boundary conditions will be ignored*/" },
		{ "ModuleRelativePath", "Public/DeformableModel.h" },
		{ "ToolTip", "If assigned, the boundary conditions will be ignored" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UDeformableModel_Statics::NewProp_FixedNodes = { "FixedNodes", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UDeformableModel, FixedNodes), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_UDeformableModel_Statics::NewProp_FixedNodes_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UDeformableModel_Statics::NewProp_FixedNodes_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UDeformableModel_Statics::NewProp_BoundaryConditionActors_Inner = { "BoundaryConditionActors", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDeformableModel_Statics::NewProp_BoundaryConditionActors_MetaData[] = {
		{ "Category", "Boundaries" },
		{ "Comment", "/** The actor that determines the fixed vertices on the deformable model. Will be destroyed when starting the game*/" },
		{ "ModuleRelativePath", "Public/DeformableModel.h" },
		{ "ToolTip", "The actor that determines the fixed vertices on the deformable model. Will be destroyed when starting the game" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UDeformableModel_Statics::NewProp_BoundaryConditionActors = { "BoundaryConditionActors", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UDeformableModel, BoundaryConditionActors), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_UDeformableModel_Statics::NewProp_BoundaryConditionActors_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UDeformableModel_Statics::NewProp_BoundaryConditionActors_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDeformableModel_Statics::NewProp_bInverseBoundary_MetaData[] = {
		{ "Category", "Boundaries" },
		{ "Comment", "/** Fixes all vertices not in the actor's mesh*/" },
		{ "ModuleRelativePath", "Public/DeformableModel.h" },
		{ "ToolTip", "Fixes all vertices not in the actor's mesh" },
	};
#endif
	void Z_Construct_UClass_UDeformableModel_Statics::NewProp_bInverseBoundary_SetBit(void* Obj)
	{
		((UDeformableModel*)Obj)->bInverseBoundary = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UDeformableModel_Statics::NewProp_bInverseBoundary = { "bInverseBoundary", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UDeformableModel), &Z_Construct_UClass_UDeformableModel_Statics::NewProp_bInverseBoundary_SetBit, METADATA_PARAMS(Z_Construct_UClass_UDeformableModel_Statics::NewProp_bInverseBoundary_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UDeformableModel_Statics::NewProp_bInverseBoundary_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UDeformableModel_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDeformableModel_Statics::NewProp_Mass,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDeformableModel_Statics::NewProp_ViscousDampingCoeff,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDeformableModel_Statics::NewProp_ContactStiffness,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDeformableModel_Statics::NewProp_bUseDistanceConstraint,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDeformableModel_Statics::NewProp_DistanceConstraint,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDeformableModel_Statics::NewProp_bUseConstantDensityConstraint,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDeformableModel_Statics::NewProp_ConstantDensityConstraint,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDeformableModel_Statics::NewProp_bUseAreaConstraint,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDeformableModel_Statics::NewProp_AreaConstraint,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDeformableModel_Statics::NewProp_FixedNodes_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDeformableModel_Statics::NewProp_FixedNodes,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDeformableModel_Statics::NewProp_BoundaryConditionActors_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDeformableModel_Statics::NewProp_BoundaryConditionActors,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDeformableModel_Statics::NewProp_bInverseBoundary,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UDeformableModel_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDeformableModel>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UDeformableModel_Statics::ClassParams = {
		&UDeformableModel::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UDeformableModel_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UDeformableModel_Statics::PropPointers),
		0,
		0x00B000A5u,
		METADATA_PARAMS(Z_Construct_UClass_UDeformableModel_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UDeformableModel_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UDeformableModel()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UDeformableModel_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UDeformableModel, 919173881);
	template<> IMSTK_API UClass* StaticClass<UDeformableModel>()
	{
		return UDeformableModel::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UDeformableModel(Z_Construct_UClass_UDeformableModel, &UDeformableModel::StaticClass, TEXT("/Script/Imstk"), TEXT("UDeformableModel"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UDeformableModel);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
