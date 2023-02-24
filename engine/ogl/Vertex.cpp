#include "oglHeader.h"
#include <API/Vertex.h>

namespace Engine {
    class IMPL(Vertex) {
            public:
            Vector3f pos;
            Color col;
            Vector2f tex;

            IMPL(Vertex)() {
                pos = Vector3f(0, 0, 0);
                col = Color(0, 0, 0);
                tex = Vector2f(0, 0);
            }

            explicit IMPL(Vertex)(const Vector3f& p) {
                pos = p;
                col = Color(0, 0, 0);
                tex = Vector2f(0, 0);
            }

            IMPL(Vertex)(const Vector3f& p, const Vector2f& t) {
                pos = p;
                tex = t;
                col = Color(255, 255, 255);
            }

            IMPL(Vertex)(const Vector3f& p, const Color& c) {
                pos = p;
                col = c;
                tex = Vector2f(0, 0);
            }

            IMPL(Vertex)(const Vector3f& p, const Vector2f& t, const Color& c) {
                pos = p;
                col = c;
                tex = t;
            }

            float* glVertex() {
                return new float[] { pos.x, pos.y, pos.z, (float)col.r()/255.0f, (float)col.g()/255.0f, (float)col.b()/255.0f, (float)col.a()/255.0f, tex.x, tex.y };
            }

            void print() {
                printf("Vertex(%f,%f,%f, %i,%i,%i,%i, %f,%f)\n", pos.x, pos.y, pos.z, col.r(), col.g(), col.b(), col.a(), tex.x, tex.y);
            }
    };

    Vertex::Vertex() {
        m_impl = new IMPL(Vertex)();
    }
    Vertex::Vertex(const Engine::Vector3f& pos) {
        m_impl = new IMPL(Vertex)(pos);
    }

    Vertex::Vertex(const Vector3f& pos, const Color& col) {
        m_impl = new IMPL(Vertex)(pos, col);
    }

    Vertex::Vertex(const Engine::Vector3f &pos, const Engine::Vector2f &tex) {
        m_impl = new IMPL(Vertex)(pos, tex);
    }

    Vertex::Vertex(const Engine::Vector3f &pos, const Engine::Vector2f &tex, const Engine::Color &col) {
        m_impl = new IMPL(Vertex)(pos, tex, col);
    }

    bool Vertex::operator==(const Engine::Vertex &other) const {
        return ((IMPL(Vertex)*)m_impl)->pos == ((IMPL(Vertex)*)other.m_impl)->pos && ((IMPL(Vertex)*)m_impl)->col == ((IMPL(Vertex)*)other.m_impl)->col && ((IMPL(Vertex)*)m_impl)->tex == ((IMPL(Vertex)*)other.m_impl)->tex;
    }

    void *Vertex::getImplShader() {
        return m_impl;
    }

    int Vertex::size() {
        return 9;
    }
}