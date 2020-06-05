cmake_minimum_required(VERSION 3.10)

file(GLOB SRC
    "*.hpp"
    "*.cpp"
)

set(arenx_SRC ${SRC})

add_library(arenx STATIC ${arenx_SRC})

target_include_directories(arenx PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})