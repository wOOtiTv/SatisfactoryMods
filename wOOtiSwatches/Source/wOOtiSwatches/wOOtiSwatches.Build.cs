using UnrealBuildTool;
using System.IO;
using System;

public class wOOtiSwatches : ModuleRules
{
    public wOOtiSwatches(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        CppStandard = CppStandardVersion.Cpp20;
        PublicDependencyModuleNames.AddRange(new string[] {
            "Core", "CoreUObject", "Engine", "DeveloperSettings", "PhysicsCore",
            "InputCore", "GeometryCollectionEngine", "AnimGraphRuntime",
            "AssetRegistry", "NavigationSystem", "AIModule", "GameplayTasks",
            "SlateCore", "Slate", "UMG", "RenderCore", "CinematicCamera",
            "Foliage", "NetCore", "GameplayTags", "Json", "JsonUtilities",
            "DummyHeaders", "FactoryGame", "SML"
        });
        if (Target.Type == TargetRules.TargetType.Editor)
        {
            PublicDependencyModuleNames.AddRange(new string[] { "AnimGraph" });
        }
    }
}
