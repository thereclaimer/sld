. "$PSScriptRoot\SLDCompiler.ps1"
. "$PSScriptRoot\SLDLib.ps1"

function Invoke-MemoryLibBuild {

    $includes = 
        "memory\include",
        "memory\src"

    $source = "memory\src\sld-memory.cpp"
    $obj    = "sld-memory.obj" 

    Invoke-CompileStaticLib -SourceList $source -IncludeList $includes
    Invoke-Lib -LibName "SLD.Memory.lib" -ObjList $obj
}

Export-ModuleMember -Function Invoke-MemoryLibBuild
