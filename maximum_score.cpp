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

    auto hash = hashFunction(pos_right, pos_left, pos_mul);

    if (map.contains(hash))
        return map[hash];

    auto left = multipliers[pos_mul] * nums[pos_left] + calc(pos_right, pos_left + 1, nums, pos_mul + 1, multipliers, map);
    auto right = multipliers[pos_mul] * nums[pos_right] + calc(pos_right - 1, pos_left, nums, pos_mul + 1, multipliers, map);

    return map[hash] = max(left, right);
}

std::size_t maximum_score::hashFunction(int pos_right, int pos_left, int pos_mul) {
    std::size_t hash_value = 0;

    hash_value += 3 * pos_right;
    hash_value += 5 * pos_left;
    hash_value += 7 * pos_mul;

    return hash_value;
}
