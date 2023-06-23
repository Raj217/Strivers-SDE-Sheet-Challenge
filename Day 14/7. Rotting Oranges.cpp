// https://leetcode.com/problems/rotting-oranges/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};
    bool isValid(int x, int y, int m, int n) {
        return x>=0 && x<m && y>=0 && y<n;
    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int time = 0;
        queue<pair<int, int>> q;
        int m = grid.size(), n = grid[0].size();
        int fresh = 0;
        for (int x=0; x<m; x++) {
            for (int y=0; y<n; y++) {
                if (grid[x][y] == 2) {
                    q.push({x, y});
                } else if (grid[x][y] == 1) {
                    fresh++;
                }
            }
        } 
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for (int i=0; i<4; i++) {
                    int nx = x+dx[i];
                    int ny = y+dy[i];
                    if (isValid(nx, ny, m, n) && grid[nx][ny] == 1) {
                        grid[nx][ny] = 2;
                        q.push({nx, ny});
                        fresh--;
                    }
                }
            }
            time++;
        }
        return fresh > 0 ? -1 : max(time-1, 0);
    }
};