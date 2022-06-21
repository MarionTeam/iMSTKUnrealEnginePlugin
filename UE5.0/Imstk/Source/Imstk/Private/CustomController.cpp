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

#include "Kismet/GameplayStatics.h"
#include "GameFramework/PlayerController.h"

#include "DrawDebugHelpers.h"

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
	// Create a line mesh tool that can be controlled
	std::shared_ptr<imstk::Geometry> ToolGeom;

	if (ToolGeometry == EToolGeometry::LineMeshTool) {
		ToolGeom = std::make_shared<imstk::LineMesh>();
		std::shared_ptr<imstk::VecDataArray<double, 3>> VertPtr = std::make_shared<imstk::VecDataArray<double, 3>>(2);
		(*VertPtr)[0] = UMathUtil::ToImstkVec3(Vertex1, true);
		(*VertPtr)[1] = UMathUtil::ToImstkVec3(Vertex2, true);
		std::shared_ptr<imstk::VecDataArray<int, 2>> IndicesPtr = std::make_shared<imstk::VecDataArray<int, 2>>(1);
		(*IndicesPtr)[0] = imstk::Vec2i(0, 1);
		std::dynamic_pointer_cast<imstk::LineMesh>(ToolGeom)->initialize(VertPtr, IndicesPtr);
	}
	else if (ToolGeometry == EToolGeometry::SphereTool) {
		// TODO: Sphere for vertex grasp not working
		std::shared_ptr <imstk::Sphere> SphereGeom = std::make_shared<imstk::Sphere>();
		SphereGeom->setRadius(Radius / UMathUtil::GetScale());

		ToolGeom = SphereGeom;
	}
	else if (ToolGeometry == EToolGeometry::CapsuleTool) {
		std::shared_ptr <imstk::Capsule> CapsuleGeom = std::make_shared<imstk::Capsule>();
		CapsuleGeom->setRadius(Radius / UMathUtil::GetScale());
		CapsuleGeom->setLength(Length / UMathUtil::GetScale());
		CapsuleGeom->setPosition(UMathUtil::ToImstkVec3(GeometryOffset, true));
		ToolGeom = CapsuleGeom;
	}
	else if (ToolGeometry == EToolGeometry::SurfaceMeshTool) {
		// TODO: Maybe make a geom utils for this (used in geomfilter as well)
		std::shared_ptr<imstk::SurfaceMesh> MeshGeom = std::make_shared<imstk::SurfaceMesh>();
		// TODO: Add check if no static mesh comp
		FPositionVertexBuffer* VertexBuffer = &MeshComp->GetStaticMesh()->GetRenderData()->LODResources[0].VertexBuffers.PositionVertexBuffer;
		FRawStaticIndexBuffer* IndexBuffer = &MeshComp->GetStaticMesh()->GetRenderData()->LODResources[0].IndexBuffer;

		// Get vertices and indices in the mesh and set those values in the imstk mesh
		TArray<FVector> Vertices;
		for (uint32 i = 0; i < VertexBuffer->GetNumVertices(); i++) {
			Vertices.Add(FVector(VertexBuffer->VertexPosition(i)));
		}

		TArray<int> Indices;
		for (int32 i = 0; i < IndexBuffer->GetNumIndices(); i++) {
			Indices.Add(IndexBuffer->GetIndex(i));
		}

		MeshGeom->initialize(UMathUtil::ToImstkVecDataArray3d(Vertices, true), UMathUtil::ToImstkVecDataArray3i(Indices));

		MeshGeom->scale(UMathUtil::ToImstkVec3(MeshComp->GetComponentScale(), false), imstk::Geometry::TransformType::ApplyToData);
		//MeshGeom->rotate(UMathUtil::ToImstkQuat(MeshComp->GetComponentRotation().Quaternion()), imstk::Geometry::TransformType::ApplyToData);
		//MeshGeom->translate(UMathUtil::ToImstkVec3(MeshComp->GetComponentLocation(), true), imstk::Geometry::TransformType::ApplyToData);
		MeshGeom->updatePostTransformData();
		ToolGeom = MeshGeom;

		/*std::shared_ptr<imstk::Plane> PlaneGeom = std::make_shared<imstk::Plane>();
		PlaneGeom->setNormal(imstk::Vec3d(0,1,0));
		ToolGeom = PlaneGeom;*/


		/*ToolGeom = imstk::GeometryUtils::toTriangleGrid(imstk::Vec3d(0,-35, 0),
			imstk::Vec2d(1000.0, 1000.0), imstk::Vec2i(2, 2));*/
	}

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
	ToolObj->setDynamicalModel(RbdModel);

	ToolObj->getRigidBody()->m_mass = Mass;
	ToolObj->getRigidBody()->m_intertiaTensor = imstk::Mat3d::Identity() * InertiaTensorMultiplier;
	ToolObj->getRigidBody()->m_initPos = UMathUtil::ToImstkVec3(GetComponentToWorld().GetLocation(), true);
	ToolObj->getRigidBody()->m_initOrientation = UMathUtil::ToImstkQuat(GetComponentToWorld().GetRotation());

	SubsystemInstance->ActiveScene->addSceneObject(ToolObj);

	Super::bIsInitialized = true;


	/*
	std::shared_ptr<imstk::Plane> PlaneGeom = std::make_shared<imstk::Plane>(imstk::Vec3d(0, -35, 0), imstk::Vec3d(0, 1, 0));
	/*PlaneGeom->setNormal();
	PlaneGeom->setPosition);*/

	/*std::shared_ptr<imstk::SurfaceMesh> cutGeom = imstk::GeometryUtils::toTriangleGrid(imstk::Vec3d(0, -35, 0),
		imstk::Vec2d(1000.0, 1000.0), imstk::Vec2i(2, 2));
	cutGeom->updatePostTransformData();
	PlaneGeom->updatePostTransformData();
	cutObj = std::make_shared<imstk::RigidObject2>("CuttingObject");
	cutObj->setDynamicalModel(SubsystemInstance->RigidBodyModel);
	cutObj->setVisualGeometry(PlaneGeom);
	cutObj->setCollidingGeometry(PlaneGeom);
	cutObj->setPhysicsGeometry(PlaneGeom);

	cutObj->getRigidBody()->m_mass = 1;
	cutObj->getRigidBody()->m_intertiaTensor = imstk::Mat3d::Identity() * 1;
	cutObj->getRigidBody()->m_initPos = imstk::Vec3d::Zero();

	SubsystemInstance->ActiveScene->addSceneObject(cutObj);


	clothObj = std::make_shared<imstk::PbdObject>("TEST CLOTH");
	double width = 50.0;
	double height = 50.0;
	int nRows = 12;
	int nCols = 12;
	std::shared_ptr<imstk::SurfaceMesh> clothMesh =
		imstk::GeometryUtils::toTriangleGrid(imstk::Vec3d::Zero(),
			imstk::Vec2d(width, height), imstk::Vec2i(nRows, nCols));

	// Setup the Parameters
	std::shared_ptr<imstk::PbdModelConfig> pbdParams = std::make_shared<imstk::PbdModelConfig>();
	pbdParams->enableConstraint(imstk::PbdModelConfig::ConstraintGenType::Distance, 1.0e3);
	pbdParams->enableConstraint(imstk::PbdModelConfig::ConstraintGenType::Dihedral, 1.0e3);
	pbdParams->m_fixedNodeIds = { 0, static_cast<size_t>(nCols) - 1 };
	pbdParams->m_uniformMassValue = width * height / static_cast<double>(nRows * nCols);
	pbdParams->m_gravity = imstk::Vec3d(0.0, -98, 0.0);
	pbdParams->m_dt = 0.005;
	pbdParams->m_iterations = 5;

	// Setup the Model
	std::shared_ptr<imstk::PbdModel> pbdModel = std::make_shared< imstk::PbdModel>();
	pbdModel->setModelGeometry(clothMesh);
	pbdModel->configure(pbdParams);

	// Setup the Object
	clothObj->setVisualGeometry(clothMesh);
	clothObj->setPhysicsGeometry(clothMesh);
	clothObj->setCollidingGeometry(clothMesh);
	clothObj->setDynamicalModel(pbdModel);

	SubsystemInstance->ActiveScene->addSceneObject(clothObj);

	Cutting = std::make_shared<imstk::PbdObjectCutting>(clothObj, cutObj);
	Super::bIsInitialized = true;
	*/
}

FVector UCustomController::UpdateImstkPosRot(FVector WorldPos, FQuat Orientation, FVector WorldDir, UDynamicalModel* PlaneActor)
{
	imstk::Vec3d Position;
	if (PlaneActor) {
		std::shared_ptr<imstk::Plane> Plane = std::dynamic_pointer_cast<imstk::Plane>(PlaneActor->GetImstkGeometry());

		if (Plane) {
			imstk::Vec3d IntersectPoint = imstk::Vec3d::Zero();
			if (imstk::CollisionUtils::testRayToPlane(UMathUtil::ToImstkVec3(WorldPos, true), UMathUtil::ToImstkVec3(WorldDir, true), Plane->getPosition(), Plane->getNormal(), IntersectPoint))
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
	else {
		Position = UMathUtil::ToImstkVec3(WorldPos, true);
	}

	// TODO: Should probably change to edit the position and orientation rather than creating new each time
	//std::dynamic_pointer_cast<imstk::Plane> (ToolObj->getCollidingGeometry())->setPosition(Position);
	ToolObj->getRigidBody()->m_orientation = new imstk::Quatd(UMathUtil::ToImstkQuat(Orientation));
	ToolObj->getRigidBody()->m_pos = new imstk::Vec3d(Position);

	//ToolObj->getRigidBody()->m_pos = new imstk::Vec3d(WorldPos.Z, WorldPos.X, WorldPos.Y);

	if (GEngine && bPrintImstkPos) {
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, UMathUtil::ToUnrealFVec(ToolObj->getRigidBody()->getPosition(), true).ToString());
		/*GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, UMathUtil::ToUnrealFVec(std::dynamic_pointer_cast<imstk::SurfaceMesh>(ToolObj->getCollidingGeometry())->getVertexPosition(0)).ToString() + " " +
			UMathUtil::ToUnrealFVec(std::dynamic_pointer_cast<imstk::SurfaceMesh>(ToolObj->getCollidingGeometry())->getVertexPosition(4)).ToString() + " " +
			UMathUtil::ToUnrealFVec(std::dynamic_pointer_cast<imstk::SurfaceMesh>(ToolObj->getCollidingGeometry())->getVertexPosition(20)).ToString() + " " +
			UMathUtil::ToUnrealFVec(std::dynamic_pointer_cast<imstk::SurfaceMesh>(ToolObj->getCollidingGeometry())->getVertexPosition(24)).ToString());*/
	}

	return UMathUtil::ToUnrealFVec(Position, true);
}

void UCustomController::UpdateUnrealPosRot()
{
	GetOwner()->SetActorLocation(UMathUtil::ToUnrealFVec(ToolObj->getRigidBody()->getPosition(), true));
	//imstk::Vec3d position = ToolObj->getRigidBody()->getPosition();
	//GetOwner()->SetActorLocation(FVector(position.y(), position.z(), position.x()));
	GetOwner()->SetActorRotation(UMathUtil::ToUnrealFQuat(ToolObj->getRigidBody()->getOrientation()));
}

void UCustomController::MoveControllerToLocation(FVector Location, FQuat Orientation, bool bUpdateUnrealPosRot)
{
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


void UCustomController::BeginVertexGrasp()
{
	if (ToolPickings.Num() > 0) {
		if (GraspType == EGraspType::VertexGrasp) {
			for (std::shared_ptr<imstk::PbdObjectGrasping> ToolPicking : ToolPickings) {
				ToolPicking->beginVertexGrasp(std::dynamic_pointer_cast<imstk::AnalyticalGeometry>(ToolObj->getCollidingGeometry()));
			}
		}
	}
	else {
		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "ToolPicking not assigned");
		UE_LOG(LogTemp, Error, TEXT("ToolPicking not assigned"));
	}
}

void UCustomController::BeginCellGrasp()
{
	if (ToolPickings.Num() > 0) {
		if (GraspType == EGraspType::CellGrasp) {
			for (std::shared_ptr<imstk::PbdObjectGrasping> ToolPicking : ToolPickings) {
				ToolPicking->beginCellGrasp(std::dynamic_pointer_cast<imstk::AnalyticalGeometry>(ToolObj->getCollidingGeometry()), std::string(TCHAR_TO_UTF8(*UEnum::GetValueAsString(GraspCollisionType))));
			}
		}
	}
	else {
		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "ToolPicking not assigned");
		UE_LOG(LogTemp, Error, TEXT("ToolPicking not assigned"));
	}
}

void UCustomController::BeginRayPointGrasp(FVector RayStart, FVector RayDir)
{
	if (ToolPickings.Num() > 0) {
		if (GraspType == EGraspType::RayPointGrasp) {
			for (std::shared_ptr<imstk::PbdObjectGrasping> ToolPicking : ToolPickings) {
				ToolPicking->beginRayPointGrasp(std::dynamic_pointer_cast<imstk::AnalyticalGeometry>(ToolObj->getCollidingGeometry()), UMathUtil::ToImstkVec3(RayStart, true), UMathUtil::ToImstkVec3(RayDir, true));
			}
		}
	}
	else {
		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "ToolPicking not assigned");
		UE_LOG(LogTemp, Error, TEXT("ToolPicking not assigned"));
	}
}

void UCustomController::EndGrasp()
{
	if (ToolPickings.Num() > 0) {
		for (std::shared_ptr<imstk::PbdObjectGrasping> ToolPicking : ToolPickings) {
			ToolPicking->endGrasp();
		}
	}
}

void UCustomController::BeginStitch()
{
	if (Stitchings.Num() > 0) {
		std::shared_ptr<imstk::LineMesh> ToolGeom = std::dynamic_pointer_cast<imstk::LineMesh>(ToolObj->getCollidingGeometry());
		const imstk::Vec3d& Vert1 = ToolGeom->getVertexPosition(0);
		const imstk::Vec3d& Vert2 = ToolGeom->getVertexPosition(1);

		//if (GEngine)
			//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "Stitching between " + UMathUtil::ToUnrealFVec(Vert1).ToString() + " and " + UMathUtil::ToUnrealFVec(Vert2).ToString());
		for (std::shared_ptr<imstk::PbdObjectStitching> Stitching : Stitchings) {
			Stitching->beginStitch(Vert1, (Vert2 - Vert1).normalized());
		}
	}
}

void UCustomController::BeginCut()
{
	if (Cuttings.Num() > 0) {
		for (std::shared_ptr<imstk::PbdObjectCutting> Cutting : Cuttings) {
			Cutting->apply();
		}
	}
}

void UCustomController::UnInit()
{
	Super::UnInit();


}
