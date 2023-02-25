#pragma once
#include "apiHeader.h"
#include "Vectors.h"
#include "Matrices.h"

namespace Engine {
    class Transform {
    public:
        Vector3f m_position;
        Vector3f m_rotation;
        Vector3f m_scale;

        Transform();
        Transform(const Vector3f &position, const Vector3f &rotation, const Vector3f &scale);
        Transform(const Transform &other);
        ~Transform();

        [[nodiscard]] Matrix4f getTransformationMatrix() const;

        void setPosition(const Vector3f &position);
        void setRotation(const Vector3f &rotation);
        void setScale(const Vector3f &scale);

        void translate(const Vector3f &translation);
        void rotate(const Vector3f &rotation);
        void scale(const Vector3f &scale);

    };
}