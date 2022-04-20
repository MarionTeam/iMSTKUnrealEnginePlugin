// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ImstkInteraction.h"
#include "DynamicalModel.h"

#include "CollisionInteraction.generated.h"

// Defines the different types of collisions. Values must have the same name as the collision in imstk
UENUM()
enum CollisionInteractionType
{
	Auto,
	SurfaceMeshToSurfaceMeshCD,
	MeshToMeshBruteForceCD,
	SurfaceMeshToSphereCD,
	SphereToSphereCD,
	PointSetToSphereCD,
	PointSetToCapsuleCD,
	PointSetToOrientedBoxCD,
	PointSetToPlaneCD,
	UnidirectionalPlaneToSphereCD
};

/** \file CollisionInteraction.h
 *  \brief Class used to create and represent the collision interaction in imstk
 *  \details Can be created in blueprint to make the imstk collision interaction and initialize using the imstk subsystem. Requires models to be set. Collision type may be left as auto automatically determine the collision type.
 */
UCLASS(BlueprintType)
class IMSTK_API UCollisionInteraction : public UImstkInteraction
{
	GENERATED_BODY()

public:
	//UCollisionInteraction(CollisionInteractionType CollisionType, TSharedPtr<UDynamicalModel> Model1, TSharedPtr<UDynamicalModel> Model2) : CollisionType(CollisionType),  Model1(Model1),  Model2(Model2) { }
	UCollisionInteraction() : Friction(0), Stiffness(0.05), Restitution(0) { }

	UCollisionInteraction(float F, float S, float R) : Friction(F), Stiffness(S), Restitution(R) { }

	// The type of collision used in the interaction
	CollisionInteractionType CollisionType = CollisionInteractionType::Auto;
	
	// The models that the collision interaction will be made between. Can be set in blueprint 
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Collision Interaction")
		UDynamicalModel* Model1;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Collision Interaction")
		UDynamicalModel* Model2;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Collision Interaction")
		float Friction;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Collision Interaction")
		float Stiffness;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Collision Interaction")
		float Restitution;

	/** Initializes the interaction between set models in imstk
	* @return None
	*/
	UFUNCTION(BlueprintCallable, Category = "iMSTKCollision")
		virtual void Init() override;
protected:
	/** Determines the type of collision using the set models
	* @return CollisionInteractionType - The type of collision that was determined. Returns Auto type if collision type could not be found
	*/
	CollisionInteractionType GetAutoCollisionType(std::shared_ptr<imstk::Geometry> Geom1, std::shared_ptr<imstk::Geometry> Geom2);
};
