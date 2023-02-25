#include <API/Meshes.h>

namespace Engine {
    Mesh Meshes::square(const Color& color) {

        return Mesh({
                            Vertex(Vector3f(0.5, 0.5, 0.0f), Vector2f(1.0f, 1.0f), color), // ex .5, .5
                            Vertex(Vector3f(0.5, -0.5, 0.0f), Vector2f(1.0f, 0.0f), color), // ex .5 -.5
                            Vertex(Vector3f(-0.5, -0.5, 0.0f), Vector2f(0.0f, 0.0f), color), // ex -.5 -.5
                            Vertex(Vector3f(-0.5, 0.5, 0.0f), Vector2f(0.0f, 1.0f), color)  // ex -.5 .5
                    }, {
                            0, 1, 3, 1, 2, 3
                    });
    }
}