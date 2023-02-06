// Fill out your copyright notice in the Description page of Project Settings.


#include "GeometryFilter.h"
#include "ImstkController.h"

//FGeometryType::~FGeometryType() {};

std::shared_ptr<imstk::Geometry> FSphereGeomStruct::Init() const
{
	std::shared_ptr<imstk::Sphere> SphereGeom = std::make_shared<imstk::Sphere>();

	SphereGeom->setRadius(Radius / UMathUtil::GetScale());
	SphereGeom->setPosition(UMathUtil::ToImstkVec3d(GeometryOffset, true));
	SphereGeom->updatePostTransformData();
	return SphereGeom;
}

FVector FSphereGeomStruct::GetGeomScale() {
	return FVector(Radius / 50, Radius / 50, Radius / 50);
}

std::shared_ptr<imstk::Geometry> FSurfaceMeshGeomStruct::Init(UDynamicalModel* Model) const {
	std::shared_ptr<imstk::SurfaceMesh> MeshGeom = std::make_shared<imstk::SurfaceMesh>();
	AActor* Actor = Model->GetOwner();

	UStaticMeshComponent* StaticMeshComp = (UStaticMeshComponent*)Actor->GetComponentByClass(UStaticMeshComponent::StaticClass());
	UProceduralMeshComponent* ProcMeshComp = (UProceduralMeshComponent*)Actor->GetComponentByClass(UProceduralMeshComponent::StaticClass());

	// If the actor is a controller then find the first static mesh attached to controller.
	// TODO: if there are multiple static meshes attached to controller it will only get the first
	if (UImstkController* Controller = (UImstkController*)Actor->GetComponentByClass(UImstkController::StaticClass())) {
		TArray<USceneComponent*> Components;
		Controller->GetChildrenComponents(true, Components);
		for (USceneComponent* Comp : Components) {
			if (UStaticMeshComponent* MeshComp = (UStaticMeshComponent*)Comp) {
				StaticMeshComp = MeshComp;
				break;
			}
		}
	}

	if (StaticMeshComp) {
		if (!StaticMeshComp->GetStaticMesh()->bAllowCPUAccess)
			FMessageLog("PIE").Warning(FText::FromString("'Allow CPU Access' is not enabled for " + StaticMeshComp->GetStaticMesh()->GetFName().ToString() + ". This is required to access static mesh data in the packaged game."));
		
		// Get vertices and indices from static mesh and create imstk geometry
		FPositionVertexBuffer* PositionVertexBuffer = &StaticMeshComp->GetStaticMesh()->GetRenderData()->LODResources[0].VertexBuffers.PositionVertexBuffer;
		FRawStaticIndexBuffer* IndexBuffer = &StaticMeshComp->GetStaticMesh()->GetRenderData()->LODResources[0].IndexBuffer;

		FStaticMeshVertexBuffer* TexCoordBuffer = &StaticMeshComp->GetStaticMesh()->GetRenderData()->LODResources[0].VertexBuffers.StaticMeshVertexBuffer;
		StaticMeshComp->GetStaticMesh()->GetRenderData()->LODResources[0].VertexBuffers.StaticMeshVertexBuffer.GetTexCoordData();

		// Get vertices and indices in the mesh and set those values in the imstk mesh
		TArray<FVector> Vertices;
		std::shared_ptr<imstk::VecDataArray<float, 2>> TCoords = std::make_shared<imstk::VecDataArray<float, 2>>();
		for (uint32 i = 0; i < PositionVertexBuffer->GetNumVertices(); i++) {
			Vertices.Add(FVector(PositionVertexBuffer->VertexPosition(i)));
			TCoords->push_back(imstk::Vec2f(TexCoordBuffer->GetVertexUV(i, 0).X, TexCoordBuffer->GetVertexUV(i, 0).Y));
		}

		TArray<int> Indices;
		for (int32 i = 0; i < IndexBuffer->GetNumIndices(); i++) {
			Indices.Add(IndexBuffer->GetIndex(i));
		}

		MeshGeom->initialize(UMathUtil::ToImstkVecDataArray3d(Vertices, true), UMathUtil::ToImstkVecDataArray3i(Indices));
		MeshGeom->setVertexTCoords("tcoords", TCoords);
		MeshGeom->computeVertexNormals();
	}
	else if (ProcMeshComp) {
		// Get vertices and indices from procedural mesh and create imstk geometry
		TArray<FProcMeshVertex> VertexBuffer = ProcMeshComp->GetProcMeshSection(0)->ProcVertexBuffer;
		TArray<uint32> IndexBuffer = ProcMeshComp->GetProcMeshSection(0)->ProcIndexBuffer;

		// Get vertices and indices in the mesh and set those values in the imstk mesh
		TArray<FVector> Vertices;
		std::shared_ptr<imstk::VecDataArray<float, 2>> TCoords = std::make_shared<imstk::VecDataArray<float, 2>>();
		for (int32 i = 0; i < VertexBuffer.Num(); i++) {
			Vertices.Add(VertexBuffer[i].Position);
			TCoords->push_back(imstk::Vec2f((float)VertexBuffer[i].UV0[0], (float)VertexBuffer[i].UV0[1]));
		}

		TArray<int> Indices;
		for (int32 i = 0; i < IndexBuffer.Num(); i++) {
			Indices.Add(IndexBuffer[i]);
		}

		MeshGeom->initialize(UMathUtil::ToImstkVecDataArray3d(Vertices, true), UMathUtil::ToImstkVecDataArray3i(Indices));

		MeshGeom->setVertexTCoords("tcoords", TCoords);
		MeshGeom->computeVertexNormals();
	}
	else {
		// ERROR
		return nullptr;
	}

	if (bFlipNormals)
		MeshGeom->flipNormals();

	return MeshGeom;
}

std::shared_ptr<imstk::Geometry> FSurfaceMeshGeomStruct::Init(UImstkController* Controller) const {
	std::shared_ptr<imstk::SurfaceMesh> MeshGeom = std::make_shared<imstk::SurfaceMesh>();

	// If the actor is a controller then find the first static mesh attached to controller.
	// TODO: if there are multiple static meshes attached to controller it will only get the first
	UStaticMeshComponent* StaticMeshComp = nullptr;

	TArray<USceneComponent*> Components;
	Controller->GetChildrenComponents(false, Components);

	int Count = 0;
	for (USceneComponent* Comp : Components) {
		if (Comp->IsA(UStaticMeshComponent::StaticClass())) {
			StaticMeshComp = (UStaticMeshComponent*)Comp;
			Count++;
		}
	}
	if (Count > 1) {
		Controller->GetWorld()->GetGameInstance()->GetSubsystem<UImstkSubsystem>()->LogToUnrealAndImstk("Warning: More than one static mesh component is attached to controller " + Controller->GetName() + ". Behaviour May not function as expected.", FColor::Yellow);
	}


	if (StaticMeshComp) {
		if (!StaticMeshComp->GetStaticMesh()->bAllowCPUAccess)
		{
			FMessageLog("PIE").Warning(FText::FromString("'Allow CPU Access' is not enabled for " + StaticMeshComp->GetStaticMesh()->GetFName().ToString() + ". This is required to access static mesh data in the packaged game."));
		}

		// Get vertices and indices from static mesh and create imstk geometry
		FPositionVertexBuffer* PositionVertexBuffer = &StaticMeshComp->GetStaticMesh()->GetRenderData()->LODResources[0].VertexBuffers.PositionVertexBuffer;
		FRawStaticIndexBuffer* IndexBuffer = &StaticMeshComp->GetStaticMesh()->GetRenderData()->LODResources[0].IndexBuffer;

		// Get vertices and indices in the mesh and set those values in the imstk mesh
		TArray<FVector> Vertices;
		for (uint32 i = 0; i < PositionVertexBuffer->GetNumVertices(); i++) {
			Vertices.Add(FVector(PositionVertexBuffer->VertexPosition(i)));
		}

		TArray<int> Indices;
		for (int32 i = 0; i < IndexBuffer->GetNumIndices(); i++) {
			Indices.Add(IndexBuffer->GetIndex(i));
		}

		MeshGeom->initialize(UMathUtil::ToImstkVecDataArray3d(Vertices, true), UMathUtil::ToImstkVecDataArray3i(Indices));
		MeshGeom->computeVertexNormals();
	}
	else {
		// ERROR
		return nullptr;
	}

	if (bFlipNormals)
		MeshGeom->flipNormals();

	return MeshGeom;
}

FVector FSurfaceMeshGeomStruct::GetGeomScale() {
	return FVector::ZeroVector;
}


std::shared_ptr<imstk::Geometry> FCapsuleGeomStruct::Init() const {
	std::shared_ptr<imstk::Capsule> CapsuleGeom = std::make_shared<imstk::Capsule>();
	CapsuleGeom->setRadius(Radius / UMathUtil::GetScale());
	CapsuleGeom->setLength(Length / UMathUtil::GetScale());
	CapsuleGeom->setPosition(UMathUtil::ToImstkVec3d(GeometryOffset, true));
	CapsuleGeom->updatePostTransformData();
	return CapsuleGeom;
}

FVector FCapsuleGeomStruct::GetGeomScale() {
	return FVector(Radius / 25, Radius / 25, Length / 100);
}


std::shared_ptr<imstk::Geometry> FCylinderGeomStruct::Init() const {
	std::shared_ptr<imstk::Cylinder> CylinderGeom = std::make_shared<imstk::Cylinder>();

	CylinderGeom->setRadius(Radius / UMathUtil::GetScale());
	CylinderGeom->setLength(Length / UMathUtil::GetScale());
	CylinderGeom->setPosition(UMathUtil::ToImstkVec3d(GeometryOffset, true));
	CylinderGeom->updatePostTransformData();
	return CylinderGeom;
}

FVector FCylinderGeomStruct::GetGeomScale() {
	return FVector(Radius / 25, Radius / 25, Length / 100);
}


std::shared_ptr<imstk::Geometry> FPointSetGeomStruct::Init(UDynamicalModel* Model) const {
	std::shared_ptr<imstk::PointSet> MeshGeom = std::make_shared<imstk::PointSet>();
	AActor* Actor = Model->GetOwner();

	UStaticMeshComponent* StaticMeshComp = (UStaticMeshComponent*)Actor->GetComponentByClass(UStaticMeshComponent::StaticClass());
	UProceduralMeshComponent* ProcMeshComp = (UProceduralMeshComponent*)Actor->GetComponentByClass(UProceduralMeshComponent::StaticClass());
	if (StaticMeshComp) {
		if (!StaticMeshComp->GetStaticMesh()->bAllowCPUAccess)
		{
			FMessageLog("PIE").Warning(FText::FromString("'Allow CPU Access' is not enabled for " + StaticMeshComp->GetStaticMesh()->GetFName().ToString() + ". This is required to access static mesh data in the packaged game."));
		}
		FPositionVertexBuffer* PositionVertexBuffer = &StaticMeshComp->GetStaticMesh()->GetRenderData()->LODResources[0].VertexBuffers.PositionVertexBuffer;

		// Get vertices and indices in the mesh and set those values in the imstk mesh
		TArray<FVector> Vertices;
		for (uint32 i = 0; i < PositionVertexBuffer->GetNumVertices(); i++) {
			Vertices.Add(FVector(PositionVertexBuffer->VertexPosition(i)));
		}

		MeshGeom->initialize(UMathUtil::ToImstkVecDataArray3d(Vertices, true));
		MeshGeom->updatePostTransformData();
		return MeshGeom;
	}
	else if (ProcMeshComp) {

		TArray<FProcMeshVertex> VertexBuffer = ProcMeshComp->GetProcMeshSection(0)->ProcVertexBuffer;

		// Get vertices and indices in the mesh and set those values in the imstk mesh
		TArray<FVector> Vertices;
		for (int32 i = 0; i < VertexBuffer.Num(); i++) {
			Vertices.Add(VertexBuffer[i].Position);
		}

		MeshGeom->initialize(UMathUtil::ToImstkVecDataArray3d(Vertices, true));
		MeshGeom->updatePostTransformData();
		return MeshGeom;

	}
	else {
		// ERROR
		return nullptr;
	}
}

std::shared_ptr<imstk::Geometry> FPointSetGeomStruct::Init(UImstkController* Controller) const {
	std::shared_ptr<imstk::PointSet> MeshGeom = std::make_shared<imstk::PointSet>();
	UStaticMeshComponent* StaticMeshComp = nullptr;

	// If the actor is a controller then find the first static mesh attached to controller.
	// TODO: if there are multiple static meshes attached to controller it will only get the first
	TArray<USceneComponent*> Components;
	Controller->GetChildrenComponents(true, Components);
	for (USceneComponent* Comp : Components) {
		if (UStaticMeshComponent* MeshComp = (UStaticMeshComponent*)Comp) {
			StaticMeshComp = MeshComp;
			break;
		}
	}

	if (StaticMeshComp) {
		if (!StaticMeshComp->GetStaticMesh()->bAllowCPUAccess)
		{
			FMessageLog("PIE").Warning(FText::FromString("'Allow CPU Access' is not enabled for " + StaticMeshComp->GetStaticMesh()->GetFName().ToString() + ". This is required to access static mesh data in the packaged game."));
		}
		FPositionVertexBuffer* PositionVertexBuffer = &StaticMeshComp->GetStaticMesh()->GetRenderData()->LODResources[0].VertexBuffers.PositionVertexBuffer;

		// Get vertices and indices in the mesh and set those values in the imstk mesh
		TArray<FVector> Vertices;
		for (uint32 i = 0; i < PositionVertexBuffer->GetNumVertices(); i++) {
			Vertices.Add(FVector(PositionVertexBuffer->VertexPosition(i)));
		}

		MeshGeom->initialize(UMathUtil::ToImstkVecDataArray3d(Vertices, true));
		MeshGeom->updatePostTransformData();
		return MeshGeom;
	}
	else {
		// ERROR
		return nullptr;
	}
}

FVector FPointSetGeomStruct::GetGeomScale() {
	return FVector::ZeroVector;
}


std::shared_ptr<imstk::Geometry> FOrientedBoxGeomStruct::Init() const {
	std::shared_ptr<imstk::OrientedBox> BoxGeom = std::make_shared<imstk::OrientedBox>();
	BoxGeom->setExtents(UMathUtil::ToImstkVec3d(Extents, true));
	return BoxGeom;
}

FVector FOrientedBoxGeomStruct::GetGeomScale() {
	return FVector::ZeroVector;
}


std::shared_ptr<imstk::Geometry> FPlaneGeomStruct::Init() const {
	std::shared_ptr<imstk::Plane> PlaneGeom = std::make_shared<imstk::Plane>();
	PlaneGeom->setNormal(UMathUtil::ToImstkVec3d(Normal, false));
	return PlaneGeom;
}

FVector FPlaneGeomStruct::GetGeomScale() {
	return FVector::ZeroVector;
}


std::shared_ptr<imstk::Geometry> FLineMeshGeomStruct::Init() const {
	std::shared_ptr<imstk::LineMesh> LineMeshGeom = std::make_shared<imstk::LineMesh>();
	std::shared_ptr<imstk::VecDataArray<double, 3>> VertPtr = UMathUtil::ToImstkVecDataArray3d(Vertices, true);
	std::shared_ptr<imstk::VecDataArray<int, 2>> IndicesPtr = std::make_shared<imstk::VecDataArray<int, 2>>();
	if (Vertices.Num() < 1)
		return LineMeshGeom;

	for (int i = 1; i < Vertices.Num(); i++) {
		IndicesPtr->push_back(imstk::Vec2i(i - 1, i));
	}

	LineMeshGeom->initialize(VertPtr, IndicesPtr);
	return LineMeshGeom;
}

FVector FLineMeshGeomStruct::GetGeomScale() {
	return FVector::ZeroVector;
}

FGeometryFilter::FGeometryFilter() {
	// Default to sphere
	GeomType = EGeometryType::SurfaceMesh;
}

std::shared_ptr<imstk::Geometry> FGeometryFilter::Init(UDynamicalModel* Model)
{
	switch (GeomType)
	{
	case 0:
		return SphereStruct.Init();
	case 1:
		return MeshStruct.Init(Model);
	case 2:
		return CapsuleStruct.Init();
	case 3:
		return CylinderStruct.Init();
	case 4:
		return PointSetStruct.Init(Model);
	case 5:
		return OrientedBoxStruct.Init();
	case 6:
		return PlaneStruct.Init();
	case 7:
		return LineMeshStruct.Init();
	default:
		return nullptr;
	}
}

std::shared_ptr<imstk::Geometry> FGeometryFilter::Init(UImstkController* Controller)
{
	switch (GeomType)
	{
	case 0:
		return SphereStruct.Init();
	case 1:
		return MeshStruct.Init(Controller);
	case 2:
		return CapsuleStruct.Init();
	case 3:
		return CylinderStruct.Init();
	case 4:
		return PointSetStruct.Init(Controller);
	case 5:
		return OrientedBoxStruct.Init();
	case 6:
		return PlaneStruct.Init();
	case 7:
		return LineMeshStruct.Init();
	default:
		return nullptr;
	}
}

FVector FGeometryFilter::GetGeomScale() {
	switch (GeomType)
	{
	case 0:
		return SphereStruct.GetGeomScale();
	case 1:
		return MeshStruct.GetGeomScale();
	case 2:
		return CapsuleStruct.GetGeomScale();
	case 3:
		return CylinderStruct.GetGeomScale();
	case 4:
		return PointSetStruct.GetGeomScale();
	case 5:
		return OrientedBoxStruct.GetGeomScale();
	case 6:
		return PlaneStruct.GetGeomScale();
	case 7:
		return LineMeshStruct.GetGeomScale();
	default:
		return FVector::ZeroVector;
	}
}

FVector FGeometryFilter::GetGeomOffset() {
	switch (GeomType)
	{
	case 0:
		return SphereStruct.GeometryOffset;
	case 1:
		return FVector::ZeroVector;
	case 2:
		return CapsuleStruct.GeometryOffset;
	case 3:
		return CylinderStruct.GeometryOffset;
	case 4:
		return FVector::ZeroVector;
	case 5:
		return FVector::ZeroVector;
	case 6:
		return FVector::ZeroVector;
	case 7:
		return FVector::ZeroVector;
	default:
		return FVector::ZeroVector;
	}
}
