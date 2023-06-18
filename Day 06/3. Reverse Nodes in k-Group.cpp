// https://leetcode.com/problems/reverse-nodes-in-k-group/

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
    void reverseRange(ListNode *&head, ListNode *&prev, ListNode *&curr, int len)
    {
        ListNode *prevFront = prev, *prevCurr = curr, *next = curr->next;
        while (len-- && curr)
        {
            curr->next = prev;
            prev = curr;
            curr = next;
            if (next)
                next = next->next;
        }
        if (prevFront)
            prevFront->next = prev;
        else
            head = prev;
        prevCurr->next = curr;
        prev = prevCurr;
    }

public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode *prev = NULL, *curr = head, *check = head, *checkPrev = NULL;
        int len = 0;
        while (curr)
        {
            if (len != 0 && len % k == 0)
            {
                reverseRange(head, checkPrev, check, k);
            }
            prev = curr;
            curr = curr->next;
            len++;
        }
        if (len != 0 && len % k == 0)
        {
            reverseRange(head, checkPrev, check, k);
        }
        return head;
    }
};