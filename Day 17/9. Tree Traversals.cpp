// https://www.codingninjas.com/studio/problems/981269?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=1

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
};

void traverse(BinaryTreeNode<int> *root, vector<vector<int>> &traversals)
{
    if (!root)
        return;
    traversals[1].push_back(root->data);
    traverse(root->left, traversals);
    traversals[0].push_back(root->data);
    traverse(root->right, traversals);
    traversals[2].push_back(root->data);
}
vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root)
{
    vector<vector<int>> traversals(3);
    traverse(root, traversals);
    return traversals;
}