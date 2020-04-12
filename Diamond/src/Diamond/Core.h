#pragma once

#ifdef DI_PLATFORM_WINDOWS
#if DI_DYNAMIC_LINK
	#ifdef DIAMOND_BUILD_DLL
		#define DIAMOND_API __declspec(dllexport)
	#else
		#define DIAMOND_API __declspec(dllimport)
	#endif
#else
	#define DIAMOND_API
#endif
#else
	#error Diamond only supports Windows
#endif

#ifdef  DI_CORE_ASSERT
	#define DI_ASSERT(x, ...) { if(!(x)) { DI_ERROR("Assertion Failed: {0}", __VA_ARGS__);__debugbreak(); } }
	#define DI_CORE_ASSERT(x, ...) { if(!(x)) { DI_ERROR("Assertion Failed: {0}", __VA_ARGS__);__debugbreak(); } }
#else
	#define DI_ASSERT(x, ...)
	#define DI_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define DI_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)