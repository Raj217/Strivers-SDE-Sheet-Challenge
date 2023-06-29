// https://leetcode.com/problems/serialize-and-deserialize-binary-tree/description/


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


class Codec {
    vector<string> split(string str, char sep) {
        string part;
        vector<string> v;
        for (char c: str) {
            if (c==sep) {
                v.push_back(part);
                part.clear();
            } else part += c;
        }
        v.push_back(part);
        return v;
    }
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "";
        string serialized;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front(); q.pop();
            if (node) serialized += to_string(node->val)+" ";
            else serialized += "N ";
            if (node) q.push(node->left);
            if (node) q.push(node->right);
        }
        serialized.pop_back();
        return serialized;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.size() == 0) return NULL;
        vector<string> parts = split(data, ' ');
        int i=0;
        TreeNode* root = new TreeNode(stoi(parts[i++]));
        queue<TreeNode*> q;
        q.push(root);
        while (i<parts.size()) {
            TreeNode* curr = q.front();q.pop();
            string left = parts[i++];
            string right = parts[i++];
            if (left != "N") {
                curr->left = new TreeNode(stoi(left));
                q.push(curr->left);
            }  
            if (right != "N") {
                curr->right = new TreeNode(stoi(right));
                q.push(curr->right);
            }
        }
        return root;
    }
};
