//
// Created by jhonny on 2/25/24.
//

#include "maximum_score.h"
#include <algorithm>

int maximum_score::maximumScore(vector<int> &nums, vector<int> &multipliers) {
    auto map = unordered_map<size_t, int>();
    return calc(nums.size() - 1, 0, nums, 0, multipliers, map);
}

int maximum_score::calc(int pos_right, int pos_left, vector<int>& nums, int pos_mul, vector<int>& multipliers, unordered_map<size_t, int> &map) {
    if (pos_mul == multipliers.size())
        return 0;

    size_t hash = (pos_mul << 20) ^ (pos_left << 10) ^ pos_right;

    if (map.contains(hash))
        return map[hash];

    auto left = multipliers[pos_mul] * nums[pos_left] + calc(pos_right, pos_left + 1, nums, pos_mul + 1, multipliers, map);
    auto right = multipliers[pos_mul] * nums[pos_right] + calc(pos_right - 1, pos_left, nums, pos_mul + 1, multipliers, map);

    map[hash] = max(left, right);

    return map[hash];
}

// A better solution
//class Solution {
//public:
//
//    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
//        int m=multipliers.size();
//        if(m==0) return 0;
//
//        vector t(m+1, vector<int>(m+1, INT_MIN));
//
//        return helper(nums, multipliers, t, 0,0);
//    }
//
//    int helper(vector<int>& nums, vector<int>& multipliers, vector<vector<int>>& t, int op, int left){
//        if(op ==  multipliers.size()) return 0;
//
//        if(t[op][left]!=INT_MIN) return t[op][left];
//
//        int n=nums.size();
//        return t[op][left]=max((helper(nums, multipliers, t, op+1, left+1)+ multipliers[op]*nums[left]), (helper(nums, multipliers, t, op+1, left)+multipliers[op]*nums[n-1-(op-left)]));
//
//    }
//};