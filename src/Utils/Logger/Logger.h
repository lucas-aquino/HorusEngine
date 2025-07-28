#pragma once

#include <memory>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>


namespace Horus
{
	class Logger
	{
	public: 
		void static Init();

		static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}


//Para Core
#define HE_CORE_TRACE(...)    ::Horus::Logger::GetCoreLogger()->trace(__VA_ARGS__)
#define HE_CORE_INFO(...)     ::Horus::Logger::GetCoreLogger()->info(__VA_ARGS__)
#define HE_CORE_WARN(...)     ::Horus::Logger::GetCoreLogger()->warn(__VA_ARGS__)
#define HE_CORE_ERROR(...)    ::Horus::Logger::GetCoreLogger()->error(__VA_ARGS__)
#define HE_CORE_FATAL(...)    ::Horus::Logger::GetCoreLogger()->fatal(__VA_ARGS__)


//Para Cliente
#define HE_TRACE(...)         ::Horus::Logger::GetClientLogger()->trace(__VA_ARGS__)
#define HE_INFO(...)          ::Horus::Logger::GetClientLogger()->info(__VA_ARGS__)
#define HE_WARN(...)          ::Horus::Logger::GetClientLogger()->warn(__VA_ARGS__)
#define HE_ERROR(...)         ::Horus::Logger::GetClientLogger()->error(__VA_ARGS__)
#define HE_FATAL(...)         ::Horus::Logger::GetClientLogger()->fatal(__VA_ARGS__)


