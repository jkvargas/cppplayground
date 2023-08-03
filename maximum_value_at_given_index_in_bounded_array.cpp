//
// Created by jhonny on 8/3/23.
//

#include "maximum_value_at_given_index_in_bounded_array.h"
#include <vector>
#include <gtest/gtest.h>

using namespace std;

int maximum_value_at_given_index_in_bounded_array::maxValue(int n, int index, int maxSum) {
    auto nums = vector<int>(n, -1);

    return nums[index];
}

TEST(maximum_value_at_given_index_in_bounded_array, TestOne) {
    auto solution = maximum_value_at_given_index_in_bounded_array();
    EXPECT_EQ(2, solution.maxValue(4, 2, 6));
    EXPECT_EQ(3, solution.maxValue(6, 1, 10));
}
