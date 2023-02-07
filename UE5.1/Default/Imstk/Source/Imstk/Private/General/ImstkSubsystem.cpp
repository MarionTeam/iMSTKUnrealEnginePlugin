// Fill out your copyright notice in the Description page of Project Settings.

#include "ImstkSubsystem.h"

#include "ImstkSettings.h"
#include "DeformableModel.h"
#include "MathUtil.h"
#include "imstkSimulationManager.h"
#include "imstkLogger.h"
#include "imstkTaskGraph.h"
#include "imstkTaskGraphVizWriter.h"
#include "imstkPbdModel.h"
#include "ImstkController.h"
#include "imstkPbdModelConfig.h"
#include "TimerManager.h"

// Physics Substepping
#include "Windows/PreWindowsApi.h"
#include "Windows/PostWindowsApi.h"
#include "PhysicsEngine/PhysicsSettings.h"
#include "PBDRigidsSolver.h"

#if WITH_EDITOR
#include "TaskGraph.h"
#include "AssetRegistry/AssetRegistryModule.h"
#include "SavePackage.h"
#endif


void FImstkSubsystemAsyncCallback::OnPreSimulate_Internal()
{
	GetConsumerInput_Internal()->SubsystemInstance->UpdateSimulation(GetDeltaTime_Internal());
}

void FImstkSubsystemAsyncCallback::OnContactModification_Internal(Chaos::FCollisionContactModifier& Modifier)
{
}


UImstkSubsystem::UImstkSubsystem()
{
	bIsCreateOnRunning = GIsRunning;
}

void UImstkSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	
}


void UImstkSubsystem::ImstkInit()
{
	if (UImstkSettings::IsUseAsyncPhysics()) {

		UPhysicsSettings* Settings = UPhysicsSettings::Get();
		Settings->bTickPhysicsAsync = true;
		Settings->AsyncFixedTimeStepSize = TickInterval;

	}
	else {
		UPhysicsSettings* Settings = UPhysicsSettings::Get();
		Settings->bTickPhysicsAsync = false;
	}

	UMathUtil::SetScale(SceneScale);

	SceneManager = std::make_shared<imstk::SceneManager>();
	ActiveScene = std::make_shared<imstk::Scene>("Active Scene");
	RigidBodyModel = std::make_shared<imstk::RigidBodyModel2>();

	PbdModel = std::make_shared<imstk::PbdModel>();

	std::shared_ptr<imstk::PbdModelConfig> PbdConfig = std::make_shared<imstk::PbdModelConfig>();
	PbdConfig->m_gravity = UMathUtil::ToImstkVec3d(Gravity, true);
	PbdConfig->m_iterations = PbdModelIterations;
	PbdConfig->m_linearDampingCoeff = LinearDampingCoeff;
	PbdConfig->m_doPartitioning = bDoPartitioning;
	PbdConfig->m_dt = PbdModelDt;
	PbdModel->configure(PbdConfig);

	// Set up rigid body model using variables set in editor
	RigidBodyModel->getConfig()->m_gravity = UMathUtil::ToImstkVec3d(Gravity, true);
	RigidBodyModel->getConfig()->m_maxNumIterations = RigidBodyMaxIterations;
	RigidBodyModel->getConfig()->m_dt = TickInterval;

	if (UImstkSettings::IsLoggerActive()) {
		imstk::Logger::getInstance().addFileSink("simulation", std::string(TCHAR_TO_UTF8(*FPaths::ProjectLogDir())));
	}

	// Initialize behaviours (models, etc) and interactions (collisions) after
	for (UImstkBehaviour* Behaviour : AllBehaviours)
	{
		if (!Behaviour->IsInitialized())
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
	for (UImstkConstraint* Constraints : AllConstraints)
	{
		Constraints->Init();
	}

	bIsInitialized = true;
	if (UImstkSettings::IsDebugging()) {
		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Subsystem Initialized"));
		UE_LOG(LogTemp, Warning, TEXT("Subsystem Initialized"));
	}

	// Set up scene manager
	SceneManager->setActiveScene(ActiveScene);

	SceneManager->init();

	if (UImstkSettings::IsUseAsyncPhysics()) {
		AsyncScene = GetWorld()->GetPhysicsScene();
		OnAsyncScenePreTickHandle = AsyncScene->OnPhysScenePreTick.AddUObject(this, &UImstkSubsystem::AsyncScenePreTick);
		// Cannot set the delta time of the solver directly so it must be run twice to update the timestep
		//((Chaos::FPBDRigidsSolver*)AsyncScene->GetSolver());
		AsyncObject = AsyncScene->GetSolver()->CreateAndRegisterSimCallbackObject_External<FImstkSubsystemAsyncCallback>();
	}


#if WITH_EDITOR
	// Generates a task graph in the log directory
	if (UImstkSettings::IsWritingTaskGraph()) {
		imstk::TaskGraphVizWriter writer;
		writer.setInput(ActiveScene->getTaskGraph());
		writer.setFileName(std::string(TCHAR_TO_UTF8(*FPaths::ProjectLogDir())) + "/sceneTaskGraph.svg");
		writer.write();


		// Create task graph asset or load if it already exists
		FString AssetPath = FPaths::ProjectContentDir();
		FString AssetName = GetWorld()->GetMapName();
		AssetName.RemoveFromStart(GetWorld()->StreamingLevelsPrefix);

		FString FilePath = FString::Printf(TEXT("%s%s%S"), *AssetPath.Append("TaskGraphs/"), *AssetName, ".uasset");
		UTaskGraph* TaskGraph;

		if (!FPaths::FileExists(FilePath)) {
			FString PackagePath = TEXT("/Game/TaskGraphs/") + AssetName;

			UPackage* Package = CreatePackage(*PackagePath);
			TaskGraph = NewObject<UTaskGraph>(Package, UTaskGraph::StaticClass(), *AssetName, EObjectFlags::RF_Public | EObjectFlags::RF_Standalone);

			FAssetRegistryModule::AssetCreated(TaskGraph);
			TaskGraph->MarkPackageDirty();

			UE_LOG(LogClass, Log, TEXT("File created"));
		}
		else {
			FSoftObjectPath AssetReference(TEXT("/Game/TaskGraphs/") + AssetName);
			TaskGraph = Cast<UTaskGraph>(AssetReference.TryLoad());
			UE_LOG(LogClass, Log, TEXT("File already exists"));
		}
		std::shared_ptr<imstk::TaskGraph> Graph = ActiveScene->getTaskGraph();
		TaskGraph->Clear();

		std::unordered_map<std::shared_ptr<imstk::TaskNode>, int> Map;
		auto Nodes = Graph->getNodes();
		int Index = 0;
		for (auto Node : Nodes) {
			FLinearColor Color;
			if (Node->m_isCritical)
				Color = FLinearColor::Red;
			else
				Color = FLinearColor::Blue;


			TaskGraph->Nodes.Add(FTaskGraphNode(Index, FString(Node->m_name.c_str()), Color));
			TaskGraph->Nodes[Index].DisplayDepth = 0;
			Map[Node] = Index;
			if (Node == Graph->getSource()) {
				TaskGraph->SourceIndex = Index;
			}
			else if (Node == Graph->getSink()) {
				TaskGraph->SinkIndex = Index;
			}
			Index++;
		}
		auto Edges = Graph->getAdjList();
		for (auto Edge : Edges) {
			for (auto Node : Edge.second) {
				TaskGraph->Nodes[Map[Edge.first]].ChildNodeIndices.Add(Map[Node]);
				TaskGraph->Nodes[Map[Node]].ParentNodeIndices.Add(Map[Edge.first]);
			}
		}

		// BFS repeated to find visual depths
		bool Dirty = true;
		//Put into layer of highest depth parent +1
		while (Dirty) {
			Dirty = false;
			TArray<bool> Visited;
			Visited.SetNum(TaskGraph->Nodes.Num());

			Visited[TaskGraph->SourceIndex] = true;
			TQueue<int> Queue;
			Queue.Enqueue(TaskGraph->SourceIndex);
			int Level = 0;
			int QueueSize = 1;

			while (!Queue.IsEmpty()) {
				int LevelSize = QueueSize;
				while (LevelSize-- != 0) {
					int CurIndex;
					Queue.Dequeue(CurIndex);
					QueueSize--;

					if (Level > TaskGraph->Nodes[CurIndex].DisplayDepth) {
						TaskGraph->Nodes[CurIndex].DisplayDepth = Level;
						Dirty = true;
					}

					for (int Parent : TaskGraph->Nodes[CurIndex].ParentNodeIndices) {
						if (TaskGraph->Nodes[Parent].DisplayDepth >= TaskGraph->Nodes[CurIndex].DisplayDepth) {
							TaskGraph->Nodes[CurIndex].DisplayDepth = TaskGraph->Nodes[Parent].DisplayDepth + 1;
							Dirty = true;
						}
					}


					for (int Child : TaskGraph->Nodes[CurIndex].ChildNodeIndices) {
						if (!Visited[Child]) {
							Visited[Child] = true;
							Queue.Enqueue(Child);
							QueueSize++;
						}
					}
				}
				Level++;
			}
		}

		TaskGraph->MarkPackageDirty();

		FSavePackageArgs SavePackageArgs = { nullptr, nullptr,  EObjectFlags::RF_Standalone ,0U, false, true, true, FDateTime::MinValue(), GError };

		bool IsSuccessful = UPackage::SavePackage(TaskGraph->GetPackage(), TaskGraph, *FilePath, SavePackageArgs);
	}

#endif
}

void UImstkSubsystem::AsyncScenePreTick(FPhysScene* PhysScene, float DeltaTime) 
{
	FImstkSubsystemAsyncInput* AsyncInput = AsyncObject->GetProducerInputData_External();
	AsyncInput->SubsystemInstance = this;
}

void UImstkSubsystem::UpdateSimulation(float DeltaTime)
{
	if (bIsInitialized) {
		// Set the delta time for the rigid body model and pbd models and progress the scene by that amount using the Unreal time since last update
		if (UImstkSettings::IsUseRealtime()) {
			PbdModel->getConfig()->m_dt = DeltaTime;
			RigidBodyModel->getConfig()->m_dt = DeltaTime;
			SceneManager->getActiveScene()->advance(DeltaTime);
		}

		else if (UImstkSettings::IsUseSubstepping()) {
			TimeRemaining += DeltaTime;
			while (TimeRemaining > TickInterval)
			{
				SceneManager->getActiveScene()->advance(TickInterval);
				TimeRemaining -= TickInterval;
			}
		}
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

void UImstkSubsystem::LogToUnrealAndImstk(FString Message, FColor Color)
{
	if (UImstkSettings::IsDebugging()) {
		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, Color, Message);
		UE_LOG(LogTemp, Warning, TEXT("%s"), *Message);
	}
	LOG(WARNING) << std::string(TCHAR_TO_UTF8(*Message));
}

void UImstkSubsystem::ReInitScene() 
{
	ActiveScene->initialize();
}

void UImstkSubsystem::Deinitialize()
{
	AsyncScene->OnPhysScenePreTick.Remove(OnAsyncScenePreTickHandle);
	if (AsyncObject != nullptr)
	{
		AsyncScene->GetSolver()->UnregisterAndFreeSimCallbackObject_External(AsyncObject);
	}

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
