// Fill out your copyright notice in the Description page of Project Settings.


#include "NeedleObject.h"
#include "ImstkSettings.h"
#include "imstkPbdModel.h"
#include "Interfaces/IPluginManager.h"
#include "imstkIsometricMap.h"
#include "imstkNeedle.h"
#include "imstkMeshIO.h"

// Called when the game starts or when spawned
void UNeedleObject::BeginPlay()
{
	Super::BeginPlay();
}

void UNeedleObject::InitializeComponent()
{
	UDynamicalModel::InitializeComponent();
	// Check if game is in play mode (required because InitializeComponent() is run when creating a blueprint of the object)
	if (GetWorld() && GetWorld()->GetGameInstance()) {
		// Make the subsystem tick first to update the imstk scene before updating the model in unreal
		AddTickPrerequisiteActor((AActor*)SubsystemInstance);
		ProcMeshComp = NewObject<UProceduralMeshComponent>(this);
		ProcMeshComp->AttachToComponent(Owner->GetRootComponent(), FAttachmentTransformRules::SnapToTargetNotIncludingScale);
		ProcMeshComp->RegisterComponent();
			
	}

}
void UNeedleObject::Init()
{
	// Create a Pbd object with a rigid body for the needle, visuals are the needle mesh and colliding and phyics are a line mesh

	Needle = std::make_shared<imstk::PbdObject>(TCHAR_TO_UTF8(*(Owner->GetName())));
	FString ContentDir = IPluginManager::Get().FindPlugin((TEXT("Imstk")))->GetContentDir();
	auto SutureMesh = imstk::MeshIO::read<imstk::SurfaceMesh>(std::string(TCHAR_TO_UTF8(*(ContentDir + "/ExtraFiles/Needles/c6_suture.stl"))));
	auto SutureLineMesh = imstk::MeshIO::read<imstk::LineMesh>(std::string(TCHAR_TO_UTF8(*(ContentDir + "/ExtraFiles/Needles/c6_suture_hull.vtk"))));
	SutureMesh->translate(imstk::Vec3d(0.0, -0.0047, -0.0087), imstk::Geometry::TransformType::ApplyToData);
	SutureLineMesh->translate(imstk::Vec3d(0.0, -0.0047, -0.0087), imstk::Geometry::TransformType::ApplyToData);

	SutureMesh->scale(UMathUtil::ToImstkVec3d(Owner->GetActorScale(), false), imstk::Geometry::TransformType::ApplyToData);
	SutureLineMesh->scale(UMathUtil::ToImstkVec3d(Owner->GetActorScale(), false), imstk::Geometry::TransformType::ApplyToData);

	Needle->setVisualGeometry(SutureMesh);
	Needle->setCollidingGeometry(SutureLineMesh);
	Needle->setPhysicsGeometry(SutureLineMesh);
	Needle->setPhysicsToVisualMap(std::make_shared<imstk::IsometricMap>(SutureLineMesh, SutureMesh));

	std::shared_ptr<imstk::PbdModel> PbdModel = SubsystemInstance->PbdModel;
	
	Needle->setDynamicalModel(PbdModel);

	Needle->getPbdBody()->setRigid(UMathUtil::ToImstkVec3d(Owner->GetActorLocation(), true), 1, imstk::Quatd::Identity(), imstk::Mat3d::Identity() * 0.01);

	Needle->addComponent<imstk::Needle>();

	{
		std::shared_ptr<imstk::SurfaceMesh> NeedleVisGeom = std::dynamic_pointer_cast<imstk::SurfaceMesh>(Needle->getVisualGeometry());
		NeedleVisGeom->computeVertexNormals();
		imstk::VecDataArray<double, 3>& ImstkNorms = *NeedleVisGeom->getVertexNormals();

		TArray<FVector2D> UV0;
		TArray<FLinearColor> VertColors;
		TArray<FProcMeshTangent> Tangents;

		TArray<FVector> Verts;
		TArray<FVector> Normals;
		TArray<int32> Indices;

		// Use normals from imstk
		Normals.Empty();
		for (int i = 0; i < ImstkNorms.size(); i++) {
			Normals.Add(UMathUtil::ToUnrealFVec(ImstkNorms[i], false));
		}

		// Get vertex data from imstk
		Verts = UMathUtil::ToUnrealFVecArray(NeedleVisGeom->getVertexPositions(), true);

		Indices = UMathUtil::ToUnrealIntArray(NeedleVisGeom->getTriangleIndices());

		// Create the mesh sections on the procedural meshes
		ProcMeshComp->CreateMeshSection_LinearColor(0, Verts, Indices, Normals, UV0, VertColors, Tangents, false);
	}

	SubsystemInstance->ActiveScene->addSceneObject(Needle);
	ImstkCollidingObject = Needle;
	Super::bIsInitialized = true;

}

FVector UNeedleObject::GetVertexPosition(int Vert)
{
	return UMathUtil::ToUnrealFVec(std::dynamic_pointer_cast<imstk::LineMesh>(Needle->getPhysicsGeometry())->getVertexPosition(Vert), true);
}


// Called every frame
void UNeedleObject::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Owner->SetActorLocationAndRotation(UMathUtil::ToUnrealFVec((*Needle->getPbdBody()->vertices)[0], true), UMathUtil::ToUnrealFQuat((*Needle->getPbdBody()->orientations)[0]));
}

void UNeedleObject::UnInit()
{
	Super::UnInit();

}