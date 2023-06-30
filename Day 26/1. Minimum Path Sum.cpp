// https://leetcode.com/problems/minimum-path-sum/description/

#include <bits/stdc++.h>
using namespace std;


class Solution {
    int dp(vector<vector<int>> &grid, int x, int y,vector<vector<int>> &memo) {
        int m = grid.size(), n = grid[0].size();
        if (x==m-1 && y==n-1) return grid[x][y];
        if (memo[x][y] != -1) return memo[x][y];
        int right = 1e9;
        int down = 1e9;
        if (y+1<n) right = dp(grid, x, y+1, memo);
        if (x+1<m) down = dp(grid, x+1, y, memo);
        return memo[x][y] = grid[x][y] + min(right, down);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> memo(m, vector<int>(n, -1));
        return dp(grid, 0, 0, memo);
    }
};