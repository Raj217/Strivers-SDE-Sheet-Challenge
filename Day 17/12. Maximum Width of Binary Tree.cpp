// https://leetcode.com/problems/maximum-width-of-binary-tree/description/


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
    int height(TreeNode* root) {
        return !root ? 0 : max(height(root->left), height(root->right))+1;
    }
    void dfs(TreeNode* root, vector<pair<unsigned long long, unsigned long long>> &edges, int level, unsigned long long pos) {
        if (!root) return;
        edges[level].first = min(edges[level].first, pos);
        edges[level].second = max(edges[level].second, pos);
        dfs(root->left, edges, level+1, 2*pos);
        dfs(root->right, edges, level+1, 2*pos+1);
    }
public:
    int widthOfBinaryTree(TreeNode* root) {
        vector<pair<unsigned long long, unsigned long long>> edges(height(root), {ULLONG_MAX, 0});
        dfs(root, edges, 0, 0);
        unsigned long long maxWidth = 0;
        for (auto edge: edges) {
            maxWidth = max(maxWidth, edge.second - edge.first + 1);
        }
        return maxWidth;
    }
};