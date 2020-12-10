cmake_minimum_required(VERSION 3.17)
project(obdii-copilot C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${PROJECT_SOURCE_DIR})

file(GLOB_RECURSE INCLUDES "lv_drivers/*.h" "lvgl/*.h" "./*.h")
file(GLOB_RECURSE SOURCES "lv_drivers/*.c" "lvgl/*.c")

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR} "/usr/local/include")

add_executable(obdii-copilot main.c hal.c hal.h assets/mouse_cursor_icon.c ${SOURCES} ${INCLUDES})

if(APPLE)
    target_link_libraries(obdii-copilot PRIVATE SDL2::SDL2)
else()
    target_link_libraries(obdii-copilot PRIVATE SDL2)
endif()

add_custom_target (run COMMAND ${EXECUTABLE_OUTPUT_PATH}/obdii-copilot)
