// https://leetcode.com/problems/longest-increasing-subsequence/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        for (int i=n-2; i>=0; i--) {
            int j = i+1;
            int maxi = 0;
            for (; j<n; j++) {
                if (nums[i] < nums[j]) {
                    maxi = max(dp[j], maxi);
                }
            }
            dp[i] = maxi+1;
        }
        return *max_element(dp.begin(), dp.end());
    }
};