// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef IMSTK_GeometryFilter_generated_h
#error "GeometryFilter.generated.h already included, missing '#pragma once' in GeometryFilter.h"
#endif
#define IMSTK_GeometryFilter_generated_h

#define HostProject_Plugins_Imstk_Source_Imstk_Public_GeometryFilter_h_371_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FGeometryFilter_Statics; \
	IMSTK_API static class UScriptStruct* StaticStruct();


template<> IMSTK_API UScriptStruct* StaticStruct<struct FGeometryFilter>();

#define HostProject_Plugins_Imstk_Source_Imstk_Public_GeometryFilter_h_340_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FPlaneGeomStruct_Statics; \
	IMSTK_API static class UScriptStruct* StaticStruct(); \
	typedef FGeometryTypeStruct Super;


template<> IMSTK_API UScriptStruct* StaticStruct<struct FPlaneGeomStruct>();

#define HostProject_Plugins_Imstk_Source_Imstk_Public_GeometryFilter_h_310_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FOrientedBoxGeomStruct_Statics; \
	IMSTK_API static class UScriptStruct* StaticStruct(); \
	typedef FGeometryTypeStruct Super;


template<> IMSTK_API UScriptStruct* StaticStruct<struct FOrientedBoxGeomStruct>();

#define HostProject_Plugins_Imstk_Source_Imstk_Public_GeometryFilter_h_250_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FPointSetGeomStruct_Statics; \
	IMSTK_API static class UScriptStruct* StaticStruct(); \
	typedef FGeometryTypeStruct Super;


template<> IMSTK_API UScriptStruct* StaticStruct<struct FPointSetGeomStruct>();

#define HostProject_Plugins_Imstk_Source_Imstk_Public_GeometryFilter_h_218_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FCylinderGeomStruct_Statics; \
	IMSTK_API static class UScriptStruct* StaticStruct(); \
	typedef FGeometryTypeStruct Super;


template<> IMSTK_API UScriptStruct* StaticStruct<struct FCylinderGeomStruct>();

#define HostProject_Plugins_Imstk_Source_Imstk_Public_GeometryFilter_h_186_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FCapsuleGeomStruct_Statics; \
	IMSTK_API static class UScriptStruct* StaticStruct(); \
	typedef FGeometryTypeStruct Super;


template<> IMSTK_API UScriptStruct* StaticStruct<struct FCapsuleGeomStruct>();

#define HostProject_Plugins_Imstk_Source_Imstk_Public_GeometryFilter_h_91_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FSurfaceMeshGeomStruct_Statics; \
	IMSTK_API static class UScriptStruct* StaticStruct(); \
	typedef FGeometryTypeStruct Super;


template<> IMSTK_API UScriptStruct* StaticStruct<struct FSurfaceMeshGeomStruct>();

#define HostProject_Plugins_Imstk_Source_Imstk_Public_GeometryFilter_h_62_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FSphereGeomStruct_Statics; \
	IMSTK_API static class UScriptStruct* StaticStruct(); \
	typedef FGeometryTypeStruct Super;


template<> IMSTK_API UScriptStruct* StaticStruct<struct FSphereGeomStruct>();

#define HostProject_Plugins_Imstk_Source_Imstk_Public_GeometryFilter_h_44_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FGeometryTypeStruct_Statics; \
	IMSTK_API static class UScriptStruct* StaticStruct();


template<> IMSTK_API UScriptStruct* StaticStruct<struct FGeometryTypeStruct>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID HostProject_Plugins_Imstk_Source_Imstk_Public_GeometryFilter_h


#define FOREACH_ENUM_EGEOMETRYTYPE(op) \
	op(Sphere) \
	op(SurfaceMesh) \
	op(Capsule) \
	op(Cylinder) \
	op(PointSet) \
	op(OrientedBox) \
	op(Plane) 
PRAGMA_ENABLE_DEPRECATION_WARNINGS
