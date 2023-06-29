// https://www.codingninjas.com/studio/problems/893106?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

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
};

BinaryTreeNode<int> *BTtoDLL(BinaryTreeNode<int> *root)
{
    if (!root)
        return NULL;
    BinaryTreeNode<int> *left = BTtoDLL(root->left);
    BinaryTreeNode<int> *right = BTtoDLL(root->right);
    BinaryTreeNode<int> *head = left;
    if (left)
    {
        while (left->right)
        {
            left = left->right;
        }
        left->right = root;
        root->left = left;
    }
    else
        head = root;
    if (right)
    {
        right->left = root;
        root->right = right;
    }
    return head;
}