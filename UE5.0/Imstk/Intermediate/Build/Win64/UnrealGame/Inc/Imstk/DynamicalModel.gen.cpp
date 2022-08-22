// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Imstk/Public/DynamicalModel.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeDynamicalModel() {}
// Cross Module References
	IMSTK_API UClass* Z_Construct_UClass_UDynamicalModel_NoRegister();
	IMSTK_API UClass* Z_Construct_UClass_UDynamicalModel();
	IMSTK_API UClass* Z_Construct_UClass_UImstkBehaviour();
	UPackage* Z_Construct_UPackage__Script_Imstk();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	IMSTK_API UScriptStruct* Z_Construct_UScriptStruct_FGeometryFilter();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	IMSTK_API UClass* Z_Construct_UClass_UImstkSubsystem_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(UDynamicalModel::execGetGeomOffset)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FVector*)Z_Param__Result=P_THIS->GetGeomOffset();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDynamicalModel::execGetGeomScale)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FVector*)Z_Param__Result=P_THIS->GetGeomScale();
		P_NATIVE_END;
	}
	void UDynamicalModel::StaticRegisterNativesUDynamicalModel()
	{
		UClass* Class = UDynamicalModel::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetGeomOffset", &UDynamicalModel::execGetGeomOffset },
			{ "GetGeomScale", &UDynamicalModel::execGetGeomScale },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UDynamicalModel_GetGeomOffset_Statics
	{
		struct DynamicalModel_eventGetGeomOffset_Parms
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
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UDynamicalModel_GetGeomOffset_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DynamicalModel_eventGetGeomOffset_Parms, ReturnValue), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDynamicalModel_GetGeomOffset_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDynamicalModel_GetGeomOffset_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDynamicalModel_GetGeomOffset_Statics::Function_MetaDataParams[] = {
		{ "Category", "iMSTK" },
		{ "Comment", "/** Returns the amount the geometry is offset within iMSTK\n\x09* @return FVector - Offset of the geometry or zero vector if not implemented\n\x09*/" },
		{ "ModuleRelativePath", "Public/DynamicalModel.h" },
		{ "ToolTip", "Returns the amount the geometry is offset within iMSTK\n@return FVector - Offset of the geometry or zero vector if not implemented" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDynamicalModel_GetGeomOffset_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDynamicalModel, nullptr, "GetGeomOffset", nullptr, nullptr, sizeof(Z_Construct_UFunction_UDynamicalModel_GetGeomOffset_Statics::DynamicalModel_eventGetGeomOffset_Parms), Z_Construct_UFunction_UDynamicalModel_GetGeomOffset_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDynamicalModel_GetGeomOffset_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UDynamicalModel_GetGeomOffset_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UDynamicalModel_GetGeomOffset_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UDynamicalModel_GetGeomOffset()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDynamicalModel_GetGeomOffset_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDynamicalModel_GetGeomScale_Statics
	{
		struct DynamicalModel_eventGetGeomScale_Parms
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
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UDynamicalModel_GetGeomScale_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DynamicalModel_eventGetGeomScale_Parms, ReturnValue), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDynamicalModel_GetGeomScale_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDynamicalModel_GetGeomScale_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDynamicalModel_GetGeomScale_Statics::Function_MetaDataParams[] = {
		{ "Category", "iMSTK" },
		{ "Comment", "/** Calculates and returns the scale applied to Unreal's basic shapes in order to have the same shape as iMSTK's geometry\n\x09* @return FVector - Scale of the geometry or zero vector if not implemented\n\x09*/" },
		{ "ModuleRelativePath", "Public/DynamicalModel.h" },
		{ "ToolTip", "Calculates and returns the scale applied to Unreal's basic shapes in order to have the same shape as iMSTK's geometry\n@return FVector - Scale of the geometry or zero vector if not implemented" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDynamicalModel_GetGeomScale_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDynamicalModel, nullptr, "GetGeomScale", nullptr, nullptr, sizeof(Z_Construct_UFunction_UDynamicalModel_GetGeomScale_Statics::DynamicalModel_eventGetGeomScale_Parms), Z_Construct_UFunction_UDynamicalModel_GetGeomScale_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDynamicalModel_GetGeomScale_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UDynamicalModel_GetGeomScale_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UDynamicalModel_GetGeomScale_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UDynamicalModel_GetGeomScale()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDynamicalModel_GetGeomScale_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UDynamicalModel);
	UClass* Z_Construct_UClass_UDynamicalModel_NoRegister()
	{
		return UDynamicalModel::StaticClass();
	}
	struct Z_Construct_UClass_UDynamicalModel_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_GeomFilter_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_GeomFilter;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bIndividualGravity_MetaData[];
#endif
		static void NewProp_bIndividualGravity_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bIndividualGravity;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Gravity_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Gravity;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bIndividualDT_MetaData[];
#endif
		static void NewProp_bIndividualDT_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bIndividualDT;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_IndividualDT_MetaData[];
#endif
		static const UECodeGen_Private::FDoublePropertyParams NewProp_IndividualDT;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Owner_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Owner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SubsystemInstance_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_SubsystemInstance;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bPrintPositionInformation_MetaData[];
#endif
		static void NewProp_bPrintPositionInformation_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bPrintPositionInformation;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UDynamicalModel_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UImstkBehaviour,
		(UObject* (*)())Z_Construct_UPackage__Script_Imstk,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UDynamicalModel_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UDynamicalModel_GetGeomOffset, "GetGeomOffset" }, // 936214221
		{ &Z_Construct_UFunction_UDynamicalModel_GetGeomScale, "GetGeomScale" }, // 2796548449
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDynamicalModel_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/** \\file DynamicalModel.h\n *  \\brief Abstract class to model any object that is added to the Imstk scene\n *  \\details Contains a geometry filter to convert between Unreal and Imstk objects\n */" },
		{ "IncludePath", "DynamicalModel.h" },
		{ "ModuleRelativePath", "Public/DynamicalModel.h" },
		{ "ToolTip", "\\file DynamicalModel.h\n\\brief Abstract class to model any object that is added to the Imstk scene\n\\details Contains a geometry filter to convert between Unreal and Imstk objects" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDynamicalModel_Statics::NewProp_GeomFilter_MetaData[] = {
		{ "Category", "General|Geometry" },
		{ "Comment", "// Geometry of the model\n" },
		{ "ModuleRelativePath", "Public/DynamicalModel.h" },
		{ "ToolTip", "Geometry of the model" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UDynamicalModel_Statics::NewProp_GeomFilter = { "GeomFilter", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UDynamicalModel, GeomFilter), Z_Construct_UScriptStruct_FGeometryFilter, METADATA_PARAMS(Z_Construct_UClass_UDynamicalModel_Statics::NewProp_GeomFilter_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UDynamicalModel_Statics::NewProp_GeomFilter_MetaData)) }; // 76715730
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDynamicalModel_Statics::NewProp_bIndividualGravity_MetaData[] = {
		{ "Category", "General" },
		{ "Comment", "// Set the object to have separate gravity from the rest of the scene in iMSTK\n" },
		{ "ModuleRelativePath", "Public/DynamicalModel.h" },
		{ "ToolTip", "Set the object to have separate gravity from the rest of the scene in iMSTK" },
	};
#endif
	void Z_Construct_UClass_UDynamicalModel_Statics::NewProp_bIndividualGravity_SetBit(void* Obj)
	{
		((UDynamicalModel*)Obj)->bIndividualGravity = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UDynamicalModel_Statics::NewProp_bIndividualGravity = { "bIndividualGravity", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UDynamicalModel), &Z_Construct_UClass_UDynamicalModel_Statics::NewProp_bIndividualGravity_SetBit, METADATA_PARAMS(Z_Construct_UClass_UDynamicalModel_Statics::NewProp_bIndividualGravity_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UDynamicalModel_Statics::NewProp_bIndividualGravity_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDynamicalModel_Statics::NewProp_Gravity_MetaData[] = {
		{ "Category", "General" },
		{ "EditCondition", "bIndividualGravity == true" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/DynamicalModel.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UDynamicalModel_Statics::NewProp_Gravity = { "Gravity", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UDynamicalModel, Gravity), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UClass_UDynamicalModel_Statics::NewProp_Gravity_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UDynamicalModel_Statics::NewProp_Gravity_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDynamicalModel_Statics::NewProp_bIndividualDT_MetaData[] = {
		{ "Category", "General" },
		{ "Comment", "// Set the object to have a separate time step from the rest of the scene in iMSTK\n" },
		{ "ModuleRelativePath", "Public/DynamicalModel.h" },
		{ "ToolTip", "Set the object to have a separate time step from the rest of the scene in iMSTK" },
	};
#endif
	void Z_Construct_UClass_UDynamicalModel_Statics::NewProp_bIndividualDT_SetBit(void* Obj)
	{
		((UDynamicalModel*)Obj)->bIndividualDT = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UDynamicalModel_Statics::NewProp_bIndividualDT = { "bIndividualDT", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UDynamicalModel), &Z_Construct_UClass_UDynamicalModel_Statics::NewProp_bIndividualDT_SetBit, METADATA_PARAMS(Z_Construct_UClass_UDynamicalModel_Statics::NewProp_bIndividualDT_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UDynamicalModel_Statics::NewProp_bIndividualDT_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDynamicalModel_Statics::NewProp_IndividualDT_MetaData[] = {
		{ "Category", "General" },
		{ "ClampMin", "0" },
		{ "EditCondition", "bIndividualDT == true" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/DynamicalModel.h" },
	};
#endif
	const UECodeGen_Private::FDoublePropertyParams Z_Construct_UClass_UDynamicalModel_Statics::NewProp_IndividualDT = { "IndividualDT", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Double, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UDynamicalModel, IndividualDT), METADATA_PARAMS(Z_Construct_UClass_UDynamicalModel_Statics::NewProp_IndividualDT_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UDynamicalModel_Statics::NewProp_IndividualDT_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDynamicalModel_Statics::NewProp_Owner_MetaData[] = {
		{ "Comment", "// References to the owning object\n" },
		{ "ModuleRelativePath", "Public/DynamicalModel.h" },
		{ "ToolTip", "References to the owning object" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UDynamicalModel_Statics::NewProp_Owner = { "Owner", nullptr, (EPropertyFlags)0x0020080000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UDynamicalModel, Owner), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UDynamicalModel_Statics::NewProp_Owner_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UDynamicalModel_Statics::NewProp_Owner_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDynamicalModel_Statics::NewProp_SubsystemInstance_MetaData[] = {
		{ "Comment", "// Reference to the imstk subsystem\n" },
		{ "ModuleRelativePath", "Public/DynamicalModel.h" },
		{ "ToolTip", "Reference to the imstk subsystem" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UDynamicalModel_Statics::NewProp_SubsystemInstance = { "SubsystemInstance", nullptr, (EPropertyFlags)0x0020080000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UDynamicalModel, SubsystemInstance), Z_Construct_UClass_UImstkSubsystem_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UDynamicalModel_Statics::NewProp_SubsystemInstance_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UDynamicalModel_Statics::NewProp_SubsystemInstance_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDynamicalModel_Statics::NewProp_bPrintPositionInformation_MetaData[] = {
		{ "Category", "Debugging" },
		{ "Comment", "// Print the location of the object converted to Unreal from iMSTK\n" },
		{ "ModuleRelativePath", "Public/DynamicalModel.h" },
		{ "ToolTip", "Print the location of the object converted to Unreal from iMSTK" },
	};
#endif
	void Z_Construct_UClass_UDynamicalModel_Statics::NewProp_bPrintPositionInformation_SetBit(void* Obj)
	{
		((UDynamicalModel*)Obj)->bPrintPositionInformation = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UDynamicalModel_Statics::NewProp_bPrintPositionInformation = { "bPrintPositionInformation", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UDynamicalModel), &Z_Construct_UClass_UDynamicalModel_Statics::NewProp_bPrintPositionInformation_SetBit, METADATA_PARAMS(Z_Construct_UClass_UDynamicalModel_Statics::NewProp_bPrintPositionInformation_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UDynamicalModel_Statics::NewProp_bPrintPositionInformation_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UDynamicalModel_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDynamicalModel_Statics::NewProp_GeomFilter,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDynamicalModel_Statics::NewProp_bIndividualGravity,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDynamicalModel_Statics::NewProp_Gravity,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDynamicalModel_Statics::NewProp_bIndividualDT,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDynamicalModel_Statics::NewProp_IndividualDT,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDynamicalModel_Statics::NewProp_Owner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDynamicalModel_Statics::NewProp_SubsystemInstance,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDynamicalModel_Statics::NewProp_bPrintPositionInformation,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UDynamicalModel_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDynamicalModel>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UDynamicalModel_Statics::ClassParams = {
		&UDynamicalModel::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UDynamicalModel_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UDynamicalModel_Statics::PropPointers),
		0,
		0x00B000A5u,
		METADATA_PARAMS(Z_Construct_UClass_UDynamicalModel_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UDynamicalModel_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UDynamicalModel()
	{
		if (!Z_Registration_Info_UClass_UDynamicalModel.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDynamicalModel.OuterSingleton, Z_Construct_UClass_UDynamicalModel_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UDynamicalModel.OuterSingleton;
	}
	template<> IMSTK_API UClass* StaticClass<UDynamicalModel>()
	{
		return UDynamicalModel::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UDynamicalModel);
	struct Z_CompiledInDeferFile_FID_HostProject_Plugins_Imstk_Source_Imstk_Public_DynamicalModel_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_Imstk_Source_Imstk_Public_DynamicalModel_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UDynamicalModel, UDynamicalModel::StaticClass, TEXT("UDynamicalModel"), &Z_Registration_Info_UClass_UDynamicalModel, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDynamicalModel), 321087035U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_Imstk_Source_Imstk_Public_DynamicalModel_h_172998164(TEXT("/Script/Imstk"),
		Z_CompiledInDeferFile_FID_HostProject_Plugins_Imstk_Source_Imstk_Public_DynamicalModel_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HostProject_Plugins_Imstk_Source_Imstk_Public_DynamicalModel_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
