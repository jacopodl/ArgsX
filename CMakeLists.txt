cmake_minimum_required(VERSION 3.0)
project(LibArgsX)

set (VERSION_MAJOR 1)
set (VERSION_MINOR 5)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} --pedantic")

set(DEFAULT_INSTALL_PATH "${PROJECT_SOURCE_DIR}/bin")
set(INCLUDE_PATH "${PROJECT_SOURCE_DIR}/include")

add_subdirectory(src)
