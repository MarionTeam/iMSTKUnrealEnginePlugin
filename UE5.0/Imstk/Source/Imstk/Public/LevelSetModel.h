// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DynamicalModel.h"
#include "ProceduralMeshComponent.h"
#include "imstkLevelSetDeformableObject.h"

#include "imstkLocalMarchingCubes.h"

#include "LevelSetModel.generated.h"


class FemurObject : public imstk::LevelSetDeformableObject
{
public:
    FemurObject();
    ~FemurObject() override = default;

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

protected:
    std::shared_ptr<imstk::LocalMarchingCubes> m_isoExtract;
    std::unordered_set<int>   m_chunksGenerated;               // Lazy generation of chunks
    std::shared_ptr<imstk::TaskNode> m_forwardModifiedVoxels;
    bool m_useRandomChunkColors = false;
};





/**
 * 
 */
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

protected:
	UPROPERTY()
		UProceduralMeshComponent* MeshComp;

	void UpdateModel();

	std::shared_ptr<imstk::LevelSetDeformableObject> LevelsetObj;
    std::shared_ptr<FemurObject> TESTObj;

	void CreateVisualSections();
	std::shared_ptr<imstk::LocalMarchingCubes> m_isoExtract;
	std::unordered_set<int> m_chunksGenerated;
};
