# src/Utils/Logger/CMakeLists.txt

add_library(Utils_Logger STATIC
    Logger.h   
    Logger.cpp
)

target_include_directories(Utils_Logger PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:include/Utils/Logger>
)
