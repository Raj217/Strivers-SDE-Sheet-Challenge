// https://leetcode.com/problems/binary-tree-maximum-path-sum/description/

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
    int sum(TreeNode* root, int &maxSum) {
        if (!root) return 0;
        int left = sum(root->left, maxSum);
        int right = sum(root->right, maxSum);
        int maxi = max({left+root->val, right+root->val, root->val});
        maxSum = max({maxSum, maxi, left+right+root->val});
        return maxi;
    }
public:
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        sum(root, maxSum);
        return maxSum;
    }
};