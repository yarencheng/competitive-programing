cmake_minimum_required(VERSION 3.10)

file(GLOB SRCS *.cpp)

ADD_EXECUTABLE(testarenx ${SRCS})
TARGET_LINK_LIBRARIES(testarenx arenx gtest_main gtest gmock pthread)

add_test(NAME testarenx COMMAND testarenx)