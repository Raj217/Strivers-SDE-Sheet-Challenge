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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len1 = 0, len2 = 0;
        ListNode *curr1=headA, *curr2=headB;
        while(curr1 && curr2) {
            len1++, len2++;
            curr1 = curr1->next;
            curr2 = curr2->next;
        } 
        while (curr1) {
            len1++;
            curr1 = curr1->next;
        }
        while (curr2) {
            len2++;
            curr2=curr2->next;
        }
        curr1 = headA, curr2 = headB;
        if (len1 > len2) {
            while (len1 > len2) {
                curr1 = curr1->next;
                len1--;
            }
        } else {
            while (len2 > len1) {
                curr2 = curr2->next;
                len2--;
            }
        }
        while (curr1 && curr2) {
            if (curr1 == curr2) {
                return curr1;
            }
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
        return NULL;
    }
};