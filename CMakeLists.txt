cmake_minimum_required(VERSION 3.17)
project(obdii-copilot C)

set(CMAKE_C_STANDARD 11)

add_executable(obdii-copilot main.c)
add_library(sdl2 STATIC main.c)

include_directories(.)

find_library(SDL2_LIBRARY sdl2 /usr/lib/x86_64-linux-gnu)
target_link_libraries(obdii-copilot LINK_PUBLIC $SDL2_LIBRARY)
