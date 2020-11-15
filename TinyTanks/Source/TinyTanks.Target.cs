// Developed by Sam Ganjian 2020.

using UnrealBuildTool;
using System.Collections.Generic;

public class TinyTanksTarget : TargetRules
{
	public TinyTanksTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V2;

		ExtraModuleNames.AddRange( new string[] { "TinyTanks" } );
	}
}
