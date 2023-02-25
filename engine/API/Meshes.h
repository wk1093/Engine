#pragma once
#include "apiHeader.h"

#include "Color.h"
#include "Mesh.h"

namespace Engine {
    class Meshes {
    public:

        static Mesh square(float x, float y, float w, float h, const Color& color);
    };
}