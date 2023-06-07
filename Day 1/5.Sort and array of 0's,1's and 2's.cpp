#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void freqSort(vector<int> &nums)
    {
        vector<int> freq(3, 0);
        for (int num : nums)
        {
            freq[num]++;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            for (int num = 0; num < freq.size(); num++)
            {
                if (freq[num] > 0)
                {
                    nums[i] = num;
                    freq[num]--;
                    break;
                }
            }
        }
    }
    void threePointer(vector<int> &nums)
    {
        // dividing the region into 3 parts
        // start to low: 0
        // low+1 to high: 1
        // high+1 to end: 2
        int n = nums.size();
        int low = -1, i = 0, high = n;
        while (i < high)
        {
            if (nums[i] == 0)
            {
                swap(nums[i++], nums[++low]); // Add the 0 to the next of current low mainting the order of 0..01..12..2
            }
            else if (nums[i] == 1)
            {
                i++; // If 1 is there in the middle it is perfect
            }
            else
            {
                swap(nums[i], nums[--high]); // Add 2 to the begining of high so the new range is now i to high-1 thus we decrease only high and i is left untouched mainting the order of 0..01..12..2
            }
        }
    }

public:
    void sortColors(vector<int> &nums)
    {
        threePointer(nums);
    }
};