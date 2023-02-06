// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DynamicalModel.h"
#include "ProceduralMeshComponent.h"
#include "ImageDataAsset.h"
#include "imstkLevelSetDeformableObject.h"

#include "imstkLocalMarchingCubes.h"
#include "LevelSetModel.generated.h"

/** \file LevelSetModel.h
 *  \brief Generates a level set deformable model using the ImageDataAsset provided
 *  \details Contains LevelSetObject class and ULevelSetModel class
 */

class LevelSetObject : public imstk::LevelSetDeformableObject
{
public:
	LevelSetObject(UProceduralMeshComponent* ProcMeshComp, UImageDataAsset* ImageData, ULevelSetModel* LevelSetModel, UMaterial* Material);
	LevelSetObject(UProceduralMeshComponent* ProcMeshComp, std::shared_ptr<imstk::SurfaceMesh> SurfMesh, ULevelSetModel* LevelSetModel, UMaterial* Material);
	~LevelSetObject() override = default;

public:
	///
	/// \brief Update the isosurface before rendering, the isosurface
	/// is not used for simulation so we can afford to update it
	/// less frequently
	///
	void visualUpdate() override;

	///
	/// \brief Creates visual models for any chunk that has non-zero vertices
	/// and is not already generated
	///
	void createVisualModels();

	void setUseRandomChunkColors(const bool useRandom) { m_useRandomChunkColors = useRandom; }
	bool getUseRandomChunkColors() const { return m_useRandomChunkColors; }

	void UpdateUnrealMesh();

protected:
	///
	/// \brief Forwards/copies the levelsets list of modified voxels to the isosurface
	/// extraction filters list of modified voxels
	///
	void updateModifiedVoxels();

	///
	/// \brief Setup connectivity of task graph
	///
	virtual void initGraphEdges(std::shared_ptr<imstk::TaskNode> source, std::shared_ptr<imstk::TaskNode> sink) override;

public:
	std::shared_ptr<imstk::ImageData> InitLvlSetImage;
protected:
	std::shared_ptr<imstk::LocalMarchingCubes> m_isoExtract;
	std::unordered_set<int>   m_chunksGenerated;               // Lazy generation of chunks
	std::shared_ptr<imstk::TaskNode> m_forwardModifiedVoxels;
	bool m_useRandomChunkColors = false;

	UPROPERTY()
		UProceduralMeshComponent* MeshComp;
	UPROPERTY()
		UMaterial* Material;
};



UCLASS(ClassGroup = (Imstk), meta = (BlueprintSpawnableComponent))
class IMSTK_API ULevelSetModel : public UDynamicalModel
{
	GENERATED_BODY()

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void InitializeComponent() override;

	/** Initializes the rigid object that is defined in editor through the geometry filter
	* @return None
	*/
	virtual void Init() override;

	// Image data asset to generate the iMSTK object from
	UPROPERTY(EditAnywhere, Category = "iMSTK")
		UImageDataAsset* ImageData;

	UPROPERTY(EditAnywhere, meta = (EditCondition = "ImageData == nullptr", EditConditionHides), Category = "iMSTK")
		FIntVector Dimensions = FIntVector(1, 1, 1);

	UPROPERTY(EditAnywhere, meta = (EditCondition = "ImageData == nullptr", EditConditionHides), Category = "iMSTK")
		AActor* BoundingActor;

	UPROPERTY(EditAnywhere, Category = "iMSTK")
		FIntVector NumChunks = FIntVector(1, 1, 1);

	// The material to be set on each section of the mesh (TODO)
	UPROPERTY(EditAnywhere, Category = "iMSTK")
		UMaterial* ImageMaterial;

	// The iMSTK LevelSet Object
	std::shared_ptr<LevelSetObject> LevelSetObj;

	/** Generates the data for the surface mesh. Can be called in the blueprint to obtain vertices, indices and normals for the mesh
	* @return the MeshDataStruct containing information regarding the surface mesh of the levelset
	*/
	UFUNCTION(BlueprintCallable, Category = "iMSTKTEST")
		FMeshDataStruct GenerateSurfaceMeshData(bool FlipNormals = false);


	FVector3f MinBounds;
	FVector3f MaxBounds;

protected:
	// The mesh component that will be generated to represent the LevelSet during runtime
	UPROPERTY()
		UProceduralMeshComponent* MeshComp;

	// The mesh component to represent the LevelSet when using the editor. Will be disabled upon starting the game
	UPROPERTY(BlueprintReadWrite, Category = "iMSTK")
		UProceduralMeshComponent* EditorMeshComp;

	std::shared_ptr<imstk::SurfaceMesh> GetSurfaceMeshFromStatic();

	void FindBounds();

	/** Updates the visuals for the LevelSet model
	* @return none
	*/
	void UpdateModel();

public:
	virtual void UnInit() override;
};

