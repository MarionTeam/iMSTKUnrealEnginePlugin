// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Imstk/Public/ImstkController.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeImstkController() {}
// Cross Module References
	IMSTK_API UEnum* Z_Construct_UEnum_Imstk_EToolGeometry();
	UPackage* Z_Construct_UPackage__Script_Imstk();
	IMSTK_API UEnum* Z_Construct_UEnum_Imstk_EGraspType();
	IMSTK_API UEnum* Z_Construct_UEnum_Imstk_EToolType();
	IMSTK_API UClass* Z_Construct_UClass_UImstkController_NoRegister();
	IMSTK_API UClass* Z_Construct_UClass_UImstkController();
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
	IMSTK_API UClass* Z_Construct_UClass_UImstkSubsystem_NoRegister();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
// End Cross Module References
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_EToolGeometry;
	static UEnum* EToolGeometry_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_EToolGeometry.OuterSingleton)
		{
			Z_Registration_Info_UEnum_EToolGeometry.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_Imstk_EToolGeometry, Z_Construct_UPackage__Script_Imstk(), TEXT("EToolGeometry"));
		}
		return Z_Registration_Info_UEnum_EToolGeometry.OuterSingleton;
	}
	template<> IMSTK_API UEnum* StaticEnum<EToolGeometry>()
	{
		return EToolGeometry_StaticEnum();
	}
	struct Z_Construct_UEnum_Imstk_EToolGeometry_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_Imstk_EToolGeometry_Statics::Enumerators[] = {
		{ "LineMeshTool", (int64)LineMeshTool },
		{ "SphereTool", (int64)SphereTool },
		{ "CapsuleTool", (int64)CapsuleTool },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_Imstk_EToolGeometry_Statics::Enum_MetaDataParams[] = {
		{ "CapsuleTool.Name", "CapsuleTool" },
		{ "LineMeshTool.Name", "LineMeshTool" },
		{ "ModuleRelativePath", "Public/ImstkController.h" },
		{ "SphereTool.Name", "SphereTool" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_Imstk_EToolGeometry_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_Imstk,
		nullptr,
		"EToolGeometry",
		"EToolGeometry",
		Z_Construct_UEnum_Imstk_EToolGeometry_Statics::Enumerators,
		UE_ARRAY_COUNT(Z_Construct_UEnum_Imstk_EToolGeometry_Statics::Enumerators),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::Regular,
		METADATA_PARAMS(Z_Construct_UEnum_Imstk_EToolGeometry_Statics::Enum_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UEnum_Imstk_EToolGeometry_Statics::Enum_MetaDataParams))
	};
	UEnum* Z_Construct_UEnum_Imstk_EToolGeometry()
	{
		if (!Z_Registration_Info_UEnum_EToolGeometry.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EToolGeometry.InnerSingleton, Z_Construct_UEnum_Imstk_EToolGeometry_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_EToolGeometry.InnerSingleton;
	}
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_EGraspType;
	static UEnum* EGraspType_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_EGraspType.OuterSingleton)
		{
			Z_Registration_Info_UEnum_EGraspType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_Imstk_EGraspType, Z_Construct_UPackage__Script_Imstk(), TEXT("EGraspType"));
		}
		return Z_Registration_Info_UEnum_EGraspType.OuterSingleton;
	}
	template<> IMSTK_API UEnum* StaticEnum<EGraspType>()
	{
		return EGraspType_StaticEnum();
	}
	struct Z_Construct_UEnum_Imstk_EGraspType_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_Imstk_EGraspType_Statics::Enumerators[] = {
		{ "RayPointGrasp", (int64)RayPointGrasp },
		{ "VertexGrasp", (int64)VertexGrasp },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_Imstk_EGraspType_Statics::Enum_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/ImstkController.h" },
		{ "RayPointGrasp.Name", "RayPointGrasp" },
		{ "VertexGrasp.Name", "VertexGrasp" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_Imstk_EGraspType_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_Imstk,
		nullptr,
		"EGraspType",
		"EGraspType",
		Z_Construct_UEnum_Imstk_EGraspType_Statics::Enumerators,
		UE_ARRAY_COUNT(Z_Construct_UEnum_Imstk_EGraspType_Statics::Enumerators),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::Regular,
		METADATA_PARAMS(Z_Construct_UEnum_Imstk_EGraspType_Statics::Enum_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UEnum_Imstk_EGraspType_Statics::Enum_MetaDataParams))
	};
	UEnum* Z_Construct_UEnum_Imstk_EGraspType()
	{
		if (!Z_Registration_Info_UEnum_EGraspType.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EGraspType.InnerSingleton, Z_Construct_UEnum_Imstk_EGraspType_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_EGraspType.InnerSingleton;
	}
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_EToolType;
	static UEnum* EToolType_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_EToolType.OuterSingleton)
		{
			Z_Registration_Info_UEnum_EToolType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_Imstk_EToolType, Z_Construct_UPackage__Script_Imstk(), TEXT("EToolType"));
		}
		return Z_Registration_Info_UEnum_EToolType.OuterSingleton;
	}
	template<> IMSTK_API UEnum* StaticEnum<EToolType>()
	{
		return EToolType_StaticEnum();
	}
	struct Z_Construct_UEnum_Imstk_EToolType_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_Imstk_EToolType_Statics::Enumerators[] = {
		{ "GraspingTool", (int64)GraspingTool },
		{ "StitchingTool", (int64)StitchingTool },
		{ "CollidingTool", (int64)CollidingTool },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_Imstk_EToolType_Statics::Enum_MetaDataParams[] = {
		{ "CollidingTool.Name", "CollidingTool" },
		{ "GraspingTool.Name", "GraspingTool" },
		{ "ModuleRelativePath", "Public/ImstkController.h" },
		{ "StitchingTool.Name", "StitchingTool" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_Imstk_EToolType_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_Imstk,
		nullptr,
		"EToolType",
		"EToolType",
		Z_Construct_UEnum_Imstk_EToolType_Statics::Enumerators,
		UE_ARRAY_COUNT(Z_Construct_UEnum_Imstk_EToolType_Statics::Enumerators),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::Regular,
		METADATA_PARAMS(Z_Construct_UEnum_Imstk_EToolType_Statics::Enum_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UEnum_Imstk_EToolType_Statics::Enum_MetaDataParams))
	};
	UEnum* Z_Construct_UEnum_Imstk_EToolType()
	{
		if (!Z_Registration_Info_UEnum_EToolType.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EToolType.InnerSingleton, Z_Construct_UEnum_Imstk_EToolType_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_EToolType.InnerSingleton;
	}
	DEFINE_FUNCTION(UImstkController::execIsInitialized)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->IsInitialized();
		P_NATIVE_END;
	}
	void UImstkController::StaticRegisterNativesUImstkController()
	{
		UClass* Class = UImstkController::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "IsInitialized", &UImstkController::execIsInitialized },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UImstkController_IsInitialized_Statics
	{
		struct ImstkController_eventIsInitialized_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UImstkController_IsInitialized_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((ImstkController_eventIsInitialized_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UImstkController_IsInitialized_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(ImstkController_eventIsInitialized_Parms), &Z_Construct_UFunction_UImstkController_IsInitialized_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UImstkController_IsInitialized_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UImstkController_IsInitialized_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UImstkController_IsInitialized_Statics::Function_MetaDataParams[] = {
		{ "Category", "Imstk" },
		{ "ModuleRelativePath", "Public/ImstkController.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UImstkController_IsInitialized_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UImstkController, nullptr, "IsInitialized", nullptr, nullptr, sizeof(Z_Construct_UFunction_UImstkController_IsInitialized_Statics::ImstkController_eventIsInitialized_Parms), Z_Construct_UFunction_UImstkController_IsInitialized_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UImstkController_IsInitialized_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UImstkController_IsInitialized_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UImstkController_IsInitialized_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UImstkController_IsInitialized()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UImstkController_IsInitialized_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UImstkController);
	UClass* Z_Construct_UClass_UImstkController_NoRegister()
	{
		return UImstkController::StaticClass();
	}
	struct Z_Construct_UClass_UImstkController_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SubsystemInstance_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_SubsystemInstance;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ToolGeometry_MetaData[];
#endif
		static const UECodeGen_Private::FBytePropertyParams NewProp_ToolGeometry;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bGraspingTool_MetaData[];
#endif
		static void NewProp_bGraspingTool_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bGraspingTool;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_GraspType_MetaData[];
#endif
		static const UECodeGen_Private::FBytePropertyParams NewProp_GraspType;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_GraspStiffness_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_GraspStiffness;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bStitchingTool_MetaData[];
#endif
		static void NewProp_bStitchingTool_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bStitchingTool;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Vertex1_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Vertex1;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Vertex2_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Vertex2;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Radius_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Radius;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Length_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Length;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UImstkController_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UActorComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_Imstk,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UImstkController_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UImstkController_IsInitialized, "IsInitialized" }, // 2324562878
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UImstkController_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/** \\file ImstkController.h\n *  \\brief Abstract class for object in imstk that can be controlled by the user\n *  \\details \n */" },
		{ "IncludePath", "ImstkController.h" },
		{ "ModuleRelativePath", "Public/ImstkController.h" },
		{ "ToolTip", "\\file ImstkController.h\n\\brief Abstract class for object in imstk that can be controlled by the user\n\\details" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UImstkController_Statics::NewProp_SubsystemInstance_MetaData[] = {
		{ "ModuleRelativePath", "Public/ImstkController.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UImstkController_Statics::NewProp_SubsystemInstance = { "SubsystemInstance", nullptr, (EPropertyFlags)0x0020080000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UImstkController, SubsystemInstance), Z_Construct_UClass_UImstkSubsystem_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UImstkController_Statics::NewProp_SubsystemInstance_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UImstkController_Statics::NewProp_SubsystemInstance_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UImstkController_Statics::NewProp_ToolGeometry_MetaData[] = {
		{ "Category", "General" },
		{ "ModuleRelativePath", "Public/ImstkController.h" },
	};
#endif
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UImstkController_Statics::NewProp_ToolGeometry = { "ToolGeometry", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UImstkController, ToolGeometry), Z_Construct_UEnum_Imstk_EToolGeometry, METADATA_PARAMS(Z_Construct_UClass_UImstkController_Statics::NewProp_ToolGeometry_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UImstkController_Statics::NewProp_ToolGeometry_MetaData)) }; // 3887863533
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UImstkController_Statics::NewProp_bGraspingTool_MetaData[] = {
		{ "Category", "General" },
		{ "Comment", "// TODO: If you set as true with a spheretool then change geometry it will be hidden but still set to true\n" },
		{ "EditCondition", "ToolGeometry == EToolGeometry::SphereTool || ToolGeometry == EToolGeometry::CapsuleTool" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/ImstkController.h" },
		{ "ToolTip", "TODO: If you set as true with a spheretool then change geometry it will be hidden but still set to true" },
	};
#endif
	void Z_Construct_UClass_UImstkController_Statics::NewProp_bGraspingTool_SetBit(void* Obj)
	{
		((UImstkController*)Obj)->bGraspingTool = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UImstkController_Statics::NewProp_bGraspingTool = { "bGraspingTool", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UImstkController), &Z_Construct_UClass_UImstkController_Statics::NewProp_bGraspingTool_SetBit, METADATA_PARAMS(Z_Construct_UClass_UImstkController_Statics::NewProp_bGraspingTool_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UImstkController_Statics::NewProp_bGraspingTool_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UImstkController_Statics::NewProp_GraspType_MetaData[] = {
		{ "Category", "General" },
		{ "EditCondition", "bGraspingTool && ToolGeometry == EToolGeometry::SphereTool || ToolGeometry == EToolGeometry::CapsuleTool" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/ImstkController.h" },
	};
#endif
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UImstkController_Statics::NewProp_GraspType = { "GraspType", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UImstkController, GraspType), Z_Construct_UEnum_Imstk_EGraspType, METADATA_PARAMS(Z_Construct_UClass_UImstkController_Statics::NewProp_GraspType_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UImstkController_Statics::NewProp_GraspType_MetaData)) }; // 3983069190
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UImstkController_Statics::NewProp_GraspStiffness_MetaData[] = {
		{ "Category", "General" },
		{ "EditCondition", "bGraspingTool && ToolGeometry == EToolGeometry::SphereTool || ToolGeometry == EToolGeometry::CapsuleTool" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/ImstkController.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UImstkController_Statics::NewProp_GraspStiffness = { "GraspStiffness", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UImstkController, GraspStiffness), METADATA_PARAMS(Z_Construct_UClass_UImstkController_Statics::NewProp_GraspStiffness_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UImstkController_Statics::NewProp_GraspStiffness_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UImstkController_Statics::NewProp_bStitchingTool_MetaData[] = {
		{ "Category", "General" },
		{ "EditCondition", "ToolGeometry == EToolGeometry::LineMeshTool" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/ImstkController.h" },
	};
#endif
	void Z_Construct_UClass_UImstkController_Statics::NewProp_bStitchingTool_SetBit(void* Obj)
	{
		((UImstkController*)Obj)->bStitchingTool = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UImstkController_Statics::NewProp_bStitchingTool = { "bStitchingTool", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UImstkController), &Z_Construct_UClass_UImstkController_Statics::NewProp_bStitchingTool_SetBit, METADATA_PARAMS(Z_Construct_UClass_UImstkController_Statics::NewProp_bStitchingTool_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UImstkController_Statics::NewProp_bStitchingTool_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UImstkController_Statics::NewProp_Vertex1_MetaData[] = {
		{ "Category", "General" },
		{ "Comment", "// TODO: Maybe separate into different tool types (stitching tool as a separate class)\n" },
		{ "EditCondition", "ToolGeometry == EToolGeometry::LineMeshTool" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/ImstkController.h" },
		{ "ToolTip", "TODO: Maybe separate into different tool types (stitching tool as a separate class)" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UImstkController_Statics::NewProp_Vertex1 = { "Vertex1", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UImstkController, Vertex1), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UClass_UImstkController_Statics::NewProp_Vertex1_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UImstkController_Statics::NewProp_Vertex1_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UImstkController_Statics::NewProp_Vertex2_MetaData[] = {
		{ "Category", "General" },
		{ "EditCondition", "ToolGeometry == EToolGeometry::LineMeshTool" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/ImstkController.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UImstkController_Statics::NewProp_Vertex2 = { "Vertex2", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UImstkController, Vertex2), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UClass_UImstkController_Statics::NewProp_Vertex2_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UImstkController_Statics::NewProp_Vertex2_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UImstkController_Statics::NewProp_Radius_MetaData[] = {
		{ "Category", "General" },
		{ "ClampMin", "0.01" },
		{ "EditCondition", "ToolGeometry == EToolGeometry::SphereTool || ToolGeometry == EToolGeometry::CapsuleTool" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/ImstkController.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UImstkController_Statics::NewProp_Radius = { "Radius", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UImstkController, Radius), METADATA_PARAMS(Z_Construct_UClass_UImstkController_Statics::NewProp_Radius_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UImstkController_Statics::NewProp_Radius_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UImstkController_Statics::NewProp_Length_MetaData[] = {
		{ "Category", "General" },
		{ "ClampMin", "0.01" },
		{ "EditCondition", "ToolGeometry == EToolGeometry::CapsuleTool" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/ImstkController.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UImstkController_Statics::NewProp_Length = { "Length", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UImstkController, Length), METADATA_PARAMS(Z_Construct_UClass_UImstkController_Statics::NewProp_Length_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UImstkController_Statics::NewProp_Length_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UImstkController_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UImstkController_Statics::NewProp_SubsystemInstance,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UImstkController_Statics::NewProp_ToolGeometry,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UImstkController_Statics::NewProp_bGraspingTool,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UImstkController_Statics::NewProp_GraspType,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UImstkController_Statics::NewProp_GraspStiffness,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UImstkController_Statics::NewProp_bStitchingTool,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UImstkController_Statics::NewProp_Vertex1,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UImstkController_Statics::NewProp_Vertex2,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UImstkController_Statics::NewProp_Radius,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UImstkController_Statics::NewProp_Length,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UImstkController_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UImstkController>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UImstkController_Statics::ClassParams = {
		&UImstkController::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UImstkController_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UImstkController_Statics::PropPointers),
		0,
		0x00B000A5u,
		METADATA_PARAMS(Z_Construct_UClass_UImstkController_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UImstkController_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UImstkController()
	{
		if (!Z_Registration_Info_UClass_UImstkController.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UImstkController.OuterSingleton, Z_Construct_UClass_UImstkController_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UImstkController.OuterSingleton;
	}
	template<> IMSTK_API UClass* StaticClass<UImstkController>()
	{
		return UImstkController::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UImstkController);
	struct Z_CompiledInDeferFile_FID_HostProject_Plugins_Imstk_Source_Imstk_Public_ImstkController_h_Statics
	{
		static const FEnumRegisterCompiledInInfo EnumInfo[];
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FEnumRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_Imstk_Source_Imstk_Public_ImstkController_h_Statics::EnumInfo[] = {
		{ EToolGeometry_StaticEnum, TEXT("EToolGeometry"), &Z_Registration_Info_UEnum_EToolGeometry, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3887863533U) },
		{ EGraspType_StaticEnum, TEXT("EGraspType"), &Z_Registration_Info_UEnum_EGraspType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3983069190U) },
		{ EToolType_StaticEnum, TEXT("EToolType"), &Z_Registration_Info_UEnum_EToolType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3741650383U) },
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_Imstk_Source_Imstk_Public_ImstkController_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UImstkController, UImstkController::StaticClass, TEXT("UImstkController"), &Z_Registration_Info_UClass_UImstkController, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UImstkController), 2753065435U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_Imstk_Source_Imstk_Public_ImstkController_h_1531250391(TEXT("/Script/Imstk"),
		Z_CompiledInDeferFile_FID_HostProject_Plugins_Imstk_Source_Imstk_Public_ImstkController_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HostProject_Plugins_Imstk_Source_Imstk_Public_ImstkController_h_Statics::ClassInfo),
		nullptr, 0,
		Z_CompiledInDeferFile_FID_HostProject_Plugins_Imstk_Source_Imstk_Public_ImstkController_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HostProject_Plugins_Imstk_Source_Imstk_Public_ImstkController_h_Statics::EnumInfo));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
