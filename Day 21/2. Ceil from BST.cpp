// https://www.codingninjas.com/studio/problems/ceil-from-bst_920464?source=youtube&campaign=Striver_Tree_Videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=Striver_Tree_Videos&leftPanelTab=1

#include <bits/stdc++.h>
using namespace std;

template<typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~BinaryTreeNode()
    {
        if (left)
        {
            delete left;
        }
        if (right)
        {
            delete right;
        }
    }
};

int findCeil(BinaryTreeNode<int> *root, int X)
{
    if (!root)
        return -1;
    if (root->data == X)
        return X;
    int val = -1;
    if (root->data > X)
    {
        int res = findCeil(root->left, X);
        if (res != -1)
            val = min(res, root->data);
        else
            val = root->data;
    }
    else if (root->data < X)
        val = findCeil(root->right, X);
    return val;
}