// Copyright Epic Games, Inc. All Rights Reserved.

using System.IO;
using UnrealBuildTool;

public class WTF : ModuleRules
{
    public WTF(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });

        PublicIncludePaths.AddRange(new string[] {
            Path.Combine(ModuleDirectory, "Projectile"),
            Path.Combine(ModuleDirectory, "Characters"),
            Path.Combine(ModuleDirectory, "Gravity"),
        });
    }
}
