#include <iostream>
#include <API/Window.h>
#include <API/Shader.h>
#include <API/Renderer.h>

int main() {
    std::cout << "Engine Using " << Engine::engineBackend() << std::endl;
    Engine::Window window("Engine", 800, 600);
    Engine::Shader shader("res/shaders/basic.vert", "res/shaders/basic.frag");
    Engine::Renderer object; // test constructor

    while (!window.closed()) {
        window.update();
        window.clear();


        shader.bind();

        object.render();

        shader.unbind();


        window.render();
    }

    window.close();

    return 0;
}


// TODO: Add a renderer class that will handle the rendering of objects using vertex arrays and vertex buffers
// TODO: Add a texture class that will handle the loading of textures
// TODO: Add a camera class that will handle the camera movement and projection matrix
// TODO: Add a mesh class that will handle the loading of meshes
// TODO: Make the ECS
// TODO: Easy way to render basic shapes without dealing with vertex arrays or shaders, built-in shaders
// TODO: Vulkan backend
// TODO: OpenGL ES backend
// TODO: DirectX backend
// TODO: WebGL backend
// TODO: Metal backend