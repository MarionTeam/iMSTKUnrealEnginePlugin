// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Imstk/Public/CollisionInteraction.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCollisionInteraction() {}
// Cross Module References
	IMSTK_API UEnum* Z_Construct_UEnum_Imstk_CollisionInteractionType();
	UPackage* Z_Construct_UPackage__Script_Imstk();
	IMSTK_API UClass* Z_Construct_UClass_UCollisionInteraction_NoRegister();
	IMSTK_API UClass* Z_Construct_UClass_UCollisionInteraction();
	IMSTK_API UClass* Z_Construct_UClass_UImstkInteraction();
	IMSTK_API UClass* Z_Construct_UClass_UDynamicalModel_NoRegister();
// End Cross Module References
	static UEnum* CollisionInteractionType_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_Imstk_CollisionInteractionType, Z_Construct_UPackage__Script_Imstk(), TEXT("CollisionInteractionType"));
		}
		return Singleton;
	}
	template<> IMSTK_API UEnum* StaticEnum<CollisionInteractionType>()
	{
		return CollisionInteractionType_StaticEnum();
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_CollisionInteractionType(CollisionInteractionType_StaticEnum, TEXT("/Script/Imstk"), TEXT("CollisionInteractionType"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_Imstk_CollisionInteractionType_Hash() { return 476572726U; }
	UEnum* Z_Construct_UEnum_Imstk_CollisionInteractionType()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_Imstk();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("CollisionInteractionType"), 0, Get_Z_Construct_UEnum_Imstk_CollisionInteractionType_Hash(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "Auto", (int64)Auto },
				{ "SurfaceMeshToSurfaceMeshCD", (int64)SurfaceMeshToSurfaceMeshCD },
				{ "MeshToMeshBruteForceCD", (int64)MeshToMeshBruteForceCD },
				{ "SurfaceMeshToSphereCD", (int64)SurfaceMeshToSphereCD },
				{ "SphereToSphereCD", (int64)SphereToSphereCD },
				{ "PointSetToSphereCD", (int64)PointSetToSphereCD },
				{ "PointSetToCapsuleCD", (int64)PointSetToCapsuleCD },
				{ "PointSetToOrientedBoxCD", (int64)PointSetToOrientedBoxCD },
				{ "PointSetToPlaneCD", (int64)PointSetToPlaneCD },
				{ "UnidirectionalPlaneToSphereCD", (int64)UnidirectionalPlaneToSphereCD },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "Auto.Name", "Auto" },
				{ "Comment", "// Defines the different types of collisions. Values must have the same name as the collision in imstk\n" },
				{ "MeshToMeshBruteForceCD.Name", "MeshToMeshBruteForceCD" },
				{ "ModuleRelativePath", "Public/CollisionInteraction.h" },
				{ "PointSetToCapsuleCD.Name", "PointSetToCapsuleCD" },
				{ "PointSetToOrientedBoxCD.Name", "PointSetToOrientedBoxCD" },
				{ "PointSetToPlaneCD.Name", "PointSetToPlaneCD" },
				{ "PointSetToSphereCD.Name", "PointSetToSphereCD" },
				{ "SphereToSphereCD.Name", "SphereToSphereCD" },
				{ "SurfaceMeshToSphereCD.Name", "SurfaceMeshToSphereCD" },
				{ "SurfaceMeshToSurfaceMeshCD.Name", "SurfaceMeshToSurfaceMeshCD" },
				{ "ToolTip", "Defines the different types of collisions. Values must have the same name as the collision in imstk" },
				{ "UnidirectionalPlaneToSphereCD.Name", "UnidirectionalPlaneToSphereCD" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_Imstk,
				nullptr,
				"CollisionInteractionType",
				"CollisionInteractionType",
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
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCollisionInteraction_Init_Statics::Function_MetaDataParams[] = {
		{ "Category", "iMSTKCollision" },
		{ "Comment", "/** Initializes the interaction between set models in imstk\n\x09* @return None\n\x09*/" },
		{ "ModuleRelativePath", "Public/CollisionInteraction.h" },
		{ "ToolTip", "Initializes the interaction between set models in imstk\n@return None" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UCollisionInteraction_Init_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCollisionInteraction, nullptr, "Init", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020400, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UCollisionInteraction_Init_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UCollisionInteraction_Init_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UCollisionInteraction_Init()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UCollisionInteraction_Init_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UCollisionInteraction_NoRegister()
	{
		return UCollisionInteraction::StaticClass();
	}
	struct Z_Construct_UClass_UCollisionInteraction_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Model1_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Model1;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Model2_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Model2;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Friction_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Friction;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Stiffness_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Stiffness;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Restitution_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Restitution;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UCollisionInteraction_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UImstkInteraction,
		(UObject* (*)())Z_Construct_UPackage__Script_Imstk,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UCollisionInteraction_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UCollisionInteraction_Init, "Init" }, // 2648521906
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCollisionInteraction_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Comment", "/** \\file CollisionInteraction.h\n *  \\brief Class used to create and represent the collision interaction in imstk\n *  \\details Can be created in blueprint to make the imstk collision interaction and initialize using the imstk subsystem. Requires models to be set. Collision type may be left as auto automatically determine the collision type.\n */" },
		{ "IncludePath", "CollisionInteraction.h" },
		{ "ModuleRelativePath", "Public/CollisionInteraction.h" },
		{ "ToolTip", "\\file CollisionInteraction.h\n\\brief Class used to create and represent the collision interaction in imstk\n\\details Can be created in blueprint to make the imstk collision interaction and initialize using the imstk subsystem. Requires models to be set. Collision type may be left as auto automatically determine the collision type." },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCollisionInteraction_Statics::NewProp_Model1_MetaData[] = {
		{ "Category", "Collision Interaction" },
		{ "Comment", "// The models that the collision interaction will be made between. Can be set in blueprint \n" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/CollisionInteraction.h" },
		{ "ToolTip", "The models that the collision interaction will be made between. Can be set in blueprint" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UCollisionInteraction_Statics::NewProp_Model1 = { "Model1", nullptr, (EPropertyFlags)0x00100000000a000d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UCollisionInteraction, Model1), Z_Construct_UClass_UDynamicalModel_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UCollisionInteraction_Statics::NewProp_Model1_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCollisionInteraction_Statics::NewProp_Model1_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCollisionInteraction_Statics::NewProp_Model2_MetaData[] = {
		{ "Category", "Collision Interaction" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/CollisionInteraction.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UCollisionInteraction_Statics::NewProp_Model2 = { "Model2", nullptr, (EPropertyFlags)0x00100000000a000d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UCollisionInteraction, Model2), Z_Construct_UClass_UDynamicalModel_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UCollisionInteraction_Statics::NewProp_Model2_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCollisionInteraction_Statics::NewProp_Model2_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCollisionInteraction_Statics::NewProp_Friction_MetaData[] = {
		{ "Category", "Collision Interaction" },
		{ "ModuleRelativePath", "Public/CollisionInteraction.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCollisionInteraction_Statics::NewProp_Friction = { "Friction", nullptr, (EPropertyFlags)0x0010000000020005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UCollisionInteraction, Friction), METADATA_PARAMS(Z_Construct_UClass_UCollisionInteraction_Statics::NewProp_Friction_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCollisionInteraction_Statics::NewProp_Friction_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCollisionInteraction_Statics::NewProp_Stiffness_MetaData[] = {
		{ "Category", "Collision Interaction" },
		{ "ModuleRelativePath", "Public/CollisionInteraction.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCollisionInteraction_Statics::NewProp_Stiffness = { "Stiffness", nullptr, (EPropertyFlags)0x0010000000020005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UCollisionInteraction, Stiffness), METADATA_PARAMS(Z_Construct_UClass_UCollisionInteraction_Statics::NewProp_Stiffness_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCollisionInteraction_Statics::NewProp_Stiffness_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCollisionInteraction_Statics::NewProp_Restitution_MetaData[] = {
		{ "Category", "Collision Interaction" },
		{ "ModuleRelativePath", "Public/CollisionInteraction.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCollisionInteraction_Statics::NewProp_Restitution = { "Restitution", nullptr, (EPropertyFlags)0x0010000000020005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UCollisionInteraction, Restitution), METADATA_PARAMS(Z_Construct_UClass_UCollisionInteraction_Statics::NewProp_Restitution_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCollisionInteraction_Statics::NewProp_Restitution_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UCollisionInteraction_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCollisionInteraction_Statics::NewProp_Model1,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCollisionInteraction_Statics::NewProp_Model2,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCollisionInteraction_Statics::NewProp_Friction,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCollisionInteraction_Statics::NewProp_Stiffness,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCollisionInteraction_Statics::NewProp_Restitution,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UCollisionInteraction_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCollisionInteraction>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UCollisionInteraction_Statics::ClassParams = {
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
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UCollisionInteraction_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UCollisionInteraction, 2216824098);
	template<> IMSTK_API UClass* StaticClass<UCollisionInteraction>()
	{
		return UCollisionInteraction::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UCollisionInteraction(Z_Construct_UClass_UCollisionInteraction, &UCollisionInteraction::StaticClass, TEXT("/Script/Imstk"), TEXT("UCollisionInteraction"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UCollisionInteraction);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
