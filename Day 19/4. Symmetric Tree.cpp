// https://leetcode.com/problems/symmetric-tree/description/

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
    bool traverse(TreeNode* left, TreeNode* right) {
        if (!left && !right) return true;
        if ((!left && right) || (left && !right)) return false;
        if (left->val != right->val) return false;
        return traverse(left->left, right->right) && traverse(left->right, right->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        if (!root || (!root->left && !root->right)) return true;
        if ((!root->left && root->right) || (root->left && !root->right)) return false;
        return traverse(root->left, root->right);
    }
};