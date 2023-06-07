#include "bits/stdc++.h"
using namespace std;

class Solution
{
    void makeColumnZero(vector<vector<int>> &matrix, int y, int n)
    {
        for (int x = 0; x < n; x++)
        {
            matrix[x][y] = 0;
        }
    }
    void makeRowZero(vector<vector<int>> &matrix, int x, int m)
    {
        for (int y = 0; y < m; y++)
        {
            matrix[x][y] = 0;
        }
    }

public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        queue<pair<int, int>> zeroPos;

        int n = matrix.size();
        int m = matrix[0].size();
        // Locating all the zeros and adding them to queue
        for (int x = 0; x < n; x++)
        {
            for (int y = 0; y < m; y++)
            {
                if (matrix[x][y] == 0)
                {
                    zeroPos.push({x, y});
                }
            }
        }

        while (!zeroPos.empty())
        {
            int x = zeroPos.front().first;
            int y = zeroPos.front().second;
            zeroPos.pop();

            makeColumnZero(matrix, y, n);
            makeRowZero(matrix, x, m);
        }
    }
};