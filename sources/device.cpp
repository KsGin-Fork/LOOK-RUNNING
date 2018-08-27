//
// Created by ksgin on 18-8-24.
//

#include <cstdlib>
#include "../headers/device.h"

bool device::initialize(const char *title, const int width, const int height) {
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

void device::setKeyCallback(GLFWkeyfun fun) {
    glfwSetKeyCallback(this->window, fun);
}

bool device::windowShouldClosed() {
    return static_cast<bool>(glfwWindowShouldClose(this->window));
}

void device::present() {
    glfwSwapBuffers(this->window);
}

void device::setViewPort(int x, int y, int w, int d) {
    glViewport(x, y, w, d);
}

void device::pollEvents() {
    glfwPollEvents();
}

void device::destroy() {
    if (window) free(window);
}

void device::clear(device::bitfield mask) {
    glClear(mask);
}

void device::clearColor(device::clampf r, device::clampf g, device::clampf b, device::clampf a) {
    glClearColor(r , g , b , a);
}

void device::setWindowShouldClose(bool shouldClosed) {
    glfwSetWindowShouldClose(this->window , shouldClosed);
}
