// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UPBDThread;
#ifdef IMSTK_SuturingController_generated_h
#error "SuturingController.generated.h already included, missing '#pragma once' in SuturingController.h"
#endif
#define IMSTK_SuturingController_generated_h

#define FID_HostProject_Plugins_Imstk_Source_Imstk_Public_SuturingController_h_24_SPARSE_DATA
#define FID_HostProject_Plugins_Imstk_Source_Imstk_Public_SuturingController_h_24_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execMoveNeedleToLocation); \
	DECLARE_FUNCTION(execStitch); \
	DECLARE_FUNCTION(execSetThread);


#define FID_HostProject_Plugins_Imstk_Source_Imstk_Public_SuturingController_h_24_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execMoveNeedleToLocation); \
	DECLARE_FUNCTION(execStitch); \
	DECLARE_FUNCTION(execSetThread);


#define FID_HostProject_Plugins_Imstk_Source_Imstk_Public_SuturingController_h_24_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUSuturingController(); \
	friend struct Z_Construct_UClass_USuturingController_Statics; \
public: \
	DECLARE_CLASS(USuturingController, UImstkController, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Imstk"), NO_API) \
	DECLARE_SERIALIZER(USuturingController)


#define FID_HostProject_Plugins_Imstk_Source_Imstk_Public_SuturingController_h_24_INCLASS \
private: \
	static void StaticRegisterNativesUSuturingController(); \
	friend struct Z_Construct_UClass_USuturingController_Statics; \
public: \
	DECLARE_CLASS(USuturingController, UImstkController, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Imstk"), NO_API) \
	DECLARE_SERIALIZER(USuturingController)


#define FID_HostProject_Plugins_Imstk_Source_Imstk_Public_SuturingController_h_24_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API USuturingController(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(USuturingController) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, USuturingController); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(USuturingController); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API USuturingController(USuturingController&&); \
	NO_API USuturingController(const USuturingController&); \
public:


#define FID_HostProject_Plugins_Imstk_Source_Imstk_Public_SuturingController_h_24_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API USuturingController() { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API USuturingController(USuturingController&&); \
	NO_API USuturingController(const USuturingController&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, USuturingController); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(USuturingController); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(USuturingController)


#define FID_HostProject_Plugins_Imstk_Source_Imstk_Public_SuturingController_h_21_PROLOG
#define FID_HostProject_Plugins_Imstk_Source_Imstk_Public_SuturingController_h_24_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_HostProject_Plugins_Imstk_Source_Imstk_Public_SuturingController_h_24_SPARSE_DATA \
	FID_HostProject_Plugins_Imstk_Source_Imstk_Public_SuturingController_h_24_RPC_WRAPPERS \
	FID_HostProject_Plugins_Imstk_Source_Imstk_Public_SuturingController_h_24_INCLASS \
	FID_HostProject_Plugins_Imstk_Source_Imstk_Public_SuturingController_h_24_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_HostProject_Plugins_Imstk_Source_Imstk_Public_SuturingController_h_24_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_HostProject_Plugins_Imstk_Source_Imstk_Public_SuturingController_h_24_SPARSE_DATA \
	FID_HostProject_Plugins_Imstk_Source_Imstk_Public_SuturingController_h_24_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_HostProject_Plugins_Imstk_Source_Imstk_Public_SuturingController_h_24_INCLASS_NO_PURE_DECLS \
	FID_HostProject_Plugins_Imstk_Source_Imstk_Public_SuturingController_h_24_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> IMSTK_API UClass* StaticClass<class USuturingController>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_HostProject_Plugins_Imstk_Source_Imstk_Public_SuturingController_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
