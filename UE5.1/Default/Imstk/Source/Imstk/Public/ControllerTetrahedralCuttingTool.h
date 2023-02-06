// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ControllerTool.h"
#include "PBDModel.h"
#include "imstkPbdObjectCellRemoval.h"
#include "ControllerTetrahedralCuttingTool.generated.h"

/** \file ControllerTetrahedralCuttingTool.h
 *  \brief Object for a tetrahedral cutting tool
 *  \details Initializes the tool and creates the interactions between an object and the tool
 */
UCLASS()
class IMSTK_API UControllerTetrahedralCuttingTool : public UControllerTool
{
	GENERATED_BODY()

public:
	/** Initializes the tetrahedral cutting controller tool and tells the controller which type of tool to generate
	* @param Controller - The controller the tool is attached to
	* @param ToolFilter - The tool filter of the controller for this particular tool
	* @return EControllerObjectType - Returns the type of tool the controller must create for the tool to be functional
	*/
	virtual EControllerObjectType Init(UImstkController* Controller, const FControllerToolFilter& ToolFilter) override;

	/** Initializes the tet cutting interaction
	* @param OtherObject - The object to be cut
	* @return std::shared_ptr<imstk::SceneObject> The generated interaction or nullptr if there was an error in generation
	*/
	virtual std::shared_ptr<imstk::SceneObject> CreateInteraction(UDynamicalModel* OtherObject) override;

	/** Executes each tet cut
	* @return bool - True if tet is cut, false if tet is not cut
	*/
	virtual bool Execute() override;

	virtual void UnInit() override;

protected:
	// Cutting interactions generated with this tool
	TArray<std::shared_ptr<imstk::PbdObjectCellRemoval>> TetCuttings;

	// Each tet mesh to be cut
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
