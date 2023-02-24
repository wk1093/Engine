#pragma once

#include "Vectors.h"
#include "Color.h"

namespace Engine {
    class Vertex {
    private:
        void* m_impl;

    public:
        Vertex();
        explicit Vertex(const Vector3f& pos);
        Vertex(const Vector3f& pos, const Color& col);
        Vertex(const Vector3f& pos, const Vector2f& tex);
        Vertex(const Vector3f& pos, const Vector2f& tex, const Color& col);
        Vertex(const Vector3f& pos, const Vector2f& tex, const Vector3f& norm, const Color& col);

        static int size();

        bool operator==(const Vertex& other) const;

        void* getImplShader();
    };
}