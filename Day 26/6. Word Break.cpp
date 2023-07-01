// https://leetcode.com/problems/word-break/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool doesExist(string s, unordered_set<string> &wordSet) {
        return wordSet.find(s) != wordSet.end();
    }
    bool dp(string &s, int left, int i, unordered_set<string> &wordSet,vector<vector<int>> &memo) {
        if (i==s.size()) return doesExist(s.substr(left), wordSet);
        if (memo[left][i] != -1) return memo[left][i];

        if (doesExist(s.substr(left, i-left+1), wordSet)) {
            if (doesExist(s.substr(i+1), wordSet)) return memo[left][i] = true;
            if (dp(s, i+1, i+1, wordSet, memo)) return memo[left][i] = true;
        }
        return memo[left][i] = dp(s, left, i+1, wordSet, memo);
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<vector<int>> memo(s.size(), vector<int>(s.size(), -1));
        return dp(s, 0, 0, wordSet, memo);
    }
};