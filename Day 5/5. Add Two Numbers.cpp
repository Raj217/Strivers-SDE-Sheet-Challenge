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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        int carry = 0;
        ListNode* i1 = l1, *i2 = l2;
        int s = l1->val + l2->val;
        carry = s/10;
        s %= 10;
        ListNode* head = new ListNode(s);
        i1 = i1->next;
        i2 = i2->next;
        ListNode* curr = head;
        while (i1 && i2) {
            s = i1->val+i2->val+carry;
            carry = s/10;
            s %= 10;
            curr->next = new ListNode(s);
            curr = curr->next;
            i1 = i1->next;
            i2 = i2->next;
        }
        while (i1) {
            s = i1->val+carry;
            carry = s/10;
            s %= 10;
            curr->next = new ListNode(s);
            curr = curr->next;
            i1 = i1->next;
        }
        while (i2) {
            s = i2->val+carry;
            carry = s/10;
            s %= 10;
            curr->next = new ListNode(s);
            curr = curr->next;
            i2 = i2->next;
        }
        if (carry != 0) curr->next = new ListNode(carry);
        return head;
    }
};