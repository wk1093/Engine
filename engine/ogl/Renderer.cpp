#include "oglHeader.h"
#include <API/Renderer.h>

#include "VertexAttributeBuilder.h"

#define VERTEX(x,y,z,r,g,b,a,u,v) Vertex(Vector3f(x,y,z),Vector2f(u,v),Color(r,g,b,a))

namespace Engine {

    struct glVertexArray {
        float* arr;
        int len;
    };
    struct glVertexElementArray {
        unsigned int* arr;
        int len;
    };

    glVertexArray toGlArray(const std::vector<Vertex>& v) {
        auto* f = new float[v.size()*Vertex::size()];
        for (int i = 0; i < v.size(); i++) {
            float* fs = v[i].glVertex();
            for (int j = 0; j < Vertex::size(); j++) {
                f[i*Vertex::size()+j] = fs[j];
            }
        }
        return glVertexArray{f, int(v.size()*Vertex::size())};
    }
    glVertexElementArray toGlArray(const std::vector<unsigned int>& v) {
        auto* f = new unsigned int[v.size()];
        for (int i = 0; i < v.size(); i++) {
            f[i] = v[i];
        }
        return glVertexElementArray{f, int(v.size())};
    }

    class IMPL(Renderer) {
    private:
        unsigned int vao, vbo, ebo;
        Mesh m;
        VertexAttributeBuilder vab;

        void init() {
            glGenVertexArrays(1, &vao);
            glGenBuffers(1, &vbo);
            glGenBuffers(1, &ebo);

            glBindVertexArray(vao);

            glVertexArray va = toGlArray(m.vertices);
            glBindBuffer(GL_ARRAY_BUFFER, vbo);
            glBufferData(GL_ARRAY_BUFFER, va.len*(int)sizeof(float), va.arr, GL_STATIC_DRAW);

            glVertexElementArray vb = toGlArray(m.indices);
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
            glBufferData(GL_ELEMENT_ARRAY_BUFFER, vb.len*(int)sizeof(float), vb.arr, GL_STATIC_DRAW);

            vab = VertexAttributeBuilder(Vertex::glVertexSize());
            vab.build();

            glBindBuffer(GL_ARRAY_BUFFER, 0);
            glBindVertexArray(0);
        }
    public:
        IMPL(Renderer)() {
            m = Mesh(
                    {
                            VERTEX( 0.5, 0.5,0.0, 255.0,  0.0,0.0,255.0, 1.0,1.0),
                            VERTEX( 0.5,-0.5,0.0, 0.0,  255.0,0.0,255.0, 1.0,0.0),
                            VERTEX(-0.5,-0.5,0.0, 0.0,  0.0,255.0,255.0, 0.0,0.0),
                            VERTEX(-0.5, 0.5,0.0, 255.0,255.0,0.0,255.0, 0.0,1.0)
                    },
                    m.indices = {
                            0, 1, 3,
                            1, 2, 3
                    });
            vao = 0;
            vbo = 0;
            ebo = 0;
            init();
        }

        IMPL(Renderer)(const Mesh& mesh, const std::string& texPath) {
            m = mesh;
            vao = 0;
            vbo = 0;
            ebo = 0;
            init();
        }

        void render() {
            vab.enable();
            glBindVertexArray(vao);
            glDrawElements(GL_TRIANGLES, (int)m.indices.size(), GL_UNSIGNED_INT, nullptr);
            vab.disable();
        }

    };

    IMPL(Renderer)* implr(Renderer* v) {
        return reinterpret_cast<IMPL(Renderer)*>(v->getImplRenderer());
    }

    Renderer::Renderer() {
        m_impl = new IMPL(Renderer)();
    }

    Renderer::Renderer(const Mesh& mesh, const std::string& texPath) {
        m_impl = new IMPL(Renderer)(mesh, texPath);
    }

    void Renderer::render() {
        implr(this)->render();
    }

    void* Renderer::getImplRenderer() {
        return m_impl;
    }


}