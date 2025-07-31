# src/Core/Application/CMakeLists.txt

add_library(Horus_Core_Application STATIC
    Application.cpp
    Application.h
    ${CMAKE_SOURCE_DIR}/src/main.cpp
)

target_include_directories(Horus_Core_Application PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:include/Core/Application>
)

target_compile_definitions(Horus_Core_Application PUBLIC SPDLOG_DLL)
target_link_libraries(Horus_Core_Application PRIVATE spdlog::spdlog)

target_link_libraries(Horus_Core_Application PUBLIC
    glfw
    glad::glad
    glm::glm-header-only
)

add_executable(Horus
    Horus.cpp
)

target_include_directories(Horus PRIVATE
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_SOURCE_DIR}/src/Utils/Logger
)

target_link_libraries(Horus PRIVATE
    Horus_Core_Application
    Horus_Utils_Logger
    Horus_Graphics_Shader
)

target_compile_definitions(Horus PRIVATE GLFW_DLL)