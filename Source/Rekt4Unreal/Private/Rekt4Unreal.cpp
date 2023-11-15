// Copyright Epic Games, Inc. All Rights Reserved.

#include "Rekt4Unreal.h"

#include "ISettingsModule.h"
#include "Settings/RPSettings.h"

#define LOCTEXT_NAMESPACE "FRekt4UnrealModule"

void FRekt4UnrealModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	if (ISettingsModule* SettingModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
	{
		SettingModule->RegisterSettings("Project", "Plugins", "Settings",
			LOCTEXT("RuntimeSettingsName", "Rekt Protocol Toolbox Settings"),
			LOCTEXT("RuntimeSettingsDescription", "Configure the plugins"),
			GetMutableDefault<URPSettings>()
		);
	}
}

void FRekt4UnrealModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FRekt4UnrealModule, Rekt4Unreal)