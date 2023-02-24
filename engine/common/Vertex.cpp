#include <API/Vertex.h>

namespace Engine {
    Vertex::Vertex() : pos(Vector3f()), tex(Vector2f()), col(Color()), norm(Vector3f()) {}
    Vertex::Vertex(const Vector3f& pos) : pos(pos), tex(Vector2f()), col(Color()), norm(Vector3f()) {}
    Vertex::Vertex(const Vector3f& pos, const Color& col) : pos(pos), tex(Vector2f()), col(col), norm(Vector3f()) {}
    Vertex::Vertex(const Vector3f& pos, const Vector2f& tex) : pos(pos), tex(tex), col(Color()), norm(Vector3f()) {}
    Vertex::Vertex(const Vector3f& pos, const Vector2f& tex, const Color& col) : pos(pos), tex(tex), col(col), norm(Vector3f()) {}
    Vertex::Vertex(const Vector3f& pos, const Vector2f& tex, const Vector3f& norm, const Color& col) : pos(pos), tex(tex), col(col), norm(norm) {}

    int Vertex::size() {
        return 3 + 2 + 4 + 0; // posx, posy, posz, texx, texy, colr, colg, colb, cola, normx, normy, normz TODO: add normals
    }

    float* Vertex::glVertex() const {
        return new float[Vertex::size()] {
                pos.x, pos.y, pos.z,
                (float)col.r()/255.0f, (float)col.g()/255.0f, (float)col.b()/255.0f, (float)col.a()/255.0f,
                tex.x, tex.y,
                //norm.x, norm.y, norm.z
        };
    }

    bool Vertex::operator==(const Vertex& other) const {
        return pos == other.pos && tex == other.tex && col == other.col && norm == other.norm;
    }


}