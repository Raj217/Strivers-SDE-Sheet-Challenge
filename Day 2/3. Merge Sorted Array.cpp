#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        if (n == 0)
            return;
        int num1Used = 0, num2Ind = 0, i = 0;
        for (; i < nums1.size() && num1Used < m && num2Ind < n; i++)
        {
            if (nums1[i] > nums2[num2Ind])
            {
                nums1.pop_back();
                nums1.insert(begin(nums1) + i, nums2[num2Ind++]);
            }
            else
            {
                num1Used++;
            }
        }
        while (num2Ind < nums2.size())
        {
            nums1[i++] = nums2[num2Ind++];
        }
    }
};