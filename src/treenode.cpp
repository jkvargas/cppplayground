//
// Created by jhonny on 4/14/24.
//

#include "treenode.h"

TreeNode *TreeNode::from(std::vector<std::optional<int>> values) {
    return fill(0, values);
}

TreeNode *TreeNode::fill(int index, std::vector<std::optional<int>> &values) {
    if (values[index].has_value()) {
        auto result = new TreeNode(values[index].value(), nullptr, nullptr);

        if ( index * 2 + 1 < values.size()) {
            result->left = fill(index * 2 + 1, values);
        }

        if ( index * 2 + 2 < values.size()) {
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