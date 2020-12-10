cmake_minimum_required(VERSION 3.17)
project(obdii-copilot)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)#C17
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${PROJECT_SOURCE_DIR})

file(GLOB_RECURSE INCLUDES "lv_drivers/*.h" "lvgl/*.h"  "./*.h" )
file(GLOB_RECURSE SOURCES  "lv_drivers/*.c" "lvgl/*.c" )

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(MACOS_HOMEBREW_INCLUDE_PATH "/usr/local/include")
set(MACOS_HOMEBREW_LIBRARY "/usr/local/lib")

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR} ${MACOS_HOMEBREW_INCLUDE_PATH})

add_executable(obdii-copilot main.c mouse_cursor_icon.c ${SOURCES} ${INCLUDES})
target_link_libraries(obdii-copilot ${SDL2_LIBRARY} ${MACOS_HOMEBREW_LIBRARY}/libSDL2.dylib)
add_custom_target (run COMMAND ${EXECUTABLE_OUTPUT_PATH}/obdii-copilot)
