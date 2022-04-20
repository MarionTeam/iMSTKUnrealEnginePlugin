// Fill out your copyright notice in the Description page of Project Settings.


#include "RBDModel.h"
#include "ImstkSettings.h"
#include "iMSTK-5.0/imstkRigidBodyModel2.h"
#include "iMSTK-5.0/imstkRbdConstraint.h"
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

	if (Super::bIsInitalized) {
		UpdatePosRot();
	}
}


void URBDModel::Init()
{
	Super::Init();
	// Create the imstk object using the geometry set in the geometry filter
	RigidObject = std::make_shared<imstk::RigidObject2>(TCHAR_TO_UTF8(*(Owner->GetName())));
	std::shared_ptr<imstk::Geometry> Geom = GetCollidingGeometry();

	//Geom->scale(UMathUtil::ToImstkVec3(Owner->GetActorScale()), imstk::Geometry::TransformType::ApplyToData);

	RigidObject->setDynamicalModel(SubsystemInstance->RigidBodyModel);
	RigidObject->setPhysicsGeometry(Geom);
	RigidObject->setCollidingGeometry(Geom);

	RigidObject->getRigidBody()->m_mass = Mass;
	//
	// TODO: Add other starting values
	RigidObject->getRigidBody()->setInitPos(UMathUtil::ToImstkVec3(Owner->GetActorLocation()));
	RigidObject->getRigidBody()->setInitOrientation(UMathUtil::ToImstkQuat(Owner->GetActorRotation().Quaternion()));
	RigidObject->getRigidBody()->setInertiaTensor(imstk::Mat3d::Identity());

	SubsystemInstance->ActiveScene->addSceneObject(RigidObject);

	// Set the parent colliding object to the constructed object
	ImstkCollidingObject = RigidObject;


	if (UImstkSettings::IsDebugging()) {
		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, "Initialized: " + Owner->GetFName().ToString());

		// Use to test if mesh is being inputted into imstk properly
		/*if (GeomFilter.GeomType == GeometryType::SurfaceMesh) {
			std::shared_ptr<imstk::SurfaceMesh> Mesh = std::dynamic_pointer_cast<imstk::SurfaceMesh>(Geom);

			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, FString(Mesh->getName().c_str()));
			for (int i = 0; i < Mesh->getNumVertices(); i++) {
				imstk::Vec3d Vert = Mesh->getVertexPosition(i);
				GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, "X: " + FString::SanitizeFloat(Vert.x()) + " Y: " + FString::SanitizeFloat(Vert.y()) + "Z: " + FString::SanitizeFloat(Vert.z()));
			}
		}*/


	}

	Super::bIsInitalized = true;
}

void URBDModel::UpdatePosRot()
{
	// get the position and rotation of the object in the scene and update the object in unreal
	std::shared_ptr<imstk::RigidBody> RigidBody = RigidObject->getRigidBody();

	FVector pos = UMathUtil::ToUnrealFVec(RigidBody->getPosition());
	FQuat rot = UMathUtil::ToUnrealFQuat(RigidBody->getOrientation());

	Owner->SetActorLocation(pos);
	Owner->SetActorRotation(rot);

	if (UImstkSettings::IsDebugging()) {
		if (GEngine) {
			//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, Owner->GetName() + " " + pos.ToString());

			if (bPrintPositionInformation)
				GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, Owner->GetName() + ": " + UMathUtil::ToUnrealFVec(RigidObject->getCollidingGeometry()->getCenter()).ToString());
		}
	}
}

void URBDModel::UnInit() 
{
	Super::UnInit();
	RigidObject.reset();
}