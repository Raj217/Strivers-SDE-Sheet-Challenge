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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        if (!head)
            return NULL;
        ListNode *fast = head, *nth = head, *nthPrev = NULL;
        while (--n >= 0 && fast)
        {
            fast = fast->next;
        }
        while (fast)
        {
            nthPrev = nth;
            nth = nth->next;
            fast = fast->next;
        }
        if (nthPrev && nth)
            nthPrev->next = nth->next;
        else if (nthPrev == NULL)
            head = head->next;
        return head;
    }
};