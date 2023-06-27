// https://www.codingninjas.com/studio/problems/893110?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=1

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

vector<int> bottomView(BinaryTreeNode<int> *root)
{

    map<int, int> nodes;
    queue<pair<BinaryTreeNode<int> *, int>> q;
    vector<int> ans;
    q.push({root, 0});
    while (!q.empty())
    {
        BinaryTreeNode<int> *curr = q.front().first;
        int line = q.front().second;
        q.pop();
        nodes[line] = curr->data;
        if (curr->left)
        {
            q.push({curr->left, line - 1});
        }
        if (curr->right)
        {
            q.push({curr->right, line + 1});
        }
    }
    for (auto node : nodes)
    {
        ans.push_back(node.second);
    }
    return ans;
}
