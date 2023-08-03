#include "soup_servings.h"
#include <gtest/gtest.h>

double Solution::soupServings(int n) {
    if (n > 4800) {
        return 1.0;
    }

    n = (n + 24) / 25;
    unordered_map<int, double> memo;

    return dp(n, n, memo);
}

double Solution::dp(int a, int b, unordered_map<int, double> &memo) {
    if (a <= 0 && b <= 0) {
        return 0.5;
    }

    if (a <= 0) {
        return 1.0;
    }

    if (b <= 0) {
        return 0.0;
    }

    auto key = a * 5000 + b;

    if (memo.count(key)) {
        return memo[key];
    }

    memo[key] = 0.25 * (dp(a - 4, b, memo) + dp(a - 3, b - 1, memo) + dp(a - 2, b - 2, memo) + dp(a - 1, b - 3, memo));

    return memo[key];
}

TEST(soupServings, TestOne) {
    auto solution = Solution();
    EXPECT_EQ(1.0, solution.soupServings(4800));
}

TEST(soupServings, TestTwo) {
    auto solution = Solution();
    EXPECT_EQ(0.71875, solution.soupServings(100));
}