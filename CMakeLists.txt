cmake_minimum_required(VERSION 3.13)

set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

project(ray_tracer)

set (RAY_TRACER_SOURCE
    source/tuple.cpp
    source/point.cpp
    source/vector.cpp
)

add_executable(raytracer source/main.cpp)
target_include_directories(raytracer PRIVATE include/trtc)
target_sources(raytracer PRIVATE ${RAY_TRACER_SOURCE})


set (TEST_SOURCES
    lib/munit/munit.c
)

add_executable(tests tests/test_main.cpp)
target_sources(tests PRIVATE ${TEST_SOURCES} ${RAY_TRACER_SOURCE})
target_include_directories(tests PRIVATE lib)
target_include_directories(tests PRIVATE include/trtc)