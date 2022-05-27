// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Imstk/Public/MathUtil.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMathUtil() {}
// Cross Module References
	IMSTK_API UClass* Z_Construct_UClass_UMathUtil_NoRegister();
	IMSTK_API UClass* Z_Construct_UClass_UMathUtil();
	ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
	UPackage* Z_Construct_UPackage__Script_Imstk();
// End Cross Module References
	void UMathUtil::StaticRegisterNativesUMathUtil()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UMathUtil);
	UClass* Z_Construct_UClass_UMathUtil_NoRegister()
	{
		return UMathUtil::StaticClass();
	}
	struct Z_Construct_UClass_UMathUtil_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UMathUtil_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
		(UObject* (*)())Z_Construct_UPackage__Script_Imstk,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMathUtil_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/** \\file MathUtil.h\n *  \\brief Provides static functions that convert between Imstk and Unreal structures\n *  \\details Converts Vectors, Quaternions...\n */" },
		{ "IncludePath", "MathUtil.h" },
		{ "ModuleRelativePath", "Public/MathUtil.h" },
		{ "ToolTip", "\\file MathUtil.h\n\\brief Provides static functions that convert between Imstk and Unreal structures\n\\details Converts Vectors, Quaternions..." },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UMathUtil_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMathUtil>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UMathUtil_Statics::ClassParams = {
		&UMathUtil::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UMathUtil_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UMathUtil_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UMathUtil()
	{
		if (!Z_Registration_Info_UClass_UMathUtil.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UMathUtil.OuterSingleton, Z_Construct_UClass_UMathUtil_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UMathUtil.OuterSingleton;
	}
	template<> IMSTK_API UClass* StaticClass<UMathUtil>()
	{
		return UMathUtil::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UMathUtil);
	struct Z_CompiledInDeferFile_FID_HostProject_Plugins_Imstk_Source_Imstk_Public_MathUtil_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_Imstk_Source_Imstk_Public_MathUtil_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UMathUtil, UMathUtil::StaticClass, TEXT("UMathUtil"), &Z_Registration_Info_UClass_UMathUtil, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UMathUtil), 3310787945U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_Imstk_Source_Imstk_Public_MathUtil_h_18888913(TEXT("/Script/Imstk"),
		Z_CompiledInDeferFile_FID_HostProject_Plugins_Imstk_Source_Imstk_Public_MathUtil_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HostProject_Plugins_Imstk_Source_Imstk_Public_MathUtil_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
