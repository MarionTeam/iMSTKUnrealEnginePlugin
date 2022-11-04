// Fill out your copyright notice in the Description page of Project Settings.


#include "HapticController.h"
#include "imstkPbdObject.h"
#include "imstkPbdObjectController.h"
#include "imstkDeviceManager.h"
#include "imstkDeviceManagerFactory.h"
#include "imstkDeviceClient.h"
#include "imstkRigidObjectController.h"
#include "imstkRigidBodyModel2.h"
#include "imstkRbdConstraint.h"
#include "imstkMeshIO.h"
#include "imstkIsometricMap.h"

void UHapticController::PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent)
{
	FName PropertyName = (PropertyChangedEvent.Property != NULL) ? PropertyChangedEvent.Property->GetFName() : NAME_None;

	if (PropertyName == GET_MEMBER_NAME_CHECKED(UHapticController, Preset)) {
		switch (Preset)
		{
		case 0:
			ToolGeomFilter.GeomType = EGeometryType::Capsule;
			ToolGeomFilter.CapsuleStruct.Radius = 12.5;
			ToolGeomFilter.CapsuleStruct.Length = 50;
			ToolType = EToolType::CollidingTool;
			break;
		case 1:
			ToolGeomFilter.GeomType = EGeometryType::Capsule;
			ToolGeomFilter.CapsuleStruct.Radius = 12.5;
			ToolGeomFilter.CapsuleStruct.Length = 50;
			ToolType = EToolType::GraspingTool;
			GraspStiffness = 1.0;
			GraspType = EGraspType::VertexGrasp;
			break;
		case 2:
			ToolGeomFilter.GeomType = EGeometryType::SurfaceMesh;
			ToolType = EToolType::CuttingTool;
			break;
		case 3:
			ToolGeomFilter.GeomType = EGeometryType::LineMesh;
			ToolGeomFilter.LineMeshStruct.Vertices.Empty();
			ToolGeomFilter.LineMeshStruct.Vertices.Add(FVector(0, 0, 0));
			ToolGeomFilter.LineMeshStruct.Vertices.Add(FVector(0, 0, 50));
			ToolType = EToolType::StitchingTool;
			break;
		case 4:
			ToolGeomFilter.GeomType = EGeometryType::SurfaceMesh;
			ToolType = EToolType::LevelSetTool;
			break;
		default:
			return;
		}
	}
}

// Called before Begin Play
void UHapticController::InitializeComponent()
{
	Super::InitializeComponent();

	// Turn off ticking for this component
	if (GetWorld() && GetWorld()->GetGameInstance())
		this->SetComponentTickEnabled(false);
}

void UHapticController::InitController()
{
	Super::InitController();

	if (ToolGeomFilter.GeomType != EGeometryType::Sphere && ToolGeomFilter.GeomType != EGeometryType::Capsule &&
		ToolGeomFilter.GeomType != EGeometryType::LineMesh && ToolGeomFilter.GeomType != EGeometryType::SurfaceMesh) {
		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "Error: Geometry type not implemented for controllers. Please select sphere, capsule, line mesh or surface mesh");
		UE_LOG(LogTemp, Error, TEXT("Error: Geometry type not implemented for controllers. Please select sphere, capsule, line mesh or surface mesh"));;
		//SubsystemInstance->AllControllers.Remove(this); // This causes an error since it removes from the for loop it resides in
		return;
	}

	// Check if the selected geometry type matches the tool type
	if ((ToolType == EToolType::GraspingTool && (ToolGeomFilter.GeomType != EGeometryType::Sphere && ToolGeomFilter.GeomType != EGeometryType::Capsule)) ||
		(ToolType == EToolType::StitchingTool && ToolGeomFilter.GeomType != EGeometryType::LineMesh) ||
		(ToolType == EToolType::CuttingTool && ToolGeomFilter.GeomType != EGeometryType::SurfaceMesh)) {
		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "Error: Controller type to Geometry mismatch");
		UE_LOG(LogTemp, Error, TEXT("Error: Controller type to Geometry mismatch"));;
		//SubsystemInstance->AllControllers.Remove(this); // This causes an error since it removes from the for loop it resides in
		return;
	}

	std::shared_ptr<imstk::Geometry> ToolGeom = ToolGeomFilter.Init(this);

	// Only scale for surface mesh tools
	// TODO: if there are multiple static meshes attached to controller it will only get the first
	if (ToolGeomFilter.GeomType == EGeometryType::SurfaceMesh) {
		TArray<USceneComponent*> Components;
		GetChildrenComponents(false, Components);
		for (USceneComponent* Comp : Components) {
			if (Comp->IsA(UStaticMeshComponent::StaticClass())) {
				MeshComp = (UStaticMeshComponent*)Comp;
				ToolGeom->scale(UMathUtil::ToImstkVec3d(MeshComp->GetComponentScale(), false), imstk::Geometry::TransformType::ApplyToData);
				break;
			}
		}
	}

	if (MeshComp)
		ToolGeom->rotate(UMathUtil::ToImstkQuat(MeshComp->GetComponentRotation().Quaternion()), imstk::Geometry::TransformType::ApplyToData);
	else
		std::dynamic_pointer_cast<imstk::AnalyticalGeometry>(ToolGeom)->setOrientation(UMathUtil::ToImstkQuat(GetComponentRotation().Quaternion()));
	
	std::shared_ptr<imstk::SceneObjectController> Controller;
	if (ToolType == EToolType::LevelSetTool) 
	{
		// Use a rigid object for levelset tool 
		RigidToolObj = std::make_shared<imstk::RigidObject2>(TCHAR_TO_UTF8(*this->GetName()));
		ToolObj = RigidToolObj;

		std::shared_ptr<imstk::RigidObjectController> RigidController = ToolObj->addComponent<imstk::RigidObjectController>();
		Controller = RigidController;
		RigidController->setControlledObject(ToolObj);
		RigidController->setTranslationScaling(TranslationScaling);
		RigidController->setLinearKs(LinearKs);
		RigidController->setAngularKs(AngularKs);
		RigidController->setForceScaling(ForceScaling);
		RigidController->setUseCritDamping(bUseCriticalDamping);
		RigidController->setUseForceSmoothening(bUseForceSmoothening);
		RigidController->setSmoothingKernelSize(SmoothingKernelSize);

		auto RbdModel = std::make_shared<imstk::RigidBodyModel2>();
		RbdModel->getConfig()->m_maxNumIterations = MaxNumIterations;
		RbdModel->getConfig()->m_velocityDamping = VelocityDamping;
		RbdModel->getConfig()->m_angularVelocityDamping = AngularVelocityDamping;
		RbdModel->getConfig()->m_maxNumConstraints = MaxNumConstraints;
		RbdModel->getConfig()->m_gravity = imstk::Vec3d::Zero();
		ToolObj->setDynamicalModel(RbdModel);
		//RigidToolObj->getRigidBody()->setInitOrientation(UMathUtil::ToImstkQuat(MeshComp->GetComponentRotation().Quaternion()));
	}
	else {
		// Use a Pbd object with a shared model and rigid body for every other type of tool
		bIsPbdTool = true;
		std::shared_ptr<imstk::PbdModel> PbdModel = SubsystemInstance->PbdModel;
		PbdToolObj = std::make_shared<imstk::PbdObject>(TCHAR_TO_UTF8(*this->GetName()));
		ToolObj = PbdToolObj;
		ToolObj->setDynamicalModel(PbdModel);

		PbdToolObj->getPbdBody()->setRigid(
			UMathUtil::ToImstkVec3d(RBPos, true),
			RBMass,
			imstk::Quatd::Identity(),
			imstk::Mat3d::Identity() * RBInertiaMultiplier);

		std::shared_ptr<imstk::PbdObjectController> PbdController = PbdToolObj->addComponent<imstk::PbdObjectController>();
		Controller = PbdController;
		PbdController->setControlledObject(PbdToolObj);
		PbdController->setTranslationScaling(TranslationScaling);
		PbdController->setLinearKs(LinearKs);
		PbdController->setAngularKs(AngularKs);
		PbdController->setForceScaling(ForceScaling);
		PbdController->setUseCritDamping(bUseCriticalDamping);
		PbdController->setUseForceSmoothening(bUseForceSmoothening);
		PbdController->setSmoothingKernelSize(SmoothingKernelSize);	
	}
	FString ContentDir = FPaths::ProjectContentDir();

	if (!bVisualGeometryFromFile)
		ToolObj->setVisualGeometry(ToolGeom);
	else {
		// Import the visual from the set file path
		std::shared_ptr<imstk::SurfaceMesh> VisMesh = imstk::MeshIO::read<imstk::SurfaceMesh>(std::string(TCHAR_TO_UTF8(*(ContentDir.Append(VisualGeometryFilePath)))));
		ToolObj->setVisualGeometry(VisMesh);

		ToolObj->setPhysicsToVisualMap(std::make_shared<imstk::IsometricMap>(ToolGeom, VisMesh));

		// Assume visual is always a surface mesh
		UProceduralMeshComponent* VisMeshComp = NewObject<UProceduralMeshComponent>(this);
		// If including scale, scale gets applied twice
		VisMeshComp->AttachToComponent(this, FAttachmentTransformRules::SnapToTargetNotIncludingScale);
		VisMeshComp->RegisterComponent();
		VisMeshComp->SetWorldRotation(FQuat::Identity);

		VisMesh->computeVertexNormals();
		imstk::VecDataArray<double, 3>& ImstkNorms = *VisMesh->getVertexNormals();

		TArray<FVector2D> UV0;
		TArray<FLinearColor> VertColors;
		TArray<FProcMeshTangent> Tangents;

		TArray<FVector> Verts;
		TArray<FVector> Normals;
		TArray<int32> Indices;

		// Use normals from imstk
		Normals.Empty();
		for (int i = 0; i < ImstkNorms.size(); i++) {
			Normals.Add(UMathUtil::ToUnrealFVec(ImstkNorms[i], false));
		}

		// Get vertex data from imstk
		Verts = UMathUtil::ToUnrealFVecArray(VisMesh->getVertexPositions(), true);

		Indices = UMathUtil::ToUnrealIntArray(VisMesh->getTriangleIndices());

		// Create the mesh sections on the procedural meshes
		VisMeshComp->CreateMeshSection_LinearColor(0, Verts, Indices, Normals, UV0, VertColors, Tangents, false);
	}

	if (!bCollidingGeometryFromFile)
		ToolObj->setCollidingGeometry(ToolGeom);
	else
		ToolObj->setCollidingGeometry(imstk::MeshIO::read(std::string(TCHAR_TO_UTF8(*(ContentDir.Append(CollidingGeometryFilePath))))));

	if (!bPhysicsGeometryFromFile)
		ToolObj->setPhysicsGeometry(ToolGeom);
	else
		ToolObj->setPhysicsGeometry(imstk::MeshIO::read(std::string(TCHAR_TO_UTF8(*(ContentDir.Append(PhysicsGeometryFilePath))))));


	if (MeshComp) 
		Controller->setTranslationOffset(UMathUtil::ToImstkVec3d(MeshComp->GetComponentLocation(), true));
	else 
		Controller->setTranslationOffset(UMathUtil::ToImstkVec3d(GetComponentLocation(), true));

	std::shared_ptr<imstk::DeviceManager> HapticManager = imstk::DeviceManagerFactory::makeDeviceManager();
	DeviceClient = HapticManager->makeDeviceClient();
	Controller->setDevice(DeviceClient);

	SubsystemInstance->HapticManager = HapticManager;

	SubsystemInstance->ActiveScene->addSceneObject(ToolObj);

	OrientationOffset = GetRelativeRotation().Quaternion();

	Super::bIsInitialized = true;
}

void UHapticController::UpdateUnrealPosRot()
{
	if (bIsPbdTool)
		SetWorldLocationAndRotation(UMathUtil::ToUnrealFVec((*PbdToolObj->getPbdBody()->vertices)[0], true), UMathUtil::ToUnrealFQuat((*PbdToolObj->getPbdBody()->orientations)[0]) * OrientationOffset);
	else
		SetWorldLocationAndRotation(UMathUtil::ToUnrealFVec(RigidToolObj->getRigidBody()->getPosition(), true), UMathUtil::ToUnrealFQuat(RigidToolObj->getRigidBody()->getOrientation()) * OrientationOffset);
}

void UHapticController::InitGrasping(const int Button)
{
	imstk::connect<imstk::ButtonEvent>(DeviceClient, &imstk::DeviceClient::buttonStateChanged,
		[&](imstk::ButtonEvent* e)
		{
			if (e->m_buttonState == BUTTON_PRESSED)
			{
				if (e->m_button == 1)
				{
					for (auto Picking : ToolPickings) {
						if(GraspType == EGraspType::VertexGrasp)
							Picking->beginVertexGrasp(std::dynamic_pointer_cast<imstk::AnalyticalGeometry>(ToolObj->getCollidingGeometry()));
						else if(GraspType == EGraspType::CellGrasp)
							Picking->beginCellGrasp(std::dynamic_pointer_cast<imstk::AnalyticalGeometry>(ToolObj->getCollidingGeometry()));
					}
				}
			}
			else if (e->m_buttonState == BUTTON_RELEASED)
			{
				if (e->m_button == 1)
				{
					for (auto Picking : ToolPickings)
						Picking->endGrasp();
				}
			}
		});
}

void UHapticController::InitCutting(const int Button)
{
	imstk::connect<imstk::ButtonEvent>(DeviceClient, &imstk::DeviceClient::buttonStateChanged,
		[&](imstk::ButtonEvent* e)
		{
			if (e->m_buttonState == BUTTON_PRESSED)
			{
				if (e->m_button == 1)
				{
					for (auto Cut : Cuttings)
						Cut->apply();
				}
			}
		});
}

void UHapticController::UnInit()
{
	Super::UnInit();
	PbdToolObj.reset();
	RigidToolObj.reset();
	DeviceClient.reset();
}