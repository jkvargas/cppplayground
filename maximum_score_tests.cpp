//
// Created by jhonny on 2/25/24.
//

#include <gtest/gtest.h>
#include "maximum_score.h"

TEST(maximum_score, TestOne) {
    auto par_a = vector<int> {1, 2, 3};
    auto par_b = vector<int> {3, 2, 1};
    auto solution = maximum_score();

    EXPECT_EQ(14, solution.maximumScore(par_a, par_b));
}

TEST(maximum_score, TestTwo) {
    auto par_a = vector<int> {-5,-3,-3,-2,7,1};
    auto par_b = vector<int> {-10,-5,3,4,6};
    auto solution = maximum_score();

    EXPECT_EQ(102, solution.maximumScore(par_a, par_b));
}