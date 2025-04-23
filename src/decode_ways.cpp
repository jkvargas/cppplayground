// https://leetcode.com/explore/interview/card/facebook/55/dynamic-programming-3/264/

#include <gtest/gtest.h>

#include <string>

class Solution {
 public:
  int numDecodings(std::string s) {
    std::unordered_map<int, int> memo;
    return f(s, 0, memo);
  }

  int f(std::string& s, int index, std::unordered_map<int, int>& memo) {
    if (memo.contains(index)) return memo[index];
    if (index >= s.size()) return 1;

    auto number = s[index] - '0';
    if (number == 0 ) return 0;

    auto result = 0;
    if (index < s.size() - 1 && (number == 1 || number == 2) && s[index + 1] - '0' <= 6) {
      result = f(s, index + 2, memo) + f(s, index + 1, memo);
    } else {
      result = f(s, index + 1, memo);
    }

    return memo[index] = result;
  }
};

TEST(decode_ways, test_one) {
  auto solution = Solution();
  ASSERT_EQ(2, solution.numDecodings("12"));
}

TEST(decode_ways, test_two) {
  auto solution = Solution();
  ASSERT_EQ(3, solution.numDecodings("226"));
}

TEST(decode_ways, test_three) {
  auto solution = Solution();
  ASSERT_EQ(0, solution.numDecodings("06"));
}

TEST(decode_ways, test_four) {
  auto solution = Solution();
  ASSERT_EQ(4, solution.numDecodings("2611055971756562"));
}