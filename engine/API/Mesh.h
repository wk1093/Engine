#pragma once
#include <utility>

#include "apiHeader.h"

#include "Vertex.h"

namespace Engine {
    class Mesh {
    public:
        std::vector<Vertex> vertices;
        std::vector<unsigned int> indices;
        Mesh() = default;
        Mesh(const std::vector<Vertex>& v, const std::vector<unsigned int>& i) {
            vertices = v;
            indices = i;
        }

        Mesh(std::string objFile) {
            // TODO: Load Obj File
        }
    };
}
