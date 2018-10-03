#include <iostream>
#include "headers/device.h"
#include "headers/shader.h"
#include "headers/model.h"
#include "headers/texture.h"
#include "headers/common.h"

const int width = 800;
const int height = 500;

void key_callback(GLFWwindow* window , int key , int scancode , int action , int mode){
    if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS){
        glfwSetWindowShouldClose(window , GL_TRUE);
    }
}

glm::vec3 color() {
    static int r = 0;
    static int g = 128;
    static int b = 255;
    static int dr = 1;
    static int dg = 1;
    static int db = 1;
    r += dr;
    g += dg;
    b += db;
    if (r > 255 || r < 0) dr = -dr;
    if (g > 255 || g < 0) dg = -dg;
    if (b > 255 || b < 0) db = -db;

    return glm::vec3(r / 255.0f , g / 255.0f, b / 255.0f);
}

int main()
{
    auto immediateDevice = new device;

    immediateDevice->initialize("look running" , width , height);
    immediateDevice->setKeyCallback(key_callback);

    /*顶点坐标*/
    GLfloat vertices[] = {
            -1.0f, -1.0f, 0.0f, 0.0f , 1.0f ,
            1.0f, 1.0f, 0.0f, 1.0f , 0.0f ,
            -1.0f, 1.0f, 0.0f, 0.0f , 0.0f,
            -1.0f, -1.0f, 0.0f, 0.0f , 1.0f ,
            1.0f , -1.0f , 0.0f , 1.0f , 1.0f ,
            1.0f, 1.0f, 0.0f, 1.0f , 0.0f
    };
    int numVertices = 6 * 5;

    auto triangleModel = new model;
    triangleModel->initialize(vertices , numVertices);
    triangleModel->vertexPointer(0 , 3 , 5 , 0);
    triangleModel->vertexPointer(1 , 2 , 5 , 3);

    auto triangleShader = new shader;
    triangleShader->initialize("../shaders/triangleVertex.glsl" , "../shaders/triangleFragment.glsl");

    auto triangleTexture = new texture;
    triangleTexture->initialize("../resources/texture2.jpg" , false);

    while (!immediateDevice->windowShouldClosed()){
        immediateDevice->pollEvents();

        immediateDevice->clear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        immediateDevice->clearColor(0 , 0 , 0 , 1);
        immediateDevice->activeTexture(0);

        triangleTexture->use();

        triangleShader->use();
        triangleShader->setVec3("color" , color());
        triangleShader->setVec2("screen" , glm::vec2(width , height));

        triangleModel->draw(0 , 6);

        immediateDevice->present();

    }

    immediateDevice->destroy();
    triangleModel->destroy();
    triangleShader->destroy();

    delete immediateDevice;
    return 0;
}