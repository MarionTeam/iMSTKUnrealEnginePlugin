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
#include "imstkMeshIO.h"

void ULevelSetModel::InitializeComponent()
{
	Super::InitializeComponent();
	// Check if game is in play mode (required because InitializeComponent() is run when creating a blueprint of the object)
	if (GetWorld() && GetWorld()->GetGameInstance()) {
		// Make the subsystem tick first to update the imstk scene before updating the Model in unreal
		AddTickPrerequisiteActor((AActor*)SubsystemInstance);

		if (EditorMeshComp)
			EditorMeshComp->DestroyComponent();

		if (UProceduralMeshComponent* Comp = (UProceduralMeshComponent*)Owner->GetComponentByClass(UProceduralMeshComponent::StaticClass()))
		{
			MeshComp = Comp;
		}
		else
		{
			MeshComp = NewObject<UProceduralMeshComponent>(this);
			// If including scale, scale gets applied twice
			MeshComp->AttachToComponent(Owner->GetRootComponent(), FAttachmentTransformRules::SnapToTargetNotIncludingScale);
			MeshComp->RegisterComponent();
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
	if (bDelayInit)
		return;
	Super::Init();

	if (GeomFilter.GeomType != EGeometryType::SurfaceMesh) {
		SubsystemInstance->LogToUnrealAndImstk("LevelSetModels can only be SurfaceMeshes for " + Owner->GetName(), FColor::Red);
		return;
	}
	if (!ImageData) {
		std::shared_ptr<imstk::SurfaceMesh> MeshGeom = GetSurfaceMeshFromStatic();
		if (!MeshGeom) {
			SubsystemInstance->LogToUnrealAndImstk("Error Initializing: " + Owner->GetName() + " no static mesh attached to actor", FColor::Red);
			return;
		}

		if (BoundingActor)
			FindBounds();

		LevelSetObj = std::make_shared<LevelSetObject>(MeshComp, MeshGeom, this, ImageMaterial);
	}
	else {
		LevelSetObj = std::make_shared<LevelSetObject>(MeshComp, ImageData, this, ImageMaterial);
	}

	ImstkCollidingObject = LevelSetObj;

	// Set the location of the component to 0,0,0 because of how the image data is positioned
	MeshComp->SetWorldLocation(FVector::Zero());
	MeshComp->SetWorldRotation(FRotator::ZeroRotator);


	SubsystemInstance->ActiveScene->addSceneObject(LevelSetObj);

	SubsystemInstance->LogToUnrealAndImstk("Initialized: " + Owner->GetFName().ToString(), FColor::Green);

	Super::bIsInitialized = true;
}

void ULevelSetModel::UpdateModel()
{
	LevelSetObj->visualUpdate();
}

void ULevelSetModel::FindBounds()
{
	UStaticMeshComponent* BoundaryMeshComp = (UStaticMeshComponent*)BoundingActor->GetComponentByClass(UStaticMeshComponent::StaticClass());
	if (!BoundaryMeshComp) {
		SubsystemInstance->LogToUnrealAndImstk("No mesh attached to bounding actor for " + Owner->GetName(), FColor::Red);
	}
	if (!BoundaryMeshComp->GetStaticMesh()->bAllowCPUAccess)
		FMessageLog("PIE").Warning(FText::FromString("'Allow CPU Access' is not enabled for " + BoundaryMeshComp->GetStaticMesh()->GetFName().ToString() + ". This is required to access static mesh data in the packaged game."));

	UStaticMesh* BoundaryMesh = BoundaryMeshComp->GetStaticMesh();
	FPositionVertexBuffer* VertexBuffer = &BoundaryMesh->GetRenderData()->LODResources[0].VertexBuffers.PositionVertexBuffer;

	MinBounds.X = VertexBuffer->VertexPosition(0).X * BoundaryMeshComp->GetComponentScale().X;
	MinBounds.Y = VertexBuffer->VertexPosition(0).Y * BoundaryMeshComp->GetComponentScale().Y;
	MinBounds.Z = VertexBuffer->VertexPosition(0).Z * BoundaryMeshComp->GetComponentScale().Z;

	MaxBounds.X = VertexBuffer->VertexPosition(0).X * BoundaryMeshComp->GetComponentScale().X;
	MaxBounds.Y = VertexBuffer->VertexPosition(0).Y * BoundaryMeshComp->GetComponentScale().Y;
	MaxBounds.Z = VertexBuffer->VertexPosition(0).Z * BoundaryMeshComp->GetComponentScale().Z;

	// TODO: Maybe a more efficient way to do this by getting already transformed values for vertices
	for (uint32 i = 1; i < VertexBuffer->GetNumVertices(); i++) {
		FVector3f Vert = VertexBuffer->VertexPosition(i);
		if ((Vert.X * BoundaryMeshComp->GetComponentScale().X) < MinBounds.X)
			MinBounds.X = Vert.X * BoundaryMeshComp->GetComponentScale().X;
		else if ((Vert.X * BoundaryMeshComp->GetComponentScale().X) > MaxBounds.X)
			MaxBounds.X = Vert.X * BoundaryMeshComp->GetComponentScale().X;

		if ((Vert.Y * BoundaryMeshComp->GetComponentScale().Y) < MinBounds.Y)
			MinBounds.Y = Vert.Y * BoundaryMeshComp->GetComponentScale().Y;
		else if ((Vert.Y * BoundaryMeshComp->GetComponentScale().Y) > MaxBounds.Y)
			MaxBounds.Y = Vert.Y * BoundaryMeshComp->GetComponentScale().Y;

		if ((Vert.Z * BoundaryMeshComp->GetComponentScale().Z) < MinBounds.Z)
			MinBounds.Z = Vert.Z * BoundaryMeshComp->GetComponentScale().Z;
		else if ((Vert.Z * BoundaryMeshComp->GetComponentScale().Z) > MaxBounds.Z)
			MaxBounds.Z = Vert.Z * BoundaryMeshComp->GetComponentScale().Z;
	}

	MinBounds.X += BoundaryMeshComp->GetComponentLocation().X;
	MinBounds.Y += BoundaryMeshComp->GetComponentLocation().Y;
	MinBounds.Z += BoundaryMeshComp->GetComponentLocation().Z;

	MaxBounds.X += BoundaryMeshComp->GetComponentLocation().X;
	MaxBounds.Y += BoundaryMeshComp->GetComponentLocation().Y;
	MaxBounds.Z += BoundaryMeshComp->GetComponentLocation().Z;

	BoundingActor->Destroy();
}

std::shared_ptr<imstk::SurfaceMesh> ULevelSetModel::GetSurfaceMeshFromStatic()
{
	std::shared_ptr<imstk::SurfaceMesh> MeshGeom = std::make_shared<imstk::SurfaceMesh>();
	UStaticMeshComponent* StaticMeshComp = (UStaticMeshComponent*)GetOwner()->GetComponentByClass(UStaticMeshComponent::StaticClass());
	if (!StaticMeshComp || !StaticMeshComp->GetStaticMesh())
		return nullptr;

	// Get vertices and indices from static mesh and create imstk geometry
	FPositionVertexBuffer* PositionVertexBuffer = &StaticMeshComp->GetStaticMesh()->GetRenderData()->LODResources[0].VertexBuffers.PositionVertexBuffer;
	FRawStaticIndexBuffer* IndexBuffer = &StaticMeshComp->GetStaticMesh()->GetRenderData()->LODResources[0].IndexBuffer;

	// Get vertices and indices in the mesh and set those values in the imstk mesh
	TArray<FVector> Vertices;
	for (uint32 i = 0; i < PositionVertexBuffer->GetNumVertices(); i++) {
		Vertices.Add(FVector(PositionVertexBuffer->VertexPosition(i)));
	}

	// TODO: Could change this to array view?
	TArray<int> Indices;
	for (int32 i = 0; i < IndexBuffer->GetNumIndices(); i++) {
		Indices.Add(IndexBuffer->GetIndex(i));
	}
	MeshGeom->initialize(UMathUtil::ToImstkVecDataArray3d(Vertices, true), UMathUtil::ToImstkVecDataArray3i(Indices));
	MeshGeom->computeVertexNormals();
	MeshGeom->rotate(UMathUtil::ToImstkQuat(StaticMeshComp->GetComponentRotation().Quaternion()), imstk::Geometry::TransformType::ApplyToData);
	MeshGeom->scale(UMathUtil::ToImstkVec3d(StaticMeshComp->GetComponentScale(), false), imstk::Geometry::TransformType::ApplyToData);
	MeshGeom->updatePostTransformData();
	MeshGeom->translate(UMathUtil::ToImstkVec3d(StaticMeshComp->GetComponentLocation(), true), imstk::Geometry::TransformType::ApplyToData);
	StaticMeshComp->DestroyComponent();
	return MeshGeom;
}

FMeshDataStruct ULevelSetModel::GenerateSurfaceMeshData(bool FlipNormals)
{
	FMeshDataStruct MeshData = FMeshDataStruct();
	if (!ImageData)
		return MeshData;

	MeshComp = (UProceduralMeshComponent*)GetOwner()->GetComponentByClass(UProceduralMeshComponent::StaticClass());

	std::shared_ptr<imstk::SurfaceMeshFlyingEdges> SMFE = std::make_shared<imstk::SurfaceMeshFlyingEdges>();
	std::shared_ptr<imstk::ImageData> LvlSetImage = ImageData->GetImageData();

	// Scale the iMSTK level set Model appropriately
	const imstk::Vec3d& currSpacing = LvlSetImage->getSpacing();
	const FVector UnrealScale = MeshComp->GetComponentScale(); // TODO: This is annoying since its an actor component and not a scene component so you can't scale the actual Model. Maybe change this into a scene component
	imstk::Vec3d scaledSpacing = imstk::Vec3d(currSpacing.x() * UnrealScale.X, currSpacing.y() * UnrealScale.Z, currSpacing.z() * UnrealScale.Y);
	LvlSetImage->setSpacing(scaledSpacing);

	// Extract the surface mesh of the Model
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

LevelSetObject::LevelSetObject(UProceduralMeshComponent* ProcMeshComp, UImageDataAsset* ImageData, ULevelSetModel* LevelSetModel, UMaterial* Material) : LevelSetDeformableObject("LevelSetObject"),
m_isoExtract(std::make_shared<imstk::LocalMarchingCubes>())
{
	MeshComp = ProcMeshComp;
	this->Material = Material;
	InitLvlSetImage = ImageData->GetImageData();

	const imstk::Vec3d& CurrSpacing = InitLvlSetImage->getSpacing();
	const FVector UnrealScale = MeshComp->GetComponentScale(); // TODO: This is annoying since its an actor component and not a scene component so you can't scale the actual Model. maybe transform this into a scene component

	imstk::Vec3d ScaledSpacing = imstk::Vec3d(CurrSpacing.x() * UnrealScale.X, CurrSpacing.y() * UnrealScale.Z, CurrSpacing.z() * UnrealScale.Y);
	InitLvlSetImage->setSpacing(ScaledSpacing);

	MeshComp->SetWorldScale3D(FVector(1, 1, 1));

	// Note: Anistropic scaling would invalidate the SDF
	InitLvlSetImage->setOrigin(UMathUtil::ToImstkVec3d(MeshComp->GetComponentLocation(), true));

	// Setup the Parameters
	std::shared_ptr<imstk::LevelSetModelConfig> LvlSetConfig = std::make_shared<imstk::LevelSetModelConfig>();
	LvlSetConfig->m_sparseUpdate = true;
	LvlSetConfig->m_substeps = 15;
	LvlSetConfig->m_dt = 0.001;

	m_isoExtract->setInputImage(InitLvlSetImage);

	m_isoExtract->setNumberOfChunks(UMathUtil::ToImstkVec3i(LevelSetModel->NumChunks, false));
	m_isoExtract->update();

	if (m_useRandomChunkColors)
	{
		srand(static_cast<unsigned int>(time(NULL)));
	}

	createVisualModels();

	// Setup the Object
	std::shared_ptr<imstk::SignedDistanceField> SDF = std::make_shared<imstk::SignedDistanceField>(InitLvlSetImage);

	// Setup the Model
	std::shared_ptr<imstk::LevelSetModel> Model = std::make_shared<imstk::LevelSetModel>();
	Model->setModelGeometry(SDF);
	Model->configure(LvlSetConfig);

	setPhysicsGeometry(SDF);
	setCollidingGeometry(SDF);
	setDynamicalModel(Model);

	// Setup a custom task to forward the modified voxels of the level set Model
	// to the marching cubes before they're cleared
	m_forwardModifiedVoxels = std::make_shared<imstk::TaskNode>(
		std::bind(&LevelSetObject::updateModifiedVoxels, this), "Isosurface: SetModifiedVoxels");
	m_taskGraph->addNode(m_forwardModifiedVoxels);
}

LevelSetObject::LevelSetObject(UProceduralMeshComponent* ProcMeshComp, std::shared_ptr<imstk::SurfaceMesh> SurfMesh, ULevelSetModel* LevelSetModel, UMaterial* Material) : LevelSetDeformableObject("LevelSetObject"),
m_isoExtract(std::make_shared<imstk::LocalMarchingCubes>())
{
	MeshComp = ProcMeshComp;
	this->Material = Material;

	//TODO: this is a hacky work around for an issue with rotation. Not sure why this works and it doesnt work normally. 
	imstk::MeshIO::write(SurfMesh, std::string(TCHAR_TO_UTF8(*FPaths::ProjectLogDir())) + "outputMesh.stl");
	SurfMesh = imstk::MeshIO::read<imstk::SurfaceMesh>(std::string(TCHAR_TO_UTF8(*FPaths::ProjectLogDir())) + "outputMesh.stl");


	imstk::SurfaceMeshDistanceTransform ComputeSdf;
	ComputeSdf.setInputMesh(SurfMesh);
	ComputeSdf.setDimensions(UMathUtil::ToImstkVec3i(LevelSetModel->Dimensions, false));
	ComputeSdf.setBounds(UMathUtil::ToImstkVec3d(LevelSetModel->MinBounds, true), UMathUtil::ToImstkVec3d(LevelSetModel->MaxBounds, true));
	ComputeSdf.update();

	InitLvlSetImage = ComputeSdf.getOutputImage();

	MeshComp->SetWorldScale3D(FVector(1, 1, 1));

	// Setup the Parameters
	std::shared_ptr<imstk::LevelSetModelConfig> lvlSetConfig = std::make_shared<imstk::LevelSetModelConfig>();
	lvlSetConfig->m_sparseUpdate = true;
	lvlSetConfig->m_substeps = 15;
	lvlSetConfig->m_dt = 0.001;

	// Too many chunks and you'll hit memory constraints quickly
	// Too little chunks and the updates for a chunk will take too long
	// The chunks must divide the image dimensions-1 (image dim-1 must be divisible by # chunks)
	m_isoExtract->setInputImage(InitLvlSetImage);
	//m_isoExtract->setIsoValue(0.0);
	m_isoExtract->setNumberOfChunks(UMathUtil::ToImstkVec3i(LevelSetModel->NumChunks, false));
	m_isoExtract->update();

	if (m_useRandomChunkColors)
	{
		srand(static_cast<unsigned int>(time(NULL)));
	}

	createVisualModels();

	// Setup the Object
	std::shared_ptr<imstk::SignedDistanceField> sdf = std::make_shared<imstk::SignedDistanceField>(InitLvlSetImage);

	// Setup the Model
	std::shared_ptr<imstk::LevelSetModel> model = std::make_shared<imstk::LevelSetModel>();
	model->setModelGeometry(sdf);
	model->configure(lvlSetConfig);

	setPhysicsGeometry(sdf);
	setCollidingGeometry(sdf);
	setDynamicalModel(model);

	// Setup a custom task to forward the modified voxels of the level set Model
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
			TArray<FVector2D> UV0;

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
	// Copy, sum, and connect the Model graph to nest within this graph
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

			TArray<FLinearColor> VertColors;
			TArray<FProcMeshTangent> Tangents;
			imstk::VecDataArray<double, 3>& ImstkNorms = *surfMesh->getVertexNormals();
			TArray<FVector> Normals;
			for (int j = 0; j < ImstkNorms.size(); j++) {
				Normals.Add(UMathUtil::ToUnrealFVec(ImstkNorms[j], false));
			}

			TArray<FVector> Verts;
			Verts = UMathUtil::ToUnrealFVecArray(surfMesh->getVertexPositions(), true);

			TArray<int32> Indices = UMathUtil::ToUnrealIntArray(surfMesh->getTriangleIndices());

			MeshComp->ClearMeshSection(i.first);
			MeshComp->CreateMeshSection_LinearColor(i.first, Verts, Indices, Normals, UV0, VertColors, Tangents, false);
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