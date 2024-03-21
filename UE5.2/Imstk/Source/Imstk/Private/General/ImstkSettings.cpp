// Fill out your copyright notice in the Description page of Project Settings.


#include "ImstkSettings.h"

UImstkSettings::UImstkSettings(const FObjectInitializer& ObjectInitializer) {
	LoadConfig();
}

bool UImstkSettings::IsDebugging() {
	return GetMutableDefault<UImstkSettings>()->bDebuggingActive;
}

bool UImstkSettings::IsLoggerActive() {
	return GetMutableDefault<UImstkSettings>()->bLoggerActive;
}

bool UImstkSettings::IsUseRealtimeRBD() {
	return GetMutableDefault<UImstkSettings>()->bRBDUseRealtime;
}

bool UImstkSettings::IsUseRealtimePBD() {
	return GetMutableDefault<UImstkSettings>()->bPBDUseRealtime;
}

bool UImstkSettings::IsWritingTaskGraph() {
	return GetMutableDefault<UImstkSettings>()->bWriteTaskGraph;
}

bool UImstkSettings::IsUseAsyncPhysics() {
	return GetMutableDefault<UImstkSettings>()->bUseAsyncPhysics;
}

bool UImstkSettings::IsUseSubstepping() {
	return GetMutableDefault<UImstkSettings>()->bUseSubstepping;
}