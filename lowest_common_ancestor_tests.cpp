//
// Created by jhonny on 4/14/24.
//

#include <gtest/gtest.h>
#include "lowest_common_ancestor.h"

TEST(LCA, TestOne) {
    auto values = vector<optional<int>> { 3, 5, 1, 6, 2, 0, 8, nullopt, nullopt, 7, 4};
    auto treeNode = TreeNode::from(values);

    auto solution = lowest_common_ancestor();
    auto nodes = vector<TreeNode*>();
    nodes.push_back(new TreeNode(4));
    nodes.push_back(new TreeNode(7));

    auto result = solution.lowestCommonAncestor(treeNode, nodes);

    try {
        ASSERT_EQ(2, result->val);

        for ( auto item: nodes) {
            delete item;
        }
        delete result;
    }
    catch (const std::exception& exception) {
        for ( auto item: nodes) {
            delete item;
        }
        
        delete result;
        throw exception;
    }
}