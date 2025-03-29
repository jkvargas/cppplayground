find_package(GTest REQUIRED)
include_directories(GTEST_INCLUDE_DIRS)
enable_testing()

file(GLOB_RECURSE SRC_BIN
        CONFIGURE_DEPENDS
        "${CMAKE_CURRENT_SOURCE_DIR}/*.[hc]"
        "${CMAKE_CURRENT_SOURCE_DIR}/*.[hc]pp"
)

add_executable(${PROJECT_NAME} ${SRC_BIN})
target_link_libraries(${PROJECT_NAME} GTest::gtest_main)
gtest_discover_tests(${PROJECT_NAME})
