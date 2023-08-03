//
// Created by jhonny on 8/3/23.
//

#include <gtest/gtest.h>
#include "soup_servings.h"

TEST(soupServings, TestOne) {
    auto solution = Solution();
    EXPECT_EQ(1.0, solution.soupServings(4800));
}

TEST(soupServings, TestTwo) {
    auto solution = Solution();
    EXPECT_EQ(0.71875, solution.soupServings(100));
}