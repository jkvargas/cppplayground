//
// Created by jhonny on 4/1/25.
//
#include <gtest/gtest.h>

#include <algorithm>
#include <vector>

class Solution {
 public:
  int maxProduct(std::vector<int>& nums) {
    if (nums.empty()) return 0;

    int max_so_far = nums[0];
    int min_so_far = nums[0];
    int result = max_so_far;

    for (int i = 1; i < nums.size(); i++) {
      int curr = nums[i];
      int temp_max = std::max(std::max(curr, max_so_far * curr), min_so_far * curr);
      min_so_far = std::min(std::min(curr, max_so_far * curr), min_so_far * curr);
      max_so_far = temp_max;
      result = std::max(max_so_far, result);
    }

    return result;
  }
};

TEST(maximum_product_subarray, test_one) {
  Solution solution;
  std::vector<int> nums = {2, 3, -2, 4};
  ASSERT_EQ(6, solution.maxProduct(nums));
}