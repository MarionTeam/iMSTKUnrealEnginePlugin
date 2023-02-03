// Fill out your copyright notice in the Description page of Project Settings.


#include "CollisionInteraction.h"

#include "PBDModel.h"
#include "RBDModel.h"
#include "StaticModel.h"
#include "PBDThread.h"
#include "imstkPBDObjectCollision.h"
#include "imstkRigidObjectCollision.h"
#include "imstkPbdCollisionHandling.h"
#include "imstkLineMesh.h"
#include "ImstkSubsystem.h"
#include "ImstkSettings.h"

// Deprecated function for determining the collision type
ECollisionInteractionType UCollisionInteraction::GetAutoCollisionType(std::shared_ptr<imstk::Geometry> Geom1, std::shared_ptr<imstk::Geometry> Geom2)
{
	// Cast both models to determine what types they are and return the corresponding CollisionInteractionType for each combination of imstk geometries 
	if (std::dynamic_pointer_cast<imstk::Sphere>(Geom1) && std::dynamic_pointer_cast<imstk::Sphere>(Geom2)) {
		return ECollisionInteractionType::SphereToSphereCD;
	}
	else if ((std::dynamic_pointer_cast<imstk::Sphere>(Geom1) && std::dynamic_pointer_cast<imstk::Cylinder>(Geom2)) ||
		(std::dynamic_pointer_cast<imstk::Cylinder>(Geom1) && std::dynamic_pointer_cast<imstk::Sphere>(Geom2))) {
		return ECollisionInteractionType::SphereToCylinderCD;
	}
	else if (std::dynamic_pointer_cast<imstk::LineMesh>(Geom1) && std::dynamic_pointer_cast<imstk::LineMesh>(Geom2)) {
		return ECollisionInteractionType::LineMeshToLineMeshCCD;
	}
	else if ((std::dynamic_pointer_cast<imstk::Sphere>(Geom1) && std::dynamic_pointer_cast<imstk::SurfaceMesh>(Geom2)) ||
		(std::dynamic_pointer_cast<imstk::SurfaceMesh>(Geom1) && std::dynamic_pointer_cast<imstk::Sphere>(Geom2))) {
		return ECollisionInteractionType::SurfaceMeshToSphereCD;
	}
	else if ((std::dynamic_pointer_cast<imstk::SurfaceMesh>(Geom1) && std::dynamic_pointer_cast<imstk::Capsule>(Geom2)) ||
		(std::dynamic_pointer_cast<imstk::Capsule>(Geom1) && std::dynamic_pointer_cast<imstk::SurfaceMesh>(Geom2))) {
		return ECollisionInteractionType::SurfaceMeshToCapsuleCD;
	}
	else if ((std::dynamic_pointer_cast<imstk::SurfaceMesh>(Geom1) && std::dynamic_pointer_cast<imstk::SurfaceMesh>(Geom2)) ||
		(std::dynamic_pointer_cast<imstk::PointSet>(Geom1) && std::dynamic_pointer_cast<imstk::SurfaceMesh>(Geom2)) ||
		(std::dynamic_pointer_cast<imstk::SurfaceMesh>(Geom1) && std::dynamic_pointer_cast<imstk::PointSet>(Geom2)) ||
		(std::dynamic_pointer_cast<imstk::SurfaceMesh>(Geom1) && std::dynamic_pointer_cast<imstk::LineMesh>(Geom2)) ||
		(std::dynamic_pointer_cast<imstk::LineMesh>(Geom1) && std::dynamic_pointer_cast<imstk::SurfaceMesh>(Geom2))) {
		return ECollisionInteractionType::ClosedSurfaceMeshToMeshCD;
	}
	else if ((std::dynamic_pointer_cast<imstk::PointSet>(Geom1) && std::dynamic_pointer_cast<imstk::Sphere>(Geom2)) ||
		(std::dynamic_pointer_cast<imstk::Sphere>(Geom1) && std::dynamic_pointer_cast<imstk::PointSet>(Geom2))) {
		return ECollisionInteractionType::PointSetToSphereCD;
	}
	else if ((std::dynamic_pointer_cast<imstk::PointSet>(Geom1) && std::dynamic_pointer_cast<imstk::Capsule>(Geom2)) ||
		(std::dynamic_pointer_cast<imstk::Capsule>(Geom1) && std::dynamic_pointer_cast<imstk::PointSet>(Geom2))) {
		return ECollisionInteractionType::PointSetToCapsuleCD;
	}
	else if ((std::dynamic_pointer_cast<imstk::PointSet>(Geom1) && std::dynamic_pointer_cast<imstk::Cylinder>(Geom2)) ||
		(std::dynamic_pointer_cast<imstk::Cylinder>(Geom1) && std::dynamic_pointer_cast<imstk::PointSet>(Geom2))) {
		return ECollisionInteractionType::PointSetToCylinderCD;
	}
	else if ((std::dynamic_pointer_cast<imstk::OrientedBox>(Geom1) && std::dynamic_pointer_cast<imstk::PointSet>(Geom2)) ||
		(std::dynamic_pointer_cast<imstk::PointSet>(Geom1) && std::dynamic_pointer_cast<imstk::OrientedBox>(Geom2))) {
		return ECollisionInteractionType::PointSetToOrientedBoxCD;
	}
	else if ((std::dynamic_pointer_cast<imstk::Plane>(Geom1) && std::dynamic_pointer_cast<imstk::PointSet>(Geom2)) ||
		(std::dynamic_pointer_cast<imstk::PointSet>(Geom1) && std::dynamic_pointer_cast<imstk::Plane>(Geom2))) {
		return ECollisionInteractionType::PointSetToPlaneCD;
	}
	else if ((std::dynamic_pointer_cast<imstk::Plane>(Geom1) && std::dynamic_pointer_cast<imstk::Sphere>(Geom2)) ||
		(std::dynamic_pointer_cast<imstk::Sphere>(Geom1) && std::dynamic_pointer_cast<imstk::Plane>(Geom2))) {
		return ECollisionInteractionType::UnidirectionalPlaneToSphereCD;
	}
	else {
		// Print an error if there is no type found and return Auto
		if(GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "ERROR: Could not find collision type");
		UE_LOG(LogTemp, Error, TEXT("%s"), "ERROR: Could not find collision type");
	}

	return ECollisionInteractionType::Auto;
}

void UCollisionInteraction::Init()
{
	if (Model1 == nullptr ) {
		GetWorld()->GetGameInstance()->GetSubsystem<UImstkSubsystem>()->LogToUnrealAndImstk("ERROR: Model1 is not assigned in collision interaction", FColor::Red);
		return;
	}
	else if (Model2 == nullptr) {
		GetWorld()->GetGameInstance()->GetSubsystem<UImstkSubsystem>()->LogToUnrealAndImstk("ERROR: Model2 is not assigned in collision interaction", FColor::Red);
		return;
	}

	if (!Model1->IsInitialized() || !Model2->IsInitialized())
		return;

	Interactions.Empty();

	// Create interaction and add to scene
	UImstkSubsystem* SubsystemInstance = GetWorld()->GetGameInstance()->GetSubsystem<UImstkSubsystem>();
	std::shared_ptr<imstk::CollisionInteraction> Interaction;

	if (CollisionType == "") {
		if (Cast<UPBDThread>(Model1) && Cast<UPBDThread>(Model2)) {
			Interaction = std::make_shared<imstk::PbdObjectCollision>(std::dynamic_pointer_cast<imstk::PbdObject>(Model1->ImstkCollidingObject), std::dynamic_pointer_cast<imstk::PbdObject>(Model2->ImstkCollidingObject));
		}
		else if (Cast<URBDModel>(Model1) && Cast<URBDModel>(Model2))
		{
			Interaction = std::make_shared<imstk::RigidObjectCollision>(std::dynamic_pointer_cast<imstk::RigidObject2>(Model1->ImstkCollidingObject), std::dynamic_pointer_cast<imstk::RigidObject2>(Model2->ImstkCollidingObject));
		}
		else if (Cast<URBDModel>(Model1) && Cast<UStaticModel>(Model2))
		{
			Interaction = std::make_shared<imstk::RigidObjectCollision>(std::dynamic_pointer_cast<imstk::RigidObject2>(Model1->ImstkCollidingObject), Model2->ImstkCollidingObject);
		}
		else if (Cast<UStaticModel>(Model1) && Cast<URBDModel>(Model2))
		{
			Interaction = std::make_shared<imstk::RigidObjectCollision>(std::dynamic_pointer_cast<imstk::RigidObject2>(Model2->ImstkCollidingObject), Model1->ImstkCollidingObject);
		}
		else if (Cast<UPBDModel>(Model1) && Cast<UPBDModel>(Model2))
		{
			Interaction = std::make_shared<imstk::PbdObjectCollision>(std::dynamic_pointer_cast<imstk::PbdObject>(Model1->ImstkCollidingObject), std::dynamic_pointer_cast<imstk::PbdObject>(Model2->ImstkCollidingObject));
		}
		else if (Cast<UPBDModel>(Model1) && (Cast<UStaticModel>(Model2) || Cast<URBDModel>(Model2)))
		{
			Interaction = std::make_shared<imstk::PbdObjectCollision>(std::dynamic_pointer_cast<imstk::PbdObject>(Model1->ImstkCollidingObject), Model2->ImstkCollidingObject);
		}
		else if ((Cast<UStaticModel>(Model1) || Cast<URBDModel>(Model1)) && Cast<UDeformableModel>(Model2))
		{
			Interaction = std::make_shared<imstk::PbdObjectCollision>(std::dynamic_pointer_cast<imstk::PbdObject>(Model2->ImstkCollidingObject), Model1->ImstkCollidingObject);
		}
		else {
			Model1->GetWorld()->GetGameInstance()->GetSubsystem<UImstkSubsystem>()->LogToUnrealAndImstk("Creating interaction between " + FString(Model1->ImstkCollidingObject->getName().c_str()) + " and " + FString(Model2->ImstkCollidingObject->getName().c_str()) + " failed", FColor::Red);
			return;
		}
	}
	else {
		if (Cast<UPBDThread>(Model1) && Cast<UPBDThread>(Model2)) {
			Interaction = std::make_shared<imstk::PbdObjectCollision>(std::dynamic_pointer_cast<imstk::PbdObject>(Model1->ImstkCollidingObject), std::dynamic_pointer_cast<imstk::PbdObject>(Model2->ImstkCollidingObject), std::string(TCHAR_TO_UTF8(*CollisionType)));
		}
		else if (Cast<URBDModel>(Model1) && Cast<URBDModel>(Model2))
		{
			Interaction = std::make_shared<imstk::RigidObjectCollision>(std::dynamic_pointer_cast<imstk::RigidObject2>(Model1->ImstkCollidingObject), std::dynamic_pointer_cast<imstk::RigidObject2>(Model2->ImstkCollidingObject), std::string(TCHAR_TO_UTF8(*CollisionType)));
		}
		else if (Cast<URBDModel>(Model1) && Cast<UStaticModel>(Model2))
		{
			Interaction = std::make_shared<imstk::RigidObjectCollision>(std::dynamic_pointer_cast<imstk::RigidObject2>(Model1->ImstkCollidingObject), Model2->ImstkCollidingObject, std::string(TCHAR_TO_UTF8(*CollisionType)));
		}
		else if (Cast<UStaticModel>(Model1) && Cast<URBDModel>(Model2))
		{
			Interaction = std::make_shared<imstk::RigidObjectCollision>(std::dynamic_pointer_cast<imstk::RigidObject2>(Model2->ImstkCollidingObject), Model1->ImstkCollidingObject, std::string(TCHAR_TO_UTF8(*CollisionType)));
		}
		else if (Cast<UPBDModel>(Model1) && Cast<UPBDModel>(Model2))
		{
			Interaction = std::make_shared<imstk::PbdObjectCollision>(std::dynamic_pointer_cast<imstk::PbdObject>(Model1->ImstkCollidingObject), std::dynamic_pointer_cast<imstk::PbdObject>(Model2->ImstkCollidingObject), std::string(TCHAR_TO_UTF8(*CollisionType)));
		}
		else if (Cast<UPBDModel>(Model1) && (Cast<UStaticModel>(Model2) || Cast<URBDModel>(Model2)))
		{
			Interaction = std::make_shared<imstk::PbdObjectCollision>(std::dynamic_pointer_cast<imstk::PbdObject>(Model1->ImstkCollidingObject), Model2->ImstkCollidingObject, std::string(TCHAR_TO_UTF8(*CollisionType)));
		}
		else if ((Cast<UStaticModel>(Model1) || Cast<URBDModel>(Model1)) && Cast<UDeformableModel>(Model2))
		{
			Interaction = std::make_shared<imstk::PbdObjectCollision>(std::dynamic_pointer_cast<imstk::PbdObject>(Model2->ImstkCollidingObject), Model1->ImstkCollidingObject, std::string(TCHAR_TO_UTF8(*CollisionType)));
		}
		else {
			Model1->GetWorld()->GetGameInstance()->GetSubsystem<UImstkSubsystem>()->LogToUnrealAndImstk("Creating interaction between " + FString(Model1->ImstkCollidingObject->getName().c_str()) + " and " + FString(Model2->ImstkCollidingObject->getName().c_str()) + " failed", FColor::Red);
			return;
		}
	}

	// Set parameters of the interaction
	if (std::shared_ptr<imstk::RigidObjectCollision> RBDInteraction = std::dynamic_pointer_cast<imstk::RigidObjectCollision>(Interaction))
	{
		RBDInteraction->setFriction(Friction);
		RBDInteraction->setBaumgarteStabilization(Stiffness);
	}
	else if (std::shared_ptr<imstk::PbdObjectCollision> PBDInteraction = std::dynamic_pointer_cast<imstk::PbdObjectCollision>(Interaction))
	{
		PBDInteraction->setFriction(Friction);
		PBDInteraction->setRestitution(Restitution);
		PBDInteraction->setDeformableStiffnessA(Stiffness);
		PBDInteraction->setDeformableStiffnessB(Stiffness);
		PBDInteraction->setRigidBodyCompliance(RigidBodyCompliance);

		PBDInteraction->setUseCorrectVelocity(bUseCorrectVelocity);
	}

	SubsystemInstance->ActiveScene->addInteraction(Interaction);
	
	Interactions.Add(Interaction);

	if (Interactions.Num() > 0) {
		Model1->AddInteraction(this);
		Model2->AddInteraction(this);
	}
	if (UImstkSettings::IsDebugging()) {
		GetWorld()->GetGameInstance()->GetSubsystem<UImstkSubsystem>()->LogToUnrealAndImstk("Interaction created between " + FString(Model1->ImstkCollidingObject->getName().c_str()) + " and " + Model2->ImstkCollidingObject->getName().c_str(), FColor::Green);
	}
}

void UCollisionInteraction::UnInit() {
	Super::UnInit();
	for (auto Interaction : Interactions)
		Interaction->reset();
	Interactions.Empty();
}