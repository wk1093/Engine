#pragma once
#include "apiHeader.h"

#include "Color.h"
#include "Vectors.h"
#include "Mesh.h"
#include "Vertex.h"
#include "Shader.h"

namespace Engine {
    class Renderer {
    private:
        void* m_impl;
        Shader* m_shader;

    public:
        Renderer(); // test constructor TODO: Remove this.
        explicit Renderer(const Mesh&, const std::string& texPath="");
        Renderer(const Mesh&, Shader* shader);

        void render();

        void* getImplRenderer();
    };
}