// https://www.codingninjas.com/studio/problems/893049?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include <bits/stdc++.h>
using namespace std;

template <typename T>

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

void traverse(BinaryTreeNode<int> *root, int &key, vector<int> &ans)
{
    if (!root)
        return;
    traverse(root->left, key, ans);
    if (root->data == key)
    {
        ans[1] = root->data;
    }
    else
    {
        if (root->data < key && (ans[0] == -1 || ans[0] < root->data))
        {
            ans[0] = root->data;
        }

        if (root->data > key && (ans[2] == -1 || ans[2] > root->data))
        {
            ans[2] = root->data;
        }
    }
    traverse(root->right, key, ans);
}

pair<int, int> predecessorSuccessor(BinaryTreeNode<int> *root, int key)
{
    vector<int> ans = {-1, -1, -1};
    traverse(root, key, ans);
    if (ans[1] == key)
    {
        return {ans[0], ans[2]};
    }
    return {-1, -1};
}