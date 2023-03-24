// Copyright 2022 CQUnreal. All Rights Reserved.

#include "ConfigIniEditorModule.h"
#include "ISettingsModule.h"
#include "ISettingsSection.h"


IMPLEMENT_MODULE(FConfigIniEditorModule, ConfigIniEditor);

DEFINE_LOG_CATEGORY(LogConfigIniEditor)

#define LOCTEXT_NAMESPACE "FConfigIniEditorModule"

void FConfigIniEditorModule::StartupModule()
{
	RegisterSettings();
}

void FConfigIniEditorModule::ShutdownModule()
{
	UnregisterSettings();
}

void FConfigIniEditorModule::RegisterSettings()
{
	ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings");
	if (!SettingsModule)
		return;

	const auto Section = SettingsModule->RegisterSettings("Project", "Plugins", "OnlineSubsystemStudio",
		LOCTEXT("ConfigIniEditorSettingsName", "ConfigIni"),
		LOCTEXT("ConfigIniEditorSettingsDescription", "ConfigIni Editor Settings"),
		GetMutableDefault<UConfigIniEditorSettings>());

	Section->OnModified().BindRaw(this, &FConfigIniEditorModule::OnSettingsModified);

	UpdateSettingsSections();
}

void FConfigIniEditorModule::UnregisterSettings()
{
	ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings");
	if (!SettingsModule)
		return;

	SettingsModule->UnregisterSettings("Project", "Plugins", "OnlineSubsystemStudio");
}

bool FConfigIniEditorModule::OnSettingsModified()
{
	UpdateSettingsSections();

	return true;
}

void FConfigIniEditorModule::UpdateSettingsSections()
{
	ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings");
	if (!SettingsModule)
		return;

	UConfigIniEditorSettings* ConfigIniEditorSettings = GetMutableDefault<UConfigIniEditorSettings>();
	if (ConfigIniEditorSettings != nullptr)
	{
		TArray<FConfigIniSettings> TempConfigIniSettings = CurrentConfigIniSettings;
		for (const FConfigIniSettings& ConfigIniSettings : TempConfigIniSettings)
		{
			if (!ConfigIniEditorSettings->ConfigIniSettings.Contains(ConfigIniSettings))
			{
				SettingsModule->UnregisterSettings(ConfigIniSettings.ContainerName, ConfigIniSettings.CategoryName, ConfigIniSettings.SectionName);

				CurrentConfigIniSettings.Remove(ConfigIniSettings);
			}
		}

		for (const FConfigIniSettings& ConfigIniSettings : ConfigIniEditorSettings->ConfigIniSettings)
		{
			if (!CurrentConfigIniSettings.Contains(ConfigIniSettings))
			{
				if (IsValid(ConfigIniSettings.Class) && !ConfigIniSettings.ContainerName.IsNone() && !ConfigIniSettings.CategoryName.IsNone() && !ConfigIniSettings.SectionName.IsNone() && !ConfigIniSettings.DisplayName.IsEmpty())
				{
					SettingsModule->RegisterSettings(ConfigIniSettings.ContainerName, ConfigIniSettings.CategoryName, ConfigIniSettings.SectionName, ConfigIniSettings.DisplayName, ConfigIniSettings.Description, ConfigIniSettings.Class->GetDefaultObject());

					CurrentConfigIniSettings.Add(ConfigIniSettings);
				}				
			}
		}
	}
}

void FConfigIniEditorModule::ClearSettingsSections()
{
	ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings");
	if (!SettingsModule)
		return;

	for (const FConfigIniSettings& ConfigIniSettings : CurrentConfigIniSettings)
	{
		SettingsModule->UnregisterSettings(ConfigIniSettings.ContainerName, ConfigIniSettings.CategoryName, ConfigIniSettings.SectionName);
	}
	CurrentConfigIniSettings.Empty();
}

#undef LOCTEXT_NAMESPACE
