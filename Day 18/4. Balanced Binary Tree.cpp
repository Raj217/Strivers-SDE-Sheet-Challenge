// https://leetcode.com/problems/balanced-binary-tree/description/

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
    int height(TreeNode* root, bool &isHeightBalanced) {
        if (!root) return 0;
        int left = height(root->left, isHeightBalanced);
        int right = height(root->right, isHeightBalanced);
        if (abs(left-right) > 1) isHeightBalanced = false;
        return max(left, right)+1;
    }
public: 
    bool isBalanced(TreeNode* root) {
        bool isHeightBalanced = true;
        height(root, isHeightBalanced);
        return isHeightBalanced;
    }
};