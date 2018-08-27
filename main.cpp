#include <iostream>
#include "headers/device.h"

void key_callback(GLFWwindow* window , int key , int scancode , int action , int mode){
    if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS){
        glfwSetWindowShouldClose(window , GL_TRUE);
    }
}

int main()
{
    auto *d = new device;

    d->initialize("Empty window" , 800 , 600);
    d->setViewPort(100 , 100 , 800 , 600);
    d->setKeyCallback(key_callback);

    while (!d->windowShouldClosed()){
        d->pollEvents();

        static int r = 0;
        static int g = 128;
        static int b = 255;

        d->clear(GL_COLOR_BUFFER_BIT);
        d->clearColor(r / 255.0f  , g / 255.0f , b / 255.0f  , 1.0f);

        static int dr = 1;
        static int dg = 1;
        static int db = 1;
        r += dr;
        g += dg;
        b += db;
        if (r > 255 || r < 0) dr = -dr;
        if (g > 255 || g < 0) dg = -dg;
        if (b > 255 || b < 0) db = -db;

        d->present();
    }

    d->destroy();
    delete d;
    return 0;
}