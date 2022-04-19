// Fill out your copyright notice in the Description page of Project Settings.


#include "ImstkSubsystem.h"

//#include "Tickable.h"
#include "Engine/GameEngine.h"
#include "ImstkSettings.h"
#include "DeformableModel.h"
#include "MathUtil.h"

//#include "iMSTK-5.0/imstkSphere.h"
//#include "iMSTK-5.0/imstkPlane.h"

//#include "iMSTK-5.0/imstkRigidObject2.h"
//#include "iMSTK-5.0/imstkPbdObject.h"
//#include "iMSTK-5.0/imstkPbdModel.h"

//#include "iMSTK-5.0/imstkSceneObject.h"

#include "iMSTK-5.0/imstkSimulationManager.h"
//#include "iMSTK-5.0/imstkDynamicObject.h"
#include "iMSTK-5.0/imstkLogger.h"
#include "iMSTK-5.0/imstkTaskGraph.h"
#include "iMSTK-5.0/imstkPbdModel.h"

// For testing purposes
#include "iMSTK-5.0/imstkNew.h"
#include "iMSTK-5.0/imstkSurfaceMesh.h"


void FImstkSubsystemTickFunction::ExecuteTick(float DeltaTime, enum ELevelTick TickType, ENamedThreads::Type CurrentThread, const FGraphEventRef& MyCompletionGraphEvent) 
{
	// Actions that occur when subsystem ticks
	check(Owner);
	if (!Owner->IsSimulationPaused() && Owner->IsSubsystemInitialized())
		Owner->UpdateSimulation(DeltaTime);
}



UImstkSubsystem::UImstkSubsystem() 
{
	bIsCreateOnRunning = GIsRunning;
}

void UImstkSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	TickFunction.bCanEverTick = true;
	TickFunction.Owner = this;
	TickFunction.RegisterTickFunction(GetWorld()->GetCurrentLevel());
}


void UImstkSubsystem::ImstkInit() 
{
	SceneManager = std::make_shared<imstk::SceneManager>();
	ActiveScene = std::make_shared<imstk::Scene>("Active Scene");
	RigidBodyModel = std::make_shared<imstk::RigidBodyModel2>();
	// TODO: task graph file path can not be accessed from the scene itself (unless theres some way i dont know about) so it will be in the engine files for unreal
	ActiveScene->getConfig()->writeTaskGraph = UImstkSettings::IsWritingTaskGraph();

	// Set up rigid body model using variables set in editor
	RigidBodyModel->getConfig()->m_gravity = UMathUtil::ToImstkVec3(Gravity);
	RigidBodyModel->getConfig()->m_maxNumIterations = RigidBodyMaxIterations;
	RigidBodyModel->getConfig()->m_dt = 0.01;

	if (UImstkSettings::IsLoggerActive()) {
		//imstk::Logger::startLogger();
		imstk::Logger::getInstance().addFileSink("simulation", std::string(TCHAR_TO_UTF8(*FPaths::ProjectLogDir())));
	}

	
	// Initialize behaviours (models, etc) and interactions after (collisions)
	if (Controller)
		Controller->InitController();
	for (UImstkBehaviour* Behaviour : AllBehaviours)
	{
		Behaviour->Init();
		UDeformableModel* DModel = Cast<UDeformableModel>(Behaviour);
		if (DModel)
			DeformableModels.Add(DModel);
	}
	for (UImstkInteraction* Interaction : AllInteractions)
	{
		Interaction->Init();
	}
	

	bIsInitialized = true;
	if (UImstkSettings::IsDebugging()) {
		if (GEngine) {
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Subsystem Initialized"));
			/*
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, TEXT("Objects in Imstk scene: "));
			std::unordered_set<std::shared_ptr<imstk::SceneObject>> objects = ActiveScene->getSceneObjects();

			for (auto obj : objects) {
				GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, FString(obj->getName().c_str()) + " ");
			}*/
		}
	}

	// Set up scene manager
	SceneManager->setActiveScene(ActiveScene);

	SceneManager->init();
	SceneManager->pause();
}

void UImstkSubsystem::UpdateSimulation(float DeltaTime) 
{
	// Set the delta time for the rigid body model and pbd models and progress the scene by that amount using the Unreal time since last update
	if (UImstkSettings::IsUseRealtime()) {
		for (UDeformableModel* Model : DeformableModels) {
			Model->PbdObject->getPbdModel()->setTimeStep(DeltaTime);
		}
	}
	RigidBodyModel->getConfig()->m_dt = DeltaTime;
	SceneManager->getActiveScene()->advance(DeltaTime);
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
	if (Controller)
		Controller->UnInit();
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


void UImstkSubsystem::ImstkTest()
{
	imstk::Logger::getInstance().addFileSink("simulation", std::string(TCHAR_TO_UTF8(*FPaths::ProjectLogDir())));
	imstk::imstkNew<imstk::SurfaceMesh> clothMesh;

	imstk::imstkNew<imstk::VecDataArray<double, 3>> verticesPtr(16 * 16);
	imstk::VecDataArray<double, 3>& vertices = *verticesPtr.get();
	const double                      dy = 10 / (16 - 1);
	const double                      dx = 10 / (16 - 1);
	for (int i = 0; i < 16; ++i)
	{
		for (int j = 0; j < 16; j++)
		{
			vertices[i * 16 + j] = imstk::Vec3d(dx * static_cast<double>(i), 1.0, dy * static_cast<double>(j));
		}
	}

	// Add connectivity data
	imstk::imstkNew<imstk::VecDataArray<int, 3>> indicesPtr;
	imstk::VecDataArray<int, 3>& indices = *indicesPtr.get();
	for (int i = 0; i < 16 - 1; i++)
	{
		for (int j = 0; j < 16 - 1; j++)
		{
			const int index1 = i * 16 + j;
			const int index2 = index1 + 16;
			const int index3 = index1 + 1;
			const int index4 = index2 + 1;

			// Interleave [/][\]
			if (i % 2 ^ j % 2)
			{
				indices.push_back(imstk::Vec3i(index1, index2, index3));
				indices.push_back(imstk::Vec3i(index4, index3, index2));
			}
			else
			{
				indices.push_back(imstk::Vec3i(index2, index4, index1));
				indices.push_back(imstk::Vec3i(index4, index3, index1));
			}
		}
	}

	imstk::imstkNew<imstk::VecDataArray<float, 2>> uvCoordsPtr(16 * 16);
	imstk::VecDataArray<float, 2>& uvCoords = *uvCoordsPtr.get();
	for (int i = 0; i < 16; ++i)
	{
		for (int j = 0; j < 16; j++)
		{
			uvCoords[i * 16 + j] = imstk::Vec2f(static_cast<float>(i) / 16, static_cast<float>(j) / 16) * 2;
		}
	}

	clothMesh->initialize(verticesPtr, indicesPtr);
	clothMesh->setVertexTCoords("uvs", uvCoordsPtr);
	LOG(WARNING) << "Vertex: " << clothMesh->getVertexPositions().use_count();
	LOG(WARNING) << "Indices: " << clothMesh->getTriangleIndices().use_count();
	LOG(WARNING) << "UVs: " << clothMesh->getVertexTCoords().use_count();
	LOG(WARNING) << clothMesh->getTriangleIndices()->size();
}

bool UImstkSubsystem::IsSubsystemInitialized() {
	return bIsInitialized;
}