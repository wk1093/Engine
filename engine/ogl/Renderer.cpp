#include "oglHeader.h"
#include <API/Renderer.h>

#include "VertexAttributeBuilder.h"
#include "Vertex.cpp"

#define VERTEX(x,y,z,r,g,b,a,u,v) Vertex(Vector3f(x,y,z),Vector2f(u,v),Color(r,g,b,a))

namespace Engine {
    IMPL(Vertex)* implv(Vertex v) {
        return reinterpret_cast<IMPL(Vertex)*>(v.getImplShader());
    }

    struct glVertexArray {
        float* arr;
        int len;
    };
    struct glVertexElementArray {
        unsigned int* arr;
        int len;
    };

    glVertexArray toGlArray(const std::vector<Vertex>& v) {
        std::vector<float> f;
        for (Vertex vx : v) {
            implv(vx)->print();
            float* fs = implv(vx)->glVertex();
            for (int i = 0; i < Vertex::size(); i++) {
                f.push_back(fs[i]);
            }
        }
        return glVertexArray{f.data(), (int)(f.size())};
    }
    glVertexElementArray toGlArray(const std::vector<unsigned int>& v) {
        std::vector<unsigned int> f = v;
        return glVertexElementArray{f.data(), (int)(f.size())};
    }

    class IMPL(Renderer) {
    private:
        unsigned int vao, vbo, ebo;
        std::vector<Vertex> vertices;
        std::vector<unsigned int> indices;
        VertexAttributeBuilder vab;

        void init() {
            glGenVertexArrays(1, &vao);
            glGenBuffers(1, &vbo);
            glGenBuffers(1, &ebo);

            glBindVertexArray(vao);


            glVertexArray va = toGlArray(vertices);
            glBindBuffer(GL_ARRAY_BUFFER, vbo);
            glBufferData(GL_ARRAY_BUFFER, va.len*(int)sizeof(float), va.arr, GL_STATIC_DRAW);

            glVertexElementArray vb = toGlArray(indices);
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
            glBufferData(GL_ELEMENT_ARRAY_BUFFER, vb.len*(int)sizeof(float), vb.arr, GL_STATIC_DRAW);

            vab = VertexAttributeBuilder(3, 4, 2);
            vab.build();
        }
    public:
        IMPL(Renderer)() {
            vertices = {
                    VERTEX( 0.5, 0.5,0.0, 255.0,  0.0,0.0,255.0, 1.0,1.0),
                    VERTEX( 0.5,-0.5,0.0, 0.0,  255.0,0.0,255.0, 1.0,0.0),
                    VERTEX(-0.5,-0.5,0.0, 0.0,  0.0,255.0,255.0, 0.0,0.0),
                    VERTEX(-0.5, 0.5,0.0, 255.0,255.0,0.0,255.0, 0.0,1.0)
            };
            indices = {
                    0, 1, 3,
                    1, 2, 3
            };
            vao = 0;
            vbo = 0;
            ebo = 0;
            init();
        }

        void render() {
            vab.enable();
            glBindVertexArray(vao);
            glDrawElements(GL_TRIANGLES, (int)indices.size(), GL_UNSIGNED_INT, nullptr);
            glBindVertexArray(0);
            vab.disable();
        }

    };

    IMPL(Renderer)* implr(Renderer* v) {
        return reinterpret_cast<IMPL(Renderer)*>(v->getImplRenderer());
    }

    Renderer::Renderer() {
        m_impl = new IMPL(Renderer)();
    }

    void Renderer::render() {
        implr(this)->render();
    }

    void* Renderer::getImplRenderer() {
        return m_impl;
    }


}