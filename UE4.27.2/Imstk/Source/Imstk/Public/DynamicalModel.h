// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ImstkBehaviour.h"
#include "GeometryFilter.h"
#include "ImstkSubsystem.h"
#include "iMSTK-5.0/imstkCollidingObject.h"
#include "DynamicalModel.generated.h"

/** \file DynamicalModel.h
 *  \brief Abstract class to model any object that is added to the Imstk scene
 *  \details Contains a geometry filter to convert between Unreal and Imstk objects
 */
UCLASS(Abstract)
class IMSTK_API UDynamicalModel : public UImstkBehaviour
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, Category = "General|Geometry")
		FGeometryFilter GeomFilter;

	/** Creates and returns the geometry of the model
	* @return std::shared_ptr<imstk::Geometry> - The colliding geometry created by the Geometry filter
	*/
	virtual std::shared_ptr<imstk::Geometry> GetCollidingGeometry();

	// The colliding object created and assigned in child classes
	std::shared_ptr<imstk::CollidingObject> ImstkCollidingObject;

	virtual void InitializeComponent() override;


protected:
	// References to the owning object and imstk subsystem
	UPROPERTY()
		AActor* Owner;
	UPROPERTY()
		UImstkSubsystem* SubsystemInstance;
	// Cached geometry for when GetCollidingGeometry is called
	std::shared_ptr<imstk::Geometry> Geometry;
	//bool bIsGeomCreated = false;

	// Maybe add this to a geometry util class
	/** Converts the static mesh attached to the model into a procedural mesh
	* @param StaticMesh - Pointer to the static mesh that will be converted to procedural
	* @param ProcMesh - Pointer to the created procedural mesh
	* @return None
	*/
	void ConvertStaticToProceduralMesh(UStaticMeshComponent* StaticMesh, UProceduralMeshComponent* ProcMesh);

public:
	virtual void UnInit() override;
	UPROPERTY(EditAnywhere, Category = "General")
		bool bPrintPositionInformation = false;
};
