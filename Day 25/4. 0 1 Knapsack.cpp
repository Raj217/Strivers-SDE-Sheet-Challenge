// https://www.codingninjas.com/studio/problems/1072980?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=3

#include <bits/stdc++.h>
using namespace std;

int dp(vector<int> &values, vector<int> &weights, int i, int w, vector<vector<int>> &memo) {
	if (w<0) return -1e9;
	if (i==values.size()) return 0;
	if (memo[i][w] != -1) return memo[i][w];

	return memo[i][w] = max(values[i]+dp(values, weights, i+1, w-weights[i], memo),dp(values, weights, i+1, w, memo));
}

int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
	vector<vector<int>> memo(n, vector<int>(w+1, -1));
	return dp(values, weights, 0, w, memo);
}