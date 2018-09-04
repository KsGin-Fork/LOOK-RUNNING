#version 330 core
layout(location=0) in vec3 pos;
layout(location=1) in vec2 uv;

out vec2 outUV;

void main() {
        outUV = uv;
        gl_Position = vec4(pos.x , pos.y , pos.z , 1.0f);
}