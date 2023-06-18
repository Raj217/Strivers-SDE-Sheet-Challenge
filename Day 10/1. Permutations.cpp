// https://leetcode.com/problems/permutations/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void gen(vector<int> &nums, int i, vector<vector<int>> &ans)
    {
        if (i == nums.size())
        {
            ans.push_back(nums);
            return;
        }
        for (int j = i; j < nums.size(); j++)
        {
            swap(nums[i], nums[j]);
            gen(nums, i + 1, ans);
            swap(nums[j], nums[i]);
        }
    }

public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> ans;
        gen(nums, 0, ans);
        return ans;
    }
};