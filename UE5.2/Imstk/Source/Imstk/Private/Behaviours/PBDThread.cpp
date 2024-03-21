// Fill out your copyright notice in the Description page of Project Settings.


#include "PBDThread.h"
#include "ImstkSettings.h"
#include "imstkPbdModel.h"
#include "imstkPbdModelConfig.h"
#include "Kismet/KismetMathLibrary.h"
#include "DynamicMeshBuilder.h"


void UPBDThread::InitializeComponent()
{
	Super::InitializeComponent();

	// Check if game is in play mode (required because InitializeComponent() is run when creating a blueprint of the object)
	if (GetWorld() && GetWorld()->GetGameInstance()) {
		// Make the subsystem tick first to update the imstk scene before updating the model in unreal

		// Create procedural mesh, convert static mesh to procedural and then disable static mesh
		MeshComp = NewObject<UProceduralMeshComponent>(this);
		// If including scale, scale gets applied twice
		MeshComp->AttachToComponent(Owner->GetRootComponent(), FAttachmentTransformRules::SnapToTargetNotIncludingScale);
		MeshComp->RegisterComponent();

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

	if (bScaleMassPerVertex)
		PbdObject->getPbdBody()->uniformMassValue = Mass / std::dynamic_pointer_cast<imstk::PointSet>(PbdObject->getPhysicsGeometry())->getNumVertices();
	else
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

	if (bGenerateMesh)
		GenerateMesh();

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
		//SplineComponent->SetTangentsAtSplinePoint();
	}

	if (bGenerateMesh)
		GenerateMesh();

	if (UImstkSettings::IsDebugging()) {
		if (GEngine) {
			if (bPrintPositionInformation)
				GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, Owner->GetName() + ": " + UMathUtil::ToUnrealFVec(PbdObject->getVisualGeometry()->getCenter(), true).ToString());
		}
	}
}

// Modified from CableComponent code
void UPBDThread::GenerateMesh() 
{
	TArray<FDynamicMeshVertex> OutVertices;
	TArray<int32> OutIndices;

	const FColor VertexColor(255, 255, 255);
	auto LineMesh = std::dynamic_pointer_cast<imstk::LineMesh>(Geometry);
	imstk::VecDataArray<double, 3>& WorldPos = *LineMesh->getVertexPositions().get();
	TArray<FVector> InPoints;

	const int32 NumPoints = LineMesh->getNumVertices();
	const int32 SegmentCount = NumPoints - 1;

	// Build vertices

	// We double up the first and last vert of the ring, because the UVs are different
	int32 NumRingVerts = NumSides + 1;

	// World positions to local
	for (int32 i = 0; i < NumPoints; i++)
	{
		InPoints.Add(UKismetMathLibrary::InverseTransformLocation(MeshComp->GetComponentTransform(), UMathUtil::ToUnrealFVec(WorldPos[i], true)));
	}

	// For each point along spline..
	for (int32 PointIdx = 0; PointIdx < NumPoints; PointIdx++)
	{
		const float AlongFrac = (float)PointIdx / (float)SegmentCount; // Distance along cable

		// Find direction of cable at this point, by averaging previous and next points
		const int32 PrevIndex = FMath::Max(0, PointIdx - 1);
		const int32 NextIndex = FMath::Min(PointIdx + 1, NumPoints - 1);
		const FVector ForwardDir = (InPoints[NextIndex] - InPoints[PrevIndex]).GetSafeNormal();

		// Find quat from up (Z) vector to forward
		const FQuat DeltaQuat = FQuat::FindBetween(FVector(0, 0, -1), ForwardDir);

		// Apply quat orth vectors
		const FVector RightDir = DeltaQuat.RotateVector(FVector(0, 1, 0));
		const FVector UpDir = DeltaQuat.RotateVector(FVector(1, 0, 0));

		// Generate a ring of verts
		for (int32 VertIdx = 0; VertIdx < NumRingVerts; VertIdx++)
		{
			const float AroundFrac = float(VertIdx) / float(NumSides);
			// Find angle around the ring
			const float RadAngle = 2.f * PI * AroundFrac;
			// Find direction from center of cable to this vertex
			const FVector OutDir = (FMath::Cos(RadAngle) * UpDir) + (FMath::Sin(RadAngle) * RightDir);

			FDynamicMeshVertex Vert;
			Vert.Position = FVector3f(InPoints[PointIdx] + (OutDir * 0.5f * Width));
			Vert.TextureCoordinate[0] = FVector2f(AlongFrac * Tiling, AroundFrac);
			Vert.Color = VertexColor;
			Vert.SetTangents((FVector3f)ForwardDir, FVector3f(OutDir ^ ForwardDir), (FVector3f)OutDir);
			OutVertices.Add(Vert);
		}
	}

	// Build triangles
	for (int32 SegIdx = 0; SegIdx < SegmentCount; SegIdx++)
	{
		for (int32 SideIdx = 0; SideIdx < NumSides; SideIdx++)
		{
			int32 TL = GetVertIndex(SegIdx, SideIdx);
			int32 BL = GetVertIndex(SegIdx, SideIdx + 1);
			int32 TR = GetVertIndex(SegIdx + 1, SideIdx);
			int32 BR = GetVertIndex(SegIdx + 1, SideIdx + 1);

			OutIndices.Add(TL);
			OutIndices.Add(BL);
			OutIndices.Add(TR);

			OutIndices.Add(TR);
			OutIndices.Add(BL);
			OutIndices.Add(BR);
		}
	}

	TArray<FVector2D> UV0;
	TArray<FLinearColor> VertColors;
	TArray<FProcMeshTangent> Tangents;
	TArray<FVector> Verts;
	//TArray<int32> Indices;
	TArray<FVector> Normals;
	for (int i = 0; i < OutVertices.Num(); i++)
	{
		const FDynamicMeshVertex& Vertex = OutVertices[i];
		Verts.Add(FVector(Vertex.Position));
		Tangents.Add(FProcMeshTangent(Vertex.TangentX.ToFVector(), false));
		Normals.Add(Vertex.TangentZ.ToFVector());
		UV0.Add(FVector2D(Vertex.TextureCoordinate[0]));
		VertColors.Add(Vertex.Color);
		//VertexBuffers.PositionVertexBuffer.VertexPosition(i) = Vertex.Position;
		//VertexBuffers.StaticMeshVertexBuffer.SetVertexTangents(i, Vertex.TangentX.ToFVector3f(), Vertex.GetTangentY(), Vertex.TangentZ.ToFVector3f());
		//VertexBuffers.StaticMeshVertexBuffer.SetVertexUV(i, 0, Vertex.TextureCoordinate[0]);
		//VertexBuffers.ColorVertexBuffer.VertexColor(i) = Vertex.Color;
	}

	MeshComp->CreateMeshSection_LinearColor(0, Verts, OutIndices, Normals, UV0, VertColors, Tangents, false);
}

int32 UPBDThread::GetVertIndex(int32 AlongIdx, int32 AroundIdx) const
{
	return (AlongIdx * (NumSides + 1)) + AroundIdx;
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