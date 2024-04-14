cmake_minimum_required(VERSION 3.26)
project(cppplayground)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(GTest REQUIRED)

include_directories(GTEST_INCLUDE_DIRS)

enable_testing()

add_library(${PROJECT_NAME} SHARED maximum_value_at_given_index_in_bounded_array.h
        maximum_value_at_given_index_in_bounded_array.cpp
        soup_servings.h
        soup_servings.cpp
        maximal_square.cpp
        maximal_square.h
        maximum_score.cpp
        maximum_score.h
        lowest_common_ancestor.h
        treenode.cpp
        treenode.h)
add_executable(${PROJECT_NAME}_tests
        maximum_value_at_given_index_in_bounded_array_tests.cpp
        soup_servings_tests.cpp
        maximal_square_tests.cpp
        maximum_score_tests.cpp
        lowest_common_ancestor_tests.cpp)

target_link_libraries(${PROJECT_NAME}_tests GTest::gtest_main ${PROJECT_NAME})

gtest_discover_tests(${PROJECT_NAME}_tests)