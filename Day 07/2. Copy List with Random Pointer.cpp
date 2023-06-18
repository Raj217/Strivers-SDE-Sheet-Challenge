// https://leetcode.com/problems/copy-list-with-random-pointer/description/

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (!head)
            return NULL;
        Node *curr = head, *root, *next, *curr2;
        root = new Node(head->val);
        curr2 = root;
        while (curr)
        {
            next = curr->next;
            curr->next = curr2;
            curr2->next = next;
            curr = curr2->next;
            if (curr)
            {
                curr2 = new Node(curr->val);
            }
        }
        curr = head;
        curr2 = root;
        while (curr)
        {
            if (curr->random)
                curr2->random = curr->random->next;
            curr = curr->next->next;
            if (curr)
                curr2 = curr->next;
        }
        curr2 = root;
        curr = head;
        while (curr)
        {
            curr->next = curr2->next;
            if (curr2->next)
                curr2->next = curr2->next->next;
            else
                curr2->next = NULL;
            curr2 = curr2->next;
            curr = curr->next;
        }
        return root;
    }
};