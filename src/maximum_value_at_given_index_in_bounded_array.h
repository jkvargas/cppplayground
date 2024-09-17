//
// Created by jhonny on 8/3/23.
//

#ifndef CPPPLAYGROUND_MAXIMUM_VALUE_AT_GIVEN_INDEX_IN_BOUNDED_ARRAY_H
#define CPPPLAYGROUND_MAXIMUM_VALUE_AT_GIVEN_INDEX_IN_BOUNDED_ARRAY_H

// https://leetcode.com/problems/maximum-value-at-a-given-index-in-a-bounded-array/

#include <vector>

class maximum_value_at_given_index_in_bounded_array {
public:
    int maxValue(int n, int index, int maxSum);

private:
    long getSum(int index, int value, int n);
};


#endif //CPPPLAYGROUND_MAXIMUM_VALUE_AT_GIVEN_INDEX_IN_BOUNDED_ARRAY_H
