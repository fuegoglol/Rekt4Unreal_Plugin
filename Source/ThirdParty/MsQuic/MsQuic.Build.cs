using System.IO;
using UnrealBuildTool;
 
public class MsQuic: ModuleRules {
    public MsQuic(ReadOnlyTargetRules Target) : base(Target)
    {
        CppStandard = CppStandardVersion.Cpp20;
        Type = ModuleType.External;
        PublicIncludePaths.Add(Path.Combine(ModuleDirectory, "msquic", "src"));
    }
}