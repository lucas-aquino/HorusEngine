#include "Log.h"


namespace Horus
{


	std::shared_ptr<spdlog::logger> Log::sCoreLogger;
	std::shared_ptr<spdlog::logger> Log::sClientLogger;

	void Log::Init()
	{

		spdlog::set_pattern("%^[%T] %n: %v%$");

		sCoreLogger = spdlog::stdout_color_mt("HORUS");
		sCoreLogger->set_level(spdlog::level::trace);

		sClientLogger = spdlog::stdout_color_mt("APP");
		sClientLogger->set_level(spdlog::level::trace);


	}
}
