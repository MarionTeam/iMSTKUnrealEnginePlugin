// Fill out your copyright notice in the Description page of Project Settings.


#include "StaticModel.h"
#include "ImstkSettings.h"
#include "Engine/GameEngine.h"

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
	Super::Init();
	// Create the imstk object using the geometry set in the geometry filter
	ImstkCollidingObject = std::make_shared<imstk::CollidingObject>(TCHAR_TO_UTF8(*(Owner->GetName())));
	std::shared_ptr<imstk::Geometry> Geom = GetImstkGeometry();

	// Following steps must be done in this order to have rotation of the object around the center of the model
	Geom->scale(UMathUtil::ToImstkVec3(Owner->GetActorScale(), false), imstk::Geometry::TransformType::ApplyToData);
	Geom->rotate(UMathUtil::ToImstkQuat(Owner->GetActorRotation().Quaternion()), imstk::Geometry::TransformType::ApplyToData);
	Geom->updatePostTransformData();
	Geom->translate(UMathUtil::ToImstkVec3(Owner->GetActorLocation(), true), imstk::Geometry::TransformType::ApplyToData);

	ImstkCollidingObject->setCollidingGeometry(Geom);

	SubsystemInstance->ActiveScene->addSceneObject(ImstkCollidingObject);

	if (UImstkSettings::IsDebugging()) {
		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, "Initialized: " + Owner->GetFName().ToString());
	}
	Super::bIsInitialized = true;
}