//
// Created by jhonny on 7/6/25.
//

#include <gtest/gtest.h>
#include "treenode.h"

class Solution {
 public:
  void flatten(TreeNode *root) { flattenTree(root); }

 private:
  TreeNode *flattenTree(TreeNode *root) {
    if (root == nullptr) {
      return nullptr;
    }
    if (root->left == nullptr && root->right == nullptr) {
      return root;
    }

    auto left = flattenTree(root->left);
    auto right = flattenTree(root->right);

    if (left != nullptr) {
      left->right = root->right;
      root->right = root->left;
      root->left = nullptr;
    }

    return right == nullptr ? left : right;
  }
};

TEST(flatten_binary_tree_to_linked_list, test_one) {
  Solution solution;

  std::vector<std::optional<int>> items = {1, 2, 5, 3, 4, std::nullopt, 6};
  auto tree = TreeNode::from(items);
  solution.flatten(tree);
  auto result = tree->toVector();
  std::vector<std::optional<int>> expected = {
    1, std::nullopt,
    2, std::nullopt,
    3, std::nullopt,
    4, std::nullopt,
    5, std::nullopt,
    6
};
  ASSERT_EQ(expected, result);
}
