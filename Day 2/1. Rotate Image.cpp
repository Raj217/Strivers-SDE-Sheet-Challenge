#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void flipCols(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        for (int x = 0; x < n / 2; x++)
        {
            for (int y = 0; y < m; y++)
            {
                swap(matrix[x][y], matrix[n - x - 1][y]);
            }
        }
    }
    void transpose(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        for (int x = 0; x < n; x++)
        {
            for (int y = 0; y < x; y++)
            {
                swap(matrix[x][y], matrix[y][x]);
            }
        }
    }

public:
    void rotate(vector<vector<int>> &matrix)
    {
        flipCols(matrix);
        transpose(matrix);
    }
};