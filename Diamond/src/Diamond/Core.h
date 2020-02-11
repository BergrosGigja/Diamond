#pragma once

#ifdef DI_PLATFORM_WINDOWS
	#ifdef DIAMOND_BUILD_DLL
		#define DIAMOND_API __declspec(dllexport)
	#else
		#define DIAMOND_API __declspec(dllimport)
	#endif
#else
	#error Diamond only supports Windows
#endif

#define BIT(x) (1 << x)