#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/fmt/ostr.h"

namespace Fantasy {
	class FANTASY_API Log
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
#define FT_CORE_TRACE(...)    ::Fantasy::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define FT_CORE_INFO(...)	  ::Fantasy::Log::GetCoreLogger()->info(__VA_ARGS__)
#define FT_CORE_WARN(...)	  ::Fantasy::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define FT_CORE_ERROR(...)	  ::Fantasy::Log::GetCoreLogger()->error(__VA_ARGS__)
#define FT_CORE_FATAL(...)    ::Fantasy::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define FT_TRACE(...)		  ::Fantasy::Log::GetClientLogger()->trace(__VA_ARGS__)
#define FT_INFO(...)		  ::Fantasy::Log::GetClientLogger()->info(__VA_ARGS__)
#define FT_WARN(...)		  ::Fantasy::Log::GetClientLogger()->warn(__VA_ARGS__)
#define FT_ERROR(...)		  ::Fantasy::Log::GetClientLogger()->error(__VA_ARGS__)
#define FT_FATAL(...)		  ::Fantasy::Log::GetClientLogger()->fatal(__VA_ARGS__)


