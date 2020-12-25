cmake_minimum_required(VERSION 3.17)
project(dbuddy C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${PROJECT_SOURCE_DIR})

file(GLOB_RECURSE INCLUDES "lv_drivers/*.h" "lvgl/*.h" "inih/*.h" "assets/*.h" "src/*.h")
file(GLOB_RECURSE SOURCES "lv_drivers/*.c" "lvgl/*.c" "inih/*.c" "assets/*.c" "src/*.c")

list(FILTER SOURCES EXCLUDE REGEX "lvgl/src/lv_font/.*dejavu.*.c")
list(FILTER SOURCES EXCLUDE REGEX "lvgl/src/lv_font/.*montserrat.*.c")
list(FILTER SOURCES EXCLUDE REGEX "lvgl/src/lv_font/.*simsun.*.c")
list(FILTER SOURCES EXCLUDE REGEX "lvgl/src/lv_font/.*unscii.*.c")
list(FILTER SOURCES EXCLUDE REGEX "inih/cpp/.*.c")
list(FILTER SOURCES EXCLUDE REGEX "inih/examples/.*.c")
list(FILTER SOURCES EXCLUDE REGEX "inih/tests/.*.c")

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR} "/usr/local/include")

add_executable(dbuddy main.c ${SOURCES} ${INCLUDES})

if (APPLE)
    target_link_libraries(dbuddy PRIVATE SDL2::SDL2)
else ()
    target_link_libraries(dbuddy PRIVATE SDL2)
endif ()

add_custom_target(run COMMAND ${EXECUTABLE_OUTPUT_PATH}/dbuddy)
