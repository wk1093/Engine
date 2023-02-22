#pragma once
#include "apiHeader.h"

#include "Vertex.h"

namespace Engine {
    class Mesh {
        std::vector<Vertex> vertices;
        std::vector<unsigned int> indices;
    };
}
