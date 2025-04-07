// https://leetcode.com/explore/interview/card/google/64/dynamic-programming-4/3089/

#include <gtest/gtest.h>

#include <limits>
#include <unordered_map>
#include <vector>

class Solution {
 public:
  // Defined it as per the maximum size of array and split count
  // But can be defined with the input size as well
  int memo[1001][51];

  int getMinimumLargestSplitSum(std::vector<int>& prefixSum, int currIndex, int subarrayCount) {
    int n = prefixSum.size() - 1;

    // We have already calculated the answer so no need to go into recursion
    if (memo[currIndex][subarrayCount] != -1) {
      return memo[currIndex][subarrayCount];
    }

    // Base Case: If there is only one subarray left, then all of the remaining numbers
    // must go in the current subarray. So return the sum of the remaining numbers.
    if (subarrayCount == 1) {
      return memo[currIndex][subarrayCount] = prefixSum[n] - prefixSum[currIndex];
    }

    // Otherwise, use the recurrence relation to determine the minimum largest subarray
    // sum between currIndex and the end of the array with subarrayCount subarrays remaining.
    int minimumLargestSplitSum = INT_MAX;
    for (int i = currIndex; i <= n - subarrayCount; i++) {
      // Store the sum of the first subarray.
      int firstSplitSum = prefixSum[i + 1] - prefixSum[currIndex];

      // Find the maximum subarray sum for the current first split.
      int largestSplitSum =
          std::max(firstSplitSum, getMinimumLargestSplitSum(prefixSum, i + 1, subarrayCount - 1));

      // Find the minimum among all possible combinations.
      minimumLargestSplitSum = std::min(minimumLargestSplitSum, largestSplitSum);

      if (firstSplitSum >= minimumLargestSplitSum) {
        break;
      }
    }

    return memo[currIndex][subarrayCount] = minimumLargestSplitSum;
  }

  int splitArray(std::vector<int>& nums, int m) {
    // Marking all values to -1 so that we can differentiate
    // If we have already calculated the answer or not
    memset(memo, -1, sizeof(memo));

    // Store the prefix sum of nums array.
    int n = nums.size();
    std::vector prefixSum(n + 1, 0);
    for (int i = 0; i < n; i++) {
      prefixSum[i + 1] = prefixSum[i] + nums[i];
    }

    return getMinimumLargestSplitSum(prefixSum, 0, m);
  }

  // Time Limit Exceeded
  int splitArray_jhonny(std::vector<int>& nums, int k) {
    std::unordered_map<std::string, int> map;
    std::vector<int> results;
    return dp(nums, 0, k - 1, 0, results, &map);
  }

  int dp(std::vector<int>& nums, int position, int k, int acc, std::vector<int> previous,
         std::unordered_map<std::string, int>* map) {
    std::string key =
        std::to_string(position) + "," + std::to_string(k) + "," + std::to_string(acc);
    for (auto item : previous) {
      key += std::to_string(item);
    }
    if (map->find(key) != map->end()) return (*map)[key];

    if (position >= nums.size()) {
      auto max = std::numeric_limits<int>::min();
      for (int previou : previous) {
        max = std::max(max, previou);
      }
      return std::max(max, acc);
    }

    auto sum = dp(nums, position + 1, k, acc + nums[position], previous, map);
    auto split = std::numeric_limits<int>::max();

    if (k > 0) {
      previous.push_back(acc + nums[position]);
      split = dp(nums, position + 1, k - 1, 0, previous, map);
    }

    auto ret = std::min(sum, split);
    (*map)[key] = ret;
    return ret;
  }
};

TEST(split_array_largest_sum, test_one) {
  Solution solution;
  std::vector<int> input = {7, 2, 5, 10, 8};
  ASSERT_EQ(18, solution.splitArray(input, 2));
}

TEST(split_array_largest_sum, test_two) {
  Solution solution;
  std::vector<int> input = {2, 3, 1, 2, 4, 3};
  ASSERT_EQ(4, solution.splitArray(input, 5));
}

TEST(split_array_largest_sum, test_three) {
  Solution solution;
  std::vector<int> input = {2, 3, 1, 1, 1, 1, 1};
  ASSERT_EQ(3, solution.splitArray(input, 5));
}
