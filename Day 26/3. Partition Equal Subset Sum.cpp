// https://leetcode.com/problems/partition-equal-subset-sum/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool dp(vector<int> &nums, int i, int sum, vector<vector<int>>  &memo, int &tot) {
        if (i==nums.size()) return sum == 0;
        if (memo[i][sum+tot] != -1) return memo[i][sum+tot];
        return memo[i][sum+tot] = (dp(nums, i+1, sum+nums[i], memo, tot) || dp(nums, i+1, sum-nums[i], memo, tot));
    }
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        vector<vector<int>> memo(nums.size(), vector<int>(2*sum+1, -1));
        return dp(nums, 0, 0, memo, sum);
    }
};