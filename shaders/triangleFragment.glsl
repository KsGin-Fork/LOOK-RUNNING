#version 420 core
out vec3 frag;
uniform vec3 color;
void main() {
    frag = color;
}