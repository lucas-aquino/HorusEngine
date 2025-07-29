#include "Application.h"


#include "../../Utils/Logger/Logger.h"

namespace Horus
{

    Application::Application()
        : m_Running(true), m_Window(nullptr), m_LastFrameTime(0.0f)
    {
        HE_CORE_INFO("Application: Constructor de la aplicacion Horus.");
    }


    Application::~Application()
    {
        HE_CORE_INFO("Application: Destructor de la aplicacion Horus.");
        Shutdown();
    }

    bool Application::Initialize()
    {
        HE_CORE_INFO("Application: Inicializando motor...");


        //Inicializar GLFW
        glfwSetErrorCallback(GLFWErrorCallback);

        if (!glfwInit())
        {
            HE_CORE_ERROR("Application: Error al inicializar GLFW");
            return false;
        }

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwWindowHint(GLFW_SAMPLES, 4); // Anti-aliasing MSAA

        //Crear la ventana
        m_Window = glfwCreateWindow(1280, 720, "Horus Engine", nullptr, nullptr);
        if (!m_Window) {
            HE_CORE_ERROR("Application: Error al crear la ventana GLFW");
            glfwTerminate();
            return false;
        }

        //Establecer el contexto de OpenGL
        glfwMakeContextCurrent(m_Window);

        // Establecer el callback de cierre de ventana
        glfwSetWindowCloseCallback(m_Window, GLFWWindowCloseCallback);

        // Establecer el puntero de usuario para acceder a la aplicacion desde el callback
        glfwSetWindowUserPointer(m_Window, this);

        HE_CORE_INFO("Application: Ventana creada correctamente.");

        //Inicializar GLAD
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
            HE_CORE_ERROR("Application: Error al inicializar Glad");
            return 0;
        }

        HE_CORE_INFO("Application: Version de OpenGL: {0}", (const char*)glGetString(GL_VERSION));
        HE_CORE_INFO("Application: Inicializacion de OpenGL completa.");

        // Configuracion inicial de OpenGL
        glEnable(GL_DEPTH_TEST); // Habilitar test de profundidad
        glEnable(GL_CULL_FACE);  // Habilitar culling de caras traseras
        glFrontFace(GL_CCW);     // Sentido de las manecillas del reloj para caras frontales
        glCullFace(GL_BACK);     // Eliminar caras traseras
        glViewport(0, 0, 1280, 720); // Establecer el viewport inicial
        glClearColor(0.0f, 0.3f, 0.5f, 1.0f);

        //TODO: Inicializar subsistemas adicionales

        HE_CORE_INFO("Application: Motor inicializado correctamente.");
        return true;
    }

    void Application::Run() {
        HE_CORE_INFO("Application: Iniciando bucle principal del juego...");


        while (IsRunning()) {

            //calcular el deltaTime
            float time = static_cast<float>(glfwGetTime());
            float deltaTime = time - m_LastFrameTime;
            m_LastFrameTime = time;

            //actualizar subsistemas y logica

            glfwPollEvents(); //procesar los eventos GLFW

            Update(deltaTime); // actualiza el juego

            //Render de la escena
            
            Render();

            glfwSwapBuffers(m_Window);
        }

        HE_CORE_INFO("Application: Bucle principal del juego finalizado.");
    }

    void Application::Shutdown() {
        HE_CORE_INFO("Application: Apagando motor...");

        m_Running = false;

        //destruimos la ventana
        if (m_Window) {
            glfwDestroyWindow(m_Window); //se tiene que destruir primero la ventana de glfw
            m_Window = nullptr;
        }

        glfwTerminate(); // terminamos GLFW

        HE_CORE_INFO("Application: Motor apagado.");
    }

    void Application::Update(float deltaTime)
    {
        //HE_CORE_TRACE("Application: Base Update llamado. DeltaTime: {0}s", deltaTime);
        //TODO: Update
    }

    void Application::Render() {
        //HE_CORE_TRACE("Application: Base Render llamado.");
        
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    void Application::GLFWErrorCallback(int error, const char* description) {
        HE_CORE_ERROR("GLFW Error ({0}): {1}", error, description);
    }

    void Application::GLFWWindowCloseCallback(GLFWwindow* window) {
        Application* app = static_cast<Application*>(glfwGetWindowUserPointer(window));
        if (app)
        {
            HE_CORE_INFO("Application: Solicitud de cierre de ventana.");
            app->m_Running = false;
        }
    }
}
