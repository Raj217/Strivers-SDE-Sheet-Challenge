// https://leetcode.com/problems/populating-next-right-pointers-in-each-node/description/

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return root;
        Node* left = root->left, *right = root->right;
        if (left) {
            left->next = right;
            if (root->next) right->next = root->next->left;

            connect(root->left);
            connect(root->right);
        }
        return root;
    }
};