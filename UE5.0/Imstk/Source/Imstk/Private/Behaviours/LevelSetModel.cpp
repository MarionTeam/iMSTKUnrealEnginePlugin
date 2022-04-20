// Fill out your copyright notice in the Description page of Project Settings.


#include "LevelSetModel.h"
#include "iMSTK-5.0/imstkSurfaceMeshDistanceTransform.h"
#include "iMSTK-5.0/imstkLevelSetModel.h"
#include "Engine/GameEngine.h"


void ULevelSetModel::InitializeComponent()
{
	Super::InitializeComponent();
	// Check if game is in play mode (required because InitializeComponent() is run when creating a blueprint of the object)
	if (GetWorld() && GetWorld()->GetGameInstance()) {
		// Make the subsystem tick first to update the imstk scene before updating the model in unreal
		AddTickPrerequisiteActor((AActor*)SubsystemInstance);

		/*if (UProceduralMeshComponent* Comp = (UProceduralMeshComponent*)Owner->GetComponentByClass(UProceduralMeshComponent::StaticClass()))
		{
			MeshComp = Comp;
		}*/
		if (UStaticMeshComponent* StaticMesh = (UStaticMeshComponent*)Owner->GetComponentByClass(UStaticMeshComponent::StaticClass()))
		{
			// Create procedural mesh, convert static mesh to procedural and then disable static mesh
			MeshComp = NewObject<UProceduralMeshComponent>(this);
			// If including scale, scale gets applied twice
			MeshComp->AttachToComponent(Owner->GetRootComponent(), FAttachmentTransformRules::SnapToTargetNotIncludingScale);
			MeshComp->RegisterComponent();

			//if(!TetrahedralMesh)
			// Currently using this even when there is a tetrahedral mesh to apply the materials to the procedural mesh
			ConvertStaticToProceduralMesh(StaticMesh, MeshComp);

			StaticMesh->SetVisibility(false);
		}
		else
		{
			// No mesh attached error
			UE_LOG(LogTemp, Error, TEXT("Error Initializing: %s. No mesh component attached to actor"), *Owner->GetName());
			SubsystemInstance->AllBehaviours.Remove(this);
		}
	}

}

// Called when the game starts or when spawned
void ULevelSetModel::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ULevelSetModel::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (Super::bIsInitalized) {
		UpdateModel();
	}
}

void ULevelSetModel::Init()
{
	Super::Init();
	if ( GeomFilter.GeomType != EGeometryType::SurfaceMesh) {
		UE_LOG(LogTemp, Error, TEXT("LevelSetModels can only be SurfaceMeshes"));
		return;
	}
	std::shared_ptr<imstk::SurfaceMesh> SurfMesh = std::dynamic_pointer_cast<imstk::SurfaceMesh> (GetCollidingGeometry());

	std::shared_ptr<imstk::SurfaceMeshDistanceTransform> ComputeSdf = std::make_shared<imstk::SurfaceMeshDistanceTransform>();
	ComputeSdf->setInputMesh(SurfMesh);
	ComputeSdf->setDimensions(50, 50, 50);
	ComputeSdf->update();
	std::shared_ptr<imstk::ImageData> InitLvlsetImage = ComputeSdf->getOutputImage();

	std::shared_ptr<imstk::LevelSetModelConfig> Config = std::make_shared<imstk::LevelSetModelConfig>();
	Config->m_sparseUpdate = false;
	Config->m_dt = 0.003;
	Config->m_constantVelocity = -1.0;

	std::shared_ptr<imstk::LevelSetModel> DynamicalModel = std::make_shared<imstk::LevelSetModel>();
	DynamicalModel->setModelGeometry(InitLvlsetImage);
	DynamicalModel->configure(Config);

	LevelsetObj = std::make_shared<imstk::LevelSetDeformableObject>(TCHAR_TO_UTF8(*(Owner->GetName())));

	LevelsetObj->setVisualGeometry(InitLvlsetImage);
	LevelsetObj->setPhysicsGeometry(InitLvlsetImage);
	LevelsetObj->setDynamicalModel(DynamicalModel);

	LOG(WARNING) << "Imstk: " << InitLvlsetImage->getBounds();

	Super::bIsInitalized = true;
}

void ULevelSetModel::UpdateModel() 
{
	if (GEngine) {
		//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, "Imstk: " + std::dynamic_pointer_cast<imstk::ImageData>(LevelsetObj->getVisualGeometry())->getVertexPositions()->size());
		//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, "Unreal: " + MeshComp->GetProcMeshSection(0)->ProcVertexBuffer.Num());
	}

	//LOG(WARNING) << "Imstk: " << std::dynamic_pointer_cast<imstk::ImageData>(LevelsetObj->getVisualGeometry())->getVertexPositions()->size();
	//LOG(WARNING) << "Unreal: "<< MeshComp->GetProcMeshSection(0)->ProcVertexBuffer.Num();
}