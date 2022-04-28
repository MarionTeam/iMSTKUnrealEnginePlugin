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
	IMSTK_API UClass* Z_Construct_UClass_UImstkController_NoRegister();
	IMSTK_API UClass* Z_Construct_UClass_UImstkController();
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
	IMSTK_API UClass* Z_Construct_UClass_UImstkSubsystem_NoRegister();
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
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_Imstk_EToolGeometry_Statics::Enum_MetaDataParams[] = {
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
	void UImstkController::StaticRegisterNativesUImstkController()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UImstkController);
	UClass* Z_Construct_UClass_UImstkController_NoRegister()
	{
		return UImstkController::StaticClass();
	}
	struct Z_Construct_UClass_UImstkController_Statics
	{
		static UObject* (*const DependentSingletons[])();
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
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bStitchingTool_MetaData[];
#endif
		static void NewProp_bStitchingTool_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bStitchingTool;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UImstkController_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UActorComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_Imstk,
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
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UImstkController_Statics::NewProp_ToolGeometry = { "ToolGeometry", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UImstkController, ToolGeometry), Z_Construct_UEnum_Imstk_EToolGeometry, METADATA_PARAMS(Z_Construct_UClass_UImstkController_Statics::NewProp_ToolGeometry_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UImstkController_Statics::NewProp_ToolGeometry_MetaData)) }; // 2510509312
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UImstkController_Statics::NewProp_bGraspingTool_MetaData[] = {
		{ "Category", "General" },
		{ "Comment", "// TODO: If you set as true with a spheretool then change geometry it will be hidden but still set to true\n" },
		{ "EditCondition", "ToolGeometry == EToolGeometry::SphereTool" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/ImstkController.h" },
		{ "ToolTip", "TODO: If you set as true with a spheretool then change geometry it will be hidden but still set to true" },
	};
#endif
	void Z_Construct_UClass_UImstkController_Statics::NewProp_bGraspingTool_SetBit(void* Obj)
	{
		((UImstkController*)Obj)->bGraspingTool = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UImstkController_Statics::NewProp_bGraspingTool = { "bGraspingTool", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UImstkController), &Z_Construct_UClass_UImstkController_Statics::NewProp_bGraspingTool_SetBit, METADATA_PARAMS(Z_Construct_UClass_UImstkController_Statics::NewProp_bGraspingTool_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UImstkController_Statics::NewProp_bGraspingTool_MetaData)) };
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
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UImstkController_Statics::NewProp_bStitchingTool = { "bStitchingTool", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UImstkController), &Z_Construct_UClass_UImstkController_Statics::NewProp_bStitchingTool_SetBit, METADATA_PARAMS(Z_Construct_UClass_UImstkController_Statics::NewProp_bStitchingTool_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UImstkController_Statics::NewProp_bStitchingTool_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UImstkController_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UImstkController_Statics::NewProp_SubsystemInstance,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UImstkController_Statics::NewProp_ToolGeometry,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UImstkController_Statics::NewProp_bGraspingTool,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UImstkController_Statics::NewProp_bStitchingTool,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UImstkController_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UImstkController>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UImstkController_Statics::ClassParams = {
		&UImstkController::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UImstkController_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
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
		{ EToolGeometry_StaticEnum, TEXT("EToolGeometry"), &Z_Registration_Info_UEnum_EToolGeometry, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2510509312U) },
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_Imstk_Source_Imstk_Public_ImstkController_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UImstkController, UImstkController::StaticClass, TEXT("UImstkController"), &Z_Registration_Info_UClass_UImstkController, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UImstkController), 612482653U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_Imstk_Source_Imstk_Public_ImstkController_h_2537621526(TEXT("/Script/Imstk"),
		Z_CompiledInDeferFile_FID_HostProject_Plugins_Imstk_Source_Imstk_Public_ImstkController_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HostProject_Plugins_Imstk_Source_Imstk_Public_ImstkController_h_Statics::ClassInfo),
		nullptr, 0,
		Z_CompiledInDeferFile_FID_HostProject_Plugins_Imstk_Source_Imstk_Public_ImstkController_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HostProject_Plugins_Imstk_Source_Imstk_Public_ImstkController_h_Statics::EnumInfo));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
