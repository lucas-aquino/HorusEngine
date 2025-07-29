#include "Horus.h"
#include "Utils/Logger/Logger.h"

// Nota: No hay codigo de shaders, VBOs, VAOs o funciones de renderizado aqu.
// Esta es solo la funcion principal del motor.

int main(int argc, char** argv)
{
    Horus::Logger::Init();
    HE_CORE_INFO("Horus Engine: Punto de entrada ejecutado.");

    Horus::Application* app = Horus::CreateHorusApplication();
    if (!app)
    {
        HE_CORE_CRITICAL("Horus Engine: La funcion CreateHorusApplication() devolvio nullptr!"); 
        return -1;
    }
    HE_CORE_INFO("Horus Engine: Instancia de aplicacion de juego creada.");

    if (!app->Initialize())
    {
        HE_CORE_CRITICAL("Horus Engine: Fallo al inicializar la aplicacion!");
        delete app;
        return -1;
    }
    HE_CORE_INFO("Horus Engine: Aplicacion inicializada correctamente.");

    HE_CORE_INFO("Horus Engine: Iniciando bucle principal del juego...");
    app->Run();
    HE_CORE_INFO("Horus Engine: Bucle principal del juego finalizado.");

    app->Shutdown();
    HE_CORE_INFO("Horus Engine: Aplicacion apagada correctamente.");

    delete app;
    HE_CORE_INFO("Horus Engine: Ejecucion finalizada con exito.");
    return 0;
}