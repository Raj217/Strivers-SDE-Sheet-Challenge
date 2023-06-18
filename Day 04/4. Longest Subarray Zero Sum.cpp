// https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1

#include <bits/stdc++.h>
using namespace std;

int LongestSubsetWithZeroSum(vector<int> arr)
{

    int maxLen = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        int j = i;
        int s = arr[j++];
        if (s == 0)
            maxLen = max(maxLen, 1);
        while (j - i < maxLen)
            s += arr[j++];
        for (; j < arr.size(); j++)
        {
            s += arr[j];
            if (s == 0)
            {
                maxLen = max(maxLen, j - i + 1);
            }
        }
    }
    return maxLen;
}