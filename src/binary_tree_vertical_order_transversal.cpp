// https://leetcode.com/problems/binary-tree-vertical-order-traversal/?envType=company&envId=facebook&favoriteSlug=facebook-thirty-days

#include "treenode.h"
#include <vector>
#include <gtest/gtest.h>

/**
* Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int max_index, min_index;

    // std::vector<std::vector<int>> verticalOrder(TreeNode* root) {
    //     std::unordered_map<int, std::vector<int>> mid;
    //     dfs(root, 0, mid, );
    //
    //     std::vector<std::vector<int>> result;
    //     for (auto i = min_index; i <= max_index; i++) {
    //         result.push_back(std::move(mid.at(i)));
    //     }
    //
    //     return result;
    // }

    void dfs(TreeNode* node, int column, int line, std::unordered_map<int, std::vector<int>> &result) {
        if (node == nullptr) return;
        max_index = std::max(max_index, column);
        min_index = std::min(min_index, column);

        if (node->left != nullptr) dfs(node->left, column - 1, line + 1, result);

        if (!result.contains(column)) result.emplace(column, std::vector<int>());
        result.at(column).push_back(node->val);

        if (node->right != nullptr) dfs(node->right, column + 1, line + 1, result);
    }
};

// TEST(binary_tree_vertical_order_transversal, test_two) {
//     std::vector<std::optional<int>> items = {3,9,8,4,0,1,7};
//     auto node = TreeNode::from(items);
//     auto solution = Solution();
//     auto result = solution.verticalOrder(node);
//
//     std::vector<std::vector<int>> vec = { { 4 }, { 0, 3, 1 }, { 1, 2 } };
//
//     for (int i = 0; i < vec.size(); i++) {
//         ASSERT_EQ(vec[i], result[i]);
//     }
// }
//
// TEST(binary_tree_vertical_order_transversal, test_one) {
//     std::vector<std::optional<int>> items = {3, 9, 20, std::nullopt, std::nullopt, 15, 7};
//     auto node = TreeNode::from(items);
//     auto solution = Solution();
//     auto result = solution.verticalOrder(node);
//
//     std::vector first = { 9 };
//     std::vector sec =  { 3, 15 };
//     std::vector three = { 20 };
//     std::vector four = { 7 };
//
//     ASSERT_EQ(first, result[0]);
//     ASSERT_EQ(sec, result[1]);
//     ASSERT_EQ(three, result[2]);
//     ASSERT_EQ(four, result[3]);
// }