// https://leetcode.com/problems/number-of-islands/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, -1, 0, 1};
    bool isValid(int x, int y, int m, int n) {
        return x>=0 && y>=0 && x<m && y<n;
    }
    void bfs(vector<vector<char>> &grid, int x, int y, vector<vector<bool>> &isVisited) {
        int m = grid.size(), n = grid[0].size();

        isVisited[x][y] = true;
        queue<pair<int, int>> q;
        q.push({x, y});

        while (!q.empty()) {
            x = q.front().first;
            y = q.front().second;
            q.pop();
            for (int i=0; i<4; i++) {
                int nx = x+dx[i], ny = y+dy[i];
                if (isValid(nx, ny, m, n) && !isVisited[nx][ny] && grid[nx][ny] == '1') {
                    isVisited[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
    }
    void dfs(vector<vector<char>> &grid, int x, int y, vector<vector<bool>> &isVisited) {
        int m = grid.size(), n = grid[0].size();
        isVisited[x][y] = true;

        for (int i=0; i<4; i++) {
            int nx = x+dx[i], ny = y+dy[i];
            if (isValid(nx, ny, m, n) && !isVisited[nx][ny] && grid[nx][ny] == '1') {
                dfs(grid, nx, ny, isVisited);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> isVisited(m, vector<bool>(n, false));
        int nIslands = 0;
        for (int x=0; x<m; x++) {
            for (int y=0; y<n; y++) {
                if (grid[x][y] == '1' && !isVisited[x][y]) {
                    dfs(grid, x, y, isVisited);
                    nIslands++;
                }
            }
        }
        return nIslands;
    }
};