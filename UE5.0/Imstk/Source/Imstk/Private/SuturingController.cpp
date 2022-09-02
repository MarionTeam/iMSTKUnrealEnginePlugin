// Fill out your copyright notice in the Description page of Project Settings.


#include "SuturingController.h"
#include "imstkPbdModel.h"
#include "MathUtil.h"
#include "Materials/MaterialInstanceDynamic.h"



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
		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "No PBDThread attached to SuturingController");
		UE_LOG(LogTemp, Error, TEXT("No PBDThread attached to SuturingController"));
		return;
	}

	Super::InitController();
	Needle = std::make_shared<NeedleObject>(SubsystemInstance->RigidBodyModel, this);
	Needle->setForceThreshold(ForceThreshold);
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
	std::dynamic_pointer_cast<imstk::PbdModel>(Thread->PbdObject->getDynamicalModel())->getConfig()->m_fixedNodeIds.push_back(0);
	std::dynamic_pointer_cast<imstk::PbdModel>(Thread->PbdObject->getDynamicalModel())->getConfig()->m_fixedNodeIds.push_back(1);
	Needle->getRigidBody()->setInitPos(UMathUtil::ToImstkVec3d(GetComponentToWorld().GetLocation(), true));

	Needle->getRigidBody()->m_intertiaTensor = imstk::Mat3d::Identity() * InertiaTensorMultiplier;
	Needle->getRigidBody()->m_mass = Mass;

	ToolObj = Needle;
	SubsystemInstance->ActiveScene->addSceneObject(ToolObj);

	Super::bIsInitialized = true;
}

void USuturingController::SetThread(UPBDThread* Input)
{
	Thread = Input;
}


//
//
// TODO: many of these functions are the same as custom controller (maybe make it a child of that instead)
//
//
void USuturingController::MoveNeedleToLocation(FVector Location, FQuat Orientation)
{
	UpdateImstkPosRot(Location, Orientation);
	UpdateUnrealPosRot();
}

void USuturingController::UpdateImstkPosRot(FVector Location, FQuat Orientation) {
	if (!bForceTool) {
		Needle->getRigidBody()->m_orientation = new imstk::Quatd(UMathUtil::ToImstkQuat(Orientation));
		Needle->getRigidBody()->m_pos = new imstk::Vec3d(UMathUtil::ToImstkVec3d(Location, true));
	}
	else {
		GhostMeshComp->SetWorldLocation(Location);
		GhostMeshComp->SetWorldRotation(Orientation);
		

		// From imstkRigidObjectController
		const imstk::Vec3d& currPos = Needle->getRigidBody()->getPosition();
		const imstk::Quatd& currOrientation = Needle->getRigidBody()->getOrientation();
		const imstk::Vec3d& currVelocity = Needle->getRigidBody()->getVelocity();
		const imstk::Vec3d& currAngularVelocity = Needle->getRigidBody()->getAngularVelocity();
		imstk::Vec3d& currForce = *Needle->getRigidBody()->m_force;
		imstk::Vec3d& currTorque = *Needle->getRigidBody()->m_torque;

		const imstk::Vec3d& devicePos = UMathUtil::ToImstkVec3d(Location, true);
		const imstk::Quatd& deviceOrientation = UMathUtil::ToImstkQuat(Orientation);
		const imstk::Vec3d& deviceOffset = imstk::Vec3d(0.0, 0.0, 0.0);

		imstk::Vec3d  m_linearKs = imstk::Vec3d(LinearKs, LinearKs, LinearKs); ///< Spring coefficient, linear
		imstk::Vec3d  m_angularKs = imstk::Vec3d(AngularKs, AngularKs, AngularKs);       ///< Spring coefficient, rotational
		//{
		//	const double mass = Needle->getRigidBody()->getMass();
		//	const double linearKs = m_linearKs.maxCoeff();
		//	LinearKd = 2.0 * std::sqrt(mass * linearKs);

		//	const imstk::Mat3d inertia = Needle->getRigidBody()->getIntertiaTensor();
		//	// Currently kd is not a 3d vector though it could be.
		//	// So here we make an approximation. Either:
		//	//  - Use one colums eigenvalue (maxCoeff)
		//	//  - cbrt(eigenvalue0*eigenvalue1*eigenvalue2). (det)
		//	// Both may behave weird on anistropic inertia tensors
		//	//const double inertiaScale = inertia.eigenvalues().real().maxCoeff();
		//	const double inertiaScale = std::cbrt(inertia.determinant());
		//	const double angularKs = m_angularKs.maxCoeff();
		//	AngularKd = 2.0 * std::sqrt(inertiaScale * angularKs);
		//}

		// If kd > 2 * sqrt(mass * ks); The system is overdamped (may be intentional)
		// If kd < 2 * sqrt(mass * ks); The system is underdamped (never intended)

		// Uses non-relative force
		{
			// Linear spring force and damper force
			imstk::Vec3d m_fS = imstk::Vec3d::Zero();
			imstk::Vec3d m_fD = imstk::Vec3d::Zero();

			// Angular spring force and damper force
			imstk::Vec3d m_tS = imstk::Vec3d::Zero();
			imstk::Vec3d m_tD = imstk::Vec3d::Zero();

			// Compute force
			m_fS = m_linearKs.cwiseProduct(devicePos - currPos - deviceOffset);
			m_fD = LinearKd * (-currVelocity - currAngularVelocity.cross(deviceOffset));
			imstk::Vec3d force = m_fS + m_fD;

			// Compute torque
			const imstk::Quatd dq = deviceOrientation * currOrientation.inverse();
			const imstk::Rotd  angleAxes = imstk::Rotd(dq);
			m_tS = deviceOffset.cross(force) + m_angularKs.cwiseProduct(angleAxes.axis() * angleAxes.angle());
			m_tD = AngularKd * -currAngularVelocity;
			imstk::Vec3d torque = m_tS + m_tD;

			currForce += (force * 0.00005);
			currTorque += (torque * 0.00005);
		}

		// TODO: update this to the force movement version in suturing controller
		//imstk::Vec3d fS = (UMathUtil::ToImstkVec3d(Location, true) - Needle->getRigidBody()->getPosition()) * SpringForce; // Spring force
		//imstk::Vec3d fD = -Needle->getRigidBody()->getVelocity() * SpringDamping; // Spring damping
		//(*Needle->getRigidBody()->m_force) += (fS + fD);

		//Needle->getRigidBody()->m_orientation = new imstk::Quatd(UMathUtil::ToImstkQuat(Orientation));
		
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
	ProcMeshComp->SetWorldLocation(UMathUtil::ToUnrealFVec(Needle->getRigidBody()->getPosition(), true));
	ProcMeshComp->SetWorldRotation(UMathUtil::ToUnrealFQuat(Needle->getRigidBody()->getOrientation()));
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


