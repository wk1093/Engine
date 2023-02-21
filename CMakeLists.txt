cmake_minimum_required(VERSION 3.23)
project(Engine)

set(CMAKE_CXX_STANDARD 17)
include(FetchContent)

include_directories(engine)

add_library(engine_api INTERFACE engine/API/Vector.h engine/API/Vector2i.h engine/API/Window.h engine/API/Color.h)
add_library(engine_common STATIC engine/common/Vector.cpp engine/common/Vector2i.cpp engine/common/Color.cpp)
target_link_libraries(engine_common engine_api)

#
add_library(engine_oGL STATIC engine/ogl/Window.cpp engine/ogl/oglHeader.h) # OpenGL implementation
FetchContent_Declare(
        GLFW
        GIT_REPOSITORY https://github.com/glfw/glfw
        GIT_TAG        3.3.4
)
FetchContent_MakeAvailable(GLFW)
FetchContent_Declare(
        glad
        GIT_REPOSITORY https://github.com/Dav1dde/glad.git
        GIT_TAG        v0.1.34
)
FetchContent_GetProperties(glad)
if(NOT glad_POPULATED)
    FetchContent_Populate(glad)
    set(GLAD_INSTALL ON)
    add_subdirectory(
            ${glad_SOURCE_DIR}
            ${glad_BINARY_DIR}
            EXCLUDE_FROM_ALL)
endif()
FetchContent_Declare(
        glm
        GIT_REPOSITORY https://github.com/g-truc/glm.git
        GIT_TAG        0.9.9.8
)
FetchContent_MakeAvailable(glm)
target_link_libraries(engine_oGL glfw glad glm engine_common)
find_package(OpenGL REQUIRED)
target_link_libraries(engine_oGL OpenGL::GL)
target_include_directories(engine_oGL PUBLIC ${OPENGL_INCLUDE_DIR} ${GLFW_INCLUDE_DIR} ${GLAD_INCLUDE_DIR} ${GLM_INCLUDE_DIR})

add_executable(Engine main.cpp)
target_link_libraries(Engine engine_oGL) # here you can select which implementation to use



