cmake_minimum_required(VERSION 3.20)
project(xmactree C)

set(CMAKE_C_STANDARD 99)

add_executable(xmactree src/xmas_tree.c src/xmas_tree.h src/main.c)
