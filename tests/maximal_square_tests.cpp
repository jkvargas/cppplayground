//
// Created by jhonny on 2/25/24.
//

#include <gtest/gtest.h>
#include "../src/maximal_square.h"

TEST(maximal_square, TestOne) {
    auto solution = maximal_square();
    std::vector<std::vector<char>> matrix = {
            {'1', '0', '1', '0', '0'},
            {'1', '0', '1', '1', '1'},
            {'1', '1', '1', '1', '1'},
            {'1', '0', '0', '1', '0'}
    };

    EXPECT_EQ(4, solution.maximalSquare(matrix));
}