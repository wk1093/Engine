#pragma once
#include <API/engineHeader.h>

#include "Vector.h"
namespace Engine {
    class Vector2i : public Vector<int, 2> {
    public:
        Vector2i();

        Vector2i(int x, int y);

        explicit Vector2i(int value);

        [[nodiscard]] int x() const;

        [[nodiscard]] int y() const;

        void setX(int x);

        void setY(int y);
    };
}