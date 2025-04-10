// https://leetcode.com/problems/find-peak-element/description/?envType=company&envId=facebook&favoriteSlug=facebook-thirty-days

#include <gtest/gtest.h>

#include <limits>
#include <vector>
#include <optional>

class Solution {
 public:
  int findPeakElement(std::vector<int>& nums) {
    for (int i = 0; i < nums.size(); i++) {
      auto element = nums[i];
      std::optional<int> left_neighbour = i == 0 ? std::nullopt : std::optional<int>{nums[i - 1]};
      std::optional<int> right_neighbour = i == nums.size() - 1 ? std::nullopt : std::optional<int>{nums[i + 1]};

      if ((!left_neighbour.has_value() || element > left_neighbour.value()) && (!right_neighbour.has_value() || element > right_neighbour.value())) return i;
    }

    return -1;
  }
};

TEST(find_peak_element, test_one) {
  std::vector<int> nums = {1, 2, 3, 1};
  auto solution = Solution{};
  ASSERT_EQ(2, solution.findPeakElement(nums));
}

TEST(find_peak_element, test_two) {
  std::vector<int> nums = {1, 2, 1, 3, 5, 6, 4};
  auto solution = Solution{};
  ASSERT_EQ(1, solution.findPeakElement(nums));
}

TEST(find_peak_element, test_three) {
  std::vector<int> nums = { -2147483648 };
  auto solution = Solution{};
  ASSERT_EQ(0, solution.findPeakElement(nums));
}
