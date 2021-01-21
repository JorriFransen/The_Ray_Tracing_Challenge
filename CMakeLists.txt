cmake_minimum_required(VERSION 3.13)

set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

project(ray_tracer)

set (RAY_TRACER_SOURCE
    source/allocator.cpp
    source/canvas.cpp
    source/color.cpp
    source/c_allocator.cpp
    source/temp_allocator.cpp
    source/tuple.cpp
    source/point.cpp
    source/vector.cpp
    source/matrix.cpp
    source/util.cpp
    source/string_builder.cpp

    source/putting_it_together_ch01.cpp
    source/putting_it_together_ch02.cpp
    source/putting_it_together_ch04.cpp
)

add_library(raytracer_lib ${RAY_TRACER_SOURCE})
target_include_directories(raytracer_lib PUBLIC include/trtc)

add_executable(raytracer source/main.cpp)
target_link_libraries(raytracer raytracer_lib)


set (TEST_SOURCES
    lib/munit/munit.c
)

add_executable(tests tests/test_main.cpp)
target_sources(tests PRIVATE ${TEST_SOURCES})
target_include_directories(tests PRIVATE lib)
target_link_libraries(tests raytracer_lib)
