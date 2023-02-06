// Fill out your copyright notice in the Description page of Project Settings.


#include "ControllerCuttingTool.h"
#include "ImstkController.h"
#include "ImstkSubsystem.h"

EControllerObjectType UControllerCuttingTool::Init(UImstkController* Controller, const FControllerToolFilter& ToolFilter)
{
	SubsystemInstance = Controller->GetWorld()->GetGameInstance()->GetSubsystem<UImstkSubsystem>();
	if (Controller->ToolGeomFilter.GeomType != EGeometryType::SurfaceMesh) {
		SubsystemInstance->LogToUnrealAndImstk("Error: Geometry type not implemented for cutting controllers for " + Controller->GetName(), FColor::Red);
		return EControllerObjectType::Null;
	}

	ControllerComponent = Controller;

	ControllerToolFilter = ToolFilter;

	bIsInitialized = true;

	return EControllerObjectType::PbdToolObject;
}

std::shared_ptr<imstk::SceneObject> UControllerCuttingTool::CreateInteraction(UDynamicalModel* OtherObject)
{
	if (std::shared_ptr<imstk::PbdObject> PBDObject = std::dynamic_pointer_cast<imstk::PbdObject>(OtherObject->ImstkCollidingObject)) {
		std::shared_ptr<imstk::PbdObjectCutting> Cutting = std::make_shared<imstk::PbdObjectCutting>(PBDObject, ControllerComponent->GetToolObj());
		Cutting->setEpsilon(ControllerToolFilter.CuttingToolStruct.CutEpsilon);
		Cuttings.Add(Cutting);

		SubsystemInstance->LogToUnrealAndImstk("Interaction created between " + FString(OtherObject->ImstkCollidingObject->getName().c_str()) + " and " + FString(ControllerComponent->GetToolObj()->getName().c_str()), FColor::Green);
		return Cutting;
	}
	else {
		SubsystemInstance->LogToUnrealAndImstk("Model must be deformable. Cutting interaction could not be created between " + FString(OtherObject->ImstkCollidingObject->getName().c_str()) + " " + FString(ControllerComponent->GetToolObj()->getName().c_str()) + ".", FColor::Red);
		return nullptr;
	}
}


bool UControllerCuttingTool::Execute()
{
	bool Cut = false;
	if (Cuttings.Num() > 0) {
		if (ControllerComponent->ToolGeomFilter.GeomType = EGeometryType::SurfaceMesh) {
			for (std::shared_ptr<imstk::PbdObjectCutting> Cutting : Cuttings) {
				Cutting->apply();
				Cut = true;
			}
		}
	}
	else {
		SubsystemInstance->LogToUnrealAndImstk("Cutting not assigned", FColor::Red);
	}
	return Cut;
}

void UControllerCuttingTool::UnInit() {
	Super::UnInit();
	for (auto Cut : Cuttings)
		Cut.reset();
	Cuttings.Empty();
}
