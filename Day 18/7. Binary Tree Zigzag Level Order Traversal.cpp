// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/

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
    void traverse(TreeNode* root, int level, vector<vector<int>> &ans) {
        if (!root) return;
        if (level == ans.size()) ans.push_back({});
        ans[level].push_back(root->val);
        traverse(root->left, level+1, ans);
        traverse(root->right, level+1, ans);
    }
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        traverse(root, 0, ans);
        for (int i=0; i<ans.size(); i++) {
            if (i%2 == 1) reverse(ans[i].begin(), ans[i].end());
        }
        return ans;
    }
};