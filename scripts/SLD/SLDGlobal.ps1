$script:StaticLibFlags = 
    "/c"    +
    "/MD"   +
    "/Z7"   +
    "/EHsc" +
    "/std:c++17"

$script:ObjDir = "build\debug\obj\"
$script:BinDir = "build\debug\bin\"
$script:LibDir = "build\debug\lib\"

$script:LibRoot = $PSScriptRoot + "..\..\"

$script:CLPath   = "cl.exe "
$script:LibPath  = "lib.exe "
$script:LinkPath = "link.exe "

$script:ObjPathFlag = "/Fo:" + $script:ObjDir 

function Create-CompileCommandLib {
	param (
		[string]$LibSource,
		[string]$LibInclude
	)
	
	$compileCommand = 
		$script:CLPath          +
		$LibSource              +
		$script:GStaticLibFlags +
		$script:ObjPathFlag

	return $compileCommand
}

function Create-LibCommand {
	param (
		[string]$LibName
		[string]$ObjList
	)

	$outString = $script:LibDir + $LibName

	$libCommand = 
		$script:LibPath +
		$outString      +
		$ObjList

	return $libCommand
}
