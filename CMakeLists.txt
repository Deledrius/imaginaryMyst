cmake_minimum_required(VERSION 3.10)
project(imaginaryMyst)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

find_package(SDL REQUIRED)
find_package(OpenGL REQUIRED)
find_package(ZLIB REQUIRED)
find_package(libSquish REQUIRED)

add_subdirectory(src)
