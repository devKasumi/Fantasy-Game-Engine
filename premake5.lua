workspace "Fantasy"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release",
        "Dist" 
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Fantasy/vendor/GLFW/include"

include "Fantasy/vendor/GLFW"

project "Fantasy"
    location "Fantasy"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "ftpch.h"
    pchsource "Fantasy/src/ftpch.cpp"

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs 
    {
        "%{prj.name}/src",
        "%{prj.name}/vendor/spdlog/include",
        "%{IncludeDir.GLFW}"
    }

    links
    {
        "GLFW",
        "opengl32.lib",
        "dwmapi.lib"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "FT_PLATFORM_WINDOWS",
            "FT_BUILD_DLL",
            "_DEBUG",
            "_CONSOLE"
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        }

    filter "configurations:Debug"
        defines "FT_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "FT_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "FT_DIST"
        optimize "On"

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "Fantasy/vendor/spdlog/include",
        "Fantasy/src"
    }

    links
    {
        "Fantasy"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "FT_PLATFORM_WINDOWS",
        }

    filter "configurations:Debug"
        defines "FT_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "FT_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "FT_DIST"
        optimize "On"


    