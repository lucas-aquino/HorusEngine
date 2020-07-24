#pragma once

#include <memory>
#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Horus
{
	class HORUS_API Log
	{
	public:

		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return sCoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return sClientLogger; }
		
	private:
		static std::shared_ptr<spdlog::logger> sCoreLogger;
		static std::shared_ptr<spdlog::logger> sClientLogger;
	};

}


//Define Core Log Macros
#define HOR_CORE_TRACE(...) ::Horus::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define HOR_CORE_INFO(...)  ::Horus::Log::GetCoreLogger()->info(__VA_ARGS__)
#define HOR_CORE_WARN(...)  ::Horus::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define HOR_CORE_ERROR(...) ::Horus::Log::GetCoreLogger()->error(__VA_ARGS__)

//Define Client Log Macros
#define HOR_TRACE(...)		::Horus::Log::GetClientLogger()->trace(__VA_ARGS__)
#define HOR_INFO(...)		::Horus::Log::GetClientLogger()->info(__VA_ARGS__)
#define HOR_WARN(...)		::Horus::Log::GetClientLogger()->warn(__VA_ARGS__)
#define HOR_ERROR(...)		::Horus::Log::GetClientLogger()->error(__VA_ARGS__)

