// https://leetcode.com/problems/search-in-rotated-sorted-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int breakPoint = 0, n = nums.size();
        int low = 0, high = n - 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (mid + 1 < n && mid - 1 >= 0 && nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
            {
                breakPoint = mid;
                break;
            }
            else if (nums[mid] < nums[low])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        int ind = lower_bound(nums.begin(), nums.begin() + breakPoint, target) - nums.begin();
        if (ind < n && nums[ind] == target)
            return ind;

        ind = lower_bound(nums.begin() + breakPoint + 1, nums.end(), target) - nums.begin();
        if (ind < n && nums[ind] == target)
            return ind;
        return -1;
    }
};