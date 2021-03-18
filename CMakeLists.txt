cmake_minimum_required(VERSION 3.17)
project(LI3 C)

set(CMAKE_C_STANDARD 99)

add_executable(ex1 src/ex1.c)
add_executable(ex2 src/ex2 src/ex2Main.c)
add_executable(ex3 src/ex2.c src/ex2.h src/ex3.c src/ex3.h)
