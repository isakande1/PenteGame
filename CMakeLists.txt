cmake_minimum_required(VERSION 3.26)
project(PenteV C)

set(CMAKE_C_STANDARD 90)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -ansi -Wall -Wextra -Wpedantic -Werror")
add_executable(PenteV main.c)
