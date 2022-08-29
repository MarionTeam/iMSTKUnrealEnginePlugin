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

#include "Engine/GameEngine.h"

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

			ConvertStaticToProceduralMesh(StaticMesh, MeshComp);

			StaticMesh->SetVisibility(false);
		}
		else
		{
			if (GEngine) {
				GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "Error Initializing : " + Owner->GetName() + ".No mesh component attached to actor");
			}
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
		if (GEngine) {
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "PBDModels can only be PointSets or SurfaceMeshes");
		}
		UE_LOG(LogTemp, Error, TEXT("PBDModels can only be PointSets or SurfaceMeshes"));
		return;
	}

	PbdObject = std::make_shared<imstk::PbdObject>(TCHAR_TO_UTF8(*(Owner->GetName())));

	// Configure model
	std::shared_ptr<imstk::PbdModelConfig> PbdConfig = std::make_shared<imstk::PbdModelConfig>();

	if (bUseDistanceConstraint)
		PbdConfig->enableConstraint(imstk::PbdModelConfig::ConstraintGenType::Distance, DistanceConstraint);

	if (bUseDihedralConstraint && !TetrahedralMesh && GeomFilter.GeomType != EGeometryType::PointSet)
		PbdConfig->enableConstraint(imstk::PbdModelConfig::ConstraintGenType::Dihedral, DihedralConstraint);

	if (bUseVolumeConstraint && TetrahedralMesh)
		PbdConfig->enableConstraint(imstk::PbdModelConfig::ConstraintGenType::Volume, VolumeConstraint);

	if (bUseConstantDensityConstraint) // Untested
		PbdConfig->enableConstraint(imstk::PbdModelConfig::ConstraintGenType::ConstantDensity, ConstantDensityConstraint);

	if (bUseAreaConstraint && GeomFilter.GeomType != EGeometryType::PointSet) // Untested
		PbdConfig->enableConstraint(imstk::PbdModelConfig::ConstraintGenType::Area, AreaConstraint);

	if (bUseFEMConstraint && TetrahedralMesh) {
		PbdConfig->m_femParams->m_YoungModulus = YoungsModulus;
		PbdConfig->m_femParams->m_PoissonRatio = PossionsRatio;
		PbdConfig->enableFemConstraint(static_cast<imstk::PbdFemConstraint::MaterialType>(MaterialType.GetValue()));
		PbdConfig->m_doPartitioning = false;
	}

	PbdConfig->m_uniformMassValue = Mass;

	// If the object should have separate gravity from the rest of the scene
	if (bIndividualGravity)
		PbdConfig->m_gravity = UMathUtil::ToImstkVec3d(Gravity, true);
	else
		PbdConfig->m_gravity = UMathUtil::ToImstkVec3d(SubsystemInstance->Gravity, true);

	PbdConfig->m_iterations = 5;
	PbdConfig->m_viscousDampingCoeff = ViscousDampingCoeff;
	PbdConfig->m_contactStiffness = ContactStiffness;

	// If the object should have separate delta time from the rest of the scene
	if (bIndividualDT)
		PbdConfig->m_dt = IndividualDT;
	else
		PbdConfig->m_dt = SubsystemInstance->TickInterval;

	std::shared_ptr<imstk::PbdModel> PbdModel = std::make_shared<imstk::PbdModel>();

	// Create and set imstk geometry to unreal values
	if (!TetrahedralMesh) {
		// Create the PbdObject using the geometry of the static mesh
		std::shared_ptr<imstk::Geometry> Geom = GetImstkGeometry();
		if (!Geom) {
			if (GEngine) {
				GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "Error getting colliding geometry for " + Owner->GetName());
			}
			UE_LOG(LogTemp, Error, TEXT("Error getting colliding geometry for %s"), *Owner->GetName());
			return;
		}

		Geom->scale(UMathUtil::ToImstkVec3d(Owner->GetActorScale(), false), imstk::Geometry::TransformType::ApplyToData);
		Geom->rotate(UMathUtil::ToImstkQuat(Owner->GetActorRotation().Quaternion()), imstk::Geometry::TransformType::ApplyToData);
		Geom->translate(UMathUtil::ToImstkVec3d(Owner->GetActorLocation(), true), imstk::Geometry::TransformType::ApplyToData);
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

		TetMesh->scale(UMathUtil::ToImstkVec3d(Owner->GetActorScale(), false), imstk::Geometry::TransformType::ApplyToData);
		TetMesh->rotate(UMathUtil::ToImstkQuat(Owner->GetActorRotation().Quaternion()), imstk::Geometry::TransformType::ApplyToData);
		TetMesh->translate(UMathUtil::ToImstkVec3d(Owner->GetActorLocation(), true), imstk::Geometry::TransformType::ApplyToData);
		TetMesh->updatePostTransformData();

		std::shared_ptr<imstk::SurfaceMesh> SurfMesh;

		if (bGenerateSurfaceFromTetrahedral) {
			SurfMesh = TetMesh->extractSurfaceMesh();

			// Create a procedural mesh section and override the existing one using the values from the extracted surface mesh
			TArray<FVector2D> UV0;
			TArray<FColor> VertColors;
			TArray<FProcMeshTangent> Tangents;

			TArray<FVector> Verts;
			TArray<FVector> Normals;
			TArray<int32> Triangles = UMathUtil::ToUnrealIntArray(SurfMesh->getTriangleIndices());

			Verts = UMathUtil::ToUnrealFVecArray(SurfMesh->getVertexPositions(), true);
			MeshComp->CreateMeshSection(0, Verts, Triangles, Normals, UV0, VertColors, Tangents, false);
		}
		else {
			SurfMesh = std::dynamic_pointer_cast<imstk::SurfaceMesh>(GetImstkGeometry());
			SurfMesh->scale(UMathUtil::ToImstkVec3d(Owner->GetActorScale(), false), imstk::Geometry::TransformType::ApplyToData);
			SurfMesh->rotate(UMathUtil::ToImstkQuat(Owner->GetActorRotation().Quaternion()), imstk::Geometry::TransformType::ApplyToData);
			SurfMesh->translate(UMathUtil::ToImstkVec3d(Owner->GetActorLocation(), true), imstk::Geometry::TransformType::ApplyToData);
			SurfMesh->updatePostTransformData();
		}

		PbdObject->setCollidingGeometry(SurfMesh);
		PbdObject->setVisualGeometry(SurfMesh);
		if (bGenerateSurfaceFromTetrahedral)
			PbdObject->setPhysicsToCollidingMap(std::make_shared<imstk::PointwiseMap>(TetMesh, SurfMesh));
		else
			PbdObject->setPhysicsToCollidingMap(std::make_shared<imstk::PointToTetMap>(TetMesh, SurfMesh));

		PbdObject->setPhysicsGeometry(TetMesh);
		PbdModel->setModelGeometry(TetMesh);
	}

	// Fix vertices of the model with either the set boundaries or with specified vertices
	ProcessBoundaryConditions();

	for (const int Num : FixedNodes) {
		PbdConfig->m_fixedNodeIds.push_back(Num);
	}

	PbdModel->configure(PbdConfig);

	/*if (bUseFEMConstraint && TetrahedralMesh) {
		std::shared_ptr<imstk::PbdConstraintContainer> Constraints = PbdModel->getConstraints();
		for (auto Constraint : Constraints->getConstraints()) {
			if (auto FemTetConstraint = std::dynamic_pointer_cast<imstk::PbdFemTetConstraint>(Constraint))
				FemTetConstraint->setInverstionHandling(false);
		}
	}*/

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
	if (!MeshGeom && !PointSetGeom) {
		if (GeomFilter.GeomType != EGeometryType::PointSet) {
			MeshGeom = std::dynamic_pointer_cast<imstk::SurfaceMesh>(PbdObject->getVisualGeometry());
		}
		else {
			PointSetGeom = std::dynamic_pointer_cast<imstk::PointSet>(PbdObject->getVisualGeometry());
		}
	}

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



		// If the number of verts and triangles is the same then just update the positions, otherwise clear the old mesh section and create a new one
		if (Verts.Num() == MeshComp->GetProcMeshSection(0)->ProcVertexBuffer.Num() && (GeomFilter.GeomType == EGeometryType::PointSet || MeshGeom->getNumTriangles() * 3 == MeshComp->GetProcMeshSection(0)->ProcIndexBuffer.Num())) {
			MeshComp->UpdateMeshSection_LinearColor(0, Verts, Normals, UV0, VertColors, Tangents);
		}
		else {
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