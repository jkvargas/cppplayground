// https://leetcode.com/explore/interview/card/facebook/52/trees-and-graphs/544/

#include <gtest/gtest.h>

#include <algorithm>
#include <vector>

#include "treenode.h"

typedef TreeNode Node;

class Helper {
 public:
  explicit Helper(Node* node) : m_node{node} {}
  Node* m_node;

  bool operator<(const Helper& other) { return this->m_node->val < other.m_node->val; }
};

class Solution {
 public:
  Node* first = NULL;
  Node* last = NULL;

  void helper(Node* node) {
    if (node) {
      // left
      helper(node->left);

      // node
      if (last) {
        // link the previous node (last)
        // with the current one (node)
        last->right = node;
        node->left = last;
      } else {
        // keep the smallest node
        // to close DLL later on
        first = node;
      }
      last = node;

      // right
      helper(node->right);
    }
  }

  Node* treeToDoublyList(Node* root) {
    if (!root) return NULL;

    helper(root);

    // close DLL
    last->right = first;
    first->left = last;
    return first;
  }

  Node* treeToDoublyList_jhonny(Node* root) {
    if (root == nullptr) return nullptr;

    auto helper_list = std::vector<Helper>{};
    feed_dfs(root, helper_list);
    std::sort(helper_list.begin(), helper_list.end());

    for (auto i = 0; i < helper_list.size(); i++) {
      helper_list[i].m_node->left = helper_list[i == 0 ? helper_list.size() - 1 : i - 1].m_node;
      helper_list[i].m_node->right = helper_list[i == helper_list.size() - 1 ? 0 : i + 1].m_node;
    }

    return helper_list[0].m_node;
  }

  void feed_dfs(Node* node, std::vector<Helper>& helper_list) {
    if (node != nullptr) {
      helper_list.emplace_back(node);

      feed_dfs(node->right, helper_list);
      feed_dfs(node->left, helper_list);
    }
  }
};

TEST(convert_binary_tree_to_sorted_doubly_linked_list, test_one) {
  std::vector<std::optional<int>> items = {4, 2, 5, 1, 3};
  auto tree_node = Node::from(items);
  auto solution = Solution{};
  auto result = solution.treeToDoublyList(tree_node);

  for (int i = 1; i < 6; i++) {
    ASSERT_EQ(i, result->val);
    ASSERT_EQ(i == 1 ? 5 : i - 1, result->left->val);
    ASSERT_EQ(i == 5 ? 1 : i + 1, result->right->val);

    result = result->right;
  }

  delete tree_node;
}
