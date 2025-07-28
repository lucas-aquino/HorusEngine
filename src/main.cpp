#include "Core/Application/Application.h"
#include "Core/Application/Horus.h" // Solo si necesitas las declaraciones de CreateHorusApplication()
#include "Utils/Logger/Logger.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h> // Necesario para funciones de GLFW si las usas aqu�

class GameApplication : public Horus::Application
{
public:
    // Variables para el tri�ngulo de prueba
    unsigned int m_VBO;
    unsigned int m_VAO;
    unsigned int m_shaderProgram;

    GameApplication()
    {
        HE_INFO("GameApplication: �Horus Engine est� listo para tu juego!");

        // --- Configuraci�n para dibujar un tri�ngulo ---
        float vertices[] = {
            // Posiciones        // Colores (RGB)
            -0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,
             0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,
             0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f
        };

        glGenVertexArrays(1, &m_VAO);
        glBindVertexArray(m_VAO);

        glGenBuffers(1, &m_VBO);
        glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
        glEnableVertexAttribArray(1);

        // --- Shaders ---
        const char* vertexShaderSource = R"(
            #version 330 core
            layout (location = 0) in vec3 aPos;
            layout (location = 1) in vec3 aColor;
            out vec3 ourColor;
            void main()
            {
                gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
                ourColor = aColor;
            }
        )";

        const char* fragmentShaderSource = R"(
            #version 330 core
            out vec4 FragColor;
            in vec3 ourColor;
            void main()
            {
                FragColor = vec4(ourColor, 1.0);
            }
        )";

        unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
        glCompileShader(vertexShader);
        int success;
        char infoLog[512];
        glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
        if (!success) {
            glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
            HE_ERROR("GameApplication: ERROR::SHADER::VERTEX::COMPILATION_FAILED\n{0}", infoLog);
        }

        unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
        glCompileShader(fragmentShader);
        glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
        if (!success) {
            glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
            HE_ERROR("GameApplication: ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n{0}", infoLog);
        }

        m_shaderProgram = glCreateProgram();
        glAttachShader(m_shaderProgram, vertexShader);
        glAttachShader(m_shaderProgram, fragmentShader);
        glLinkProgram(m_shaderProgram);
        glGetProgramiv(m_shaderProgram, GL_LINK_STATUS, &success);
        if (!success) {
            glGetProgramInfoLog(m_shaderProgram, 512, NULL, infoLog);
            HE_ERROR("GameApplication: ERROR::SHADER::PROGRAM::LINKING_FAILED\n{0}", infoLog);
        }

        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);

        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindVertexArray(0);
    }

    ~GameApplication()
    {
        HE_INFO("GameApplication: Tu juego se est� cerrando.");
        glDeleteVertexArrays(1, &m_VAO);
        glDeleteBuffers(1, &m_VBO);
        glDeleteProgram(m_shaderProgram);
    }

    void Update(float deltaTime) override
    {
        // Tu l�gica de actualizaci�n de juego
    }

    void Render() override
    {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f); // Puedes mover esto al Application::Initialize() si es un estado global
        glClear(GL_COLOR_BUFFER_BIT); // Tambi�n puedes mover esto al Application::Render()
        glUseProgram(m_shaderProgram);
        glBindVertexArray(m_VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        glBindVertexArray(0);
    }
};

// Esta funci�n es llamada por el motor para obtener una instancia de la aplicaci�n del juego
Horus::Application* Horus::CreateHorusApplication()
{
    return new GameApplication();
}