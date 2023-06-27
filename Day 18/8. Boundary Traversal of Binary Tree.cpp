// https://www.codingninjas.com/studio/problems/boundary-traversal_790725?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

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

    ~TreeNode()
    {
        if (left)
            delete left;
        if (right)
            delete right;
    }
};

bool isLeaf(TreeNode<int> *root)
{
    return root && !root->left && !root->right;
}
void leftNodes(TreeNode<int> *root, vector<int> &nodes)
{
    root = root->left;
    while (root)
    {
        if (!isLeaf(root))
            nodes.push_back(root->data);
        if (root->left)
            root = root->left;
        else
            root = root->right;
    }
}
void rightNodes(TreeNode<int> *root, vector<int> &nodes)
{
    root = root->right;
    while (root)
    {
        if (!isLeaf(root))
            nodes.push_back(root->data);
        if (root->right)
            root = root->right;
        else
            root = root->left;
    }
    reverse(nodes.begin(), nodes.end());
}
void bottomNodes(TreeNode<int> *root, vector<int> &nodes)
{
    if (!root)
        return;
    if (isLeaf(root))
        nodes.push_back(root->data);
    bottomNodes(root->left, nodes);
    bottomNodes(root->right, nodes);
}

vector<int> traverseBoundary(TreeNode<int> *root)
{
    vector<int> left, bottom, right;
    leftNodes(root, left);
    bottomNodes(root, bottom);
    rightNodes(root, right);
    vector<int> ans;
    if (!isLeaf(root))
        ans.push_back(root->data);
    ans.insert(ans.end(), left.begin(), left.end());
    ans.insert(ans.end(), bottom.begin(), bottom.end());
    ans.insert(ans.end(), right.begin(), right.end());
    return ans;
}