#include <iostream>
#include <API/Window.h>

int main() {
    std::cout << "Engine Using " << Engine::engineBackend() << std::endl;
    Engine::Window window("Engine", 800, 600);

    while (!window.closed()) {
        window.update();
        window.clear();
        // Draw stuff
        window.render();
    }

    return 0;
}
