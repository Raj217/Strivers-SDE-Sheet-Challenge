// https://leetcode.com/problems/binary-tree-postorder-traversal/submissions/979879306/


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
    void postOrder(TreeNode* root, vector<int> &nodes) {
        if (!root) return;
        postOrder(root->left, nodes);
        postOrder(root->right, nodes);
        nodes.push_back(root->val);
    }
    vector<int> recur(TreeNode* root) {
        vector<int> nodes;
        postOrder(root, nodes);
        return nodes;
    }
    vector<int> itter(TreeNode* root) {
        vector<int> nodes;
        stack<TreeNode*> st;
        TreeNode* curr = root, *prev=NULL;
        while (curr || !st.empty()) {
            if (curr) {
                st.push(curr);
                curr = curr->left;
            } else {
                curr = st.top(); 
                if (curr->right == prev || !curr->right) {
                    nodes.push_back(curr->val);
                    prev = curr;
                    curr = NULL;
                    st.pop();
                } else {
                    curr = curr->right;
                }
            }
        } 
        return nodes;
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        return itter(root);
    }
};