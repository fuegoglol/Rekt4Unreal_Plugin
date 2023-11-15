using System.IO;
using UnrealBuildTool;
 
public class RektCommon: ModuleRules {
    public RektCommon(ReadOnlyTargetRules Target) : base(Target) {
        Type = ModuleType.External;
        PublicIncludePaths.Add(Path.Combine(ModuleDirectory, "rekt"));
        PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "rekt", "rekt_common.lib"));
    }
}