#include <API/Transform.h>

namespace Engine {
    Transform::Transform() : m_position(Vector3f(0, 0, 0)), m_rotation(Vector3f(0, 0, 0)), m_scale(Vector3f(1, 1, 1)) {}
    Transform::Transform(const Vector3f &position, const Vector3f &rotation, const Vector3f &scale) : m_position(position), m_rotation(rotation), m_scale(scale) {}
    Transform::Transform(const Transform &other) = default;
    Transform::~Transform() = default;

    Matrix4f Transform::getTransformationMatrix() const {
        Matrix4f translationMatrix = glm::translate(m_position);
        Matrix4f rotationMatrix = glm::rotate(m_rotation.x, Vector3f(1, 0, 0)) * glm::rotate(m_rotation.y, Vector3f(0, 1, 0)) * glm::rotate(m_rotation.z, Vector3f(0, 0, 1));
        Matrix4f scaleMatrix = glm::scale(m_scale);
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