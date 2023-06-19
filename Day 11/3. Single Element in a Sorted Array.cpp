// https://leetcode.com/problems/single-element-in-a-sorted-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        int n = nums.size();
        int low = 0, high = n - 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            // The general trend should be that the duplicate is next to the number
            // in the odd place
            // But if the single element appears
            // The duplicate will be on the even place
            if (mid % 2 == 0)
            {
                if (mid + 1 < n && nums[mid] == nums[mid + 1])
                    low = mid + 1;
                else
                    high = mid - 1;
            }
            else
            {
                if (mid - 1 >= 0 && nums[mid] == nums[mid - 1])
                    low = mid + 1;
                else
                    high = mid - 1;
            }
        }
        return nums[low];
    }
};