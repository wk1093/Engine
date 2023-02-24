#include <API/Color.h>

namespace Engine {
    Color::Color() {cr = cg = cb = ca = 0;}

    Color::Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
        cr = r;
        cg = g;
        cb = b;
        ca = a;
    }

    Color::Color(const Color &c) {
        cr = c.cr;
        cg = c.cg;
        cb = c.cb;
        ca = c.ca;
    }

    uint8_t Color::r() const {
        return cr;
    }

    uint8_t Color::g() const {
        return cg;
    }

    uint8_t Color::b() const {
        return cb;
    }

    uint8_t Color::a() const {
        return ca;
    }

    void Color::r(uint8_t r) {
        this->cr = r;
    }

    void Color::g(uint8_t g) {
        this->cg = g;
    }

    void Color::b(uint8_t b) {
        this->cb = b;
    }

    void Color::a(uint8_t a) {
        this->ca = a;
    }

    bool Color::operator==(const Color &c) const {
        return cr == c.cr && cg == c.cg && cb == c.cb && ca == c.ca;
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