# Horus Engine

Horus Engine es un motor de juego experimental desarrollado en C++ utilizando OpenGL. Este proyecto tiene como objetivo explorar la creación de un motor desde cero, abarcando aspectos como el sistema de ventanas, el pipeline de renderizado, la gestión de recursos y más.

## Contenido

- [Características](#características)
- [Requisitos del Sistema](#requisitos-del-sistema)
- [Configuración del Entorno de Desarrollo](#configuración-del-entorno-de-desarrollo)
    - [1. Visual Studio 2022](#1-visual-studio-2022)
    - [2. CMake](#2-cmake)
    - [3. VCPKG](#3-vcpkg)
- [Clonar el Repositorio](#clonar-el-repositorio)
- [Construir el Proyecto](#construir-el-proyecto)
- [Ejecutar el Proyecto](#ejecutar-el-proyecto)
- [Estructura del Proyecto](#estructura-del-proyecto)
- [Contribuciones](#contribuciones)
- [Licencia](#licencia)

## Características

* **Sistema de Ventanas:** Gestión de ventanas y eventos de entrada (GLFW).
* **Gráficos 3D:** Renderizado con OpenGL (GLAD).
* **Registro:** Sistema de logging robusto y configurable (Spdlog).
* **Matemáticas:** Utilidades matemáticas para gráficos (GLM).
* **Estructura Modular:** Proyecto organizado en librerías para facilitar la gestión.

## Requisitos del Sistema

* **Sistema Operativo:** Windows 10/11 (la configuración actual está optimizada para Windows y MSVC).
* **Espacio en Disco:** ~1-2 GB para las dependencias y el build.
* **Compilador:** MSVC (Visual Studio 2022).
* **Tarjeta Gráfica:** Compatible con OpenGL 3.3 o superior.

## Configuración del Entorno de Desarrollo

Para construir y ejecutar Horus Engine, necesitarás las siguientes herramientas:

### 1. Visual Studio 2022

Descarga e instala [Visual Studio 2022 Community Edition](https://visualstudio.microsoft.com/es/vs/community/).
Asegúrate de instalar los siguientes Workloads:
* **Desarrollo para escritorio con C++**
* **Desarrollo de juegos con C++** (opcional, pero útil para herramientas).
* Componentes individuales: Asegúrate de que el **SDK de Windows más reciente** esté seleccionado.

### 2. CMake

Descarga e instala [CMake](https://cmake.org/download/).
Asegúrate de añadir CMake al PATH del sistema durante la instalación.

### 3. VCPKG

VCPKG es un gestor de paquetes de C++ de Microsoft. Lo usaremos para gestionar todas las dependencias del proyecto.

1.  **Clonar VCPKG:**
    ```bash
    git clone [https://github.com/microsoft/vcpkg.git](https://github.com/microsoft/vcpkg.git) C:\tools\vcpkg
    ```
    (Puedes elegir otra ubicación, pero `C:\tools\vcpkg` es una convención común).

2.  **Construir VCPKG:**
    ```bash
    cd C:\tools\vcpkg
    .\bootstrap-vcpkg.bat
    ```

3.  **Integrar VCPKG con Visual Studio:**
    ```bash
    .\vcpkg integrate install
    ```
    Esto configurará Visual Studio para encontrar librerías instaladas por VCPKG.

4.  **Instalar dependencias del proyecto:**
    Navega a la raíz de tu proyecto Horus Engine y ejecuta:
    ```bash
    # Asegúrate de estar en la raíz de Horus Engine, donde está vcpkg.json
    vcpkg install
    ```
    Esto leerá el archivo `vcpkg.json` y descargará/compilará todas las dependencias necesarias (GLFW, GLAD, GLM, Spdlog). Esto puede tardar un tiempo la primera vez.

## Clonar el Repositorio

```bash
git clone [https://github.com/tu_usuario/HorusEngine.git](https://github.com/tu_usuario/HorusEngine.git)
cd HorusEngine