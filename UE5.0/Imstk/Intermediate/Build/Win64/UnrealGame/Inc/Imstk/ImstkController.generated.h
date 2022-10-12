// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UStaticMeshComponent;
#ifdef IMSTK_ImstkController_generated_h
#error "ImstkController.generated.h already included, missing '#pragma once' in ImstkController.h"
#endif
#define IMSTK_ImstkController_generated_h

#define FID_HostProject_Plugins_Imstk_Source_Imstk_Public_ImstkController_h_58_SPARSE_DATA
#define FID_HostProject_Plugins_Imstk_Source_Imstk_Public_ImstkController_h_58_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execGetGeomOffset); \
	DECLARE_FUNCTION(execGetGeomScale); \
	DECLARE_FUNCTION(execEnableAllCollisions); \
	DECLARE_FUNCTION(execDisableAllCollisions); \
	DECLARE_FUNCTION(execSetStaticMeshComp); \
	DECLARE_FUNCTION(execIsInitialized);


#define FID_HostProject_Plugins_Imstk_Source_Imstk_Public_ImstkController_h_58_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execGetGeomOffset); \
	DECLARE_FUNCTION(execGetGeomScale); \
	DECLARE_FUNCTION(execEnableAllCollisions); \
	DECLARE_FUNCTION(execDisableAllCollisions); \
	DECLARE_FUNCTION(execSetStaticMeshComp); \
	DECLARE_FUNCTION(execIsInitialized);


#define FID_HostProject_Plugins_Imstk_Source_Imstk_Public_ImstkController_h_58_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUImstkController(); \
	friend struct Z_Construct_UClass_UImstkController_Statics; \
public: \
	DECLARE_CLASS(UImstkController, USceneComponent, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Config), CASTCLASS_None, TEXT("/Script/Imstk"), NO_API) \
	DECLARE_SERIALIZER(UImstkController)


#define FID_HostProject_Plugins_Imstk_Source_Imstk_Public_ImstkController_h_58_INCLASS \
private: \
	static void StaticRegisterNativesUImstkController(); \
	friend struct Z_Construct_UClass_UImstkController_Statics; \
public: \
	DECLARE_CLASS(UImstkController, USceneComponent, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Config), CASTCLASS_None, TEXT("/Script/Imstk"), NO_API) \
	DECLARE_SERIALIZER(UImstkController)


#define FID_HostProject_Plugins_Imstk_Source_Imstk_Public_ImstkController_h_58_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UImstkController(const FObjectInitializer& ObjectInitializer); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UImstkController) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UImstkController); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UImstkController); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UImstkController(UImstkController&&); \
	NO_API UImstkController(const UImstkController&); \
public:


#define FID_HostProject_Plugins_Imstk_Source_Imstk_Public_ImstkController_h_58_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UImstkController(UImstkController&&); \
	NO_API UImstkController(const UImstkController&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UImstkController); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UImstkController); \
	DEFINE_ABSTRACT_DEFAULT_CONSTRUCTOR_CALL(UImstkController)


#define FID_HostProject_Plugins_Imstk_Source_Imstk_Public_ImstkController_h_55_PROLOG
#define FID_HostProject_Plugins_Imstk_Source_Imstk_Public_ImstkController_h_58_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_HostProject_Plugins_Imstk_Source_Imstk_Public_ImstkController_h_58_SPARSE_DATA \
	FID_HostProject_Plugins_Imstk_Source_Imstk_Public_ImstkController_h_58_RPC_WRAPPERS \
	FID_HostProject_Plugins_Imstk_Source_Imstk_Public_ImstkController_h_58_INCLASS \
	FID_HostProject_Plugins_Imstk_Source_Imstk_Public_ImstkController_h_58_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_HostProject_Plugins_Imstk_Source_Imstk_Public_ImstkController_h_58_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_HostProject_Plugins_Imstk_Source_Imstk_Public_ImstkController_h_58_SPARSE_DATA \
	FID_HostProject_Plugins_Imstk_Source_Imstk_Public_ImstkController_h_58_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_HostProject_Plugins_Imstk_Source_Imstk_Public_ImstkController_h_58_INCLASS_NO_PURE_DECLS \
	FID_HostProject_Plugins_Imstk_Source_Imstk_Public_ImstkController_h_58_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> IMSTK_API UClass* StaticClass<class UImstkController>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_HostProject_Plugins_Imstk_Source_Imstk_Public_ImstkController_h


#define FOREACH_ENUM_ETOOLGEOMETRY(op) \
	op(LineMeshTool) \
	op(SphereTool) \
	op(CapsuleTool) \
	op(SurfaceMeshTool) 
#define FOREACH_ENUM_EGRASPTYPE(op) \
	op(RayPointGrasp) \
	op(VertexGrasp) \
	op(CellGrasp) 
#define FOREACH_ENUM_ETOOLTYPE(op) \
	op(GraspingTool) \
	op(StitchingTool) \
	op(CollidingTool) \
	op(CuttingTool) \
	op(LevelSetTool) 
PRAGMA_ENABLE_DEPRECATION_WARNINGS
