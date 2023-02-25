#pragma once
#include "apiHeader.h"

#include "Vectors.h"
#include "Matrices.h"

namespace Engine {
    class Shader {
    private:
        void* m_impl; // implementation specific data

    public:
        Shader();
        Shader(const std::string &vertexShaderPath, const std::string &fragmentShaderPath); // paths to glsl (OpenGL), hlsl (DirectX) or spirv (Vulkan) files
        ~Shader();

        static std::string getShaderType(); // returns "glsl", "hlsl" or "spirv"

        void bind();
        void unbind();

        void setUniform1i(const std::string &name, int value);

        void setUniform2i(const std::string &name, int value1, int value2);
        void setUniform2i(const std::string &name, const int *value);
        void setUniform2i(const std::string &name, const Vector2i &value);

        void setUniform3i(const std::string &name, int value1, int value2, int value3);
        void setUniform3i(const std::string &name, const int *value);
        void setUniform3i(const std::string &name, const Vector3i &value);

        void setUniform4i(const std::string &name, int value1, int value2, int value3, int value4);
        void setUniform4i(const std::string &name, const int *value);
        void setUniform4i(const std::string &name, const Vector4i &value);

        void setUniform1f(const std::string &name, float value);

        void setUniform2f(const std::string &name, float value1, float value2);
        void setUniform2f(const std::string &name, const float *value);
        void setUniform2f(const std::string &name, const Vector2f &value);

        void setUniform3f(const std::string &name, float value1, float value2, float value3);
        void setUniform3f(const std::string &name, const float *value);
        void setUniform3f(const std::string &name, const Vector3f &value);

        void setUniform4f(const std::string &name, float value1, float value2, float value3, float value4);
        void setUniform4f(const std::string &name, const float *value);
        void setUniform4f(const std::string &name, const Vector4f &value);

        void setUniformMat4f(const std::string &name, const float *value);
        void setUniformMat4f(const std::string &name, const Matrix4f &value);

        void* getImplShader();
    };
}
