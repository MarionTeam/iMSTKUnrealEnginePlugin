// Fill out your copyright notice in the Description page of Project Settings.


#include "HapticsThread.h"
#include "Kismet/GameplayStatics.h"
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

	World->GetGameInstance()->GetSubsystem<UImstkSubsystem>()->LogToUnrealAndImstk("Initialized haptics thread");
	return true;
}

uint32 FHapticsThread::Run()
{
	//float DeltaTime = 0;
	//float PreviousTime = UGameplayStatics::GetRealTimeSeconds(World);
	while (!bStopThread)
	{
		if (HapticManager)
			HapticManager->update();

		// // This only occurs once every frame anyways so it doesnt do anything unless the time interval is high
		//DeltaTime += UGameplayStatics::GetRealTimeSeconds(World) - PreviousTime ;
		//PreviousTime = UGameplayStatics::GetRealTimeSeconds(World);
		//if (DeltaTime > TimeInterval) {
		//    HapticManager->update();
		//    DeltaTime = 0;
		//}
	}

	return 0;
}

void FHapticsThread::Stop()
{
	HapticManager->uninit();
	HapticManager.reset();
}


