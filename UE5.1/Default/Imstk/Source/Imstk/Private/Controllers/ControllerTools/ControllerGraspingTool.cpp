// Fill out your copyright notice in the Description page of Project Settings.


#include "ControllerGraspingTool.h"
#include "ImstkSubsystem.h"
#include "ImstkController.h"

#include "imstkPbdRigidObjectGrasping.h"

// Currently can not handle ray point grasps
EControllerObjectType UControllerGraspingTool::Init(UImstkController* Controller, const FControllerToolFilter& ToolFilter)
{
	SubsystemInstance = Controller->GetWorld()->GetGameInstance()->GetSubsystem<UImstkSubsystem>();

	if (Controller->ToolGeomFilter.GeomType != EGeometryType::Sphere && Controller->ToolGeomFilter.GeomType != EGeometryType::Capsule) {
		SubsystemInstance->LogToUnrealAndImstk("Error: Controller type to Geometry mismatch for " + Controller->GetName(), FColor::Red);
		bIsInitialized = false;
		return EControllerObjectType::Null;
	}

	ControllerComponent = Controller;

	ControllerToolFilter = ToolFilter;

	bIsInitialized = true;
	if (ToolFilter.GraspingToolStruct.bRigidTool)
		return EControllerObjectType::RigidToolObject;
	else
		return EControllerObjectType::PbdToolObject;
}

std::shared_ptr<imstk::SceneObject> UControllerGraspingTool::CreateInteraction(UDynamicalModel* OtherObject)
{
	if (std::shared_ptr<imstk::PbdObject> DeformableObj = std::dynamic_pointer_cast<imstk::PbdObject>(OtherObject->ImstkCollidingObject)) {
		std::shared_ptr<imstk::PbdObjectGrasping> ToolPicking;
		if (ControllerToolFilter.GraspingToolStruct.GraspType == EGraspType::VertexGrasp) {
			if (std::shared_ptr<imstk::RigidObject2> RigidObjectTool = std::dynamic_pointer_cast<imstk::RigidObject2>(ControllerComponent->GetToolObj()))
				ToolPicking = std::make_shared<imstk::PbdRigidObjectGrasping>(DeformableObj, RigidObjectTool);
			else
				ToolPicking = std::make_shared<imstk::PbdObjectGrasping>(DeformableObj, std::dynamic_pointer_cast<imstk::PbdObject>(ControllerComponent->GetToolObj()));
		}
		else if (ControllerToolFilter.GraspingToolStruct.GraspType == EGraspType::CellGrasp) {
			ToolPicking = std::make_shared<imstk::PbdObjectGrasping>(std::dynamic_pointer_cast<imstk::PbdObject>(DeformableObj), std::dynamic_pointer_cast<imstk::PbdObject>(ControllerComponent->GetToolObj()));
		}
		ToolPicking->setCompliance(ControllerToolFilter.GraspingToolStruct.GraspCompliance);
		ToolPicking->setName("PbdObjectGrasping_" + DeformableObj->getName() + "_" + ControllerComponent->GetToolObj()->getName());
		ToolPicking->setStiffness(ControllerToolFilter.GraspingToolStruct.GraspStiffness);
		SubsystemInstance->ActiveScene->addInteraction(ToolPicking);
		ToolPickings.Add(ToolPicking);
		SubsystemInstance->LogToUnrealAndImstk("Interaction created between " + FString(OtherObject->ImstkCollidingObject->getName().c_str()) + " and " + FString(ControllerComponent->GetToolObj()->getName().c_str()), FColor::Green);
		return ToolPicking;
		
	}
	else {
		SubsystemInstance->LogToUnrealAndImstk("Wrong model type. Grasped model must be deformable. Grasping interaction could not be created between  " + FString(OtherObject->ImstkCollidingObject->getName().c_str()) + " " + FString(ControllerComponent->GetToolObj()->getName().c_str()) + ".", FColor::Red);
		return nullptr;
	}
}


bool UControllerGraspingTool::Execute()
{
	// This doesn't return true if it actually grasps, but if grasp attempt was made
	bool Grasped = false;
	if (bIsInitialized) {
		if (ToolPickings.Num() > 0) {
			if (ControllerToolFilter.GraspingToolStruct.GraspType == EGraspType::VertexGrasp) {
				for (std::shared_ptr<imstk::PbdObjectGrasping> ToolPicking : ToolPickings) {
					ToolPicking->beginVertexGrasp(std::dynamic_pointer_cast<imstk::AnalyticalGeometry>(ControllerComponent->GetToolObj()->getCollidingGeometry()));
					Grasped = true;
				}
			}

			if (ControllerToolFilter.GraspingToolStruct.GraspType == EGraspType::CellGrasp) {
				for (std::shared_ptr<imstk::PbdObjectGrasping> ToolPicking : ToolPickings) {
					ToolPicking->beginCellGrasp(std::dynamic_pointer_cast<imstk::AnalyticalGeometry>(ControllerComponent->GetToolObj()->getCollidingGeometry()));
					Grasped = true;
				}
			}
		}
		else {
			SubsystemInstance->LogToUnrealAndImstk("ToolPicking not assigned", FColor::Red);
		}
	}
	return Grasped;
}

bool UControllerGraspingTool::Release()
{
	bool Ended = false;
	if (bIsInitialized) {
		if (ToolPickings.Num() > 0) {
			for (std::shared_ptr<imstk::PbdObjectGrasping> ToolPicking : ToolPickings) {
				ToolPicking->endGrasp();
				Ended = true;
			}
		}
	}
	return Ended;
}

void UControllerGraspingTool::UnInit() {
	Super::UnInit();
	for (auto Picking : ToolPickings)
		Picking.reset();
	ToolPickings.Empty();
}
