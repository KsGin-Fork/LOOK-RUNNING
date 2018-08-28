#include <iostream>
#include "headers/device.h"
#include "headers/shader.h"

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
    auto *d = new device;

    d->initialize("look running" , 1024 , 768);
    d->setViewPort(0, 0 , 1024 , 768);
    d->setKeyCallback(key_callback);

    /*顶点坐标*/
    GLfloat vertices[] = {
            -0.5f, -0.5f, 0.0f,
            0.5f, -0.5f, 0.0f,
            0.0f, 0.5f, 0.0f,
    };

    GLuint VBO;
    GLuint VAO;
    glGenVertexArrays(1 , &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glVertexAttribPointer( 0 , 3 , GL_FLOAT , GL_FALSE , 0 , (void*)0);

    glEnableVertexAttribArray(0);
    glBindBuffer(1,VBO);

    shader triangle("../shaders/triangleVertex.glsl" , "../shaders/triangleFragment.glsl");

    while (!d->windowShouldClosed()){
        d->pollEvents();

        d->clear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        d->clearColor(0 , 0 , 0 , 1);

        triangle.use();
        triangle.setVec3("color" , color());
        glDrawArrays(GL_TRIANGLES , 0 , 3);

        d->present();
    }

    d->destroy();
    triangle.destroy();

    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1 , &VBO);

    delete d;
    return 0;
}