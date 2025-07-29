# Horus Engine

Horus Engine es un motor de juego experimental desarrollado en C++ utilizando OpenGL. Este proyecto tiene como objetivo explorar la creaci�n de un motor desde cero, abarcando aspectos como el sistema de ventanas, el pipeline de renderizado, la gesti�n de recursos y m�s.

## Contenido

- [Caracter�sticas](#caracter�sticas)
- [Requisitos del Sistema](#requisitos-del-sistema)
- [Configuraci�n del Entorno de Desarrollo](#configuraci�n-del-entorno-de-desarrollo)
    - [1. Visual Studio 2022](#1-visual-studio-2022)
    - [2. CMake](#2-cmake)
    - [3. VCPKG](#3-vcpkg)
- [Clonar el Repositorio](#clonar-el-repositorio)
- [Construir el Proyecto](#construir-el-proyecto)
- [Ejecutar el Proyecto](#ejecutar-el-proyecto)
- [Estructura del Proyecto](#estructura-del-proyecto)
- [Contribuciones](#contribuciones)
- [Licencia](#licencia)

## Caracter�sticas

* **Sistema de Ventanas:** Gesti�n de ventanas y eventos de entrada (GLFW).
* **Gr�ficos 3D:** Renderizado con OpenGL (GLAD).
* **Registro:** Sistema de logging robusto y configurable (Spdlog).
* **Matem�ticas:** Utilidades matem�ticas para gr�ficos (GLM).
* **Estructura Modular:** Proyecto organizado en librer�as para facilitar la gesti�n.

## Requisitos del Sistema

* **Sistema Operativo:** Windows 10/11 (la configuraci�n actual est� optimizada para Windows y MSVC).
* **Espacio en Disco:** ~1-2 GB para las dependencias y el build.
* **Compilador:** MSVC (Visual Studio 2022).
* **Tarjeta Gr�fica:** Compatible con OpenGL 3.3 o superior.

## Configuraci�n del Entorno de Desarrollo

Para construir y ejecutar Horus Engine, necesitar�s las siguientes herramientas:

### 1. Visual Studio 2022

Descarga e instala [Visual Studio 2022 Community Edition](https://visualstudio.microsoft.com/es/vs/community/).
Aseg�rate de instalar los siguientes Workloads:
* **Desarrollo para escritorio con C++**
* **Desarrollo de juegos con C++** (opcional, pero �til para herramientas).
* Componentes individuales: Aseg�rate de que el **SDK de Windows m�s reciente** est� seleccionado.

### 2. CMake

Descarga e instala [CMake](https://cmake.org/download/).
Aseg�rate de a�adir CMake al PATH del sistema durante la instalaci�n.

### 3. VCPKG

VCPKG es un gestor de paquetes de C++ de Microsoft. Lo usaremos para gestionar todas las dependencias del proyecto.

1.  **Clonar VCPKG:**
    ```bash
    git clone [https://github.com/microsoft/vcpkg.git](https://github.com/microsoft/vcpkg.git) C:\tools\vcpkg
    ```
    (Puedes elegir otra ubicaci�n, pero `C:\tools\vcpkg` es una convenci�n com�n).

2.  **Construir VCPKG:**
    ```bash
    cd C:\tools\vcpkg
    .\bootstrap-vcpkg.bat
    ```

3.  **Integrar VCPKG con Visual Studio:**
    ```bash
    .\vcpkg integrate install
    ```
    Esto configurar� Visual Studio para encontrar librer�as instaladas por VCPKG.

4.  **Instalar dependencias del proyecto:**
    Navega a la ra�z de tu proyecto Horus Engine y ejecuta:
    ```bash
    # Aseg�rate de estar en la ra�z de Horus Engine, donde est� vcpkg.json
    vcpkg install
    ```
    Esto leer� el archivo `vcpkg.json` y descargar�/compilar� todas las dependencias necesarias (GLFW, GLAD, GLM, Spdlog). Esto puede tardar un tiempo la primera vez.

## Clonar el Repositorio

```bash
git clone [https://github.com/tu_usuario/HorusEngine.git](https://github.com/tu_usuario/HorusEngine.git)
cd HorusEngine