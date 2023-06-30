// https://www.codingninjas.com/studio/problems/1112624?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include <bits/stdc++.h>
using namespace std;

int dp(vector<int> &reck, int i, int prevInd, vector<vector<int>> &memo) {
	if (i==reck.size()) return 0;
	if (memo[i][prevInd+1] != -1) return memo[i][prevInd+1];
	int pick = 0;
	if (prevInd == -1 || reck[i] > reck[prevInd]) pick = reck[i]+dp(reck, i+1, i, memo);
	int notPick = dp(reck, i+1, prevInd, memo);
	return memo[i][prevInd+1] = max(pick, notPick);
} 
int maxIncreasingDumbbellsSum(vector<int> &rack, int n)
{
	vector<vector<int>> memo(n, vector<int>(n+1, -1));
	return dp(rack, 0, -1, memo);
}