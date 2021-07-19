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

set (RAY_TRACER_LIB_HEADERS
    include/trtc/allocator.h
    include/trtc/array.h
    include/trtc/c_allocator.h
    include/trtc/canvas.h
    include/trtc/color.h
    include/trtc/light.h
    include/trtc/material.h
    include/trtc/matrix.h
    include/trtc/point.h
    include/trtc/ray.h
    include/trtc/string_builder.h
    include/trtc/temp_allocator.h
    include/trtc/tuple.h
    include/trtc/util.h
    include/trtc/vector.h
    include/trtc/world.h

    include/trtc/putting_it_together_ch01.h
    include/trtc/putting_it_together_ch02.h
    include/trtc/putting_it_together_ch04.h
    include/trtc/putting_it_together_ch05.h
    include/trtc/putting_it_together_ch06.h
)
set_source_files_properties(${RAY_TRACER_LIB_HEADERS} PROPERTIES HEADER_FILE_ONLY 1)

add_library(raytracer_lib ${RAY_TRACER_LIB_SOURCE} ${RAY_TRACER_LIB_HEADERS})
target_include_directories(raytracer_lib PUBLIC include/trtc)

set(RAY_TRACER_SOURCES
    source/main.cpp
    source/gui_window.cpp
)

set (RAY_TRACER_HEADERS
    include/trtc/gui_window.h
)
set_source_files_properties(${RAY_TRACER_HEADERS} PROPERTIES HEADER_FILE_ONLY 1)

add_executable(raytracer ${RAY_TRACER_SOURCES} ${RAY_TRACER_HEADERS})
target_link_libraries(raytracer raytracer_lib glfw)
target_include_directories(raytracer PRIVATE lib)

set (_TEST_SOURCES
    tests/common.h
    tests/CH01.cpp
    tests/CH02.cpp
    tests/CH03.cpp
    tests/CH04.cpp
    tests/CH05.cpp
    tests/CH06.cpp
    tests/CH07.cpp
)
set_source_files_properties(${_TEST_SOURCES} PROPERTIES HEADER_FILE_ONLY 1)

set (TEST_SOURCES
    lib/munit/munit.c
    ${_TEST_SOURCES}
)

add_executable(tests tests/test_main.cpp)
target_sources(tests PRIVATE ${TEST_SOURCES})
target_include_directories(tests PRIVATE lib)
target_link_libraries(tests raytracer_lib)

if (MSVC)
    target_compile_options(raytracer_lib PRIVATE /W4 /std:c++latest -D_CRT_SECURE_NO_WARNINGS)
    target_compile_options(raytracer_lib PRIVATE /wd4201)
endif()
