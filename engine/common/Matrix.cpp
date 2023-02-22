#include <API/Matrix.h>

#define MATTEMPL template<typename T, int N>

namespace Engine {
    MATTEMPL
    Matrix<T, N>::Matrix() { // default constructor is identity matrix
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                m_data[i][j] = 0;
                if (i == j) {
                    m_data[i][j] = 1;
                }
            }
        }
    }

    MATTEMPL
    Matrix<T, N>::Matrix(T value) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                m_data[i][j] = value;
            }
        }
    }

    MATTEMPL
    Matrix<T, N>::Matrix(T value[N][N]) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                m_data[i][j] = value[i][j];
            }
        }
    }

    MATTEMPL
    Matrix<T, N>::Matrix(const Matrix<T, N> &other) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                m_data[i][j] = other.m_data[i][j];
            }
        }
    }

    MATTEMPL
    Matrix<T, N>::Matrix(const std::initializer_list<T> &list) {
        int i = 0;
        int j = 0;
        for (auto &value : list) {
            m_data[i][j] = value;
            j++;
            if (j == N) {
                j = 0;
                i++;
            }
        }
    }

    MATTEMPL
    Matrix<T, N>::Matrix(const std::vector<T> &vector) {
        int i = 0;
        int j = 0;
        for (auto &value : vector) {
            m_data[i][j] = value;
            j++;
            if (j == N) {
                j = 0;
                i++;
            }
        }
    }

    MATTEMPL
    template <typename... Args>
    Matrix<T, N>::Matrix(Args... args) {
        int i = 0;
        int j = 0;
        for (auto &value : {args...}) {
            m_data[i][j] = value;
            j++;
            if (j == N) {
                j = 0;
                i++;
            }
        }
    }

    MATTEMPL
    Matrix<T, N>::~Matrix() = default;

    MATTEMPL
    Matrix<T, N> &Matrix<T, N>::add(const Matrix<T, N> &other) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                m_data[i][j] += other.m_data[i][j];
            }
        }
        return *this;
    }

    MATTEMPL
    Matrix<T, N> &Matrix<T, N>::subtract(const Matrix<T, N> &other) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                m_data[i][j] -= other.m_data[i][j];
            }
        }
        return *this;
    }

    MATTEMPL
    Matrix<T, N> &Matrix<T, N>::multiply(const Matrix<T, N> &other) {
        Matrix<T, N> result;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                for (int k = 0; k < N; k++) {
                    result.m_data[i][j] += m_data[i][k] * other.m_data[k][j];
                }
            }
        }
        *this = result;
        return *this;
    }

    MATTEMPL
    Matrix<T, N> &Matrix<T, N>::divide(const Matrix<T, N> &other) {
        Matrix<T, N> result;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                result.m_data[i][j] = m_data[i][j] / other.m_data[i][j];
            }
        }
        *this = result;
        return *this;
    }

    MATTEMPL
    Matrix<T, N> &Matrix<T, N>::operator+=(const Matrix<T, N> &other) {
        return add(other);
    }

    MATTEMPL
    Matrix<T, N> &Matrix<T, N>::operator-=(const Matrix<T, N> &other) {
        return subtract(other);
    }

    MATTEMPL
    Matrix<T, N> &Matrix<T, N>::operator*=(const Matrix<T, N> &other) {
        return multiply(other);
    }

    MATTEMPL
    Matrix<T, N> &Matrix<T, N>::operator/=(const Matrix<T, N> &other) {
        return divide(other);
    }

    MATTEMPL
    Matrix<T, N> &Matrix<T, N>::operator=(const Matrix<T, N> &other) {
        if (this == &other) {
            return *this;
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                m_data[i][j] = other.m_data[i][j];
            }
        }
        return *this;
    }

    MATTEMPL
    Matrix<T, N> &Matrix<T, N>::operator=(const std::initializer_list<T> &list) {
        int i = 0;
        int j = 0;
        for (auto &value : list) {
            m_data[i][j] = value;
            j++;
            if (j == N) {
                j = 0;
                i++;
            }
        }
        return *this;
    }

    MATTEMPL
    Matrix<T, N> &Matrix<T, N>::operator=(const std::vector<T> &vector) {
        int i = 0;
        int j = 0;
        for (auto &value : vector) {
            m_data[i][j] = value;
            j++;
            if (j == N) {
                j = 0;
                i++;
            }
        }
        return *this;
    }

    template<typename T, int N>
    T* Matrix<T, N>::elements() {
        // make a 1 dimensional array of the elements
        T* elements = new T[N * N];
        int i = 0;
        for (int x = 0; x < N; x++) {
            for (int y = 0; y < N; y++) {
                elements[i] = m_data[x][y];
                i++;
            }
        }
        return elements;
    }

    MATTEMPL
    Matrix<T, N> &Matrix<T, N>::add(T value) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                m_data[i][j] += value;
            }
        }
        return *this;
    }

    MATTEMPL
    Matrix<T, N> &Matrix<T, N>::subtract(T value) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                m_data[i][j] -= value;
            }
        }
        return *this;
    }

    MATTEMPL
    Matrix<T, N> &Matrix<T, N>::multiply(T value) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                m_data[i][j] *= value;
            }
        }
        return *this;
    }

    MATTEMPL
    Matrix<T, N> &Matrix<T, N>::divide(T value) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                m_data[i][j] /= value;
            }
        }
        return *this;
    }

    MATTEMPL
    Matrix<T, N> &Matrix<T, N>::operator+=(T value) {
        return add(value);
    }

    MATTEMPL
    Matrix<T, N> &Matrix<T, N>::operator-=(T value) {
        return subtract(value);
    }

    MATTEMPL
    Matrix<T, N> &Matrix<T, N>::operator*=(T value) {
        return multiply(value);
    }

    MATTEMPL
    Matrix<T, N> &Matrix<T, N>::operator/=(T value) {
        return divide(value);
    }

    MATTEMPL
    bool Matrix<T, N>::operator==(const Matrix<T, N> &other) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (m_data[i][j] != other.m_data[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }

    MATTEMPL
    bool Matrix<T, N>::operator!=(const Matrix<T, N> &other) {
        return !(this->operator==(other));
    }

    MATTEMPL
    Matrix<T, N> &Matrix<T, N>::operator=(T value) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                m_data[i][j] = value;
            }
        }
        return *this;
    }

    MATTEMPL
    Matrix<T, N> &Matrix<T, N>::operator=(const T data[N*N]) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                m_data[i][j] = data[i * N + j];
            }
        }
        return *this;
    }

    MATTEMPL
    Matrix<T, N> &Matrix<T, N>::operator=(const T data[N][N]) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                m_data[i][j] = data[i][j];
            }
        }
        return *this;
    }








}

#undef MATTEMPL