using UnrealBuildTool;

public class wOOtiSwatches : ModuleRules
{
    public wOOtiSwatches(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        CppStandard = CppStandardVersion.Cpp20;
        PublicDependencyModuleNames.AddRange(new[]
        {
            "Core", "CoreUObject", "Engine", "Json", "JsonUtilities",
            "FactoryGame", "SML"
        });
    }
}
