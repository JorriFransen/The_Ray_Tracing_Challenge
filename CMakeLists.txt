cmake_minimum_required(VERSION 3.13)

project(ray_tracer)
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory(lib/glfw)

set (RAY_TRACER_LIB_SOURCE
    source/allocator.cpp
    source/c_allocator.cpp
    source/canvas.cpp
    source/color.cpp
    source/light.cpp
    source/material.cpp
    source/matrix.cpp
    source/point.cpp
    source/ray.cpp
    source/string_builder.cpp
    source/temp_allocator.cpp
    source/tuple.cpp
    source/util.cpp
    source/vector.cpp
    source/world.cpp

    source/putting_it_together_ch01.cpp
    source/putting_it_together_ch02.cpp
    source/putting_it_together_ch04.cpp
    source/putting_it_together_ch05.cpp
    source/putting_it_together_ch06.cpp
)

add_library(raytracer_lib ${RAY_TRACER_LIB_SOURCE})
target_include_directories(raytracer_lib PUBLIC include/trtc)

set(RAY_TRACER_SOURCES
    source/main.cpp
    source/gui_window.cpp
)

add_executable(raytracer ${RAY_TRACER_SOURCES})
target_link_libraries(raytracer raytracer_lib glfw)
target_include_directories(raytracer PRIVATE lib)


set (TEST_SOURCES
    lib/munit/munit.c
)

add_executable(tests tests/test_main.cpp)
target_sources(tests PRIVATE ${TEST_SOURCES})
target_include_directories(tests PRIVATE lib)
target_link_libraries(tests raytracer_lib)
