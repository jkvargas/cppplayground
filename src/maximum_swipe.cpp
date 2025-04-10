// https://leetcode.com/problems/maximum-swap/description/?envType=company&envId=facebook&favoriteSlug=facebook-thirty-days

#include <gtest/gtest.h>

#include <queue>
#include <string>
#include <unordered_set>

class Item {
 public:
  int position;
  int value;

  explicit Item(int position, int value) : position(position), value(value) {}
  bool operator<(const Item &other) const { return value < other.value; }
};

class Solution {
 public:
  int maximumSwap(int num) {
    std::string numStr = std::to_string(num);
    int n = numStr.size();
    int maxDigitIndex = -1, swapIdx1 = -1, swapIdx2 = -1;

    // Traverse the string from right to left, tracking the max digit and
    // potential swap
    for (int i = n - 1; i >= 0; --i) {
      if (maxDigitIndex == -1 || numStr[i] > numStr[maxDigitIndex]) {
        maxDigitIndex = i;  // Update the index of the max digit
      } else if (numStr[i] < numStr[maxDigitIndex]) {
        swapIdx1 = i;              // Mark the smaller digit for swapping
        swapIdx2 = maxDigitIndex;  // Mark the larger digit for swapping
      }
    }

    // Perform the swap if a valid swap is found
    if (swapIdx1 != -1 && swapIdx2 != -1) {
      std::swap(numStr[swapIdx1], numStr[swapIdx2]);
    }

    return stoi(numStr);  // Return the new number or the original if no
    // swap occurred
  }

  int maximumSwap_Jhonny(int num) {
    auto number = std::to_string(num);
    std::priority_queue<Item> queue;

    for (int i = 0; i < number.size(); ++i) {
      auto item = Item(i, number[i] - '0');
      queue.push(item);
    }

    for (int order = 0; order < number.size(); order++) {
      auto val_to_compare = number[order] - '0';
      auto highest = queue.top();
      if (highest.value > val_to_compare && highest.position > order) {
        auto temp = number[order];
        number[order] = '0' + highest.value;
        number[highest.position] = temp;
        queue.pop();
        break;
      }
      order++;
    }

    return std::stoi(number);
  }
};

TEST(maximum_swipe, test_one) {
  Solution solution;
  ASSERT_EQ(7236, solution.maximumSwap(2736));
}

TEST(maximum_swipe, test_two) {
  Solution solution;
  ASSERT_EQ(9973, solution.maximumSwap(9973));
}

TEST(maximum_swipe, test_three) {
  Solution solution;
  ASSERT_EQ(9913, solution.maximumSwap(1993));
}
