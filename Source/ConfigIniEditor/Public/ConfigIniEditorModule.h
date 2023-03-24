// Copyright 2022 CQUnreal. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ConfigIniEditorSettings.h"
#include "Modules/ModuleInterface.h"


class FConfigIniEditorModule : public IModuleInterface
{
	// IModuleInterface

	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

protected:
	void RegisterSettings();
	void UnregisterSettings();

private:
	bool OnSettingsModified();
	void UpdateSettingsSections();
	void ClearSettingsSections();

private:
	TArray<FConfigIniSettings> CurrentConfigIniSettings;
};

CONFIGINIEDITOR_API DECLARE_LOG_CATEGORY_EXTERN(LogConfigIniEditor, Log, All);
