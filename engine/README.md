# Engine Structure

/API - all the headers (.h) for the engine
/common - common implementation (.cpp) files
/gfx-glfw-opengl-glad - graphics implementation (.cpp) files for GLFW and OpenGL and glad
/gfx-directx - graphics implementation (.cpp) files for DirectX
/gfx-vulkan - graphics implementation (.cpp) files for Vulkan

Only one gfx implementation can be used at a time.
