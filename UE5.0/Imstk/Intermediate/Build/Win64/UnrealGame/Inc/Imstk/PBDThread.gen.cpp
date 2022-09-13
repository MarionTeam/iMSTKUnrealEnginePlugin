// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Imstk/Public/PBDThread.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePBDThread() {}
// Cross Module References
	IMSTK_API UClass* Z_Construct_UClass_UPBDThread_NoRegister();
	IMSTK_API UClass* Z_Construct_UClass_UPBDThread();
	IMSTK_API UClass* Z_Construct_UClass_UDeformableModel();
	UPackage* Z_Construct_UPackage__Script_Imstk();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	ENGINE_API UClass* Z_Construct_UClass_USplineComponent_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(UPBDThread::execMoveVertexToLocation)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_VertIndex);
		P_GET_STRUCT(FVector,Z_Param_Pos);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->MoveVertexToLocation(Z_Param_VertIndex,Z_Param_Pos);
		P_NATIVE_END;
	}
	void UPBDThread::StaticRegisterNativesUPBDThread()
	{
		UClass* Class = UPBDThread::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "MoveVertexToLocation", &UPBDThread::execMoveVertexToLocation },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UPBDThread_MoveVertexToLocation_Statics
	{
		struct PBDThread_eventMoveVertexToLocation_Parms
		{
			int32 VertIndex;
			FVector Pos;
		};
		static const UECodeGen_Private::FUnsizedIntPropertyParams NewProp_VertIndex;
		static const UECodeGen_Private::FStructPropertyParams NewProp_Pos;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_UPBDThread_MoveVertexToLocation_Statics::NewProp_VertIndex = { "VertIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PBDThread_eventMoveVertexToLocation_Parms, VertIndex), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPBDThread_MoveVertexToLocation_Statics::NewProp_Pos = { "Pos", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PBDThread_eventMoveVertexToLocation_Parms, Pos), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPBDThread_MoveVertexToLocation_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPBDThread_MoveVertexToLocation_Statics::NewProp_VertIndex,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPBDThread_MoveVertexToLocation_Statics::NewProp_Pos,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPBDThread_MoveVertexToLocation_Statics::Function_MetaDataParams[] = {
		{ "Category", "Imstk" },
		{ "Comment", "/** Moves the specified vertex on the thread to the location. Note: Node on thread may need to be fixed for intended behaviour in iMSTK\n\x09* @param VertIndex Vertex to move\n\x09* @param Pos Position to move the vertex to\n\x09* @return None\n\x09*/" },
		{ "ModuleRelativePath", "Public/PBDThread.h" },
		{ "ToolTip", "Moves the specified vertex on the thread to the location. Note: Node on thread may need to be fixed for intended behaviour in iMSTK\n@param VertIndex Vertex to move\n@param Pos Position to move the vertex to\n@return None" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPBDThread_MoveVertexToLocation_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPBDThread, nullptr, "MoveVertexToLocation", nullptr, nullptr, sizeof(Z_Construct_UFunction_UPBDThread_MoveVertexToLocation_Statics::PBDThread_eventMoveVertexToLocation_Parms), Z_Construct_UFunction_UPBDThread_MoveVertexToLocation_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPBDThread_MoveVertexToLocation_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UPBDThread_MoveVertexToLocation_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UPBDThread_MoveVertexToLocation_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UPBDThread_MoveVertexToLocation()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPBDThread_MoveVertexToLocation_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UPBDThread);
	UClass* Z_Construct_UClass_UPBDThread_NoRegister()
	{
		return UPBDThread::StaticClass();
	}
	struct Z_Construct_UClass_UPBDThread_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bZeroTangents_MetaData[];
#endif
		static void NewProp_bZeroTangents_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bZeroTangents;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bUseBendConstraint_MetaData[];
#endif
		static void NewProp_bUseBendConstraint_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bUseBendConstraint;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_BendStiffness_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_BendStiffness;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SplineComponent_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_SplineComponent;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UPBDThread_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UDeformableModel,
		(UObject* (*)())Z_Construct_UPackage__Script_Imstk,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UPBDThread_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UPBDThread_MoveVertexToLocation, "MoveVertexToLocation" }, // 1762989890
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPBDThread_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Imstk" },
		{ "Comment", "/**\n *   \n */" },
		{ "HideCategories", "General|Geometry" },
		{ "IncludePath", "PBDThread.h" },
		{ "ModuleRelativePath", "Public/PBDThread.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPBDThread_Statics::NewProp_bZeroTangents_MetaData[] = {
		{ "Category", "General|Advanced" },
		{ "Comment", "// Zeros the tangents for the spine in Unreal \n// TODO: maybe remove this option\n" },
		{ "ModuleRelativePath", "Public/PBDThread.h" },
		{ "ToolTip", "Zeros the tangents for the spine in Unreal\nTODO: maybe remove this option" },
	};
#endif
	void Z_Construct_UClass_UPBDThread_Statics::NewProp_bZeroTangents_SetBit(void* Obj)
	{
		((UPBDThread*)Obj)->bZeroTangents = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UPBDThread_Statics::NewProp_bZeroTangents = { "bZeroTangents", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UPBDThread), &Z_Construct_UClass_UPBDThread_Statics::NewProp_bZeroTangents_SetBit, METADATA_PARAMS(Z_Construct_UClass_UPBDThread_Statics::NewProp_bZeroTangents_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UPBDThread_Statics::NewProp_bZeroTangents_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPBDThread_Statics::NewProp_bUseBendConstraint_MetaData[] = {
		{ "Category", "General|Advanced|Constraints" },
		{ "ModuleRelativePath", "Public/PBDThread.h" },
	};
#endif
	void Z_Construct_UClass_UPBDThread_Statics::NewProp_bUseBendConstraint_SetBit(void* Obj)
	{
		((UPBDThread*)Obj)->bUseBendConstraint = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UPBDThread_Statics::NewProp_bUseBendConstraint = { "bUseBendConstraint", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UPBDThread), &Z_Construct_UClass_UPBDThread_Statics::NewProp_bUseBendConstraint_SetBit, METADATA_PARAMS(Z_Construct_UClass_UPBDThread_Statics::NewProp_bUseBendConstraint_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UPBDThread_Statics::NewProp_bUseBendConstraint_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPBDThread_Statics::NewProp_BendStiffness_MetaData[] = {
		{ "Category", "General|Advanced|Constraints" },
		{ "EditCondition", "bUseBendConstraint" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/PBDThread.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UPBDThread_Statics::NewProp_BendStiffness = { "BendStiffness", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UPBDThread, BendStiffness), METADATA_PARAMS(Z_Construct_UClass_UPBDThread_Statics::NewProp_BendStiffness_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UPBDThread_Statics::NewProp_BendStiffness_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPBDThread_Statics::NewProp_SplineComponent_MetaData[] = {
		{ "Comment", "// Spline component attached to the Actor\n" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/PBDThread.h" },
		{ "ToolTip", "Spline component attached to the Actor" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UPBDThread_Statics::NewProp_SplineComponent = { "SplineComponent", nullptr, (EPropertyFlags)0x0010000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UPBDThread, SplineComponent), Z_Construct_UClass_USplineComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UPBDThread_Statics::NewProp_SplineComponent_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UPBDThread_Statics::NewProp_SplineComponent_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UPBDThread_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPBDThread_Statics::NewProp_bZeroTangents,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPBDThread_Statics::NewProp_bUseBendConstraint,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPBDThread_Statics::NewProp_BendStiffness,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPBDThread_Statics::NewProp_SplineComponent,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UPBDThread_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPBDThread>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UPBDThread_Statics::ClassParams = {
		&UPBDThread::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UPBDThread_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UPBDThread_Statics::PropPointers),
		0,
		0x00B000A4u,
		METADATA_PARAMS(Z_Construct_UClass_UPBDThread_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UPBDThread_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UPBDThread()
	{
		if (!Z_Registration_Info_UClass_UPBDThread.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UPBDThread.OuterSingleton, Z_Construct_UClass_UPBDThread_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UPBDThread.OuterSingleton;
	}
	template<> IMSTK_API UClass* StaticClass<UPBDThread>()
	{
		return UPBDThread::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UPBDThread);
	struct Z_CompiledInDeferFile_FID_HostProject_Plugins_Imstk_Source_Imstk_Public_PBDThread_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_Imstk_Source_Imstk_Public_PBDThread_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UPBDThread, UPBDThread::StaticClass, TEXT("UPBDThread"), &Z_Registration_Info_UClass_UPBDThread, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UPBDThread), 1772321125U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_Imstk_Source_Imstk_Public_PBDThread_h_3102200793(TEXT("/Script/Imstk"),
		Z_CompiledInDeferFile_FID_HostProject_Plugins_Imstk_Source_Imstk_Public_PBDThread_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HostProject_Plugins_Imstk_Source_Imstk_Public_PBDThread_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
