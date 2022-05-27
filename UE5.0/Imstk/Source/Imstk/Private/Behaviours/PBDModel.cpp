// Fill out your copyright notice in the Description page of Project Settings.


#include "PBDModel.h"
#include "ImstkSettings.h"
#include "iMSTK-5.0/imstkPbdModel.h"
#include "iMSTK-5.0/imstkSelectEnclosedPoints.h"
#include "iMSTK-5.0/imstkPointwiseMap.h"
#include "iMSTK-5.0/imstkTetrahedralMesh.h"
#include "Engine/GameEngine.h"
//#include "iMSTK-5.0/imstkPbdFemConstraint.h"

// Called when the game starts or when spawned
void UPBDModel::BeginPlay()
{
	Super::BeginPlay();


}

void UPBDModel::InitializeComponent()
{
	Super::InitializeComponent();

	// Check if game is in play mode (required because InitializeComponent() is run when creating a blueprint of the object)
	if (GetWorld() && GetWorld()->GetGameInstance()) {
		// Make the subsystem tick first to update the imstk scene before updating the model in unreal
		AddTickPrerequisiteActor((AActor*)SubsystemInstance);

		if (UProceduralMeshComponent* Comp = (UProceduralMeshComponent*)Owner->GetComponentByClass(UProceduralMeshComponent::StaticClass()))
		{
			MeshComp = Comp;
		}
		else if (UStaticMeshComponent* StaticMesh = (UStaticMeshComponent*)Owner->GetComponentByClass(UStaticMeshComponent::StaticClass()))
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
			// TODO: Dont think removing works here since this occurs before the behaviours are set
			SubsystemInstance->AllBehaviours.Remove(this);
		}
	}

}
void UPBDModel::Init()
{
	Super::Init();
	if (GeomFilter.GeomType != EGeometryType::PointSet && GeomFilter.GeomType != EGeometryType::SurfaceMesh) {
		UE_LOG(LogTemp, Error, TEXT("PBDModels can only be PointSets or SurfaceMeshes"));
		return;
	}

	PbdObject = std::make_shared<imstk::PbdObject>(TCHAR_TO_UTF8(*(Owner->GetName())));

	// Configure model
	std::shared_ptr<imstk::PbdModelConfig> PbdConfig = std::make_shared<imstk::PbdModelConfig>();

	if (bUseDistanceConstraint)
		PbdConfig->enableConstraint(imstk::PbdModelConfig::ConstraintGenType::Distance, DistanceConstraint);

	if (bUseDihedralConstraint && !TetrahedralMesh)
		PbdConfig->enableConstraint(imstk::PbdModelConfig::ConstraintGenType::Dihedral, DihedralConstraint);

	if (bUseVolumeConstraint && TetrahedralMesh)
		PbdConfig->enableConstraint(imstk::PbdModelConfig::ConstraintGenType::Volume, VolumeConstraint);

	if (bUseConstantDensityConstraint) // Untested
		PbdConfig->enableConstraint(imstk::PbdModelConfig::ConstraintGenType::ConstantDensity, ConstantDensityConstraint);

	if (bUseAreaConstraint) // Untested
		PbdConfig->enableConstraint(imstk::PbdModelConfig::ConstraintGenType::Area, AreaConstraint);

	if (bUseFEMConstraint && TetrahedralMesh) {
		PbdConfig->m_femParams->m_YoungModulus = YoungsModulus;
		PbdConfig->m_femParams->m_PoissonRatio = PossionsRatio;
		PbdConfig->enableFemConstraint(static_cast<imstk::PbdFemConstraint::MaterialType>(MaterialType.GetValue()));
		PbdConfig->m_doPartitioning = false;
	}

	PbdConfig->m_uniformMassValue = Mass;
	PbdConfig->m_gravity = UMathUtil::ToImstkVec3(SubsystemInstance->Gravity);
	PbdConfig->m_iterations = 5;
	PbdConfig->m_viscousDampingCoeff = ViscousDampingCoeff;
	PbdConfig->m_contactStiffness = ContactStiffness;
	PbdConfig->m_dt = 0.01;

	std::shared_ptr<imstk::PbdModel> PbdModel = std::make_shared<imstk::PbdModel>();

	//PbdObject->setCollidingGeometry(Geom);
	//PbdObject->setVisualGeometry(Geom);

	// Create and set imstk geometry to unreal values
	if (!TetrahedralMesh) {
		// Create the PbdObject using the colliding geometry of the static mesh
		std::shared_ptr<imstk::Geometry> Geom = GetImstkGeometry();
		if (!Geom) {
			UE_LOG(LogTemp, Error, TEXT("Error getting colliding geometry for %s"), *Owner->GetName());
			return;
		}

		Geom->scale(UMathUtil::ToImstkVec3(Owner->GetActorScale()), imstk::Geometry::TransformType::ApplyToData);
		Geom->rotate(UMathUtil::ToImstkQuat(Owner->GetActorRotation().Quaternion()), imstk::Geometry::TransformType::ApplyToData);
		Geom->translate(UMathUtil::ToImstkVec3(Owner->GetActorLocation()), imstk::Geometry::TransformType::ApplyToData);
		Geom->updatePostTransformData();
		PbdObject->setCollidingGeometry(Geom);
		PbdObject->setVisualGeometry(Geom);


		PbdObject->setPhysicsGeometry(Geom);
		PbdModel->setModelGeometry(Geom);
	}
	else
	{
		// Use the assigned tetrahedral mesh and extract its surface mesh
		std::shared_ptr<imstk::TetrahedralMesh> TetMesh = TetrahedralMesh->GetTetrahedralMesh();
		//std::shared_ptr<imstk::TetrahedralMesh> TetMesh = imstk::MeshIO::read<imstk::TetrahedralMesh>("D:\\Temp\\heart_volume.vtk");

		TetMesh->scale(UMathUtil::ToImstkVec3(Owner->GetActorScale()), imstk::Geometry::TransformType::ApplyToData);
		TetMesh->rotate(UMathUtil::ToImstkQuat(Owner->GetActorRotation().Quaternion()), imstk::Geometry::TransformType::ApplyToData);
		TetMesh->translate(UMathUtil::ToImstkVec3(Owner->GetActorLocation()), imstk::Geometry::TransformType::ApplyToData);
		TetMesh->updatePostTransformData();

		std::shared_ptr<imstk::SurfaceMesh> SurfMesh = TetMesh->extractSurfaceMesh();

		/************************************************************************************************
		imstk::imstkNew<imstk::SurfaceMesh> clothMesh;

		imstk::imstkNew<imstk::VecDataArray<double, 3>> verticesPtr(16 * 16);
		imstk::VecDataArray<double, 3>& vertices = *verticesPtr.get();
		const double                      dy = 10 / (16 - 1);
		const double                      dx = 10 / (16 - 1);
		for (int i = 0; i < 16; ++i)
		{
			for (int j = 0; j < 16; j++)
			{
				vertices[i * 16 + j] = imstk::Vec3d(dx * static_cast<double>(i), 1.0, dy * static_cast<double>(j));
			}
		}

		// Add connectivity data
		imstk::imstkNew<imstk::VecDataArray<int, 3>> indicesPtr;
		imstk::VecDataArray<int, 3>& indices = *indicesPtr.get();
		for (int i = 0; i < 16 - 1; i++)
		{
			for (int j = 0; j < 16 - 1; j++)
			{
				const int index1 = i * 16 + j;
				const int index2 = index1 + 16;
				const int index3 = index1 + 1;
				const int index4 = index2 + 1;

				// Interleave [/][\]
				if (i % 2 ^ j % 2)
				{
					indices.push_back(imstk::Vec3i(index1, index2, index3));
					indices.push_back(imstk::Vec3i(index4, index3, index2));
				}
				else
				{
					indices.push_back(imstk::Vec3i(index2, index4, index1));
					indices.push_back(imstk::Vec3i(index4, index3, index1));
				}
			}
		}

		imstk::imstkNew<imstk::VecDataArray<float, 2>> uvCoordsPtr(16 * 16);
		imstk::VecDataArray<float, 2>& uvCoords = *uvCoordsPtr.get();
		for (int i = 0; i < 16; ++i)
		{
			for (int j = 0; j < 16; j++)
			{
				uvCoords[i * 16 + j] = imstk::Vec2f(static_cast<float>(i) / 16, static_cast<float>(j) / 16) * 2;
			}
		}

		clothMesh->initialize(verticesPtr, indicesPtr);
		clothMesh->setVertexTCoords("uvs", uvCoordsPtr);
		LOG(WARNING) << clothMesh->getTriangleIndices()->size();
		************************************************************************************************/


		//************************************************************************************************
		//imstkNew<TetrahedralMesh> tissueMesh;

		//imstkNew<VecDataArray<double, 3>> verticesPtr(dim[0] * dim[1] * dim[2]);
		//VecDataArray<double, 3>& vertices = *verticesPtr.get();
		//const Vec3d                       dx = size.cwiseQuotient((dim - Vec3i(1, 1, 1)).cast<double>());
		//for (int z = 0; z < dim[2]; z++)
		//{
		//	for (int y = 0; y < dim[1]; y++)
		//	{
		//		for (int x = 0; x < dim[0]; x++)
		//		{
		//			vertices[x + dim[0] * (y + dim[1] * z)] = Vec3i(x, y, z).cast<double>().cwiseProduct(dx) - size * 0.5 + center;
		//		}
		//	}
		//}

		//// Add connectivity data
		//imstkNew<VecDataArray<int, 4>> indicesPtr;
		//VecDataArray<int, 4>& indices = *indicesPtr.get();
		//for (int z = 0; z < dim[2] - 1; z++)
		//{
		//	for (int y = 0; y < dim[1] - 1; y++)
		//	{
		//		for (int x = 0; x < dim[0] - 1; x++)
		//		{
		//			int cubeIndices[8] =
		//			{
		//				x + dim[0] * (y + dim[1] * z),
		//				(x + 1) + dim[0] * (y + dim[1] * z),
		//				(x + 1) + dim[0] * (y + dim[1] * (z + 1)),
		//				x + dim[0] * (y + dim[1] * (z + 1)),
		//				x + dim[0] * ((y + 1) + dim[1] * z),
		//				(x + 1) + dim[0] * ((y + 1) + dim[1] * z),
		//				(x + 1) + dim[0] * ((y + 1) + dim[1] * (z + 1)),
		//				x + dim[0] * ((y + 1) + dim[1] * (z + 1))
		//			};

		//			// Alternate the pattern so the edges line up on the sides of each voxel
		//			if ((z % 2 ^ x % 2) ^ y % 2)
		//			{
		//				indices.push_back(Vec4i(cubeIndices[0], cubeIndices[7], cubeIndices[5], cubeIndices[4]));
		//				indices.push_back(Vec4i(cubeIndices[3], cubeIndices[7], cubeIndices[2], cubeIndices[0]));
		//				indices.push_back(Vec4i(cubeIndices[2], cubeIndices[7], cubeIndices[5], cubeIndices[0]));
		//				indices.push_back(Vec4i(cubeIndices[1], cubeIndices[2], cubeIndices[0], cubeIndices[5]));
		//				indices.push_back(Vec4i(cubeIndices[2], cubeIndices[6], cubeIndices[7], cubeIndices[5]));
		//			}
		//			else
		//			{
		//				indices.push_back(Vec4i(cubeIndices[3], cubeIndices[7], cubeIndices[6], cubeIndices[4]));
		//				indices.push_back(Vec4i(cubeIndices[1], cubeIndices[3], cubeIndices[6], cubeIndices[4]));
		//				indices.push_back(Vec4i(cubeIndices[3], cubeIndices[6], cubeIndices[2], cubeIndices[1]));
		//				indices.push_back(Vec4i(cubeIndices[1], cubeIndices[6], cubeIndices[5], cubeIndices[4]));
		//				indices.push_back(Vec4i(cubeIndices[0], cubeIndices[3], cubeIndices[1], cubeIndices[4]));
		//			}
		//		}
		//	}
		//}

		//imstkNew<VecDataArray<float, 2>> uvCoordsPtr(dim[0] * dim[1] * dim[2]);
		//VecDataArray<float, 2>& uvCoords = *uvCoordsPtr.get();
		//for (int z = 0; z < dim[2]; z++)
		//{
		//	for (int y = 0; y < dim[1]; y++)
		//	{
		//		for (int x = 0; x < dim[0]; x++)
		//		{
		//			uvCoords[x + dim[0] * (y + dim[1] * z)] = Vec2f(static_cast<float>(x) / dim[0], static_cast<float>(z) / dim[2]) * 3.0;
		//		}
		//	}
		//}

		//// Ensure correct windings
		//for (int i = 0; i < indices.size(); i++)
		//{
		//	if (tetVolume(vertices[indices[i][0]], vertices[indices[i][1]], vertices[indices[i][2]], vertices[indices[i][3]]) < 0.0)
		//	{
		//		std::swap(indices[i][0], indices[i][2]);
		//	}
		//}

		//tissueMesh->initialize(verticesPtr, indicesPtr);
		//tissueMesh->setVertexTCoords("uvs", uvCoordsPtr);
		//************************************************************************************************

		//UE_LOG(LogTemp, Warning, TEXT("TCoords %s"), (SurfMesh->getVertexTCoords() == nullptr) ? TEXT("true") : TEXT("false"));
		//SurfMesh->flipNormals();
		/*
		imstk::VecDataArray<double, 3>& Arr = *SurfMesh->getVertexPositions();
		//LOG(WARNING) << Arr.size();
		std::shared_ptr<imstk::VecDataArray<int, 3>> indicesPtr = SurfMesh->getTriangleIndices();
		imstk::VecDataArray<int, 3>& indices = *indicesPtr;
		indices.size();
		LOG(WARNING) << indices.size();
		*/

		//MeshComp->GetProcMeshSection(0)->Reset();

		// Create a procedural mesh section and override the existing one using the values from the extracted surface mesh
		TArray<FVector2D> UV0;
		TArray<FColor> VertColors;
		TArray<FProcMeshTangent> Tangents;

		TArray<FVector> Verts;
		TArray<FVector> Normals;
		TArray<int32> Triangles;
		/*imstk::VecDataArray<int, 3>& Arr = *SurfMesh->getTriangleIndices().get();
		for (int i = 0; i < Arr.size(); i++) {
			for (int j = 0; j < 3; j++) {
				Triangles.Add(Arr[i][j]);
			}
		}*/

		for (int i = 0; i < SurfMesh->getNumTriangles(); i++) {
			imstk::Vec3i Indices = SurfMesh->getTriangleIndices(i);
			Triangles.Add(Indices.x());
			Triangles.Add(Indices.y());
			Triangles.Add(Indices.z());
		}


		//Normals = UMathUtil::ToUnrealFVecArray(SurfMesh->getVertexNormals());
		Verts = UMathUtil::ToUnrealFVecArray(SurfMesh->getVertexPositions());
		MeshComp->CreateMeshSection(0, Verts, Triangles, Normals, UV0, VertColors, Tangents, false);


		//LOG(WARNING) << SurfMesh->getNumVertices();
		//LOG(WARNING) << SurfMesh->getNumTriangles();

		PbdObject->setCollidingGeometry(SurfMesh);
		PbdObject->setVisualGeometry(SurfMesh);
		PbdObject->setPhysicsToCollidingMap(std::make_shared<imstk::PointwiseMap>(TetMesh, SurfMesh));

		PbdObject->setPhysicsGeometry(TetMesh);
		PbdModel->setModelGeometry(TetMesh);
	}

	// Fix vertices of the model with either the set boundaries or with specified vertices
	ProcessBoundaryConditions();

	for (const int num : FixedNodes) {
		PbdConfig->m_fixedNodeIds.push_back(num);
	}

	PbdModel->configure(PbdConfig);
	PbdObject->setDynamicalModel(PbdModel);

	ImstkCollidingObject = PbdObject;

	SubsystemInstance->ActiveScene->addSceneObject(PbdObject);

	// TODO: Name gets incremented on each run until editor is reset
	//if (GeomFilter.GeomType == GeometryType::SurfaceMesh) {
		//std::shared_ptr<imstk::SurfaceMesh> Mesh = std::dynamic_pointer_cast<imstk::SurfaceMesh>(Geom);
		//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Purple, UMathUtil::ToUnrealFVec(Mesh->getCenter()).ToString());

		//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, FString(Mesh->getName().c_str()));
		//for (int i = 0; i < Mesh->getNumVertices(); i++) {


			//imstk::Vec3d Vert = Mesh->getVertexPosition(i);
			//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, "X: " + FString::SanitizeFloat(Vert.x()) + " Y: " + FString::SanitizeFloat(Vert.y()) + " Z: " + FString::SanitizeFloat(Vert.z()));
		//}
	//}

	// Set the owner to origin of the game since imstk values are world values
	Owner->SetActorLocation(FVector::ZeroVector);
	Owner->SetActorRotation(FQuat::Identity);

	Super::bIsInitialized = true;

}


// Called every frame
void UPBDModel::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (Super::bIsInitialized) {
		UpdateModel();
	}
}


void UPBDModel::UpdateModel()
{
	// Cache MeshGeom to avoid dynamic pointer cast every frame
	if (!MeshGeom) {
		MeshGeom = std::dynamic_pointer_cast<imstk::SurfaceMesh>(PbdObject->getVisualGeometry());
	}

	// Update the procedural mesh to positions from imstk
	// Currently only supports vertex positions and normals
	if (MeshComp) {
		TArray<FVector2D> UV0;
		TArray<FLinearColor> VertColors;
		TArray<FProcMeshTangent> Tangents;
		MeshGeom->computeVertexNormals();
		imstk::VecDataArray<double, 3>& ImstkNorms = *MeshGeom->getVertexNormals();
		TArray<FVector> Verts;
		TArray<FVector> Normals;
		for (int i = 0; i < ImstkNorms.size(); i++) {
			Normals.Add(UMathUtil::ToUnrealFVec(ImstkNorms[i]));
		}


		Verts = UMathUtil::ToUnrealFVecArray(MeshGeom->getVertexPositions());

		// If the number of verts and triangles is the same then just update the positions, otherwise clear the old mesh section and create a new one
		if (Verts.Num() == MeshComp->GetProcMeshSection(0)->ProcVertexBuffer.Num() && MeshGeom->getNumTriangles() * 3 == MeshComp->GetProcMeshSection(0)->ProcIndexBuffer.Num()) {
			MeshComp->UpdateMeshSection_LinearColor(0, Verts, Normals, UV0, VertColors, Tangents);
		}
		else {
			MeshComp->ClearMeshSection(0);

			TArray<int32> Indices;
			for (int i = 0; i < MeshGeom->getNumTriangles(); i++) {
				imstk::Vec3i Triangle = MeshGeom->getTriangleIndices(i);
				Indices.Add(Triangle.x());
				Indices.Add(Triangle.y());
				Indices.Add(Triangle.z());
			}

			MeshComp->CreateMeshSection_LinearColor(0, Verts, Indices, Normals, UV0, VertColors, Tangents, false);
		}

		// Get vert positions from imstk and apply to each section in order
		// imstk object is flattened mesh with vertices in order of sections in unreal
		// Might be needed if there are multiple sections in the mesh
		//int VertNum = 0;
		//for (int MeshSec = 0; MeshSec < MeshComp->GetNumSections(); MeshSec++) {
		//	Verts.Empty();
		//	for (int i = 0; i < MeshComp->GetProcMeshSection(MeshSec)->ProcVertexBuffer.Num(); i++) {
		//		imstk::Vec3d Vert = MeshGeom->getVertexPosition(VertNum + i);
		//		Verts.Add(UMathUtil::ToUnrealFVec(Vert));
		//		//Normals.Add(UMathUtil::ToUnrealFVec(ImstkNorms[i]));
		//	}
		//	VertNum += MeshComp->GetProcMeshSection(MeshSec)->ProcVertexBuffer.Num();
		//	MeshComp->UpdateMeshSection_LinearColor(MeshSec, Verts, Normals, UV0, VertColors, Tangents);
		//}
	}

	if (UImstkSettings::IsDebugging()) {
		if (GEngine) {
			if (bPrintPositionInformation)
				GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, Owner->GetName() + ": " + UMathUtil::ToUnrealFVec(PbdObject->getCollidingGeometry()->getCenter()).ToString());
		}
	}

	//Owner->SetActorRotation(UMathUtil::ToUnrealFQuat(imstk::Quatd(PbdModel->getModelGeometry()->getRotation())));
	//Owner->SetActorLocation(UMathUtil::ToUnrealFVec(PbdModel->getModelGeometry()->getTranslation()));


	// OLD TEST CODE
	/*UStaticMeshComponent* MeshComponent = (UStaticMeshComponent*)Owner->GetComponentByClass(UStaticMeshComponent::StaticClass());;

	const int32 NumVerts = MeshGeom->getNumVertices();
	TResourceArray<FVector4, VERTEXBUFFER_ALIGNMENT> Verts;


	for (int i = 0; i < NumVerts; i++) {
		FVector4 Vert = FVector4(UMathUtil::ToUnrealFVec(MeshGeom->getVertexPosition(i)), 1.0);
		Verts[i] = Vert;
	}
	uint32 Size = Verts.GetResourceDataSize();
	FRHIResourceCreateInfo CreateInfo(&Verts);
	MeshComponent->GetStaticMesh()->GetRenderData()->LODResources[0].VertexBuffers.PositionVertexBuffer.VertexBufferRHI = RHICreateVertexBuffer(Size, BUF_Static, CreateInfo);
	MeshComponent->GetStaticMesh()->GetRenderData()->LODResources[0].VertexBuffers.PositionVertexBuffer.UpdateRHI();*/

	//std::shared_ptr<imstk::PbdModel> PbdModel = PbdObject->getPbdModel();
	//FVector pos = UMathUtil::ToUnrealFVec(PbdModel->getModelGeometry()->getCenter());
	//if (UImstkSettings::IsDebugging()) {
	//	/*if (GEngine) {
	//		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, Owner->GetName() + " " + pos.ToString());
	//	}*/
	//	UE_LOG(LogTemp, Warning, TEXT("%s"), *FString("Frame: "));

	//	
	//	

	//	for (int i = 0; i < MeshGeom->getNumVertices(); i++) {
	//		imstk::Vec3d Vert = MeshGeom->getVertexPosition(i);
	//		//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, "X: " + FString::SanitizeFloat(Vert.x()) + " Y: " + FString::SanitizeFloat(Vert.y()) + " Z: " + FString::SanitizeFloat(Vert.z()));
	//	  UE_LOG(LogTemp, Warning, TEXT("%s"), *("X: " + FString::SanitizeFloat(Vert.x()) + " Y: " + FString::SanitizeFloat(Vert.y()) + " Z: " + FString::SanitizeFloat(Vert.z())));
	//		UE_LOG(LogTemp, Warning, TEXT("%s"), *("X: " + FString::SanitizeFloat(Vert.x()) + " Y: " + FString::SanitizeFloat(Vert.y()) + " Z: " + FString::SanitizeFloat(Vert.z())));
	//	}
	//}
}