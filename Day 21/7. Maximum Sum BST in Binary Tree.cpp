// https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/description/


#include <bits/stdc++.h>
using namespace std;


struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class NodeInfo {
public:
    int maxElement;
    int minElement;
    bool isBST;
    int sum;
    NodeInfo(
        int maxElement,
        int minElement, 
        bool isBST, 
        int sum
    ) : 
    maxElement(maxElement),
    minElement(minElement), 
    isBST(isBST), 
    sum(sum) {}

    NodeInfo() : 
    maxElement(INT_MIN),
    minElement(INT_MAX),
    isBST(true),
    sum(0) {}
};
class Solution {
    NodeInfo maxSum(TreeNode* root, int &maxi) {
        if (!root) return NodeInfo();
        NodeInfo left = maxSum(root->left, maxi);
        NodeInfo right = maxSum(root->right, maxi);

        NodeInfo currInfo;
        if (left.isBST && right.isBST && root->val > left.maxElement && root->val < right.minElement) {
            currInfo.isBST = true;
        } else {
            currInfo.isBST = false;
        }
        currInfo.maxElement = max({left.maxElement, right.maxElement, root->val});
        currInfo.minElement = min({left.minElement, right.minElement, root->val});
        currInfo.sum = root->val + left.sum + right.sum;
        if (currInfo.isBST) {
            maxi = max(maxi, currInfo.sum);
        }
        return currInfo;
    }
public:
    int maxSumBST(TreeNode* root) {
        int maxi = 0;
        maxSum(root, maxi);
        return maxi;
    }
};