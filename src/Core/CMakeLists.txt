# src/Core/CMakeLists.txt

# Este CMakeLists.txt solo se encarga de añadir los subdirectorios
# que contienen los módulos reales del "Core" del motor.

# Añade el subdirectorio 'Application'.
# El CMakeLists.txt dentro de 'Application' se encargará de definir
# la librería Core_Application y el ejecutable principal 'Horus'.
add_subdirectory(Application)

# Descomenta y añade los siguientes cuando crees esos módulos
# y sus respectivos CMakeLists.txt dentro de ellos.
# add_subdirectory(ECS)
# add_subdirectory(Input)
# add_subdirectory(Time)
# add_subdirectory(ResourceManager)