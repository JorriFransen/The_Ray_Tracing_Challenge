cmake_minimum_required(VERSION 3.13)

set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

project(ray_tracer)

set (RAY_TRACER_SOURCE
    source/main.cpp

    source/tuple.cpp
)

add_executable(raytracer source/main.cpp)
# target_include_directories(zodiac PRIVATE include/zodiac)
target_sources(raytracer PRIVATE ${RAY_TRACER_SOURCE})


set (TEST_SOURCES
    lib/munit/munit.c
    tests/test_main.cpp
)

add_executable(tests tests/test_main.cpp)
target_sources(tests PRIVATE ${TEST_SOURCES})
target_include_directories(tests PRIVATE lib)
