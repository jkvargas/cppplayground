//
// Created by jhonny on 4/14/24.
//

#ifndef CPPPLAYGROUND_LOWEST_COMMON_ANCESTOR_H
#define CPPPLAYGROUND_LOWEST_COMMON_ANCESTOR_H

#include <vector>
#include <unordered_set>
#include "treenode.h"

// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree-iv/description/?envType=study-plan-v2&envId=amazon-spring-23-high-frequency

using namespace std;

class lowest_common_ancestor {
    TreeNode* dfs(TreeNode *root, unordered_set<TreeNode*> nodesSet) {
        if (!root) return nullptr;
        if (nodesSet.count(root)==1) return root;
        TreeNode* left = dfs(root->left,nodesSet);
        TreeNode* right = dfs(root->right,nodesSet);
        if (left && right) return root;
        else if (left) return left;
        else return right;
    }

public:
    TreeNode *lowestCommonAncestor(TreeNode *root, vector<TreeNode *> &nodes) {
        unordered_set<TreeNode*> nodesSet(nodes.begin(),nodes.end());
        return dfs(root, nodesSet);
    }
};


#endif //CPPPLAYGROUND_LOWEST_COMMON_ANCESTOR_H
