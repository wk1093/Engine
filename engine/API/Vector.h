#pragma once
#include <API/engineHeader.h>

namespace Engine {
    template<typename T, int N>
    class Vector {
    public:
        Vector();

        explicit Vector(T value);

        explicit Vector(T value[N]);

        Vector(const Vector<T, N> &other);

        Vector(const std::initializer_list<T> &list);

        explicit Vector(const std::vector<T> &vector);

        template <typename... Args>
        explicit Vector(Args... args);

        virtual ~Vector();

        Vector<T, N> &add(const Vector<T, N> &other);

        Vector<T, N> &subtract(const Vector<T, N> &other);

        Vector<T, N> &multiply(const Vector<T, N> &other);

        Vector<T, N> &divide(const Vector<T, N> &other);

        Vector<T, N> &add(T value);

        Vector<T, N> &subtract(T value);

        Vector<T, N> &multiply(T value);

        Vector<T, N> &divide(T value);

        Vector<T, N> &operator+=(const Vector<T, N> &other);

        Vector<T, N> &operator-=(const Vector<T, N> &other);

        Vector<T, N> &operator*=(const Vector<T, N> &other);

        Vector<T, N> &operator/=(const Vector<T, N> &other);

        Vector<T, N> &operator+=(T value);

        Vector<T, N> &operator-=(T value);

        Vector<T, N> &operator*=(T value);

        Vector<T, N> &operator/=(T value);

        bool operator==(const Vector<T, N> &other);

        bool operator!=(const Vector<T, N> &other);

        Vector<T, N> operator+(const Vector<T, N> &other) const;

        Vector<T, N> operator-(const Vector<T, N> &other) const;

        Vector<T, N> operator*(const Vector<T, N> &other) const;

        Vector<T, N> operator/(const Vector<T, N> &other) const;

        Vector<T, N> operator+(T value) const;

        Vector<T, N> operator-(T value) const;

        Vector<T, N> operator*(T value) const;

        Vector<T, N> operator/(T value) const;

        T &operator[](int index);

        T operator[](int index) const;

        T &get(int index);

        T get(int index) const;

        void set(int index, T value);

        T *getPointer();

        const T *getPointer() const;

        T *getPointer(int index);

        const T *getPointer(int index) const;

        T *begin();

        const T *begin() const;

        T *end();

        const T *end() const;

        [[nodiscard]] int getSize() const;

        [[nodiscard]] std::string toString() const;

        T length() const;

        T lengthSquared() const;

        static Vector<T, N> zero();

        static Vector<T, N> one();

        static Vector<T, N> up();

        static Vector<T, N> down();

        static Vector<T, N> left();

        static Vector<T, N> right();

        static Vector<T, N> forward();

        static Vector<T, N> backward();

        static Vector<T, N> random();

        static Vector<T, N> min(const Vector<T, N> &a, const Vector<T, N> &b);

        static Vector<T, N> max(const Vector<T, N> &a, const Vector<T, N> &b);

        static Vector<T, N> clampVector(const Vector<T, N> &value, const Vector<T, N> &min, const Vector<T, N> &max);

        static Vector<T, N> lerp(const Vector<T, N> &a, const Vector<T, N> &b, T t);

        static Vector<T, N> lerpUnclamped(const Vector<T, N> &a, const Vector<T, N> &b, T t);

        static Vector<T, N> moveTowards(const Vector<T, N> &current, const Vector<T, N> &target, T maxDistanceDelta);

        static Vector<T, N>
        smoothDamp(const Vector<T, N> &current, const Vector<T, N> &target, Vector<T, N> &currentVelocity, T smoothTime,
                   T maxSpeed, T deltaTime);

        static Vector<T, N>
        smoothDamp(const Vector<T, N> &current, const Vector<T, N> &target, Vector<T, N> &currentVelocity, T smoothTime,
                   T maxSpeed);

    private:
        T* m_data;
    };
}

// fix problems with the undefined reference to `Engine::Vector<int, 2>::Vector()'
// and the undefined reference to `Engine::Vector<int, 2>::~Vector()'

template class Engine::Vector<char, 2>;
template class Engine::Vector<unsigned char, 2>;
template class Engine::Vector<int, 2>;
template class Engine::Vector<unsigned int, 2>;
template class Engine::Vector<float, 2>;
template class Engine::Vector<double, 2>;
template class Engine::Vector<char, 3>;
template class Engine::Vector<unsigned char, 3>;
template class Engine::Vector<int, 3>;
template class Engine::Vector<unsigned int, 3>;
template class Engine::Vector<float, 3>;
template class Engine::Vector<double, 3>;
template class Engine::Vector<char, 4>;
template class Engine::Vector<unsigned char, 4>;
template class Engine::Vector<int, 4>;
template class Engine::Vector<unsigned int, 4>;
template class Engine::Vector<float, 4>;
template class Engine::Vector<double, 4>;