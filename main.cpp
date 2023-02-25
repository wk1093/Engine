#include <iostream>
#include <API/Window.h>
#include <API/Renderer.h>
#include <API/Meshes.h>

using namespace Engine;

int main() {
    std::cout << engineBackend() << std::endl;
    std::cout << "Loading mesh...";
    Mesh spiral = Mesh("res/meshes/spiral.obj", Colors::Cyan);

    std::cout << " Done" << std::endl;

    Window window("Engine", 800, 600);

    Renderer object(spiral);

    while (!window.closed()) {
        window.update();
        window.clear();

        object.rotate(Vector3f(0, 0, 0.01));

        object.render();

        window.render();
    }

    window.close();

    return 0;
}

// TODO: Add 3d transformations
// TODO: Add a texture class that will handle the loading of textures
// TODO: Add a camera class that will handle the camera movement and projection matrix
// TODO: Make the ECS
// TODO: OpenGL ES backend
// TODO: WebGL backend
// TODO: Vulkan backend
// TODO: DirectX backend
// TODO: Metal backend