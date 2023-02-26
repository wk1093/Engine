# Engine Structure

/API - all the headers (.h) for the engine

/common - common implementation (.cpp) files

/ogl - graphics implementation (.cpp) files for GLFW and OpenGL and glad

/dx11 - graphics implementation (.cpp) files for DirectX

/vk - graphics implementation (.cpp) files for Vulkan

Only one gfx implementation can be used at a time.
