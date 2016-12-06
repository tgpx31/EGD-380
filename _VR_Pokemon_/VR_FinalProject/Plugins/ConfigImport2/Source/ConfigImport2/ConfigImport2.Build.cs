// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class ConfigImport2 : ModuleRules
{
	public ConfigImport2(TargetInfo Target)
	{
		
		PublicIncludePaths.AddRange(
			new string[] {
				"ConfigImport2/Public"
				// ... add public include paths required here ...
			}
			);
				
		
		PrivateIncludePaths.AddRange(
			new string[] {
				"ConfigImport2/Private",
				// ... add other private include paths required here ...
			}
			);
			
		
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
                "Projects",
                "InputCore",
                "UnrealEd",
                "LevelEditor",
                "PropertyEditor",
                "CoreUObject",
                "Engine",
                "Slate",
                "SlateCore",
				// ... add other public dependencies that you statically link with here ...
			}
			);
			
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				
				// ... add private dependencies that you statically link with here ...	
			}
			);
		
		
		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				// ... add any modules that your module loads dynamically here ...
			}
			);
	}
}
