. "$PSScriptRoot\SLDGlobal.ps1"

function Get-LibFlags {
	param(
		[string]   $LibName,
		[string[]] $ObjList
	)

	$DirLib = Get-DirLib
	$DirObj = Get-DirObj

	$FlagLibOut = "/OUT:" + $DirLib + "\" + $LibName

	$SourceStringDelimiter = $DirObj + " "
	$SourceString          = $ObjList -join $SourceStringDelimiter

	$LibFlags =
		$FlagLibOut +
		$SourceString

	return $LibFlags
}

function Get-LibCommand {
	param(
		[string]   $LibName,
		[string[]] $ObjList
	)

	$LibFlags = Get-LibFlags -LibName $LibName -ObjList $ObjList

	$LibCommand = 
		"lib.exe " +
		$LibFlags

	return $LibCommand
}

function Invoke-Lib {
	param(
		[string]   $LibName,
		[string[]] $ObjList
	)

	Create-DirLib

	$LibCommand = Get-LibCommand -LibName $LibName -ObjList $ObjList

	Invoke-Expression $LibCommand
}
