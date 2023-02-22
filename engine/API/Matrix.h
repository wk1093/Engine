#pragma once
#include "apiHeader.h"

namespace Engine {
    template<typename T, int N>
    class Matrix {
        // Matrices are always square

    public:
        Matrix();

        explicit Matrix(T value);

        explicit Matrix(T value[N][N]);

        Matrix(const Matrix<T, N> &other);

        Matrix(const std::initializer_list<T> &list);

        explicit Matrix(const std::vector<T> &vector);

        template <typename... Args>
        explicit Matrix(Args... args);

        virtual ~Matrix();

        Matrix<T, N> &add(const Matrix<T, N> &other);

        Matrix<T, N> &subtract(const Matrix<T, N> &other);

        Matrix<T, N> &multiply(const Matrix<T, N> &other);

        Matrix<T, N> &divide(const Matrix<T, N> &other);

        Matrix<T, N> &add(T value);

        Matrix<T, N> &subtract(T value);

        Matrix<T, N> &multiply(T value);

        Matrix<T, N> &divide(T value);

        Matrix<T, N> &operator+=(const Matrix<T, N> &other);

        Matrix<T, N> &operator-=(const Matrix<T, N> &other);

        Matrix<T, N> &operator*=(const Matrix<T, N> &other);

        Matrix<T, N> &operator/=(const Matrix<T, N> &other);

        Matrix<T, N> &operator+=(T value);

        Matrix<T, N> &operator-=(T value);

        Matrix<T, N> &operator*=(T value);

        Matrix<T, N> &operator/=(T value);

        bool operator==(const Matrix<T, N> &other);

        bool operator!=(const Matrix<T, N> &other);

        Matrix<T, N> &operator=(const Matrix<T, N> &other);

        Matrix<T, N> &operator=(const std::initializer_list<T> &list);

        Matrix<T, N> &operator=(const std::vector<T> &vector);

        Matrix<T, N> &operator=(const T value[N][N]);

        Matrix<T, N> &operator=(T value);

        Matrix<T, N> &operator=(const T value[N*N]);

        T* elements();

    private:
        T m_data[N][N];
    };

    template class Matrix<float, 4>;
}