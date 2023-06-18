// https://leetcode.com/problems/n-queens/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    bool isValid(vector<string> &board, int x, int y)
    {
        int n = board.size();

        // Validating Row
        for (int ny = 0; ny < n; ny++)
        {
            if (board[x][ny] == 'Q')
                return false;
        }

        // Validating Column
        for (int nx = 0; nx < n; nx++)
        {
            if (board[nx][y] == 'Q')
                return false;
        }

        // Validating Diagonal North West
        for (int nx = x, ny = y; nx >= 0 && ny >= 0; nx--, ny--)
        {
            if (board[nx][ny] == 'Q')
                return false;
        }

        // Validating Diagonal North East
        for (int nx = x, ny = y; nx >= 0 && ny < n; nx--, ny++)
        {
            if (board[nx][ny] == 'Q')
                return false;
        }

        // Validating Diagonal South West
        for (int nx = x, ny = y; nx < n && ny >= 0; nx++, ny--)
        {
            if (board[nx][ny] == 'Q')
                return false;
        }

        // Validating Diagonal South East
        for (int nx = x, ny = y; nx < n && ny < n; nx++, ny++)
        {
            if (board[nx][ny] == 'Q')
                return false;
        }

        return true;
    }
    void fillQueens(vector<string> &board, int x, vector<vector<string>> &ans)
    {
        int n = board.size();
        if (x == n)
        {
            ans.push_back(board);
            return;
        }

        for (int y = 0; y < n; y++)
        {
            if (isValid(board, x, y))
            {
                board[x][y] = 'Q';
                fillQueens(board, x + 1, ans);
                board[x][y] = '.';
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> ans;
        fillQueens(board, 0, ans);
        return ans;
    }
};