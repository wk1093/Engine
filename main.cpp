#include <iostream>
#include <API/Window.h>
#include <API/Shader.h>

int main() {
    std::cout << "Engine Using " << Engine::engineBackend() << std::endl;
    Engine::Window window("Engine", 800, 600);
    Engine::Shader shader("res/shaders/basic.vert", "res/shaders/basic.frag");

    while (!window.closed()) {
        window.update();
        window.clear();
        //shader.bind();
        // Draw stuff
        // shader.unbind();
        window.render();
    }

    window.close();

    return 0;
}
