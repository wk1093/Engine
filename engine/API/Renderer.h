#pragma once
#include "apiHeader.h"

#include "Color.h"
#include "Vectors.h"
#include "Mesh.h"
#include "Vertex.h"

namespace Engine {
    class Renderer {
    private:
        void* m_impl;

    public:
        Renderer(); // test constructor TODO: Remove this.
        Renderer(const std::string& pathToObj, const Color& color, const std::string& texPath="");
        Renderer(const std::vector<Vertex> vertices, const std::string& texPath="");
        Renderer(const Mesh&, const std::string& texPath="");

        void render();

        void* getImplRenderer();
    };
}