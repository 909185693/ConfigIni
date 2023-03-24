// Copyright 2022 CQUnreal. All Rights Reserved.

using UnrealBuildTool;
using System.IO;

public class ConfigIniEditor : ModuleRules
{
    public ConfigIniEditor(ReadOnlyTargetRules Target) : base(Target)
    {
#if UE_5_2_OR_LATER
        IWYUSupport = IWYUSupport.None;
#else
        bEnforceIWYU = false;
#endif

        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicIncludePaths.AddRange(
            new string[]
            {

            }
        );

        PrivateIncludePathModuleNames.AddRange(
            new string[]
            {
                "Kismet",
                "MainFrame",
                "Slate",
                "SlateCore",
            }
        );

        PrivateDependencyModuleNames.AddRange(
            new string[]
            {
                "Core",
                "CoreUObject",
                "Engine",
                "UnrealEd",
                "EditorStyle",
                "ApplicationCore",
                "Projects",
                "InputCore",
                "UMG",
                "UMGEditor",
                "BlueprintGraph",
                "Slate",
                "SlateCore",
                "ToolMenus"
            }
        );

        DynamicallyLoadedModuleNames.AddRange(
            new string[]
            {
                "Kismet",
                "MainFrame",
                "AnimationBlueprintEditor",
            }
        );
    }
}