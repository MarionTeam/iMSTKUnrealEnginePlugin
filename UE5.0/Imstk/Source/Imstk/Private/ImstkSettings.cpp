// Fill out your copyright notice in the Description page of Project Settings.


#include "ImstkSettings.h"

UImstkSettings::UImstkSettings(const FObjectInitializer& ObjectInitializer) {

}

bool UImstkSettings::IsDebugging() {
	return GetMutableDefault<UImstkSettings>()->bDebuggingActive;
}

bool UImstkSettings::IsLoggerActive() {
	return GetMutableDefault<UImstkSettings>()->bLoggerActive;
}

bool UImstkSettings::IsUseRealtime() {
	return GetMutableDefault<UImstkSettings>()->bUseRealtime;
}

bool UImstkSettings::IsWritingTaskGraph() {
	return GetMutableDefault<UImstkSettings>()->bWriteTaskGraph;
}