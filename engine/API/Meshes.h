#pragma once
#include "apiHeader.h"

#include "Color.h"
#include "Mesh.h"

namespace Engine {
    class Meshes {
    public:

        static Mesh square(float x, float y, float w, float h, const Color& color) {
            float x1 = x-w/2.0f;
            float y1 = y-h/2.0f;
            float x2 = x+w/2.0f;
            float y2 = y+h/2.0f;

            return Mesh({
                Vertex(Vector3f(x2, y2, 0.0f), Vector2f(1.0f, 1.0f), color), // ex .5, .5
                Vertex(Vector3f(x2, y1, 0.0f), Vector2f(1.0f, 0.0f), color), // ex .5 -.5
                Vertex(Vector3f(x1, y1, 0.0f), Vector2f(0.0f, 0.0f), color), // ex -.5 -.5
                Vertex(Vector3f(x1, y2, 0.0f), Vector2f(0.0f, 1.0f), color)  // ex -.5 .5
            }, {
                0, 1, 3, 1, 2, 3
            });
        }
    };
}