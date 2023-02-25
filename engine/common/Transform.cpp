#include <API/Transform.h>

namespace Engine {
    Transform::Transform() : m_position(Vector3f(0, 0, 0)), m_rotation(Vector3f(0, 0, 0)), m_scale(Vector3f(1, 1, 1)) {}
    Transform::Transform(const Vector3f &position, const Vector3f &rotation, const Vector3f &scale) : m_position(position), m_rotation(rotation), m_scale(scale) {}
    Transform::Transform(const Transform &other) : m_position(other.m_position), m_rotation(other.m_rotation), m_scale(other.m_scale) {}
    Transform::~Transform() {
        delete &m_position;
        delete &m_rotation;
        delete &m_scale;
    }

    Matrix4f Transform::getTransformationMatrix() const {
        Matrix4f translationMatrix = Matrix4f(
            1, 0, 0, m_position.x,
            0, 1, 0, m_position.y,
            0, 0, 1, m_position.z,
            0, 0, 0, 1
        );

        Matrix4f rotationMatrix = Matrix4f(
            cos(m_rotation.y) * cos(m_rotation.z), cos(m_rotation.z) * sin(m_rotation.x) * sin(m_rotation.y) - cos(m_rotation.x) * sin(m_rotation.z), sin(m_rotation.x) * sin(m_rotation.z) + cos(m_rotation.x) * cos(m_rotation.z) * sin(m_rotation.y), 0,
            cos(m_rotation.y) * sin(m_rotation.z), cos(m_rotation.x) * cos(m_rotation.z) + sin(m_rotation.x) * sin(m_rotation.y) * sin(m_rotation.z), cos(m_rotation.x) * sin(m_rotation.y) * sin(m_rotation.z) - cos(m_rotation.z) * sin(m_rotation.x), 0,
            -sin(m_rotation.y), cos(m_rotation.y) * sin(m_rotation.x), cos(m_rotation.x) * cos(m_rotation.y), 0,
            0, 0, 0, 1
        );

        Matrix4f scaleMatrix = Matrix4f(
            m_scale.x, 0, 0, 0,
            0, m_scale.y, 0, 0,
            0, 0, m_scale.z, 0,
            0, 0, 0, 1
        );

        return translationMatrix * rotationMatrix * scaleMatrix;
    }

    void Transform::setPosition(const Vector3f &position) {
        m_position = position;
    }

    void Transform::setRotation(const Vector3f &rotation) {
        m_rotation = rotation;
    }

    void Transform::setScale(const Vector3f &scale) {
        m_scale = scale;
    }

    void Transform::translate(const Vector3f &translation) {
        m_position += translation;
    }

    void Transform::rotate(const Vector3f &rotation) {
        m_rotation += rotation;
    }

    void Transform::scale(const Vector3f &scale) {
        m_scale += scale;
    }


}