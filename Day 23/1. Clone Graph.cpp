// https://leetcode.com/problems/clone-graph/submissions/982333712/

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    vector<Node *> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution
{
    map<Node *, Node *> nodesMap;

public:
    Node *cloneGraph(Node *node)
    {
        if (!node)
            return NULL;
        if (nodesMap.find(node) != nodesMap.end())
            return nodesMap[node];
        Node *newNode = new Node(node->val);
        nodesMap[node] = newNode;
        vector<Node *> neighbors;
        for (Node *neighbour : node->neighbors)
        {
            if (nodesMap.find(neighbour) == nodesMap.end())
            {
                cloneGraph(neighbour);
            }
            neighbors.push_back(nodesMap[neighbour]);
        }
        newNode->neighbors = neighbors;
        return newNode;
    }
};