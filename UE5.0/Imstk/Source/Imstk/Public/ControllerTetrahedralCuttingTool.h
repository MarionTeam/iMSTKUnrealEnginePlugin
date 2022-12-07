// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ControllerTool.h"
#include "PBDModel.h"
#include "imstkTetrahedralMesh.h"
#include "imstkPbdObjectCellRemoval.h"
#include "ControllerTetrahedralCuttingTool.generated.h"

/**
 * 
 */
UCLASS()
class IMSTK_API UControllerTetrahedralCuttingTool : public UControllerTool
{
	GENERATED_BODY()

public:
	virtual EControllerObjectType Init(UImstkController* Controller, const FControllerToolFilter& ToolFilter) override;

	virtual bool CreateInteraction(UDynamicalModel* OtherObject) override;

	virtual bool Execute() override;

	virtual void UnInit() override;

protected:
	TArray<std::shared_ptr<imstk::PbdObjectCellRemoval>> TetCuttings;
	UPROPERTY()
		TArray<UPBDModel*> CutObjects;
	
	// Helper functions to determine the cut
	bool SplitTest(const std::array<imstk::Vec3d, 4>& InputTetVerts,
		const imstk::Vec3d& PlaneOrigin,
		const imstk::Vec3d& U, const double Width,
		const imstk::Vec3d& V, const double Height,
		const imstk::Vec3d& N);
	bool IsIntersect(const double A, const double B, const double C, const double D);
};
