# src/Graphics/Shader/CMakeLists.txt


add_library(Horus_Graphics_Shader STATIC
	Shader.cpp
	Shader.h
)

target_include_directories(Horus_Graphics_Shader PUBLIC
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
	$<INSTALL_INTERFACE:include/Graphics/Shader>
)


target_link_libraries(Horus_Graphics_Shader PRIVATE glm::glm)
	