add_library(Horus_Core_Application STATIC
    Application.cpp
    Application.h
)
target_include_directories(Horus_Core_Application PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:include/Core/Application>
)
target_link_libraries(Horus_Core_Application PUBLIC
    glfw::glfw 
    glad::glad
    glm::glm-header-only
)
add_executable(Horus
    Horus.cpp
    ${CMAKE_SOURCE_DIR}/src/main.cpp
)
target_include_directories(Horus PRIVATE
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_SOURCE_DIR}/src/Utils/Logger
)
target_link_libraries(Horus PRIVATE
    Horus_Core_Application
    Horus_Utils_Logger
)
target_compile_definitions(Horus PRIVATE GLFW_DLL)