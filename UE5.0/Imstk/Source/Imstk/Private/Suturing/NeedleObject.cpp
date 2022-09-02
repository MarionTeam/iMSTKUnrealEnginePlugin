// Fill out your copyright notice in the Description page of Project Settings.

#include "NeedleObject.h"
#include "Interfaces/IPluginManager.h"
#include "MathUtil.h"
#include "imstkIsometricMap.h"
#include "imstkLineMesh.h"
#include "imstkMeshIO.h"
#include "imstkRbdConstraint.h"
#include "imstkTetrahedralMesh.h"
#include "imstkRenderMaterial.h"
#include "imstkRigidBodyModel2.h"
#include "imstkSurfaceMesh.h"
#include "imstkVisualModel.h"
#include "imstkCollisionUtils.h"

NeedleObject::NeedleObject(std::shared_ptr<imstk::RigidBodyModel2> rbdModel, USceneComponent* Comp) : imstk::RigidObject2("Needle")
{
	FString ContentDir = IPluginManager::Get().FindPlugin((TEXT("Imstk")))->GetContentDir();

	auto sutureMesh = imstk::MeshIO::read<imstk::SurfaceMesh>(std::string(TCHAR_TO_UTF8(*(ContentDir +"/ExtraFiles/Needles/c6_suture.stl"))));
	auto sutureLineMesh = imstk::MeshIO::read<imstk::LineMesh>(std::string(TCHAR_TO_UTF8(*(ContentDir + "/ExtraFiles/Needles/c6_suture_hull.vtk"))));

	const imstk::Mat4d rot = imstk::mat4dRotation(imstk::Rotd(-PI_2, imstk::Vec3d(0.0, 1.0, 0.0))) *
		imstk::mat4dRotation(imstk::Rotd(-0.6, imstk::Vec3d(1.0, 0.0, 0.0)));

	sutureMesh->setScaling(UMathUtil::ToImstkVec3d(Comp->GetComponentScale(), false));

	sutureMesh->transform(rot, imstk::Geometry::TransformType::ApplyToData);
	sutureLineMesh->transform(rot, imstk::Geometry::TransformType::ApplyToData);

	setVisualGeometry(sutureMesh);
	// setVisualGeometry(sutureLineMesh);
	setCollidingGeometry(sutureLineMesh);
	setPhysicsGeometry(sutureLineMesh);
	setPhysicsToVisualMap(std::make_shared<imstk::IsometricMap>(sutureLineMesh, sutureMesh));

	/*getVisualModel(0)->getRenderMaterial()->setColor(imstk::Color(0.9, 0.9, 0.9));
	getVisualModel(0)->getRenderMaterial()->setShadingModel(imstk::RenderMaterial::ShadingModel::PBR);
	getVisualModel(0)->getRenderMaterial()->setRoughness(0.5);
	getVisualModel(0)->getRenderMaterial()->setMetalness(1.0);*/

	//std::shared_ptr<imstk::RigidBodyModel2> rbdModel = std::make_shared<imstk::RigidBodyModel2>();
	rbdModel->getConfig()->m_gravity = imstk::Vec3d::Zero();
	rbdModel->getConfig()->m_maxNumIterations = 5;
	setDynamicalModel(rbdModel);

	getRigidBody()->m_mass = 1.0;
	getRigidBody()->m_intertiaTensor = imstk::Mat3d::Identity() * 10000.0;
	getRigidBody()->m_initPos = imstk::Vec3d(0.0, 0.0, 0.0);
}