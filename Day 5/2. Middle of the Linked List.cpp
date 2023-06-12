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

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* fast=head->next->next, *slow = head;
        bool isEven = true;
        while (fast != NULL) {
            fast = fast->next;
            slow = slow->next;
            if (fast) fast = fast->next;
            else isEven = false;
        }
        return isEven ? slow->next : slow;
    }
};