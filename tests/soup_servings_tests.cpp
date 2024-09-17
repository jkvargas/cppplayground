//
// Created by jhonny on 8/3/23.
//

#include <gtest/gtest.h>
#include "../src/soup_servings.h"
#include <cmath>

TEST(soupServings, TestOne) {
    auto solution = Solution();
    EXPECT_EQ(1.0, round(solution.soupServings(4800)));
}

TEST(soupServings, TestTwo) {
    auto solution = Solution();
    EXPECT_EQ(0.71875, solution.soupServings(100));
}