// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

/** \file ImstkSettings.h
 *  \brief Provides settings in editor for imstk
 *  \details Has settings for imstk logging and debugging messages in unreal
 */
#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "ImstkSettings.generated.h"

// Settings for iMSTK
UCLASS(config = Engine, defaultconfig)
class IMSTK_API UImstkSettings : public UObject
{
	GENERATED_BODY()

public:
	UImstkSettings(const FObjectInitializer& ObjectInitializer);

	UPROPERTY(config, EditAnywhere, Category = "General", meta = (Tooltip = "Experimental!"))
		bool bUseAsyncPhysics = false;

	UPROPERTY(config, EditAnywhere, Category = "General", meta = (Tooltip = "Experimental!"))
		bool bUseSubstepping = false;

	UPROPERTY(config, EditAnywhere, Category = "General", meta = (Tooltip = "If true, rbd models will update their timesteps to line up with Unreal."))
		bool bRBDUseRealtime = false;

	UPROPERTY(config, EditAnywhere, Category = "General", meta = (Tooltip = "If true, pbd models will update their timesteps to line up with Unreal."))
		bool bPBDUseRealtime = false;

	UPROPERTY(config, EditAnywhere, Category = "Debugging", meta = (Tooltip = "If true, the iMSTK logger will be written to."))
		bool bLoggerActive = false;

	UPROPERTY(config, EditAnywhere, Category = "Debugging", meta = (Tooltip = "If true, debugging information will be provided in Unreal."))
		bool bDebuggingActive = false;

	UPROPERTY(config, EditAnywhere, Category = "Debugging", meta = (Tooltip = "If true, generates a task graph of the imstk scene."))
		bool bWriteTaskGraph = false;
public:
	UFUNCTION(BlueprintCallable, Category = "iMSTK|Settings")
		static bool IsDebugging();
	UFUNCTION(BlueprintCallable, Category = "iMSTK|Settings")
		static bool IsLoggerActive();
	UFUNCTION(BlueprintCallable, Category = "iMSTK|Settings")
		static bool IsUseRealtimeRBD();
	UFUNCTION(BlueprintCallable, Category = "iMSTK|Settings")
		static bool IsUseRealtimePBD();
	UFUNCTION(BlueprintCallable, Category = "iMSTK|Settings")
		static bool IsWritingTaskGraph();
	UFUNCTION(BlueprintCallable, Category = "iMSTK|Settings")
		static bool IsUseAsyncPhysics();
	UFUNCTION(BlueprintCallable, Category = "iMSTK|Settings")
		static bool IsUseSubstepping();
};
