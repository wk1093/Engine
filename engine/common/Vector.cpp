#include <API/Vector.h>
// Implementation of the Vector class.

namespace Engine {
    template<typename T, int N>
    Vector<T, N>::Vector() {
        m_data = new T[N];
    }

    template<typename T, int N>
    Vector<T, N>::Vector(T value) {
        m_data = new T[N];
        for (int i = 0; i < N; i++) {
            m_data[i] = value;
        }
    }

    template<typename T, int N>
    Vector<T, N>::Vector(T value[N]) {
        m_data = new T[N];
        for (int i = 0; i < N; i++) {
            m_data[i] = value[i];
        }
    }

    template<typename T, int N>
    Vector<T, N>::Vector(const Vector<T, N> &other) {
        m_data = new T[N];
        for (int i = 0; i < N; i++) {
            m_data[i] = other.m_data[i];
        }
    }

    template<typename T, int N>
    Vector<T, N>::Vector(const std::initializer_list<T> &list) {
        m_data = new T[N];
        int i = 0;
        for (auto value : list) {
            m_data[i] = value;
            i++;
        }
    }

    template<typename T, int N>
    Vector<T, N>::Vector(const std::vector<T> &vector) {
        m_data = new T[N];
        for (int i = 0; i < N; i++) {
            m_data[i] = vector[i];
        }
    }

    template<typename T, int N>
    template <class... Args>
    Vector<T, N>::Vector(Args... args) {
        // Vector<int, 2> v(1, 2) acts as v(new int[2]{1, 2});
        m_data = new T[N]{args...};

    }

    template<typename T, int N>
    Vector<T, N>::~Vector() {
        delete[] m_data;
    }

    template<typename T, int N>
    Vector<T, N> &Vector<T, N>::add(const Vector<T, N> &other) {
        for (int i = 0; i < N; i++) {
            m_data[i] += other.m_data[i];
        }
        return *this;
    }

    template<typename T, int N>
    Vector<T, N> &Vector<T, N>::subtract(const Vector<T, N> &other) {
        for (int i = 0; i < N; i++) {
            m_data[i] -= other.m_data[i];
        }
        return *this;
    }

    template<typename T, int N>
    Vector<T, N> &Vector<T, N>::multiply(const Vector<T, N> &other) {
        for (int i = 0; i < N; i++) {
            m_data[i] *= other.m_data[i];
        }
        return *this;
    }

    template<typename T, int N>
    Vector<T, N> &Vector<T, N>::divide(const Vector<T, N> &other) {
        for (int i = 0; i < N; i++) {
            m_data[i] /= other.m_data[i];
        }
        return *this;
    }

    template<typename T, int N>
    Vector<T, N> &Vector<T, N>::add(T value) {
        for (int i = 0; i < N; i++) {
            m_data[i] += value;
        }
        return *this;
    }

    template<typename T, int N>
    Vector<T, N> &Vector<T, N>::subtract(T value) {
        for (int i = 0; i < N; i++) {
            m_data[i] -= value;
        }
        return *this;
    }

    template<typename T, int N>
    Vector<T, N> &Vector<T, N>::multiply(T value) {
        for (int i = 0; i < N; i++) {
            m_data[i] *= value;
        }
        return *this;
    }

    template<typename T, int N>
    Vector<T, N> &Vector<T, N>::divide(T value) {
        for (int i = 0; i < N; i++) {
            m_data[i] /= value;
        }
        return *this;
    }

    template<typename T, int N>
    Vector<T, N> &Vector<T, N>::operator+=(const Vector<T, N> &other) {
        return add(other);
    }

    template<typename T, int N>
    Vector<T, N> &Vector<T, N>::operator-=(const Vector<T, N> &other) {
        return subtract(other);
    }

    template<typename T, int N>
    Vector<T, N> &Vector<T, N>::operator*=(const Vector<T, N> &other) {
        return multiply(other);
    }

    template<typename T, int N>
    Vector<T, N> &Vector<T, N>::operator/=(const Vector<T, N> &other) {
        return divide(other);
    }

    template<typename T, int N>
    Vector<T, N> &Vector<T, N>::operator+=(T value) {
        return add(value);
    }

    template<typename T, int N>
    Vector<T, N> &Vector<T, N>::operator-=(T value) {
        return subtract(value);
    }

    template<typename T, int N>
    Vector<T, N> &Vector<T, N>::operator*=(T value) {
        return multiply(value);
    }

    template<typename T, int N>
    Vector<T, N> &Vector<T, N>::operator/=(T value) {
        return divide(value);
    }

    template<typename T, int N>
    bool Vector<T, N>::operator==(const Vector<T, N> &other) {
        for (int i = 0; i < N; i++) {
            if (m_data[i] != other.m_data[i]) {
                return false;
            }
        }
        return true;
    }

    template<typename T, int N>
    bool Vector<T, N>::operator!=(const Vector<T, N> &other) {
        return *this != other;
    }

    template<typename T, int N>
    Vector<T, N> Vector<T, N>::operator+(const Vector<T, N> &other) const {
        Vector<T, N> result(*this);
        return result.add(other);
    }

    template<typename T, int N>
    Vector<T, N> Vector<T, N>::operator-(const Vector<T, N> &other) const {
        Vector<T, N> result(*this);
        return result.subtract(other);
    }

    template<typename T, int N>
    Vector<T, N> Vector<T, N>::operator*(const Vector<T, N> &other) const {
        Vector<T, N> result(*this);
        return result.multiply(other);
    }

    template<typename T, int N>
    Vector<T, N> Vector<T, N>::operator/(const Vector<T, N> &other) const {
        Vector<T, N> result(*this);
        return result.divide(other);
    }

    template<typename T, int N>
    Vector<T, N> Vector<T, N>::operator+(T value) const {
        Vector<T, N> result(*this);
        return result.add(value);
    }

    template<typename T, int N>
    Vector<T, N> Vector<T, N>::operator-(T value) const {
        Vector<T, N> result(*this);
        return result.subtract(value);
    }

    template<typename T, int N>
    Vector<T, N> Vector<T, N>::operator*(T value) const {
        Vector<T, N> result(*this);
        return result.multiply(value);
    }

    template<typename T, int N>
    Vector<T, N> Vector<T, N>::operator/(T value) const {
        Vector<T, N> result(*this);
        return result.divide(value);
    }

    template<typename T, int N>
    T &Vector<T, N>::operator[](int index) {
        return m_data[index];
    }

    template<typename T, int N>
    T Vector<T, N>::operator[](int index) const {
        return m_data[index];
    }

    template<typename T, int N>
    T& Vector<T, N>::get(int index) {
        return m_data[index];
    }

    template<typename T, int N>
    T Vector<T, N>::get(int index) const {
        return m_data[index];
    }

    template<typename T, int N>
    void Vector<T, N>::set(int index, T value) {
        m_data[index] = value;
    }

    template<typename T, int N>
    T* Vector<T, N>::getPointer() {
        return m_data;
    }

    template<typename T, int N>
    const T* Vector<T, N>::getPointer() const {
        return m_data;
    }

    template<typename T, int N>
    T* Vector<T, N>::begin() {
        return m_data;
    }

    template<typename T, int N>
    const T* Vector<T, N>::begin() const {
        return m_data;
    }

    template<typename T, int N>
    T* Vector<T, N>::end() {
        return m_data + N;
    }

    template<typename T, int N>
    const T* Vector<T, N>::end() const {
        return m_data + N;
    }

    template<typename T, int N>
    int Vector<T, N>::getSize() const {
        return N;
    }

    template<typename T, int N>
    T Vector<T, N>::length() const {
        T result = 0;
        for (int i = 0; i < N; i++) {
            result += m_data[i] * m_data[i];
        }
        return sqrt(result);
    }

    template<typename T, int N>
    T Vector<T, N>::lengthSquared() const {
        T result = 0;
        for (int i = 0; i < N; i++) {
            result += m_data[i] * m_data[i];
        }
        return result;
    }

    template<typename T, int N>
    T* Vector<T, N>::getPointer(int index) {
        return m_data + index;
    }

    template<typename T, int N>
    const T* Vector<T, N>::getPointer(int index) const {
        return m_data + index;
    }

    template<typename T, int N>
    std::string Vector<T, N>::toString() const {
        std::stringstream ss;
        ss << "(";
        for (int i = 0; i < N; i++) {
            ss << m_data[i];
            if (i < N - 1) {
                ss << ", ";
            }
        }
        ss << ")";
        return ss.str();
    }

    template<typename T, int N>
    Vector<T, N> Vector<T, N>::zero() {
        Vector<T, N> result;
        for (int i = 0; i < N; i++) {
            result.m_data[i] = 0;
        }
        return result;
    }

    template<typename T, int N>
    Vector<T, N> Vector<T, N>::one() {
        Vector<T, N> result;
        for (int i = 0; i < N; i++) {
            result.m_data[i] = 1;
        }
        return result;
    }

    template<typename T, int N>
    Vector<T, N> Vector<T, N>::up() {
        Vector<T, N> result;
        for (int i = 0; i < N; i++) {
            result.m_data[i] = 0;
        }
        result.m_data[1] = 1;
        return result;
    }

    template<typename T, int N>
    Vector<T, N> Vector<T, N>::down() {
        Vector<T, N> result;
        for (int i = 0; i < N; i++) {
            result.m_data[i] = 0;
        }
        result.m_data[1] = -1;
        return result;
    }

    template<typename T, int N>
    Vector<T, N> Vector<T, N>::left() {
        Vector<T, N> result;
        for (int i = 0; i < N; i++) {
            result.m_data[i] = 0;
        }
        result.m_data[0] = -1;
        return result;
    }

    template<typename T, int N>
    Vector<T, N> Vector<T, N>::right() {
        Vector<T, N> result;
        for (int i = 0; i < N; i++) {
            result.m_data[i] = 0;
        }
        result.m_data[0] = 1;
        return result;
    }

    template<typename T, int N>
    Vector<T, N> Vector<T, N>::forward() {
        Vector<T, N> result;
        for (int i = 0; i < N; i++) {
            result.m_data[i] = 0;
        }
        result.m_data[2] = -1;
        return result;
    }

    template<typename T, int N>
    Vector<T, N> Vector<T, N>::backward() {
        Vector<T, N> result;
        for (int i = 0; i < N; i++) {
            result.m_data[i] = 0;
        }
        result.m_data[2] = 1;
        return result;
    }

    template<typename T, int N>
    Vector<T, N> Vector<T, N>::random() {
        Vector<T, N> result;
        for (int i = 0; i < N; i++) {
            result.m_data[i] = (T)rand() / (T)RAND_MAX;
        }
        return result;
    }

    template<typename T, int N>
    Vector<T, N> Vector<T, N>::max(const Vector<T, N> &a, const Vector<T, N> &b) {
        Vector<T, N> result;
        for (int i = 0; i < N; i++) {
            result.m_data[i] = std::max(a.m_data[i], b.m_data[i]);
        }
        return result;
    }

    template<typename T, int N>
    Vector<T, N> Vector<T, N>::min(const Vector<T, N> &a, const Vector<T, N> &b) {
        Vector<T, N> result;
        for (int i = 0; i < N; i++) {
            result.m_data[i] = std::min(a.m_data[i], b.m_data[i]);
        }
        return result;
    }

    template<typename T, int N>
    Vector<T, N> Vector<T, N>::clampVector(const Vector<T, N> &value, const Vector<T, N> &min, const Vector<T, N> &max) {
        Vector<T, N> result;
        for (int i = 0; i < N; i++) {
            result.m_data[i] = std::min(std::max(value.m_data[i], min.m_data[i]), max.m_data[i]);
        }
        return result;
    }

    template<typename T, int N>
    Vector<T, N> Vector<T, N>::lerp(const Vector<T, N> &a, const Vector<T, N> &b, T t) {
        Vector<T, N> result;
        for (int i = 0; i < N; i++) {
            result.m_data[i] = a.m_data[i] + (b.m_data[i] - a.m_data[i]) * t;
        }
        return result;
    }

    template<typename T, int N>
    Vector<T, N> Vector<T, N>::lerpUnclamped(const Vector<T, N> &a, const Vector<T, N> &b, T t) {
        Vector<T, N> result;
        for (int i = 0; i < N; i++) {
            result.m_data[i] = a.m_data[i] + (b.m_data[i] - a.m_data[i]) * t;
        }
        return result;
    }

    template<typename T, int N>
    Vector<T, N> Vector<T, N>::moveTowards(const Vector<T, N> &current, const Vector<T, N> &target, T maxDistanceDelta) {
        Vector<T, N> result;
        for (int i = 0; i < N; i++) {
            // std::moveTowards doesn't exist in C++ so we have to do it ourselves
            T delta = target.m_data[i] - current.m_data[i];
            if (delta > maxDistanceDelta) {
                result.m_data[i] = current.m_data[i] + maxDistanceDelta;
            } else if (delta < -maxDistanceDelta) {
                result.m_data[i] = current.m_data[i] - maxDistanceDelta;
            } else {
                result.m_data[i] = target.m_data[i];
            }
        }
        return result;
    }

    template<typename T, int N>
    Vector<T, N> Vector<T, N>::smoothDamp(const Vector<T, N> &current, const Vector<T, N> &target, Vector<T, N> &currentVelocity, T smoothTime, T maxSpeed, T deltaTime) {
        Vector<T, N> result;
        for (int i = 0; i < N; i++) {
            // std::smoothDamp doesn't exist in C++ so we have to do it ourselves
            T omega = 2.0f / smoothTime;
            T x = omega * deltaTime;
            T exp = 1.0f / (1.0f + x + 0.48f * x * x + 0.235f * x * x * x);
            T change = current.m_data[i] - target.m_data[i];
            T originalTo = target.m_data[i];
            T maxChange = maxSpeed * smoothTime;
            change = std::clamp((int)change, -(int)maxChange, (int)maxChange);
            target.m_data[i] = current.m_data[i] - change;
            T temp = (currentVelocity.m_data[i] + omega * change) * deltaTime;
            currentVelocity.m_data[i] = (currentVelocity.m_data[i] - omega * temp) * exp;
            T output = target.m_data[i] + (change + temp) * exp;
            if (originalTo - current.m_data[i] > 0.0f == output > originalTo) {
                output = originalTo;
                currentVelocity.m_data[i] = (output - originalTo) / deltaTime;
            }
            result.m_data[i] = output;
        }
        return result;
    }

    template<typename T, int N>
    Vector<T, N> Vector<T, N>::smoothDamp(const Vector<T, N> &current, const Vector<T, N> &target, Vector<T, N> &currentVelocity, T smoothTime, T deltaTime) {
        Vector<T, N> result;
        for (int i = 0; i < N; i++) {
            // std::smoothDamp doesn't exist in C++ so we have to do it ourselves
            T omega = 2.0f / smoothTime;
            T x = omega * deltaTime;
            T exp = 1.0f / (1.0f + x + 0.48f * x * x + 0.235f * x * x * x);
            T change = current.m_data[i] - target.m_data[i];
            T originalTo = target.m_data[i];
            T maxChange = std::numeric_limits<T>::max();
            change = std::clamp((int)change, -(int)maxChange, (int)maxChange);
            target.m_data[i] = current.m_data[i] - change;
            T temp = (currentVelocity.m_data[i] + omega * change) * deltaTime;
            currentVelocity.m_data[i] = (currentVelocity.m_data[i] - omega * temp) * exp;
            T output = target.m_data[i] + (change + temp) * exp;
            if (originalTo - current.m_data[i] > 0.0f == output > originalTo) {
                output = originalTo;
                currentVelocity.m_data[i] = (output - originalTo) / deltaTime;
            }
            result.m_data[i] = output;
        }
        return result;
    }
}
