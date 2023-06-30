// https://leetcode.com/problems/edit-distance/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    int dp(string &word1, string &word2, int i1, int i2, vector<vector<int>> &memo) {
        if (i1 == word1.size() && i2 < word2.size()) return word2.size()-i2;
        if (i2 == word2.size() && i1 < word1.size()) return word1.size()-i1;
        if (i1 == word1.size() && i2 == word2.size()) return 0;
        if (memo[i1][i2] != -1) return memo[i1][i2];
        if (word1[i1] == word2[i2]) return memo[i1][i2] = dp(word1, word2, i1+1, i2+1, memo);
        else {
            int insert = 1+min(dp(word1, word2, i1+1, i2, memo), dp(word1, word2, i1, i2+1, memo));
            int remove = 1+min(dp(word1, word2, i1+1, i2, memo), dp(word1, word2, i1, i2+1, memo));
            int replace = 1+dp(word1, word2, i1+1, i2+1, memo);
            return memo[i1][i2] = min({insert, remove, replace});
        }
    }
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> memo(word1.size(), vector<int>(word2.size(), -1));
        return dp(word1, word2, 0, 0, memo);
    }
};