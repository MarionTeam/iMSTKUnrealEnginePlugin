// Fill out your copyright notice in the Description page of Project Settings.

#include "CustomController.h"
#include "MathUtil.h"
#include "ImstkSubsystem.h"
#include "RBDModel.h"
#include "imstkLineMesh.h"
#include "imstkRigidBodyModel2.h"
#include "imstkRbdConstraint.h"
#include "imstkCollisionUtils.h"
#include "imstkGeometryUtilities.h"
#include "imstkPbdModel.h"
#include "Materials/MaterialInstanceDynamic.h"

void UCustomController::PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent)
{
	FName PropertyName = (PropertyChangedEvent.Property != NULL) ? PropertyChangedEvent.Property->GetFName() : NAME_None;

	if (PropertyName == GET_MEMBER_NAME_CHECKED(UCustomController, Preset)) {
		switch (Preset)
		{
		case 0:
			ToolGeomFilter.GeomType = EGeometryType::Capsule;
			ToolGeomFilter.CapsuleStruct.Radius = 12.5;
			ToolGeomFilter.CapsuleStruct.Length = 50;
			ControllerFilters.Empty();
			ControllerFilters.Add(FControllerToolFilter());
			ControllerFilters[0].ToolType = EToolType::CollidingTool;
			break;
		case 1:
			ToolGeomFilter.GeomType = EGeometryType::Capsule;
			ToolGeomFilter.CapsuleStruct.Radius = 12.5;
			ToolGeomFilter.CapsuleStruct.Length = 50;
			ControllerFilters.Empty();
			ControllerFilters.Add(FControllerToolFilter());
			ControllerFilters[0].ToolType = EToolType::GraspingTool;
			bForceTool = true;
			break;
		case 2:
			ToolGeomFilter.GeomType = EGeometryType::SurfaceMesh;
			ControllerFilters.Empty();
			ControllerFilters.Add(FControllerToolFilter());
			ControllerFilters[0].ToolType = EToolType::CuttingTool;
			bForceTool = false;
			break;
		case 3:
			ToolGeomFilter.GeomType = EGeometryType::LineMesh;
			ToolGeomFilter.LineMeshStruct.Vertices.Empty();
			ToolGeomFilter.LineMeshStruct.Vertices.Add(FVector(0, 0, 0));
			ToolGeomFilter.LineMeshStruct.Vertices.Add(FVector(0, 0, 50));
			ControllerFilters.Empty();
			ControllerFilters.Add(FControllerToolFilter());
			ControllerFilters[0].ToolType = EToolType::StitchingTool;
			bForceTool = false;
			break;
		case 4:
			ToolGeomFilter.GeomType = EGeometryType::SurfaceMesh;
			ControllerFilters.Empty();
			ControllerFilters.Add(FControllerToolFilter());
			ControllerFilters[0].ToolType = EToolType::LevelSetTool;
			bForceTool = true;
			SpringForce = 1000;
			DamperForce = 10;
			bIgnoreAngularForce = true;
			break;
		case 5:
			ToolGeomFilter.GeomType = EGeometryType::Plane;
			ControllerFilters.Empty();
			ControllerFilters.Add(FControllerToolFilter());
			ControllerFilters[0].ToolType = EToolType::TetrahedralCuttingTool;
			bForceTool = false;
			break;
		case 6:
			ToolGeomFilter.GeomType = EGeometryType::Capsule;
			ToolGeomFilter.CapsuleStruct.Radius = 12.5;
			ToolGeomFilter.CapsuleStruct.Length = 50;
			ControllerFilters.Empty();
			ControllerFilters.Add(FControllerToolFilter());
			ControllerFilters[0].ToolType = EToolType::BurningTool;
			bForceTool = false;
			break;
		default:
			return;
		}
	}
}
UCustomController::UCustomController() : UImstkController()
{
	ToolGeomFilter.GeomType = EGeometryType::Capsule;
	ToolGeomFilter.CapsuleStruct.Radius = 12.5;
	ToolGeomFilter.CapsuleStruct.Length = 50;
}

// Called before Begin Play
void UCustomController::InitializeComponent()
{
	Super::InitializeComponent();

	// Turn off ticking for this component
	if (GetWorld() && GetWorld()->GetGameInstance())
		this->SetComponentTickEnabled(false);
}

void UCustomController::InitController()
{
	Super::InitController();

	std::shared_ptr<imstk::Geometry> ToolGeom = ToolGeomFilter.Init(this);

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
	else
		ToolGeom->scale(UMathUtil::ToImstkVec3d(GetComponentScale(), false), imstk::Geometry::TransformType::ApplyToData);

	for (auto ToolFilter : ControllerFilters) {
		UControllerTool* NewTool = ToolFilter.CreateTool();
		EControllerObjectType ObjectType = NewTool->Init(this, ToolFilter);

		// Skip this controller if error in init
		if (ObjectType == EControllerObjectType::Null)
			continue;
		else if (!PbdToolObj && ObjectType == EControllerObjectType::PbdToolObject) {
			// Currently tools shouldnt really be plane so convert to surface mesh
			if (std::shared_ptr<imstk::Plane> PlaneGeom = std::dynamic_pointer_cast<imstk::Plane>(ToolGeom)) {
				std::shared_ptr<imstk::SurfaceMesh> SurfGeom = imstk::GeometryUtils::toSurfaceMesh(PlaneGeom);
				ToolGeom = SurfGeom;
			}

			std::shared_ptr<imstk::PbdModel> PbdModel = SubsystemInstance->PbdModel;
			PbdToolObj = std::make_shared<imstk::PbdObject>(TCHAR_TO_UTF8(*this->GetName()));
			ToolObj = PbdToolObj;
			ToolObj->setDynamicalModel(PbdModel);
			ToolObj->setVisualGeometry(ToolGeom);
			ToolObj->setCollidingGeometry(ToolGeom);
			ToolObj->setPhysicsGeometry(ToolGeom);


			PbdToolObj->getPbdBody()->setRigid(
				imstk::Vec3d(0.0, 0.0, 0.0),         // Position
				Mass,                                // Mass
				imstk::Quatd::Identity(),            // Orientation
				imstk::Mat3d::Identity() * 1);       // Inertia

			(*PbdToolObj->getPbdBody()->vertices)[0] = UMathUtil::ToImstkVec3d(GetComponentLocation(), true);
			if (MeshComp)
				(*PbdToolObj->getPbdBody()->orientations)[0] = UMathUtil::ToImstkQuat(MeshComp->GetComponentRotation().Quaternion());
			else
				(*PbdToolObj->getPbdBody()->orientations)[0] = UMathUtil::ToImstkQuat(GetComponentRotation().Quaternion());
		}
		else if (!RigidToolObj && ObjectType == EControllerObjectType::RigidToolObject) {
			ToolObj = std::make_shared<imstk::RigidObject2>(TCHAR_TO_UTF8(*this->GetName()));
			ToolObj->setVisualGeometry(ToolGeom);
			ToolObj->setCollidingGeometry(ToolGeom);
			ToolObj->setPhysicsGeometry(ToolGeom);

			// Configure the model
			std::shared_ptr<imstk::RigidBodyModel2> RbdModel = std::make_shared<imstk::RigidBodyModel2>();
			RbdModel->getConfig()->m_gravity = imstk::Vec3d::Zero();
			RbdModel->getConfig()->m_maxNumIterations = MaxNumIterations;
			RbdModel->getConfig()->m_velocityDamping = VelocityDamping;
			RbdModel->getConfig()->m_angularVelocityDamping = AngularVelocityDamping;
			RbdModel->getConfig()->m_maxNumConstraints = MaxNumConstraints;

			RigidToolObj = std::dynamic_pointer_cast<imstk::RigidObject2>(ToolObj);

			RigidToolObj->setDynamicalModel(RbdModel);

			RigidToolObj->getRigidBody()->m_mass = Mass;
			RigidToolObj->getRigidBody()->m_intertiaTensor = imstk::Mat3d::Identity() * InertiaTensorMultiplier;
			RigidToolObj->getRigidBody()->setInitPos(UMathUtil::ToImstkVec3d(GetComponentLocation(), true));

			if (MeshComp)
				RigidToolObj->getRigidBody()->setInitOrientation(UMathUtil::ToImstkQuat(MeshComp->GetComponentRotation().Quaternion()));
			else
				RigidToolObj->getRigidBody()->setInitOrientation(UMathUtil::ToImstkQuat(GetComponentRotation().Quaternion()));

		}
		if (NewTool)
			ControllerTools.Add(NewTool);
	}

	if (bForceTool && GhostMaterial && GhostMeshes.Num() > 0) {
		for (auto GhostMeshComp : GhostMeshes) {
			auto* MaterialInstance = UMaterialInstanceDynamic::Create(GhostMaterial, GhostMaterial);
			GhostMeshComp->SetMaterial(0, MaterialInstance);
		}
	}


	SubsystemInstance->ActiveScene->addSceneObject(ToolObj);
	SubsystemInstance->LogToUnrealAndImstk("Initialized: " + GetFName().ToString(), FColor::Green);

	if (!PbdToolObj && !RigidToolObj)
		SubsystemInstance->LogToUnrealAndImstk("Error initializing " + GetFName().ToString(), FColor::Red);

	Super::bIsInitialized = true;
	if (PbdToolObj && RigidToolObj)
		SubsystemInstance->LogToUnrealAndImstk("Warning: Both a Pbd Object and Rigid object were created on " + GetFName().ToString() + ". This can result in unexpected behavior.", FColor::Yellow);

	return;
}

FVector UCustomController::UpdateImstkPosRot(FVector WorldPos, FQuat Orientation, FVector WorldDir, UDynamicalModel* PlaneActor)
{
	imstk::Vec3d Position = UMathUtil::ToImstkVec3d(WorldPos, true);
	if (!bForceTool) {
		if (PlaneActor) {
			std::shared_ptr<imstk::Plane> Plane = std::dynamic_pointer_cast<imstk::Plane>(PlaneActor->GetImstkGeometry());

			if (Plane) {
				imstk::Vec3d IntersectPoint = imstk::Vec3d::Zero();
				if (imstk::CollisionUtils::testRayToPlane(UMathUtil::ToImstkVec3d(WorldPos, true), UMathUtil::ToImstkVec3d(WorldDir, true), Plane->getPosition(), Plane->getNormal(), IntersectPoint))
				{
					Position = IntersectPoint;
				}
				else {
					// No hit for ray
					return FVector::ZeroVector;
				}
			}
			else {
				//ERROR

				Super::bIsInitialized = false;
				return FVector::ZeroVector;
			}
		}

		if (RigidToolObj) {
			RigidToolObj->getRigidBody()->m_orientation = new imstk::Quatd(UMathUtil::ToImstkQuat(Orientation));
			RigidToolObj->getRigidBody()->m_pos = new imstk::Vec3d(Position);
		}
		else if (PbdToolObj) {
			(*PbdToolObj->getPbdBody()->vertices)[0] = Position;
			(*PbdToolObj->getPbdBody()->orientations)[0] = UMathUtil::ToImstkQuat(Orientation);
		}
	}
	else
	{
		if (GhostSceneComp) {
			GhostSceneComp->SetWorldLocation(WorldPos);
			GhostSceneComp->SetWorldRotation(Orientation);
		}

		if (bIgnoreAngularForce) {
			if (RigidToolObj) {
				imstk::Vec3d fS = (UMathUtil::ToImstkVec3d(WorldPos, true) - RigidToolObj->getRigidBody()->getPosition()) * SpringForce; // Spring force
				imstk::Vec3d fD = -RigidToolObj->getRigidBody()->getVelocity() * DamperForce; // Spring damping
				(*RigidToolObj->getRigidBody()->m_force) += (fS + fD);

				RigidToolObj->getRigidBody()->m_orientation = new imstk::Quatd(UMathUtil::ToImstkQuat(Orientation));
			}
			else if (PbdToolObj) {

				imstk::Vec3d fS = (UMathUtil::ToImstkVec3d(WorldPos, true) - (*PbdToolObj->getPbdBody()->vertices)[0]) * SpringForce; // Spring force
				imstk::Vec3d fD = -(*PbdToolObj->getPbdBody()->velocities)[0] * DamperForce; // Spring damping
				(PbdToolObj->getPbdBody()->externalForce) += (fS + fD);
				(*PbdToolObj->getPbdBody()->orientations)[0] = imstk::Quatd(UMathUtil::ToImstkQuat(Orientation));
			}
		}
		else {
			const imstk::Vec3d& CurrPos = RigidToolObj->getRigidBody()->getPosition();
			const imstk::Quatd& CurrOrientation = RigidToolObj->getRigidBody()->getOrientation();
			const imstk::Vec3d& CurrVelocity = RigidToolObj->getRigidBody()->getVelocity();
			const imstk::Vec3d& CurrAngularVelocity = RigidToolObj->getRigidBody()->getAngularVelocity();
			imstk::Vec3d& CurrForce = *RigidToolObj->getRigidBody()->m_force;
			imstk::Vec3d& CurrTorque = *RigidToolObj->getRigidBody()->m_torque;

			const imstk::Vec3d& DevicePos = UMathUtil::ToImstkVec3d(WorldPos, true);
			const imstk::Quatd& DeviceOrientation = UMathUtil::ToImstkQuat(Orientation);
			const imstk::Vec3d& DeviceOffset = imstk::Vec3d(0.0, 0.0, 0.0);

			// If using critical damping automatically compute kd
			{
				//const double Mass = ToolObj->getRigidBody()->getMass();
				const double MaxLinearKs = UMathUtil::ToImstkVec3d(LinearKs, true).maxCoeff();
				LinearKd = 2.0 * std::sqrt(Mass * MaxLinearKs);

				const imstk::Mat3d Inertia = RigidToolObj->getRigidBody()->getIntertiaTensor();
				// Currently kd is not a 3d vector though it could be.
				// So here we make an approximation. Either:
				//  - Use one colums eigenvalue (maxCoeff)
				//  - cbrt(eigenvalue0*eigenvalue1*eigenvalue2). (det)
				// Both may behave weird on anistropic Inertia tensors
				//const double InertiaScale = Inertia.eigenvalues().real().maxCoeff();
				const double InertiaScale = std::cbrt(Inertia.determinant());
				const double MaxAngularKs = UMathUtil::ToImstkVec3d(AngularKs, true).maxCoeff();
				AngularKd = 2.0 * std::sqrt(InertiaScale * MaxAngularKs);
			}

			// If kd > 2 * sqrt(Mass * ks); The system is overdamped (may be intentional)
			// If kd < 2 * sqrt(Mass * ks); The system is underdamped (never intended)

			// Uses non-relative force
			{
				// Compute force
				imstk::Vec3d SForce = UMathUtil::ToImstkVec3d(LinearKs, true).cwiseProduct(DevicePos - CurrPos - DeviceOffset);
				imstk::Vec3d DForce = LinearKd * (-CurrVelocity - CurrAngularVelocity.cross(DeviceOffset));
				imstk::Vec3d Force = SForce + DForce;

				// Computer torque
				const imstk::Quatd Dq = DeviceOrientation * CurrOrientation.inverse();
				const imstk::Rotd  AngleAxes = imstk::Rotd(Dq);
				AngularSpringForce = DeviceOffset.cross(Force) + UMathUtil::ToImstkVec3d(AngularKs, true).cwiseProduct(AngleAxes.axis() * AngleAxes.angle());
				AngularDamperForce = AngularKd * -CurrAngularVelocity;
				imstk::Vec3d Torque = AngularSpringForce + AngularDamperForce;

				CurrForce += Force * ForceScale;
				CurrTorque += Torque * ForceScale;
			}
		}
	}

	if (GEngine && bPrintImstkPos) {
		if (RigidToolObj)
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, UMathUtil::ToUnrealFVec(RigidToolObj->getRigidBody()->getPosition(), true).ToString());
		else if (PbdToolObj)
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, UMathUtil::ToUnrealFVec((*PbdToolObj->getPbdBody()->vertices)[0], true).ToString());
	}

	return UMathUtil::ToUnrealFVec(Position, true);
}

void UCustomController::UpdateUnrealPosRot()
{
	// Since mesh comp and controller can have different orientations, only orient the controller to update and keep rotation offset for the mesh component
	if (MeshComp && RigidToolObj)
		MeshComp->SetWorldLocationAndRotation(UMathUtil::ToUnrealFVec(RigidToolObj->getRigidBody()->getPosition(), true), UMathUtil::ToUnrealFQuat(RigidToolObj->getRigidBody()->getOrientation()).Rotator());
	else if (MeshComp && PbdToolObj)
		MeshComp->SetWorldLocationAndRotation(UMathUtil::ToUnrealFVec((*PbdToolObj->getPbdBody()->vertices)[0], true), UMathUtil::ToUnrealFQuat((*PbdToolObj->getPbdBody()->orientations)[0]));
	else if (RigidToolObj)
		SetWorldLocationAndRotation(UMathUtil::ToUnrealFVec(RigidToolObj->getRigidBody()->getPosition(), true), UMathUtil::ToUnrealFQuat(RigidToolObj->getRigidBody()->getOrientation()));
	else if (PbdToolObj)
		SetWorldLocationAndRotation(UMathUtil::ToUnrealFVec((*PbdToolObj->getPbdBody()->vertices)[0], true), UMathUtil::ToUnrealFQuat((*PbdToolObj->getPbdBody()->orientations)[0]));
}

void UCustomController::MoveControllerToLocation(FVector Location, FQuat Orientation, bool bUpdateUnrealPosRot)
{
	if (!Super::bIsInitialized)
		return;

	UpdateImstkPosRot(Location, Orientation);
	if (bUpdateUnrealPosRot)
		UpdateUnrealPosRot();
}

FVector UCustomController::MoveControllerToRaycastOnPlane(FVector RayStart, FVector RayDir, FQuat Orientation, UDynamicalModel* PlaneActor, bool bUpdateUnrealPosRot)
{
	FVector ImstkPos = UpdateImstkPosRot(RayStart, Orientation, RayDir, PlaneActor);
	if (bUpdateUnrealPosRot)
		UpdateUnrealPosRot();

	return ImstkPos;
}

FVector UCustomController::GetControlleriMSTKPosition()
{
	if (RigidToolObj)
		return UMathUtil::ToUnrealFVec(RigidToolObj->getRigidBody()->getPosition(), true);
	else if (PbdToolObj)
		return UMathUtil::ToUnrealFVec((*PbdToolObj->getPbdBody()->vertices)[0], true);
	else {
		SubsystemInstance->LogToUnrealAndImstk("Tool " + GetFName().ToString() + " generated no tool object.", FColor::Red);
		return FVector::Zero();
	}
}

void UCustomController::SetGhostComponents(USceneComponent* SceneComponent, TArray<UStaticMeshComponent*> StaticMeshComponents)
{
	GhostSceneComp = SceneComponent;
	GhostMeshes = StaticMeshComponents;
}

void UCustomController::UnInit()
{
	Super::UnInit();
	RigidToolObj.reset();
}
