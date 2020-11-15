// Developed by Sam Ganjian 2020.

using UnrealBuildTool;
using System.Collections.Generic;

public class TinyTanksEditorTarget : TargetRules
{
	public TinyTanksEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V2;

		ExtraModuleNames.AddRange( new string[] { "TinyTanks" } );
	}
}
