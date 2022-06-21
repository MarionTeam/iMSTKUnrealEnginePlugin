// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef IMSTK_CollisionInteraction_generated_h
#error "CollisionInteraction.generated.h already included, missing '#pragma once' in CollisionInteraction.h"
#endif
#define IMSTK_CollisionInteraction_generated_h

#define FID_HostProject_Plugins_Imstk_Source_Imstk_Public_CollisionInteraction_h_36_SPARSE_DATA
#define FID_HostProject_Plugins_Imstk_Source_Imstk_Public_CollisionInteraction_h_36_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execInit);


#define FID_HostProject_Plugins_Imstk_Source_Imstk_Public_CollisionInteraction_h_36_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execInit);


#define FID_HostProject_Plugins_Imstk_Source_Imstk_Public_CollisionInteraction_h_36_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUCollisionInteraction(); \
	friend struct Z_Construct_UClass_UCollisionInteraction_Statics; \
public: \
	DECLARE_CLASS(UCollisionInteraction, UImstkInteraction, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Imstk"), NO_API) \
	DECLARE_SERIALIZER(UCollisionInteraction)


#define FID_HostProject_Plugins_Imstk_Source_Imstk_Public_CollisionInteraction_h_36_INCLASS \
private: \
	static void StaticRegisterNativesUCollisionInteraction(); \
	friend struct Z_Construct_UClass_UCollisionInteraction_Statics; \
public: \
	DECLARE_CLASS(UCollisionInteraction, UImstkInteraction, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Imstk"), NO_API) \
	DECLARE_SERIALIZER(UCollisionInteraction)


#define FID_HostProject_Plugins_Imstk_Source_Imstk_Public_CollisionInteraction_h_36_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UCollisionInteraction(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UCollisionInteraction) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UCollisionInteraction); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UCollisionInteraction); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UCollisionInteraction(UCollisionInteraction&&); \
	NO_API UCollisionInteraction(const UCollisionInteraction&); \
public:


#define FID_HostProject_Plugins_Imstk_Source_Imstk_Public_CollisionInteraction_h_36_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UCollisionInteraction(UCollisionInteraction&&); \
	NO_API UCollisionInteraction(const UCollisionInteraction&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UCollisionInteraction); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UCollisionInteraction); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UCollisionInteraction)


#define FID_HostProject_Plugins_Imstk_Source_Imstk_Public_CollisionInteraction_h_33_PROLOG
#define FID_HostProject_Plugins_Imstk_Source_Imstk_Public_CollisionInteraction_h_36_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_HostProject_Plugins_Imstk_Source_Imstk_Public_CollisionInteraction_h_36_SPARSE_DATA \
	FID_HostProject_Plugins_Imstk_Source_Imstk_Public_CollisionInteraction_h_36_RPC_WRAPPERS \
	FID_HostProject_Plugins_Imstk_Source_Imstk_Public_CollisionInteraction_h_36_INCLASS \
	FID_HostProject_Plugins_Imstk_Source_Imstk_Public_CollisionInteraction_h_36_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_HostProject_Plugins_Imstk_Source_Imstk_Public_CollisionInteraction_h_36_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_HostProject_Plugins_Imstk_Source_Imstk_Public_CollisionInteraction_h_36_SPARSE_DATA \
	FID_HostProject_Plugins_Imstk_Source_Imstk_Public_CollisionInteraction_h_36_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_HostProject_Plugins_Imstk_Source_Imstk_Public_CollisionInteraction_h_36_INCLASS_NO_PURE_DECLS \
	FID_HostProject_Plugins_Imstk_Source_Imstk_Public_CollisionInteraction_h_36_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> IMSTK_API UClass* StaticClass<class UCollisionInteraction>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_HostProject_Plugins_Imstk_Source_Imstk_Public_CollisionInteraction_h


#define FOREACH_ENUM_ECOLLISIONINTERACTIONTYPE(op) \
	op(Auto) \
	op(ClosedSurfaceMeshToMeshCD) \
	op(SurfaceMeshToSurfaceMeshCD) \
	op(MeshToMeshBruteForceCD) \
	op(SurfaceMeshToSphereCD) \
	op(SurfaceMeshToCapsuleCD) \
	op(SphereToSphereCD) \
	op(PointSetToSphereCD) \
	op(PointSetToCapsuleCD) \
	op(PointSetToOrientedBoxCD) \
	op(PointSetToPlaneCD) \
	op(UnidirectionalPlaneToSphereCD) 
PRAGMA_ENABLE_DEPRECATION_WARNINGS
