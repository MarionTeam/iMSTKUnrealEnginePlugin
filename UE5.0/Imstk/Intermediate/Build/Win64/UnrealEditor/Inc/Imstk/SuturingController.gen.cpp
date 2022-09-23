// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Imstk/Public/SuturingController.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSuturingController() {}
// Cross Module References
	IMSTK_API UClass* Z_Construct_UClass_USuturingController_NoRegister();
	IMSTK_API UClass* Z_Construct_UClass_USuturingController();
	IMSTK_API UClass* Z_Construct_UClass_UImstkController();
	UPackage* Z_Construct_UPackage__Script_Imstk();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FQuat();
	IMSTK_API UClass* Z_Construct_UClass_UPBDThread_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UMaterial_NoRegister();
	PROCEDURALMESHCOMPONENT_API UClass* Z_Construct_UClass_UProceduralMeshComponent_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(USuturingController::execMoveNeedleToLocation)
	{
		P_GET_STRUCT(FVector,Z_Param_Location);
		P_GET_STRUCT(FQuat,Z_Param_Orientation);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->MoveNeedleToLocation(Z_Param_Location,Z_Param_Orientation);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USuturingController::execStitch)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Stitch();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USuturingController::execSetThread)
	{
		P_GET_OBJECT(UPBDThread,Z_Param_Input);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetThread(Z_Param_Input);
		P_NATIVE_END;
	}
	void USuturingController::StaticRegisterNativesUSuturingController()
	{
		UClass* Class = USuturingController::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "MoveNeedleToLocation", &USuturingController::execMoveNeedleToLocation },
			{ "SetThread", &USuturingController::execSetThread },
			{ "Stitch", &USuturingController::execStitch },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_USuturingController_MoveNeedleToLocation_Statics
	{
		struct SuturingController_eventMoveNeedleToLocation_Parms
		{
			FVector Location;
			FQuat Orientation;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_Location;
		static const UECodeGen_Private::FStructPropertyParams NewProp_Orientation;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USuturingController_MoveNeedleToLocation_Statics::NewProp_Location = { "Location", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuturingController_eventMoveNeedleToLocation_Parms, Location), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USuturingController_MoveNeedleToLocation_Statics::NewProp_Orientation = { "Orientation", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuturingController_eventMoveNeedleToLocation_Parms, Orientation), Z_Construct_UScriptStruct_FQuat, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USuturingController_MoveNeedleToLocation_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USuturingController_MoveNeedleToLocation_Statics::NewProp_Location,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USuturingController_MoveNeedleToLocation_Statics::NewProp_Orientation,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USuturingController_MoveNeedleToLocation_Statics::Function_MetaDataParams[] = {
		{ "Category", "Imstk" },
		{ "Comment", "/** Moves the needle and attached thread to the given position and orientation\n\x09* @param Location Position to move the needle to\n\x09* @param Orientation Orientation to move the needle to\n\x09* @return None\n\x09*/" },
		{ "ModuleRelativePath", "Public/SuturingController.h" },
		{ "ToolTip", "Moves the needle and attached thread to the given position and orientation\n@param Location Position to move the needle to\n@param Orientation Orientation to move the needle to\n@return None" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USuturingController_MoveNeedleToLocation_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USuturingController, nullptr, "MoveNeedleToLocation", nullptr, nullptr, sizeof(Z_Construct_UFunction_USuturingController_MoveNeedleToLocation_Statics::SuturingController_eventMoveNeedleToLocation_Parms), Z_Construct_UFunction_USuturingController_MoveNeedleToLocation_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USuturingController_MoveNeedleToLocation_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USuturingController_MoveNeedleToLocation_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USuturingController_MoveNeedleToLocation_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USuturingController_MoveNeedleToLocation()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USuturingController_MoveNeedleToLocation_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USuturingController_SetThread_Statics
	{
		struct SuturingController_eventSetThread_Parms
		{
			UPBDThread* Input;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Input_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Input;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USuturingController_SetThread_Statics::NewProp_Input_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USuturingController_SetThread_Statics::NewProp_Input = { "Input", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuturingController_eventSetThread_Parms, Input), Z_Construct_UClass_UPBDThread_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_USuturingController_SetThread_Statics::NewProp_Input_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USuturingController_SetThread_Statics::NewProp_Input_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USuturingController_SetThread_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USuturingController_SetThread_Statics::NewProp_Input,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USuturingController_SetThread_Statics::Function_MetaDataParams[] = {
		{ "Category", "Imstk" },
		{ "Comment", "/** Setter for the thread attached to the needle. Required to be set in the construction of the blueprint.\n\x09* @param InputMeshComp Static mesh component to be set\n\x09* @return None\n\x09*/" },
		{ "ModuleRelativePath", "Public/SuturingController.h" },
		{ "ToolTip", "Setter for the thread attached to the needle. Required to be set in the construction of the blueprint.\n@param InputMeshComp Static mesh component to be set\n@return None" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USuturingController_SetThread_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USuturingController, nullptr, "SetThread", nullptr, nullptr, sizeof(Z_Construct_UFunction_USuturingController_SetThread_Statics::SuturingController_eventSetThread_Parms), Z_Construct_UFunction_USuturingController_SetThread_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USuturingController_SetThread_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USuturingController_SetThread_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USuturingController_SetThread_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USuturingController_SetThread()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USuturingController_SetThread_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USuturingController_Stitch_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USuturingController_Stitch_Statics::Function_MetaDataParams[] = {
		{ "Category", "Imstk" },
		{ "Comment", "/** Stitch along the thread attached to the needle\n\x09* @return None\n\x09*/" },
		{ "ModuleRelativePath", "Public/SuturingController.h" },
		{ "ToolTip", "Stitch along the thread attached to the needle\n@return None" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USuturingController_Stitch_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USuturingController, nullptr, "Stitch", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USuturingController_Stitch_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USuturingController_Stitch_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USuturingController_Stitch()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USuturingController_Stitch_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(USuturingController);
	UClass* Z_Construct_UClass_USuturingController_NoRegister()
	{
		return USuturingController::StaticClass();
	}
	struct Z_Construct_UClass_USuturingController_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_InertiaTensorMultiplier_MetaData[];
#endif
		static const UECodeGen_Private::FDoublePropertyParams NewProp_InertiaTensorMultiplier;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Mass_MetaData[];
#endif
		static const UECodeGen_Private::FDoublePropertyParams NewProp_Mass;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ForceThreshold_MetaData[];
#endif
		static const UECodeGen_Private::FDoublePropertyParams NewProp_ForceThreshold;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bForceTool_MetaData[];
#endif
		static void NewProp_bForceTool_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bForceTool;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_LinearKs_MetaData[];
#endif
		static const UECodeGen_Private::FDoublePropertyParams NewProp_LinearKs;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AngularKs_MetaData[];
#endif
		static const UECodeGen_Private::FDoublePropertyParams NewProp_AngularKs;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_LinearKd_MetaData[];
#endif
		static const UECodeGen_Private::FDoublePropertyParams NewProp_LinearKd;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AngularKd_MetaData[];
#endif
		static const UECodeGen_Private::FDoublePropertyParams NewProp_AngularKd;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ForceScaling_MetaData[];
#endif
		static const UECodeGen_Private::FDoublePropertyParams NewProp_ForceScaling;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_GhostMaterial_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_GhostMaterial;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Thread_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Thread;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ProcMeshComp_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ProcMeshComp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_GhostMeshComp_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_GhostMeshComp;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_USuturingController_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UImstkController,
		(UObject* (*)())Z_Construct_UPackage__Script_Imstk,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_USuturingController_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_USuturingController_MoveNeedleToLocation, "MoveNeedleToLocation" }, // 3143606102
		{ &Z_Construct_UFunction_USuturingController_SetThread, "SetThread" }, // 1533906447
		{ &Z_Construct_UFunction_USuturingController_Stitch, "Stitch" }, // 267144416
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USuturingController_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Imstk" },
		{ "Comment", "/** \\file SuturingController.h\n  *  \\brief Creates a needle and thread controller. Requires a PBD thread to be attached to the actor\n  *  \\details Creates the Imstk scene manager, scene and rigidbody model as well as initializing all imstk behaviours assigned in Unreal.\n  * TODO: Maybe make it not inherit from ImstkController, because it requires more than one tool obj for collisions, etc\n  * Note: Needle only works with iMSTK scene scale set to ~100 since it is currently always the same size within the iMSTK scene and is scaled up/down for Unreal\n  */" },
		{ "HideCategories", "Trigger PhysicsVolume" },
		{ "IncludePath", "SuturingController.h" },
		{ "ModuleRelativePath", "Public/SuturingController.h" },
		{ "ToolTip", "\\file SuturingController.h\n\\brief Creates a needle and thread controller. Requires a PBD thread to be attached to the actor\n\\details Creates the Imstk scene manager, scene and rigidbody model as well as initializing all imstk behaviours assigned in Unreal.\nTODO: Maybe make it not inherit from ImstkController, because it requires more than one tool obj for collisions, etc\nNote: Needle only works with iMSTK scene scale set to ~100 since it is currently always the same size within the iMSTK scene and is scaled up/down for Unreal" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USuturingController_Statics::NewProp_InertiaTensorMultiplier_MetaData[] = {
		{ "Category", "ToolSettings" },
		{ "ModuleRelativePath", "Public/SuturingController.h" },
	};
#endif
	const UECodeGen_Private::FDoublePropertyParams Z_Construct_UClass_USuturingController_Statics::NewProp_InertiaTensorMultiplier = { "InertiaTensorMultiplier", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Double, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USuturingController, InertiaTensorMultiplier), METADATA_PARAMS(Z_Construct_UClass_USuturingController_Statics::NewProp_InertiaTensorMultiplier_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USuturingController_Statics::NewProp_InertiaTensorMultiplier_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USuturingController_Statics::NewProp_Mass_MetaData[] = {
		{ "Category", "ToolSettings" },
		{ "ModuleRelativePath", "Public/SuturingController.h" },
	};
#endif
	const UECodeGen_Private::FDoublePropertyParams Z_Construct_UClass_USuturingController_Statics::NewProp_Mass = { "Mass", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Double, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USuturingController, Mass), METADATA_PARAMS(Z_Construct_UClass_USuturingController_Statics::NewProp_Mass_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USuturingController_Statics::NewProp_Mass_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USuturingController_Statics::NewProp_ForceThreshold_MetaData[] = {
		{ "Category", "ToolSettings" },
		{ "ModuleRelativePath", "Public/SuturingController.h" },
	};
#endif
	const UECodeGen_Private::FDoublePropertyParams Z_Construct_UClass_USuturingController_Statics::NewProp_ForceThreshold = { "ForceThreshold", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Double, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USuturingController, ForceThreshold), METADATA_PARAMS(Z_Construct_UClass_USuturingController_Statics::NewProp_ForceThreshold_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USuturingController_Statics::NewProp_ForceThreshold_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USuturingController_Statics::NewProp_bForceTool_MetaData[] = {
		{ "Category", "ToolSettings" },
		{ "ModuleRelativePath", "Public/SuturingController.h" },
	};
#endif
	void Z_Construct_UClass_USuturingController_Statics::NewProp_bForceTool_SetBit(void* Obj)
	{
		((USuturingController*)Obj)->bForceTool = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_USuturingController_Statics::NewProp_bForceTool = { "bForceTool", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(USuturingController), &Z_Construct_UClass_USuturingController_Statics::NewProp_bForceTool_SetBit, METADATA_PARAMS(Z_Construct_UClass_USuturingController_Statics::NewProp_bForceTool_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USuturingController_Statics::NewProp_bForceTool_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USuturingController_Statics::NewProp_LinearKs_MetaData[] = {
		{ "Category", "ToolSettings" },
		{ "EditCondition", "bForceTool" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/SuturingController.h" },
	};
#endif
	const UECodeGen_Private::FDoublePropertyParams Z_Construct_UClass_USuturingController_Statics::NewProp_LinearKs = { "LinearKs", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Double, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USuturingController, LinearKs), METADATA_PARAMS(Z_Construct_UClass_USuturingController_Statics::NewProp_LinearKs_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USuturingController_Statics::NewProp_LinearKs_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USuturingController_Statics::NewProp_AngularKs_MetaData[] = {
		{ "Category", "ToolSettings" },
		{ "EditCondition", "bForceTool" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/SuturingController.h" },
	};
#endif
	const UECodeGen_Private::FDoublePropertyParams Z_Construct_UClass_USuturingController_Statics::NewProp_AngularKs = { "AngularKs", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Double, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USuturingController, AngularKs), METADATA_PARAMS(Z_Construct_UClass_USuturingController_Statics::NewProp_AngularKs_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USuturingController_Statics::NewProp_AngularKs_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USuturingController_Statics::NewProp_LinearKd_MetaData[] = {
		{ "Category", "ToolSettings" },
		{ "EditCondition", "bForceTool" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/SuturingController.h" },
	};
#endif
	const UECodeGen_Private::FDoublePropertyParams Z_Construct_UClass_USuturingController_Statics::NewProp_LinearKd = { "LinearKd", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Double, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USuturingController, LinearKd), METADATA_PARAMS(Z_Construct_UClass_USuturingController_Statics::NewProp_LinearKd_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USuturingController_Statics::NewProp_LinearKd_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USuturingController_Statics::NewProp_AngularKd_MetaData[] = {
		{ "Category", "ToolSettings" },
		{ "EditCondition", "bForceTool" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/SuturingController.h" },
	};
#endif
	const UECodeGen_Private::FDoublePropertyParams Z_Construct_UClass_USuturingController_Statics::NewProp_AngularKd = { "AngularKd", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Double, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USuturingController, AngularKd), METADATA_PARAMS(Z_Construct_UClass_USuturingController_Statics::NewProp_AngularKd_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USuturingController_Statics::NewProp_AngularKd_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USuturingController_Statics::NewProp_ForceScaling_MetaData[] = {
		{ "Category", "ToolSettings" },
		{ "EditCondition", "bForceTool" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/SuturingController.h" },
	};
#endif
	const UECodeGen_Private::FDoublePropertyParams Z_Construct_UClass_USuturingController_Statics::NewProp_ForceScaling = { "ForceScaling", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Double, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USuturingController, ForceScaling), METADATA_PARAMS(Z_Construct_UClass_USuturingController_Statics::NewProp_ForceScaling_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USuturingController_Statics::NewProp_ForceScaling_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USuturingController_Statics::NewProp_GhostMaterial_MetaData[] = {
		{ "Category", "ToolSettings" },
		{ "Comment", "// Material of the ghost model for the needle\n" },
		{ "EditCondition", "bForceTool" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/SuturingController.h" },
		{ "ToolTip", "Material of the ghost model for the needle" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_USuturingController_Statics::NewProp_GhostMaterial = { "GhostMaterial", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USuturingController, GhostMaterial), Z_Construct_UClass_UMaterial_NoRegister, METADATA_PARAMS(Z_Construct_UClass_USuturingController_Statics::NewProp_GhostMaterial_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USuturingController_Statics::NewProp_GhostMaterial_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USuturingController_Statics::NewProp_Thread_MetaData[] = {
		{ "Comment", "// Required to be set in the construction blueprint\n" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/SuturingController.h" },
		{ "ToolTip", "Required to be set in the construction blueprint" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_USuturingController_Statics::NewProp_Thread = { "Thread", nullptr, (EPropertyFlags)0x0010000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USuturingController, Thread), Z_Construct_UClass_UPBDThread_NoRegister, METADATA_PARAMS(Z_Construct_UClass_USuturingController_Statics::NewProp_Thread_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USuturingController_Statics::NewProp_Thread_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USuturingController_Statics::NewProp_ProcMeshComp_MetaData[] = {
		{ "Comment", "// Procedural mesh component created and attached to the object to visualize the needle\n" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/SuturingController.h" },
		{ "ToolTip", "Procedural mesh component created and attached to the object to visualize the needle" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_USuturingController_Statics::NewProp_ProcMeshComp = { "ProcMeshComp", nullptr, (EPropertyFlags)0x0010000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USuturingController, ProcMeshComp), Z_Construct_UClass_UProceduralMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_USuturingController_Statics::NewProp_ProcMeshComp_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USuturingController_Statics::NewProp_ProcMeshComp_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USuturingController_Statics::NewProp_GhostMeshComp_MetaData[] = {
		{ "Comment", "// Procedural mesh component created and attached if the controller is set to use force. Used to visualize the ghost of the tool\n" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/SuturingController.h" },
		{ "ToolTip", "Procedural mesh component created and attached if the controller is set to use force. Used to visualize the ghost of the tool" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_USuturingController_Statics::NewProp_GhostMeshComp = { "GhostMeshComp", nullptr, (EPropertyFlags)0x0010000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USuturingController, GhostMeshComp), Z_Construct_UClass_UProceduralMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_USuturingController_Statics::NewProp_GhostMeshComp_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USuturingController_Statics::NewProp_GhostMeshComp_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_USuturingController_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USuturingController_Statics::NewProp_InertiaTensorMultiplier,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USuturingController_Statics::NewProp_Mass,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USuturingController_Statics::NewProp_ForceThreshold,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USuturingController_Statics::NewProp_bForceTool,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USuturingController_Statics::NewProp_LinearKs,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USuturingController_Statics::NewProp_AngularKs,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USuturingController_Statics::NewProp_LinearKd,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USuturingController_Statics::NewProp_AngularKd,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USuturingController_Statics::NewProp_ForceScaling,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USuturingController_Statics::NewProp_GhostMaterial,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USuturingController_Statics::NewProp_Thread,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USuturingController_Statics::NewProp_ProcMeshComp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USuturingController_Statics::NewProp_GhostMeshComp,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_USuturingController_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USuturingController>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_USuturingController_Statics::ClassParams = {
		&USuturingController::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_USuturingController_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_USuturingController_Statics::PropPointers),
		0,
		0x00B000A4u,
		METADATA_PARAMS(Z_Construct_UClass_USuturingController_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_USuturingController_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_USuturingController()
	{
		if (!Z_Registration_Info_UClass_USuturingController.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_USuturingController.OuterSingleton, Z_Construct_UClass_USuturingController_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_USuturingController.OuterSingleton;
	}
	template<> IMSTK_API UClass* StaticClass<USuturingController>()
	{
		return USuturingController::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(USuturingController);
	struct Z_CompiledInDeferFile_FID_HostProject_Plugins_Imstk_Source_Imstk_Public_SuturingController_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_Imstk_Source_Imstk_Public_SuturingController_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_USuturingController, USuturingController::StaticClass, TEXT("USuturingController"), &Z_Registration_Info_UClass_USuturingController, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(USuturingController), 124789449U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_Imstk_Source_Imstk_Public_SuturingController_h_1530094309(TEXT("/Script/Imstk"),
		Z_CompiledInDeferFile_FID_HostProject_Plugins_Imstk_Source_Imstk_Public_SuturingController_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HostProject_Plugins_Imstk_Source_Imstk_Public_SuturingController_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
