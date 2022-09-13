// Fill out your copyright notice in the Description page of Project Settings.


#include "LevelSetModel.h"
#include "Materials/MaterialInstanceDynamic.h"

#include "imstkSurfaceMeshDistanceTransform.h"
#include "imstkLevelSetModel.h"

#include "imstkVisualModel.h"
#include "imstkSignedDistanceField.h"
#include "imstkTaskGraph.h"
#include "imstkImageData.h"
#include "imstkSurfaceMesh.h"
#include "imstkSurfaceMeshFlyingEdges.h"


void ULevelSetModel::InitializeComponent()
{
	Super::InitializeComponent();
	// Check if game is in play mode (required because InitializeComponent() is run when creating a blueprint of the object)
	if (GetWorld() && GetWorld()->GetGameInstance()) {
		// Make the subsystem tick first to update the imstk scene before updating the model in unreal
		AddTickPrerequisiteActor((AActor*)SubsystemInstance);

		if (EditorMeshComp)
			EditorMeshComp->DestroyComponent();

		if (UProceduralMeshComponent* Comp = (UProceduralMeshComponent*)Owner->GetComponentByClass(UProceduralMeshComponent::StaticClass()))
		{
			MeshComp = Comp;
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
		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, "LevelSetModels can only be SurfaceMeshes");
		UE_LOG(LogTemp, Error, TEXT("LevelSetModels can only be SurfaceMeshes"));
		return;
	}
	if (!ImageData) {
		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, "LevelSetModels can only be SurfaceMeshes");
		UE_LOG(LogTemp, Error, TEXT("ImageData not Assigned on LevelSetModel"));
		return;
	}

	LevelSetObj = std::make_shared<LevelSetObject>(MeshComp, ImageData, ImageMaterial);
	SubsystemInstance->ActiveScene->addSceneObject(LevelSetObj);
	ImstkCollidingObject = LevelSetObj;

	// Set the location of the component to 0,0,0 because of how the image data is positioned
	MeshComp->SetWorldLocation(FVector::Zero());

	Super::bIsInitialized = true;
}

void ULevelSetModel::UpdateModel()
{
	LevelSetObj->visualUpdate();
}

FMeshDataStruct ULevelSetModel::GenerateSurfaceMeshData(bool FlipNormals)
{
	FMeshDataStruct MeshData = FMeshDataStruct();
	if (!ImageData)
		return MeshData;

	MeshComp = (UProceduralMeshComponent*)GetOwner()->GetComponentByClass(UProceduralMeshComponent::StaticClass());

	std::shared_ptr<imstk::SurfaceMeshFlyingEdges> SMFE = std::make_shared<imstk::SurfaceMeshFlyingEdges>();
	std::shared_ptr<imstk::ImageData> LvlSetImage = ImageData->GetImageData();

	// Scale the iMSTK level set model appropriately
	const imstk::Vec3d& currSpacing = LvlSetImage->getSpacing();
	const FVector UnrealScale = MeshComp->GetComponentScale(); // TODO: This is annoying since its an actor component and not a scene component so you can't scale the actual model. maybe transform this into a scene component
	imstk::Vec3d scaledSpacing = imstk::Vec3d(currSpacing.x() * UnrealScale.X, currSpacing.y() * UnrealScale.Z, currSpacing.z() * UnrealScale.Y);
	LvlSetImage->setSpacing(scaledSpacing);

	// Extract the surface mesh of the model
	SMFE->setInputImage(LvlSetImage);
	SMFE->update();
	std::shared_ptr<imstk::SurfaceMesh> SurfMesh = SMFE->getOutputMesh();
	SurfMesh->computeVertexNormals();
	if (FlipNormals)
		SurfMesh->flipNormals();

	// Assign mesh values to the struct and return
	MeshData.Verts = UMathUtil::ToUnrealFVecArray(SurfMesh->getVertexPositions(), true);
	MeshData.Indices = UMathUtil::ToUnrealIntArray(SurfMesh->getTriangleIndices());
	MeshData.Normals = UMathUtil::ToUnrealFVecArray(SurfMesh->getVertexNormals(), false);

	return MeshData;
}

void ULevelSetModel::UnInit() 
{
	Super::UnInit();
	LevelSetObj.reset();
}

//void ULevelSetModel::GenerateSurfaceMeshData() 
//{
//	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, "Creating mesh file");
//	std::shared_ptr<imstk::SurfaceMeshFlyingEdges> SMFE = std::make_shared<imstk::SurfaceMeshFlyingEdges>();
//
//	SMFE->setInputImage(LevelSetObject->initLvlSetImage);
//	SMFE->update();
//	imstk::MeshIO::write(SMFE->getOutputMesh(), std::string(TCHAR_TO_UTF8(*FPaths::ProjectLogDir())) + "outputMesh.stl");
//}
//
//void ULevelSetModel::GenerateLevelSetData()
//{
//	imstk::MeshIO::write(LevelSetObject->initLvlSetImage, std::string(TCHAR_TO_UTF8(*FPaths::ProjectLogDir())) + "outputMesh.mhd");
//}





LevelSetObject::LevelSetObject(UProceduralMeshComponent* ProcMeshComp, UImageDataAsset* ImageData, UMaterial* Material) : LevelSetDeformableObject("LevelSetObject"),
m_isoExtract(std::make_shared<imstk::LocalMarchingCubes>())
{
	MeshComp = ProcMeshComp;
	this->Material = Material;
	initLvlSetImage = ImageData->GetImageData();

	const imstk::Vec3d& currSpacing = initLvlSetImage->getSpacing();
	const FVector UnrealScale = MeshComp->GetComponentScale(); // TODO: This is annoying since its an actor component and not a scene component so you can't scale the actual model. maybe transform this into a scene component

	imstk::Vec3d scaledSpacing = imstk::Vec3d(currSpacing.x() * UnrealScale.X, currSpacing.y() * UnrealScale.Z, currSpacing.z() * UnrealScale.Y);
	initLvlSetImage->setSpacing(scaledSpacing);

	MeshComp->SetWorldScale3D(FVector(1, 1, 1));

	// Note: Anistropic scaling would invalidate the SDF
	initLvlSetImage->setOrigin(UMathUtil::ToImstkVec3d(MeshComp->GetComponentLocation(), true));
	//initLvlSetImage->setOrigin(imstk::Vec3d(0, 0, 0));

	// Setup the Parameters
	std::shared_ptr<imstk::LevelSetModelConfig> lvlSetConfig = std::make_shared<imstk::LevelSetModelConfig>();
	lvlSetConfig->m_sparseUpdate = true;
	lvlSetConfig->m_substeps = 15;
	lvlSetConfig->m_dt = 0.001;

	// Too many chunks and you'll hit memory constraints quickly
	// Too little chunks and the updates for a chunk will take too long
	// The chunks must divide the image dimensions-1 (image dim-1 must be divisible by # chunks)
	m_isoExtract->setInputImage(initLvlSetImage);
	m_isoExtract->setIsoValue(0.0);
	//m_isoExtract->setNumberOfChunks(imstk::Vec3i(32, 9, 9));

	const imstk::Vec3i& Dimensions = initLvlSetImage->getDimensions();
	m_isoExtract->setNumberOfChunks(imstk::Vec3i((Dimensions.x() - 1) / 10, (Dimensions.y() - 1) / 10, (Dimensions.z() - 1) / 10));
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
		std::bind(&LevelSetObject::updateModifiedVoxels, this), "Isosurface: SetModifiedVoxels");
	m_taskGraph->addNode(m_forwardModifiedVoxels);
}

void
LevelSetObject::visualUpdate()
{
	// Update any chunks that contain a voxel which was set modified
	m_isoExtract->update();

	// Create meshes for chunks if they now contain vertices (and weren't already generated)
	// You could just create all the chunks, but this saves some memory for internal/empty ones
	createVisualModels();

	UpdateUnrealMesh();
}

void
LevelSetObject::createVisualModels()
{
	const imstk::Vec3i& numChunks = m_isoExtract->getNumberOfChunks();
	for (int i = 0; i < numChunks[0] * numChunks[1] * numChunks[2]; i++)
	{
		auto surfMesh = std::dynamic_pointer_cast<imstk::SurfaceMesh>(m_isoExtract->getOutput(i));
		if (surfMesh->getNumVertices() > 0 && m_chunksGenerated.count(i) == 0)
		{
			//LOG(WARNING) << "New visual";
			std::shared_ptr<imstk::VisualModel> surfMeshModel = std::make_shared<imstk::VisualModel>();
			surfMeshModel->setGeometry(m_isoExtract->getOutput(i));

			TArray<FVector2D> UV0;
			/*for (int j = 0; j < surfMesh->getNumVertices(); j++) {
				UV0.Add(FVector2D(FMath::FRand(), FMath::FRand()));
			}*/

			TArray<FLinearColor> VertColors;
			TArray<FProcMeshTangent> Tangents;
			imstk::VecDataArray<double, 3>& ImstkNorms = *surfMesh->getVertexNormals();

			TArray<FVector> Verts;
			Verts = UMathUtil::ToUnrealFVecArray(surfMesh->getVertexPositions(), true);

			TArray<FVector> Normals;
			for (int j = 0; j < ImstkNorms.size(); j++) {
				Normals.Add(UMathUtil::ToUnrealFVec(ImstkNorms[j], false));
			}

			TArray<int32> Indices = UMathUtil::ToUnrealIntArray(surfMesh->getTriangleIndices());

			MeshComp->CreateMeshSection_LinearColor(i, Verts, Indices, Normals, UV0, VertColors, Tangents, false);

			if (Material) {
				auto* MaterialInstance = UMaterialInstanceDynamic::Create(Material, Material);
				MeshComp->SetMaterial(i, MaterialInstance);
			}
			addVisualModel(surfMeshModel);
			m_chunksGenerated.insert(i);
		}
	}
}

void
LevelSetObject::updateModifiedVoxels()
{
	// Forward the level set's modified nodes to the isosurface extraction
	for (auto i : getLevelSetModel()->getNodesToUpdate())
	{
		m_isoExtract->setModified(std::get<0>(i.second));
	}
}

void
LevelSetObject::initGraphEdges(std::shared_ptr<imstk::TaskNode> source, std::shared_ptr<imstk::TaskNode> sink)
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

void
LevelSetObject::UpdateUnrealMesh()
{

	std::unordered_map<int, imstk::Vec3i> modifiedChunks = m_isoExtract->getModifiedChunks();
	for (auto i : modifiedChunks)
	{
		auto surfMesh = std::dynamic_pointer_cast<imstk::SurfaceMesh>(m_isoExtract->getOutput(i.first));
		if (surfMesh->getNumVertices() > 0) {
			TArray<FVector2D> UV0;
			/*for (int j = 0; j < surfMesh->getNumVertices(); j++) {
				UV0.Add(FVector2D(FMath::FRand(), FMath::FRand()));
			}*/

			TArray<FLinearColor> VertColors;
			TArray<FProcMeshTangent> Tangents;
			imstk::VecDataArray<double, 3>& ImstkNorms = *surfMesh->getVertexNormals();
			TArray<FVector> Normals;
			for (int j = 0; j < ImstkNorms.size(); j++) {
				Normals.Add(UMathUtil::ToUnrealFVec(ImstkNorms[j], false));
			}

			TArray<FVector> Verts;
			Verts = UMathUtil::ToUnrealFVecArray(surfMesh->getVertexPositions(), true);

			/*if (Verts.Num() == MeshComp->GetProcMeshSection(i.first)->ProcVertexBuffer.Num() && surfMesh->getNumTriangles() * 3 == MeshComp->GetProcMeshSection(i.first)->ProcIndexBuffer.Num()) {
				MeshComp->UpdateMeshSection_LinearColor(i.first, Verts, Normals, UV0, VertColors, Tangents);
			}
			else {*/
			TArray<int32> Indices = UMathUtil::ToUnrealIntArray(surfMesh->getTriangleIndices());

			MeshComp->ClearMeshSection(i.first);
			MeshComp->CreateMeshSection_LinearColor(i.first, Verts, Indices, Normals, UV0, VertColors, Tangents, false);
			//}
			if (Material) {
				auto* MaterialInstance = UMaterialInstanceDynamic::Create(Material, Material);
				MeshComp->SetMaterial(i.first, MaterialInstance);
			}
		}
		else
		{
			MeshComp->ClearMeshSection(i.first);
		}
	}
}