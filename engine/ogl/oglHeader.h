#pragma once

#include <API/apiHeader.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#define ENGINE_BACKEND_OPENGL

#define IMPL(x) OpenGLImpl##x
#define IMPLEMENTATION "OpenGL"
