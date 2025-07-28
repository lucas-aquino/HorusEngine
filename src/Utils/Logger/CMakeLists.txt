# src/Utils/Logger/CMakeLists.txt

add_library(Horus_Utils_Logger STATIC
    Logger.cpp
    Logger.h
)

target_include_directories(Horus_Utils_Logger PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:include/Utils/Logger>
)

target_link_libraries(Horus_Utils_Logger PUBLIC spdlog::spdlog)