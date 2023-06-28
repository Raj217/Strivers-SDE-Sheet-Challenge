// https://www.codingninjas.com/studio/problems/920438?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=1

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

int KthLargestNumber(TreeNode<int> *root, int &k)
{
    if (!root)
        return -1;
    int right = KthLargestNumber(root->right, k);
    if (right != -1)
        return right;
    k--;
    if (k == 0)
        return root->data;
    return KthLargestNumber(root->left, k);
}
