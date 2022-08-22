// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Imstk/Public/RBDModel.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeRBDModel() {}
// Cross Module References
	IMSTK_API UClass* Z_Construct_UClass_URBDModel_NoRegister();
	IMSTK_API UClass* Z_Construct_UClass_URBDModel();
	IMSTK_API UClass* Z_Construct_UClass_UDynamicalModel();
	UPackage* Z_Construct_UPackage__Script_Imstk();
// End Cross Module References
	void URBDModel::StaticRegisterNativesURBDModel()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(URBDModel);
	UClass* Z_Construct_UClass_URBDModel_NoRegister()
	{
		return URBDModel::StaticClass();
	}
	struct Z_Construct_UClass_URBDModel_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Mass_MetaData[];
#endif
		static const UECodeGen_Private::FDoublePropertyParams NewProp_Mass;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_URBDModel_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UDynamicalModel,
		(UObject* (*)())Z_Construct_UPackage__Script_Imstk,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_URBDModel_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Imstk" },
		{ "Comment", "/** \\file RBDModel.h\n *  \\brief Rigid body model to attach to an actor in Unreal to mark as an object to add into Imstk simulation\n *  \\details Has variables available in editor and blueprint to set the default values of the object in Imstk. Updates position and rotation of the Unreal model to match the Imstk simulation.\n */" },
		{ "IncludePath", "RBDModel.h" },
		{ "ModuleRelativePath", "Public/RBDModel.h" },
		{ "ToolTip", "\\file RBDModel.h\n\\brief Rigid body model to attach to an actor in Unreal to mark as an object to add into Imstk simulation\n\\details Has variables available in editor and blueprint to set the default values of the object in Imstk. Updates position and rotation of the Unreal model to match the Imstk simulation." },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_URBDModel_Statics::NewProp_Mass_MetaData[] = {
		{ "Category", "General" },
		{ "Comment", "// Mass of the rigid object set in editor\n" },
		{ "ModuleRelativePath", "Public/RBDModel.h" },
		{ "ToolTip", "Mass of the rigid object set in editor" },
	};
#endif
	const UECodeGen_Private::FDoublePropertyParams Z_Construct_UClass_URBDModel_Statics::NewProp_Mass = { "Mass", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Double, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(URBDModel, Mass), METADATA_PARAMS(Z_Construct_UClass_URBDModel_Statics::NewProp_Mass_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_URBDModel_Statics::NewProp_Mass_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_URBDModel_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_URBDModel_Statics::NewProp_Mass,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_URBDModel_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<URBDModel>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_URBDModel_Statics::ClassParams = {
		&URBDModel::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_URBDModel_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_URBDModel_Statics::PropPointers),
		0,
		0x00B000A4u,
		METADATA_PARAMS(Z_Construct_UClass_URBDModel_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_URBDModel_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_URBDModel()
	{
		if (!Z_Registration_Info_UClass_URBDModel.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_URBDModel.OuterSingleton, Z_Construct_UClass_URBDModel_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_URBDModel.OuterSingleton;
	}
	template<> IMSTK_API UClass* StaticClass<URBDModel>()
	{
		return URBDModel::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(URBDModel);
	struct Z_CompiledInDeferFile_FID_HostProject_Plugins_Imstk_Source_Imstk_Public_RBDModel_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_Imstk_Source_Imstk_Public_RBDModel_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_URBDModel, URBDModel::StaticClass, TEXT("URBDModel"), &Z_Registration_Info_UClass_URBDModel, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(URBDModel), 4013918762U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_Imstk_Source_Imstk_Public_RBDModel_h_3545294933(TEXT("/Script/Imstk"),
		Z_CompiledInDeferFile_FID_HostProject_Plugins_Imstk_Source_Imstk_Public_RBDModel_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HostProject_Plugins_Imstk_Source_Imstk_Public_RBDModel_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
