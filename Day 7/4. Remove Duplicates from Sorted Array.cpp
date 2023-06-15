// https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        if (nums.size() == 1)
            return 1;
        int k = 0;
        int n = nums.size();
        bool areLastTwoSame = nums[n - 1] == nums[n - 2];
        for (int i = 0; i < n - 1; i++)
        {
            if (nums[i] == nums[i + 1])
            {
                while (i + 1 < n && nums[i] == nums[i + 1])
                    i++;
            }
            swap(nums[i], nums[k]);
            k++;
        }
        if (!areLastTwoSame)
        {
            swap(nums[n - 1], nums[k++]);
        }
        return k;
    }
};