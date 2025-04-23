// https://leetcode.com/problems/reorder-list/

#include <gtest/gtest.h>

#include <vector>

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  void reorderList(ListNode* head) {
    std::vector<int> nums;
    feed(head, nums);
    go(nums, 0, head, head->next);
  }

  void go(std::vector<int>& nums, int position, ListNode* first, ListNode* sec) {
    if (first != nullptr) first->val = nums[position];

    if (sec != nullptr) sec->val = nums[nums.size() - 1 - position];

    if ((first == nullptr || first->next == nullptr) && (sec == nullptr || sec->next == nullptr))
      return;

    go(nums, position + 1, first->next != nullptr ? first->next->next : nullptr,
       sec->next != nullptr ? sec->next->next : nullptr);
  }

  void feed(ListNode* node, std::vector<int>& nums) {
    if (node == nullptr) {
      return;
    }
    nums.push_back(node->val);
    feed(node->next, nums);
  }
};