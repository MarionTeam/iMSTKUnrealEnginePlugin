// Fill out your copyright notice in the Description page of Project Settings.


#include "LevelSetModel.h"
#include "imstkSurfaceMeshDistanceTransform.h"
#include "imstkLevelSetModel.h"
#include "Engine/GameEngine.h"

//TEMP
#include "imstkMeshIO.h"
#include "imstkVisualModel.h"
#include "imstkSignedDistanceField.h"
#include "imstkTaskGraph.h"
#include "imstkImageData.h"
#include "imstkSurfaceMesh.h"



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

	if (Super::bIsInitialized) {
		UpdateModel();
	}
}


void ULevelSetModel::Init()
{
	Super::Init();
	if (GeomFilter.GeomType != EGeometryType::SurfaceMesh) {
		UE_LOG(LogTemp, Error, TEXT("LevelSetModels can only be SurfaceMeshes"));
		return;
	}
	//std::shared_ptr<imstk::ImageData> initLvlSetImage = imstk::MeshIO::read<imstk::ImageData>("D:/IMSTK/FreshInstall/release-build/install/data/legs/femurBoneSolid_SDF.nii")->cast(IMSTK_DOUBLE);

	std::shared_ptr<imstk::SurfaceMesh> dragonSurfMesh = imstk::MeshIO::read<imstk::SurfaceMesh>("D:/IMSTK/FreshInstall/release-build/install/data/asianDragon/asianDragon.obj");

	std::shared_ptr<imstk::SurfaceMeshDistanceTransform> computeSdf = std::make_shared<imstk::SurfaceMeshDistanceTransform>();
	computeSdf->setInputMesh(dragonSurfMesh);
	computeSdf->setDimensions(50, 50, 50);
	computeSdf->update();
	std::shared_ptr<imstk::ImageData> initLvlsetImage = computeSdf->getOutputImage();
	//imstk::Vec3i Dims = initLvlsetImage->getDimensions();
	//imstk::Vec3i Dims = computeSdf->getDimensions();

	LOG(WARNING) << "TEST";
	initLvlsetImage->print();
	//LOG(WARNING) << "x: " << initLvlsetImage->getDimensions(0);
	//LOG(WARNING) << "y: " << initLvlsetImage->getDimensions(1);
	//LOG(WARNING) << "z: " << initLvlsetImage->getDimensions(2);

	//TESTObj = std::make_shared<FemurObject>();
	//SubsystemInstance->ActiveScene->addSceneObject(TESTObj);

	Super::bIsInitialized = true;
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


void ULevelSetModel::CreateVisualSections()
{
	const imstk::Vec3i& numChunks = m_isoExtract->getNumberOfChunks();
	for (int i = 0; i < numChunks[0] * numChunks[1] * numChunks[2]; i++)
	{
		auto surfMesh = std::dynamic_pointer_cast<imstk::SurfaceMesh>(m_isoExtract->getOutput(i));
		if (surfMesh->getNumVertices() > 0 && m_chunksGenerated.count(i) == 0)
		{
			std::shared_ptr<imstk::VisualModel> surfMeshModel = std::make_shared<imstk::VisualModel>();
			surfMeshModel->setGeometry(m_isoExtract->getOutput(i));
			//imstkNew<RenderMaterial> material;
			//material->setDisplayMode(RenderMaterial::DisplayMode::Surface);
			//material->setLineWidth(4.0);
			//if (m_useRandomChunkColors)
			//{
			//	const double r = (rand() % 10000) / 10000.0;
			//	const double g = (rand() % 10000) / 10000.0;
			//	const double b = (rand() % 10000) / 10000.0;
			//	material->setColor(Color(r, g, b));
			//}
			//else
			//{
			//	material->setColor(Color::Bone);
			//}
			////material->setOpacity(0.7);
			//surfMeshModel->setRenderMaterial(material);
			LevelsetObj->addVisualModel(surfMeshModel);
			m_chunksGenerated.insert(i);
		}
	}
}




FemurObject::FemurObject() : LevelSetDeformableObject("Femur"),
m_isoExtract(std::make_shared<imstk::LocalMarchingCubes>())
{
	std::shared_ptr<imstk::ImageData> initLvlSetImage = imstk::MeshIO::read<imstk::ImageData>("D:/IMSTK/FreshInstall/release-build/install/data/legs/femurBoneSolid_SDF.nii")->cast(IMSTK_DOUBLE);
	//const Vec3d& currSpacing = initLvlSetImage->getSpacing();
	LOG(WARNING) << "TEST";
	LOG(WARNING) << "x: " << initLvlSetImage->getDimensions().x();
	LOG(WARNING) << "y: " << initLvlSetImage->getDimensions().y();
	LOG(WARNING) << "z: " << initLvlSetImage->getDimensions().z();
	// Note: Anistropic scaling would invalidate the SDF
	initLvlSetImage->setOrigin(imstk::Vec3d(0.0, 0.8, 1.5));

	// Setup the Parameters
	std::shared_ptr<imstk::LevelSetModelConfig> lvlSetConfig = std::make_shared<imstk::LevelSetModelConfig>();
	lvlSetConfig->m_sparseUpdate = true;
	lvlSetConfig->m_substeps = 15;

	// Too many chunks and you'll hit memory constraints quickly
	// Too little chunks and the updates for a chunk will take too long
	// The chunks must divide the image dimensions-1 (image dim-1 must be divisible by # chunks)
	m_isoExtract->setInputImage(initLvlSetImage);
	m_isoExtract->setIsoValue(0.0);
	m_isoExtract->setNumberOfChunks(imstk::Vec3i(32, 9, 9));
	m_isoExtract->update();

	if (m_useRandomChunkColors)
	{
		srand(static_cast<unsigned int>(time(NULL)));
	}

	createVisualModels();

	// Setup the Object
	std::shared_ptr<imstk::SignedDistanceField> sdf = std::make_shared<imstk::SignedDistanceField>(initLvlSetImage);

	// Setup the Model
	std::shared_ptr<imstk::LevelSetModel> model = std::make_shared<imstk::LevelSetModel>();
	model->setModelGeometry(sdf);
	model->configure(lvlSetConfig);

	setPhysicsGeometry(sdf);
	setCollidingGeometry(sdf);
	setDynamicalModel(model);

	// Setup a custom task to forward the modified voxels of the level set model
	// to the marching cubes before they're cleared
	m_forwardModifiedVoxels = std::make_shared<imstk::TaskNode>(
		std::bind(&FemurObject::updateModifiedVoxels, this), "Isosurface: SetModifiedVoxels");
	m_taskGraph->addNode(m_forwardModifiedVoxels);
}

void
FemurObject::visualUpdate()
{
	// Update any chunks that contain a voxel which was set modified
	m_isoExtract->update();

	// Create meshes for chunks if they now contain vertices (and weren't already generated)
	// You could just create all the chunks, but this saves some memory for internal/empty ones
	createVisualModels();
}

void
FemurObject::createVisualModels()
{
	const imstk::Vec3i& numChunks = m_isoExtract->getNumberOfChunks();
	for (int i = 0; i < numChunks[0] * numChunks[1] * numChunks[2]; i++)
	{
		auto surfMesh = std::dynamic_pointer_cast<imstk::SurfaceMesh>(m_isoExtract->getOutput(i));
		if (surfMesh->getNumVertices() > 0 && m_chunksGenerated.count(i) == 0)
		{
			std::shared_ptr<imstk::VisualModel> surfMeshModel = std::make_shared<imstk::VisualModel>();
			surfMeshModel->setGeometry(m_isoExtract->getOutput(i));
			//std::shared_ptr<imstk::RenderMaterial> material = std::make_shared<imstk::RenderMaterial>();
			//material->setDisplayMode(imstk::RenderMaterial::DisplayMode::Surface);
			//material->setLineWidth(4.0);
			//if (m_useRandomChunkColors)
			//{
			//	const double r = (rand() % 10000) / 10000.0;
			//	const double g = (rand() % 10000) / 10000.0;
			//	const double b = (rand() % 10000) / 10000.0;
			//	material->setColor(Color(r, g, b));
			//}
			//else
			//{
			//	material->setColor(Color::Bone);
			//}
			////material->setOpacity(0.7);
			//surfMeshModel->setRenderMaterial(material);
			addVisualModel(surfMeshModel);
			m_chunksGenerated.insert(i);
		}
	}
}

void
FemurObject::updateModifiedVoxels()
{
	// Forward the level set's modified nodes to the isosurface extraction
	for (auto i : getLevelSetModel()->getNodesToUpdate())
	{
		m_isoExtract->setModified(std::get<0>(i.second));
	}
}

void
FemurObject::initGraphEdges(std::shared_ptr<imstk::TaskNode> source, std::shared_ptr<imstk::TaskNode> sink)
{
	// Copy, sum, and connect the model graph to nest within this graph
	m_taskGraph->addEdge(source, getUpdateNode());

	m_dynamicalModel->initGraphEdges();
	m_taskGraph->nestGraph(m_dynamicalModel->getTaskGraph(), getUpdateNode(), getUpdateGeometryNode());

	// The levelsetmodel produces a list of modified voxels, we forward that to the isosurface extraction
	// filter to update only the modified chunks
	m_taskGraph->addEdge(getLevelSetModel()->getGenerateVelocitiesEndNode(), m_forwardModifiedVoxels);
	m_taskGraph->addEdge(m_forwardModifiedVoxels, getLevelSetModel()->getQuantityEvolveNode(0));

	m_taskGraph->addEdge(getUpdateGeometryNode(), sink);
}