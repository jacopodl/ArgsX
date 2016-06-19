cmake_minimum_required(VERSION 2.8)
project(LibArgsX)

add_library(ArgsX argsx.c)
configure_file("${PROJECT_SOURCE_DIR}/argsx.h" "${INCLUDE_PATH}/argsx.h")

install(TARGETS ArgsX DESTINATION "${DEFAULT_INSTALL_PATH}")
