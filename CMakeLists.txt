cmake_minimum_required(VERSION 3.12)

project(raylib_test)

set(CMAKE_C_STANDARD 11)

add_subdirectory(raylib)
add_subdirectory(pocketpy)

include_directories(raylib/src)
include_directories(pocketpy/include)

add_executable(
    ${PROJECT_NAME}
    main.c
    output/raylib.c
)

target_link_libraries(
    ${PROJECT_NAME}
    raylib
    pocketpy
)
