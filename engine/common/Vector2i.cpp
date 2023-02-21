#include <API/Vector2i.h>

namespace Engine {
    Vector2i::Vector2i() : Vector<int, 2>() {}

    Vector2i::Vector2i(int x, int y) : Vector<int, 2>(new int[] {x, y}) {}

    Vector2i::Vector2i(int value) : Vector<int, 2>(new int[] {value, value}) {}

    int Vector2i::x() const { return (*this)[0]; }

    int Vector2i::y() const { return (*this)[1]; }

    void Vector2i::setX(int x) { (*this)[0] = x; }

    void Vector2i::setY(int y) { (*this)[1] = y; }
}