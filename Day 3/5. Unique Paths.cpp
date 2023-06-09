#include <bits/stdc++.h>
using namespace std;

class Solution
{
    bool isValid(int x, int y, int m, int n)
    {
        return x >= 0 && x < m && y >= 0 && y < n;
    }
    int dp(int x, int y, int &m, int &n, vector<vector<int>> &memo)
    {
        if (x == m - 1 && y == n - 1)
            return 1;
        if (memo[x][y] != -1)
            return memo[x][y];

        int count = 0;
        if (isValid(x + 1, y, m, n))
            count += dp(x + 1, y, m, n, memo);
        if (isValid(x, y + 1, m, n))
            count += dp(x, y + 1, m, n, memo);
        return memo[x][y] = count;
    }

public:
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> memo(m, vector<int>(n, -1));
        return dp(0, 0, m, n, memo);
    }
};