// https://leetcode.com/problems/combination-sum/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void getCombinations(vector<int> &candidates, int i, int target, vector<int> &v, vector<vector<int>> &ans)
    {
        if (i == candidates.size())
        {
            if (target == 0)
            {
                ans.push_back(v);
            }
            return;
        }
        if (candidates[i] <= target)
        {
            v.push_back(candidates[i]);
            getCombinations(candidates, i, target - candidates[i], v, ans);
            v.pop_back();
        }
        getCombinations(candidates, i + 1, target, v, ans);
    }

public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> v;
        getCombinations(candidates, 0, target, v, ans);
        return ans;
    }
};