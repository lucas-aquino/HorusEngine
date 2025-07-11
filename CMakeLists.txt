# Establece la versión mínima requerida de CMake.
# Asegúrate de que esta versión sea compatible con tu instalación de CMake.
cmake_minimum_required(VERSION 3.21)

# Define el nombre de tu proyecto.
project(Horus)

# Establece el estándar de C++ a C++20.
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON) # Asegura que se use el estándar 20

# Configura CMake para usar vcpkg si la variable de entorno VCPKG_ROOT está definida.
# Esto es crucial para que CMake encuentre las librerías instaladas por vcpkg.
if(DEFINED ENV{VCPKG_ROOT})
    set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake"
        CACHE STRING "Ruta al archivo toolchain de vcpkg")
endif()

# Agrega el subdirectorio 'src' a la compilación.
# CMake buscará un CMakeLists.txt dentro de este directorio.
add_subdirectory(src)