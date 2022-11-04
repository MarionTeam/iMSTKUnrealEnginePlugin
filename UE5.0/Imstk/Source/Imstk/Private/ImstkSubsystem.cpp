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
#include "imstkPbdModelConfig.h"



#include "imstkCamera.h"
#include "imstkCapsule.h"
#include "imstkDirectionalLight.h"
#include "imstkGeometryUtilities.h"
#include "imstkKeyboardDeviceClient.h"
#include "imstkKeyboardSceneControl.h"
#include "imstkMouseDeviceClient.h"
#include "imstkMouseSceneControl.h"
#include "imstkObjectControllerGhost.h"
#include "imstkPbdModel.h"
#include "imstkPbdModelConfig.h"
#include "imstkPbdObject.h"
#include "imstkPbdObjectCollision.h"
#include "imstkPbdObjectController.h"
#include "imstkPbdRigidBaryPointToPointConstraint.h"
#include "imstkPbdRigidObjectGrasping.h"
#include "imstkRenderMaterial.h"
#include "imstkScene.h"
#include "imstkSceneManager.h"
#include "imstkSimulationManager.h"
#include "imstkSimulationUtils.h"
#include "imstkVisualModel.h"

#include "imstkVTKViewer.h"

#include "imstkMeshIO.h"
#include "imstkDeviceManager.h"
#include "imstkDeviceManagerFactory.h"
#include "TimerManager.h"

#if WITH_EDITOR
#include "TaskGraph.h"
#include "AssetRegistry/AssetRegistryModule.h"
#include "SavePackage.h"
#endif



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

	PbdModel = std::make_shared<imstk::PbdModel>();

	std::shared_ptr<imstk::PbdModelConfig> PbdConfig = std::make_shared<imstk::PbdModelConfig>();
	PbdConfig->m_gravity = UMathUtil::ToImstkVec3d(Gravity, true);
	PbdConfig->m_iterations = PbdModelIterations;
	PbdConfig->m_linearDampingCoeff = LinearDampingCoeff;
	//PbdConfig->m_collisionIterations = PbdModelCollisionIterations;
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
	if (UImstkSettings::IsDebugging())
		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Subsystem Initialized"));

	if (HapticManager) {
		HapticsThread = new FHapticsThread(HapticManager, GetWorld(), TickInterval);
		CurrentHapticsThread = FRunnableThread::Create(HapticsThread, TEXT("Haptics Thread"));
	}

	// Set up scene manager
	SceneManager->setActiveScene(ActiveScene);

	SceneManager->init();

	// This is putting haptics on a timer instead (very laggy)
	//if (HapticManager) {
	//	HapticManager->init();
	//	GetWorld()->GetTimerManager().SetTimer(HapticsTimer, this, &UImstkSubsystem::UpdateHaptics, TickInterval, true);
	//}


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

			UPackage* Package = CreatePackage(nullptr, *PackagePath);
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

		/*bool IsSuccessful = UPackage::SavePackage(TaskGraph->GetPackage(), TaskGraph, EObjectFlags::RF_Public | EObjectFlags::RF_Standalone, *FilePath);*/

		FSavePackageArgs SavePackageArgs = { NULL,  EObjectFlags::RF_Standalone ,0U, false, true, true, FDateTime::MinValue(), GError };

		bool IsSuccessful = UPackage::SavePackage(TaskGraph->GetPackage(), TaskGraph, *FilePath, SavePackageArgs);
	}

#endif
}

void UImstkSubsystem::UpdateSimulation(float DeltaTime)
{
	if (!bIsPaused && bIsInitialized) {
		// Set the delta time for the rigid body model and pbd models and progress the scene by that amount using the Unreal time since last update
		if (UImstkSettings::IsUseRealtime()) {
			/*for (UDeformableModel* Model : DeformableModels) {
				Model->PbdObject->getPbdModel()->setTimeStep(DeltaTime);
			}*/
			PbdModel->getConfig()->m_dt = DeltaTime;
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
	if (CurrentHapticsThread && HapticsThread) {
		CurrentHapticsThread->Suspend(true);
		HapticsThread->bStopThread = true;
		CurrentHapticsThread->Suspend(false);
		CurrentHapticsThread->Kill(false);
		CurrentHapticsThread->WaitForCompletion();
		delete HapticsThread;
	}
	if (HapticManager) {
		GetWorld()->GetTimerManager().ClearTimer(HapticsTimer);
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

	if (HapticManager) {
		HapticManager->uninit();
	}

	SceneManager.reset();
	RigidBodyModel.reset();
	ActiveScene.reset();

	HapticManager.reset();
}

bool UImstkSubsystem::IsSubsystemInitialized() {
	return bIsInitialized;
}








static std::shared_ptr<imstk::PbdObject>
makePbdObjSurface(
	const std::string& name,
	std::shared_ptr<imstk::PbdModel> model,
	const imstk::Vec3d& size,
	const imstk::Vec3i& dim,
	const imstk::Vec3d& center)
{
	auto prismObj = std::make_shared<imstk::PbdObject>(name);

	// Setup the Geometry
	std::shared_ptr<imstk::TetrahedralMesh> prismMesh = imstk::MeshIO::read<imstk::TetrahedralMesh>("C:/WorkStuff/UnmodifiedTest/build/install/data/textured_organs/heart_volume.vtk");
	std::shared_ptr<imstk::SurfaceMesh>     surfMesh = prismMesh->extractSurfaceMesh();
	//std::shared_ptr<TetrahedralMesh> prismMesh = MeshIO::read<TetrahedralMesh>(iMSTK_DATA_ROOT "/textured_organs/heart_volume.vtk");
	//std::shared_ptr<SurfaceMesh>     surfMesh = prismMesh->extractSurfaceMesh();

	// Setup the Object
	prismObj->setPhysicsGeometry(surfMesh);
	prismObj->setCollidingGeometry(surfMesh);
	prismObj->setVisualGeometry(surfMesh);
	prismObj->getVisualModel(0)->getRenderMaterial()->setDisplayMode(imstk::RenderMaterial::DisplayMode::Wireframe);
	prismObj->setDynamicalModel(model);
	prismObj->getPbdBody()->uniformMassValue = 0.05;
	// Use volume+distance constraints, worse results. More performant (can use larger mesh)
	model->getConfig()->enableConstraint(imstk::PbdModelConfig::ConstraintGenType::Dihedral, 1000.0,
		prismObj->getPbdBody()->bodyHandle);
	model->getConfig()->enableConstraint(imstk::PbdModelConfig::ConstraintGenType::Distance, 500.0,
		prismObj->getPbdBody()->bodyHandle);
	// Fix the borders
	std::shared_ptr<imstk::VecDataArray<double, 3>> vertices = surfMesh->getVertexPositions();
	for (int i = 0; i < surfMesh->getNumVertices(); i++)
	{
		const imstk::Vec3d& pos = (*vertices)[i];
		if (pos[1] <= center[1] - size[1] * 0.5)
		{
			prismObj->getPbdBody()->fixedNodeIds.push_back(i);
		}
	}

	return prismObj;
}

static std::shared_ptr<imstk::PbdObject>
makeCapsuleToolObj(std::shared_ptr<imstk::PbdModel> model)
{
	auto toolGeometry = std::make_shared<imstk::Capsule>();
	toolGeometry->setRadius(0.5);
	toolGeometry->setLength(1);
	toolGeometry->setPosition(imstk::Vec3d(0.0, 0.0, 0.0));
	toolGeometry->setOrientation(imstk::Quatd(0.707, 0.0, 0.0, 0.707));

	auto toolObj = std::make_shared<imstk::PbdObject>("Tool");

	// Create the object
	toolObj->setVisualGeometry(toolGeometry);
	toolObj->setPhysicsGeometry(toolGeometry);
	toolObj->setCollidingGeometry(toolGeometry);
	toolObj->setDynamicalModel(model);
	toolObj->getPbdBody()->setRigid(
		imstk::Vec3d(0.0, 5.0, 2.0),
		1.0,
		imstk::Quatd::Identity(),
		imstk::Mat3d::Identity() * 1.0);

	toolObj->getVisualModel(0)->getRenderMaterial()->setOpacity(0.9);

	// Add a component for controlling via another device
	auto controller = toolObj->addComponent<imstk::PbdObjectController>();
	controller->setControlledObject(toolObj);
	controller->setTranslationScaling(50.0);
	controller->setLinearKs(5000.0);
	controller->setAngularKs(1000.0);
	controller->setUseCritDamping(true);
	controller->setForceScaling(0.01);
	controller->setSmoothingKernelSize(15);
	controller->setUseForceSmoothening(true);

	// Add extra component to tool for the ghost
	auto controllerGhost = toolObj->addComponent<imstk::ObjectControllerGhost>();
	controllerGhost->setController(controller);

	return toolObj;
}

void UImstkSubsystem::ImstkTest() {
	// Setup logger (write to file and stdout)
	imstk::Logger::getInstance().addFileSink("simulation", std::string(TCHAR_TO_UTF8(*FPaths::ProjectLogDir())));

	// Setup the scene
	auto scene = std::make_shared<imstk::Scene>("PbdHapticGrasping");
	scene->getActiveCamera()->setPosition(0.12, 4.51, 16.51);
	scene->getActiveCamera()->setFocalPoint(0.0, 0.0, 0.0);
	scene->getActiveCamera()->setViewUp(0.0, 0.96, -0.28);

	auto                            pbdModel = std::make_shared<imstk::PbdModel>();
	std::shared_ptr<imstk::PbdModelConfig> pbdParams = pbdModel->getConfig();
	pbdParams->m_gravity = imstk::Vec3d(0.0, 0.0, 0.0);
	pbdParams->m_dt = 0.005;
	pbdParams->m_iterations = 8;
	pbdParams->m_linearDampingCoeff = 0.003;

	// Setup a tissue to grasp
	std::shared_ptr<imstk::PbdObject> pbdObj = makePbdObjSurface("Tissue",
		pbdModel,
		imstk::Vec3d(4.0, 4.0, 4.0),  // Dimensions
		imstk::Vec3i(5, 5, 5),        // Divisions
		imstk::Vec3d(0.0, 0.0, 0.0)); // Center
	scene->addSceneObject(pbdObj);

	// Setup a tool to grasp with
	std::shared_ptr<imstk::PbdObject> toolObj = makeCapsuleToolObj(pbdModel);
	scene->addSceneObject(toolObj);

	// Add collision
	auto pbdToolCollision = std::make_shared<imstk::PbdObjectCollision>(pbdObj, toolObj);
	//pbdToolCollision->setRigidBodyCompliance(0.0001); // Helps with smoothness
	scene->addInteraction(pbdToolCollision);

	// Create new picking with constraints
	/*auto toolPicking = std::make_shared<imstk::PbdObjectGrasping>(pbdObj, toolObj);
	toolPicking->setStiffness(0.3);
	scene->addInteraction(toolPicking);*/

	// Light
	auto light = std::make_shared<imstk::DirectionalLight>();
	light->setFocalPoint(imstk::Vec3d(5.0, -8.0, -5.0));
	light->setIntensity(1.0);
	scene->addLight("Light", light);

	// Run the simulation
	{
		// Setup a viewer to render
		auto viewer = std::make_shared<imstk::VTKViewer>();
		viewer->setActiveScene(scene);
		viewer->setVtkLoggerMode(imstk::VTKViewer::VTKLoggerMode::MUTE);

		// Setup a scene manager to advance the scene
		auto sceneManager = std::make_shared<imstk::SceneManager>();
		sceneManager->setActiveScene(scene);
		sceneManager->pause();         // Start simulation paused

		auto driver = std::make_shared<imstk::SimulationManager>();
		driver->addModule(viewer);
		driver->addModule(sceneManager);
		driver->setDesiredDt(0.005);

		auto controller = toolObj->getComponent<imstk::PbdObjectController>();
		// Setup default haptics manager
		std::shared_ptr<imstk::DeviceManager> hapticManager = imstk::DeviceManagerFactory::makeDeviceManager();
		if (hapticManager->getTypeName() == "HaplyDeviceManager")
		{
			controller->setTranslationOffset(imstk::Vec3d(2.0, 0.0, -2.0));
		}
		std::shared_ptr<imstk::DeviceClient> deviceClient = hapticManager->makeDeviceClient();
		driver->addModule(hapticManager);

		//connect<imstk::ButtonEvent>(deviceClient, &imstk::DeviceClient::buttonStateChanged,
		//    [&](imstk::ButtonEvent* e)
		//    {
		//        if (e->m_buttonState == BUTTON_PRESSED)
		//        {
		//            if (e->m_button == 1)
		//            {
		//                // Use a slightly larger capsule since collision prevents intersection
		//                auto capsule = std::dynamic_pointer_cast<Capsule>(toolObj->getCollidingGeometry());
		//                auto dilatedCapsule = std::make_shared<Capsule>(*capsule);
		//                dilatedCapsule->setRadius(capsule->getRadius() * 1.1);
		//                toolPicking->beginVertexGrasp(dilatedCapsule);
		//                //pbdToolCollision->setEnabled(false);
		//            }
		//        }
		//        else if (e->m_buttonState == BUTTON_RELEASED)
		//        {
		//            if (e->m_button == 1)
		//            {
		//                toolPicking->endGrasp();
		//                //pbdToolCollision->setEnabled(true);
		//            }
		//        }
		//    });

		// Alternative grasping by keyboard (in case device doesn't have a button)
		//connect<KeyEvent>(viewer->getKeyboardDevice(), &KeyboardDeviceClient::keyPress,
		//    [&](KeyEvent* e)
		//    {
		//        if (e->m_key == 'g')
		//        {
		//            auto capsule = std::dynamic_pointer_cast<Capsule>(toolObj->getCollidingGeometry());
		//            auto dilatedCapsule = std::make_shared<Capsule>(*capsule);
		//            dilatedCapsule->setRadius(capsule->getRadius() * 1.1);
		//            toolPicking->beginVertexGrasp(dilatedCapsule);
		//            //pbdToolCollision->setEnabled(false);
		//        }
		//    });
		//connect<KeyEvent>(viewer->getKeyboardDevice(), &KeyboardDeviceClient::keyRelease,
		//    [&](KeyEvent* e)
		//    {
		//        if (e->m_key == 'g')
		//        {
		//            toolPicking->endGrasp();
		//            //pbdToolCollision->setEnabled(true);
		//        }
		//    });
		controller->setDevice(deviceClient);

		// Add default mouse and keyboard controls to the viewer
		std::shared_ptr<imstk::Entity> mouseAndKeyControls =
			imstk::SimulationUtils::createDefaultSceneControl(driver);
		scene->addSceneObject(mouseAndKeyControls);

		imstk::connect<imstk::Event>(sceneManager, &imstk::SceneManager::preUpdate, [&](imstk::Event*)
			{
				// Simulate in real time
				pbdModel->getConfig()->m_dt = sceneManager->getDt();
				auto verts = std::dynamic_pointer_cast<imstk::SurfaceMesh>(pbdObj->getVisualGeometry())->getVertexPositions();
				for (auto vert : *verts.get())
					if (vert.x() != vert.x())
						LOG(WARNING) << "NAN";
			});

		driver->start();
	}
}
void UImstkSubsystem::UpdateHaptics()
{
	HapticManager->update();
}