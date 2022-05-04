// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Imstk/Public/CustomController.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCustomController() {}
// Cross Module References
	IMSTK_API UClass* Z_Construct_UClass_UCustomController_NoRegister();
	IMSTK_API UClass* Z_Construct_UClass_UCustomController();
	IMSTK_API UClass* Z_Construct_UClass_UImstkController();
	UPackage* Z_Construct_UPackage__Script_Imstk();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FQuat();
	IMSTK_API UClass* Z_Construct_UClass_UDynamicalModel_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(UCustomController::execBeginStitch)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->BeginStitch();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UCustomController::execEndGrasp)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->EndGrasp();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UCustomController::execBeginRayPointGrasp)
	{
		P_GET_STRUCT(FVector,Z_Param_RayStart);
		P_GET_STRUCT(FVector,Z_Param_RayDir);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->BeginRayPointGrasp(Z_Param_RayStart,Z_Param_RayDir);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UCustomController::execBeginVertexGrasp)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->BeginVertexGrasp();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UCustomController::execMoveControllerToRaycastOnPlane)
	{
		P_GET_STRUCT(FVector,Z_Param_RayStart);
		P_GET_STRUCT(FVector,Z_Param_RayDir);
		P_GET_STRUCT(FQuat,Z_Param_Orientation);
		P_GET_OBJECT(UDynamicalModel,Z_Param_PlaneActor);
		P_GET_UBOOL(Z_Param_bUpdateUnrealPosRot);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->MoveControllerToRaycastOnPlane(Z_Param_RayStart,Z_Param_RayDir,Z_Param_Orientation,Z_Param_PlaneActor,Z_Param_bUpdateUnrealPosRot);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UCustomController::execMoveControllerToLocation)
	{
		P_GET_STRUCT(FVector,Z_Param_Location);
		P_GET_STRUCT(FQuat,Z_Param_Orientation);
		P_GET_UBOOL(Z_Param_bUpdateUnrealPosRot);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->MoveControllerToLocation(Z_Param_Location,Z_Param_Orientation,Z_Param_bUpdateUnrealPosRot);
		P_NATIVE_END;
	}
	void UCustomController::StaticRegisterNativesUCustomController()
	{
		UClass* Class = UCustomController::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "BeginRayPointGrasp", &UCustomController::execBeginRayPointGrasp },
			{ "BeginStitch", &UCustomController::execBeginStitch },
			{ "BeginVertexGrasp", &UCustomController::execBeginVertexGrasp },
			{ "EndGrasp", &UCustomController::execEndGrasp },
			{ "MoveControllerToLocation", &UCustomController::execMoveControllerToLocation },
			{ "MoveControllerToRaycastOnPlane", &UCustomController::execMoveControllerToRaycastOnPlane },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UCustomController_BeginRayPointGrasp_Statics
	{
		struct CustomController_eventBeginRayPointGrasp_Parms
		{
			FVector RayStart;
			FVector RayDir;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_RayStart;
		static const UECodeGen_Private::FStructPropertyParams NewProp_RayDir;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCustomController_BeginRayPointGrasp_Statics::NewProp_RayStart = { "RayStart", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CustomController_eventBeginRayPointGrasp_Parms, RayStart), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCustomController_BeginRayPointGrasp_Statics::NewProp_RayDir = { "RayDir", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CustomController_eventBeginRayPointGrasp_Parms, RayDir), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCustomController_BeginRayPointGrasp_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCustomController_BeginRayPointGrasp_Statics::NewProp_RayStart,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCustomController_BeginRayPointGrasp_Statics::NewProp_RayDir,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCustomController_BeginRayPointGrasp_Statics::Function_MetaDataParams[] = {
		{ "Category", "Imstk" },
		{ "ModuleRelativePath", "Public/CustomController.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCustomController_BeginRayPointGrasp_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCustomController, nullptr, "BeginRayPointGrasp", nullptr, nullptr, sizeof(Z_Construct_UFunction_UCustomController_BeginRayPointGrasp_Statics::CustomController_eventBeginRayPointGrasp_Parms), Z_Construct_UFunction_UCustomController_BeginRayPointGrasp_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCustomController_BeginRayPointGrasp_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04880401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UCustomController_BeginRayPointGrasp_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UCustomController_BeginRayPointGrasp_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UCustomController_BeginRayPointGrasp()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCustomController_BeginRayPointGrasp_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UCustomController_BeginStitch_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCustomController_BeginStitch_Statics::Function_MetaDataParams[] = {
		{ "Category", "Imstk" },
		{ "ModuleRelativePath", "Public/CustomController.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCustomController_BeginStitch_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCustomController, nullptr, "BeginStitch", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04080401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UCustomController_BeginStitch_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UCustomController_BeginStitch_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UCustomController_BeginStitch()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCustomController_BeginStitch_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UCustomController_BeginVertexGrasp_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCustomController_BeginVertexGrasp_Statics::Function_MetaDataParams[] = {
		{ "Category", "Imstk" },
		{ "ModuleRelativePath", "Public/CustomController.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCustomController_BeginVertexGrasp_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCustomController, nullptr, "BeginVertexGrasp", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04080401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UCustomController_BeginVertexGrasp_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UCustomController_BeginVertexGrasp_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UCustomController_BeginVertexGrasp()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCustomController_BeginVertexGrasp_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UCustomController_EndGrasp_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCustomController_EndGrasp_Statics::Function_MetaDataParams[] = {
		{ "Category", "Imstk" },
		{ "ModuleRelativePath", "Public/CustomController.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCustomController_EndGrasp_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCustomController, nullptr, "EndGrasp", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04080401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UCustomController_EndGrasp_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UCustomController_EndGrasp_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UCustomController_EndGrasp()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCustomController_EndGrasp_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UCustomController_MoveControllerToLocation_Statics
	{
		struct CustomController_eventMoveControllerToLocation_Parms
		{
			FVector Location;
			FQuat Orientation;
			bool bUpdateUnrealPosRot;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_Location;
		static const UECodeGen_Private::FStructPropertyParams NewProp_Orientation;
		static void NewProp_bUpdateUnrealPosRot_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bUpdateUnrealPosRot;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCustomController_MoveControllerToLocation_Statics::NewProp_Location = { "Location", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CustomController_eventMoveControllerToLocation_Parms, Location), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCustomController_MoveControllerToLocation_Statics::NewProp_Orientation = { "Orientation", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CustomController_eventMoveControllerToLocation_Parms, Orientation), Z_Construct_UScriptStruct_FQuat, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UCustomController_MoveControllerToLocation_Statics::NewProp_bUpdateUnrealPosRot_SetBit(void* Obj)
	{
		((CustomController_eventMoveControllerToLocation_Parms*)Obj)->bUpdateUnrealPosRot = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UCustomController_MoveControllerToLocation_Statics::NewProp_bUpdateUnrealPosRot = { "bUpdateUnrealPosRot", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(CustomController_eventMoveControllerToLocation_Parms), &Z_Construct_UFunction_UCustomController_MoveControllerToLocation_Statics::NewProp_bUpdateUnrealPosRot_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCustomController_MoveControllerToLocation_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCustomController_MoveControllerToLocation_Statics::NewProp_Location,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCustomController_MoveControllerToLocation_Statics::NewProp_Orientation,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCustomController_MoveControllerToLocation_Statics::NewProp_bUpdateUnrealPosRot,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCustomController_MoveControllerToLocation_Statics::Function_MetaDataParams[] = {
		{ "Category", "Imstk" },
		{ "CPP_Default_bUpdateUnrealPosRot", "true" },
		{ "ModuleRelativePath", "Public/CustomController.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCustomController_MoveControllerToLocation_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCustomController, nullptr, "MoveControllerToLocation", nullptr, nullptr, sizeof(Z_Construct_UFunction_UCustomController_MoveControllerToLocation_Statics::CustomController_eventMoveControllerToLocation_Parms), Z_Construct_UFunction_UCustomController_MoveControllerToLocation_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCustomController_MoveControllerToLocation_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UCustomController_MoveControllerToLocation_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UCustomController_MoveControllerToLocation_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UCustomController_MoveControllerToLocation()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCustomController_MoveControllerToLocation_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UCustomController_MoveControllerToRaycastOnPlane_Statics
	{
		struct CustomController_eventMoveControllerToRaycastOnPlane_Parms
		{
			FVector RayStart;
			FVector RayDir;
			FQuat Orientation;
			UDynamicalModel* PlaneActor;
			bool bUpdateUnrealPosRot;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_RayStart;
		static const UECodeGen_Private::FStructPropertyParams NewProp_RayDir;
		static const UECodeGen_Private::FStructPropertyParams NewProp_Orientation;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_PlaneActor_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_PlaneActor;
		static void NewProp_bUpdateUnrealPosRot_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bUpdateUnrealPosRot;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCustomController_MoveControllerToRaycastOnPlane_Statics::NewProp_RayStart = { "RayStart", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CustomController_eventMoveControllerToRaycastOnPlane_Parms, RayStart), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCustomController_MoveControllerToRaycastOnPlane_Statics::NewProp_RayDir = { "RayDir", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CustomController_eventMoveControllerToRaycastOnPlane_Parms, RayDir), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCustomController_MoveControllerToRaycastOnPlane_Statics::NewProp_Orientation = { "Orientation", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CustomController_eventMoveControllerToRaycastOnPlane_Parms, Orientation), Z_Construct_UScriptStruct_FQuat, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCustomController_MoveControllerToRaycastOnPlane_Statics::NewProp_PlaneActor_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UCustomController_MoveControllerToRaycastOnPlane_Statics::NewProp_PlaneActor = { "PlaneActor", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CustomController_eventMoveControllerToRaycastOnPlane_Parms, PlaneActor), Z_Construct_UClass_UDynamicalModel_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UCustomController_MoveControllerToRaycastOnPlane_Statics::NewProp_PlaneActor_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UCustomController_MoveControllerToRaycastOnPlane_Statics::NewProp_PlaneActor_MetaData)) };
	void Z_Construct_UFunction_UCustomController_MoveControllerToRaycastOnPlane_Statics::NewProp_bUpdateUnrealPosRot_SetBit(void* Obj)
	{
		((CustomController_eventMoveControllerToRaycastOnPlane_Parms*)Obj)->bUpdateUnrealPosRot = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UCustomController_MoveControllerToRaycastOnPlane_Statics::NewProp_bUpdateUnrealPosRot = { "bUpdateUnrealPosRot", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(CustomController_eventMoveControllerToRaycastOnPlane_Parms), &Z_Construct_UFunction_UCustomController_MoveControllerToRaycastOnPlane_Statics::NewProp_bUpdateUnrealPosRot_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCustomController_MoveControllerToRaycastOnPlane_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCustomController_MoveControllerToRaycastOnPlane_Statics::NewProp_RayStart,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCustomController_MoveControllerToRaycastOnPlane_Statics::NewProp_RayDir,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCustomController_MoveControllerToRaycastOnPlane_Statics::NewProp_Orientation,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCustomController_MoveControllerToRaycastOnPlane_Statics::NewProp_PlaneActor,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCustomController_MoveControllerToRaycastOnPlane_Statics::NewProp_bUpdateUnrealPosRot,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCustomController_MoveControllerToRaycastOnPlane_Statics::Function_MetaDataParams[] = {
		{ "Category", "Imstk" },
		{ "CPP_Default_bUpdateUnrealPosRot", "true" },
		{ "ModuleRelativePath", "Public/CustomController.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCustomController_MoveControllerToRaycastOnPlane_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCustomController, nullptr, "MoveControllerToRaycastOnPlane", nullptr, nullptr, sizeof(Z_Construct_UFunction_UCustomController_MoveControllerToRaycastOnPlane_Statics::CustomController_eventMoveControllerToRaycastOnPlane_Parms), Z_Construct_UFunction_UCustomController_MoveControllerToRaycastOnPlane_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCustomController_MoveControllerToRaycastOnPlane_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UCustomController_MoveControllerToRaycastOnPlane_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UCustomController_MoveControllerToRaycastOnPlane_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UCustomController_MoveControllerToRaycastOnPlane()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCustomController_MoveControllerToRaycastOnPlane_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UCustomController);
	UClass* Z_Construct_UClass_UCustomController_NoRegister()
	{
		return UCustomController::StaticClass();
	}
	struct Z_Construct_UClass_UCustomController_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Mass_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Mass;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_VelocityDamping_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_VelocityDamping;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AngularVelocityDamping_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_AngularVelocityDamping;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MaxNumIterations_MetaData[];
#endif
		static const UECodeGen_Private::FUnsizedIntPropertyParams NewProp_MaxNumIterations;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MaxNumConstraints_MetaData[];
#endif
		static const UECodeGen_Private::FUnsizedIntPropertyParams NewProp_MaxNumConstraints;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_InertiaTensorMultiplier_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_InertiaTensorMultiplier;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SpringForce_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_SpringForce;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SpringDamping_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_SpringDamping;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bPrintImstkPos_MetaData[];
#endif
		static void NewProp_bPrintImstkPos_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bPrintImstkPos;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UCustomController_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UImstkController,
		(UObject* (*)())Z_Construct_UPackage__Script_Imstk,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UCustomController_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UCustomController_BeginRayPointGrasp, "BeginRayPointGrasp" }, // 3418216217
		{ &Z_Construct_UFunction_UCustomController_BeginStitch, "BeginStitch" }, // 60443789
		{ &Z_Construct_UFunction_UCustomController_BeginVertexGrasp, "BeginVertexGrasp" }, // 1437371557
		{ &Z_Construct_UFunction_UCustomController_EndGrasp, "EndGrasp" }, // 1434236603
		{ &Z_Construct_UFunction_UCustomController_MoveControllerToLocation, "MoveControllerToLocation" }, // 3846045038
		{ &Z_Construct_UFunction_UCustomController_MoveControllerToRaycastOnPlane, "MoveControllerToRaycastOnPlane" }, // 1202390267
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCustomController_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Imstk" },
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "CustomController.h" },
		{ "ModuleRelativePath", "Public/CustomController.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCustomController_Statics::NewProp_Mass_MetaData[] = {
		{ "Category", "ToolSettings" },
		{ "ModuleRelativePath", "Public/CustomController.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCustomController_Statics::NewProp_Mass = { "Mass", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UCustomController, Mass), METADATA_PARAMS(Z_Construct_UClass_UCustomController_Statics::NewProp_Mass_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCustomController_Statics::NewProp_Mass_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCustomController_Statics::NewProp_VelocityDamping_MetaData[] = {
		{ "Category", "ToolSettings" },
		{ "ModuleRelativePath", "Public/CustomController.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCustomController_Statics::NewProp_VelocityDamping = { "VelocityDamping", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UCustomController, VelocityDamping), METADATA_PARAMS(Z_Construct_UClass_UCustomController_Statics::NewProp_VelocityDamping_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCustomController_Statics::NewProp_VelocityDamping_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCustomController_Statics::NewProp_AngularVelocityDamping_MetaData[] = {
		{ "Category", "ToolSettings" },
		{ "ModuleRelativePath", "Public/CustomController.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCustomController_Statics::NewProp_AngularVelocityDamping = { "AngularVelocityDamping", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UCustomController, AngularVelocityDamping), METADATA_PARAMS(Z_Construct_UClass_UCustomController_Statics::NewProp_AngularVelocityDamping_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCustomController_Statics::NewProp_AngularVelocityDamping_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCustomController_Statics::NewProp_MaxNumIterations_MetaData[] = {
		{ "Category", "ToolSettings" },
		{ "ModuleRelativePath", "Public/CustomController.h" },
	};
#endif
	const UECodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_UCustomController_Statics::NewProp_MaxNumIterations = { "MaxNumIterations", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UCustomController, MaxNumIterations), METADATA_PARAMS(Z_Construct_UClass_UCustomController_Statics::NewProp_MaxNumIterations_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCustomController_Statics::NewProp_MaxNumIterations_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCustomController_Statics::NewProp_MaxNumConstraints_MetaData[] = {
		{ "Category", "ToolSettings" },
		{ "ModuleRelativePath", "Public/CustomController.h" },
	};
#endif
	const UECodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_UCustomController_Statics::NewProp_MaxNumConstraints = { "MaxNumConstraints", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UCustomController, MaxNumConstraints), METADATA_PARAMS(Z_Construct_UClass_UCustomController_Statics::NewProp_MaxNumConstraints_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCustomController_Statics::NewProp_MaxNumConstraints_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCustomController_Statics::NewProp_InertiaTensorMultiplier_MetaData[] = {
		{ "Category", "ToolSettings" },
		{ "ModuleRelativePath", "Public/CustomController.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCustomController_Statics::NewProp_InertiaTensorMultiplier = { "InertiaTensorMultiplier", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UCustomController, InertiaTensorMultiplier), METADATA_PARAMS(Z_Construct_UClass_UCustomController_Statics::NewProp_InertiaTensorMultiplier_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCustomController_Statics::NewProp_InertiaTensorMultiplier_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCustomController_Statics::NewProp_SpringForce_MetaData[] = {
		{ "Category", "ToolSettings" },
		{ "ModuleRelativePath", "Public/CustomController.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCustomController_Statics::NewProp_SpringForce = { "SpringForce", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UCustomController, SpringForce), METADATA_PARAMS(Z_Construct_UClass_UCustomController_Statics::NewProp_SpringForce_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCustomController_Statics::NewProp_SpringForce_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCustomController_Statics::NewProp_SpringDamping_MetaData[] = {
		{ "Category", "ToolSettings" },
		{ "ModuleRelativePath", "Public/CustomController.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCustomController_Statics::NewProp_SpringDamping = { "SpringDamping", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UCustomController, SpringDamping), METADATA_PARAMS(Z_Construct_UClass_UCustomController_Statics::NewProp_SpringDamping_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCustomController_Statics::NewProp_SpringDamping_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCustomController_Statics::NewProp_bPrintImstkPos_MetaData[] = {
		{ "Category", "Debugging" },
		{ "ModuleRelativePath", "Public/CustomController.h" },
	};
#endif
	void Z_Construct_UClass_UCustomController_Statics::NewProp_bPrintImstkPos_SetBit(void* Obj)
	{
		((UCustomController*)Obj)->bPrintImstkPos = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UCustomController_Statics::NewProp_bPrintImstkPos = { "bPrintImstkPos", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UCustomController), &Z_Construct_UClass_UCustomController_Statics::NewProp_bPrintImstkPos_SetBit, METADATA_PARAMS(Z_Construct_UClass_UCustomController_Statics::NewProp_bPrintImstkPos_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCustomController_Statics::NewProp_bPrintImstkPos_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UCustomController_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCustomController_Statics::NewProp_Mass,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCustomController_Statics::NewProp_VelocityDamping,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCustomController_Statics::NewProp_AngularVelocityDamping,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCustomController_Statics::NewProp_MaxNumIterations,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCustomController_Statics::NewProp_MaxNumConstraints,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCustomController_Statics::NewProp_InertiaTensorMultiplier,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCustomController_Statics::NewProp_SpringForce,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCustomController_Statics::NewProp_SpringDamping,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCustomController_Statics::NewProp_bPrintImstkPos,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UCustomController_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCustomController>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UCustomController_Statics::ClassParams = {
		&UCustomController::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UCustomController_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UCustomController_Statics::PropPointers),
		0,
		0x00B000A4u,
		METADATA_PARAMS(Z_Construct_UClass_UCustomController_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UCustomController_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UCustomController()
	{
		if (!Z_Registration_Info_UClass_UCustomController.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UCustomController.OuterSingleton, Z_Construct_UClass_UCustomController_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UCustomController.OuterSingleton;
	}
	template<> IMSTK_API UClass* StaticClass<UCustomController>()
	{
		return UCustomController::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UCustomController);
	struct Z_CompiledInDeferFile_FID_HostProject_Plugins_Imstk_Source_Imstk_Public_CustomController_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_Imstk_Source_Imstk_Public_CustomController_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UCustomController, UCustomController::StaticClass, TEXT("UCustomController"), &Z_Registration_Info_UClass_UCustomController, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UCustomController), 1951945616U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_Imstk_Source_Imstk_Public_CustomController_h_3352355330(TEXT("/Script/Imstk"),
		Z_CompiledInDeferFile_FID_HostProject_Plugins_Imstk_Source_Imstk_Public_CustomController_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HostProject_Plugins_Imstk_Source_Imstk_Public_CustomController_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
