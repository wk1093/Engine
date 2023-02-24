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
        explicit Renderer(const Mesh&, const std::string& texPath="");

        void render();

        void* getImplRenderer();
    };
}