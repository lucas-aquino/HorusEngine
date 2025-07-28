#include "Horus.h"
#include "Application.h"
#include "Utils/Logger/Logger.h"

// Nota: No hay código de shaders, VBOs, VAOs o funciones de renderizado aquí.
// Esta es solo la función principal del motor.

int main(int argc, char** argv)
{
    Horus::Logger::Init();
    HE_CORE_INFO("Horus Engine: Punto de entrada ejecutado.");

    Horus::Application* app = Horus::CreateHorusApplication();
    if (!app)
    {
        HE_CORE_FATAL("Horus Engine: ¡La función CreateHorusApplication() devolvió nullptr!");
        return -1;
    }
    HE_CORE_INFO("Horus Engine: Instancia de aplicación de juego creada.");

    if (!app->Initialize())
    {
        HE_CORE_FATAL("Horus Engine: ¡Fallo al inicializar la aplicación!");
        delete app;
        return -1;
    }
    HE_CORE_INFO("Horus Engine: Aplicación inicializada correctamente.");

    HE_CORE_INFO("Horus Engine: Iniciando bucle principal del juego...");
    app->Run();
    HE_CORE_INFO("Horus Engine: Bucle principal del juego finalizado.");

    app->Shutdown();
    HE_CORE_INFO("Horus Engine: Aplicación apagada correctamente.");

    delete app;
    HE_CORE_INFO("Horus Engine: Ejecución finalizada con éxito.");
    return 0;
}