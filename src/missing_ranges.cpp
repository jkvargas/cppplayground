/* https://leetcode.com/explore/interview/card/google/59/array-and-strings/3055/ */
#include <gtest/gtest.h>

#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> findMissingRanges(std::vector<int>& nums, int lower, int upper) {
    std::vector<std::vector<int>> result;
    if (nums.empty()) {
      result.push_back(create_range(lower, upper));
      return result;
    }

    if (nums[0] > lower) {
      result.push_back(create_range(lower, nums[0] - 1));
    }

    if (nums.size() >= 2) {
      for (int i = 1; i < nums.size() && nums[i] >= lower && nums[i] <= upper; i++) {
        if (nums[i] - nums[i - 1] > 1) {
          result.push_back(create_range(nums[i - 1] + 1, nums[i] - 1));
        }
      }
    }

    if (nums[nums.size() - 1] < upper) {
      result.push_back(create_range(nums[nums.size() - 1] + 1, upper));
    }

    return std::move(result);
  }

  std::vector<int> create_range(int min, int max) {
    std::vector<int> temp;
    temp.push_back(min);
    temp.push_back(max);
    return std::move(temp);
  }
};

TEST(missing_ranges, test_one) {
  std::vector send_it = {0, 1, 3, 50, 75};
  Solution solution{};
  auto result = solution.findMissingRanges(send_it, 0, 99);
  ASSERT_EQ((std::vector{2, 2}), result[0]);
  ASSERT_EQ((std::vector{4, 49}), result[1]);
  ASSERT_EQ((std::vector{51, 74}), result[2]);
  ASSERT_EQ((std::vector{76, 99}), result[2]);
}

TEST(missing_ranges, test_two) {
  std::vector<int> send_it{};
  Solution solution{};
  auto result = solution.findMissingRanges(send_it, 1, 1);
  ASSERT_EQ((std::vector{1, 1}), result[0]);
}

TEST(missing_ranges, test_three) {
  std::vector<int> send_it{1, 3};
  Solution solution{};
  auto result = solution.findMissingRanges(send_it, 0, 9);
  ASSERT_EQ((std::vector{0, 0}), result[0]);
  ASSERT_EQ((std::vector{2, 2}), result[1]);
  ASSERT_EQ((std::vector{4, 9}), result[2]);
}

TEST(missing_ranges, test_four) {
  std::vector<int> send_it{0, 9};
  Solution solution{};
  auto result = solution.findMissingRanges(send_it, 0, 9);
  ASSERT_EQ((std::vector{1, 8}), result[0]);
}