// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef IMSTK_DeformableModel_generated_h
#error "DeformableModel.generated.h already included, missing '#pragma once' in DeformableModel.h"
#endif
#define IMSTK_DeformableModel_generated_h

#define HostProject_Plugins_Imstk_Source_Imstk_Public_DeformableModel_h_29_SPARSE_DATA
#define HostProject_Plugins_Imstk_Source_Imstk_Public_DeformableModel_h_29_RPC_WRAPPERS
#define HostProject_Plugins_Imstk_Source_Imstk_Public_DeformableModel_h_29_RPC_WRAPPERS_NO_PURE_DECLS
#define HostProject_Plugins_Imstk_Source_Imstk_Public_DeformableModel_h_29_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUDeformableModel(); \
	friend struct Z_Construct_UClass_UDeformableModel_Statics; \
public: \
	DECLARE_CLASS(UDeformableModel, UDynamicalModel, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Config), CASTCLASS_None, TEXT("/Script/Imstk"), NO_API) \
	DECLARE_SERIALIZER(UDeformableModel)


#define HostProject_Plugins_Imstk_Source_Imstk_Public_DeformableModel_h_29_INCLASS \
private: \
	static void StaticRegisterNativesUDeformableModel(); \
	friend struct Z_Construct_UClass_UDeformableModel_Statics; \
public: \
	DECLARE_CLASS(UDeformableModel, UDynamicalModel, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Config), CASTCLASS_None, TEXT("/Script/Imstk"), NO_API) \
	DECLARE_SERIALIZER(UDeformableModel)


#define HostProject_Plugins_Imstk_Source_Imstk_Public_DeformableModel_h_29_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UDeformableModel(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UDeformableModel) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UDeformableModel); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UDeformableModel); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UDeformableModel(UDeformableModel&&); \
	NO_API UDeformableModel(const UDeformableModel&); \
public:


#define HostProject_Plugins_Imstk_Source_Imstk_Public_DeformableModel_h_29_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UDeformableModel() { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UDeformableModel(UDeformableModel&&); \
	NO_API UDeformableModel(const UDeformableModel&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UDeformableModel); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UDeformableModel); \
	DEFINE_ABSTRACT_DEFAULT_CONSTRUCTOR_CALL(UDeformableModel)


#define HostProject_Plugins_Imstk_Source_Imstk_Public_DeformableModel_h_29_PRIVATE_PROPERTY_OFFSET
#define HostProject_Plugins_Imstk_Source_Imstk_Public_DeformableModel_h_26_PROLOG
#define HostProject_Plugins_Imstk_Source_Imstk_Public_DeformableModel_h_29_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	HostProject_Plugins_Imstk_Source_Imstk_Public_DeformableModel_h_29_PRIVATE_PROPERTY_OFFSET \
	HostProject_Plugins_Imstk_Source_Imstk_Public_DeformableModel_h_29_SPARSE_DATA \
	HostProject_Plugins_Imstk_Source_Imstk_Public_DeformableModel_h_29_RPC_WRAPPERS \
	HostProject_Plugins_Imstk_Source_Imstk_Public_DeformableModel_h_29_INCLASS \
	HostProject_Plugins_Imstk_Source_Imstk_Public_DeformableModel_h_29_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define HostProject_Plugins_Imstk_Source_Imstk_Public_DeformableModel_h_29_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	HostProject_Plugins_Imstk_Source_Imstk_Public_DeformableModel_h_29_PRIVATE_PROPERTY_OFFSET \
	HostProject_Plugins_Imstk_Source_Imstk_Public_DeformableModel_h_29_SPARSE_DATA \
	HostProject_Plugins_Imstk_Source_Imstk_Public_DeformableModel_h_29_RPC_WRAPPERS_NO_PURE_DECLS \
	HostProject_Plugins_Imstk_Source_Imstk_Public_DeformableModel_h_29_INCLASS_NO_PURE_DECLS \
	HostProject_Plugins_Imstk_Source_Imstk_Public_DeformableModel_h_29_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> IMSTK_API UClass* StaticClass<class UDeformableModel>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID HostProject_Plugins_Imstk_Source_Imstk_Public_DeformableModel_h


#define FOREACH_ENUM_FEMCONSTRAINTMATERIAL(op) \
	op(Linear) \
	op(Corotation) \
	op(StVK) \
	op(NeoHookean) 
PRAGMA_ENABLE_DEPRECATION_WARNINGS
