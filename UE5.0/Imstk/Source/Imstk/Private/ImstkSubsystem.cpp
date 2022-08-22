// Fill out your copyright notice in the Description page of Project Settings.

#include "ImstkSubsystem.h"

#include "Engine/GameEngine.h"
#include "ImstkSettings.h"
#include "DeformableModel.h"
#include "MathUtil.h"
#include "imstkSimulationManager.h"
#include "imstkLogger.h"
#include "imstkTaskGraph.h"
#include "imstkTaskGraphVizWriter.h"
#include "imstkPbdModel.h"
#include "ImstkController.h"

//void FImstkSubsystemTickFunction::ExecuteTick(float DeltaTime, enum ELevelTick TickType, ENamedThreads::Type CurrentThread, const FGraphEventRef& MyCompletionGraphEvent)
//{
//	// Actions that occur when subsystem ticks
//	check(Owner);
//	if (!Owner->IsSimulationPaused() && Owner->IsSubsystemInitialized())
//		Owner->UpdateSimulation(DeltaTime);
//}



UImstkSubsystem::UImstkSubsystem()
{
	bIsCreateOnRunning = GIsRunning;
}

void UImstkSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	//TickFunction.bCanEverTick = true;
	//TickFunction.Owner = this;
	//TickFunction.TickInterval = TickInterval;
	//TickFunction.RegisterTickFunction(GetWorld()->GetCurrentLevel());
}


void UImstkSubsystem::ImstkInit()
{
	UMathUtil::SetScale(SceneScale);

	SceneManager = std::make_shared<imstk::SceneManager>();
	ActiveScene = std::make_shared<imstk::Scene>("Active Scene");
	RigidBodyModel = std::make_shared<imstk::RigidBodyModel2>();

	// Set up rigid body model using variables set in editor
	RigidBodyModel->getConfig()->m_gravity = UMathUtil::ToImstkVec3(Gravity, true);
	RigidBodyModel->getConfig()->m_maxNumIterations = RigidBodyMaxIterations;
	RigidBodyModel->getConfig()->m_dt = TickInterval;

	if (UImstkSettings::IsLoggerActive()) {
		imstk::Logger::getInstance().addFileSink("simulation", std::string(TCHAR_TO_UTF8(*FPaths::ProjectLogDir())));
	}

	// Initialize behaviours (models, etc) and interactions (collisions) after
	for (UImstkBehaviour* Behaviour : AllBehaviours)
	{
		Behaviour->Init();
		UDeformableModel* DModel = Cast<UDeformableModel>(Behaviour);
		if (DModel)
			DeformableModels.Add(DModel);
	}
	// Init controllers after behaviours as some rely on behaviours to be initialized
	for (UImstkController* Controller : AllControllers)
	{
		Controller->InitController();
	}
	for (UImstkInteraction* Interaction : AllInteractions)
	{
		Interaction->Init();
	}


	bIsInitialized = true;
	if (UImstkSettings::IsDebugging()) 
		if (GEngine) 
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Subsystem Initialized"));

	// Set up scene manager
	SceneManager->setActiveScene(ActiveScene);

	SceneManager->init();

	// Generates a task graph in the log directory
	if (UImstkSettings::IsWritingTaskGraph()) {
		imstk::TaskGraphVizWriter writer;
		writer.setInput(ActiveScene->getTaskGraph());
		writer.setFileName(std::string(TCHAR_TO_UTF8(*FPaths::ProjectLogDir())) + "/sceneTaskGraph.svg");
		writer.write();
	}
}

void UImstkSubsystem::UpdateSimulation(float DeltaTime)
{
	if (!bIsPaused && bIsInitialized) {
		// Set the delta time for the rigid body model and pbd models and progress the scene by that amount using the Unreal time since last update
		if (UImstkSettings::IsUseRealtime()) {
			for (UDeformableModel* Model : DeformableModels) {
				Model->PbdObject->getPbdModel()->setTimeStep(DeltaTime);
			}
			RigidBodyModel->getConfig()->m_dt = DeltaTime;
			SceneManager->getActiveScene()->advance(DeltaTime);
		}
		// TODO: may need a reference to each RBM since when they are assigned to the objects I think they copy the RBM
		else {
			SceneManager->getActiveScene()->advance(TickInterval);
		}
	}
}

void UImstkSubsystem::ToggleSimulation()
{
	bIsPaused = !bIsPaused;
}

bool UImstkSubsystem::IsSimulationPaused()
{
	return bIsPaused;
}

void UImstkSubsystem::Deinitialize()
{
	for (UImstkController* Controller : AllControllers)
	{
		Controller->UnInit();
	}
	for (UImstkInteraction* Interaction : AllInteractions) {
		Interaction->UnInit();
	}
	for (UImstkBehaviour* Behaviour : AllBehaviours) {
		Behaviour->UnInit();
	}
	AllInteractions.Empty();
	AllBehaviours.Empty();

	if (bIsInitialized) {
		SceneManager->uninit();
		imstk::Logger::getInstance().destroy();
	}

	SceneManager.reset();
	RigidBodyModel.reset();
	ActiveScene.reset();
}

bool UImstkSubsystem::IsSubsystemInitialized() {
	return bIsInitialized;
}