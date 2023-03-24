// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "ConfigIniBlueprintLibrary.h"
#include "CoreGlobals.h"
#include "Misc/ConfigCacheIni.h"

const FString& operator*(const EConfigIniFileNames& IniConfig)
{
	static FString DefaultIni = TEXT("");
	switch (IniConfig)
	{
	case EConfigIniFileNames::GEngineIni:
		return GEngineIni;
	case EConfigIniFileNames::GGameIni:
		return GGameIni;
	case EConfigIniFileNames::GGameUserSettingsIni:
		return GGameUserSettingsIni;
	case EConfigIniFileNames::GEditorIni:
		return GEditorIni;
	case EConfigIniFileNames::GEditorKeyBindingsIni:
		return GEditorKeyBindingsIni;
	case EConfigIniFileNames::GEditorLayoutIni:
		return GEditorLayoutIni;
	case EConfigIniFileNames::GEditorSettingsIni:
		return GEditorSettingsIni;
	case EConfigIniFileNames::GEditorPerProjectIni:
		return GEditorPerProjectIni;
	case EConfigIniFileNames::GCompatIni:
		return GCompatIni;
	case EConfigIniFileNames::GLightmassIni:
		return GLightmassIni;
	case EConfigIniFileNames::GScalabilityIni:
		return GScalabilityIni;
	case EConfigIniFileNames::GHardwareIni:
		return GHardwareIni;
	case EConfigIniFileNames::GInputIni:
		return GInputIni;
	case EConfigIniFileNames::GRuntimeOptionsIni:
		return GRuntimeOptionsIni;
	#if ENGINE_MAJOR_VERSION > 4 || ENGINE_MINOR_VERSION > 24
	case EConfigIniFileNames::GInstallBundleIni:
		return GInstallBundleIni;
	case EConfigIniFileNames::GDeviceProfilesIni:
		return GDeviceProfilesIni;
	#endif
	default:
		return DefaultIni;
	}
}

void UConfigIni::GetString(EConfigIniFileNames ConfigFile, const FString& SectionName, const FString& PropertyName, FString& StringValue, bool& bWasFound)
{
	bWasFound = GConfig->GetString(*SectionName, *PropertyName, StringValue, *ConfigFile);
}

void UConfigIni::GetText(EConfigIniFileNames ConfigFile, const FString& SectionName, const FString& PropertyName, FText& TextValue, bool& bWasFound)
{
	bWasFound = GConfig->GetText(*SectionName, *PropertyName, TextValue, *ConfigFile);
}

void UConfigIni::GetBool(EConfigIniFileNames ConfigFile, const FString& SectionName, const FString& PropertyName, bool& BoolValue, bool& bWasFound)
{
	bWasFound = GConfig->GetBool(*SectionName, *PropertyName, BoolValue, *ConfigFile);
}

void UConfigIni::GetInt(EConfigIniFileNames ConfigFile, const FString& SectionName, const FString& PropertyName, int32& IntValue, bool& bWasFound)
{
	bWasFound = GConfig->GetInt(*SectionName, *PropertyName, IntValue, *ConfigFile);
}

void UConfigIni::GetFloat(EConfigIniFileNames ConfigFile, const FString& SectionName, const FString& PropertyName, float& FloatValue, bool& bWasFound)
{
	bWasFound = GConfig->GetFloat(*SectionName, *PropertyName, FloatValue, *ConfigFile);
}


void UConfigIni::GetArray(EConfigIniFileNames ConfigFile, const FString& SectionName, const FString& PropertyName, TArray<FString>& ArrayValue, bool& bWasFound)
{
	bWasFound = GConfig->GetArray(*SectionName, *PropertyName, ArrayValue, *ConfigFile) > 0;
}

void UConfigIni::GetColor(EConfigIniFileNames ConfigFile, const FString& SectionName, const FString& PropertyName, FColor& ColorValue, bool& bWasFound)
{
	bWasFound = GConfig->GetColor(*SectionName, *PropertyName, ColorValue, *ConfigFile);
}

void UConfigIni::GetVector2D(EConfigIniFileNames ConfigFile, const FString& SectionName, const FString& PropertyName, FVector2D& VectorValue, bool& bWasFound)
{
	bWasFound = GConfig->GetVector2D(*SectionName, *PropertyName, VectorValue, *ConfigFile);
}

void UConfigIni::GetVector(EConfigIniFileNames ConfigFile, const FString& SectionName, const FString& PropertyName, FVector& VectorValue, bool& bWasFound)
{
	bWasFound = GConfig->GetVector(*SectionName, *PropertyName, VectorValue, *ConfigFile);
}

void UConfigIni::GetVector4(EConfigIniFileNames ConfigFile, const FString& SectionName, const FString& PropertyName, FVector4& VectorValue, bool& bWasFound)
{
	bWasFound = GConfig->GetVector4(*SectionName, *PropertyName, VectorValue, *ConfigFile);
}

void UConfigIni::GetRotator(EConfigIniFileNames ConfigFile, const FString& SectionName, const FString& PropertyName, FRotator& RotatorValue, bool& bWasFound)
{
	bWasFound = GConfig->GetRotator(*SectionName, *PropertyName, RotatorValue, *ConfigFile);
}


////////////////////////////////////////////////////////////////
// GConfig Setters

void UConfigIni::SetString(EConfigIniFileNames ConfigFile, const FString& SectionName, const FString& PropertyName, const FString& StringValue)
{
	GConfig->SetString(*SectionName, *PropertyName, *StringValue, *ConfigFile);
}

void UConfigIni::SetText(EConfigIniFileNames ConfigFile, const FString& SectionName, const FString& PropertyName, const FText TextValue)
{
	GConfig->SetText(*SectionName, *PropertyName, TextValue, *ConfigFile);
}

void UConfigIni::SetBool(EConfigIniFileNames ConfigFile, const FString& SectionName, const FString& PropertyName, const bool BoolValue)
{
	GConfig->SetBool(*SectionName, *PropertyName, BoolValue, *ConfigFile);
}

void UConfigIni::SetInt(EConfigIniFileNames ConfigFile, const FString& SectionName, const FString& PropertyName, const int32 IntValue)
{
	GConfig->SetInt(*SectionName, *PropertyName, IntValue, *ConfigFile);
}

void UConfigIni::SetFloat(EConfigIniFileNames ConfigFile, const FString& SectionName, const FString& PropertyName, const float FloatValue)
{
	GConfig->SetFloat(*SectionName, *PropertyName, FloatValue, *ConfigFile);
}

void UConfigIni::SetArray(EConfigIniFileNames ConfigFile, const FString& SectionName, const FString& PropertyName, const TArray<FString>& ArrayValue)
{
	GConfig->SetArray(*SectionName, *PropertyName, ArrayValue, *ConfigFile);
}

void UConfigIni::SetColor(EConfigIniFileNames ConfigFile, const FString& SectionName, const FString& PropertyName, const FColor& ColorValue)
{
	GConfig->SetColor(*SectionName, *PropertyName, ColorValue, *ConfigFile);
}

void UConfigIni::SetVector2D(EConfigIniFileNames ConfigFile, const FString& SectionName, const FString& PropertyName, const FVector2D& Vector2DValue)
{
	GConfig->SetVector2D(*SectionName, *PropertyName, Vector2DValue, *ConfigFile);
}

void UConfigIni::SetVector(EConfigIniFileNames ConfigFile, const FString& SectionName, const FString& PropertyName, const FVector& VectorValue)
{
	GConfig->SetVector(*SectionName, *PropertyName, VectorValue, *ConfigFile);
}

void UConfigIni::SetVector4(EConfigIniFileNames ConfigFile, const FString& SectionName, const FString& PropertyName, const FVector4& Vector4Value)
{
	GConfig->SetVector4(*SectionName, *PropertyName, Vector4Value, *ConfigFile);
}

void UConfigIni::SetRotator(EConfigIniFileNames ConfigFile, const FString& SectionName, const FString& PropertyName, const FRotator& RotatorValue)
{
	GConfig->SetRotator(*SectionName, *PropertyName, RotatorValue, *ConfigFile);
}


////////////////////////////////////////////////////////////////
// GConfig Misc

void UConfigIni::Flush(EConfigIniFileNames ConfigFile, const bool bRefreshInConfigSystem)
{
	GConfig->Flush(bRefreshInConfigSystem, *ConfigFile);
}