// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class SSM : ModuleRules
{
	public SSM(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
		PrivatePCHHeaderFile = "SSM.h";

		PublicDependencyModuleNames.AddRange( new string[]
											  {
												  "Core", 
												  "CoreUObject", 
												  "Engine", 
												  "InputCore",
											  } );

		PublicIncludePaths.AddRange( new string[]
									 {
										 "SSM/Core",
										 "SSM/Pawn",
										 "SSM/Content",
									 });
	}
}
