// https://www.codingninjas.com/studio/problems/path-in-a-tree_3843990?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=1

#include <bits/stdc++.h>
using namespace std;

template <typename T = int>
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
        if (left != NULL)
        {
            delete left;
        }
        if (right != NULL)
        {
            delete right;
        }
    }
};
bool findPath(TreeNode<int> *root, int x, vector<int> &path)
{
    if (!root)
        return false;
    path.push_back(root->data);
    if (root->data == x)
        return true;
    if (findPath(root->left, x, path))
        return true;
    if (findPath(root->right, x, path))
        return true;
    path.pop_back();
    return false;
}

vector<int> pathInATree(TreeNode<int> *root, int x)
{
    vector<int> path;
    findPath(root, x, path);
    return path;
}
