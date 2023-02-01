// Fill out your copyright notice in the Description page of Project Settings.


#include "PBDModel.h"
#include "ImstkSettings.h"
#include "imstkPbdModel.h"
#include "imstkSelectEnclosedPoints.h"
#include "imstkPointwiseMap.h"
#include "imstkPointToTetMap.h"
#include "imstkTetrahedralMesh.h"
#include "KismetProceduralMeshLibrary.h"
#include "imstkPbdConstraintContainer.h"
#include "imstkPbdFemTetConstraint.h"
#include "imstkPbdModelConfig.h"
#include "imstkPbdObjectCollision.h"

#include "imstkCleanMesh.h"
#include "imstkMeshIO.h"
#include "imstkVisualModel.h"
#include "CollisionInteraction.h"
#include "Engine/GameEngine.h"


#include "imstkGeometryUtilities.h"

UPBDModel::UPBDModel() : UDeformableModel()
{
	GeomFilter.GeomType = EGeometryType::SurfaceMesh;

	// Default constraint values for cloth
	bUseDistanceConstraint = true;
	DistanceConstraint = 100;
	bUseConstantDensityConstraint = false;
	bUseAreaConstraint = false;

	bUseDihedralConstraint = true;
	DihedralConstraint = 100;
	bUseVolumeConstraint = false;

	bUseFEMConstraint = false;
}

void UPBDModel::PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent)
{
	//GeomFilter.GeomType = EGeometryType::SurfaceMesh;

	FName PropertyName = (PropertyChangedEvent.Property != NULL) ? PropertyChangedEvent.Property->GetFName() : NAME_None;

	if (PropertyName == GET_MEMBER_NAME_CHECKED(UPBDModel, Preset)) {
		switch (Preset)
		{
		case 0:
			bUseDistanceConstraint = false;
			bUseConstantDensityConstraint = false;
			bUseAreaConstraint = false;

			bUseDihedralConstraint = false;
			bUseVolumeConstraint = false;

			bUseFEMConstraint = true;
			MaterialType = FemConstraintMaterial::StVK;
			YoungsModulus = 50;
			PossionsRatio = 0.4;
			break;
		case 1:
			bUseDistanceConstraint = true;
			DistanceConstraint = 100;
			bUseConstantDensityConstraint = false;
			bUseAreaConstraint = false;

			bUseDihedralConstraint = true;
			DihedralConstraint = 100;
			bUseVolumeConstraint = false;

			bUseFEMConstraint = false;
			break;
		default:
			return;
		}
	}
}

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

		if (bRigidBody)
			return;

		if (UProceduralMeshComponent* Comp = (UProceduralMeshComponent*)Owner->GetComponentByClass(UProceduralMeshComponent::StaticClass()))
		{
			MeshComp = Comp;
		}
		else if (UStaticMeshComponent* StaticMesh = (UStaticMeshComponent*)Owner->GetComponentByClass(UStaticMeshComponent::StaticClass()))
		{
			// Create procedural mesh, convert static mesh to procedural and then disable static mesh
			MeshComp = NewObject<UProceduralMeshComponent>(this);
			MeshComp->SetWorldScale3D(StaticMesh->GetComponentScale());
			// If including scale, scale gets applied twice
			MeshComp->AttachToComponent(Owner->GetRootComponent(), FAttachmentTransformRules::SnapToTargetNotIncludingScale);
			MeshComp->RegisterComponent();

			ConvertStaticToProceduralMesh(StaticMesh, MeshComp);

			MeshComp->SetVisibility(StaticMesh->GetVisibleFlag());
			StaticMesh->SetVisibility(false);
		}
		else
		{
			SubsystemInstance->LogToUnrealAndImstk("Error Initializing : " + Owner->GetName() + ". No mesh component attached to actor");
			SubsystemInstance->AllBehaviours.Remove(this);
		}
	}

}
void UPBDModel::Init()
{
	if (bDelayInit)
		return;

	Super::Init();

	if (GeomFilter.GeomType != EGeometryType::PointSet && GeomFilter.GeomType != EGeometryType::SurfaceMesh && !bRigidBody) {
		SubsystemInstance->LogToUnrealAndImstk("Non Rigid PBDModels can only be PointSets or SurfaceMeshes");
		return;
	}

	PbdObject = std::make_shared<imstk::PbdObject>(TCHAR_TO_UTF8(*(Owner->GetName())));

	std::shared_ptr<imstk::PbdModel> PbdModel;

	if (bSharedModel)
		PbdModel = SubsystemInstance->PbdModel;
	else
		PbdModel = std::make_shared<imstk::PbdModel>();

	if (bRigidBody) {
		std::shared_ptr<imstk::Geometry> Geom = GetImstkGeometry();
		/*if (!bVisualGeometryFromFile)
			PbdObject->setVisualGeometry(Geom);
		else
			PbdObject->setVisualGeometry(imstk::MeshIO::read(std::string(TCHAR_TO_UTF8(*(ContentDir + VisualGeometryFilePath)))));

		if (!bCollidingGeometryFromFile)
			PbdObject->setCollidingGeometry(Geom);
		else
			PbdObject->setCollidingGeometry(imstk::MeshIO::read(std::string(TCHAR_TO_UTF8(*(ContentDir + CollidingGeometryFilePath)))));

		if (!bVisualGeometryFromFile)
			PbdObject->setPhysicsGeometry(Geom);
		else
			PbdObject->setPhysicsGeometry(imstk::MeshIO::read(std::string(TCHAR_TO_UTF8(*(ContentDir + PhysicsGeometryFilePath)))));*/

		if (MeshComp)
			Geom->scale(UMathUtil::ToImstkVec3d(MeshComp->GetComponentScale(), false), imstk::Geometry::TransformType::ApplyToData);
		else
			Geom->scale(UMathUtil::ToImstkVec3d(Owner->GetActorScale(), false), imstk::Geometry::TransformType::ApplyToData);

		Geom->updatePostTransformData();
		PbdObject->setDynamicalModel(PbdModel);

		if (MeshComp)
			PbdObject->getPbdBody()->setRigid(UMathUtil::ToImstkVec3d(Owner->GetActorLocation(), true), Mass, UMathUtil::ToImstkQuat(MeshComp->GetComponentRotation().Quaternion()), imstk::Mat3d::Identity() * RBInertiaMultiplier);
		else
			PbdObject->getPbdBody()->setRigid(UMathUtil::ToImstkVec3d(Owner->GetActorLocation(), true), Mass, UMathUtil::ToImstkQuat(Owner->GetActorQuat()), imstk::Mat3d::Identity() * RBInertiaMultiplier);

		PbdObject->setVisualGeometry(Geom);
		PbdObject->setCollidingGeometry(Geom);
		PbdObject->setPhysicsGeometry(Geom);

		ImstkCollidingObject = PbdObject;

		SubsystemInstance->ActiveScene->addSceneObject(PbdObject);

		Super::bIsInitialized = true;
		return;
	}


	// Creates a tetrahedral cube for testing purposes
	if (temp) {
		PbdModel = SubsystemInstance->PbdModel;
		std::shared_ptr<imstk::TetrahedralMesh> prismMesh = imstk::GeometryUtils::toTetGrid(imstk::Vec3d(0, 0, 0), imstk::Vec3d(4.0, 4.0, 4.0), imstk::Vec3i(5, 5, 5));
		std::shared_ptr<imstk::SurfaceMesh>     surfMesh = prismMesh->extractSurfaceMesh();

		/*std::shared_ptr<imstk::PbdModelConfig> pbdParams = PbdModel->getConfig();
		pbdParams->m_gravity = imstk::Vec3d(0.0, 0.0, 0.0);
		pbdParams->m_dt = 0.005;
		pbdParams->m_iterations = 8;
		pbdParams->m_linearDampingCoeff = 0.003;*/

		//PbdObject = std::make_shared<imstk::PbdObject>("test");

		PbdObject->setPhysicsGeometry(surfMesh);
		PbdObject->setCollidingGeometry(surfMesh);
		PbdObject->setVisualGeometry(surfMesh);
		PbdObject->setDynamicalModel(PbdModel);
		PbdObject->getPbdBody()->uniformMassValue = 0.05;
		// Use volume+distance constraints, worse results. More performant (can use larger mesh)
		PbdModel->getConfig()->enableConstraint(imstk::PbdModelConfig::ConstraintGenType::Dihedral, 1000.0,
			PbdObject->getPbdBody()->bodyHandle);
		PbdModel->getConfig()->enableConstraint(imstk::PbdModelConfig::ConstraintGenType::Distance, 500.0,
			PbdObject->getPbdBody()->bodyHandle);
		// Fix the borders
		std::shared_ptr<imstk::VecDataArray<double, 3>> vertices = surfMesh->getVertexPositions();
		for (int i = 0; i < surfMesh->getNumVertices(); i++)
		{
			const imstk::Vec3d& pos = (*vertices)[i];
			if (pos[1] <= -4 * 0.5)
			{
				PbdObject->getPbdBody()->fixedNodeIds.push_back(i);
			}
		}

		ImstkCollidingObject = PbdObject;

		SubsystemInstance->ActiveScene->addSceneObject(PbdObject);

		TArray<FVector2D> UV0;
		TArray<FColor> VertColors;
		TArray<FProcMeshTangent> Tangents;

		TArray<FVector> Verts;
		TArray<FVector> Normals;
		TArray<int32> Triangles = UMathUtil::ToUnrealIntArray(surfMesh->getTriangleIndices());

		Verts = UMathUtil::ToUnrealFVecArray(surfMesh->getVertexPositions(), true);
		MeshComp->CreateMeshSection(0, Verts, Triangles, Normals, UV0, VertColors, Tangents, false);


		Super::bIsInitialized = true;
		return;
	}


	// Create and set imstk geometry to unreal values
	if (!TetrahedralMesh) {
		// Create the PbdObject using the geometry of the static mesh
		std::shared_ptr<imstk::Geometry> Geom = GetImstkGeometry();
		if (!Geom) {
			SubsystemInstance->LogToUnrealAndImstk("Error getting colliding geometry for " + Owner->GetName());
			return;
		}

		std::shared_ptr<imstk::SurfaceMesh> CleanedMesh;
		if (bCleanMesh) {
			std::shared_ptr<imstk::SurfaceMesh> SurfMesh = std::dynamic_pointer_cast<imstk::SurfaceMesh>(Geom);

			imstk::CleanMesh Clean;
			Clean.setInputMesh(SurfMesh);
			Clean.update();
			CleanedMesh = Clean.getOutputMesh();

			CleanedMesh->scale(UMathUtil::ToImstkVec3d(MeshComp->GetComponentScale(), false), imstk::Geometry::TransformType::ApplyToData);
			CleanedMesh->rotate(UMathUtil::ToImstkQuat(MeshComp->GetComponentRotation().Quaternion()), imstk::Geometry::TransformType::ApplyToData);
			CleanedMesh->translate(UMathUtil::ToImstkVec3d(MeshComp->GetComponentLocation(), true), imstk::Geometry::TransformType::ApplyToData);

			Geom->scale(UMathUtil::ToImstkVec3d(MeshComp->GetComponentScale(), false), imstk::Geometry::TransformType::ApplyToData);
			Geom->rotate(UMathUtil::ToImstkQuat(MeshComp->GetComponentRotation().Quaternion()), imstk::Geometry::TransformType::ApplyToData);
			Geom->translate(UMathUtil::ToImstkVec3d(MeshComp->GetComponentLocation(), true), imstk::Geometry::TransformType::ApplyToData);
			//std::dynamic_pointer_cast<imstk::SurfaceMesh>(Geom)->computeUVSeamVertexGroups();
			//Geom->updatePostTransformData();
			std::shared_ptr<imstk::PointwiseMap> Map = std::make_shared<imstk::PointwiseMap>(CleanedMesh, SurfMesh);

			// Default value in iMSTK scaled with unreal
			Map->setTolerance(0.00000001 * UMathUtil::GetScale());

			PbdObject->setPhysicsToVisualMap(Map);
			PbdObject->setCollidingToVisualMap(Map);

			PbdObject->setCollidingGeometry(CleanedMesh);
			PbdObject->setPhysicsGeometry(CleanedMesh);
			//PbdModel->setModelGeometry(CleanedMesh);


		}
		else {
			Geom->scale(UMathUtil::ToImstkVec3d(MeshComp->GetComponentScale(), false), imstk::Geometry::TransformType::ApplyToData);
			Geom->rotate(UMathUtil::ToImstkQuat(MeshComp->GetComponentRotation().Quaternion()), imstk::Geometry::TransformType::ApplyToData);
			Geom->translate(UMathUtil::ToImstkVec3d(MeshComp->GetComponentLocation(), true), imstk::Geometry::TransformType::ApplyToData);
			std::dynamic_pointer_cast<imstk::SurfaceMesh>(Geom)->computeUVSeamVertexGroups();
			Geom->updatePostTransformData();

			PbdObject->setCollidingGeometry(Geom);
			PbdObject->setPhysicsGeometry(Geom);
			//PbdModel->setModelGeometry(Geom);
		}

		PbdObject->setVisualGeometry(Geom);
	}
	else
	{
		// Use the assigned tetrahedral mesh and extract its surface mesh
		std::shared_ptr<imstk::TetrahedralMesh> TetMesh = TetrahedralMesh->GetTetrahedralMesh();

		TetMesh->scale(UMathUtil::ToImstkVec3d(MeshComp->GetComponentScale(), false), imstk::Geometry::TransformType::ApplyToData);
		TetMesh->rotate(UMathUtil::ToImstkQuat(MeshComp->GetComponentRotation().Quaternion()), imstk::Geometry::TransformType::ApplyToData);
		TetMesh->translate(UMathUtil::ToImstkVec3d(MeshComp->GetComponentLocation(), true), imstk::Geometry::TransformType::ApplyToData);
		TetMesh->updatePostTransformData();

		std::shared_ptr<imstk::SurfaceMesh> ExtractedSurfMesh = TetMesh->extractSurfaceMesh();;
		std::shared_ptr<imstk::SurfaceMesh> VisualSurfMesh;
		if (bGenerateSurfaceFromTetrahedral) {
			VisualSurfMesh = ExtractedSurfMesh;
			// Create a procedural mesh section and override the existing one using the values from the extracted surface mesh
			TArray<FVector2D> UV0;
			TArray<FColor> VertColors;
			TArray<FProcMeshTangent> Tangents;

			TArray<FVector> Verts;
			TArray<FVector> Normals;
			TArray<int32> Triangles = UMathUtil::ToUnrealIntArray(ExtractedSurfMesh->getTriangleIndices());

			Verts = UMathUtil::ToUnrealFVecArray(ExtractedSurfMesh->getVertexPositions(), true);
			MeshComp->CreateMeshSection(0, Verts, Triangles, Normals, UV0, VertColors, Tangents, false);
		}
		else {
			VisualSurfMesh = std::dynamic_pointer_cast<imstk::SurfaceMesh>(GetImstkGeometry());
			VisualSurfMesh->scale(UMathUtil::ToImstkVec3d(MeshComp->GetComponentScale(), false), imstk::Geometry::TransformType::ApplyToData);
			VisualSurfMesh->rotate(UMathUtil::ToImstkQuat(MeshComp->GetComponentRotation().Quaternion()), imstk::Geometry::TransformType::ApplyToData);
			VisualSurfMesh->translate(UMathUtil::ToImstkVec3d(MeshComp->GetComponentLocation(), true), imstk::Geometry::TransformType::ApplyToData);
			VisualSurfMesh->updatePostTransformData();
		}

		PbdObject->setCollidingGeometry(ExtractedSurfMesh);
		PbdObject->setVisualGeometry(VisualSurfMesh);
		PbdObject->setPhysicsToCollidingMap(std::make_shared<imstk::PointwiseMap>(TetMesh, ExtractedSurfMesh));
		if (bGenerateSurfaceFromTetrahedral)
			PbdObject->setPhysicsToVisualMap(std::make_shared<imstk::PointwiseMap>(TetMesh, VisualSurfMesh));
		else
			PbdObject->setPhysicsToVisualMap(std::make_shared<imstk::PointToTetMap>(TetMesh, VisualSurfMesh));

		PbdObject->setPhysicsGeometry(TetMesh);
		//PbdModel->setModelGeometry(TetMesh);
	}
	PbdObject->setDynamicalModel(PbdModel);
	// Fix vertices of the model with either the set boundaries or with specified vertices
	ProcessBoundaryConditions();

	PbdObject->getPbdBody()->uniformMassValue = Mass;
	PbdModel->getConfig()->setBodyDamping(PbdObject->getPbdBody()->bodyHandle, LinearDampingCoefficient, AngularDampingCoefficient);

	for (const int Num : FixedNodes) {
		PbdObject->getPbdBody()->fixedNodeIds.push_back(Num);
	}

	// Configure model
	if (bUseDistanceConstraint)
		PbdModel->getConfig()->enableConstraint(imstk::PbdModelConfig::ConstraintGenType::Distance, DistanceConstraint, PbdObject->getPbdBody()->bodyHandle);

	if (bUseDihedralConstraint && !TetrahedralMesh && GeomFilter.GeomType != EGeometryType::PointSet)
		PbdModel->getConfig()->enableConstraint(imstk::PbdModelConfig::ConstraintGenType::Dihedral, DihedralConstraint, PbdObject->getPbdBody()->bodyHandle);

	if (bUseVolumeConstraint && TetrahedralMesh)
		PbdModel->getConfig()->enableConstraint(imstk::PbdModelConfig::ConstraintGenType::Volume, VolumeConstraint, PbdObject->getPbdBody()->bodyHandle);

	if (bUseConstantDensityConstraint) // Untested
		PbdModel->getConfig()->enableConstraint(imstk::PbdModelConfig::ConstraintGenType::ConstantDensity, ConstantDensityConstraint, PbdObject->getPbdBody()->bodyHandle);

	if (bUseAreaConstraint && GeomFilter.GeomType != EGeometryType::PointSet) // Untested
		PbdModel->getConfig()->enableConstraint(imstk::PbdModelConfig::ConstraintGenType::Area, AreaConstraint, PbdObject->getPbdBody()->bodyHandle);

	if (bUseFEMConstraint && TetrahedralMesh) {
		PbdModel->getConfig()->m_femParams->m_YoungModulus = YoungsModulus;
		PbdModel->getConfig()->m_femParams->m_PoissonRatio = PossionsRatio;
		PbdModel->getConfig()->enableFemConstraint(static_cast<imstk::PbdFemConstraint::MaterialType>(MaterialType.GetValue()), PbdObject->getPbdBody()->bodyHandle);
		PbdModel->getConfig()->m_doPartitioning = false;
	}

	// If the object should have separate gravity from the rest of the scene
	if (bIndividualGravity && !bSharedModel)
		PbdModel->getConfig()->m_gravity = UMathUtil::ToImstkVec3d(Gravity, true);
	else
		PbdModel->getConfig()->m_gravity = UMathUtil::ToImstkVec3d(SubsystemInstance->Gravity, true);

	if (!bSharedModel) {
		PbdModel->getConfig()->m_iterations = ModelIterations;
		//PbdModel->getConfig()->m_collisionIterations = CollisionIterations;
	}

	// If the object should have separate delta time from the rest of the scene
	if (bIndividualDT && !bSharedModel)
		PbdModel->getConfig()->m_dt = IndividualDT;
	else
		PbdModel->getConfig()->m_dt = SubsystemInstance->TickInterval;

	ImstkCollidingObject = PbdObject;
	// Set the owner to origin of the game since imstk values are world values
	Owner->SetActorLocation(FVector::ZeroVector);
	Owner->SetActorRotation(FQuat::Identity);
	MeshComp->SetWorldScale3D(FVector::OneVector);

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

	SubsystemInstance->LogToUnrealAndImstk("Initialized: " + Owner->GetFName().ToString());

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
	if (bRigidBody) {
		Owner->SetActorLocationAndRotation(UMathUtil::ToUnrealFVec((*PbdObject->getPbdBody()->vertices)[0], true), UMathUtil::ToUnrealFQuat((*PbdObject->getPbdBody()->orientations)[0]));
		return;
	}

	// Cache MeshGeom to avoid dynamic pointer cast every frame
	if (!MeshGeom && !PointSetGeom) {
		if (GeomFilter.GeomType != EGeometryType::PointSet) {
			MeshGeom = std::dynamic_pointer_cast<imstk::SurfaceMesh>(PbdObject->getVisualGeometry());
		}
		else {
			PointSetGeom = std::dynamic_pointer_cast<imstk::PointSet>(PbdObject->getVisualGeometry());
		}
	}
	if (bCleanMesh && !CleanMeshGeom) {
		CleanMeshGeom = std::dynamic_pointer_cast<imstk::SurfaceMesh>(PbdObject->getCollidingGeometry());
	}

	/*auto PhysGeom = std::dynamic_pointer_cast<imstk::SurfaceMesh>(PbdObject->getPhysicsGeometry());
	for (auto vert : *PhysGeom->getVertexPositions()) {
		LOG(WARNING) << "x: " <<vert.x() << " y: " << vert.y() << " z: " << vert.z();
	}*/


	// Update the procedural mesh to positions from imstk
	// Currently only supports vertex positions and normals
	if (MeshComp) {
		TArray<FVector2D> UV0;

		TArray<FLinearColor> VertColors;
		TArray<FProcMeshTangent> Tangents;

		TArray<FVector> Verts;
		TArray<int32> Indices;

		TArray<FVector> Normals;
		if (GeomFilter.GeomType != EGeometryType::PointSet) {
			MeshGeom->computeVertexNormals();
			imstk::VecDataArray<double, 3>& ImstkNorms = *MeshGeom->getVertexNormals();
			// Use normals from imstk
			Normals.Empty();
			for (int i = 0; i < ImstkNorms.size(); i++) {
				Normals.Add(UMathUtil::ToUnrealFVec(ImstkNorms[i], false));
			}

			// Get vertex data from imstk
			Verts = UMathUtil::ToUnrealFVecArray(MeshGeom->getVertexPositions(), true);
		}
		else {
			Verts = UMathUtil::ToUnrealFVecArray(PointSetGeom->getVertexPositions(), true);
		}

		//LOG(WARNING) << MeshGeom->getVertexPosition(100);
		// If the number of verts and triangles is the same then just update the positions, otherwise clear the old mesh section and create a new one
		if (Verts.Num() == MeshComp->GetProcMeshSection(0)->ProcVertexBuffer.Num() && (GeomFilter.GeomType == EGeometryType::PointSet || MeshGeom->getNumTriangles() * 3 == MeshComp->GetProcMeshSection(0)->ProcIndexBuffer.Num())) {
			MeshComp->UpdateMeshSection_LinearColor(0, Verts, Normals, UV0, VertColors, Tangents);
		}
		else {
			if (bCleanMesh) {
				//// Remap the new geometry
				//std::shared_ptr<imstk::PointwiseMap> Map = std::make_shared<imstk::PointwiseMap>(CleanMeshGeom, MeshGeom);
				//Map->setTolerance(0.00000001 * UMathUtil::GetScale());
				//Map->update();
				////std::shared_ptr<imstk::GeometryMap> Map = PbdObject->getPhysicsToVisualMap();
				////Map->update();

				//PbdObject->setPhysicsToVisualMap(Map);
				//PbdObject->setCollidingToVisualMap(Map);
			}



			UMaterialInterface* Mat = MeshComp->GetMaterial(0);

			// Get the T coords (doesnt need to be from the meshgeom, but still have to iterate for Unreal)
			TArray<FProcMeshVertex> Vertices = MeshComp->GetProcMeshSection(0)->ProcVertexBuffer;

			for (FProcMeshVertex Vert : Vertices) {
				UV0.Add(Vert.UV0);
			}

			MeshComp->ClearMeshSection(0);
			Indices = UMathUtil::ToUnrealIntArray(MeshGeom->getTriangleIndices());

			for (int i = Vertices.Num(); i < Verts.Num(); i++) {
				for (int j = 0; j < 3; j++) {
					int CurVert = Indices[(i * 3) + j];
					if (UV0.Num() > CurVert) {
						UV0.Add(FVector2D(UV0[CurVert]));
						break;
					}
				}
				//UV0.Add(FVector2D(0.5,0.5));
			}

			MeshComp->CreateMeshSection_LinearColor(0, Verts, Indices, Normals, UV0, VertColors, Tangents, false);
			MeshComp->SetMaterial(0, Mat);
		}
	}

	if (UImstkSettings::IsDebugging()) {
		if (GEngine) {
			if (bPrintPositionInformation)
				GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, Owner->GetName() + ": " + UMathUtil::ToUnrealFVec(PbdObject->getCollidingGeometry()->getCenter(), true).ToString());
		}
	}
}

void UPBDModel::UpdateVisualFromTet()
{
	std::shared_ptr<imstk::TetrahedralMesh> TetMesh = std::dynamic_pointer_cast<imstk::TetrahedralMesh>(PbdObject->getPhysicsGeometry());
	std::shared_ptr<imstk::SurfaceMesh> ExtractedSurfMesh = TetMesh->extractSurfaceMesh();
	if (PbdObject->getVisualModel(0))
		PbdObject->removeVisualModel(PbdObject->getVisualModel(0));

	PbdObject->setCollidingGeometry(ExtractedSurfMesh);

	auto VisModel = std::make_shared<imstk::VisualModel>();
	VisModel->setGeometry(ExtractedSurfMesh);

	MeshGeom = ExtractedSurfMesh;
	PbdObject->addVisualModel(VisModel);
	//PbdObject->setVisualGeometry(ExtractedSurfMesh);

	//PbdObject->getPhysicsToCollidingMap()->compute();
	//PbdObject->getPhysicsToVisualMap()->compute();

	TArray<FVector2D> UV0;
	TArray<FColor> VertColors;
	TArray<FProcMeshTangent> Tangents;

	TArray<FVector> Verts;
	TArray<FVector> Normals;
	//ExtractedSurfMesh->computeVertexNormals();
	//imstk::VecDataArray<double, 3>& ImstkNorms = *ExtractedSurfMesh->getVertexNormals();
	//// Use normals from imstk
	//Normals.Empty();
	//for (int i = 0; i < ImstkNorms.size(); i++) {
	//	Normals.Add(UMathUtil::ToUnrealFVec(ImstkNorms[i], false));
	//}
	TArray<int32> Triangles = UMathUtil::ToUnrealIntArray(ExtractedSurfMesh->getTriangleIndices());

	Verts = UMathUtil::ToUnrealFVecArray(ExtractedSurfMesh->getVertexPositions(), true);
	MeshComp->ClearMeshSection(0);
	MeshComp->CreateMeshSection(0, Verts, Triangles, Normals, UV0, VertColors, Tangents, false);

	// Re-create new map with newly extracted surface mesh
	auto Map = std::make_shared<imstk::PointwiseMap>(TetMesh, ExtractedSurfMesh);
	PbdObject->setPhysicsToCollidingMap(Map);
	PbdObject->setPhysicsToVisualMap(Map);
	Map->compute();

	// TODO: fix naming here

	TArray<UCollisionInteraction*> ToReInit;
	for (int i = 0; i < Interactions.Num(); i++) {
		for (auto ImstkInteraction : Interactions[i]->Interactions)
			if (std::dynamic_pointer_cast<imstk::PbdObjectCollision>(ImstkInteraction)) {
				SubsystemInstance->ActiveScene->removeSceneObject(ImstkInteraction);
				ToReInit.Add(Interactions[i]);

				ImstkInteraction.reset();
				Interactions[i] = nullptr;
			}
	}
	Interactions.RemoveAll([](const UCollisionInteraction* Ptr) {
		return Ptr == nullptr;
		});

	for (auto InitInteraction : ToReInit) {
		InitInteraction->Init();
	}
	SubsystemInstance->ActiveScene->initialize();
}

void UPBDModel::UnInit()
{
	Super::UnInit();
	MeshGeom.reset();
	CleanMeshGeom.reset();
	PointSetGeom.reset();
}