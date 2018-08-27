//
// Created by ksgin on 18-8-24.
//

#ifndef LOOK_RUNNING_DEVICE_H
#define LOOK_RUNNING_DEVICE_H

#define GLEW_STATIC

#include <GL/glew.h>
#include <GLFW/glfw3.h>

class device {
public:
    typedef GLbitfield bitfield;
    typedef GLclampf clampf;
    typedef GLFWkeyfun keyfun;
private:
    GLFWwindow *window;
public:
    device() = default;
    ~device() = default;
    bool initialize(const char *title, int width, int height);
    bool windowShouldClosed();
    void setWindowShouldClose(bool shouldClosed);
    void setKeyCallback(keyfun fun);
    void present();
    void setViewPort(int x , int y , int w , int d);
    void pollEvents();
    void clear(bitfield mask);
    void clearColor(clampf r , clampf g , clampf b , clampf a);
    void destroy();
};


#endif //LOOK_RUNNING_DEVICE_H
