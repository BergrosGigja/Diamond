#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"

namespace Diamond 
{
	class DIAMOND_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Core log macros
#define DI_CORE_TRACE(...)	::Diamond::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define DI_CORE_INFO(...)	::Diamond::Log::GetCoreLogger()->info(__VA_ARGS__)
#define DI_CORE_WARN(...)	::Diamond::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define DI_CORE_ERROR(...)	::Diamond::Log::GetCoreLogger()->error(__VA_ARGS__)
#define DI_CORE_FATAL(...)	::Diamond::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define DI_TRACE(...)	    ::Diamond::Log::GetClientLogger()->trace(__VA_ARGS__)
#define DI_INFO(...)	    ::Diamond::Log::GetClientLogger()->info(__VA_ARGS__)
#define DI_WARN(...)	    ::Diamond::Log::GetClientLogger()->warn(__VA_ARGS__)
#define DI_ERROR(...)	    ::Diamond::Log::GetClientLogger()->error(__VA_ARGS__)
#define DI_FATAL(...)	    ::Diamond::Log::GetClientLogger()->fatal(__VA_ARGS__)
