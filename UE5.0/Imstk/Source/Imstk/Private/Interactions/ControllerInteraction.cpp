// Fill out your copyright notice in the Description page of Project Settings.


#include "ControllerInteraction.h"

#include "DeformableModel.h"
#include "RBDModel.h"
#include "StaticModel.h"
#include "SuturingController.h"
#include "Suturing/NeedleInteraction.h"

#include "imstkPBDObjectCollision.h"
#include "imstkRigidObjectCollision.h"
#include "imstkPbdRigidObjectGrasping.h"
#include "imstkPbdObjectGrasping.h"
#include "imstkPbdObjectStitching.h"
#include "imstkLineMesh.h"
#include "ImstkSubsystem.h"
#include "ImstkSettings.h"

#include "LevelSetModel.h"
#include "imstkRigidObjectLevelSetCollision.h"
#include "imstkRigidBodyCH.h"
#include "imstkLevelSetCH.h"

void UControllerInteraction::Init()
{
	if (Model1 == nullptr) {
		UE_LOG(LogTemp, Error, TEXT("%s"), ("Model1 is not assigned in collision interaction"));
		return;
	}
	else if (Controller == nullptr) {
		UE_LOG(LogTemp, Error, TEXT("%s"), ("Controller is not assigned in collision interaction"));
		return;
	}

	if (!Model1->IsInitialized() || !Controller->IsInitialized())
		return;

	UImstkSubsystem* SubsystemInstance = GetWorld()->GetGameInstance()->GetSubsystem<UImstkSubsystem>();

	// Initialize the interaction depending on the controller type
	// TODO: maybe change this to a separate class for each interaction type (or keep like this since there are a limited number of interaction types that will likely be added in iMSTK)
	// Separating would make more modular
	// TODO: maybe make a helper function for generating an error
	USuturingController* SuturCont = Cast<USuturingController>(Controller);
	if (SuturCont) {
		if (Cast<UDeformableModel>(Model1)) {
			auto SutureInteraction = std::make_shared<NeedleInteraction>(std::dynamic_pointer_cast<imstk::PbdObject>(Model1->ImstkCollidingObject), SuturCont->Needle, std::dynamic_pointer_cast<imstk::PbdObject>(SuturCont->Thread->ImstkCollidingObject));
			SubsystemInstance->ActiveScene->addInteraction(SutureInteraction);
			SuturCont->SetNeedleInteraction(SutureInteraction);
			return;
		}
		else {
			UE_LOG(LogTemp, Error, TEXT("Wrong model types, Model1 must be a deformable model. Suturing interaction could not be created between %s and %s."), Model1->ImstkCollidingObject->getName().c_str(), Controller->GetToolObj()->getName().c_str());
			if (GEngine)
				GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "Wrong model types, Model1 must be a deformable model. Suturing interaction could not be created between " + FString(Model1->ImstkCollidingObject->getName().c_str()) + " " + FString(Controller->GetToolObj()->getName().c_str()) + ".");
			return;
		}
	}

	if (Controller->ToolType == EToolType::GraspingTool) {
		if (Cast<UDeformableModel>(Model1)) {
			std::shared_ptr<imstk::PbdObjectGrasping> ToolPicking;
			if (Controller->GraspType == EGraspType::VertexGrasp) {
				ToolPicking = std::make_shared<imstk::PbdRigidObjectGrasping>(std::dynamic_pointer_cast<imstk::PbdObject>(Model1->ImstkCollidingObject), Controller->GetToolObj());
			}
			else if (Controller->GraspType == EGraspType::RayPointGrasp || Controller->GraspType == EGraspType::CellGrasp) {
				ToolPicking = std::make_shared<imstk::PbdObjectGrasping>(std::dynamic_pointer_cast<imstk::PbdObject>(Model1->ImstkCollidingObject));
			}
			ToolPicking->setName("PbdObjectGrasping_" + Model1->ImstkCollidingObject->getName() + "_" + Controller->GetToolObj()->getName());
			ToolPicking->setStiffness(Controller->GraspStiffness);
			SubsystemInstance->ActiveScene->addInteraction(ToolPicking);
			Controller->AddToolPicking(ToolPicking);
			return;
		}
		else {
			UE_LOG(LogTemp, Error, TEXT("Wrong model types, Model1 must be a deformable model. Grasping interaction could not be created between %s and %s."), Model1->ImstkCollidingObject->getName().c_str(), Controller->GetToolObj()->getName().c_str());
			if (GEngine)
				GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "Wrong model types, Model1 must be a deformable model. Grasping interaction could not be created between " + FString(Model1->ImstkCollidingObject->getName().c_str()) + " " + FString(Controller->GetToolObj()->getName().c_str())+".");
			return;
		}
	}

	if (Controller->ToolType == EToolType::StitchingTool) {
		if (Cast<UDeformableModel>(Model1)) {
			std::shared_ptr<imstk::PbdObjectStitching> Stitching = std::make_shared<imstk::PbdObjectStitching>(std::dynamic_pointer_cast<imstk::PbdObject>(Model1->ImstkCollidingObject));
			double Dist = (std::dynamic_pointer_cast<imstk::LineMesh>(Controller->GetToolObj()->getCollidingGeometry())->getVertexPosition(0) - std::dynamic_pointer_cast<imstk::LineMesh>(Controller->GetToolObj()->getCollidingGeometry())->getVertexPosition(1)).norm();
			Stitching->setStitchDistance(Dist);
			SubsystemInstance->ActiveScene->addInteraction(Stitching);
			Controller->AddStitching(Stitching);
			return;
		}
		else {
			UE_LOG(LogTemp, Error, TEXT("Wrong model types, Model1 must be a deformable model. Stitching interaction could not be created between %s and %s."), Model1->ImstkCollidingObject->getName().c_str(), Controller->GetToolObj()->getName().c_str());
			if (GEngine)
				GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "Wrong model types, Model1 must be a deformable model. Stitching interaction could not be created between " + FString(Model1->ImstkCollidingObject->getName().c_str()) + " " + FString(Controller->GetToolObj()->getName().c_str()) + ".");
			return;
		}
	}

	if (Controller->ToolType == EToolType::CuttingTool) {
		if (Cast<UDeformableModel>(Model1)) {
			std::shared_ptr<imstk::PbdObjectCutting> Cutting = std::make_shared<imstk::PbdObjectCutting>(std::dynamic_pointer_cast<imstk::PbdObject>(Model1->ImstkCollidingObject), Controller->GetToolObj());
			//SubsystemInstance->ActiveScene->addInteraction(Cutting);
			Controller->AddCutting(Cutting);
			return;
		}
		else {
			UE_LOG(LogTemp, Error, TEXT("Wrong model types, Model1 must be a deformable model. Cutting interaction could not be created between %s and %s."), Model1->ImstkCollidingObject->getName().c_str(), Controller->GetToolObj()->getName().c_str());
			if (GEngine)
				GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "Wrong model types, Model1 must be a deformable model. Cutting interaction could not be created between " + FString(Model1->ImstkCollidingObject->getName().c_str()) + " " + FString(Controller->GetToolObj()->getName().c_str()) + ".");
			return;
		}
	}

	if (Controller->ToolType == EToolType::LevelSetTool) {
		if (Cast<ULevelSetModel>(Model1)) {
			std::shared_ptr<imstk::RigidObjectLevelSetCollision> interaction = std::make_shared<imstk::RigidObjectLevelSetCollision>(Controller->GetToolObj(), ((ULevelSetModel*)Model1)->LevelSetObj);
			{
				auto colHandlerA = std::dynamic_pointer_cast<imstk::RigidBodyCH>(interaction->getCollisionHandlingA());
				colHandlerA->setUseFriction(false);
				colHandlerA->setBaumgarteStabilization(0.5); // inelastic collision

				auto colHandlerB = std::dynamic_pointer_cast<imstk::LevelSetCH>(interaction->getCollisionHandlingB());
				colHandlerB->setLevelSetVelocityScaling(1);
				colHandlerB->setKernel(3, 1.0);
				//colHandlerB->setLevelSetVelocityScaling(0.0); // Can't push the levelset
				colHandlerB->setUseProportionalVelocity(true);
			}
			std::shared_ptr<imstk::CollisionDetectionAlgorithm> cd = interaction->getCollisionDetection();

			SubsystemInstance->ActiveScene->addInteraction(interaction);
			return;
		}
		else {
			UE_LOG(LogTemp, Error, TEXT("Wrong model types, Model1 must be a LevelSet model. LevelSet interaction could not be created between %s and %s."), Model1->ImstkCollidingObject->getName().c_str(), Controller->GetToolObj()->getName().c_str());
			if (GEngine)
				GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "Wrong model types, Model1 must be a LevelSet model. LevelSet interaction could not be created between " + FString(Model1->ImstkCollidingObject->getName().c_str()) + " " + FString(Controller->GetToolObj()->getName().c_str()) + ".");
			return;
		}
	}

	// Determine the collision type if set to auto
	if (CollisionType == ECollisionInteractionType::Auto)
		CollisionType = GetAutoCollisionType(Controller->GetToolObj()->getCollidingGeometry(), Model1->GetImstkGeometry());

	// If GetAutoCollisionType returns Auto, then collision type was not found. Therefore return
	if (CollisionType == ECollisionInteractionType::Auto)
		return;

	// Create interaction and add to scene
	if (Cast<URBDModel>(Model1) || Cast<UStaticModel>(Model1))
	{
		std::shared_ptr<imstk::RigidObjectCollision> Interaction = std::make_shared<imstk::RigidObjectCollision>(Controller->GetToolObj(), std::dynamic_pointer_cast<imstk::RigidObject2>(Model1->ImstkCollidingObject), std::string(TCHAR_TO_UTF8(*UEnum::GetValueAsString(CollisionType))));
		Interaction->setFriction(Friction);
		Interaction->setBaumgarteStabilization(Stiffness);
		//std::dynamic_pointer_cast<imstk::MeshToMeshBruteForceCD>(Interaction->getCollisionDetection())->setGenerateEdgeEdgeContacts(true);
		SubsystemInstance->ActiveScene->addInteraction(Interaction);
		Controller->AddCollision(Interaction);
	}
	else if (Cast<UDeformableModel>(Model1))
	{
		std::shared_ptr<imstk::PbdObjectCollision> Interaction = std::make_shared<imstk::PbdObjectCollision>(std::dynamic_pointer_cast<imstk::PbdObject>(Model1->ImstkCollidingObject), Controller->GetToolObj(), std::string(TCHAR_TO_UTF8(*UEnum::GetValueAsString(CollisionType))));
		Interaction->setFriction(Friction);
		Interaction->setRestitution(0);
		// TODO: not sure if this is needed (says default is true), but its done in some of the examples
		//std::dynamic_pointer_cast<imstk::MeshToMeshBruteForceCD>(Interaction->getCollisionDetection())->setGenerateEdgeEdgeContacts(true);
		SubsystemInstance->ActiveScene->addInteraction(Interaction);
		Controller->AddCollision(Interaction);
	}
	else {
		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "Initializing interaction between " + FString(Model1->ImstkCollidingObject->getName().c_str()) + " and " + FString(Controller->GetToolObj()->getName().c_str()) + " failed");
		UE_LOG(LogTemp, Error, TEXT("Initializing interaction between %s and %s failed"), Model1->ImstkCollidingObject->getName().c_str(), Controller->GetToolObj()->getName().c_str());
		return;
	}
	if (UImstkSettings::IsDebugging()) {
		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, "Interaction Initialized: " + FString(Model1->ImstkCollidingObject->getName().c_str()) + " " + FString(Controller->GetToolObj()->getName().c_str()));
	}
}