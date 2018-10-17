cmake_minimum_required(VERSION 3.12)
project(LOOK_RUNNING)

set(CMAKE_CXX_STANDARD 14)


if (APPLE)
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -framework OPENGL")
    include_directories(/usr/local/include/)
elseif(UNIX)
    find_package(GLEW REQUIRED)
    find_package(OpenGL REQUIRED)
    find_package(glfw3 REQUIRED)
    link_libraries(glfw GLEW OpenGL)
endif ()

add_executable(LOOK_RUNNING main.cpp headers/device.h headers/shader.h headers/model.h headers/texture.h headers/common.h)

if (APPLE)
    target_link_libraries(LOOK_RUNNING /usr/local/lib/libglfw.dylib)
    target_link_libraries(LOOK_RUNNING /usr/local/lib/libGLEW.dylib)
    target_link_libraries(LOOK_RUNNING /usr/local/lib/libassimp.dylib)
endif ()