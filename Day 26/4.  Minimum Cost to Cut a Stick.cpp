// https://leetcode.com/problems/minimum-cost-to-cut-a-stick/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    int dp(int left, int right, vector<int> &cuts, map<pair<int, int>, int> &memo) {
        pair<int, int> key = {left, right};
        if (memo.find(key) != memo.end()) return memo[key];
        int minCost = 1e9;
        int start = upper_bound(cuts.begin(), cuts.end(), left) - cuts.begin();
        int end = lower_bound(cuts.begin(), cuts.end(), right) - cuts.begin();
        if (start >= end) minCost = 0;
        else {
            for (int i=start; i<end ; i++) {
                minCost = min(
                    minCost, 
                    right-left+
                        dp(left, cuts[i], cuts, memo)+
                        dp(cuts[i], right, cuts, memo)
                    );
            }
        }
        return memo[key] = minCost;
    }
public:
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(), cuts.end());
        map<pair<int, int>, int> memo;
        return dp(0, n, cuts, memo);
    }
};