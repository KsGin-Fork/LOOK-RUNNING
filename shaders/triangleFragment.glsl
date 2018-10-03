#version 330 core

in vec2 outUV;
out vec3 frag;
uniform vec3 color;
uniform sampler2D textureSampler;
uniform vec2 screen;

void main() {
    frag = texture(textureSampler , outUV).rgb * color;
}