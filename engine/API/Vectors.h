#pragma once
#include "apiHeader.h"
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

        void set(int x, int y);
    };
    class Vector3i : public Vector<int, 3> {
    public:
        Vector3i();

        Vector3i(int x, int y, int z);

        explicit Vector3i(int value);

        [[nodiscard]] int x() const;
        [[nodiscard]] int y() const;
        [[nodiscard]] int z() const;

        void setX(int x);
        void setY(int y);
        void setZ(int z);

        void set(int x, int y, int z);
    };
    class Vector4i : public Vector<int, 4> {
    public:
        Vector4i();

        Vector4i(int x, int y, int z, int w);

        explicit Vector4i(int value);

        [[nodiscard]] int x() const;
        [[nodiscard]] int y() const;
        [[nodiscard]] int z() const;
        [[nodiscard]] int w() const;

        void setX(int x);
        void setY(int y);
        void setZ(int z);
        void setW(int w);

        void set(int x, int y, int z, int w);
    };
    class Vector2f : public Vector<float, 2> {
    public:
        Vector2f();

        Vector2f(float x, float y);

        explicit Vector2f(float value);

        [[nodiscard]] float x() const;
        [[nodiscard]] float y() const;

        void setX(float x);
        void setY(float y);

        void set(float x, float y);
    };
    class Vector3f : public Vector<float, 3> {
    public:
        Vector3f();

        Vector3f(float x, float y, float z);

        explicit Vector3f(float value);

        [[nodiscard]] float x() const;
        [[nodiscard]] float y() const;
        [[nodiscard]] float z() const;

        void setX(float x);
        void setY(float y);
        void setZ(float z);

        void set(float x, float y, float z);
    };
    class Vector4f : public Vector<float, 4> {
    public:
        Vector4f();

        Vector4f(float x, float y, float z, float w);

        explicit Vector4f(float value);

        [[nodiscard]] float x() const;
        [[nodiscard]] float y() const;
        [[nodiscard]] float z() const;
        [[nodiscard]] float w() const;

        void setX(float x);
        void setY(float y);
        void setZ(float z);
        void setW(float w);

        void set(float x, float y, float z, float w);
    };
}