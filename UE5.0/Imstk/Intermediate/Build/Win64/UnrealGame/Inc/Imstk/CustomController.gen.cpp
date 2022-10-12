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
	IMSTK_API UEnum* Z_Construct_UEnum_Imstk_EControllerPreset();
	UPackage* Z_Construct_UPackage__Script_Imstk();
	IMSTK_API UClass* Z_Construct_UClass_UCustomController_NoRegister();
	IMSTK_API UClass* Z_Construct_UClass_UCustomController();
	IMSTK_API UClass* Z_Construct_UClass_UImstkController();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FQuat();
	IMSTK_API UClass* Z_Construct_UClass_UDynamicalModel_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USceneComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UMaterial_NoRegister();
// End Cross Module References
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_EControllerPreset;
	static UEnum* EControllerPreset_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_EControllerPreset.OuterSingleton)
		{
			Z_Registration_Info_UEnum_EControllerPreset.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_Imstk_EControllerPreset, Z_Construct_UPackage__Script_Imstk(), TEXT("EControllerPreset"));
		}
		return Z_Registration_Info_UEnum_EControllerPreset.OuterSingleton;
	}
	template<> IMSTK_API UEnum* StaticEnum<EControllerPreset>()
	{
		return EControllerPreset_StaticEnum();
	}
	struct Z_Construct_UEnum_Imstk_EControllerPreset_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_Imstk_EControllerPreset_Statics::Enumerators[] = {
		{ "CollidingPreset", (int64)CollidingPreset },
		{ "GraspingPreset", (int64)GraspingPreset },
		{ "CuttingPreset", (int64)CuttingPreset },
		{ "StitchingPreset", (int64)StitchingPreset },
		{ "LevelSetPreset", (int64)LevelSetPreset },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_Imstk_EControllerPreset_Statics::Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "CollidingPreset.Name", "CollidingPreset" },
		{ "CuttingPreset.Name", "CuttingPreset" },
		{ "GraspingPreset.Name", "GraspingPreset" },
		{ "LevelSetPreset.Name", "LevelSetPreset" },
		{ "ModuleRelativePath", "Public/CustomController.h" },
		{ "StitchingPreset.Name", "StitchingPreset" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_Imstk_EControllerPreset_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_Imstk,
		nullptr,
		"EControllerPreset",
		"EControllerPreset",
		Z_Construct_UEnum_Imstk_EControllerPreset_Statics::Enumerators,
		UE_ARRAY_COUNT(Z_Construct_UEnum_Imstk_EControllerPreset_Statics::Enumerators),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::Regular,
		METADATA_PARAMS(Z_Construct_UEnum_Imstk_EControllerPreset_Statics::Enum_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UEnum_Imstk_EControllerPreset_Statics::Enum_MetaDataParams))
	};
	UEnum* Z_Construct_UEnum_Imstk_EControllerPreset()
	{
		if (!Z_Registration_Info_UEnum_EControllerPreset.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EControllerPreset.InnerSingleton, Z_Construct_UEnum_Imstk_EControllerPreset_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_EControllerPreset.InnerSingleton;
	}
	DEFINE_FUNCTION(UCustomController::execGetControlleriMSTKPosition)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FVector*)Z_Param__Result=P_THIS->GetControlleriMSTKPosition();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UCustomController::execSetGhostComponents)
	{
		P_GET_OBJECT(USceneComponent,Z_Param_SceneComponent);
		P_GET_TARRAY(UStaticMeshComponent*,Z_Param_StaticMeshComponents);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetGhostComponents(Z_Param_SceneComponent,Z_Param_StaticMeshComponents);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UCustomController::execBeginCut)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->BeginCut();
		P_NATIVE_END;
	}
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
	DEFINE_FUNCTION(UCustomController::execBeginCellGrasp)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->BeginCellGrasp();
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
		*(FVector*)Z_Param__Result=P_THIS->MoveControllerToRaycastOnPlane(Z_Param_RayStart,Z_Param_RayDir,Z_Param_Orientation,Z_Param_PlaneActor,Z_Param_bUpdateUnrealPosRot);
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
			{ "BeginCellGrasp", &UCustomController::execBeginCellGrasp },
			{ "BeginCut", &UCustomController::execBeginCut },
			{ "BeginRayPointGrasp", &UCustomController::execBeginRayPointGrasp },
			{ "BeginStitch", &UCustomController::execBeginStitch },
			{ "BeginVertexGrasp", &UCustomController::execBeginVertexGrasp },
			{ "EndGrasp", &UCustomController::execEndGrasp },
			{ "GetControlleriMSTKPosition", &UCustomController::execGetControlleriMSTKPosition },
			{ "MoveControllerToLocation", &UCustomController::execMoveControllerToLocation },
			{ "MoveControllerToRaycastOnPlane", &UCustomController::execMoveControllerToRaycastOnPlane },
			{ "SetGhostComponents", &UCustomController::execSetGhostComponents },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UCustomController_BeginCellGrasp_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCustomController_BeginCellGrasp_Statics::Function_MetaDataParams[] = {
		{ "Category", "Imstk" },
		{ "Comment", "/** Starts a cell grasp if the tool is set to a grasping tool and a PbdObjectGrasping interaction are set on the controller\n\x09* @return None\n\x09*/" },
		{ "ModuleRelativePath", "Public/CustomController.h" },
		{ "ToolTip", "Starts a cell grasp if the tool is set to a grasping tool and a PbdObjectGrasping interaction are set on the controller\n@return None" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCustomController_BeginCellGrasp_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCustomController, nullptr, "BeginCellGrasp", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04080401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UCustomController_BeginCellGrasp_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UCustomController_BeginCellGrasp_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UCustomController_BeginCellGrasp()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCustomController_BeginCellGrasp_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UCustomController_BeginCut_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCustomController_BeginCut_Statics::Function_MetaDataParams[] = {
		{ "Category", "Imstk" },
		{ "Comment", "/** Applies the cut for each PbdObjectCutting interaction on the controller. Requires geometry to be set to a SurfaceMeshTool.\n\x09* @return None\n\x09*/" },
		{ "ModuleRelativePath", "Public/CustomController.h" },
		{ "ToolTip", "Applies the cut for each PbdObjectCutting interaction on the controller. Requires geometry to be set to a SurfaceMeshTool.\n@return None" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCustomController_BeginCut_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCustomController, nullptr, "BeginCut", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04080401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UCustomController_BeginCut_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UCustomController_BeginCut_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UCustomController_BeginCut()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCustomController_BeginCut_Statics::FuncParams);
		}
		return ReturnFunction;
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
		{ "Comment", "/** Starts a ray point grasp from RayStart in the direction provided if the tool is set to a grasping tool and a PbdObjectGrasping interaction are set on the controller\n\x09* @param RayStart Starting point of the ray\n\x09* @param RayDir Direction of the ray to be cast\n\x09* @return None\n\x09*/" },
		{ "ModuleRelativePath", "Public/CustomController.h" },
		{ "ToolTip", "Starts a ray point grasp from RayStart in the direction provided if the tool is set to a grasping tool and a PbdObjectGrasping interaction are set on the controller\n@param RayStart Starting point of the ray\n@param RayDir Direction of the ray to be cast\n@return None" },
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
		{ "Comment", "/** Creates a stitching interaction between the two vertices of the line mesh tool. Requires geometry to be set to a LineMeshTool.\n\x09* @return None\n\x09*/" },
		{ "ModuleRelativePath", "Public/CustomController.h" },
		{ "ToolTip", "Creates a stitching interaction between the two vertices of the line mesh tool. Requires geometry to be set to a LineMeshTool.\n@return None" },
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
		{ "Comment", "/** Starts a vertex grasp if the tool is set to a grasping tool and a PbdObjectGrasping interaction are set on the controller\n\x09* @return None\n\x09*/" },
		{ "ModuleRelativePath", "Public/CustomController.h" },
		{ "ToolTip", "Starts a vertex grasp if the tool is set to a grasping tool and a PbdObjectGrasping interaction are set on the controller\n@return None" },
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
		{ "Comment", "/** Ends the current grasp\n\x09* @return None\n\x09*/" },
		{ "ModuleRelativePath", "Public/CustomController.h" },
		{ "ToolTip", "Ends the current grasp\n@return None" },
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
	struct Z_Construct_UFunction_UCustomController_GetControlleriMSTKPosition_Statics
	{
		struct CustomController_eventGetControlleriMSTKPosition_Parms
		{
			FVector ReturnValue;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCustomController_GetControlleriMSTKPosition_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CustomController_eventGetControlleriMSTKPosition_Parms, ReturnValue), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCustomController_GetControlleriMSTKPosition_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCustomController_GetControlleriMSTKPosition_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCustomController_GetControlleriMSTKPosition_Statics::Function_MetaDataParams[] = {
		{ "Category", "Imstk" },
		{ "ModuleRelativePath", "Public/CustomController.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCustomController_GetControlleriMSTKPosition_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCustomController, nullptr, "GetControlleriMSTKPosition", nullptr, nullptr, sizeof(Z_Construct_UFunction_UCustomController_GetControlleriMSTKPosition_Statics::CustomController_eventGetControlleriMSTKPosition_Parms), Z_Construct_UFunction_UCustomController_GetControlleriMSTKPosition_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCustomController_GetControlleriMSTKPosition_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04880401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UCustomController_GetControlleriMSTKPosition_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UCustomController_GetControlleriMSTKPosition_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UCustomController_GetControlleriMSTKPosition()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCustomController_GetControlleriMSTKPosition_Statics::FuncParams);
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
		{ "Comment", "/** Moves the iMSTK object to the inputted location and orientation. Moves the Unreal Actor that the component is attached to to the specified location if bUpdateUnrealPosRot is set.\n\x09* @param Location - The Unreal position to move the controller to\n\x09* @param Orientation - The Unreal orientation to move the controller to\n\x09* @param bUpdateUnrealPosRot - Updates the position and rotation of the Unreal Actor if true\n\x09* @return None\n\x09*/" },
		{ "CPP_Default_bUpdateUnrealPosRot", "true" },
		{ "ModuleRelativePath", "Public/CustomController.h" },
		{ "ToolTip", "Moves the iMSTK object to the inputted location and orientation. Moves the Unreal Actor that the component is attached to to the specified location if bUpdateUnrealPosRot is set.\n@param Location - The Unreal position to move the controller to\n@param Orientation - The Unreal orientation to move the controller to\n@param bUpdateUnrealPosRot - Updates the position and rotation of the Unreal Actor if true\n@return None" },
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
			FVector ReturnValue;
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
		static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
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
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCustomController_MoveControllerToRaycastOnPlane_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CustomController_eventMoveControllerToRaycastOnPlane_Parms, ReturnValue), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCustomController_MoveControllerToRaycastOnPlane_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCustomController_MoveControllerToRaycastOnPlane_Statics::NewProp_RayStart,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCustomController_MoveControllerToRaycastOnPlane_Statics::NewProp_RayDir,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCustomController_MoveControllerToRaycastOnPlane_Statics::NewProp_Orientation,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCustomController_MoveControllerToRaycastOnPlane_Statics::NewProp_PlaneActor,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCustomController_MoveControllerToRaycastOnPlane_Statics::NewProp_bUpdateUnrealPosRot,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCustomController_MoveControllerToRaycastOnPlane_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCustomController_MoveControllerToRaycastOnPlane_Statics::Function_MetaDataParams[] = {
		{ "Category", "Imstk" },
		{ "Comment", "/** Projects a ray with the specified start and direction onto the supplied plane to find a point of intersection and moves the iMSTK object to that location.\n\x09* Moves the Unreal Actor that the component is attached to to the specified location if bUpdateUnrealPosRot is set.\n\x09* @param Location - The Unreal position to move the controller to\n\x09* @param Orientation - The Unreal orientation to move the controller to\n\x09* @param bUpdateUnrealPosRot - Updates the position and rotation of the Unreal Actor if true\n\x09* @return The intersection location between the projected ray and the plane\n\x09*/" },
		{ "CPP_Default_bUpdateUnrealPosRot", "true" },
		{ "ModuleRelativePath", "Public/CustomController.h" },
		{ "ToolTip", "Projects a ray with the specified start and direction onto the supplied plane to find a point of intersection and moves the iMSTK object to that location.\nMoves the Unreal Actor that the component is attached to to the specified location if bUpdateUnrealPosRot is set.\n@param Location - The Unreal position to move the controller to\n@param Orientation - The Unreal orientation to move the controller to\n@param bUpdateUnrealPosRot - Updates the position and rotation of the Unreal Actor if true\n@return The intersection location between the projected ray and the plane" },
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
	struct Z_Construct_UFunction_UCustomController_SetGhostComponents_Statics
	{
		struct CustomController_eventSetGhostComponents_Parms
		{
			USceneComponent* SceneComponent;
			TArray<UStaticMeshComponent*> StaticMeshComponents;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SceneComponent_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_SceneComponent;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_StaticMeshComponents_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_StaticMeshComponents_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_StaticMeshComponents;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCustomController_SetGhostComponents_Statics::NewProp_SceneComponent_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UCustomController_SetGhostComponents_Statics::NewProp_SceneComponent = { "SceneComponent", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CustomController_eventSetGhostComponents_Parms, SceneComponent), Z_Construct_UClass_USceneComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UCustomController_SetGhostComponents_Statics::NewProp_SceneComponent_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UCustomController_SetGhostComponents_Statics::NewProp_SceneComponent_MetaData)) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UCustomController_SetGhostComponents_Statics::NewProp_StaticMeshComponents_Inner = { "StaticMeshComponents", nullptr, (EPropertyFlags)0x0000000000080000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCustomController_SetGhostComponents_Statics::NewProp_StaticMeshComponents_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UCustomController_SetGhostComponents_Statics::NewProp_StaticMeshComponents = { "StaticMeshComponents", nullptr, (EPropertyFlags)0x0010008000000080, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CustomController_eventSetGhostComponents_Parms, StaticMeshComponents), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UFunction_UCustomController_SetGhostComponents_Statics::NewProp_StaticMeshComponents_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UCustomController_SetGhostComponents_Statics::NewProp_StaticMeshComponents_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCustomController_SetGhostComponents_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCustomController_SetGhostComponents_Statics::NewProp_SceneComponent,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCustomController_SetGhostComponents_Statics::NewProp_StaticMeshComponents_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCustomController_SetGhostComponents_Statics::NewProp_StaticMeshComponents,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCustomController_SetGhostComponents_Statics::Function_MetaDataParams[] = {
		{ "Category", "Imstk" },
		{ "Comment", "/** Sets the components used for the ghost object on force tools\n\x09* @param SceneComponent - Pointer to the empty parent USceneComponent that holds the UStaticMeshComponents\n\x09* @param StaticMeshComponents - Array of pointers to UStaticMeshComponents that represent the ghost model\n\x09*/" },
		{ "ModuleRelativePath", "Public/CustomController.h" },
		{ "ToolTip", "Sets the components used for the ghost object on force tools\n@param SceneComponent - Pointer to the empty parent USceneComponent that holds the UStaticMeshComponents\n@param StaticMeshComponents - Array of pointers to UStaticMeshComponents that represent the ghost model" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCustomController_SetGhostComponents_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCustomController, nullptr, "SetGhostComponents", nullptr, nullptr, sizeof(Z_Construct_UFunction_UCustomController_SetGhostComponents_Statics::CustomController_eventSetGhostComponents_Parms), Z_Construct_UFunction_UCustomController_SetGhostComponents_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCustomController_SetGhostComponents_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04080401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UCustomController_SetGhostComponents_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UCustomController_SetGhostComponents_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UCustomController_SetGhostComponents()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCustomController_SetGhostComponents_Statics::FuncParams);
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
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Preset_MetaData[];
#endif
		static const UECodeGen_Private::FBytePropertyParams NewProp_Preset;
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
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bForceTool_MetaData[];
#endif
		static void NewProp_bForceTool_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bForceTool;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_GhostMaterial_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_GhostMaterial;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bIgnoreAngularForce_MetaData[];
#endif
		static void NewProp_bIgnoreAngularForce_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bIgnoreAngularForce;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SpringForce_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_SpringForce;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DamperForce_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_DamperForce;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_LinearKs_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_LinearKs;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AngularKs_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_AngularKs;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_LinearKd_MetaData[];
#endif
		static const UECodeGen_Private::FDoublePropertyParams NewProp_LinearKd;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AngularKd_MetaData[];
#endif
		static const UECodeGen_Private::FDoublePropertyParams NewProp_AngularKd;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ForceScale_MetaData[];
#endif
		static const UECodeGen_Private::FDoublePropertyParams NewProp_ForceScale;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bPrintImstkPos_MetaData[];
#endif
		static void NewProp_bPrintImstkPos_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bPrintImstkPos;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_GhostSceneComp_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_GhostSceneComp;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_GhostMeshes_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_GhostMeshes_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_GhostMeshes;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UCustomController_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UImstkController,
		(UObject* (*)())Z_Construct_UPackage__Script_Imstk,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UCustomController_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UCustomController_BeginCellGrasp, "BeginCellGrasp" }, // 770634997
		{ &Z_Construct_UFunction_UCustomController_BeginCut, "BeginCut" }, // 2303189727
		{ &Z_Construct_UFunction_UCustomController_BeginRayPointGrasp, "BeginRayPointGrasp" }, // 4254069295
		{ &Z_Construct_UFunction_UCustomController_BeginStitch, "BeginStitch" }, // 261615008
		{ &Z_Construct_UFunction_UCustomController_BeginVertexGrasp, "BeginVertexGrasp" }, // 3894908041
		{ &Z_Construct_UFunction_UCustomController_EndGrasp, "EndGrasp" }, // 3458966767
		{ &Z_Construct_UFunction_UCustomController_GetControlleriMSTKPosition, "GetControlleriMSTKPosition" }, // 1079064868
		{ &Z_Construct_UFunction_UCustomController_MoveControllerToLocation, "MoveControllerToLocation" }, // 1733819221
		{ &Z_Construct_UFunction_UCustomController_MoveControllerToRaycastOnPlane, "MoveControllerToRaycastOnPlane" }, // 616567667
		{ &Z_Construct_UFunction_UCustomController_SetGhostComponents, "SetGhostComponents" }, // 1573569502
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCustomController_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Imstk" },
		{ "Comment", "/** \\file CustomController.h\n *  \\brief Customizable controller to move an object within the iMSTK scene\n *  \\details\n */" },
		{ "HideCategories", "Trigger PhysicsVolume" },
		{ "IncludePath", "CustomController.h" },
		{ "ModuleRelativePath", "Public/CustomController.h" },
		{ "ToolTip", "\\file CustomController.h\n\\brief Customizable controller to move an object within the iMSTK scene\n\\details" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCustomController_Statics::NewProp_Preset_MetaData[] = {
		{ "Category", "General" },
		{ "ModuleRelativePath", "Public/CustomController.h" },
	};
#endif
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UCustomController_Statics::NewProp_Preset = { "Preset", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UCustomController, Preset), Z_Construct_UEnum_Imstk_EControllerPreset, METADATA_PARAMS(Z_Construct_UClass_UCustomController_Statics::NewProp_Preset_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCustomController_Statics::NewProp_Preset_MetaData)) }; // 1497589548
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCustomController_Statics::NewProp_Mass_MetaData[] = {
		{ "Category", "General" },
		{ "Comment", "// Mass of the object in iMSTK\n" },
		{ "ModuleRelativePath", "Public/CustomController.h" },
		{ "ToolTip", "Mass of the object in iMSTK" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCustomController_Statics::NewProp_Mass = { "Mass", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UCustomController, Mass), METADATA_PARAMS(Z_Construct_UClass_UCustomController_Statics::NewProp_Mass_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCustomController_Statics::NewProp_Mass_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCustomController_Statics::NewProp_VelocityDamping_MetaData[] = {
		{ "Category", "General|Advanced" },
		{ "Comment", "//TODO: set default values for these\n// Velocity damping of the tool's rigid body in iMSTK\n" },
		{ "ModuleRelativePath", "Public/CustomController.h" },
		{ "ToolTip", "TODO: set default values for these\n Velocity damping of the tool's rigid body in iMSTK" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCustomController_Statics::NewProp_VelocityDamping = { "VelocityDamping", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UCustomController, VelocityDamping), METADATA_PARAMS(Z_Construct_UClass_UCustomController_Statics::NewProp_VelocityDamping_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCustomController_Statics::NewProp_VelocityDamping_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCustomController_Statics::NewProp_AngularVelocityDamping_MetaData[] = {
		{ "Category", "General|Advanced" },
		{ "Comment", "// Angular velocity damping of the tool's rigid body in iMSTK\n" },
		{ "ModuleRelativePath", "Public/CustomController.h" },
		{ "ToolTip", "Angular velocity damping of the tool's rigid body in iMSTK" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCustomController_Statics::NewProp_AngularVelocityDamping = { "AngularVelocityDamping", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UCustomController, AngularVelocityDamping), METADATA_PARAMS(Z_Construct_UClass_UCustomController_Statics::NewProp_AngularVelocityDamping_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCustomController_Statics::NewProp_AngularVelocityDamping_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCustomController_Statics::NewProp_MaxNumIterations_MetaData[] = {
		{ "Category", "General|Advanced" },
		{ "Comment", "// Maximum iterations of the tool's rigid body in iMSTK\n" },
		{ "ModuleRelativePath", "Public/CustomController.h" },
		{ "ToolTip", "Maximum iterations of the tool's rigid body in iMSTK" },
	};
#endif
	const UECodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_UCustomController_Statics::NewProp_MaxNumIterations = { "MaxNumIterations", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UCustomController, MaxNumIterations), METADATA_PARAMS(Z_Construct_UClass_UCustomController_Statics::NewProp_MaxNumIterations_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCustomController_Statics::NewProp_MaxNumIterations_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCustomController_Statics::NewProp_MaxNumConstraints_MetaData[] = {
		{ "Category", "General|Advanced" },
		{ "Comment", "// Maximum constraints of the tool's rigid body in iMSTK\n" },
		{ "ModuleRelativePath", "Public/CustomController.h" },
		{ "ToolTip", "Maximum constraints of the tool's rigid body in iMSTK" },
	};
#endif
	const UECodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_UCustomController_Statics::NewProp_MaxNumConstraints = { "MaxNumConstraints", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UCustomController, MaxNumConstraints), METADATA_PARAMS(Z_Construct_UClass_UCustomController_Statics::NewProp_MaxNumConstraints_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCustomController_Statics::NewProp_MaxNumConstraints_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCustomController_Statics::NewProp_InertiaTensorMultiplier_MetaData[] = {
		{ "Category", "General|Advanced" },
		{ "ClampMin", "0.01" },
		{ "Comment", "// Inertia tensor of the tool's rigid body in iMSTK\n" },
		{ "ModuleRelativePath", "Public/CustomController.h" },
		{ "ToolTip", "Inertia tensor of the tool's rigid body in iMSTK" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCustomController_Statics::NewProp_InertiaTensorMultiplier = { "InertiaTensorMultiplier", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UCustomController, InertiaTensorMultiplier), METADATA_PARAMS(Z_Construct_UClass_UCustomController_Statics::NewProp_InertiaTensorMultiplier_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCustomController_Statics::NewProp_InertiaTensorMultiplier_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCustomController_Statics::NewProp_bForceTool_MetaData[] = {
		{ "Category", "General|Advanced" },
		{ "Comment", "// Moves the tool using force rather than moving directly to the position given\n" },
		{ "ModuleRelativePath", "Public/CustomController.h" },
		{ "ToolTip", "Moves the tool using force rather than moving directly to the position given" },
	};
#endif
	void Z_Construct_UClass_UCustomController_Statics::NewProp_bForceTool_SetBit(void* Obj)
	{
		((UCustomController*)Obj)->bForceTool = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UCustomController_Statics::NewProp_bForceTool = { "bForceTool", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UCustomController), &Z_Construct_UClass_UCustomController_Statics::NewProp_bForceTool_SetBit, METADATA_PARAMS(Z_Construct_UClass_UCustomController_Statics::NewProp_bForceTool_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCustomController_Statics::NewProp_bForceTool_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCustomController_Statics::NewProp_GhostMaterial_MetaData[] = {
		{ "Category", "General|Advanced" },
		{ "Comment", "// Material of the ghost models \n" },
		{ "EditCondition", "bForceTool" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/CustomController.h" },
		{ "ToolTip", "Material of the ghost models" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UCustomController_Statics::NewProp_GhostMaterial = { "GhostMaterial", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UCustomController, GhostMaterial), Z_Construct_UClass_UMaterial_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UCustomController_Statics::NewProp_GhostMaterial_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCustomController_Statics::NewProp_GhostMaterial_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCustomController_Statics::NewProp_bIgnoreAngularForce_MetaData[] = {
		{ "Category", "General|Advanced|ForceTool" },
		{ "EditCondition", "bForceTool" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/CustomController.h" },
	};
#endif
	void Z_Construct_UClass_UCustomController_Statics::NewProp_bIgnoreAngularForce_SetBit(void* Obj)
	{
		((UCustomController*)Obj)->bIgnoreAngularForce = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UCustomController_Statics::NewProp_bIgnoreAngularForce = { "bIgnoreAngularForce", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UCustomController), &Z_Construct_UClass_UCustomController_Statics::NewProp_bIgnoreAngularForce_SetBit, METADATA_PARAMS(Z_Construct_UClass_UCustomController_Statics::NewProp_bIgnoreAngularForce_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCustomController_Statics::NewProp_bIgnoreAngularForce_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCustomController_Statics::NewProp_SpringForce_MetaData[] = {
		{ "Category", "General|Advanced|ForceTool" },
		{ "Comment", "// Spring force of the force applied to the tool\n" },
		{ "EditCondition", "bForceTool && bIgnoreAngularForce" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/CustomController.h" },
		{ "ToolTip", "Spring force of the force applied to the tool" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCustomController_Statics::NewProp_SpringForce = { "SpringForce", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UCustomController, SpringForce), METADATA_PARAMS(Z_Construct_UClass_UCustomController_Statics::NewProp_SpringForce_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCustomController_Statics::NewProp_SpringForce_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCustomController_Statics::NewProp_DamperForce_MetaData[] = {
		{ "Category", "General|Advanced|ForceTool" },
		{ "Comment", "// Spring damping of the force applied to the tool\n" },
		{ "EditCondition", "bForceTool && bIgnoreAngularForce" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/CustomController.h" },
		{ "ToolTip", "Spring damping of the force applied to the tool" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCustomController_Statics::NewProp_DamperForce = { "DamperForce", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UCustomController, DamperForce), METADATA_PARAMS(Z_Construct_UClass_UCustomController_Statics::NewProp_DamperForce_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCustomController_Statics::NewProp_DamperForce_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCustomController_Statics::NewProp_LinearKs_MetaData[] = {
		{ "Category", "General|Advanced|ForceTool" },
		{ "EditCondition", "bForceTool && !bIgnoreAngularForce" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/CustomController.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UCustomController_Statics::NewProp_LinearKs = { "LinearKs", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UCustomController, LinearKs), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UClass_UCustomController_Statics::NewProp_LinearKs_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCustomController_Statics::NewProp_LinearKs_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCustomController_Statics::NewProp_AngularKs_MetaData[] = {
		{ "Category", "General|Advanced|ForceTool" },
		{ "EditCondition", "bForceTool && !bIgnoreAngularForce" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/CustomController.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UCustomController_Statics::NewProp_AngularKs = { "AngularKs", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UCustomController, AngularKs), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UClass_UCustomController_Statics::NewProp_AngularKs_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCustomController_Statics::NewProp_AngularKs_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCustomController_Statics::NewProp_LinearKd_MetaData[] = {
		{ "Category", "General|Advanced|ForceTool" },
		{ "EditCondition", "bForceTool && !bIgnoreAngularForce" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/CustomController.h" },
	};
#endif
	const UECodeGen_Private::FDoublePropertyParams Z_Construct_UClass_UCustomController_Statics::NewProp_LinearKd = { "LinearKd", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Double, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UCustomController, LinearKd), METADATA_PARAMS(Z_Construct_UClass_UCustomController_Statics::NewProp_LinearKd_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCustomController_Statics::NewProp_LinearKd_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCustomController_Statics::NewProp_AngularKd_MetaData[] = {
		{ "Category", "General|Advanced|ForceTool" },
		{ "EditCondition", "bForceTool && !bIgnoreAngularForce" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/CustomController.h" },
	};
#endif
	const UECodeGen_Private::FDoublePropertyParams Z_Construct_UClass_UCustomController_Statics::NewProp_AngularKd = { "AngularKd", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Double, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UCustomController, AngularKd), METADATA_PARAMS(Z_Construct_UClass_UCustomController_Statics::NewProp_AngularKd_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCustomController_Statics::NewProp_AngularKd_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCustomController_Statics::NewProp_ForceScale_MetaData[] = {
		{ "Category", "General|Advanced|ForceTool" },
		{ "EditCondition", "bForceTool && !bIgnoreAngularForce" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/CustomController.h" },
	};
#endif
	const UECodeGen_Private::FDoublePropertyParams Z_Construct_UClass_UCustomController_Statics::NewProp_ForceScale = { "ForceScale", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Double, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UCustomController, ForceScale), METADATA_PARAMS(Z_Construct_UClass_UCustomController_Statics::NewProp_ForceScale_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCustomController_Statics::NewProp_ForceScale_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCustomController_Statics::NewProp_bPrintImstkPos_MetaData[] = {
		{ "Category", "Debugging" },
		{ "Comment", "// Prints the position of the object to the screen\n" },
		{ "ModuleRelativePath", "Public/CustomController.h" },
		{ "ToolTip", "Prints the position of the object to the screen" },
	};
#endif
	void Z_Construct_UClass_UCustomController_Statics::NewProp_bPrintImstkPos_SetBit(void* Obj)
	{
		((UCustomController*)Obj)->bPrintImstkPos = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UCustomController_Statics::NewProp_bPrintImstkPos = { "bPrintImstkPos", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UCustomController), &Z_Construct_UClass_UCustomController_Statics::NewProp_bPrintImstkPos_SetBit, METADATA_PARAMS(Z_Construct_UClass_UCustomController_Statics::NewProp_bPrintImstkPos_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCustomController_Statics::NewProp_bPrintImstkPos_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCustomController_Statics::NewProp_GhostSceneComp_MetaData[] = {
		{ "Comment", "// Pointer to the empty parent USceneComponent that holds the UStaticMeshComponents. This is what will be moved around the scene to preserve offsets on the UStaticMeshComponents\n" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/CustomController.h" },
		{ "ToolTip", "Pointer to the empty parent USceneComponent that holds the UStaticMeshComponents. This is what will be moved around the scene to preserve offsets on the UStaticMeshComponents" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UCustomController_Statics::NewProp_GhostSceneComp = { "GhostSceneComp", nullptr, (EPropertyFlags)0x0020080000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UCustomController, GhostSceneComp), Z_Construct_UClass_USceneComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UCustomController_Statics::NewProp_GhostSceneComp_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCustomController_Statics::NewProp_GhostSceneComp_MetaData)) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UCustomController_Statics::NewProp_GhostMeshes_Inner = { "GhostMeshes", nullptr, (EPropertyFlags)0x0000000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCustomController_Statics::NewProp_GhostMeshes_MetaData[] = {
		{ "Comment", "// Array of pointers to UStaticMeshComponents that represent the ghost model\n" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/CustomController.h" },
		{ "ToolTip", "Array of pointers to UStaticMeshComponents that represent the ghost model" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UCustomController_Statics::NewProp_GhostMeshes = { "GhostMeshes", nullptr, (EPropertyFlags)0x0020088000000008, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UCustomController, GhostMeshes), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_UCustomController_Statics::NewProp_GhostMeshes_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCustomController_Statics::NewProp_GhostMeshes_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UCustomController_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCustomController_Statics::NewProp_Preset,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCustomController_Statics::NewProp_Mass,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCustomController_Statics::NewProp_VelocityDamping,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCustomController_Statics::NewProp_AngularVelocityDamping,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCustomController_Statics::NewProp_MaxNumIterations,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCustomController_Statics::NewProp_MaxNumConstraints,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCustomController_Statics::NewProp_InertiaTensorMultiplier,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCustomController_Statics::NewProp_bForceTool,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCustomController_Statics::NewProp_GhostMaterial,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCustomController_Statics::NewProp_bIgnoreAngularForce,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCustomController_Statics::NewProp_SpringForce,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCustomController_Statics::NewProp_DamperForce,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCustomController_Statics::NewProp_LinearKs,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCustomController_Statics::NewProp_AngularKs,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCustomController_Statics::NewProp_LinearKd,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCustomController_Statics::NewProp_AngularKd,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCustomController_Statics::NewProp_ForceScale,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCustomController_Statics::NewProp_bPrintImstkPos,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCustomController_Statics::NewProp_GhostSceneComp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCustomController_Statics::NewProp_GhostMeshes_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCustomController_Statics::NewProp_GhostMeshes,
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
		static const FEnumRegisterCompiledInInfo EnumInfo[];
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FEnumRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_Imstk_Source_Imstk_Public_CustomController_h_Statics::EnumInfo[] = {
		{ EControllerPreset_StaticEnum, TEXT("EControllerPreset"), &Z_Registration_Info_UEnum_EControllerPreset, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1497589548U) },
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_Imstk_Source_Imstk_Public_CustomController_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UCustomController, UCustomController::StaticClass, TEXT("UCustomController"), &Z_Registration_Info_UClass_UCustomController, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UCustomController), 2096512419U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_Imstk_Source_Imstk_Public_CustomController_h_2282379526(TEXT("/Script/Imstk"),
		Z_CompiledInDeferFile_FID_HostProject_Plugins_Imstk_Source_Imstk_Public_CustomController_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HostProject_Plugins_Imstk_Source_Imstk_Public_CustomController_h_Statics::ClassInfo),
		nullptr, 0,
		Z_CompiledInDeferFile_FID_HostProject_Plugins_Imstk_Source_Imstk_Public_CustomController_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HostProject_Plugins_Imstk_Source_Imstk_Public_CustomController_h_Statics::EnumInfo));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
