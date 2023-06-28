// https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/


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
    int find(TreeNode* root, int &k) {
        if (!root) return -1;
        int left = find(root->left, k);
        if (left != -1) return left;
        k--;
        if (k == 0) return root->val;
        int right = find(root->right, k);
        return max(left, right);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        return find(root, k);
    }
};