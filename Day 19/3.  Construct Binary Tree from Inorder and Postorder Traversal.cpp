// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/

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
    TreeNode* build(vector<int> &inorder, vector<int> &postorder, int inStart, int inEnd, int poStart, int poEnd, unordered_map<int, int> &inPos) {
        if (inStart > inEnd || poStart > poEnd) return NULL;

        TreeNode* root = new TreeNode(postorder[poEnd]);
        
        int inorderPos = inPos[postorder[poEnd]];
        int right = inEnd - inorderPos;

        root->right = build(inorder, postorder, inorderPos+1, inEnd, poEnd-right, poEnd-1, inPos);
        root->left = build(inorder, postorder, inStart, inorderPos-1, poStart, poEnd-right-1, inPos);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> inPos;
        int n = inorder.size();

        for (int i=0; i<n; i++) {
            inPos[inorder[i]] = i;
        }
        return build(inorder, postorder, 0, n-1, 0, n-1, inPos);
    }
};