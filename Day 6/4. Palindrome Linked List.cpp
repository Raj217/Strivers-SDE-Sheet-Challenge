// https://leetcode.com/problems/palindrome-linked-list/

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
    bool isPalindrome(ListNode *head)
    {
        if (!head || !head->next)
            return head;
        ListNode *slow = head, *fast = head->next->next;
        while (fast)
        {
            slow = slow->next;
            fast = fast->next;
            if (fast)
                fast = fast->next;
        }
        ListNode *next = slow->next;
        ListNode *slowPrev = NULL;
        while (slow)
        {
            slow->next = slowPrev;
            slowPrev = slow;
            slow = next;
            if (next)
                next = next->next;
        }
        ListNode *last = slowPrev;
        ListNode *left = head, *right = last;
        while (left && right && left != right)
        {
            if (left->val != right->val)
                return false;
            left = left->next;
            right = right->next;
        }
        return true;
    }
};