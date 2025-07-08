//
// Created by jhonny on 4/14/24.
//

#ifndef CPPPLAYGROUND_TREENODE_H
#define CPPPLAYGROUND_TREENODE_H

#include <optional>
#include <vector>

class TreeNode {
 public:
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}

  static TreeNode* from(std::vector<std::optional<int>> values);
  std::vector<std::optional<int>> toVector() const;

  ~TreeNode() { deleteTree(this); }

 protected:
  void toVectorHelper(std::vector<std::optional<int>>& out, int index) const;
  static TreeNode* fill(int index, std::vector<std::optional<int>>& values);
  static void deleteTree(TreeNode* root);
};

#endif  // CPPPLAYGROUND_TREENODE_H