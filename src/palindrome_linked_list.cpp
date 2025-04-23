// https://leetcode.com/explore/interview/card/top-interview-questions-easy/93/linked-list/772/

#include <vector>
#include <gtest/gtest.h>

  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
      static void deleteNode(ListNode *node) { if (node->next != nullptr) deleteNode(node->next); delete node;}
  };

class Solution {
public:
    ListNode* frontPointer;

    bool isPalindrome(ListNode *head) {
        frontPointer = head;
        return check(head);
    }

    bool check(ListNode* current_node) {
        if (current_node != nullptr) {
            if (!check(current_node->next)) return false;
            if (current_node->val != frontPointer->val) return false;
            frontPointer = frontPointer->next;
        }

        return true;
    }

    bool isPalindrome_jhonny(ListNode* head) {
        std::vector<int> nums;

        while (head != nullptr) {
            nums.push_back(head->val);
            head = head->next;
        }

        auto right = nums.size() - 1;
        auto left = 0;

        while (left < right) {
            if (nums[left++] != nums[right--]) {
                return false;
            }
        }

        return true;
    }
};

TEST(palindrome_linked_list, test_one) {
    auto solution = Solution();
    ListNode *head = new ListNode(1, new ListNode(2, new ListNode(2, new ListNode(1))));
    ASSERT_TRUE(solution.isPalindrome(head));
    ListNode::deleteNode(head);
}
