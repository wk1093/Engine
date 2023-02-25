#include <iostream>
#include <API/Window.h>
#include <API/Renderer.h>
#include <API/Meshes.h>

using namespace Engine;

int main() {
    std::cout << engineBackend() << std::endl;
    std::cout << "Loading mesh...";
    Mesh spiral = Mesh("res/meshes/spiral.obj", Colors::Cyan);
    Mesh square = Meshes::square(Colors::Red);

    std::cout << " Done" << std::endl;

    Window window("Engine", 800, 800);

    Renderer object1(spiral);
    Renderer object2(square);
    object2.setScale(Vector3f(0.2, 0.2, 0.2));

    while (!window.closed()) {
        window.update();
        window.clear();

        object1.rotate(Vector3f(0, 0, 300*window.mDt));
        double scale = 0.5*sin(window.mTime*5)+1;
        object1.setScale(Vector3f(scale, scale, scale));
        object1.setPos(Vector3f(0.5*cos(window.mTime), 0.5*sin(window.mTime), 0));

        object2.rotate(Vector3f(0, 0, 800*window.mDt));

        object1.render();
        object2.render();

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