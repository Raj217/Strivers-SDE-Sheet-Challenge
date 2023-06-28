// https://www.codingninjas.com/studio/problems/floor-from-bst_920457?source=youtube&campaign=Striver_Tree_Videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=Striver_Tree_Videos&leftPanelTab=1

#include <bits/stdc++.h>
using namespace std;

template <typename T>
class TreeNode
{
public:
    T val;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

int floorInBST(TreeNode<int> *root, int X)
{
    if (!root)
        return -1;
    if (root->val == X)
        return X;
    int val = -1;
    if (root->val < X)
        val = max(floorInBST(root->right, X), root->val);
    if (root->val > X)
        val = floorInBST(root->left, X);
    return val;
}