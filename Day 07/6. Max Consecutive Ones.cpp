// https://leetcode.com/problems/max-consecutive-ones/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int lastZeroPos = -1;
        int maxi = 0, n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 0)
            {
                maxi = max(maxi, i - lastZeroPos - 1);
                lastZeroPos = i;
            }
        }
        maxi = max(maxi, n - lastZeroPos - 1);
        return maxi;
    }
};