// https://leetcode.com/problems/binary-tree-preorder-traversal/description/

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
    void preorder(TreeNode* root, vector<int> &nodes) {
        if (!root) return;
        nodes.push_back(root->val);
        preorder(root->left, nodes);
        preorder(root->right, nodes);
    }
    vector<int> recur(TreeNode* root) {
        vector<int> nodes;
        preorder(root, nodes);
        return nodes;
    }
    vector<int> itter(TreeNode* root) {
        vector<int> nodes;
        stack<TreeNode*> st;
        TreeNode* curr = root;
        while (curr || !st.empty()) {
            if (curr) {
                nodes.push_back(curr->val);
                st.push(curr);
                curr = curr->left;
            } else {
                curr = st.top(); st.pop();
                curr = curr->right;
            }
        }
        return nodes;
    }
    vector<int> morris(TreeNode* root) {
        vector<int> nodes;
        TreeNode* curr = root, *temp;
        while (curr) {
            if (!curr->left) {
                nodes.push_back(curr->val);
                curr = curr->right;
            } else {
                temp = curr->left;
                while (temp->right && temp->right != curr) temp = temp->right;
                if (temp->right == curr) {
                    temp->right = NULL;
                    curr = curr->right;
                } else {
                    nodes.push_back(curr->val);
                    temp->right = curr;
                    curr = curr->left;
                }
            }
        }
        return nodes;
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        return morris(root);
    }
};

