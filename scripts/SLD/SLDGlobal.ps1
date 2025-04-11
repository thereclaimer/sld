function Get-DirObj {
	return "build\debug\obj\"
}

function Get-DirBin {
	return "build\debug\bin\"
}

function Get-DirLib {
	return "build\debug\lib\"
}

function Create-DirObj {

	$DirObj = Get-DirObj

	if (!(Test-Path -Path $DirObj) { New-Item -ItemType Directory -Path $DirObj}
}

function Create-DirBin {

	$DirBin = Get-DirBin

	if (!(Test-Path -Path $DirBin)) { New-Item -ItemType Directory -Path $DirBin}
}

function Create-DirLib {

	$DirLib = Get-DirLib

	if (!(Test-Path -Path $DirLib)) { New-Item -ItemType Directory -Path $DirLib}
}

function Get-CompilerOutFlag {

	$dir  = Get-DirStringObj
	$flag = "/Fo:" + $dir

	return $flag
}
