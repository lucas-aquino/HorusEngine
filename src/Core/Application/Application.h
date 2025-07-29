#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Horus
{

    class Application
    {
    private:

        bool m_Running;
        GLFWwindow* m_Window;

        float m_LastFrameTime; // Tiempo del ultimo frame para calcular el deltaTime

        static void GLFWErrorCallback(int error, const char* description);
        static void GLFWWindowCloseCallback(GLFWwindow* window);


    public:
        Application();
        virtual ~Application();

        virtual bool Initialize();

        virtual void Run();

        virtual void Shutdown();

        bool IsRunning() const { return m_Running; }

        GLFWwindow* GetWindow() const { return m_Window; }

        virtual void Update(float deltaTime);

        virtual void Render();

    };

    

}
