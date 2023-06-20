// https://leetcode.com/problems/kth-largest-element-in-an-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int partition(vector<int> &nums, int i, int j)
    {
        int pivot = nums[i], l = i, r = i + 1;
        while (r <= j)
        {
            if (nums[r] >= pivot)
            {
                swap(nums[++l], nums[r]);
            }
            r++;
        }
        swap(nums[i], nums[l]);
        return l;
    }
    int quickSelect(vector<int> &nums, int left, int right, int k)
    {
        if (left <= right)
        {
            int ind = partition(nums, left, right);

            if (ind == k - 1)
                return nums[ind];
            else if (ind < k - 1)
                return quickSelect(nums, ind + 1, right, k);
            else
                return quickSelect(nums, left, ind - 1, k);
        }
        return -1;
    }

public:
    int findKthLargest(vector<int> &nums, int k)
    {
        return quickSelect(nums, 0, nums.size() - 1, k);
    }
};