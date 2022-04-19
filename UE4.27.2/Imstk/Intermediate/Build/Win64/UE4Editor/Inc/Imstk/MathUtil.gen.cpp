// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Imstk/Public/MathUtil.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
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
	UClass* Z_Construct_UClass_UMathUtil_NoRegister()
	{
		return UMathUtil::StaticClass();
	}
	struct Z_Construct_UClass_UMathUtil_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UMathUtil_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
		(UObject* (*)())Z_Construct_UPackage__Script_Imstk,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMathUtil_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/** \\file MathUtil.h\n *  \\brief Provides static functions that convert between Imstk and Unreal structures\n *  \\details Converts Vectors, Quaternions...\n */" },
		{ "IncludePath", "MathUtil.h" },
		{ "ModuleRelativePath", "Public/MathUtil.h" },
		{ "ToolTip", "\\file MathUtil.h\n\\brief Provides static functions that convert between Imstk and Unreal structures\n\\details Converts Vectors, Quaternions..." },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UMathUtil_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMathUtil>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UMathUtil_Statics::ClassParams = {
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
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UMathUtil_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UMathUtil, 3967155214);
	template<> IMSTK_API UClass* StaticClass<UMathUtil>()
	{
		return UMathUtil::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UMathUtil(Z_Construct_UClass_UMathUtil, &UMathUtil::StaticClass, TEXT("/Script/Imstk"), TEXT("UMathUtil"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UMathUtil);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
