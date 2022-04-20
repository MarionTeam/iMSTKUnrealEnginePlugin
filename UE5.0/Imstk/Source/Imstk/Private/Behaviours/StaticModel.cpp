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
	std::shared_ptr<imstk::Geometry> Geom = GetCollidingGeometry();

	// Following steps must be done in this order to have rotation of the object around the center of the model
	//Geom->scale(UMathUtil::ToImstkVec3(Owner->GetActorScale()), imstk::Geometry::TransformType::ApplyToData);
	Geom->rotate(UMathUtil::ToImstkQuat(Owner->GetActorRotation().Quaternion()), imstk::Geometry::TransformType::ApplyToData);
	Geom->updatePostTransformData();
	Geom->translate(UMathUtil::ToImstkVec3(Owner->GetActorLocation()), imstk::Geometry::TransformType::ApplyToData);
	
	
	//Geom->transform(UMathUtil::ToImstkMat4d(Owner->GetTransform().ToMatrixWithScale()), imstk::Geometry::TransformType::ApplyToData);

	//Geom->updatePostTransformData();


	ImstkCollidingObject->setCollidingGeometry(Geom);

	SubsystemInstance->ActiveScene->addSceneObject(ImstkCollidingObject);
	
	

	if (UImstkSettings::IsDebugging()) {
		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, "Initialized: " + Owner->GetFName().ToString());
		//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, FString(Geom->getName().c_str()));
	}
	Super::bIsInitalized = true;
}