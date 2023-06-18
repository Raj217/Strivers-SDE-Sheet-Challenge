// https://leetcode.com/problems/two-sum/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> pos;

        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            pos[nums[i]] = i;
        }

        for (int i = 0; i < n; i++)
        {
            if (pos.find(target - nums[i]) != pos.end() && pos[target - nums[i]] != i)
            {
                return {i, pos[target - nums[i]]};
            }
        }
        return {};
    }
};