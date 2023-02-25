#pragma once
#include "apiHeader.h"

#include "Vertex.h"

namespace Engine {
    std::vector<std::string> split(const std::string& s, char delim);

    class Mesh {
    public:
        std::vector<Vertex> vertices;
        std::vector<unsigned int> indices;
        Mesh() = default;
        Mesh(const std::vector<Vertex>& v, const std::vector<unsigned int>& i);

        Mesh(const std::string& objFile, const Color& c);
    };
}
