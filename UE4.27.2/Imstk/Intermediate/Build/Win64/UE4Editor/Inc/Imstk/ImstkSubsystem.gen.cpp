// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Imstk/Public/ImstkSubsystem.h"
#include "Engine/Classes/Engine/GameInstance.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeImstkSubsystem() {}
// Cross Module References
	IMSTK_API UClass* Z_Construct_UClass_UImstkSubsystem_NoRegister();
	IMSTK_API UClass* Z_Construct_UClass_UImstkSubsystem();
	ENGINE_API UClass* Z_Construct_UClass_UGameInstanceSubsystem();
	UPackage* Z_Construct_UPackage__Script_Imstk();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	IMSTK_API UClass* Z_Construct_UClass_UImstkBehaviour_NoRegister();
	IMSTK_API UClass* Z_Construct_UClass_UImstkInteraction_NoRegister();
	IMSTK_API UClass* Z_Construct_UClass_UImstkController_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(UImstkSubsystem::execUpdateSimulation)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_DeltaTime);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->UpdateSimulation(Z_Param_DeltaTime);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UImstkSubsystem::execToggleSimulation)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->ToggleSimulation();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UImstkSubsystem::execImstkTest)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->ImstkTest();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UImstkSubsystem::execImstkInit)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->ImstkInit();
		P_NATIVE_END;
	}
	void UImstkSubsystem::StaticRegisterNativesUImstkSubsystem()
	{
		UClass* Class = UImstkSubsystem::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "ImstkInit", &UImstkSubsystem::execImstkInit },
			{ "ImstkTest", &UImstkSubsystem::execImstkTest },
			{ "ToggleSimulation", &UImstkSubsystem::execToggleSimulation },
			{ "UpdateSimulation", &UImstkSubsystem::execUpdateSimulation },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UImstkSubsystem_ImstkInit_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UImstkSubsystem_ImstkInit_Statics::Function_MetaDataParams[] = {
		{ "Category", "iMSTKSubsystem" },
		{ "Comment", "/** Function to initialize required managers for Imstk and then initialize all Imstk behaviours.\n\x09* @return None\n\x09*/" },
		{ "ModuleRelativePath", "Public/ImstkSubsystem.h" },
		{ "ToolTip", "Function to initialize required managers for Imstk and then initialize all Imstk behaviours.\n@return None" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UImstkSubsystem_ImstkInit_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UImstkSubsystem, nullptr, "ImstkInit", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UImstkSubsystem_ImstkInit_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UImstkSubsystem_ImstkInit_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UImstkSubsystem_ImstkInit()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UImstkSubsystem_ImstkInit_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UImstkSubsystem_ImstkTest_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UImstkSubsystem_ImstkTest_Statics::Function_MetaDataParams[] = {
		{ "Category", "iMSTKSubsystem" },
		{ "ModuleRelativePath", "Public/ImstkSubsystem.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UImstkSubsystem_ImstkTest_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UImstkSubsystem, nullptr, "ImstkTest", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UImstkSubsystem_ImstkTest_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UImstkSubsystem_ImstkTest_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UImstkSubsystem_ImstkTest()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UImstkSubsystem_ImstkTest_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UImstkSubsystem_ToggleSimulation_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UImstkSubsystem_ToggleSimulation_Statics::Function_MetaDataParams[] = {
		{ "Category", "iMSTKSubsystem" },
		{ "ModuleRelativePath", "Public/ImstkSubsystem.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UImstkSubsystem_ToggleSimulation_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UImstkSubsystem, nullptr, "ToggleSimulation", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UImstkSubsystem_ToggleSimulation_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UImstkSubsystem_ToggleSimulation_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UImstkSubsystem_ToggleSimulation()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UImstkSubsystem_ToggleSimulation_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UImstkSubsystem_UpdateSimulation_Statics
	{
		struct ImstkSubsystem_eventUpdateSimulation_Parms
		{
			float DeltaTime;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_DeltaTime;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UImstkSubsystem_UpdateSimulation_Statics::NewProp_DeltaTime = { "DeltaTime", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ImstkSubsystem_eventUpdateSimulation_Parms, DeltaTime), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UImstkSubsystem_UpdateSimulation_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UImstkSubsystem_UpdateSimulation_Statics::NewProp_DeltaTime,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UImstkSubsystem_UpdateSimulation_Statics::Function_MetaDataParams[] = {
		{ "Category", "iMSTKSubsystem" },
		{ "Comment", "/** Updates the scene and progresses by the amount of time provided\n\x09* @param DeltaTime - The amount of time to progress the scene\n\x09* @return None\n\x09*/" },
		{ "ModuleRelativePath", "Public/ImstkSubsystem.h" },
		{ "ToolTip", "Updates the scene and progresses by the amount of time provided\n@param DeltaTime - The amount of time to progress the scene\n@return None" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UImstkSubsystem_UpdateSimulation_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UImstkSubsystem, nullptr, "UpdateSimulation", nullptr, nullptr, sizeof(ImstkSubsystem_eventUpdateSimulation_Parms), Z_Construct_UFunction_UImstkSubsystem_UpdateSimulation_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UImstkSubsystem_UpdateSimulation_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UImstkSubsystem_UpdateSimulation_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UImstkSubsystem_UpdateSimulation_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UImstkSubsystem_UpdateSimulation()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UImstkSubsystem_UpdateSimulation_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UImstkSubsystem_NoRegister()
	{
		return UImstkSubsystem::StaticClass();
	}
	struct Z_Construct_UClass_UImstkSubsystem_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_RigidBodyMaxIterations_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_RigidBodyMaxIterations;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Gravity_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Gravity;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_AllBehaviours_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_AllBehaviours_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_AllBehaviours;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_AllInteractions_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_AllInteractions_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_AllInteractions;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Controller_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Controller;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UImstkSubsystem_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UGameInstanceSubsystem,
		(UObject* (*)())Z_Construct_UPackage__Script_Imstk,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UImstkSubsystem_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UImstkSubsystem_ImstkInit, "ImstkInit" }, // 4043360527
		{ &Z_Construct_UFunction_UImstkSubsystem_ImstkTest, "ImstkTest" }, // 3072948585
		{ &Z_Construct_UFunction_UImstkSubsystem_ToggleSimulation, "ToggleSimulation" }, // 4016532239
		{ &Z_Construct_UFunction_UImstkSubsystem_UpdateSimulation, "UpdateSimulation" }, // 3845281184
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UImstkSubsystem_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/** \\file ImstkSubsystem.h\n *  \\brief Subsystem to manage and initialize Imstk.\n *  \\details Creates the Imstk scene manager, scene and rigidbody model as well as initializing all imstk behaviours assigned in Unreal.\n */" },
		{ "IncludePath", "ImstkSubsystem.h" },
		{ "ModuleRelativePath", "Public/ImstkSubsystem.h" },
		{ "ToolTip", "\\file ImstkSubsystem.h\n\\brief Subsystem to manage and initialize Imstk.\n\\details Creates the Imstk scene manager, scene and rigidbody model as well as initializing all imstk behaviours assigned in Unreal." },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UImstkSubsystem_Statics::NewProp_RigidBodyMaxIterations_MetaData[] = {
		{ "Category", "General" },
		{ "Comment", "// Values to be set as defaults in the manager for imstk\n" },
		{ "ModuleRelativePath", "Public/ImstkSubsystem.h" },
		{ "ToolTip", "Values to be set as defaults in the manager for imstk" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_UImstkSubsystem_Statics::NewProp_RigidBodyMaxIterations = { "RigidBodyMaxIterations", nullptr, (EPropertyFlags)0x0010000000020005, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UImstkSubsystem, RigidBodyMaxIterations), METADATA_PARAMS(Z_Construct_UClass_UImstkSubsystem_Statics::NewProp_RigidBodyMaxIterations_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UImstkSubsystem_Statics::NewProp_RigidBodyMaxIterations_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UImstkSubsystem_Statics::NewProp_Gravity_MetaData[] = {
		{ "Category", "General" },
		{ "ModuleRelativePath", "Public/ImstkSubsystem.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_UImstkSubsystem_Statics::NewProp_Gravity = { "Gravity", nullptr, (EPropertyFlags)0x0010000000020005, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UImstkSubsystem, Gravity), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UClass_UImstkSubsystem_Statics::NewProp_Gravity_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UImstkSubsystem_Statics::NewProp_Gravity_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UImstkSubsystem_Statics::NewProp_AllBehaviours_Inner = { "AllBehaviours", nullptr, (EPropertyFlags)0x00000000000a0008, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_UImstkBehaviour_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UImstkSubsystem_Statics::NewProp_AllBehaviours_MetaData[] = {
		{ "Category", "General" },
		{ "Comment", "// All ImstkBehaviours attached to objects in Unreal, used to initialize the objects\n" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/ImstkSubsystem.h" },
		{ "ToolTip", "All ImstkBehaviours attached to objects in Unreal, used to initialize the objects" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UImstkSubsystem_Statics::NewProp_AllBehaviours = { "AllBehaviours", nullptr, (EPropertyFlags)0x001000800002000d, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UImstkSubsystem, AllBehaviours), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_UImstkSubsystem_Statics::NewProp_AllBehaviours_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UImstkSubsystem_Statics::NewProp_AllBehaviours_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UImstkSubsystem_Statics::NewProp_AllInteractions_Inner = { "AllInteractions", nullptr, (EPropertyFlags)0x0000000000020000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_UImstkInteraction_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UImstkSubsystem_Statics::NewProp_AllInteractions_MetaData[] = {
		{ "Category", "General" },
		{ "Comment", "// All ImstkInteractions in Unreal, used to initialize the imstk interactions between objects\n" },
		{ "ModuleRelativePath", "Public/ImstkSubsystem.h" },
		{ "ToolTip", "All ImstkInteractions in Unreal, used to initialize the imstk interactions between objects" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UImstkSubsystem_Statics::NewProp_AllInteractions = { "AllInteractions", nullptr, (EPropertyFlags)0x0010000000020005, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UImstkSubsystem, AllInteractions), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_UImstkSubsystem_Statics::NewProp_AllInteractions_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UImstkSubsystem_Statics::NewProp_AllInteractions_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UImstkSubsystem_Statics::NewProp_Controller_MetaData[] = {
		{ "Category", "General" },
		{ "Comment", "// Currently only one controller (not sure if imstk allows multiple)\n" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/ImstkSubsystem.h" },
		{ "ToolTip", "Currently only one controller (not sure if imstk allows multiple)" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UImstkSubsystem_Statics::NewProp_Controller = { "Controller", nullptr, (EPropertyFlags)0x00100000000a000d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UImstkSubsystem, Controller), Z_Construct_UClass_UImstkController_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UImstkSubsystem_Statics::NewProp_Controller_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UImstkSubsystem_Statics::NewProp_Controller_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UImstkSubsystem_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UImstkSubsystem_Statics::NewProp_RigidBodyMaxIterations,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UImstkSubsystem_Statics::NewProp_Gravity,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UImstkSubsystem_Statics::NewProp_AllBehaviours_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UImstkSubsystem_Statics::NewProp_AllBehaviours,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UImstkSubsystem_Statics::NewProp_AllInteractions_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UImstkSubsystem_Statics::NewProp_AllInteractions,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UImstkSubsystem_Statics::NewProp_Controller,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UImstkSubsystem_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UImstkSubsystem>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UImstkSubsystem_Statics::ClassParams = {
		&UImstkSubsystem::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UImstkSubsystem_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UImstkSubsystem_Statics::PropPointers),
		0,
		0x009000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UImstkSubsystem_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UImstkSubsystem_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UImstkSubsystem()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UImstkSubsystem_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UImstkSubsystem, 1527041350);
	template<> IMSTK_API UClass* StaticClass<UImstkSubsystem>()
	{
		return UImstkSubsystem::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UImstkSubsystem(Z_Construct_UClass_UImstkSubsystem, &UImstkSubsystem::StaticClass, TEXT("/Script/Imstk"), TEXT("UImstkSubsystem"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UImstkSubsystem);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
