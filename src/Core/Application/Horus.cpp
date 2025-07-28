#include "Horus.h"
#include "Application.h"
#include "Utils/Logger/Logger.h"

// Nota: No hay c�digo de shaders, VBOs, VAOs o funciones de renderizado aqu�.
// Esta es solo la funci�n principal del motor.

int main(int argc, char** argv)
{
    Horus::Logger::Init();
    HE_CORE_INFO("Horus Engine: Punto de entrada ejecutado.");

    Horus::Application* app = Horus::CreateHorusApplication();
    if (!app)
    {
        HE_CORE_FATAL("Horus Engine: �La funci�n CreateHorusApplication() devolvi� nullptr!");
        return -1;
    }
    HE_CORE_INFO("Horus Engine: Instancia de aplicaci�n de juego creada.");

    if (!app->Initialize())
    {
        HE_CORE_FATAL("Horus Engine: �Fallo al inicializar la aplicaci�n!");
        delete app;
        return -1;
    }
    HE_CORE_INFO("Horus Engine: Aplicaci�n inicializada correctamente.");

    HE_CORE_INFO("Horus Engine: Iniciando bucle principal del juego...");
    app->Run();
    HE_CORE_INFO("Horus Engine: Bucle principal del juego finalizado.");

    app->Shutdown();
    HE_CORE_INFO("Horus Engine: Aplicaci�n apagada correctamente.");

    delete app;
    HE_CORE_INFO("Horus Engine: Ejecuci�n finalizada con �xito.");
    return 0;
}