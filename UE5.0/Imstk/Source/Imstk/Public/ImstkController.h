// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
//#include "ImstkSubsystem.h"
//#include "RBDModel.h"
#include "iMSTK-5.0/imstkRigidObject2.h"
#include "iMSTK-5.0/imstkPbdObjectStitching.h"
#include "iMSTK-5.0/imstkPbdRigidObjectGrasping.h"
#include "ImstkController.generated.h"

class UImstkSubsystem;

UENUM()
enum EToolGeometry
{
	LineMeshTool,
	SphereTool
};


/** \file ImstkController.h
 *  \brief Abstract class for object in imstk that can be controlled by the user
 *  \details 
 */
UCLASS(Abstract)
class IMSTK_API UImstkController : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UImstkController();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY()
		UImstkSubsystem* SubsystemInstance;

	bool bIsInitialized = false;
	std::shared_ptr<imstk::RigidObject2> ToolObj;

	std::shared_ptr<imstk::PbdRigidObjectGrasping> ToolPicking;

	std::shared_ptr<imstk::PbdObjectStitching> Stitching;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	virtual void InitializeComponent() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "General")
		TEnumAsByte<EToolGeometry> ToolGeometry;

	// TODO: If you set as true with a spheretool then change geometry it will be hidden but still set to true
	UPROPERTY(EditAnywhere, meta = (EditCondition = "ToolGeometry == EToolGeometry::SphereTool", EditConditionHides), Category = "General")
		bool bGraspingTool = false;

	UPROPERTY(EditAnywhere, meta = (EditCondition = "ToolGeometry == EToolGeometry::LineMeshTool", EditConditionHides), Category = "General")
		bool bStitchingTool = false;

	//std::shared_ptr<imstk::PbdObjectStitching> Stitching;

	/** Initializes the controller in imstk
	* @return None
	*/
	virtual void InitController();

	std::shared_ptr<imstk::RigidObject2> GetToolObj();

	void SetToolPicking(std::shared_ptr<imstk::PbdRigidObjectGrasping> Picking);

	void SetStitching(std::shared_ptr<imstk::PbdObjectStitching> Stitching);

	virtual void UnInit();

};
