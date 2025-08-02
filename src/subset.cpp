//
// Created by jhonny on 8/1/25.
//

// https://leetcode.com/explore/interview/card/apple/509/recursion/3127/

#include <gtest/gtest.h>

#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
    std::vector<std::vector<int>> results{};
    std::vector<int> subset{};

    fn(results, 0, nums, subset);

    return results;
  }

  void fn(std::vector<std::vector<int>>& output, int start, std::vector<int>& nums,
          std::vector<int>& curr) {
    output.push_back(curr);

    for (int i = start; i < nums.size(); i++) {
      curr.push_back(nums[i]);
      fn(output, i + 1, nums, curr);
      curr.pop_back();
    }
  }
};

TEST(subsets, test_one) {
  auto solution = Solution();
  std::vector<int> nums{1, 2, 3};
  auto result = solution.subsets(nums);
  ASSERT_EQ(result.size(), 8);
}