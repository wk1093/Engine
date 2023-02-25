cmake_minimum_required(VERSION 3.23)
project(Engine)

set(CMAKE_CXX_STANDARD 17)
include(FetchContent)

include_directories(engine)

FetchContent_Declare(glm GIT_REPOSITORY https://github.com/g-truc/glm.git GIT_TAG 0.9.9.8 )
FetchContent_MakeAvailable(glm)

add_library(engine_api INTERFACE engine/API/Window.h engine/API/Color.h engine/API/Shader.h engine/API/Vectors.h engine/API/Matrices.h
        engine/API/Renderer.h engine/API/Mesh.h engine/API/Vertex.h engine/API/Transform.h engine/API/Meshes.h)
add_library(engine_common STATIC engine/common/Color.cpp engine/common/Vertex.cpp engine/common/Mesh.cpp engine/common/Meshes.cpp engine/common/Transform.cpp)
target_link_libraries(engine_common engine_api glm)

add_subdirectory(engine/ogl) # OpenGL implementation (engine_oGL)

add_executable(Engine main.cpp)
target_link_libraries(Engine engine_oGL) # here you can select which implementation to use



