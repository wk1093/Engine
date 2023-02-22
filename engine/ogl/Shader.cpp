#include "oglHeader.h"
#include <API/Shader.h>

namespace Engine {
    class OpenGLImplShader {
    private:
        unsigned int m_shaderID;

        static unsigned int compileShader(const std::string& source, unsigned int type) {
            unsigned int shader = glCreateShader(type);
            const char* src = source.c_str();
            glShaderSource(shader, 1, &src, nullptr);
            glCompileShader(shader);

            int result;
            glGetShaderiv(shader, GL_COMPILE_STATUS, &result);
            if (result == GL_FALSE) {
                int length;
                glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &length);
                char* message = (char*)alloca(length * sizeof(char));
                glGetShaderInfoLog(shader, length, &length, message);
                std::cout << "Failed to compile " << (type == GL_VERTEX_SHADER ? "vertex" : "fragment") << " shader!" << std::endl;
                std::cout << message << std::endl;
                glDeleteShader(shader);
                return 0;
            }

            return shader;
        }

        static unsigned int linkShader(unsigned int vertexShader, unsigned int fragmentShader) {
            unsigned int program = glCreateProgram();
            glAttachShader(program, vertexShader);
            glAttachShader(program, fragmentShader);
            glLinkProgram(program);
            glValidateProgram(program);

            glDeleteShader(vertexShader);
            glDeleteShader(fragmentShader);

            return program;
        }

    public:

        OpenGLImplShader(const std::string& vertexShader, const std::string& fragmentShader) {
            unsigned int vs = compileShader(vertexShader, GL_VERTEX_SHADER);
            unsigned int fs = compileShader(fragmentShader, GL_FRAGMENT_SHADER);
            m_shaderID = linkShader(vs, fs);
        }

        ~OpenGLImplShader() {
            glDeleteProgram(m_shaderID);
        }

        void bind() const {
            glUseProgram(m_shaderID);
        }

        void unbind() const {
            glUseProgram(0);
        }

        void setUniform1i(const std::string& name, int value) const {
            glUniform1i(glGetUniformLocation(m_shaderID, name.c_str()), value);
        }
        void setUniform2i(const std::string& name, const Vector2i& vector) const {
            glUniform2i(glGetUniformLocation(m_shaderID, name.c_str()), vector.x(), vector.y());
        }
        void setUniform3i(const std::string& name, const Vector3i& vector) const {
            glUniform3i(glGetUniformLocation(m_shaderID, name.c_str()), vector.x(), vector.y(), vector.z());
        }
        void setUniform4i(const std::string& name, const Vector4i& vector) const {
            glUniform4i(glGetUniformLocation(m_shaderID, name.c_str()), vector.x(), vector.y(), vector.z(), vector.w());
        }
        void setUniform1f(const std::string& name, float value) const {
            glUniform1f(glGetUniformLocation(m_shaderID, name.c_str()), value);
        }
        void setUniform2f(const std::string& name, const Vector2f& vector) const {
            glUniform2f(glGetUniformLocation(m_shaderID, name.c_str()), vector.x(), vector.y());
        }
        void setUniform3f(const std::string& name, const Vector3f& vector) const {
            glUniform3f(glGetUniformLocation(m_shaderID, name.c_str()), vector.x(), vector.y(), vector.z());
        }
        void setUniform4f(const std::string& name, const Vector4f& vector) const {
            glUniform4f(glGetUniformLocation(m_shaderID, name.c_str()), vector.x(), vector.y(), vector.z(), vector.w());
        }
        void setUniformMat4f(const std::string& name, Matrix4f matrix) const {
            glUniformMatrix4fv(glGetUniformLocation(m_shaderID, name.c_str()), 1, GL_FALSE, matrix.elements());
        }
        void setUniformMat4f(const std::string& name, const float* matrix) const {
            glUniformMatrix4fv(glGetUniformLocation(m_shaderID, name.c_str()), 1, GL_FALSE, matrix);
        }
    };

    std::string readFile(const std::string& fp) {
        // open file and read into string
        std::string result;
        std::ifstream in(fp, std::ios::in | std::ios::binary);
        if (in) {
            in.seekg(0, std::ios::end);
            result.resize(in.tellg());
            in.seekg(0, std::ios::beg);
            in.read(&result[0], (std::streamsize)result.size());
            in.close();
        }
        else {
            std::cout << "Could not open file " << fp << std::endl;
        }
    }

    Shader::Shader(const std::string& vertexShaderPath, const std::string& fragmentShaderPath) {
        std::string vertexShader = readFile(vertexShaderPath);
        std::string fragmentShader = readFile(fragmentShaderPath);
        m_impl = new OpenGLImplShader(vertexShader, fragmentShader);
    }

    OpenGLImplShader* impl(Shader* shader) {
        return static_cast<OpenGLImplShader*>(shader->getImplShader());
    }

    Shader::~Shader() {
        delete impl(this);
    }

    void Shader::bind() {
        impl(this)->bind();
    }

    void Shader::unbind() {
        impl(this)->unbind();
    }

    void Shader::setUniform1i(const std::string& name, int value) {
        impl(this)->setUniform1i(name, value);
    }
    void Shader::setUniform2i(const std::string& name, const Vector2i& vector) {
        impl(this)->setUniform2i(name, vector);
    }
    void Shader::setUniform2i(const std::string &name, const int *value) {
        impl(this)->setUniform2i(name, Vector2i(value[0], value[1]));
    }
    void Shader::setUniform2i(const std::string &name, int x, int y) {
        impl(this)->setUniform2i(name, Vector2i(x, y));
    }
    void Shader::setUniform3i(const std::string& name, const Vector3i& vector) {
        impl(this)->setUniform3i(name, vector);
    }
    void Shader::setUniform3i(const std::string &name, const int *value) {
        impl(this)->setUniform3i(name, Vector3i(value[0], value[1], value[2]));
    }
    void Shader::setUniform3i(const std::string &name, int x, int y, int z) {
        impl(this)->setUniform3i(name, Vector3i(x, y, z));
    }
    void Shader::setUniform4i(const std::string& name, const Vector4i& vector) {
        impl(this)->setUniform4i(name, vector);
    }
    void Shader::setUniform4i(const std::string &name, const int *value) {
        impl(this)->setUniform4i(name, Vector4i(value[0], value[1], value[2], value[3]));
    }
    void Shader::setUniform4i(const std::string &name, int x, int y, int z, int w) {
        impl(this)->setUniform4i(name, Vector4i(x, y, z, w));
    }
    void Shader::setUniform1f(const std::string& name, float value) {
        impl(this)->setUniform1f(name, value);
    }
    void Shader::setUniform2f(const std::string& name, const Vector2f& vector) {
        impl(this)->setUniform2f(name, vector);
    }
    void Shader::setUniform2f(const std::string &name, const float *value) {
        impl(this)->setUniform2f(name, Vector2f(value[0], value[1]));
    }
    void Shader::setUniform2f(const std::string &name, float x, float y) {
        impl(this)->setUniform2f(name, Vector2f(x, y));
    }
    void Shader::setUniform3f(const std::string& name, const Vector3f& vector) {
        impl(this)->setUniform3f(name, vector);
    }
    void Shader::setUniform3f(const std::string &name, const float *value) {
        impl(this)->setUniform3f(name, Vector3f(value[0], value[1], value[2]));
    }
    void Shader::setUniform3f(const std::string &name, float x, float y, float z) {
        impl(this)->setUniform3f(name, Vector3f(x, y, z));
    }
    void Shader::setUniform4f(const std::string& name, const Vector4f& vector) {
        impl(this)->setUniform4f(name, vector);
    }
    void Shader::setUniform4f(const std::string &name, const float *value) {
        impl(this)->setUniform4f(name, Vector4f(value[0], value[1], value[2], value[3]));
    }
    void Shader::setUniform4f(const std::string &name, float x, float y, float z, float w) {
        impl(this)->setUniform4f(name, Vector4f(x, y, z, w));
    }
    void Shader::setUniformMat4f(const std::string& name, const Matrix4f &value) {
        impl(this)->setUniformMat4f(name, value);
    }
    void Shader::setUniformMat4f(const std::string &name, const float *value) {
        impl(this)->setUniformMat4f(name, value);
    }

    void* Shader::getImplShader() {
        return m_impl;
    }
}