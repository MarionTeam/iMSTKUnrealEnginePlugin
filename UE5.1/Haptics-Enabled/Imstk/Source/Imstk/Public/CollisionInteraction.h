// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ImstkInteraction.h"
#include "DynamicalModel.h"

#include "CollisionInteraction.generated.h"

// Defines the different types of collisions. Values must have the same name as the collision type in imstk
UENUM()
enum ECollisionInteractionType
{
	Auto,
	ClosedSurfaceMeshToMeshCD,
	SurfaceMeshToSurfaceMeshCD,
	MeshToMeshBruteForceCD,
	SurfaceMeshToSphereCD,
	SurfaceMeshToCapsuleCD,
	SphereToSphereCD,
	SphereToCylinderCD,
	PointSetToSphereCD,
	PointSetToCapsuleCD,
	PointSetToCylinderCD,
	PointSetToOrientedBoxCD,
	PointSetToPlaneCD,
	UnidirectionalPlaneToSphereCD,
	LineMeshToLineMeshCCD
};

/** \file CollisionInteraction.h
 *  \brief Class used to create and represent a collision interaction in imstk
 *  \details Can be created in blueprint to make the imstk collision interaction and initialize using the iMSTK subsystem. Requires models to be set. Collision type may be left as auto automatically determine the collision type.
 */
UCLASS(BlueprintType)
class IMSTK_API UCollisionInteraction : public UImstkInteraction
{
	GENERATED_BODY()

public:
	/** Default constructor. Sets values of friction, stiffness and restitution
	* @return None
	*/
	UCollisionInteraction() : Friction(0), Stiffness(0.05), Restitution(0) { }

	/** Constructor to set the friction, stiffness and restitution to supplied values
	* @param F - Friction of the interaction
	* @param S - Stiffness of the interaction
	* @param R - Restitution of the interaction
	* @return None
	*/
	UCollisionInteraction(float F, float S, float R) : Friction(F), Stiffness(S), Restitution(R) { }

	// The type of collision used in the interaction
	//ECollisionInteractionType CollisionType = ECollisionInteractionType::Auto;
	
	// The first model in the interaction that the collision will be made between. Can be set in blueprint. 
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "iMSTK|Collision Interaction")
		UDynamicalModel* Model1;

	// The second model in the interaction that the collision will be made between. Can be set in blueprint. 
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "iMSTK|Collision Interaction")
		UDynamicalModel* Model2;

	// The name of the collision type to be used. Leave blank for automatic selection
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "iMSTK|Collision Interaction")
		FString CollisionType;

	// Friction of the interaction
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "iMSTK|Collision Interaction")
		float Friction;

	// Stiffness of the interaction
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "iMSTK|Collision Interaction")
		float Stiffness;

	// Restitution of the interaction
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "iMSTK|Collision Interaction")
		float Restitution;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "iMSTK|Collision Interaction")
		float RigidBodyCompliance;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "iMSTK|Collision Interaction")
		bool bUseCorrectVelocity = true;

	/** Initializes the interaction within iMSTK between the set models set on the CollisionInteraction
	* @return None
	*/
	UFUNCTION(BlueprintCallable, Category = "iMSTK|Collision Interaction")
		virtual void Init() override;

	virtual void UnInit() override;

	TArray<std::shared_ptr<imstk::SceneObject>> Interactions;

protected:
	/** Determines the type of collision using the models set on the CollisionInteraction
	* @return CollisionInteractionType - The type of collision that was determined. Returns Auto type if collision type could not be found
	*/
	ECollisionInteractionType GetAutoCollisionType(std::shared_ptr<imstk::Geometry> Geom1, std::shared_ptr<imstk::Geometry> Geom2);
};
