#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        if (nums.size() == 1)
            return;
        int n = nums.size();
        int i = n - 2;

        // First finding the break in decreasing order trend from the right end
        while (i >= 0)
        {
            if (nums[i] < nums[i + 1])
            {
                break;
            }
            i--;
        }
        // Edge Case
        // The array is reverse sorted
        // So returning the original array in sorted order
        if (i == -1)
        {
            reverse(begin(nums), end(nums));
            return;
        }

        int nextNum = INT_MAX, nextNumInd;
        int j = i + 1;
        while (j < n)
        {
            // The number is greater than the breaking point(i) && nums[j] is smaller than the current assumed next num of i
            if (nums[j] > nums[i] && nums[j] < nextNum)
            {
                nextNumInd = j;
                nextNum = nums[j];
            }
            j++;
        }

        swap(nums[i], nums[nextNumInd]);
        sort(begin(nums) + i + 1, end(nums));
    }
};