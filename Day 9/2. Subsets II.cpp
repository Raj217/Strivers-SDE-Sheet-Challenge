// https://leetcode.com/problems/subsets-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void genSets(vector<int> &nums, int i, vector<int> &v, set<vector<int>> &sets)
    {
        sets.insert(v);
        for (int ind = i; ind < nums.size(); ind++)
        {
            v.push_back(nums[ind]);
            genSets(nums, ind + 1, v, sets);
            v.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        set<vector<int>> sets;
        vector<int> v;
        genSets(nums, 0, v, sets);
        return vector<vector<int>>(sets.begin(), sets.end());
    }
};