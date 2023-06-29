// https://leetcode.com/problems/flood-fill/submissions/982320894/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, -1, 0, 1};
        
        queue<pair<int, int>> q;
        int parentColor = image[sr][sc];
        q.push({sr, sc});
        int m = image.size(), n = image[0].size();
        vector<vector<bool>> isVisited(m, vector<bool>(n, false));
        isVisited[sr][sc] = true;
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            image[x][y] = color;
            q.pop();
            for (int i=0; i<4; i++) {
                int nx = x+dx[i], ny = y+dy[i];
                if (nx>=0 && ny>=0 && nx<m && ny<n && image[nx][ny] == parentColor && !isVisited[nx][ny]) {
                    isVisited[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
        return image;
    }
};