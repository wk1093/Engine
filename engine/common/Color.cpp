#include <API/Color.h>

namespace Engine {
    Color::Color() : Vector<uint8_t, 4>() {}

    Color::Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a) : Vector<uint8_t, 4>(new uint8_t[] {r, g, b, a}) {}

    Color::Color(const Vector<uint8_t, 4> &v) : Vector<uint8_t, 4>(v) {}

    Color::Color(const Color &c) : Vector<uint8_t, 4>(new uint8_t[] {c.r(), c.g(), c.b(), c.a()}) {}

    uint8_t Color::r() const {
        return (*this)[0];
    }

    uint8_t Color::g() const {
        return (*this)[1];
    }

    uint8_t Color::b() const {
        return (*this)[2];
    }

    uint8_t Color::a() const {
        return (*this)[3];
    }

    void Color::r(uint8_t r) {
        (*this)[0] = r;
    }

    void Color::g(uint8_t g) {
        (*this)[1] = g;
    }

    void Color::b(uint8_t b) {
        (*this)[2] = b;
    }

    void Color::a(uint8_t a) {
        (*this)[3] = a;
    }

    const Color Colors::Black = Color(0, 0, 0);
    const Color Colors::White = Color(255, 255, 255);
    const Color Colors::Red = Color(255, 0, 0);
    const Color Colors::Green = Color(0, 255, 0);
    const Color Colors::Blue = Color(0, 0, 255);
    const Color Colors::Yellow = Color(255, 255, 0);
    const Color Colors::Cyan = Color(0, 255, 255);
    const Color Colors::Magenta = Color(255, 0, 255);
    const Color Colors::Transparent = Color(0, 0, 0, 0);
}