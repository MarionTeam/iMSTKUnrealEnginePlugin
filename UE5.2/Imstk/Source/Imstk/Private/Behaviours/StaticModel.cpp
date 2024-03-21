// Fill out your copyright notice in the Description page of Project Settings.


#include "StaticModel.h"
#include "ImstkSettings.h"
//#include "Engine/GameEngine.h"

void UStaticModel::PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent)
{
	FName PropertyName = (PropertyChangedEvent.Property != NULL) ? PropertyChangedEvent.Property->GetFName() : NAME_None;

	if (PropertyName == GET_MEMBER_NAME_CHECKED(UStaticModel, Preset)) {
		switch (Preset)
		{
		case 0:
			GeomFilter.GeomType = EGeometryType::SurfaceMesh;
			break;
		case 1:
			GeomFilter.GeomType = EGeometryType::Sphere;
			GeomFilter.SphereStruct.Radius = 50;
			break;
		case 2:
			GeomFilter.GeomType = EGeometryType::Capsule;
			GeomFilter.CapsuleStruct.Radius = 12.5;
			GeomFilter.CapsuleStruct.Length = 50;
			break;
		case 3:
			GeomFilter.GeomType = EGeometryType::Cylinder;
			GeomFilter.CylinderStruct.Radius = 12.5;
			GeomFilter.CylinderStruct.Length = 50;
			break;
		case 4:
			GeomFilter.GeomType = EGeometryType::PointSet;
			break;
		case 5:
			GeomFilter.GeomType = EGeometryType::OrientedBox;
			GeomFilter.OrientedBoxStruct.Extents = FVector(50, 50, 50);
			break;
		case 6:
			GeomFilter.GeomType = EGeometryType::Plane;
			GeomFilter.PlaneStruct.Normal = FVector(0, 0, 1);
			break;
		case 7:
			GeomFilter.GeomType = EGeometryType::LineMesh;
			break;
		default:
			return;
		}
	}
}

void UStaticModel::InitializeComponent()
{
	Super::InitializeComponent();
	PrimaryComponentTick.bCanEverTick = false;
}

void UStaticModel::BeginPlay()
{
	Super::BeginPlay();
}

void UStaticModel::Init()
{
	if (bDelayInit)
		return;
	Super::Init();

	// Create the imstk object using the geometry set in the geometry filter
	ImstkCollidingObject = std::make_shared<imstk::CollidingObject>(TCHAR_TO_UTF8(*(Owner->GetName())));
	std::shared_ptr<imstk::Geometry> Geom = GetImstkGeometry();

	// Following steps must be done in this order to have rotation of the object around the center of the model
	Geom->scale(UMathUtil::ToImstkVec3d(Owner->GetActorScale(), false), imstk::Geometry::TransformType::ApplyToData);
	Geom->rotate(UMathUtil::ToImstkQuat(Owner->GetActorRotation().Quaternion()), imstk::Geometry::TransformType::ApplyToData);
	Geom->updatePostTransformData();
	Geom->translate(UMathUtil::ToImstkVec3d(Owner->GetActorLocation(), true), imstk::Geometry::TransformType::ApplyToData);

	ImstkCollidingObject->setCollidingGeometry(Geom);
	ImstkCollidingObject->setVisualGeometry(Geom);

	if (!bDelayInit) {
		SubsystemInstance->ActiveScene->addSceneObject(ImstkCollidingObject);

		SubsystemInstance->LogToUnrealAndImstk("Initialized: " + Owner->GetFName().ToString(), FColor::Green);
		Super::bIsInitialized = true;
	}
}
