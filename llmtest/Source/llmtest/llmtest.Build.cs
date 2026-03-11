// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class llmtest : ModuleRules
{
	public llmtest(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
            "HTTP",
			"Json",
			"JsonUtilities",
            "Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"llmtest",
			"llmtest/Variant_Platforming",
			"llmtest/Variant_Platforming/Animation",
			"llmtest/Variant_Combat",
			"llmtest/Variant_Combat/AI",
			"llmtest/Variant_Combat/Animation",
			"llmtest/Variant_Combat/Gameplay",
			"llmtest/Variant_Combat/Interfaces",
			"llmtest/Variant_Combat/UI",
			"llmtest/Variant_SideScrolling",
			"llmtest/Variant_SideScrolling/AI",
			"llmtest/Variant_SideScrolling/Gameplay",
			"llmtest/Variant_SideScrolling/Interfaces",
			"llmtest/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
