// https://leetcode.com/problems/binary-tree-level-order-traversal/description/

#include <bits/stdc++.h>
using namespace std;


struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> nodes;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while (!q.empty()) {
            TreeNode* curr = q.front().first;
            int level = q.front().second;
            q.pop();
            if (level == nodes.size()) nodes.push_back({});
            nodes[level].push_back(curr->val);

            if (curr->left) q.push({curr->left, level+1});
            if (curr->right) q.push({curr->right, level+1});
        }
        return nodes;
    }
};