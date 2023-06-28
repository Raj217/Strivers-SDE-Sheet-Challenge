// https://leetcode.com/problems/validate-binary-search-tree/description/


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
    bool isValid(TreeNode* root, long long smallestParent, long long largestParent) {
        if (!root) return true;
        if (root->val <= smallestParent || root->val >= largestParent) return false;
        return isValid(root->left, smallestParent, root->val) && isValid(root->right, root->val, largestParent);
    }
public:
    bool isValidBST(TreeNode* root) {
        return isValid(root, LLONG_MIN, LLONG_MAX);
    }
};