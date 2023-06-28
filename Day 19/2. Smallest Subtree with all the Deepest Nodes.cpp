// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/

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
    TreeNode* build(vector<int> &preorder, vector<int> &inorder, int preStart, int preEnd, int inStart, int inEnd, unordered_map<int, int> &inorderPos) {
        if (preStart > preEnd || inStart > inEnd) return NULL;

        TreeNode* root = new TreeNode(preorder[preStart]);
        int inorderInd = inorderPos[preorder[preStart]];
        
        int left = inorderInd - inStart;

        root->left = build(preorder, inorder, preStart+1, preStart+left, inStart, inorderInd-1, inorderPos);
        root->right = build(preorder, inorder, preStart+left+1, preEnd, inorderInd+1, inEnd, inorderPos);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inorderPos;
        int n = inorder.size();

        for (int i=0; i<n; i++) {
            inorderPos[inorder[i]] = i;
        }
        return build(preorder, inorder, 0, n-1, 0, n-1, inorderPos);
    }
};