#include "Logger.h"

namespace Horus {
    std::shared_ptr<spdlog::logger> Logger::s_CoreLogger;
    std::shared_ptr<spdlog::logger> Logger::s_ClientLogger;

    void Logger::Init()
    {

        //configura el formato de los logs
        spdlog::set_pattern("%^[%T] %n: %v%$");

        // Inicializa el logger del Core del Motor
        s_CoreLogger = spdlog::stdout_color_mt("HORUS");
        s_CoreLogger->set_level(spdlog::level::trace);


        // Inicializa el logger de la aplicación Cliente (tu juego)
        s_ClientLogger = spdlog::stdout_color_mt("APP");
        s_ClientLogger->set_level(spdlog::level::trace);


    }

} 









