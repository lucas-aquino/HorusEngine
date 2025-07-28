#include "Application.h"
#include "../../Utils/Logger/Logger.h"
#include "Horus.h" 


int main(int argc, char** argv)
{
    // === 1. Inicializaci�n Temprana del Logger ===
    // Es crucial inicializar el logger lo antes posible para capturar
    // cualquier error durante la inicializaci�n del motor.
    Horus::Logger::Init();
    HE_INFO("Horus Engine: Punto de entrada ejecutado.");

    // === 2. Creaci�n de la Instancia de la Aplicaci�n de Juego ===
    // Llama a la funci�n que debe ser implementada por el desarrollador del juego (en main.cpp).
    // Esto desacopla el motor de la l�gica espec�fica del juego.
    Horus::Application* app = CreateHorusApplication();

    if (!app)
    {
        HE_ERROR("Horus Engine: �La funci�n CreateHorusApplication() devolvi� nullptr!");
        return -1; // Error fatal
    }
    HE_INFO("Horus Engine: Instancia de aplicaci�n de juego creada.");


    // === 3. Inicializaci�n del Motor de la Aplicaci�n ===
    // Llama al m�todo de inicializaci�n de la clase base Application.
    // Aqu� es donde se inicializan GLFW, GLAD, subsistemas principales, etc.
    if (!app->Initialize())
    {
        HE_ERROR("Horus Engine: �Fallo al inicializar la aplicaci�n!");
        delete app; // Limpiar antes de salir
        return -1; // Salir con error
    }
    HE_INFO("Horus Engine: Aplicaci�n inicializada correctamente.");

    // === 4. Ejecuci�n del Bucle Principal del Juego (Game Loop) ===
    // El m�todo Run() de Horus::Application contendr� el bucle principal
    // (manejo de eventos, actualizaci�n de subsistemas, renderizado).
    HE_INFO("Horus Engine: Iniciando bucle principal del juego...");
    app->Run();
    HE_INFO("Horus Engine: Bucle principal del juego finalizado.");

    // === 5. Apagado y Limpieza del Motor ===
    // Llama al m�todo de apagado de la clase base Application.
    // Aqu� se liberan recursos de GLFW, OpenGL, etc.
    app->Shutdown();
    HE_INFO("Horus Engine: Aplicaci�n apagada correctamente.");

    // === 6. Liberar la Memoria de la Instancia de la Aplicaci�n ===
    delete app; // Libera la memoria asignada por new en CreateHorusApplication()

    HE_INFO("Horus Engine: Ejecuci�n finalizada con �xito.");
    return 0; // Salida exitosa
}








