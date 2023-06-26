// https://leetcode.com/problems/binary-tree-inorder-traversal/description/

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

class Solution
{
    void inorder(TreeNode *root, vector<int> &node)
    {
        if (!root)
            return;
        inorder(root->left, node);
        node.push_back(root->val);
        inorder(root->right, node);
    }
    vector<int> recur(TreeNode *root)
    {
        vector<int> nodes;
        inorder(root, nodes);
        return nodes;
    }
    vector<int> itter(TreeNode *root)
    {
        if (!root)
            return {};
        vector<int> nodes;
        stack<TreeNode *> s;
        TreeNode *currNode = root;
        while (currNode || !s.empty())
        {
            if (currNode)
            {
                s.push(currNode);
                currNode = currNode->left;
            }
            else
            {
                currNode = s.top();
                s.pop();
                nodes.push_back(currNode->val);
                currNode = currNode->right;
            }
        }
        return nodes;
    }

public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        return itter(root);
    }
};