#version 330 core

void main() {
    gl_FragColor = vec4(gl_FragCoord.xy / 512.0, 0.0, 1.0);
}
