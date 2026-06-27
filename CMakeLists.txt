cmake_minimum_required(VERSION 4.2)
project(learning_opengl)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenGL REQUIRED)

include_directories(lib/)

#Executaveis
# Triângulo
add_executable(triangulo 01-Triangulo_/triangleInScreen.cpp lib/bibutil.cpp)
target_link_libraries(triangulo OpenGL::GL GLU glut jpeg)

# Casa
add_executable(casa 02-Casa_/house.cpp lib/bibutil.cpp)
target_link_libraries(casa OpenGL::GL GLU glut jpeg)