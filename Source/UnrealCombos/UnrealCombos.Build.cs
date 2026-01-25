// Scientific Ways

using UnrealBuildTool;

public class UnrealCombos : ModuleRules
{
	public UnrealCombos(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicIncludePaths.AddRange(new string[]
		{
			
		});

		PublicDependencyModuleNames.AddRange(new string[]
		{
			"Core",
			"EngineSettings",

			"GameplayAbilities",
			"GameplayTags",
			"GameplayTasks",
			"Networking",

			"UnrealCommons",
		});

		PrivateDependencyModuleNames.AddRange(new string[]
		{
			"Engine",
			"CoreUObject",
		});
	}
}
