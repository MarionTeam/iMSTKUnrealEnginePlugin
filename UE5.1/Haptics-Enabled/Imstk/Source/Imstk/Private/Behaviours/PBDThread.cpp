// Fill out your copyright notice in the Description page of Project Settings.


#include "PBDThread.h"
#include "ImstkSettings.h"
#include "imstkPbdModel.h"
#include "imstkPbdModelConfig.h"


void UPBDThread::InitializeComponent()
{
	Super::InitializeComponent();

	// Check if game is in play mode (required because InitializeComponent() is run when creating a blueprint of the object)
	if (GetWorld() && GetWorld()->GetGameInstance()) {
		// Make the subsystem tick first to update the imstk scene before updating the model in unreal
		AddTickPrerequisiteActor((AActor*)SubsystemInstance);
		if (USplineComponent* Comp = (USplineComponent*)Owner->GetComponentByClass(USplineComponent::StaticClass()))
		{
			SplineComponent = Comp;
		}
		else
		{
			// No spline attached error
			SubsystemInstance->LogToUnrealAndImstk("Error Initializing: " + Owner->GetName() + ". No spline component attached to actor", FColor::Red);
			SubsystemInstance->AllBehaviours.Remove(this);
		}
	}

}

UPBDThread::UPBDThread() : UDeformableModel()
{
	bUseDistanceConstraint = true;
	DistanceConstraint = 50;

	bUseBendConstraint = true;
	BendStiffness = 0.2;

	Mass = 0.0001;
}

void UPBDThread::Init()
{
	if (bDelayInit)
		return;
	Super::Init();

	PbdObject = std::make_shared<imstk::PbdObject>(TCHAR_TO_UTF8(*(Owner->GetName())));

	// Create a line mesh in iMSTK based on the unreal spline component attached to the actor
	// TODO: do something about the spline tangents
	std::shared_ptr<imstk::LineMesh> StringMesh = std::make_shared<imstk::LineMesh>();
	int NumVerts = SplineComponent->GetNumberOfSplinePoints();
	std::shared_ptr<imstk::VecDataArray<double, 3>> VerticesPtr = std::make_shared<imstk::VecDataArray<double, 3>>(NumVerts);
	imstk::VecDataArray<double, 3>& Vertices = *VerticesPtr.get();
	for (int i = 0; i < NumVerts; i++)
	{
		Vertices[i] = UMathUtil::ToImstkVec3d(SplineComponent->GetWorldLocationAtSplinePoint(i), true);
	}
	std::shared_ptr<imstk::VecDataArray<int, 2>> SegmentsPtr = std::make_shared<imstk::VecDataArray<int, 2>>();
	imstk::VecDataArray<int, 2>& Segments = *SegmentsPtr.get();
	for (int i = 0; i < NumVerts - 1; i++)
	{
		Segments.push_back(imstk::Vec2i(i, i + 1));
	}

	StringMesh->initialize(VerticesPtr, SegmentsPtr);

	std::shared_ptr<imstk::PbdModel> PbdModel;
	if (bSharedModel)
		PbdModel = SubsystemInstance->PbdModel;
	else
		PbdModel = std::make_shared<imstk::PbdModel>();

	// Configure model
	// If object has separate gravity and delta time than the rest of the scene
	if (bIndividualGravity && !bSharedModel)
		PbdModel->getConfig()->m_gravity = UMathUtil::ToImstkVec3d(Gravity, true);
	else
		PbdModel->getConfig()->m_gravity = UMathUtil::ToImstkVec3d(SubsystemInstance->Gravity, true);

	// If the object should have separate delta time from the rest of the scene
	if (bIndividualDT && !bSharedModel)
		PbdModel->getConfig()->m_dt = IndividualDT;
	else
		PbdModel->getConfig()->m_dt = SubsystemInstance->TickInterval;

	PbdObject->setVisualGeometry(StringMesh);
	PbdObject->setPhysicsGeometry(StringMesh);
	PbdObject->setCollidingGeometry(StringMesh);
	PbdObject->setDynamicalModel(PbdModel);

	PbdModel->getConfig()->setBodyDamping(PbdObject->getPbdBody()->bodyHandle, LinearDampingCoefficient, AngularDampingCoefficient);

	PbdObject->getPbdBody()->uniformMassValue = Mass;

	if (!bSharedModel)
		PbdModel->getConfig()->m_iterations = ModelIterations;

	if (bUseDistanceConstraint)
		PbdModel->getConfig()->enableConstraint(imstk::PbdModelConfig::ConstraintGenType::Distance, DistanceConstraint, PbdObject->getPbdBody()->bodyHandle);

	if (bUseBendConstraint)
		PbdModel->getConfig()->enableBendConstraint(BendStiffness, 1, true, PbdObject->getPbdBody()->bodyHandle);


	ImstkCollidingObject = PbdObject;
	Geometry = StringMesh;

	ProcessBoundaryConditions();

	for (const int Num : FixedNodes) {
		PbdObject->getPbdBody()->fixedNodeIds.push_back(Num);
	}

	if (bZeroTangents) {
		for (int i = 0; i < Vertices.size(); i++)
		{
			SplineComponent->SetTangentsAtSplinePoint(i, FVector::Zero(), FVector::Zero(), ESplineCoordinateSpace::Local);
		}
	}

	SubsystemInstance->ActiveScene->addSceneObject(PbdObject);

	SubsystemInstance->LogToUnrealAndImstk("Initialized: " + Owner->GetFName().ToString(), FColor::Green);
	Super::bIsInitialized = true;
}

void UPBDThread::UpdateModel()
{
	// Update spline component positions
	if (!VisualGeom)
		VisualGeom = std::dynamic_pointer_cast<imstk::LineMesh>(PbdObject->getVisualGeometry());

	std::shared_ptr<imstk::VecDataArray<double, 3>> VerticesPtr = VisualGeom->getVertexPositions();

	imstk::VecDataArray<double, 3>& Vertices = *VerticesPtr.get();

	for (int i = 0; i < Vertices.size(); i++)
	{
		SplineComponent->SetWorldLocationAtSplinePoint(i, UMathUtil::ToUnrealFVec(Vertices[i], true));
	}

	if (UImstkSettings::IsDebugging()) {
		if (GEngine) {
			if (bPrintPositionInformation)
				GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, Owner->GetName() + ": " + UMathUtil::ToUnrealFVec(PbdObject->getVisualGeometry()->getCenter(), true).ToString());
		}
	}
}

void UPBDThread::MoveVertexToLocation(int VertIndex, FVector Pos)
{
	std::shared_ptr<imstk::LineMesh> Thread = std::dynamic_pointer_cast<imstk::LineMesh>(PbdObject->getPhysicsGeometry());

	(*Thread->getVertexPositions())[VertIndex] = UMathUtil::ToImstkVec3d(Pos, true);
}

void UPBDThread::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (Super::bIsInitialized) {
		UpdateModel();
	}
}

void UPBDThread::UnInit()
{
	Super::UnInit();
	VisualGeom.reset();
}