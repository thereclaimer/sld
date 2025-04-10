$script:GStaticLibFlags = 
    "/c "    +
    "/MD "   +
    "/Z7 "   +
    "/EHsc " +
    "/std:c++17 "

function Create-CompileCommandsStaticLib {
	param (
		[string]$LibSource,
		[string]$LibInclude
	)

}
