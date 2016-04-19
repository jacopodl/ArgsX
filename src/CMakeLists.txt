cmake_minimum_required(VERSION 3.0)
project(LibArgsX)

add_library(ArgsX argsx.c)
configure_file("${PROJECT_SOURCE_DIR}/argsx.h" "${INCLUDE_PATH}/argsx.h")
