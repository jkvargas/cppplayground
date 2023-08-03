//
// Created by jhonny on 8/3/23.
//

#include <gtest/gtest.h>
#include "maximum_value_at_given_index_in_bounded_array.h"

TEST(maximum_value_at_given_index_in_bounded_array, TestOne) {
    auto solution = maximum_value_at_given_index_in_bounded_array();
    EXPECT_EQ(2, solution.maxValue(4, 2, 6));
    EXPECT_EQ(3, solution.maxValue(6, 1, 10));
}