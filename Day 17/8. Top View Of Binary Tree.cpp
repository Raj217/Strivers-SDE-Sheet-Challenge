// https://www.codingninjas.com/studio/problems/799401?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=1

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

vector<int> getTopView(TreeNode<int> *root)
{
    if (!root)
        return {};
    map<int, int> nodes;
    queue<pair<TreeNode<int> *, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        TreeNode<int> *curr = q.front().first;
        int line = q.front().second;
        q.pop();
        if (nodes.find(line) == nodes.end())
        {
            nodes[line] = curr->val;
        }
        if (curr->left)
        {
            q.push({curr->left, line - 1});
        }
        if (curr->right)
        {
            q.push({curr->right, line + 1});
        }
    }
    vector<int> ans;
    for (auto node : nodes)
    {
        ans.push_back(node.second);
    }
    return ans;
}