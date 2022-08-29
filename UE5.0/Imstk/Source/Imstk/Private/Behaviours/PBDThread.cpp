// Fill out your copyright notice in the Description page of Project Settings.


#include "PBDThread.h"
#include "ImstkSettings.h"
#include "imstkPbdModel.h"


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
			UE_LOG(LogTemp, Error, TEXT("Error Initializing: %s. No spline component attached to actor"), *Owner->GetName());
			SubsystemInstance->AllBehaviours.Remove(this);
		}
	}

}

void UPBDThread::Init()
{
	Super::Init();
	PbdObject = std::make_shared<imstk::PbdObject>(TCHAR_TO_UTF8(*(Owner->GetName())));

	// Create a line mesh in iMSTK based on the unreal spline component attached to the actor
	// TODO: do something about the spline tangents
	std::shared_ptr<imstk::LineMesh> StringMesh = std::make_shared<imstk::LineMesh>();
	int NumVerts = SplineComponent->GetNumberOfSplinePoints();
	std::shared_ptr<imstk::VecDataArray<double, 3>> VerticesPtr = std::make_shared<imstk::VecDataArray<double, 3>>(NumVerts);
	imstk::VecDataArray<double, 3>&Vertices = *VerticesPtr.get();
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
	
	// Configure model
	std::shared_ptr<imstk::PbdModelConfig> PbdConfig = std::make_shared<imstk::PbdModelConfig>();

	if (bUseDistanceConstraint)
		PbdConfig->enableConstraint(imstk::PbdModelConfig::ConstraintGenType::Distance, DistanceConstraint);

	if (bUseBendConstraint) {
		PbdConfig->enableBendConstraint(BendStiffness, 1);
		//PbdConfig->enableBendConstraint(BendStiffness, 2);
	}
	

	PbdConfig->m_uniformMassValue = Mass / NumVerts;

	// If object has separate gravity and delta time than the rest of the scene
	if (bIndividualGravity)
		PbdConfig->m_gravity = UMathUtil::ToImstkVec3d(Gravity, true);
	else
		PbdConfig->m_gravity = UMathUtil::ToImstkVec3d(SubsystemInstance->Gravity, true);

	if (bIndividualDT)
		PbdConfig->m_dt = IndividualDT;
	else
		PbdConfig->m_dt = SubsystemInstance->TickInterval;

	PbdConfig->m_iterations = ModelIterations;
	PbdConfig->m_viscousDampingCoeff = ViscousDampingCoeff;

	std::shared_ptr<imstk::PbdModel> PbdModel = std::make_shared<imstk::PbdModel>();
	PbdModel->configure(PbdConfig);
	PbdModel->setModelGeometry(StringMesh);

	PbdObject->setVisualGeometry(StringMesh);
	PbdObject->setPhysicsGeometry(StringMesh);
	PbdObject->setCollidingGeometry(StringMesh);
	PbdObject->setDynamicalModel(PbdModel);

	ImstkCollidingObject = PbdObject;
	Geometry = StringMesh;

	ProcessBoundaryConditions();

	for (const int num : FixedNodes) {
		PbdConfig->m_fixedNodeIds.push_back(num);
	}

	SubsystemInstance->ActiveScene->addSceneObject(PbdObject);

	if (bZeroTangents) {
		for (int i = 0; i < Vertices.size(); i++)
		{
			SplineComponent->SetTangentsAtSplinePoint(i, FVector::Zero(), FVector::Zero(), ESplineCoordinateSpace::Local);
		}
	}

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