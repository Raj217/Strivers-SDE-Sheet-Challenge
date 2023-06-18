// https://leetcode.com/problems/sudoku-solver/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    bool isValid(vector<vector<char>> &board, int x, int y, char num)
    {
        int n = board.size();
        // Checking Row
        for (int ny = 0; ny < n; ny++)
        {
            if (board[x][ny] == num)
                return false;
        }

        // Checking Column
        for (int nx = 0; nx < n; nx++)
        {
            if (board[nx][y] == num)
                return false;
        }

        // Checking block
        int sx = max(0, (x / 3) * 3);
        int sy = max(0, (y / 3) * 3);
        for (int nx = sx; nx < sx + 3; nx++)
        {
            for (int ny = sy; ny < sy + 3; ny++)
            {
                if (board[nx][ny] == num)
                    return false;
            }
        }
        return true;
    }

    void print(vector<vector<char>> board)
    {
        for (auto r : board)
        {
            for (auto c : r)
            {
                cout << c << " ";
            }
            cout << '\n';
        }
        cout << '\n';
    }
    bool solve(vector<vector<char>> &board, int x, int y)
    {
        int n = board.size();
        int nx, ny;
        if (x == n && y == 0)
            return true;

        if (y == n - 1)
        {
            nx = x + 1;
            ny = 0;
        }
        else
        {
            nx = x;
            ny = y + 1;
        }
        if (board[x][y] != '.')
        {
            return solve(board, nx, ny);
        }
        else
        {
            for (char num = '1'; num <= '9'; num++)
            {
                if (isValid(board, x, y, num))
                {
                    board[x][y] = num;
                    if (solve(board, nx, ny))
                        return true;
                    board[x][y] = '.';
                }
            }

            return false;
        }
    }

public:
    void solveSudoku(vector<vector<char>> &board)
    {
        solve(board, 0, 0);
    }
};