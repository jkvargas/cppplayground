// https://leetcode.com/explore/featured/card/top-interview-questions-easy/96/sorting-and-searching/774/

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);
#include <cmath>

class Solution {
public:
    bool isBadVersion(int version);

    int firstBadVersion(int n) {
        int left = 1;
        int right = n;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (isBadVersion(mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};