// https://leetcode.com/problems/maximum-sum-circular-subarray/?envType=study-plan-v2&envId=top-interview-150

#include <vector>
#include <gtest/gtest.h>

class Solution {
 public:
  int maxSubarraySumCircular(std::vector<int>& nums) {
    auto cur_max = 0;
    auto cur_min = 0;
    auto max_sum = nums[0];
    auto min_sum = nums[0];
    auto total = 0;

    for (int num : nums) {
      cur_max = std::max(cur_max, 0) + num;
      max_sum = std::max(max_sum, cur_max);

      cur_min = std::min(cur_min, 0) + num;
      min_sum = std::min(min_sum, cur_min);

      total += num;
    }

    if (total == min_sum) return max_sum;

    return std::max(max_sum, total - min_sum);
  }
};

TEST(maximum_sum_circular_subarray, test_one) {
  std::vector nums = {1, 2, -1, 3};
  auto solution = Solution{};
  ASSERT_EQ(5, solution.maxSubarraySumCircular(nums));
}
