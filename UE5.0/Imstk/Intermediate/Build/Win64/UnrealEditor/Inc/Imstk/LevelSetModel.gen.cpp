// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Imstk/Public/LevelSetModel.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeLevelSetModel() {}
// Cross Module References
	IMSTK_API UClass* Z_Construct_UClass_ULevelSetModel_NoRegister();
	IMSTK_API UClass* Z_Construct_UClass_ULevelSetModel();
	IMSTK_API UClass* Z_Construct_UClass_UDynamicalModel();
	UPackage* Z_Construct_UPackage__Script_Imstk();
	IMSTK_API UScriptStruct* Z_Construct_UScriptStruct_FMeshDataStruct();
	IMSTK_API UClass* Z_Construct_UClass_UImageDataAsset_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UMaterial_NoRegister();
	PROCEDURALMESHCOMPONENT_API UClass* Z_Construct_UClass_UProceduralMeshComponent_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(ULevelSetModel::execGenerateSurfaceMeshData)
	{
		P_GET_UBOOL(Z_Param_FlipNormals);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FMeshDataStruct*)Z_Param__Result=P_THIS->GenerateSurfaceMeshData(Z_Param_FlipNormals);
		P_NATIVE_END;
	}
	void ULevelSetModel::StaticRegisterNativesULevelSetModel()
	{
		UClass* Class = ULevelSetModel::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GenerateSurfaceMeshData", &ULevelSetModel::execGenerateSurfaceMeshData },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ULevelSetModel_GenerateSurfaceMeshData_Statics
	{
		struct LevelSetModel_eventGenerateSurfaceMeshData_Parms
		{
			bool FlipNormals;
			FMeshDataStruct ReturnValue;
		};
		static void NewProp_FlipNormals_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_FlipNormals;
		static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_ULevelSetModel_GenerateSurfaceMeshData_Statics::NewProp_FlipNormals_SetBit(void* Obj)
	{
		((LevelSetModel_eventGenerateSurfaceMeshData_Parms*)Obj)->FlipNormals = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ULevelSetModel_GenerateSurfaceMeshData_Statics::NewProp_FlipNormals = { "FlipNormals", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(LevelSetModel_eventGenerateSurfaceMeshData_Parms), &Z_Construct_UFunction_ULevelSetModel_GenerateSurfaceMeshData_Statics::NewProp_FlipNormals_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ULevelSetModel_GenerateSurfaceMeshData_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(LevelSetModel_eventGenerateSurfaceMeshData_Parms, ReturnValue), Z_Construct_UScriptStruct_FMeshDataStruct, METADATA_PARAMS(nullptr, 0) }; // 3288538142
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULevelSetModel_GenerateSurfaceMeshData_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULevelSetModel_GenerateSurfaceMeshData_Statics::NewProp_FlipNormals,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULevelSetModel_GenerateSurfaceMeshData_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULevelSetModel_GenerateSurfaceMeshData_Statics::Function_MetaDataParams[] = {
		{ "Category", "iMSTKTEST" },
		{ "Comment", "/** Generates the data for the surface mesh. Can be called in the blueprint to obtain vertices, indices and normals for the mesh\n\x09* @return the MeshDataStruct containing information regarding the surface mesh of the levelset\n\x09*/" },
		{ "CPP_Default_FlipNormals", "false" },
		{ "ModuleRelativePath", "Public/LevelSetModel.h" },
		{ "ToolTip", "Generates the data for the surface mesh. Can be called in the blueprint to obtain vertices, indices and normals for the mesh\n@return the MeshDataStruct containing information regarding the surface mesh of the levelset" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ULevelSetModel_GenerateSurfaceMeshData_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ULevelSetModel, nullptr, "GenerateSurfaceMeshData", nullptr, nullptr, sizeof(Z_Construct_UFunction_ULevelSetModel_GenerateSurfaceMeshData_Statics::LevelSetModel_eventGenerateSurfaceMeshData_Parms), Z_Construct_UFunction_ULevelSetModel_GenerateSurfaceMeshData_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ULevelSetModel_GenerateSurfaceMeshData_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ULevelSetModel_GenerateSurfaceMeshData_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ULevelSetModel_GenerateSurfaceMeshData_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ULevelSetModel_GenerateSurfaceMeshData()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ULevelSetModel_GenerateSurfaceMeshData_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ULevelSetModel);
	UClass* Z_Construct_UClass_ULevelSetModel_NoRegister()
	{
		return ULevelSetModel::StaticClass();
	}
	struct Z_Construct_UClass_ULevelSetModel_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ImageData_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ImageData;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ImageMaterial_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ImageMaterial;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MeshComp_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_MeshComp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_EditorMeshComp_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_EditorMeshComp;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ULevelSetModel_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UDynamicalModel,
		(UObject* (*)())Z_Construct_UPackage__Script_Imstk,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_ULevelSetModel_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ULevelSetModel_GenerateSurfaceMeshData, "GenerateSurfaceMeshData" }, // 2842463281
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ULevelSetModel_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Imstk" },
		{ "IncludePath", "LevelSetModel.h" },
		{ "ModuleRelativePath", "Public/LevelSetModel.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ULevelSetModel_Statics::NewProp_ImageData_MetaData[] = {
		{ "Category", "General" },
		{ "Comment", "// Image data asset to generate the iMSTK object from\n" },
		{ "ModuleRelativePath", "Public/LevelSetModel.h" },
		{ "ToolTip", "Image data asset to generate the iMSTK object from" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ULevelSetModel_Statics::NewProp_ImageData = { "ImageData", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ULevelSetModel, ImageData), Z_Construct_UClass_UImageDataAsset_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ULevelSetModel_Statics::NewProp_ImageData_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ULevelSetModel_Statics::NewProp_ImageData_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ULevelSetModel_Statics::NewProp_ImageMaterial_MetaData[] = {
		{ "Category", "General" },
		{ "Comment", "// The material to be set on each section of the mesh (TODO)\n" },
		{ "ModuleRelativePath", "Public/LevelSetModel.h" },
		{ "ToolTip", "The material to be set on each section of the mesh (TODO)" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ULevelSetModel_Statics::NewProp_ImageMaterial = { "ImageMaterial", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ULevelSetModel, ImageMaterial), Z_Construct_UClass_UMaterial_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ULevelSetModel_Statics::NewProp_ImageMaterial_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ULevelSetModel_Statics::NewProp_ImageMaterial_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ULevelSetModel_Statics::NewProp_MeshComp_MetaData[] = {
		{ "Comment", "// The mesh component that will be generated to represent the LevelSet during runtime\n" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/LevelSetModel.h" },
		{ "ToolTip", "The mesh component that will be generated to represent the LevelSet during runtime" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ULevelSetModel_Statics::NewProp_MeshComp = { "MeshComp", nullptr, (EPropertyFlags)0x0020080000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ULevelSetModel, MeshComp), Z_Construct_UClass_UProceduralMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ULevelSetModel_Statics::NewProp_MeshComp_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ULevelSetModel_Statics::NewProp_MeshComp_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ULevelSetModel_Statics::NewProp_EditorMeshComp_MetaData[] = {
		{ "Category", "General" },
		{ "Comment", "// The mesh component to represent the LevelSet when using the editor. Will be disabled upon starting the game\n" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/LevelSetModel.h" },
		{ "ToolTip", "The mesh component to represent the LevelSet when using the editor. Will be disabled upon starting the game" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ULevelSetModel_Statics::NewProp_EditorMeshComp = { "EditorMeshComp", nullptr, (EPropertyFlags)0x002008000008000c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ULevelSetModel, EditorMeshComp), Z_Construct_UClass_UProceduralMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ULevelSetModel_Statics::NewProp_EditorMeshComp_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ULevelSetModel_Statics::NewProp_EditorMeshComp_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ULevelSetModel_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULevelSetModel_Statics::NewProp_ImageData,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULevelSetModel_Statics::NewProp_ImageMaterial,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULevelSetModel_Statics::NewProp_MeshComp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULevelSetModel_Statics::NewProp_EditorMeshComp,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ULevelSetModel_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ULevelSetModel>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ULevelSetModel_Statics::ClassParams = {
		&ULevelSetModel::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_ULevelSetModel_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_ULevelSetModel_Statics::PropPointers),
		0,
		0x00B000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ULevelSetModel_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ULevelSetModel_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ULevelSetModel()
	{
		if (!Z_Registration_Info_UClass_ULevelSetModel.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ULevelSetModel.OuterSingleton, Z_Construct_UClass_ULevelSetModel_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ULevelSetModel.OuterSingleton;
	}
	template<> IMSTK_API UClass* StaticClass<ULevelSetModel>()
	{
		return ULevelSetModel::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ULevelSetModel);
	struct Z_CompiledInDeferFile_FID_HostProject_Plugins_Imstk_Source_Imstk_Public_LevelSetModel_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_Imstk_Source_Imstk_Public_LevelSetModel_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ULevelSetModel, ULevelSetModel::StaticClass, TEXT("ULevelSetModel"), &Z_Registration_Info_UClass_ULevelSetModel, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ULevelSetModel), 1420047245U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_Imstk_Source_Imstk_Public_LevelSetModel_h_2388252649(TEXT("/Script/Imstk"),
		Z_CompiledInDeferFile_FID_HostProject_Plugins_Imstk_Source_Imstk_Public_LevelSetModel_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HostProject_Plugins_Imstk_Source_Imstk_Public_LevelSetModel_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
