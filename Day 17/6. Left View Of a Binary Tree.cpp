// https://www.codingninjas.com/codestudio/problems/920519?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=1

#include <bits/stdc++.h>
using namespace std;

template <typename T>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

int height(TreeNode<int> *root)
{
    return !root ? 0 : max(height(root->left), height(root->right)) + 1;
}

void preorder(TreeNode<int> *root, vector<int> &nodes, int level)
{
    if (!root)
        return;
    if (nodes[level] == -1)
        nodes[level] = root->data;
    preorder(root->left, nodes, level + 1);
    preorder(root->right, nodes, level + 1);
}

vector<int> getLeftView(TreeNode<int> *root)
{
    vector<int> nodes(height(root), -1);
    preorder(root, nodes, 0);
    return nodes;
}