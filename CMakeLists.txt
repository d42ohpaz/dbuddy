cmake_minimum_required(VERSION 3.17)
project(odbii-copilot C)

set(CMAKE_C_STANDARD 11)

add_executable(odbii-copilot main.c)
add_library(sdl2 STATIC main.c)

include_directories(.)

find_library(SDL2_LIBRARY sdl2 /usr/lib/x86_64-linux-gnu)
target_link_libraries(odbii-copilot LINK_PUBLIC $SDL2_LIBRARY)