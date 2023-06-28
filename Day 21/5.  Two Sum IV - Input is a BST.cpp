// https://leetcode.com/problems/two-sum-iv-input-is-a-bst/description/


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
    bool find(TreeNode* root, int &k, unordered_set<int> &s) {
        if (!root) return false;
        if (s.count(k-root->val)) return true;
        s.insert(root->val);
        return find(root->left, k, s) || find(root->right, k, s);
    }
public:
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> s;
        return find(root, k, s);
    }
};