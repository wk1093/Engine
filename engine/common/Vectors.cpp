#include <API/Vectors.h>

namespace Engine {
    Vector2i::Vector2i() : Vector<int, 2>() {}

    Vector2i::Vector2i(int x, int y) : Vector<int, 2>(new int[] {x, y}) {}

    Vector2i::Vector2i(int value) : Vector<int, 2>(new int[] {value, value}) {}

    int Vector2i::x() const { return (*this)[0]; }
    int Vector2i::y() const { return (*this)[1]; }

    void Vector2i::setX(int x) { (*this)[0] = x; }
    void Vector2i::setY(int y) { (*this)[1] = y; }

    void Vector2i::set(int x, int y) {
        setX(x);
        setY(y);
    }

    Vector3i::Vector3i() : Vector<int, 3>() {}

    Vector3i::Vector3i(int x, int y, int z) : Vector<int, 3>(new int[] {x, y, z}) {}

    Vector3i::Vector3i(int value) : Vector<int, 3>(new int[] {value, value, value}) {}

    int Vector3i::x() const { return (*this)[0]; }
    int Vector3i::y() const { return (*this)[1]; }
    int Vector3i::z() const { return (*this)[2]; }

    void Vector3i::setX(int x) { (*this)[0] = x; }
    void Vector3i::setY(int y) { (*this)[1] = y; }
    void Vector3i::setZ(int z) { (*this)[2] = z; }

    void Vector3i::set(int x, int y, int z) {
        setX(x);
        setY(y);
        setZ(z);
    }

    Vector4i::Vector4i() : Vector<int, 4>() {}

    Vector4i::Vector4i(int x, int y, int z, int w) : Vector<int, 4>(new int[] {x, y, z, w}) {}

    Vector4i::Vector4i(int value) : Vector<int, 4>(new int[] {value, value, value}) {}

    int Vector4i::x() const { return (*this)[0]; }
    int Vector4i::y() const { return (*this)[1]; }
    int Vector4i::z() const { return (*this)[2]; }
    int Vector4i::w() const { return (*this)[3]; }

    void Vector4i::setX(int x) { (*this)[0] = x; }
    void Vector4i::setY(int y) { (*this)[1] = y; }
    void Vector4i::setZ(int z) { (*this)[2] = z; }
    void Vector4i::setW(int w) { (*this)[3] = w; }

    void Vector4i::set(int x, int y, int z, int w) {
        setX(x);
        setY(y);
        setZ(z);
        setW(w);
    }

    Vector2f::Vector2f() : Vector<float, 2>() {}

    Vector2f::Vector2f(float x, float y) : Vector<float, 2>(new float[] {x, y}) {}

    Vector2f::Vector2f(float value) : Vector<float, 2>(new float[] {value, value}) {}

    float Vector2f::x() const { return (*this)[0]; }
    float Vector2f::y() const { return (*this)[1]; }

    void Vector2f::setX(float x) { (*this)[0] = x; }
    void Vector2f::setY(float y) { (*this)[1] = y; }

    void Vector2f::set(float x, float y) {
        setX(x);
        setY(y);
    }

    Vector3f::Vector3f() : Vector<float, 3>() {}

    Vector3f::Vector3f(float x, float y, float z) : Vector<float, 3>({x, y, z}) {}

    Vector3f::Vector3f(float value) : Vector<float, 3>(new float[] {value, value, value}) {}

    float Vector3f::x() const { return (*this)[0]; }
    float Vector3f::y() const { return (*this)[1]; }
    float Vector3f::z() const { return (*this)[2]; }

    void Vector3f::setX(float x) { (*this)[0] = x; }
    void Vector3f::setY(float y) { (*this)[1] = y; }
    void Vector3f::setZ(float z) { (*this)[2] = z; }

    void Vector3f::set(float x, float y, float z) {
        setX(x);
        setY(y);
        setZ(z);
    }

    Vector4f::Vector4f() : Vector<float, 4>() {}

    Vector4f::Vector4f(float x, float y, float z, float w) : Vector<float, 4>(new float[] {x, y, z, w}) {}

    Vector4f::Vector4f(float value) : Vector<float, 4>(new float[] {value, value, value}) {}

    float Vector4f::x() const { return (*this)[0]; }
    float Vector4f::y() const { return (*this)[1]; }
    float Vector4f::z() const { return (*this)[2]; }
    float Vector4f::w() const { return (*this)[3]; }

    void Vector4f::setX(float x) { (*this)[0] = x; }
    void Vector4f::setY(float y) { (*this)[1] = y; }
    void Vector4f::setZ(float z) { (*this)[2] = z; }
    void Vector4f::setW(float w) { (*this)[3] = w; }

    void Vector4f::set(float x, float y, float z, float w) {
        setX(x);
        setY(y);
        setZ(z);
        setW(w);
    }
}