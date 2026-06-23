cmake_minimum_required(VERSION 4.2)
project(learning_opengl)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenGL REQUIRED)

add_executable(learning_opengl main.cpp)

target_link_libraries(learning_opengl
        OpenGL::GL
        GLU
        glut
)