cmake_minimum_required(VERSION 3.23)
project(Engine)

set(CMAKE_CXX_STANDARD 17)
include(FetchContent)

include_directories(engine)

add_library(engine_api INTERFACE engine/API/Vector.h engine/API/Window.h engine/API/Color.h engine/API/Shader.h engine/API/Vectors.h engine/API/Matrix.h engine/API/Matrices.h engine/API/Renderer.h engine/API/Mesh.h engine/API/Vertex.h)
add_library(engine_common STATIC engine/common/Vector.cpp engine/common/Color.cpp engine/common/Vectors.cpp engine/common/Matrix.cpp)
target_link_libraries(engine_common engine_api)

add_subdirectory(engine/ogl) # OpenGL implementation (engine_oGL)

add_executable(Engine main.cpp engine/API/Meshes.h)
target_link_libraries(Engine engine_oGL) # here you can select which implementation to use



