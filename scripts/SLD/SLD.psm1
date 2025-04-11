. "$PSScriptRoot\SLDCompiler.ps1"
. "$PSScriptRoot\SLDLib.ps1"

function Invoke-MemoryLibBuild {

    $Includes = "memory\include", "memory\src"
    $Source   = "memory\src\sld-memory.cpp"
    $Obj      = "sld-memory.obj" 
    $LibName  = "SLD.Memory.lib"

    Invoke-CompileStaticLib -SourceList $Source  -IncludeList $Includes
    Invoke-Lib              -LibName    $LibName -ObjList     $Obj
}

Export-ModuleMember -Function Invoke-MemoryLibBuild
