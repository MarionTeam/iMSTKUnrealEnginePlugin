// Fill out your copyright notice in the Description page of Project Settings.


#include "ControllerStitchingTool.h"
#include "ImstkController.h"
#include "ImstkSubsystem.h"


// Currently can not handle ray point grasps
EControllerObjectType UControllerStitchingTool::Init(UImstkController* Controller, const FControllerToolFilter& ToolFilter)
{
	SubsystemInstance = Controller->GetWorld()->GetGameInstance()->GetSubsystem<UImstkSubsystem>();
	if (Controller->ToolGeomFilter.GeomType != EGeometryType::LineMesh) {
		SubsystemInstance->LogToUnrealAndImstk("Error: Geometry type not implemented for stitching controllers for " + Controller->GetName(), FColor::Red);
		return EControllerObjectType::Null;
	}

	ControllerComponent = Controller;

	ControllerToolFilter = ToolFilter;

	bIsInitialized = true;

	return EControllerObjectType::PbdToolObject;
}

std::shared_ptr<imstk::SceneObject> UControllerStitchingTool::CreateInteraction(UDynamicalModel* OtherObject)
{
	if (std::shared_ptr<imstk::PbdObject> DeformableObject =  std::dynamic_pointer_cast<imstk::PbdObject>(OtherObject->ImstkCollidingObject)) {
		std::shared_ptr<imstk::PbdObjectStitching> Stitching = std::make_shared<imstk::PbdObjectStitching>(DeformableObject);
		double Dist = (std::dynamic_pointer_cast<imstk::LineMesh>(ControllerComponent->GetToolObj()->getCollidingGeometry())->getVertexPosition(0) - std::dynamic_pointer_cast<imstk::LineMesh>(ControllerComponent->GetToolObj()->getCollidingGeometry())->getVertexPosition(1)).norm();
		Stitching->setStitchDistance(Dist);
		SubsystemInstance->ActiveScene->addInteraction(Stitching);
		Stitchings.Add(Stitching);

		SubsystemInstance->LogToUnrealAndImstk("Interaction created between " + FString(OtherObject->ImstkCollidingObject->getName().c_str()) + " and " + FString(ControllerComponent->GetToolObj()->getName().c_str()), FColor::Green);
		return Stitching;
	}
	else {
		SubsystemInstance->LogToUnrealAndImstk("Model must be deformable. Stitching interaction could not be created between " + FString(OtherObject->ImstkCollidingObject->getName().c_str()) + " " + FString(ControllerComponent->GetToolObj()->getName().c_str()) + ".", FColor::Red);
		return nullptr;
	}
}


bool UControllerStitchingTool::Execute()
{
	bool Stitched = false;
	if (Stitchings.Num() > 0) {
		if (ControllerComponent->ToolGeomFilter.GeomType = EGeometryType::LineMesh) {
			std::shared_ptr<imstk::LineMesh> ToolGeom = std::dynamic_pointer_cast<imstk::LineMesh>(ControllerComponent->GetToolObj()->getCollidingGeometry());

			for (std::shared_ptr<imstk::PbdObjectStitching> Stitching : Stitchings) {
				for (int i = 1; i < ToolGeom->getNumVertices(); i++) {
					Stitching->beginStitch(ToolGeom->getVertexPosition(i - 1), (ToolGeom->getVertexPosition(i) - ToolGeom->getVertexPosition(i - 1)).normalized(), (ToolGeom->getVertexPosition(i) - ToolGeom->getVertexPosition(i - 1)).norm());
					Stitched = true;
				}
			}
		}
	}
	else {
		SubsystemInstance->LogToUnrealAndImstk("Stitching not assigned", FColor::Red);
	}
	return Stitched;
}

void UControllerStitchingTool::UnInit() {
	Super::UnInit();
	for (auto Stitching : Stitchings)
		Stitching.reset();
	Stitchings.Empty();
}