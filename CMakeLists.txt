cmake_minimum_required(VERSION 3.9)

project(voxy)
# The version number.
set (VOXY_VERSION_MAJOR 1)
set (VOXY_VERSION_MINOR 0)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/modules/")

set(TESTING on)
message(STATUS "test")

add_subdirectory(src)