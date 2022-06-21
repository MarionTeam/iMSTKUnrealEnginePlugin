// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Imstk/Public/CollisionInteraction.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCollisionInteraction() {}
// Cross Module References
	IMSTK_API UEnum* Z_Construct_UEnum_Imstk_ECollisionInteractionType();
	UPackage* Z_Construct_UPackage__Script_Imstk();
	IMSTK_API UClass* Z_Construct_UClass_UCollisionInteraction_NoRegister();
	IMSTK_API UClass* Z_Construct_UClass_UCollisionInteraction();
	IMSTK_API UClass* Z_Construct_UClass_UImstkInteraction();
	IMSTK_API UClass* Z_Construct_UClass_UDynamicalModel_NoRegister();
// End Cross Module References
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_ECollisionInteractionType;
	static UEnum* ECollisionInteractionType_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_ECollisionInteractionType.OuterSingleton)
		{
			Z_Registration_Info_UEnum_ECollisionInteractionType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_Imstk_ECollisionInteractionType, Z_Construct_UPackage__Script_Imstk(), TEXT("ECollisionInteractionType"));
		}
		return Z_Registration_Info_UEnum_ECollisionInteractionType.OuterSingleton;
	}
	template<> IMSTK_API UEnum* StaticEnum<ECollisionInteractionType>()
	{
		return ECollisionInteractionType_StaticEnum();
	}
	struct Z_Construct_UEnum_Imstk_ECollisionInteractionType_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_Imstk_ECollisionInteractionType_Statics::Enumerators[] = {
		{ "Auto", (int64)Auto },
		{ "ClosedSurfaceMeshToMeshCD", (int64)ClosedSurfaceMeshToMeshCD },
		{ "SurfaceMeshToSurfaceMeshCD", (int64)SurfaceMeshToSurfaceMeshCD },
		{ "MeshToMeshBruteForceCD", (int64)MeshToMeshBruteForceCD },
		{ "SurfaceMeshToSphereCD", (int64)SurfaceMeshToSphereCD },
		{ "SurfaceMeshToCapsuleCD", (int64)SurfaceMeshToCapsuleCD },
		{ "SphereToSphereCD", (int64)SphereToSphereCD },
		{ "PointSetToSphereCD", (int64)PointSetToSphereCD },
		{ "PointSetToCapsuleCD", (int64)PointSetToCapsuleCD },
		{ "PointSetToOrientedBoxCD", (int64)PointSetToOrientedBoxCD },
		{ "PointSetToPlaneCD", (int64)PointSetToPlaneCD },
		{ "UnidirectionalPlaneToSphereCD", (int64)UnidirectionalPlaneToSphereCD },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_Imstk_ECollisionInteractionType_Statics::Enum_MetaDataParams[] = {
		{ "Auto.Name", "Auto" },
		{ "ClosedSurfaceMeshToMeshCD.Name", "ClosedSurfaceMeshToMeshCD" },
		{ "Comment", "// Defines the different types of collisions. Values must have the same name as the collision in imstk\n" },
		{ "MeshToMeshBruteForceCD.Name", "MeshToMeshBruteForceCD" },
		{ "ModuleRelativePath", "Public/CollisionInteraction.h" },
		{ "PointSetToCapsuleCD.Name", "PointSetToCapsuleCD" },
		{ "PointSetToOrientedBoxCD.Name", "PointSetToOrientedBoxCD" },
		{ "PointSetToPlaneCD.Name", "PointSetToPlaneCD" },
		{ "PointSetToSphereCD.Name", "PointSetToSphereCD" },
		{ "SphereToSphereCD.Name", "SphereToSphereCD" },
		{ "SurfaceMeshToCapsuleCD.Name", "SurfaceMeshToCapsuleCD" },
		{ "SurfaceMeshToSphereCD.Name", "SurfaceMeshToSphereCD" },
		{ "SurfaceMeshToSurfaceMeshCD.Name", "SurfaceMeshToSurfaceMeshCD" },
		{ "ToolTip", "Defines the different types of collisions. Values must have the same name as the collision in imstk" },
		{ "UnidirectionalPlaneToSphereCD.Name", "UnidirectionalPlaneToSphereCD" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_Imstk_ECollisionInteractionType_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_Imstk,
		nullptr,
		"ECollisionInteractionType",
		"ECollisionInteractionType",
		Z_Construct_UEnum_Imstk_ECollisionInteractionType_Statics::Enumerators,
		UE_ARRAY_COUNT(Z_Construct_UEnum_Imstk_ECollisionInteractionType_Statics::Enumerators),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::Regular,
		METADATA_PARAMS(Z_Construct_UEnum_Imstk_ECollisionInteractionType_Statics::Enum_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UEnum_Imstk_ECollisionInteractionType_Statics::Enum_MetaDataParams))
	};
	UEnum* Z_Construct_UEnum_Imstk_ECollisionInteractionType()
	{
		if (!Z_Registration_Info_UEnum_ECollisionInteractionType.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_ECollisionInteractionType.InnerSingleton, Z_Construct_UEnum_Imstk_ECollisionInteractionType_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_ECollisionInteractionType.InnerSingleton;
	}
	DEFINE_FUNCTION(UCollisionInteraction::execInit)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Init();
		P_NATIVE_END;
	}
	void UCollisionInteraction::StaticRegisterNativesUCollisionInteraction()
	{
		UClass* Class = UCollisionInteraction::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "Init", &UCollisionInteraction::execInit },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UCollisionInteraction_Init_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCollisionInteraction_Init_Statics::Function_MetaDataParams[] = {
		{ "Category", "iMSTKCollision" },
		{ "Comment", "/** Initializes the interaction between set models in imstk\n\x09* @return None\n\x09*/" },
		{ "ModuleRelativePath", "Public/CollisionInteraction.h" },
		{ "ToolTip", "Initializes the interaction between set models in imstk\n@return None" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCollisionInteraction_Init_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCollisionInteraction, nullptr, "Init", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020400, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UCollisionInteraction_Init_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UCollisionInteraction_Init_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UCollisionInteraction_Init()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCollisionInteraction_Init_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UCollisionInteraction);
	UClass* Z_Construct_UClass_UCollisionInteraction_NoRegister()
	{
		return UCollisionInteraction::StaticClass();
	}
	struct Z_Construct_UClass_UCollisionInteraction_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Model1_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Model1;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Model2_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Model2;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Friction_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Friction;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Stiffness_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Stiffness;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Restitution_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Restitution;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UCollisionInteraction_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UImstkInteraction,
		(UObject* (*)())Z_Construct_UPackage__Script_Imstk,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UCollisionInteraction_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UCollisionInteraction_Init, "Init" }, // 2292608433
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCollisionInteraction_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Comment", "/** \\file CollisionInteraction.h\n *  \\brief Class used to create and represent the collision interaction in imstk\n *  \\details Can be created in blueprint to make the imstk collision interaction and initialize using the imstk subsystem. Requires models to be set. Collision type may be left as auto automatically determine the collision type.\n */" },
		{ "IncludePath", "CollisionInteraction.h" },
		{ "ModuleRelativePath", "Public/CollisionInteraction.h" },
		{ "ToolTip", "\\file CollisionInteraction.h\n\\brief Class used to create and represent the collision interaction in imstk\n\\details Can be created in blueprint to make the imstk collision interaction and initialize using the imstk subsystem. Requires models to be set. Collision type may be left as auto automatically determine the collision type." },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCollisionInteraction_Statics::NewProp_Model1_MetaData[] = {
		{ "Category", "Collision Interaction" },
		{ "Comment", "// The models that the collision interaction will be made between. Can be set in blueprint \n" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/CollisionInteraction.h" },
		{ "ToolTip", "The models that the collision interaction will be made between. Can be set in blueprint" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UCollisionInteraction_Statics::NewProp_Model1 = { "Model1", nullptr, (EPropertyFlags)0x00100000000a000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UCollisionInteraction, Model1), Z_Construct_UClass_UDynamicalModel_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UCollisionInteraction_Statics::NewProp_Model1_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCollisionInteraction_Statics::NewProp_Model1_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCollisionInteraction_Statics::NewProp_Model2_MetaData[] = {
		{ "Category", "Collision Interaction" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/CollisionInteraction.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UCollisionInteraction_Statics::NewProp_Model2 = { "Model2", nullptr, (EPropertyFlags)0x00100000000a000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UCollisionInteraction, Model2), Z_Construct_UClass_UDynamicalModel_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UCollisionInteraction_Statics::NewProp_Model2_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCollisionInteraction_Statics::NewProp_Model2_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCollisionInteraction_Statics::NewProp_Friction_MetaData[] = {
		{ "Category", "Collision Interaction" },
		{ "ModuleRelativePath", "Public/CollisionInteraction.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCollisionInteraction_Statics::NewProp_Friction = { "Friction", nullptr, (EPropertyFlags)0x0010000000020005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UCollisionInteraction, Friction), METADATA_PARAMS(Z_Construct_UClass_UCollisionInteraction_Statics::NewProp_Friction_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCollisionInteraction_Statics::NewProp_Friction_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCollisionInteraction_Statics::NewProp_Stiffness_MetaData[] = {
		{ "Category", "Collision Interaction" },
		{ "ModuleRelativePath", "Public/CollisionInteraction.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCollisionInteraction_Statics::NewProp_Stiffness = { "Stiffness", nullptr, (EPropertyFlags)0x0010000000020005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UCollisionInteraction, Stiffness), METADATA_PARAMS(Z_Construct_UClass_UCollisionInteraction_Statics::NewProp_Stiffness_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCollisionInteraction_Statics::NewProp_Stiffness_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCollisionInteraction_Statics::NewProp_Restitution_MetaData[] = {
		{ "Category", "Collision Interaction" },
		{ "ModuleRelativePath", "Public/CollisionInteraction.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCollisionInteraction_Statics::NewProp_Restitution = { "Restitution", nullptr, (EPropertyFlags)0x0010000000020005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UCollisionInteraction, Restitution), METADATA_PARAMS(Z_Construct_UClass_UCollisionInteraction_Statics::NewProp_Restitution_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCollisionInteraction_Statics::NewProp_Restitution_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UCollisionInteraction_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCollisionInteraction_Statics::NewProp_Model1,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCollisionInteraction_Statics::NewProp_Model2,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCollisionInteraction_Statics::NewProp_Friction,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCollisionInteraction_Statics::NewProp_Stiffness,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCollisionInteraction_Statics::NewProp_Restitution,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UCollisionInteraction_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCollisionInteraction>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UCollisionInteraction_Statics::ClassParams = {
		&UCollisionInteraction::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UCollisionInteraction_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UCollisionInteraction_Statics::PropPointers),
		0,
		0x009000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UCollisionInteraction_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UCollisionInteraction_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UCollisionInteraction()
	{
		if (!Z_Registration_Info_UClass_UCollisionInteraction.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UCollisionInteraction.OuterSingleton, Z_Construct_UClass_UCollisionInteraction_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UCollisionInteraction.OuterSingleton;
	}
	template<> IMSTK_API UClass* StaticClass<UCollisionInteraction>()
	{
		return UCollisionInteraction::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UCollisionInteraction);
	struct Z_CompiledInDeferFile_FID_HostProject_Plugins_Imstk_Source_Imstk_Public_CollisionInteraction_h_Statics
	{
		static const FEnumRegisterCompiledInInfo EnumInfo[];
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FEnumRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_Imstk_Source_Imstk_Public_CollisionInteraction_h_Statics::EnumInfo[] = {
		{ ECollisionInteractionType_StaticEnum, TEXT("ECollisionInteractionType"), &Z_Registration_Info_UEnum_ECollisionInteractionType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2208274567U) },
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_Imstk_Source_Imstk_Public_CollisionInteraction_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UCollisionInteraction, UCollisionInteraction::StaticClass, TEXT("UCollisionInteraction"), &Z_Registration_Info_UClass_UCollisionInteraction, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UCollisionInteraction), 4099637194U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_Imstk_Source_Imstk_Public_CollisionInteraction_h_494993702(TEXT("/Script/Imstk"),
		Z_CompiledInDeferFile_FID_HostProject_Plugins_Imstk_Source_Imstk_Public_CollisionInteraction_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HostProject_Plugins_Imstk_Source_Imstk_Public_CollisionInteraction_h_Statics::ClassInfo),
		nullptr, 0,
		Z_CompiledInDeferFile_FID_HostProject_Plugins_Imstk_Source_Imstk_Public_CollisionInteraction_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HostProject_Plugins_Imstk_Source_Imstk_Public_CollisionInteraction_h_Statics::EnumInfo));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
