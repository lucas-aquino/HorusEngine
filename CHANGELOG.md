# CHANGELOG

Todas las entradas de este registro de cambios se adhieren al formato de [Keep a Changelog](https://keepachangelog.com/en/1.0.0/).
Las versiones de este proyecto se adhieren a [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## [0.1.0] - 2025-07-11

### Added
- **Configuración Inicial del Proyecto:**
    - Establecido el estándar de C++20.
    - Integración de CMake para la gestión del proyecto.
    - Configuración del toolchain de vcpkg para la gestión de dependencias.
    - Definición del ejecutable principal `Horus`.
- **Integración de Librerías Fundamentales:**
    - **GLFW3:** Añadida para la creación de ventanas y manejo de eventos.
    - **GLAD:** Añadida para la carga de punteros de funciones de OpenGL.
    - **GLM:** Añadida como librería de matemáticas para gráficos (solo cabeceras).
- **Estructura Básica del Motor:**
    - Implementación de un bucle principal de la aplicación.
    - Creación y gestión de una ventana gráfica básica.
- **Preparación para Control de Versiones:**
    - Archivo `.gitignore` configurado para ignorar directorios de compilación (`out/`, `vcpkg_installed/`) y archivos temporales/IDE.
    - Archivo `CHANGELOG.md` inicial.

### Fixed
- **Problema de Enlace con Librerías:** Corregido error `LNK1104` al enlazar con `glad.lib` y otros, asegurando el uso correcto de los targets de CMake proporcionados por vcpkg (`glfw`, `glad::glad`, `glm::glm-header-only`).

### Changed
- No hay cambios significativos en funcionalidades preexistentes para esta versión inicial.
