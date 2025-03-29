// https://leetcode.com/problems/minimum-size-subarray-sum/editorial/?envType=study-plan-v2&envId=tiktok-spring-23-high-frequencys

#include <vector>
#include <gtest/gtest.h>

class Solution {
public:
    int minSubArrayLen(int target, std::vector<int>& nums) {
        int left = 0, right = 0, sumOfCurrentWindow = 0;
        int res = INT_MAX;

        for(right = 0; right < nums.size(); right++) {
            sumOfCurrentWindow += nums[right];

            while (sumOfCurrentWindow >= target) {
                res = std::min(res, right - left + 1);
                sumOfCurrentWindow -= nums[left];
                left++;
            }
        }

        return res == INT_MAX ? 0 : res;
    }
};

TEST(min_sum_subarray_size, test_one) {
    Solution solution;
    std::vector<int> nums = {2, 3, 1, 2, 4, 3};
    ASSERT_EQ(2, solution.minSubArrayLen(7, nums));
}

TEST(min_sum_subarray_size, test_two) {
    Solution solution;
    std::vector<int> nums = {1,4,4};
    ASSERT_EQ(1, solution.minSubArrayLen(4, nums));
}

TEST(min_sum_subarray_size, test_three) {
    Solution solution;
    std::vector<int> nums = {1,1,1,1,1,1,1,1};
    ASSERT_EQ(0, solution.minSubArrayLen(11, nums));
}

TEST(min_sum_subarray_size, test_four) {
    Solution solution;
    std::vector<int> nums = {1,2,3,4,5};
    ASSERT_EQ(5, solution.minSubArrayLen(15, nums));
}

TEST(min_sum_subarray_size, test_five) {
    Solution solution;
    std::vector<int> nums = {12,28,83,4,25,26,25,2,25,25,25,12};
    ASSERT_EQ(8, solution.minSubArrayLen(213, nums));
}