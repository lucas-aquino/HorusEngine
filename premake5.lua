workspace "HorusEngine"
	architecture "x64"
	
	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "HorusEngine"
	
	location "HorusEngine"
	kind "SharedLib"
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
		"HorusEngine/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"HOR_PLATFORM_WINDOWS",
			"HOR_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "HOR_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "HOR_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "HOR_DIST"
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
		"HorusEngine/vendor/spdlog/include",
		"HorusEngine/src"
	}
	
	links
	{
		"HorusEngine"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"HOR_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "HOR_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "HOR_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "HOR_DIST"
		optimize "On"
