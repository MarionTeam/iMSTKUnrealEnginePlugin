// Fill out your copyright notice in the Description page of Project Settings.


#include "HapticsThread.h"
#include "ImstkSubsystem.h"

// Sets default values
FHapticsThread::FHapticsThread(std::shared_ptr<imstk::DeviceManager> HapticManager, UWorld* WorldReference, float TimeInterval)
{
	this->HapticManager = HapticManager;
	World = WorldReference;
	this->TimeInterval = TimeInterval;
}

bool FHapticsThread::Init()
{
	bStopThread = false;
	HapticManager->init();

	World->GetGameInstance()->GetSubsystem<UImstkSubsystem>()->LogToUnrealAndImstk("Initialized haptics thread", FColor::Green);
	return true;
}

uint32 FHapticsThread::Run()
{
	while (!bStopThread)
	{
		if (HapticManager)
			HapticManager->update();
	}

	return 0;
}

void FHapticsThread::Stop()
{
	HapticManager->uninit();
	HapticManager.reset();
}


