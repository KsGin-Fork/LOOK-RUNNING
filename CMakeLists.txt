cmake_minimum_required(VERSION 3.12)
project(LOOK_RUNNING)

set(CMAKE_CXX_STANDARD 14)

find_package(glfw3 REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)

link_libraries(glfw GLEW OpenGL)

add_executable(LOOK_RUNNING main.cpp headers/device.h headers/shader.h headers/model.h headers/texture.h headers/common.h)