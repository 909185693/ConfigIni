// Copyright 2022 CQUnreal. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ConfigIniEditorSettings.generated.h"


USTRUCT(BlueprintType)
struct FConfigIniSettings
{
	GENERATED_USTRUCT_BODY()

	FConfigIniSettings()
		: ClassPath(TEXT(""))
		, ContainerName(TEXT("Project"))
		, CategoryName(TEXT("Game"))
		, SectionName(TEXT(""))
	{

	}

    UPROPERTY(EditAnywhere, Category = ConfigIniSection)
	FSoftClassPath ClassPath;

    UPROPERTY(EditAnywhere, Category = ConfigIniSection)
    FName ContainerName;

	UPROPERTY(EditAnywhere, Category = ConfigIniSection)
	FName CategoryName;

	UPROPERTY(EditAnywhere, Category = ConfigIniSection)
	FName SectionName;

	UPROPERTY(EditAnywhere, Category = ConfigIniSection)
    FText DisplayName;

	UPROPERTY(EditAnywhere, Category = ConfigIniSection)
	FText Description;

	friend bool operator==(const FConfigIniSettings& A, const FConfigIniSettings& B)
	{
		return A.ClassPath == B.ClassPath &&
			A.ContainerName == B.ContainerName &&
			A.CategoryName == B.CategoryName &&
			A.SectionName == B.SectionName;
	}

	friend int32 GetTypeHash(const FConfigIniSettings& ConfigIniSettings)
	{
		int32 Hash = 0;
		Hash = HashCombine(Hash, GetTypeHash(ConfigIniSettings.ClassPath));
		Hash = HashCombine(Hash, GetTypeHash(ConfigIniSettings.ContainerName));
		Hash = HashCombine(Hash, GetTypeHash(ConfigIniSettings.CategoryName));
		Hash = HashCombine(Hash, GetTypeHash(ConfigIniSettings.SectionName));
		//Hash = HashCombine(Hash, GetTypeHash(ConfigIniSettings.Name));
		//Hash = HashCombine(Hash, GetTypeHash(ConfigIniSettings.Description));
		return Hash;
	}
};

UCLASS(Config=Editor, DefaultConfig)
class CONFIGINIEDITOR_API UConfigIniEditorSettings : public UObject
{
    GENERATED_BODY()

public:
	UConfigIniEditorSettings(const FObjectInitializer& ObjectInitializer);

    UPROPERTY(Config, EditAnywhere, Category = Runtime)
    TArray<FConfigIniSettings> ConfigIniSettings;
};
