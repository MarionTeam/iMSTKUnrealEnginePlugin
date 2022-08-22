// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class USceneComponent;
class UStaticMeshComponent;
class UDynamicalModel;
#ifdef IMSTK_CustomController_generated_h
#error "CustomController.generated.h already included, missing '#pragma once' in CustomController.h"
#endif
#define IMSTK_CustomController_generated_h

#define FID_HostProject_Plugins_Imstk_Source_Imstk_Public_CustomController_h_20_SPARSE_DATA
#define FID_HostProject_Plugins_Imstk_Source_Imstk_Public_CustomController_h_20_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execSetGhostComponents); \
	DECLARE_FUNCTION(execBeginCut); \
	DECLARE_FUNCTION(execBeginStitch); \
	DECLARE_FUNCTION(execEndGrasp); \
	DECLARE_FUNCTION(execBeginRayPointGrasp); \
	DECLARE_FUNCTION(execBeginCellGrasp); \
	DECLARE_FUNCTION(execBeginVertexGrasp); \
	DECLARE_FUNCTION(execMoveControllerToRaycastOnPlane); \
	DECLARE_FUNCTION(execMoveControllerToLocation);


#define FID_HostProject_Plugins_Imstk_Source_Imstk_Public_CustomController_h_20_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execSetGhostComponents); \
	DECLARE_FUNCTION(execBeginCut); \
	DECLARE_FUNCTION(execBeginStitch); \
	DECLARE_FUNCTION(execEndGrasp); \
	DECLARE_FUNCTION(execBeginRayPointGrasp); \
	DECLARE_FUNCTION(execBeginCellGrasp); \
	DECLARE_FUNCTION(execBeginVertexGrasp); \
	DECLARE_FUNCTION(execMoveControllerToRaycastOnPlane); \
	DECLARE_FUNCTION(execMoveControllerToLocation);


#define FID_HostProject_Plugins_Imstk_Source_Imstk_Public_CustomController_h_20_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUCustomController(); \
	friend struct Z_Construct_UClass_UCustomController_Statics; \
public: \
	DECLARE_CLASS(UCustomController, UImstkController, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Imstk"), NO_API) \
	DECLARE_SERIALIZER(UCustomController)


#define FID_HostProject_Plugins_Imstk_Source_Imstk_Public_CustomController_h_20_INCLASS \
private: \
	static void StaticRegisterNativesUCustomController(); \
	friend struct Z_Construct_UClass_UCustomController_Statics; \
public: \
	DECLARE_CLASS(UCustomController, UImstkController, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Imstk"), NO_API) \
	DECLARE_SERIALIZER(UCustomController)


#define FID_HostProject_Plugins_Imstk_Source_Imstk_Public_CustomController_h_20_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UCustomController(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UCustomController) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UCustomController); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UCustomController); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UCustomController(UCustomController&&); \
	NO_API UCustomController(const UCustomController&); \
public:


#define FID_HostProject_Plugins_Imstk_Source_Imstk_Public_CustomController_h_20_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UCustomController() { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UCustomController(UCustomController&&); \
	NO_API UCustomController(const UCustomController&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UCustomController); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UCustomController); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UCustomController)


#define FID_HostProject_Plugins_Imstk_Source_Imstk_Public_CustomController_h_17_PROLOG
#define FID_HostProject_Plugins_Imstk_Source_Imstk_Public_CustomController_h_20_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_HostProject_Plugins_Imstk_Source_Imstk_Public_CustomController_h_20_SPARSE_DATA \
	FID_HostProject_Plugins_Imstk_Source_Imstk_Public_CustomController_h_20_RPC_WRAPPERS \
	FID_HostProject_Plugins_Imstk_Source_Imstk_Public_CustomController_h_20_INCLASS \
	FID_HostProject_Plugins_Imstk_Source_Imstk_Public_CustomController_h_20_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_HostProject_Plugins_Imstk_Source_Imstk_Public_CustomController_h_20_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_HostProject_Plugins_Imstk_Source_Imstk_Public_CustomController_h_20_SPARSE_DATA \
	FID_HostProject_Plugins_Imstk_Source_Imstk_Public_CustomController_h_20_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_HostProject_Plugins_Imstk_Source_Imstk_Public_CustomController_h_20_INCLASS_NO_PURE_DECLS \
	FID_HostProject_Plugins_Imstk_Source_Imstk_Public_CustomController_h_20_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> IMSTK_API UClass* StaticClass<class UCustomController>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_HostProject_Plugins_Imstk_Source_Imstk_Public_CustomController_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
