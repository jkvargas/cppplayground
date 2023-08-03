// https://leetcode.com/problems/soup-servings/

#ifndef CPPPLAYGROUND_SOUP_SERVINGS_H
#define CPPPLAYGROUND_SOUP_SERVINGS_H

#include <unordered_map>

using namespace std;

class Solution {
public:
    double soupServings(int n);
private:
    double dp(int a, int b, std::unordered_map<int, double>& memo);
};
#endif //CPPPLAYGROUND_SOUP_SERVINGS_H
