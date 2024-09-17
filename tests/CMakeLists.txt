find_package(GTest REQUIRED)

include_directories(GTEST_INCLUDE_DIRS)

enable_testing()

file(GLOB_RECURSE TEST_BIN
        CONFIGURE_DEPENDS
        "${CMAKE_CURRENT_SOURCE_DIR}/*.[hc]"
        "${CMAKE_CURRENT_SOURCE_DIR}/*.[hc]pp"
)

add_executable(${PROJECT_NAME}_tests ${TEST_BIN})
add_dependencies(${PROJECT_NAME}_tests ${PROJECT_NAME})
target_link_libraries(${PROJECT_NAME}_tests ${PROJECT_NAME} GTest::gtest_main)

gtest_discover_tests(${PROJECT_NAME}_tests)