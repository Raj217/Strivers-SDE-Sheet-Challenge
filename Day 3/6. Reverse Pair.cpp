// https://leetcode.com/problems/reverse-pairs/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void merge(vector<int> &nums, int start, int mid, int end)
    {
        int i1 = start, n1 = mid, i2 = mid + 1, n2 = end;
        vector<int> sorted(end - start + 1);
        int k = 0;
        while (i1 <= n1 && i2 <= n2)
        {
            if (nums[i1] < nums[i2])
                sorted[k++] = nums[i1++];
            else
                sorted[k++] = nums[i2++];
        }
        while (i1 <= n1)
        {
            sorted[k++] = nums[i1++];
        }
        while (i2 <= n2)
        {
            sorted[k++] = nums[i2++];
        }
        for (int i = start, k = 0; i <= end; i++, k++)
        {
            nums[i] = sorted[k];
        }
    }
    int revPairs(vector<int> &nums, int start, int mid, int end)
    {
        int i1 = start, n1 = mid, i2 = mid + 1, n2 = end;
        int count = 0;

        while (i1 <= n1 && i2 <= n2)
        {
            long long a = nums[i1];
            long long b = nums[i2];
            if (a > 2 * b)
            {
                count += n1 - i1 + 1;
                i2++;
            }
            else
                i1++;
        }
        return count;
    }
    int countRevPairs(vector<int> &nums, int start, int end)
    {
        int count = 0;
        if (start < end)
        {
            int mid = start + (end - start) / 2;
            count += countRevPairs(nums, start, mid);
            count += countRevPairs(nums, mid + 1, end);

            count += revPairs(nums, start, mid, end);

            merge(nums, start, mid, end);
        }
        return count;
    }

public:
    int reversePairs(vector<int> &nums)
    {
        return countRevPairs(nums, 0, nums.size() - 1);
    }
};