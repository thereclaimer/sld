$script:GStaticLibFlags = 
    "/c "    +
    "/MD "   +
    "/Z7 "   +
    "/EHsc " +
    "/std:c++17 "

$script:GLibRoot = $PSScriptRoot + "..\..\"

function Create-CompileCommandsStaticLib {
	param (
		[string]$LibName
		[string]$LibSource,
		[string]$LibInclude
	)
	
	$directory = $script:GLibRoot + $LibName
	$arguments = 
		"cl.exe "               + 
		$LibSource              + " "
		$script:GStaticLibFlags +
	$source = "" 
}
