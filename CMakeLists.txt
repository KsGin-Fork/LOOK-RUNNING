cmake_minimum_required(VERSION 3.12)
project(LOOK_RUNNING)

set(CMAKE_CXX_STANDARD 14)

find_package(glfw3 REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)

link_libraries(glfw GLEW OpenGL)

add_executable(LOOK_RUNNING main.cpp include/matrix.hpp include/vector.hpp sources/device.cpp headers/device.h sources/shader.cpp headers/shader.h)