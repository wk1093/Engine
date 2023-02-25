#version 330 core

out vec4 FragColor;

in vec4 ourColor;
in vec2 texCoord;
in vec3 normal;

void main() {
    FragColor = vec4(ourColor);
}
