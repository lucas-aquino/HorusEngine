# Encuentra todos los archivos .cpp en el directorio actual y subdirectorios.
# (Considera listar los archivos fuente explícitamente en proyectos grandes
# para un mejor control y para evitar problemas con GLOB_RECURSE en algunos IDEs)
file(GLOB_RECURSE SOURCES "*.cpp")

# Define el ejecutable de tu proyecto llamado 'Horus' usando los archivos fuente encontrados.
add_executable(Horus ${SOURCES})

# --- Configuración de Librerías de vcpkg ---
# Estas llamadas 'find_package' son esenciales para que CMake encuentre las librerías
# instaladas por vcpkg y configure las rutas de inclusión y enlace adecuadas.

# Encuentra el paquete glfw3. 'CONFIG REQUIRED' asegura que se encuentre la configuración de CMake.
find_package(glfw3 CONFIG REQUIRED)

# Encuentra el paquete glad.
find_package(glad CONFIG REQUIRED)

# Encuentra el paquete glm. GLM es una librería de solo cabeceras, pero 'find_package'
# asegura que sus directorios de inclusión estén disponibles.
find_package(glm CONFIG REQUIRED)

# Enlaza las librerías al ejecutable 'Horus'.
# Usamos los nombres de los "targets" que vcpkg expone, los cuales obtuvimos de tu salida de CMake.
target_link_libraries(Horus PRIVATE
    # Target para GLFW. Tu salida de vcpkg indicó 'glfw' (sin namespace).
    glfw

    # Target para GLAD. Tu salida de vcpkg indicó 'glad::glad'.
    glad::glad

    # Target para GLM. Tu salida de vcpkg ofreció 'glm::glm' o 'glm::glm-header-only'.
    # 'glm::glm-header-only' es una opción explícita para indicar que es una librería de solo cabeceras.
    glm::glm-header-only
)