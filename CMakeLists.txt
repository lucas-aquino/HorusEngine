# CMakeLists.txt (en la raíz de HorusEngine)

cmake_minimum_required(VERSION 3.21) # Asegúrate de tener una versión de CMake suficiente
project(Horus) # Nombre de tu proyecto



set(CMAKE_CXX_STANDARD 20) # Establece el estándar C++ a C++20
set(CMAKE_CXX_STANDARD_REQUIRED ON) # Asegura que se use C++20 y falle si no es posible

# --- Configuración para vcpkg ---
# Esto es crucial para que CMake encuentre las librerías instaladas por vcpkg.
if(DEFINED ENV{VCPKG_ROOT})
    set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake" CACHE STRING "")
endif()



find_package(glfw3 CONFIG REQUIRED)
find_package(glad CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)
find_package(spdlog CONFIG REQUIRED)
find_package(Stb REQUIRED)
find_package(Assimp CONFIG REQUIRED)

# --- Opciones de compilación generales ---
# Esto resuelve el error de Unicode (/utf-8) para *todos* los targets de C++ en MSVC.
if(MSVC)
    add_compile_options(/utf-8)
endif()

# --- Incluir subdirectorios ---
# Aquí agregas el subdirectorio 'src' que contiene la lógica principal del motor.
add_subdirectory(src)

