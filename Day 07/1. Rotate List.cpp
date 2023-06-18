// https://leetcode.com/problems/rotate-list/description/

#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (!head || !head->next)
            return head;
        int len = 0;
        ListNode *curr = head, *prev = NULL;
        while (curr)
        {
            len++;
            curr = curr->next;
        }
        k = k % len;
        if (k == 0)
            return head;
        k = len - k;
        prev = NULL;
        curr = head;
        while (k--)
        {
            prev = curr;
            curr = curr->next;
        }
        prev->next = NULL;
        prev = head;
        head = curr;
        while (curr->next)
        {
            curr = curr->next;
        }
        curr->next = prev;
        return head;
    }
};