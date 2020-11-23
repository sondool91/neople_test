// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class SSM : ModuleRules
{
	public SSM(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore" });
	}
}
