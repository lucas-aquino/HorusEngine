
#include "Core/Application/Application.h"

#include "Core/Application/Horus.h" 

#include "Utils/Logger/Logger.h"

#include <glad/glad.h>

class GameApplication : public Horus::Application
{
public:

    // Variables para el triángulo de prueba
    unsigned int m_VBO; // Vertex Buffer Object
    unsigned int m_VAO; // Vertex Array Object
    unsigned int m_shaderProgram; // Programa de sombreado

    GameApplication()
    {
        // Puedes añadir aquí la inicialización de sistemas de tu juego,
        // cargar escenas iniciales, crear entidades de juego, etc.
        // Aquí no va la inicialización de GLFW o OpenGL.
        HE_INFO("GameApplication: ¡Horus Engine está listo para tu juego!"); // Ejemplo usando el logger





        // --- Configuración para dibujar un triángulo ---
        // Vértices del triángulo (posición y color simple)
        float vertices[] = {
            // Posiciones        // Colores (RGB)
            -0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f, // Inferior Izquierda (Rojo)
             0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f, // Inferior Derecha (Verde)
             0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f  // Superior Centro (Azul)
        };

        // Crear Vertex Array Object (VAO)
        glGenVertexArrays(1, &m_VAO);
        glBindVertexArray(m_VAO);

        // Crear Vertex Buffer Object (VBO)
        glGenBuffers(1, &m_VBO);
        glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

        // Especificar el layout de los atributos del vértice
        // Atributo 0: Posición (3 floats)
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);
        // Atributo 1: Color (3 floats, con un offset de 3 floats)
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

        // Compilar Vertex Shader
        unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
        glCompileShader(vertexShader);
        // Verificar errores de compilación
        int success;
        char infoLog[512];
        glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
        if (!success) {
            glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
            HE_ERROR("GameApplication: ERROR::SHADER::VERTEX::COMPILATION_FAILED\n{0}", infoLog);
        }

        // Compilar Fragment Shader
        unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
        glCompileShader(fragmentShader);
        // Verificar errores de compilación
        glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
        if (!success) {
            glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
            HE_ERROR("GameApplication: ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n{0}", infoLog);
        }

        // Crear programa de sombreado
        m_shaderProgram = glCreateProgram();
        glAttachShader(m_shaderProgram, vertexShader);
        glAttachShader(m_shaderProgram, fragmentShader);
        glLinkProgram(m_shaderProgram);
        // Verificar errores de linking
        glGetProgramiv(m_shaderProgram, GL_LINK_STATUS, &success);
        if (!success) {
            glGetProgramInfoLog(m_shaderProgram, 512, NULL, infoLog);
            HE_ERROR("GameApplication: ERROR::SHADER::PROGRAM::LINKING_FAILED\n{0}", infoLog);
        }

        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);

        glBindBuffer(GL_ARRAY_BUFFER, 0); // Desvincular VBO
        glBindVertexArray(0);             // Desvincular VAO





    }

    ~GameApplication()
    {
        // Aquí puedes realizar la limpieza de recursos específicos de tu juego,
        // como guardar el estado del juego, liberar memoria de tus objetos de juego.
        HE_INFO("GameApplication: Tu juego se está cerrando.");


        // Limpieza de recursos OpenGL al destruir la aplicación
        glDeleteVertexArrays(1, &m_VAO);
        glDeleteBuffers(1, &m_VBO);
        glDeleteProgram(m_shaderProgram);
    }

    
    void Update(float deltaTime) override
    {
        // Lógica de actualización de tu juego (movimiento de personajes, IA, etc.)
        HE_TRACE("GameApplication: Actualizando con DeltaTime: {0}s", deltaTime);

        // Puedes llamar a la implementación base si necesitas que haga algo extra
        // Horus::Application::Update(deltaTime);
    }

    // Sobrescribe el método Render para la lógica de renderizado por frame.
    void Render() override
    {
        // Lógica de renderizado de tu juego (dibujar personajes, UI, etc.)
        HE_TRACE("GameApplication: Renderizando...");

        // Puedes llamar a la implementación base si necesitas que haga algo extra
        // Horus::Application::Render();



        // Usar el programa de sombreado
        glUseProgram(m_shaderProgram);
        // Vincular el VAO para dibujar
        glBindVertexArray(m_VAO);
        // Dibujar el triángulo
        glDrawArrays(GL_TRIANGLES, 0, 3);
        // Desvincular VAO después de dibujar (opcional, pero buena práctica)
        glBindVertexArray(0);
    }
};


Horus::Application* Horus::CreateHorusApplication()
{
    return new GameApplication();
}

/*
int main() {
    if (!glfwInit()) {
        std::cerr << "Fallo GLFW\n";
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(800, 600, "Horus Engine", nullptr, nullptr);
    if (!window) {
        std::cerr << "Error creando la ventana\n";
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Error inicializando GLAD\n";
        return -1;
    }

    while (!glfwWindowShouldClose(window)) {
        glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
*/
















