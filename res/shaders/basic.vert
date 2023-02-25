#version 330 core

layout (location=0) in vec3 aPos;
layout (location=1) in vec4 aColor;
layout (location=2) in vec2 aTexCoord;
layout (location=3) in vec3 aNormal;

out vec4 ourColor;
out vec2 texCoord;
out vec3 normal;

uniform mat4 transform;

void main() {
    transform;
    gl_Position = vec4(aPos, 1.0);
    ourColor = aColor;
    texCoord = vec2(aTexCoord.xy);
    normal = aNormal;
}
