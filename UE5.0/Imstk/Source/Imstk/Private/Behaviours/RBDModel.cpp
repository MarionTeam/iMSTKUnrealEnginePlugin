// Fill out your copyright notice in the Description page of Project Settings.


#include "RBDModel.h"
#include "ImstkSettings.h"
#include "imstkRigidBodyModel2.h"
#include "imstkRbdConstraint.h"
#include "MathUtil.h"
#include "Engine/GameEngine.h"

// Called before Begin Play
void URBDModel::InitializeComponent()
{
	Super::InitializeComponent();
	if (GetWorld() && GetWorld()->GetGameInstance())
		// Make the subsystem tick first to update the imstk scene before updating the rigid body in unreal
		AddTickPrerequisiteActor((AActor*)SubsystemInstance);

}

// Called when the game starts or when spawned
void URBDModel::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void URBDModel::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (Super::bIsInitialized) {
		UpdatePosRot();
	}
}


void URBDModel::Init()
{
	Super::Init();
	// Create the imstk object using the geometry set in the geometry filter
	RigidObject = std::make_shared<imstk::RigidObject2>(TCHAR_TO_UTF8(*(Owner->GetName())));
	std::shared_ptr<imstk::Geometry> Geom = GetImstkGeometry();

	Geom->scale(UMathUtil::ToImstkVec3d(Owner->GetActorScale(), false), imstk::Geometry::TransformType::ApplyToData);

	// Configure rigid object
	std::shared_ptr<imstk::RigidBodyModel2> RigidBodyModel = std::make_shared<imstk::RigidBodyModel2>();

	// Set up rigid body model using the subsystem and individual values if set
	if (bIndividualGravity)
		RigidBodyModel->getConfig()->m_gravity = UMathUtil::ToImstkVec3d(Gravity, true);
	else
		RigidBodyModel->getConfig()->m_gravity = SubsystemInstance->RigidBodyModel->getConfig()->m_gravity;
	
	if (bIndividualDT)
		RigidBodyModel->getConfig()->m_dt = IndividualDT;
	else
		RigidBodyModel->getConfig()->m_dt = SubsystemInstance->RigidBodyModel->getConfig()->m_dt;

	RigidBodyModel->getConfig()->m_maxNumIterations = SubsystemInstance->RigidBodyModel->getConfig()->m_maxNumIterations;

	RigidObject->setDynamicalModel(RigidBodyModel);
	RigidObject->setPhysicsGeometry(Geom);
	RigidObject->setCollidingGeometry(Geom);

	RigidObject->getRigidBody()->m_mass = Mass;

	

	

	RigidObject->getRigidBody()->setInitPos(UMathUtil::ToImstkVec3d(Owner->GetActorLocation(), true));
	RigidObject->getRigidBody()->setInitOrientation(UMathUtil::ToImstkQuat(Owner->GetActorRotation().Quaternion()));
	RigidObject->getRigidBody()->setInertiaTensor(imstk::Mat3d::Identity());

	SubsystemInstance->ActiveScene->addSceneObject(RigidObject);

	// Set the parent colliding object to the constructed object
	ImstkCollidingObject = RigidObject;


	if (UImstkSettings::IsDebugging()) {
		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, "Initialized: " + Owner->GetFName().ToString());
	}

	Super::bIsInitialized = true;
}

void URBDModel::UpdatePosRot()
{
	// Get the position and rotation of the object in the iMSTK scene and update the object in Unreal
	std::shared_ptr<imstk::RigidBody> RigidBody = RigidObject->getRigidBody();

	FVector pos = UMathUtil::ToUnrealFVec(RigidBody->getPosition(), true);
	FQuat rot = UMathUtil::ToUnrealFQuat(RigidBody->getOrientation());

	Owner->SetActorLocation(pos);
	Owner->SetActorRotation(rot);

	if (UImstkSettings::IsDebugging()) {
		if (GEngine) {
			if (bPrintPositionInformation)
				GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, Owner->GetName() + ": " + UMathUtil::ToUnrealFVec(RigidObject->getCollidingGeometry()->getCenter(), true).ToString());
		}
	}
}

void URBDModel::UnInit() 
{
	Super::UnInit();
	RigidObject.reset();
}