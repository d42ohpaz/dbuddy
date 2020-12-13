cmake_minimum_required(VERSION 3.17)
project(dbuddy C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${PROJECT_SOURCE_DIR})

file(GLOB_RECURSE INCLUDES "lv_drivers/*.h" "lvgl/*.h" "./*.h")
file(GLOB_RECURSE SOURCES "lv_drivers/*.c" "lvgl/*.c")

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR} "/usr/local/include")

add_executable( dbuddy
                main.c
                hal.c hal.h
                assets/mouse_cursor_icon.c
                assets/tft_background_art.c
                assets/fonts/roboto_regular_10.c
                assets/fonts/roboto_regular_12.c
                assets/fonts/roboto_regular_14.c
                assets/fonts/roboto_regular_16.c
                assets/fonts/roboto_regular_18.c
                assets/fonts/roboto_regular_24.c
                assets/fonts/roboto_regular_48.c
                assets/fonts/roboto_regular_96.c
                assets/fonts/roboto_light_10.c
                assets/fonts/roboto_light_12.c
                assets/fonts/roboto_light_14.c
                assets/fonts/roboto_light_16.c
                assets/fonts/roboto_light_18.c
                assets/fonts/roboto_light_24.c
                assets/fonts/roboto_light_48.c
                assets/fonts/roboto_light_96.c
                assets/fonts/roboto_black_10.c
                assets/fonts/roboto_black_12.c
                assets/fonts/roboto_black_14.c
                assets/fonts/roboto_black_16.c
                assets/fonts/roboto_black_18.c
                assets/fonts/roboto_black_24.c
                assets/fonts/roboto_black_48.c
                assets/fonts/roboto_black_96.c
                ${SOURCES} ${INCLUDES})

if (APPLE)
    target_link_libraries(dbuddy PRIVATE SDL2::SDL2)
else ()
    target_link_libraries(dbuddy PRIVATE SDL2)
endif ()

add_custom_target(run COMMAND ${EXECUTABLE_OUTPUT_PATH}/dbuddy)
