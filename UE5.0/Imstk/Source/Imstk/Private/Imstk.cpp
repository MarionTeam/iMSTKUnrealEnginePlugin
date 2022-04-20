// Copyright Epic Games, Inc. All Rights Reserved.

#include "Imstk.h"
//#include "Modules/ModuleManager.h"
//#include "Interfaces/IPluginManager.h"
//#include "HAL/FileManagerGeneric.h"

#define LOCTEXT_NAMESPACE "FImstkModule"

void FImstkModule::StartupModule()
{
	//// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	//FString BaseDir = IPluginManager::Get().FindPlugin("Imstk")->GetBaseDir();
	//FString ImstkLibPath = FPaths::Combine(*BaseDir, TEXT("Binaries/ThirdParty/Win64/"));

	//TArray<FString> Dlls;
	//IFileManager::Get().FindFiles(Dlls, *ImstkLibPath, TEXT("dll"));

	//for (FString Dll : Dlls) {
	//	ImstkDllHandles.Add(FPlatformProcess::GetDllHandle(*(ImstkLibPath + Dll)));
	//}

}

void FImstkModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.

	/*for (void* Handle : ImstkDllHandles) {
		FPlatformProcess::FreeDllHandle(Handle);
		Handle = nullptr;
	}*/
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FImstkModule, Imstk)