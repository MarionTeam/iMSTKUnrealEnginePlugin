// Fill out your copyright notice in the Description page of Project Settings.


#include "CollisionInteraction.h"

#include "DeformableModel.h"
#include "RBDModel.h"
#include "StaticModel.h"
#include "iMSTK-5.0/imstkPBDObjectCollision.h"
#include "iMSTK-5.0/imstkRigidObjectCollision.h"
#include "iMSTK-5.0/imstkLineMesh.h"
#include "ImstkSubsystem.h"
#include "ImstkSettings.h"
#include "Engine/Engine.h"

CollisionInteractionType UCollisionInteraction::GetAutoCollisionType(std::shared_ptr<imstk::Geometry> Geom1, std::shared_ptr<imstk::Geometry> Geom2)
{
	//std::shared_ptr<imstk::Geometry> Geom1 = Model1->GetCollidingGeometry();
	//std::shared_ptr<imstk::Geometry> Geom2 = Model2->GetCollidingGeometry();

	// Cast both models to determine what types they are and return the corresponding CollisionInteractionType for each combination of imstk geometries 
	if (std::dynamic_pointer_cast<imstk::Sphere>(Geom1) && std::dynamic_pointer_cast<imstk::Sphere>(Geom2)) {
		return CollisionInteractionType::SphereToSphereCD;
	}
	else if ((std::dynamic_pointer_cast<imstk::Sphere>(Geom1) && std::dynamic_pointer_cast<imstk::SurfaceMesh>(Geom2)) ||
		(std::dynamic_pointer_cast<imstk::SurfaceMesh>(Geom1) && std::dynamic_pointer_cast<imstk::Sphere>(Geom2))) {
		return CollisionInteractionType::SurfaceMeshToSphereCD;
	}
	else if ((std::dynamic_pointer_cast<imstk::SurfaceMesh>(Geom1) && std::dynamic_pointer_cast<imstk::SurfaceMesh>(Geom2)) ||
		(std::dynamic_pointer_cast<imstk::PointSet>(Geom1) && std::dynamic_pointer_cast<imstk::SurfaceMesh>(Geom2)) ||
		(std::dynamic_pointer_cast<imstk::SurfaceMesh>(Geom1) && std::dynamic_pointer_cast<imstk::PointSet>(Geom2)) ||
		(std::dynamic_pointer_cast<imstk::SurfaceMesh>(Geom1) && std::dynamic_pointer_cast<imstk::LineMesh>(Geom2)) ||
		(std::dynamic_pointer_cast<imstk::LineMesh>(Geom1) && std::dynamic_pointer_cast<imstk::SurfaceMesh>(Geom2))) {
		return CollisionInteractionType::MeshToMeshBruteForceCD;
	}
	else if ((std::dynamic_pointer_cast<imstk::PointSet>(Geom1) && std::dynamic_pointer_cast<imstk::Sphere>(Geom2)) ||
		(std::dynamic_pointer_cast<imstk::Sphere>(Geom1) && std::dynamic_pointer_cast<imstk::PointSet>(Geom2))) {
		return CollisionInteractionType::PointSetToSphereCD;
	}
	else if ((std::dynamic_pointer_cast<imstk::PointSet>(Geom1) && std::dynamic_pointer_cast<imstk::Capsule>(Geom2)) ||
		(std::dynamic_pointer_cast<imstk::Capsule>(Geom1) && std::dynamic_pointer_cast<imstk::PointSet>(Geom2))) {
		return CollisionInteractionType::PointSetToCapsuleCD;
	}
	else if ((std::dynamic_pointer_cast<imstk::OrientedBox>(Geom1) && std::dynamic_pointer_cast<imstk::PointSet>(Geom2)) ||
		(std::dynamic_pointer_cast<imstk::PointSet>(Geom1) && std::dynamic_pointer_cast<imstk::OrientedBox>(Geom2))) {
		return CollisionInteractionType::PointSetToOrientedBoxCD;
	}
	else if ((std::dynamic_pointer_cast<imstk::Plane>(Geom1) && std::dynamic_pointer_cast<imstk::PointSet>(Geom2)) ||
		(std::dynamic_pointer_cast<imstk::PointSet>(Geom1) && std::dynamic_pointer_cast<imstk::Plane>(Geom2))) {
		return CollisionInteractionType::PointSetToPlaneCD;
	}
	else if ((std::dynamic_pointer_cast<imstk::Plane>(Geom1) && std::dynamic_pointer_cast<imstk::Sphere>(Geom2)) ||
		(std::dynamic_pointer_cast<imstk::Sphere>(Geom1) && std::dynamic_pointer_cast<imstk::Plane>(Geom2))) {
		return CollisionInteractionType::UnidirectionalPlaneToSphereCD;
	}
	else {
		// Print an error if there is no type found and return Auto
		if(GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "ERROR: Could not find collision type");
		UE_LOG(LogTemp, Error, TEXT("%s"), "ERROR: Could not find collision type");
	}

	return CollisionInteractionType::Auto;
}

void UCollisionInteraction::Init()
{
	if (Model1 == nullptr ) {
		UE_LOG(LogTemp, Error, TEXT("%s"), ("ERROR: Model1 is not assigned in collision interaction"));
		return;
	}
	else if (Model2 == nullptr) {
		UE_LOG(LogTemp, Error, TEXT("%s"), ("ERROR: Model2 is not assigned in collision interaction"));
		return;
	}

	// Determine the collision type if set to auto
	if (CollisionType == CollisionInteractionType::Auto)
		CollisionType = GetAutoCollisionType(Model1->GetCollidingGeometry(), Model2->GetCollidingGeometry());

	// If GetAutoCollisionType returns Auto, then collision type was not found. Therefore return
	if (CollisionType == CollisionInteractionType::Auto)
		return;

	// Create interaction and add to scene
	UImstkSubsystem* SubsystemInstance = GetWorld()->GetGameInstance()->GetSubsystem<UImstkSubsystem>();
	std::shared_ptr<imstk::CollisionInteraction> Interaction;
	if (Cast<URBDModel>(Model1) && Cast<URBDModel>(Model2))
	{
		Interaction = std::make_shared<imstk::RigidObjectCollision>(std::dynamic_pointer_cast<imstk::RigidObject2>(Model1->ImstkCollidingObject), std::dynamic_pointer_cast<imstk::RigidObject2>(Model2->ImstkCollidingObject), std::string(TCHAR_TO_UTF8(*UEnum::GetValueAsString(CollisionType))));
	}
	else if (Cast<URBDModel>(Model1) && Cast<UStaticModel>(Model2))
	{
		Interaction = std::make_shared<imstk::RigidObjectCollision>(std::dynamic_pointer_cast<imstk::RigidObject2>(Model1->ImstkCollidingObject), Model2->ImstkCollidingObject, std::string(TCHAR_TO_UTF8(*UEnum::GetValueAsString(CollisionType))));
	}
	else if (Cast<UStaticModel>(Model1) && Cast<URBDModel>(Model2))
	{
		Interaction = std::make_shared<imstk::RigidObjectCollision>(std::dynamic_pointer_cast<imstk::RigidObject2>(Model2->ImstkCollidingObject), Model1->ImstkCollidingObject, std::string(TCHAR_TO_UTF8(*UEnum::GetValueAsString(CollisionType))));
	}
	else if (Cast<UDeformableModel>(Model1) && Cast<UDeformableModel>(Model2))
	{
		Interaction = std::make_shared<imstk::PbdObjectCollision>(std::dynamic_pointer_cast<imstk::PbdObject>(Model1->ImstkCollidingObject), std::dynamic_pointer_cast<imstk::PbdObject>(Model2->ImstkCollidingObject), std::string(TCHAR_TO_UTF8(*UEnum::GetValueAsString(CollisionType))));
	}
	else if (Cast<UDeformableModel>(Model1) && (Cast<UStaticModel>(Model2) || Cast<URBDModel>(Model2)))
	{
		Interaction = std::make_shared<imstk::PbdObjectCollision>(std::dynamic_pointer_cast<imstk::PbdObject>(Model1->ImstkCollidingObject), Model2->ImstkCollidingObject, std::string(TCHAR_TO_UTF8(*UEnum::GetValueAsString(CollisionType))));
	}
	else if ((Cast<UStaticModel>(Model1) || Cast<URBDModel>(Model1)) && Cast<UDeformableModel>(Model2))
	{
		Interaction = std::make_shared<imstk::PbdObjectCollision>(std::dynamic_pointer_cast<imstk::PbdObject>(Model2->ImstkCollidingObject), Model1->ImstkCollidingObject, std::string(TCHAR_TO_UTF8(*UEnum::GetValueAsString(CollisionType))));
	}
	else {
		if (GEngine) 
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "Initializing interaction between " + FString(Model1->ImstkCollidingObject->getName().c_str()) + " and " + FString(Model2->ImstkCollidingObject->getName().c_str()) + " failed");
		UE_LOG(LogTemp, Error, TEXT("Initializing interaction between %s and %s failed"), Model1->ImstkCollidingObject->getName().c_str(), Model2->ImstkCollidingObject->getName().c_str());
		return;
	}

	// Set parameters of the interaction

	if (std::shared_ptr<imstk::RigidObjectCollision> RBDInteraction = std::dynamic_pointer_cast<imstk::RigidObjectCollision>(Interaction))
	{
		RBDInteraction->setFriction(Friction);
		RBDInteraction->setStiffness(Stiffness);
	}
	else if (std::shared_ptr<imstk::PbdObjectCollision> PBDInteraction = std::dynamic_pointer_cast<imstk::PbdObjectCollision>(Interaction))
	{
		PBDInteraction->setFriction(Friction);
		PBDInteraction->setRestitution(Restitution);
	}


	SubsystemInstance->ActiveScene->addInteraction(Interaction);

	if (UImstkSettings::IsDebugging()) {
		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, "Interaction Initialized: " + FString(Model1->ImstkCollidingObject->getName().c_str()) + " " + Model2->ImstkCollidingObject->getName().c_str());
	}
}