#pragma once
#include "apiHeader.h"

#include "Color.h"
#include "Vectors.h"
#include "Mesh.h"
#include "Vertex.h"
#include "Shader.h"
#include "Transform.h"

namespace Engine {
    class Renderer {
    private:
        void* m_impl;
        Shader* m_shader;
        Transform m_tf;

    public:
        Renderer(); // test constructor TODO: Remove this.
        explicit Renderer(const Mesh&, const std::string& texPath="");
        Renderer(const Mesh&, Shader* shader, const std::string& texPath="");

        void render();

        void move(const Vector3f& vec);
        void rotate(const Vector3f& vec);
        void scale(const Vector3f& vec);

        void setPos(const Vector3f& vec);
        void setRot(const Vector3f& vec);
        void setScale(const Vector3f& vec);

        void* getImplRenderer();
    };
}