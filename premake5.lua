workspace "Diamond"
	architecture "x64"
	startproject "Sandbox"

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
IncludeDir["Glad"] = "Diamond/vendor/Glad/include"
IncludeDir["ImGui"] = "Diamond/vendor/imgui"
IncludeDir["glm"] = "Diamond/vendor/glm"

group "Dependencies"
	include "Diamond/vendor/GLFW"
	include "Diamond/vendor/Glad"
	include "Diamond/vendor/imgui"
group ""

project "Diamond"
	location "Diamond"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "dipch.h"
	pchsource "Diamond/src/dipch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl"
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}"
	}

	links
	{
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"DI_PLATFORM_WINDOWS",
			"DIAMOND_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

	filter "configurations:Debug"
		defines "DI_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "DI_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "DI_DIST"
		runtime "Release"
		optimize "on"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

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
		"Diamond/src",
		"%{IncludeDir.glm}"
	}

	links
	{
		"Diamond"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"DI_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "DI_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "DI_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "DI_DIST"
		runtime "Release"
		optimize "on"