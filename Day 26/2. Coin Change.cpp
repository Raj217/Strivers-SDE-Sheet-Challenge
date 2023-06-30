// https://leetcode.com/problems/coin-change/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    int dp(vector<int> &coins, int amount,vector<int> &memo) {
        if (amount < 0) return 1e9;
        if (amount == 0) return 0;
        if (memo[amount] != -1) return memo[amount];
        int minCoins = 1e9;
        for (int coin: coins) {
            minCoins = min(minCoins, dp(coins, amount-coin, memo)+1);
        }
        return memo[amount] = minCoins;
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> memo(amount+1, -1);
        int minCoins = dp(coins, amount, memo);
        return minCoins >= 1e9 ? -1 : minCoins;
    }
};