// Fill out your copyright notice in the Description page of Project Settings.


#include "SuturingController.h"
#include "imstkPbdModel.h"
#include "MathUtil.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "imstkMeshIO.h"
#include "Interfaces/IPluginManager.h"
#include "imstkIsometricMap.h"
#include "imstkRbdConstraint.h"
#include "imstkNeedle.h"
#include "imstkRigidObjectController.h"
#include "ControllerNeedleTool.h"


void USuturingController::InitializeComponent()
{
	Super::InitializeComponent();

	ProcMeshComp = NewObject<UProceduralMeshComponent>(this);
	// If including scale, scale gets applied twice
	ProcMeshComp->AttachToComponent(this, FAttachmentTransformRules::SnapToTargetNotIncludingScale);
	ProcMeshComp->RegisterComponent();

	// Attach a separate procedural mesh component for the ghost model if it is a force tool
	if (bForceTool) {
		GhostMeshComp = NewObject<UProceduralMeshComponent>(this);
		GhostMeshComp->AttachToComponent(this, FAttachmentTransformRules::SnapToTargetNotIncludingScale);
		GhostMeshComp->RegisterComponent();
	}
}

void USuturingController::InitController()
{
	if (!Thread) {
		SubsystemInstance->LogToUnrealAndImstk("No PBDThread attached to SuturingController", FColor::Red);
		return;
	}

	Super::InitController();

	UControllerTool* NewTool = NewObject<UControllerNeedleTool>();
	EControllerObjectType ObjectType = NewTool->Init(this, FControllerToolFilter());
	ControllerTools.Add(NewTool);

	// Create the needle object
	{
		Needle = std::make_shared<imstk::RigidObject2>();
		FString ContentDir = IPluginManager::Get().FindPlugin((TEXT("Imstk")))->GetContentDir();
		auto SutureMesh = imstk::MeshIO::read<imstk::SurfaceMesh>(std::string(TCHAR_TO_UTF8(*(ContentDir + "/Models/Needles/c6_suture.stl"))));
		auto SutureLineMesh = imstk::MeshIO::read<imstk::LineMesh>(std::string(TCHAR_TO_UTF8(*(ContentDir + "/Models/Needles/c6_suture_hull.vtk"))));

		SutureMesh->scale(UMathUtil::ToImstkVec3d(GetComponentScale(), false), Geometry::TransformType::ApplyToData);
		SutureLineMesh->scale(UMathUtil::ToImstkVec3d(GetComponentScale(), false), Geometry::TransformType::ApplyToData);

		const Mat4d Rot = mat4dRotation(Rotd(-PI_2, Vec3d(0.0, 1.0, 0.0))) *
			mat4dRotation(Rotd(-0.6, Vec3d(1.0, 0.0, 0.0)));
		SutureMesh->transform(Rot, Geometry::TransformType::ApplyToData);
		SutureLineMesh->transform(Rot, Geometry::TransformType::ApplyToData);

		Needle->setVisualGeometry(SutureMesh);
		Needle->setCollidingGeometry(SutureLineMesh);
		Needle->setPhysicsGeometry(SutureLineMesh);
		Needle->setPhysicsToVisualMap(std::make_shared<imstk::IsometricMap>(SutureLineMesh, SutureMesh));

		std::shared_ptr<RigidBodyModel2> RbdModel = std::make_shared<RigidBodyModel2>();
		RbdModel->getConfig()->m_gravity = Vec3d::Zero();
		RbdModel->getConfig()->m_maxNumIterations = 5;
		Needle->setDynamicalModel(RbdModel);

		Needle->getRigidBody()->m_mass = 1.0;
		Needle->getRigidBody()->m_intertiaTensor = Mat3d::Identity() * 10000.0;
		Needle->getRigidBody()->m_initPos = Vec3d(0.0, 0.0, 0.0);

		Needle->addComponent<imstk::Needle>();
	}


	// Create unreal visuals for the needle
	{
		std::shared_ptr<imstk::SurfaceMesh> NeedleVisGeom = std::dynamic_pointer_cast<imstk::SurfaceMesh>(Needle->getVisualGeometry());
		NeedleVisGeom->computeVertexNormals();
		imstk::VecDataArray<double, 3>& ImstkNorms = *NeedleVisGeom->getVertexNormals();

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
		Verts = UMathUtil::ToUnrealFVecArray(NeedleVisGeom->getVertexPositions(), true);

		Indices = UMathUtil::ToUnrealIntArray(NeedleVisGeom->getTriangleIndices());

		// Create the mesh sections on the procedural meshes
		ProcMeshComp->CreateMeshSection_LinearColor(0, Verts, Indices, Normals, UV0, VertColors, Tangents, false);
		if (bForceTool) {
			GhostMeshComp->CreateMeshSection_LinearColor(0, Verts, Indices, Normals, UV0, VertColors, Tangents, false);
			if (GhostMaterial) {
				auto* MaterialInstance = UMaterialInstanceDynamic::Create(GhostMaterial, GhostMaterial);
				GhostMeshComp->SetMaterial(0, MaterialInstance);
			}
		}
	}

	// Fix the nodes on the string that will move with the needle
	Thread->PbdObject->getPbdBody()->fixedNodeIds.push_back(0);
	Thread->PbdObject->getPbdBody()->fixedNodeIds.push_back(1);

	Needle->getRigidBody()->setInitPos(UMathUtil::ToImstkVec3d(GetComponentToWorld().GetLocation(), true));

	Needle->getRigidBody()->m_intertiaTensor = imstk::Mat3d::Identity() * InertiaTensorMultiplier;
	Needle->getRigidBody()->m_mass = Mass;

	ToolObj = Needle;

	SubsystemInstance->ActiveScene->addSceneObject(ToolObj);

	SubsystemInstance->LogToUnrealAndImstk("Initialized: " + GetOwner()->GetFName().ToString(), FColor::Green);

	Super::bIsInitialized = true;
}

void USuturingController::SetThread(UPBDThread* Input)
{
	Thread = Input;
}


void USuturingController::MoveNeedleToLocation(FVector Location, FQuat Orientation)
{
	UpdateImstkPosRot(Location, Orientation);
	UpdateUnrealPosRot();
}

void USuturingController::UpdateImstkPosRot(FVector Location, FQuat Orientation) {
	if (!bForceTool) {
		Needle->getRigidBody()->m_orientation = new imstk::Quatd(UMathUtil::ToImstkQuat(Orientation));
		Needle->getRigidBody()->m_pos = new imstk::Vec3d(UMathUtil::ToImstkVec3d(Location, true));
		return;
	}

	if (bIgnoreAngularForce) {
		imstk::Vec3d fS = (UMathUtil::ToImstkVec3d(Location, true) - Needle->getRigidBody()->getPosition()) * SpringForce; // Spring force
		imstk::Vec3d fD = -Needle->getRigidBody()->getVelocity() * DamperForce; // Spring damping
		(*Needle->getRigidBody()->m_force) += (fS + fD);

		Needle->getRigidBody()->m_orientation = new imstk::Quatd(UMathUtil::ToImstkQuat(Orientation));
	}
	else {
		GhostMeshComp->SetWorldLocation(Location);
		GhostMeshComp->SetWorldRotation(Orientation);

		// From imstkRigidObjectController
		const imstk::Vec3d& CurrPos = Needle->getRigidBody()->getPosition();
		const imstk::Quatd& CurrOrientation = Needle->getRigidBody()->getOrientation();
		const imstk::Vec3d& CurrVelocity = Needle->getRigidBody()->getVelocity();
		const imstk::Vec3d& CurrAngularVelocity = Needle->getRigidBody()->getAngularVelocity();
		imstk::Vec3d& CurrForce = *Needle->getRigidBody()->m_force;
		imstk::Vec3d& CurrTorque = *Needle->getRigidBody()->m_torque;

		const imstk::Vec3d& DevicePos = UMathUtil::ToImstkVec3d(Location, true);
		const imstk::Quatd& DeviceOrientation = UMathUtil::ToImstkQuat(Orientation);
		const imstk::Vec3d& DeviceOffset = imstk::Vec3d(0.0, 0.0, 0.0);

		// If using critical damping automatically compute kd
		{
			//const double Mass = ToolObj->getRigidBody()->getMass();
			const double MaxLinearKs = imstk::Vec3d(LinearKs, LinearKs, LinearKs).maxCoeff();
			LinearKd = 2.0 * std::sqrt(Mass * MaxLinearKs);

			const imstk::Mat3d Inertia = Needle->getRigidBody()->getIntertiaTensor();
			// Currently kd is not a 3d vector though it could be.
			// So here we make an approximation. Either:
			//  - Use one colums eigenvalue (maxCoeff)
			//  - cbrt(eigenvalue0*eigenvalue1*eigenvalue2). (det)
			// Both may behave weird on anistropic Inertia tensors
			//const double InertiaScale = Inertia.eigenvalues().real().maxCoeff();
			const double InertiaScale = std::cbrt(Inertia.determinant());
			const double MaxAngularKs = imstk::Vec3d(AngularKs, AngularKs, AngularKs).maxCoeff();
			AngularKd = 2.0 * std::sqrt(InertiaScale * MaxAngularKs);
		}

		// If kd > 2 * sqrt(Mass * ks); The system is overdamped (may be intentional)
		// If kd < 2 * sqrt(Mass * ks); The system is underdamped (never intended)

		// Uses non-relative force
		{
			// Compute force
			imstk::Vec3d SForce = imstk::Vec3d(LinearKs, LinearKs, LinearKs).cwiseProduct(DevicePos - CurrPos - DeviceOffset);
			imstk::Vec3d DForce = LinearKd * (-CurrVelocity - CurrAngularVelocity.cross(DeviceOffset));
			imstk::Vec3d Force = SForce + DForce;

			// Computer torque
			const imstk::Quatd Dq = DeviceOrientation * CurrOrientation.inverse();
			const imstk::Rotd  AngleAxes = imstk::Rotd(Dq);
			AngularSpringForce = DeviceOffset.cross(Force) + imstk::Vec3d(AngularKs, AngularKs, AngularKs).cwiseProduct(AngleAxes.axis() * AngleAxes.angle());
			AngularDamperForce = AngularKd * -CurrAngularVelocity;
			imstk::Vec3d Torque = AngularSpringForce + AngularDamperForce;

			CurrForce += Force * ForceScaling;
			CurrTorque += Torque * ForceScaling;
		}
	}

	Needle->updatePhysicsGeometry();
	// Move Thread to follow the needle
	if (!NeedleLineMesh)
		NeedleLineMesh = std::dynamic_pointer_cast<imstk::LineMesh>(Needle->getPhysicsGeometry());
	Thread->MoveVertexToLocation(0, UMathUtil::ToUnrealFVec(NeedleLineMesh->getVertexPosition(1), true));
	Thread->MoveVertexToLocation(1, UMathUtil::ToUnrealFVec(NeedleLineMesh->getVertexPosition(0), true));
}

void USuturingController::UpdateUnrealPosRot()
{
	SetWorldLocationAndRotation(UMathUtil::ToUnrealFVec(Needle->getRigidBody()->getPosition(), true), UMathUtil::ToUnrealFQuat(Needle->getRigidBody()->getOrientation()));
}

void USuturingController::Stitch()
{
	SutureInteraction->stitch();
}

void USuturingController::SetNeedleInteraction(std::shared_ptr<NeedleInteraction> Input)
{
	SutureInteraction = Input;
}

void USuturingController::UnInit()
{
	Super::UnInit();
	Needle.reset();
	SutureInteraction.reset();
	NeedleLineMesh.reset();
}


