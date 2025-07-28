#include "Application.h"
#include "../../Utils/Logger/Logger.h"
#include "Horus.h" 


int main(int argc, char** argv)
{
    // === 1. Inicialización Temprana del Logger ===
    // Es crucial inicializar el logger lo antes posible para capturar
    // cualquier error durante la inicialización del motor.
    Horus::Logger::Init();
    HE_INFO("Horus Engine: Punto de entrada ejecutado.");

    // === 2. Creación de la Instancia de la Aplicación de Juego ===
    // Llama a la función que debe ser implementada por el desarrollador del juego (en main.cpp).
    // Esto desacopla el motor de la lógica específica del juego.
    Horus::Application* app = CreateHorusApplication();

    if (!app)
    {
        HE_ERROR("Horus Engine: ¡La función CreateHorusApplication() devolvió nullptr!");
        return -1; // Error fatal
    }
    HE_INFO("Horus Engine: Instancia de aplicación de juego creada.");


    // === 3. Inicialización del Motor de la Aplicación ===
    // Llama al método de inicialización de la clase base Application.
    // Aquí es donde se inicializan GLFW, GLAD, subsistemas principales, etc.
    if (!app->Initialize())
    {
        HE_ERROR("Horus Engine: ¡Fallo al inicializar la aplicación!");
        delete app; // Limpiar antes de salir
        return -1; // Salir con error
    }
    HE_INFO("Horus Engine: Aplicación inicializada correctamente.");

    // === 4. Ejecución del Bucle Principal del Juego (Game Loop) ===
    // El método Run() de Horus::Application contendrá el bucle principal
    // (manejo de eventos, actualización de subsistemas, renderizado).
    HE_INFO("Horus Engine: Iniciando bucle principal del juego...");
    app->Run();
    HE_INFO("Horus Engine: Bucle principal del juego finalizado.");

    // === 5. Apagado y Limpieza del Motor ===
    // Llama al método de apagado de la clase base Application.
    // Aquí se liberan recursos de GLFW, OpenGL, etc.
    app->Shutdown();
    HE_INFO("Horus Engine: Aplicación apagada correctamente.");

    // === 6. Liberar la Memoria de la Instancia de la Aplicación ===
    delete app; // Libera la memoria asignada por new en CreateHorusApplication()

    HE_INFO("Horus Engine: Ejecución finalizada con éxito.");
    return 0; // Salida exitosa
}








