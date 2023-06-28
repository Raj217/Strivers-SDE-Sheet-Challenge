// https://leetcode.com/problems/binary-search-tree-iterator/submissions/981895019/


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


class BSTIterator {
    stack<TreeNode*> st;
    void pushAll(TreeNode* root) {
        while (root) {
            st.push(root);
            root = root->left;
        }
    }
public:
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }
    
    int next() {
        TreeNode* curr = st.top(); st.pop();
        pushAll(curr->right);
        return curr->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};