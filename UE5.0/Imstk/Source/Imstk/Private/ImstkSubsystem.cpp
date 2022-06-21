// Fill out your copyright notice in the Description page of Project Settings.

#include "ImstkSubsystem.h"

//#include "Tickable.h"
#include "Engine/GameEngine.h"
#include "ImstkSettings.h"
#include "DeformableModel.h"
#include "MathUtil.h"

//#include "imstkSphere.h"
//#include "imstkPlane.h"

//#include "imstkRigidObject2.h"
//#include "imstkPbdObject.h"
//#include "imstkPbdModel.h"

//#include "imstkSceneObject.h"

#include "imstkSimulationManager.h"
//#include "imstkDynamicObject.h"
#include "imstkLogger.h"
#include "imstkTaskGraph.h"
#include "imstkTaskGraphVizWriter.h"
#include "imstkPbdModel.h"

// For testing purposes
#include "imstkNew.h"
#include "imstkSurfaceMesh.h"
#include "imstkRigidBodyModel2.h"
#include "imstkGeometryUtilities.h"
#include "imstkRbdConstraint.h"
#include "imstkVTKViewer.h"
#include "imstkCamera.h"
#include "imstkDirectionalLight.h"
#include "imstkRenderMaterial.h"
#include "imstkVisualModel.h"
#include "imstkMouseDeviceClient.h"
#include "imstkMouseSceneControl.h"
#include "imstkKeyboardSceneControl.h"
#include "imstkPbdObjectCollision.h"
#include "imstkKeyboardDeviceClient.h"

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
	TickFunction.TickInterval = TickInterval;
	TickFunction.RegisterTickFunction(GetWorld()->GetCurrentLevel());
}


void UImstkSubsystem::ImstkInit() 
{
	UMathUtil::SetScale(SceneScale);

	SceneManager = std::make_shared<imstk::SceneManager>();
	ActiveScene = std::make_shared<imstk::Scene>("Active Scene");
	RigidBodyModel = std::make_shared<imstk::RigidBodyModel2>();
	// TODO: task graph file path can not be accessed from the scene itself (unless theres some way i dont know about) so it will be in the engine files for unreal
	ActiveScene->getConfig()->writeTaskGraph = UImstkSettings::IsWritingTaskGraph();

	// Set up rigid body model using variables set in editor
	RigidBodyModel->getConfig()->m_gravity = UMathUtil::ToImstkVec3(Gravity, true);
	RigidBodyModel->getConfig()->m_maxNumIterations = RigidBodyMaxIterations;
	RigidBodyModel->getConfig()->m_dt = TickInterval;

	if (UImstkSettings::IsLoggerActive()) {
		//imstk::Logger::startLogger();
		imstk::Logger::getInstance().addFileSink("simulation", std::string(TCHAR_TO_UTF8(*FPaths::ProjectLogDir())));
	}

	
	// Initialize behaviours (models, etc) and interactions after (collisions)
	for (UImstkController* Controller : AllControllers)
	{
		Controller->InitController();
	}
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

	if (UImstkSettings::IsWritingTaskGraph()) {
		imstk::TaskGraphVizWriter writer;
		writer.setInput(ActiveScene->getTaskGraph());
		writer.setFileName(std::string(TCHAR_TO_UTF8(*FPaths::ProjectLogDir())) + "/sceneTaskGraph.svg");
		writer.write();
	}
	//SceneManager->pause();
}

void UImstkSubsystem::UpdateSimulation(float DeltaTime) 
{
	// Set the delta time for the rigid body model and pbd models and progress the scene by that amount using the Unreal time since last update
	if (UImstkSettings::IsUseRealtime()) {
		for (UDeformableModel* Model : DeformableModels) {
			Model->PbdObject->getPbdModel()->setTimeStep(DeltaTime);
		}
		RigidBodyModel->getConfig()->m_dt = DeltaTime;
	}
	// TODO: may need a reference to each RBM since when they are assigned to the objects I think they copy the RBM
	
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


//void UImstkSubsystem::ImstkTest()
//{
//	imstk::Logger::getInstance().addFileSink("simulation", std::string(TCHAR_TO_UTF8(*FPaths::ProjectLogDir())));
//	std::shared_ptr<imstk::Scene> activeScene = std::make_shared<imstk::Scene>("Active Scene");
//	std::shared_ptr<imstk::SceneManager >sceneManager = std::make_shared<imstk::SceneManager>();
//	/*std::shared_ptr<imstk::Plane> cutGeom = std::make_shared<imstk::Plane>();
//	cutGeom->setPosition(PlanePos.X, PlanePos.Y, PlanePos.Z);
//	cutGeom->setNormal(PlaneNorm.X, PlaneNorm.Y, PlaneNorm.Z);
//	cutGeom->setWidth(100);*/
//	std::shared_ptr<imstk::SurfaceMesh> cutGeom = imstk::GeometryUtils::toTriangleGrid(imstk::Vec3d::Zero(),
//		imstk::Vec2d(100, 100), imstk::Vec2i(2, 2));
//	//cutGeom->rotate(imstk::Quatd(0.707, 0.0, 0.0, 0.707), imstk::Geometry::TransformType::ApplyToData);
//	//cutGeom->setRotation(imstk::Quatd(0.707, 0.0, 0.0, 0.707));
//	//cutGeom->updatePostTransformData();
//	
//
//	std::shared_ptr<imstk::RigidObject2> cutObj = std::make_shared<imstk::RigidObject2>("CuttingObject");
//
//	std::shared_ptr<imstk::RigidBodyModel2> RbdModel = std::make_shared<imstk::RigidBodyModel2>();
//	RbdModel->getConfig()->m_gravity = imstk::Vec3d::Zero();
//	RbdModel->getConfig()->m_maxNumIterations = 8;
//	RbdModel->getConfig()->m_velocityDamping = 1;
//	RbdModel->getConfig()->m_angularVelocityDamping = 1;
//	RbdModel->getConfig()->m_maxNumConstraints = 40;
//
//	cutObj->setDynamicalModel(RbdModel);
//
//	imstk::imstkNew<imstk::RenderMaterial> cutMaterial;
//	cutMaterial->setBackFaceCulling(false);
//	cutMaterial->setDisplayMode(imstk::RenderMaterial::DisplayMode::WireframeSurface);
//
//	imstk::imstkNew<imstk::VisualModel> cutVisualModel;
//	cutVisualModel->setGeometry(cutGeom);
//	cutVisualModel->setRenderMaterial(cutMaterial);
//	cutObj->addVisualModel(cutVisualModel);
//	//cutObj->setVisualGeometry(cutGeom;
//	cutObj->setCollidingGeometry(cutGeom);
//	cutObj->setPhysicsGeometry(cutGeom);
//
//
//	cutObj->getRigidBody()->m_mass = 1;
//	cutObj->getRigidBody()->m_intertiaTensor = imstk::Mat3d::Identity() * 1;
//	cutObj->getRigidBody()->m_initPos = imstk::Vec3d(PlanePos.X, PlanePos.Y, PlanePos.Z);
//
//	activeScene->addSceneObject(cutObj);
//
//
//	/*imstk::imstkNew<imstk::CollidingObject> cutObj("CuttingObject");
//	cutObj->setVisualGeometry(cutGeom);
//	cutObj->setCollidingGeometry(cutGeom);
//	
//	activeScene->addSceneObject(cutObj);*/
//
//
//	std::shared_ptr<imstk::PbdObject> ClothObj = std::make_shared<imstk::PbdObject>("TEST CLOTH");
//	double width = 50.0;
//	double height = 50.0;
//	int nRows = 12;
//	int nCols = 12;
//	std::shared_ptr<imstk::SurfaceMesh> clothMesh =
//		imstk::GeometryUtils::toTriangleGrid(imstk::Vec3d::Zero(),
//			imstk::Vec2d(width, height), imstk::Vec2i(nRows, nCols));
//
//	// Setup the Parameters
//	std::shared_ptr<imstk::PbdModelConfig> pbdParams = std::make_shared<imstk::PbdModelConfig>();
//	pbdParams->enableConstraint(imstk::PbdModelConfig::ConstraintGenType::Distance, 1.0e5);
//	pbdParams->enableConstraint(imstk::PbdModelConfig::ConstraintGenType::Dihedral, 1.0e5);
//	pbdParams->m_fixedNodeIds = { 0, static_cast<size_t>(nCols) - 1 };
//	pbdParams->m_uniformMassValue = width * height / static_cast<double>(nRows * nCols);
//	pbdParams->m_gravity = imstk::Vec3d(0.0, -98.0, 0.0);
//	pbdParams->m_dt = 0.005;
//	pbdParams->m_iterations = 5;
//
//	// Setup the Model
//	std::shared_ptr<imstk::PbdModel> pbdModel = std::make_shared< imstk::PbdModel>();
//	pbdModel->setModelGeometry(clothMesh);
//	pbdModel->configure(pbdParams);
//
//	
//	imstk::imstkNew<imstk::RenderMaterial> material;
//	material->setBackFaceCulling(false);
//	material->setDisplayMode(imstk::RenderMaterial::DisplayMode::WireframeSurface);
//
//	imstk::imstkNew<imstk::VisualModel> visualModel;
//	visualModel->setGeometry(clothMesh);
//	visualModel->setRenderMaterial(material);
//
//	// Setup the Object
//	ClothObj->addVisualModel(visualModel);
//
//	ClothObj->setPhysicsGeometry(clothMesh);
//	ClothObj->setCollidingGeometry(clothMesh);
//	ClothObj->setDynamicalModel(pbdModel);
//
//	activeScene->addSceneObject(ClothObj);
//
//	std::shared_ptr<imstk::PbdObjectCutting> cutting = std::make_shared<imstk::PbdObjectCutting>(ClothObj, cutObj);
//	//std::shared_ptr<imstk::PbdObjectCollision> Interaction = std::make_shared<imstk::PbdObjectCollision>(ClothObj, cutObj, "PointSetToPlaneCD");
//	//activeScene->addSceneObject(Interaction);
//
//
//	imstk::imstkNew<imstk::VTKViewer> viewer;
//	activeScene->getActiveCamera()->setPosition(imstk::Vec3d(1.0, 1.0, -1.0) * 100.0);
//	activeScene->getActiveCamera()->setFocalPoint(imstk::Vec3d(0, -50, 0));
//	imstk::imstkNew<imstk::DirectionalLight> light;
//	light->setFocalPoint(imstk::Vec3d(5.0, -8.0, -5.0));
//	light->setIntensity(1.0);
//	activeScene->addLight("light", light);
//	viewer->setActiveScene(activeScene);
//
//
//	sceneManager->setActiveScene(activeScene);
//	imstk::imstkNew<imstk::SimulationManager> driver;
//	driver->addModule(viewer);
//	driver->addModule(sceneManager);
//	driver->setDesiredDt(0.001);
//
//	imstk::imstkNew<imstk::MouseSceneControl> mouseControl(viewer->getMouseDevice());
//	mouseControl->setSceneManager(sceneManager);
//	viewer->addControl(mouseControl);
//	/*imstk::connect<imstk::MouseEvent>(viewer->getMouseDevice(), &imstk::MouseDeviceClient::mouseMove,
//		[&](imstk::MouseEvent* e)
//		{
//			LOG(WARNING) << ClothObj->getCollidingGeometry()->getCenter();
//		});*/
//
//	imstk::connect<imstk::Event>(viewer->getMouseDevice(), &imstk::MouseDeviceClient::mouseButtonPress,
//		[&](imstk::Event*)
//		{
//			LOG(WARNING) << "Cut";
//			cutting->apply();
//		});
//
//	imstk::imstkNew<imstk::KeyboardSceneControl> keyControl(viewer->getKeyboardDevice());
//	keyControl->setSceneManager(sceneManager);
//	keyControl->setModuleDriver(driver);
//	viewer->addControl(keyControl);
//
//	imstk::connect<imstk::Event>(sceneManager, imstk::SceneManager::preUpdate, [&](imstk::Event*)
//		{
//			if (viewer->getKeyboardDevice()->getButton('1') == 1)
//			{
//				(*cutObj->getRigidBody()->m_pos) += imstk::Vec3d(0.1, 0.0, 0.0);
//			}
//			if (viewer->getKeyboardDevice()->getButton('2') == 1)
//			{
//				(*cutObj->getRigidBody()->m_pos) += imstk::Vec3d(-0.1, 0.0, 0.0);
//			}
//			if (viewer->getKeyboardDevice()->getButton('3') == 1)
//			{
//				(*cutObj->getRigidBody()->m_pos) += imstk::Vec3d(0.0, 0.1, 0.0);
//			}
//			if (viewer->getKeyboardDevice()->getButton('4') == 1)
//			{
//				(*cutObj->getRigidBody()->m_pos) += imstk::Vec3d(0.0, -0.1, 0.0);
//			}
//			if (viewer->getKeyboardDevice()->getButton('5') == 1)
//			{
//				(*cutObj->getRigidBody()->m_pos) += imstk::Vec3d(0.0, 0.0, 0.1);
//			}
//			if (viewer->getKeyboardDevice()->getButton('6') == 1)
//			{
//				(*cutObj->getRigidBody()->m_pos) += imstk::Vec3d(0.0, 0.0, -0.1);
//			}
//
//			if (viewer->getKeyboardDevice()->getButton('z') == 1)
//			{
//				const imstk::Quatd delta = imstk::Quatd(imstk::Rotd( 0.01, imstk::Vec3d(1.0, 0.0, 0.0)));
//				cutObj->getRigidBody()->m_orientation = new imstk::Quatd(*cutObj->getRigidBody()->m_orientation * delta);
//			}
//			if (viewer->getKeyboardDevice()->getButton('x') == 1)
//			{
//				const imstk::Quatd delta = imstk::Quatd(imstk::Rotd(-0.01, imstk::Vec3d(1.0, 0.0, 0.0)));
//				cutObj->getRigidBody()->m_orientation = new imstk::Quatd(*cutObj->getRigidBody()->m_orientation * delta);
//			}
//			if (viewer->getKeyboardDevice()->getButton('c') == 1)
//			{
//				const imstk::Quatd delta = imstk::Quatd(imstk::Rotd(0.01, imstk::Vec3d(0.0, 1.0, 0.0)));
//				cutObj->getRigidBody()->m_orientation = new imstk::Quatd(*cutObj->getRigidBody()->m_orientation * delta);
//			}
//			if (viewer->getKeyboardDevice()->getButton('v') == 1)
//			{
//				const imstk::Quatd delta = imstk::Quatd(imstk::Rotd(-0.01, imstk::Vec3d(0.0, 1.0, 0.0)));
//				cutObj->getRigidBody()->m_orientation = new imstk::Quatd(*cutObj->getRigidBody()->m_orientation * delta);
//			}
//			if (viewer->getKeyboardDevice()->getButton('b') == 1)
//			{
//				const imstk::Quatd delta = imstk::Quatd(imstk::Rotd(0.01, imstk::Vec3d(0.0, 0.0, 1.0)));
//				cutObj->getRigidBody()->m_orientation = new imstk::Quatd(*cutObj->getRigidBody()->m_orientation * delta);
//			}
//			if (viewer->getKeyboardDevice()->getButton('n') == 1)
//			{
//				const imstk::Quatd delta = imstk::Quatd(imstk::Rotd(-0.01, imstk::Vec3d(0.0, 0.0, 1.0)));
//				cutObj->getRigidBody()->m_orientation = new imstk::Quatd(*cutObj->getRigidBody()->m_orientation * delta);
//			}
//
//			if (viewer->getKeyboardDevice()->getButton('l') == 1)
//			{
//				LOG(WARNING) << "Visual Vert 1: " << std::dynamic_pointer_cast<imstk::SurfaceMesh>(cutObj->getVisualModel(0)->getGeometry())->getVertexPosition(0);
//				LOG(WARNING) << "Visual Vert 2: " << std::dynamic_pointer_cast<imstk::SurfaceMesh>(cutObj->getVisualModel(0)->getGeometry())->getVertexPosition(1);
//				LOG(WARNING) << "Visual Vert 3: " << std::dynamic_pointer_cast<imstk::SurfaceMesh>(cutObj->getVisualModel(0)->getGeometry())->getVertexPosition(2);
//				LOG(WARNING) << "Visual Vert 4: " << std::dynamic_pointer_cast<imstk::SurfaceMesh>(cutObj->getVisualModel(0)->getGeometry())->getVertexPosition(3);
//
//				LOG(WARNING) << "Colliding Vert 1: " << std::dynamic_pointer_cast<imstk::SurfaceMesh>(cutObj->getCollidingGeometry())->getVertexPosition(0);
//				LOG(WARNING) << "Colliding Vert 2: " << std::dynamic_pointer_cast<imstk::SurfaceMesh>(cutObj->getCollidingGeometry())->getVertexPosition(1);
//				LOG(WARNING) << "Colliding Vert 3: " << std::dynamic_pointer_cast<imstk::SurfaceMesh>(cutObj->getCollidingGeometry())->getVertexPosition(2);
//				LOG(WARNING) << "Colliding Vert 4: " << std::dynamic_pointer_cast<imstk::SurfaceMesh>(cutObj->getCollidingGeometry())->getVertexPosition(3);
//			}			
//		});
//
//	LOG(WARNING) << "Visual Vert 1: " << std::dynamic_pointer_cast<imstk::SurfaceMesh>(cutObj->getVisualModel(0)->getGeometry())->getVertexPosition(0);
//	LOG(WARNING) << "Visual Vert 2: " << std::dynamic_pointer_cast<imstk::SurfaceMesh>(cutObj->getVisualModel(0)->getGeometry())->getVertexPosition(1);
//	LOG(WARNING) << "Visual Vert 3: " << std::dynamic_pointer_cast<imstk::SurfaceMesh>(cutObj->getVisualModel(0)->getGeometry())->getVertexPosition(2);
//	LOG(WARNING) << "Visual Vert 4: " << std::dynamic_pointer_cast<imstk::SurfaceMesh>(cutObj->getVisualModel(0)->getGeometry())->getVertexPosition(3);
//
//	LOG(WARNING) << "Colliding Vert 1: " << std::dynamic_pointer_cast<imstk::SurfaceMesh>(cutObj->getCollidingGeometry())->getVertexPosition(0);
//	LOG(WARNING) << "Colliding Vert 2: " << std::dynamic_pointer_cast<imstk::SurfaceMesh>(cutObj->getCollidingGeometry())->getVertexPosition(1);
//	LOG(WARNING) << "Colliding Vert 3: " << std::dynamic_pointer_cast<imstk::SurfaceMesh>(cutObj->getCollidingGeometry())->getVertexPosition(2);
//	LOG(WARNING) << "Colliding Vert 4: " << std::dynamic_pointer_cast<imstk::SurfaceMesh>(cutObj->getCollidingGeometry())->getVertexPosition(3);
//
//
//	driver->start();
//	//SceneManager->init();
//	//bIsInitialized = true;
//}
//void UImstkSubsystem::CutTest() 
//{
//	//Cutting->apply();
//}



bool UImstkSubsystem::IsSubsystemInitialized() {
	return bIsInitialized;
}