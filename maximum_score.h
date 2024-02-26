//
// Created by jhonny on 2/25/24.
//

#ifndef CPPPLAYGROUND_MAXIMUM_SCORE_H
#define CPPPLAYGROUND_MAXIMUM_SCORE_H

// https://leetcode.com/problems/maximum-score-from-performing-multiplication-operations/

#include <vector>
#include <unordered_map>

using namespace std;

class maximum_score {
public:
    int maximumScore(vector<int> &nums, vector<int> &multipliers);

private:
    int calc(int pos_right, int pos_left, vector<int> &nums, int pos_mul, vector<int> &multipliers, unordered_map<size_t, int> &map);
};


#endif //CPPPLAYGROUND_MAXIMUM_SCORE_H
