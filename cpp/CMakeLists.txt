cmake_minimum_required(VERSION 3.10)

project(Tutorial)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_VERBOSE_MAKEFILE on)

enable_testing()

add_subdirectory(arenx)
add_subdirectory(test)
# add_executable(Tutorial tutorial.cxx)


