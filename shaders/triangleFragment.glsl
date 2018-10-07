#version 330 core

in vec2 outUV;
out vec3 frag;
uniform vec3 color;
uniform sampler2D textureSampler;
uniform vec2 screen;

void main() {
    float P = 0.243555 , Wp = 0.0630;
    int M = int(screen.x) , N = int(screen.y);
    float theta = acos(P / Wp / 4);
    float prism = mod((M * outUV.x * cos(theta) + N * outUV.y * sin(theta)) , P);

    float temp = outUV.x * M;

    if(int(temp) % 2 != 0) {
        temp = temp / 2 + 1;
    } else {
        temp = temp / 2;
    }

    if (prism >= P / 2) {
        temp = temp + 0.5 * M;

    }

    frag = texture(textureSampler , vec2(temp / M, outUV.y)).rgb * color;
}