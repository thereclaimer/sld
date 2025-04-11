. "$PSScriptRoot\SLDGlobal.ps1"

function Get-CompileStaticLibFlags {
	param(
		[string[]] $SourceList,
		[string[]] $IncludeList
	)

	# source in
	$SourceListString = $SourceList -join " "

	#obj out
	$ObjPathFlag = "/Fo:" + Get-DirObj

	#includes
	$IncludeListString = $IncludeList -join "/I"

	#flags
	$StaticLibFlags = 
		$SourceListString  +
		$IncludeListString +
		$ObjPathFlag       +
		"/c"               +
		"/MD"              +
		"/Z7"              +
		"/EHsc"            +
		"/std:c++17"

	return $StaticLibFlags
}

function Get-CompileStaticLibCommand {
	param(
		[string[]] $SourceList,
		[string[]] $IncludeList
	)

	# flags
	$CompilerFlags = Get-CompileStaticLibFlags -SourceList $SourceList -IncludeList $IncludeList

	# command
	$CompilerCommand =
		"cl.exe "         +
		$CompilerFlags
	
	return $CompilerCommand 
}

function Invoke-CompileStaticLib {
	param (
		[string[]] $SourceList,
		[string[]] $IncludeList
	)

	Create-DirObj

	$CompileCommand = Get-CompileStaticLibCommand -SourceList $SourceList -IncludeList $IncludeList

	Invoke-Expression $CompileCommand 
}
