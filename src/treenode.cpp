//
// Created by jhonny on 4/14/24.
//

#include "treenode.h"

TreeNode *TreeNode::from(std::vector<std::optional<int> > values) { return fill(0, values); }

std::vector<std::optional<int> > TreeNode::toVector() const {
  std::vector<std::optional<int> > result;
  toVectorHelper(result, 0);
  return result;
}

void TreeNode::toVectorHelper(std::vector<std::optional<int> > &out, int index) const {
  if (index >= out.size()) {
    out.resize(index + 1);  // Fill with std::nullopt
  }

  out[index] = val;

  if (left) {
    left->toVectorHelper(out, index * 2 + 1);
  }

  if (right) {
    right->toVectorHelper(out, index * 2 + 2);
  }
}

TreeNode *TreeNode::fill(int index, std::vector<std::optional<int> > &values) {
  if (values[index].has_value()) {
    auto result = new TreeNode(values[index].value(), nullptr, nullptr);

    if (index * 2 + 1 < values.size()) {
      result->left = fill(index * 2 + 1, values);
    }

    if (index * 2 + 2 < values.size()) {
      result->right = fill(index * 2 + 2, values);
    }

    return result;
  }

  return nullptr;
}

void TreeNode::deleteTree(TreeNode *root) {
  if (root == nullptr) return;

  deleteTree(root->left);
  deleteTree(root->right);

  delete root;
}
