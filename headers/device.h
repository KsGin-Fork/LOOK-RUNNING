//
// Created by ksgin on 18-8-24.
//

#ifndef LOOK_RUNNING_DEVICE_H
#define LOOK_RUNNING_DEVICE_H

#include "common.h"

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
    bool initialize(const char *title, int width, int height) {
        glfwInit();
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwWindowHint(GLFW_RESIZABLE, false);
#ifdef __APPLE__
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT , GL_TRUE);
#endif
        this->window = glfwCreateWindow(width, height, title, nullptr, nullptr);
        glfwMakeContextCurrent(window);
        if (window == nullptr) {
            return false;
        }
        glewExperimental = GL_TRUE;
        return glewInit() == GLEW_OK;
    }
    bool windowShouldClosed() {
        return static_cast<bool>(glfwWindowShouldClose(this->window));
    }
    void setWindowShouldClose(bool shouldClosed){
        glfwSetWindowShouldClose(this->window , shouldClosed);
    }
    void setKeyCallback(keyfun fun) {
        glfwSetKeyCallback(this->window, fun);
    }
    void present() {
        glfwSwapBuffers(this->window);
    }
    void setViewPort(int x , int y , int w , int d) {
        glViewport(x, y, w, d);
    }
    void pollEvents() {
        glfwPollEvents();
    }
    void clear(bitfield mask) {
        glClear(mask);
    }
    void clearColor(clampf r , clampf g , clampf b , clampf a) {
        glClearColor(r , g , b , a);
    }
    void destroy() {
        if (window) free(window);
    }
};


#endif //LOOK_RUNNING_DEVICE_H
