// https://leetcode.com/problems/majority-element/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int element = -1, count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (count == 0)
                element = nums[i];

            if (nums[i] == element)
                count++;
            else
                count--;
        }
        return element;
    }
};