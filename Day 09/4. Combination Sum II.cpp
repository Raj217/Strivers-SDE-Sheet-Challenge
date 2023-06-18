// https://leetcode.com/problems/combination-sum-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void getCombinations(vector<int> &candidates, int i, int target, vector<int> &v, vector<vector<int>> &ans)
    {
        if (target == 0)
            ans.push_back(v);
        if (target < 0 || i == candidates.size())
            return;
        for (int ind = i; ind < candidates.size(); ind++)
        {
            if (ind != i && candidates[ind] == candidates[ind - 1])
                continue;
            v.push_back(candidates[ind]);
            getCombinations(candidates, ind + 1, target - candidates[ind], v, ans);
            v.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> v;
        getCombinations(candidates, 0, target, v, ans);
        return ans;
    }
};