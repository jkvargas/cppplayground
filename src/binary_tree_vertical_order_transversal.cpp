// https://leetcode.com/problems/binary-tree-vertical-order-traversal/?envType=company&envId=facebook&favoriteSlug=facebook-thirty-days

#include <queue>
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

    std::vector<std::vector<int>> verticalOrder(TreeNode* root) {
        std::vector<std::vector<int>> result{};
        if (root == nullptr) return result;

        std::unordered_map<int, std::vector<int>> columnTable{};
        std::queue<std::pair<TreeNode*, int>> queue{};
        int column = 0;

        queue.emplace(root, column);

        while (!queue.empty()) {
            auto p = queue.front();
            queue.pop();

            auto item = p.first;
            auto col = p.second;

            if (item != nullptr) {
                if (!columnTable.contains(col)) {
                    auto list = std::vector<int>{};
                    columnTable.emplace(col, list);
                }
                columnTable.at(col).push_back(item->val);
                queue.emplace(item->left, col - 1);
                queue.emplace(item->right, col + 1);
            }
        }

        std::vector<int> keys{};
        for (const auto& [key, _] : columnTable) {
            keys.push_back(key);
        }

        std::sort(keys.begin(), keys.end());

        for(int k : keys) {
            result.push_back(columnTable.at(k));
        }

        return result;
    }
};

TEST(binary_tree_vertical_order_transversal, test_two) {
    std::vector<std::optional<int>> items = {3,9,20,std::nullopt,std::nullopt,15,7};
    auto node = TreeNode::from(items);
    auto solution = Solution();
    auto result = solution.verticalOrder(node);

    std::vector<std::vector<int>> vec = { { 9 }, { 3, 15 }, {20}, {7} };

    for (int i = 0; i < vec.size(); i++) {
        ASSERT_EQ(vec[i], result[i]);
    }
}