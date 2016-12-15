using UnrealBuildTool;

public class VRFirstPerson : ModuleRules
{
	public VRFirstPerson(TargetInfo Target)
	{
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore" });

        /* VR Required Modules */ 
		PrivateDependencyModuleNames.AddRange(new string[] { "HeadMountedDisplay" });

        PrivateIncludePaths.Add("../Pokemon_C++/Type.h");
    }
}
