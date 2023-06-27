// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/description/

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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<pair<int, int>, vector<int>> nodes;
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, 0}});
        int lowerC = INT_MAX, higherC = INT_MIN;
        while (!q.empty()) {
            TreeNode* curr = q.front().first;
            int c = q.front().second.first;
            int r = q.front().second.second;
            lowerC = min(c, lowerC);
            higherC = max(c, higherC);
            q.pop();
            nodes[{c, r}].push_back(curr->val);
            if (curr->left) {
                q.push({curr->left, {c-1, r+1}});
            }
            if (curr->right) {
                q.push({curr->right, {c+1, r+1}});
            }
        }
        vector<vector<int>> ans(higherC-lowerC+1);
        for (auto node: nodes) {
            vector<int> v = node.second;
            sort(v.begin(), v.end());
            int ind = node.first.first-lowerC;
            ans[ind].insert(ans[ind].end(), v.begin(), v.end());
        }
        return ans;
    }
};