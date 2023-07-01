// https://www.codingninjas.com/studio/problems/873266?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string &s, int left, int right) {
    while (left <= right) {
        if (s[left++] != s[right--]) return false;
    }
    return true;
}
int dp(string &s, int left, int right,vector<vector<int>> &memo) {
    if (right == s.size()) return isPalindrome(s, left, right) ? 0 : INT_MAX;
    if (memo[left][right] != -1) return memo[left][right];

    int minCuts = INT_MAX;
    if (isPalindrome(s, left, right)) {
        minCuts = 1+dp(s, right+1, right+1, memo);
    }
    minCuts = min(minCuts, dp(s, left, right+1, memo));
    return memo[left][right] = minCuts;
}
int palindromePartitioning(string str) {
    vector<vector<int>> memo(str.size(), vector<int>(str.size(), -1));
    return dp(str, 0, 0, memo)-1;
}
