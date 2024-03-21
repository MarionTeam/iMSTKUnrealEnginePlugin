// Copyright Epic Games, Inc. All Rights Reserved.

#include "Imstk.h"
#include "ImstkSettings.h"
#include "Developer/Settings/Public/ISettingsModule.h"

#define LOCTEXT_NAMESPACE "FImstkModule"

void FImstkModule::StartupModule()
{
	if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
	{
		SettingsModule->RegisterSettings("Project", "Plugins", "Imstk_Settings",
			LOCTEXT("iMSTKName", "iMSTK"), LOCTEXT("iMSTKSettingsDescriptions", "Configure iMSTK plugin."),
			GetMutableDefault<UImstkSettings>());
	}
}

void FImstkModule::ShutdownModule()
{

}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FImstkModule, Imstk)