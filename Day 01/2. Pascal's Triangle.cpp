// https://leetcode.com/problems/pascals-triangle/

#include "bits/stdc++.h"
using namespace std;
class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> pascalsTriangle = {{1}};

        for (int row = 1; row < numRows; row++)
        {
            vector<int> rowVals = {1};
            for (int col = 1; col < row; col++)
            {
                int left = pascalsTriangle[row - 1][col - 1];
                int right = pascalsTriangle[row - 1][col];
                rowVals.push_back(left + right);
            }
            rowVals.push_back(1);
            pascalsTriangle.push_back(rowVals);
        }
        return pascalsTriangle;
    }
};