# CHANGELOG

Todas las entradas de este registro de cambios se adhieren al formato de [Keep a Changelog](https://keepachangelog.com/en/1.0.0/).
Las versiones de este proyecto se adhieren a [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## [0.1.0] - 2025-07-11

### Added
- **Configuraci�n Inicial del Proyecto:**
    - Establecido el est�ndar de C++20.
    - Integraci�n de CMake para la gesti�n del proyecto.
    - Configuraci�n del toolchain de vcpkg para la gesti�n de dependencias.
    - Definici�n del ejecutable principal `Horus`.
- **Integraci�n de Librer�as Fundamentales:**
    - **GLFW3:** A�adida para la creaci�n de ventanas y manejo de eventos.
    - **GLAD:** A�adida para la carga de punteros de funciones de OpenGL.
    - **GLM:** A�adida como librer�a de matem�ticas para gr�ficos (solo cabeceras).
- **Estructura B�sica del Motor:**
    - Implementaci�n de un bucle principal de la aplicaci�n.
    - Creaci�n y gesti�n de una ventana gr�fica b�sica.
- **Preparaci�n para Control de Versiones:**
    - Archivo `.gitignore` configurado para ignorar directorios de compilaci�n (`out/`, `vcpkg_installed/`) y archivos temporales/IDE.
    - Archivo `CHANGELOG.md` inicial.

### Fixed
- **Problema de Enlace con Librer�as:** Corregido error `LNK1104` al enlazar con `glad.lib` y otros, asegurando el uso correcto de los targets de CMake proporcionados por vcpkg (`glfw`, `glad::glad`, `glm::glm-header-only`).

### Changed
- No hay cambios significativos en funcionalidades preexistentes para esta versi�n inicial.
