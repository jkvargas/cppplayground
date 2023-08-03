cmake_minimum_required(VERSION 3.26)
project(cppplayground)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(GTest REQUIRED)

include_directories(GTEST_INCLUDE_DIRS)

enable_testing()

file(GLOB cppplayground_SRC
        "*.cpp"
        "*.h"
)

add_library(cppplayground SHARED ${cppplayground_SRC})
target_link_libraries(cppplayground GTest::gtest_main)

gtest_discover_tests(cppplayground)