//https://leetcode.com/problems/sort-linked-list-already-sorted-using-absolute-values/description/?envType=study-plan-v2&envId=tiktok-spring-23-high-frequency

#include <gtest/gtest.h>

#include <algorithm>
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
  ListNode* sortLinkedList(ListNode* head) {
    ListNode* node = head;
    ListNode* prev = nullptr;

    while (node) {
      if (prev && prev->val == -1 * node->val) {
        if (prev->val < node->val) {
          std::swap(prev->val, node->val);
        }
      }
      if (prev && prev->val > node->val) {
        prev->next = node->next;
        node->next = head;
        head = node;
        node = prev->next;
      } else {
        prev = node;
        node = node->next;
      }
    }
    return head;
  }

  ListNode* sortLinkedList_jho(ListNode* head) {
    std::vector<ListNode*> nodes;
    auto ptr = head;

    while (ptr != nullptr) {
      nodes.push_back(ptr);
      ptr = ptr->next;
    }

    std::sort(nodes.begin(), nodes.end(), [](ListNode* a, ListNode* b) { return a->val < b->val; });

    for (int i = 0; i < nodes.size(); i++) {
      if (i + 1 < nodes.size()) {
        nodes[i]->next = nodes[i + 1];
      }
    }

    nodes[nodes.size() - 1]->next = nullptr;

    return nodes[0];
  }
};

void free_list_node(ListNode* treeNode) {
  if (treeNode->next != nullptr) {
    free_list_node(treeNode->next);
  }
  delete treeNode;
}

TEST(sort_linked_list_already_sorted_using_absolute_values, test_one) {
  ListNode* ln = new ListNode(
      0, new ListNode(2, new ListNode(-5, new ListNode(5, new ListNode(10, new ListNode(-10))))));
  Solution sol;
  sol.sortLinkedList(ln);
  free_list_node(ln);
}