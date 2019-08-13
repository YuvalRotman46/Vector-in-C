cmake_minimum_required(VERSION 3.14)
project(Vector_Task C)

set(CMAKE_C_STANDARD 11)

add_executable(Vector_Task main.c Node.c Node.h Vector.c Vector.h myLib.h)