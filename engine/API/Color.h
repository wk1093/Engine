#pragma once
#include "apiHeader.h"

#include "Vector.h"


namespace Engine {
    class Color : public Vector<uint8_t, 4> {
    public:

        Color();

        Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a = 255);

        explicit Color(const Vector<uint8_t, 4> &v);

        Color(const Color &c);

        [[nodiscard]] uint8_t r() const;

        [[nodiscard]] uint8_t g() const;

        [[nodiscard]] uint8_t b() const;

        [[nodiscard]] uint8_t a() const;

        void r(uint8_t r);

        void g(uint8_t g);

        void b(uint8_t b);

        void a(uint8_t a);
    };

    class Colors {
    public:
        static const Color Black;
        static const Color White;
        static const Color Red;
        static const Color Green;
        static const Color Blue;
        static const Color Yellow;
        static const Color Cyan;
        static const Color Magenta;
        static const Color Transparent;
    };
}