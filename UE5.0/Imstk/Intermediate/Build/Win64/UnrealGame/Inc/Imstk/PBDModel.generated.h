// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef IMSTK_PBDModel_generated_h
#error "PBDModel.generated.h already included, missing '#pragma once' in PBDModel.h"
#endif
#define IMSTK_PBDModel_generated_h

#define FID_HostProject_Plugins_Imstk_Source_Imstk_Public_PBDModel_h_26_SPARSE_DATA
#define FID_HostProject_Plugins_Imstk_Source_Imstk_Public_PBDModel_h_26_RPC_WRAPPERS
#define FID_HostProject_Plugins_Imstk_Source_Imstk_Public_PBDModel_h_26_RPC_WRAPPERS_NO_PURE_DECLS
#define FID_HostProject_Plugins_Imstk_Source_Imstk_Public_PBDModel_h_26_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUPBDModel(); \
	friend struct Z_Construct_UClass_UPBDModel_Statics; \
public: \
	DECLARE_CLASS(UPBDModel, UDeformableModel, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Imstk"), NO_API) \
	DECLARE_SERIALIZER(UPBDModel)


#define FID_HostProject_Plugins_Imstk_Source_Imstk_Public_PBDModel_h_26_INCLASS \
private: \
	static void StaticRegisterNativesUPBDModel(); \
	friend struct Z_Construct_UClass_UPBDModel_Statics; \
public: \
	DECLARE_CLASS(UPBDModel, UDeformableModel, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Imstk"), NO_API) \
	DECLARE_SERIALIZER(UPBDModel)


#define FID_HostProject_Plugins_Imstk_Source_Imstk_Public_PBDModel_h_26_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UPBDModel(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UPBDModel) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UPBDModel); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UPBDModel); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UPBDModel(UPBDModel&&); \
	NO_API UPBDModel(const UPBDModel&); \
public:


#define FID_HostProject_Plugins_Imstk_Source_Imstk_Public_PBDModel_h_26_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UPBDModel(UPBDModel&&); \
	NO_API UPBDModel(const UPBDModel&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UPBDModel); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UPBDModel); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UPBDModel)


#define FID_HostProject_Plugins_Imstk_Source_Imstk_Public_PBDModel_h_23_PROLOG
#define FID_HostProject_Plugins_Imstk_Source_Imstk_Public_PBDModel_h_26_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_HostProject_Plugins_Imstk_Source_Imstk_Public_PBDModel_h_26_SPARSE_DATA \
	FID_HostProject_Plugins_Imstk_Source_Imstk_Public_PBDModel_h_26_RPC_WRAPPERS \
	FID_HostProject_Plugins_Imstk_Source_Imstk_Public_PBDModel_h_26_INCLASS \
	FID_HostProject_Plugins_Imstk_Source_Imstk_Public_PBDModel_h_26_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_HostProject_Plugins_Imstk_Source_Imstk_Public_PBDModel_h_26_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_HostProject_Plugins_Imstk_Source_Imstk_Public_PBDModel_h_26_SPARSE_DATA \
	FID_HostProject_Plugins_Imstk_Source_Imstk_Public_PBDModel_h_26_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_HostProject_Plugins_Imstk_Source_Imstk_Public_PBDModel_h_26_INCLASS_NO_PURE_DECLS \
	FID_HostProject_Plugins_Imstk_Source_Imstk_Public_PBDModel_h_26_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> IMSTK_API UClass* StaticClass<class UPBDModel>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_HostProject_Plugins_Imstk_Source_Imstk_Public_PBDModel_h


#define FOREACH_ENUM_EPBDMODELPRESETS(op) \
	op(VolumetricTissuePreset) \
	op(ClothPreset) 
PRAGMA_ENABLE_DEPRECATION_WARNINGS
