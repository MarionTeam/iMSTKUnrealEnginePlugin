// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Core/Public/HAL/Runnable.h"
#include "imstkDeviceManager.h"

class FRunnableThread;

/** \file HapticsThread.h
 *  \brief Separate thread for haptic devices 
 *  \details
 */
class FHapticsThread : public FRunnable
{
	
public:	
	// Sets default values for this actor's properties
	FHapticsThread(std::shared_ptr<imstk::DeviceManager> HapticManager, UWorld* WorldReference, float TimeInterval);

	bool bStopThread;

	virtual bool Init();

	virtual uint32 Run();

	virtual void Stop();

protected:
	std::shared_ptr<imstk::DeviceManager> HapticManager;

	UPROPERTY()
		UWorld* World;

	float TimeInterval = 0;
};
