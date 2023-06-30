// https://www.codingninjas.com/studio/problems/975344?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website

#include <bits/stdc++.h>
using namespace std;

int dp(vector<int> &arr, int left, int right, vector<vector<int>> &memo) {
    int n = arr.size();
    if (left==right) {
        return 0;
    }
    if (memo[left][right] != -1) return memo[left][right];
    int minCost = INT_MAX;
    for (int i=left; i<right; i++) {
        int cost = arr[left-1]*arr[i]*arr[right];
        cost = dp(arr, left, i, memo) + cost + dp(arr, i+1, right, memo);
        minCost = min(cost, minCost);
    }
    return memo[left][right] = minCost;
}
int matrixMultiplication(vector<int> &arr, int N)
{
    vector<vector<int>> memo(N, vector<int>(N, -1));
    return dp(arr, 1, N-1, memo);
}