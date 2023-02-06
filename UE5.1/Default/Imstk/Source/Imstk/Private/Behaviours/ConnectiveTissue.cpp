// Fill out your copyright notice in the Description page of Project Settings.


#include "ConnectiveTissue.h"
#include "PBDModel.h"
#include "imstkPbdConnectiveTissueConstraintGenerator.h"
#include "imstkTearable.h"
#include "imstkBurnable.h"
#include "imstkPbdModel.h"
#include "imstkPbdModelConfig.h"

void UConnectiveTissue::InitializeComponent()
{
	Super::InitializeComponent();

	// Check if game is in play mode (required because InitializeComponent() is run when creating a blueprint of the object)
	if (GetWorld() && GetWorld()->GetGameInstance()) {
		// Make the subsystem tick first to update the imstk scene before updating the model in unreal
		AddTickPrerequisiteActor((AActor*)SubsystemInstance);
	}

}

void UConnectiveTissue::Init()
{
	Super::Init();
	UPBDModel* PbdModelA = (UPBDModel*)PBDActorA->GetComponentByClass(UPBDModel::StaticClass());
	UPBDModel* PbdModelB = (UPBDModel*)PBDActorB->GetComponentByClass(UPBDModel::StaticClass());

	if (!PbdModelA || !PbdModelB) {
		return;
	}

	// Init the models if they are not already initialized (subsystem will prevent double initialization)
	if (!PbdModelA->IsInitialized())
		PbdModelA->Init();
	if (!PbdModelB->IsInitialized())
		PbdModelB->Init();

	PbdObject = imstk::makeConnectiveTissue(PbdModelA->PbdObject, PbdModelB->PbdObject, SubsystemInstance->PbdModel, MaxDistance/UMathUtil::GetScale(), StrandsPerFace, SegmentsPerStrand);

	SubsystemInstance->PbdModel->getConfig()->setBodyDamping(PbdObject->getPbdBody()->bodyHandle, LinearDampingCoefficient, AngularDampingCoefficient);

	if (bIsTearable) {
		std::shared_ptr<imstk::Tearable> TearableComp = PbdObject->addComponent<imstk::Tearable>();
		TearableComp->setMaxStrain(MaxStrain);
	}

	if (bIsBurnable)
		std::shared_ptr<imstk::Burnable> BurnableComp = PbdObject->addComponent<imstk::Burnable>();

	ImstkCollidingObject = PbdObject;

	SubsystemInstance->ActiveScene->addSceneObject(PbdObject);

	SubsystemInstance->LogToUnrealAndImstk("Initialized: " + Owner->GetFName().ToString(), FColor::Green);

	Super::bIsInitialized = true;
}

void UConnectiveTissue::UpdateModel()
{
	if (!VisualGeom)
		VisualGeom = std::dynamic_pointer_cast<imstk::LineMesh>(PbdObject->getVisualGeometry());

	if (!bSplinesInitialized)
		InitSplines();

	if (VisualGeom->getNumCells() == Splines.Num()) {
		imstk::VecDataArray<double, 3>& VertexPositions = *VisualGeom->getVertexPositions().get();
		imstk::VecDataArray<int, 2>& Indices = *VisualGeom->getLinesIndices().get();

		// Update positions
		// For Tearable component it never changes the number of indices for the line meshes, however it will set some to 0 if they get deleted
		for (int i = 0; i < Splines.Num(); i++) {

			if (Indices[i].x() != Splines[i].IndexA || Indices[i].y() != Splines[i].IndexB) {
				Splines[i].IndexA = Indices[i].x();
				Splines[i].IndexB = Indices[i].y();
			}
			const FVector UnrealPosA = UMathUtil::ToUnrealFVec(VertexPositions[Splines[i].IndexA], true);
			const FVector UnrealPosB = UMathUtil::ToUnrealFVec(VertexPositions[Splines[i].IndexB], true);
			Splines[i].SplineComp->SetWorldLocationAtSplinePoint(0, UnrealPosA);
			Splines[i].SplineComp->SetWorldLocationAtSplinePoint(1, UnrealPosB);

			const FVector StartTangent = Splines[i].SplineComp->GetTangentAtSplinePoint(0, ESplineCoordinateSpace::World);
			const FVector EndTangent = Splines[i].SplineComp->GetTangentAtSplinePoint(1, ESplineCoordinateSpace::World);

			SplineMeshes[i]->SetStartAndEnd(UnrealPosA, StartTangent, UnrealPosB, EndTangent, true);
		}
	}
	else {
		return;
	}
}

void UConnectiveTissue::InitSplines() 
{
	// For each line segment create a new spline mesh in unreal to represent the connective tissue
	// This will likely have a large amount of overhead, however unsure about perfomance
	auto LineMesh = std::dynamic_pointer_cast<imstk::LineMesh>(PbdObject->getVisualGeometry());

	imstk::VecDataArray<double, 3>& VertexPositions = *LineMesh->getVertexPositions().get();
	imstk::VecDataArray<int, 2>& Indices = *LineMesh->getLinesIndices().get();

	for (int i = 0; i < LineMesh->getNumLines(); i++)
	{
		// Create splines
		auto NewSpline = NewObject<USplineComponent>(this);

		NewSpline->AttachToComponent(Owner->GetRootComponent(), FAttachmentTransformRules::SnapToTargetNotIncludingScale);
		NewSpline->RegisterComponent();
		NewSpline->ClearSplinePoints();

		const FVector UnrealPosA = UMathUtil::ToUnrealFVec(VertexPositions[Indices[i][0]], true);
		const FVector UnrealPosB = UMathUtil::ToUnrealFVec(VertexPositions[Indices[i][1]], true);
		NewSpline->AddSplinePoint(UnrealPosA, ESplineCoordinateSpace::World);
		NewSpline->AddSplinePoint(UnrealPosB, ESplineCoordinateSpace::World);

		Splines.Add(FSplineLineMeshData(NewSpline, Indices[i][0], Indices[i][1]));

		// Add a spline mesh comp for visualization
		USplineMeshComponent* SplineMeshComponent = NewObject<USplineMeshComponent>(this);
		SplineMeshComponent->SetStaticMesh(SplineMesh);
		SplineMeshComponent->SetMobility(EComponentMobility::Movable);
		SplineMeshComponent->CreationMethod = EComponentCreationMethod::UserConstructionScript;
		SplineMeshComponent->RegisterComponent();
		SplineMeshComponent->AttachToComponent(NewSpline, FAttachmentTransformRules::KeepWorldTransform);

		// Only need one start and end for each spline since each are 1 segment long
		const FVector StartTangent = NewSpline->GetTangentAtSplinePoint(0, ESplineCoordinateSpace::World);
		const FVector EndTangent = NewSpline->GetTangentAtSplinePoint(1, ESplineCoordinateSpace::World);

		SplineMeshComponent->SetStartAndEnd(UnrealPosA, StartTangent, UnrealPosB, EndTangent, true);
		SplineMeshComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		SplineMeshComponent->SetForwardAxis(ForwardAxis);
		if (SplineMeshMaterial)
			SplineMeshComponent->SetMaterial(0, SplineMeshMaterial);

		SplineMeshComponent->UpdateMesh();

		SplineMeshes.Add(SplineMeshComponent);
	}
	bSplinesInitialized = true;
}

void UConnectiveTissue::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (Super::bIsInitialized) {
		UpdateModel();
	}
}

void UConnectiveTissue::UnInit()
{
	Super::UnInit();
	VisualGeom.reset();
}