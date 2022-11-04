// Fill out your copyright notice in the Description page of Project Settings.


#include "PortHoleInteraction.h"
#include "ImstkSubsystem.h"
#include "MathUtil.h"
#include "imstkPortHoleInteraction.h"



void UPortHoleInteraction::Init()
{
	//UImstkSubsystem* SubsystemInstance = GetWorld()->GetGameInstance()->GetSubsystem<UImstkSubsystem>();
	if (auto PbdToolObj = std::dynamic_pointer_cast<imstk::PbdObject>(Controller->GetToolObj())) {
		auto Porthole = Controller->GetToolObj()->addComponent<imstk::PortHoleInteraction>();
		Porthole->setTool(PbdToolObj);
		Porthole->setPortHoleLocation(UMathUtil::ToImstkVec3d(PortHoleActor->GetActorLocation(), true));
		Porthole->setToolGeometry(Controller->GetToolObj()->getCollidingGeometry());
		Porthole->setCompliance(Compliance);
	}
	else {
		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "Initializing porthole interaction between " + FString(Controller->GetToolObj()->getName().c_str()) + " and " + PortHoleActor->GetName() + " failed");
		UE_LOG(LogTemp, Error, TEXT("Initializing interaction between %s and %s failed"), Controller->GetToolObj()->getName().c_str(), *PortHoleActor->GetName());
		return;
	}

	//SubsystemInstance->ActiveScene->addInteraction(Porthole);
}
