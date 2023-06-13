// https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    struct Node *bottom;

    Node(int x)
    {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

Node *flatten(Node *root)
{
    if (!root)
        return root;
    if (!root->next)
    {
        root->bottom = flatten(root->bottom);
        return root;
    };
    Node *l1 = flatten(root->next);
    Node *l2 = flatten(root->bottom);
    Node *curr = root;
    while (l1 && l2)
    {
        if (l1->data < l2->data)
        {
            curr->bottom = l1;
            l1 = l1->bottom;
        }
        else
        {
            curr->bottom = l2;
            l2 = l2->bottom;
        }
        curr = curr->bottom;
    }
    if (l1)
        curr->bottom = l1;
    if (l2)
        curr->bottom = l2;
    return root;
}
