workspace "Diamond"
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
IncludeDir["GLFW"] = "Diamond/vendor/GLFW/include"

include "Diamond/vendor/GLFW"

project "Diamond"
	location "Diamond"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "dipch.h"
	pchsource "Diamond/src/dipch.cpp"

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
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"DI_PLATFORM_WINDOWS",
			"DIAMOND_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "DI_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "DI_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "DI_DIST"
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
		"Diamond/vendor/spdlog/include",
		"Diamond/src"
	}

	links
	{
		"Diamond"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"DI_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "DI_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "DI_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "DI_DIST"
		optimize "On"