// https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

#include <bits/stdc++.h>
using namespace std;

class Solution{
    bool isValid(int x, int y, int n) {
        return x>=0 && x<n && y>=0 && y<n;
    }
    bool findPaths(vector<vector<int>> &m, int x, int y, string path, vector<string> &ans,vector<vector<bool>> isVisited) {
        int n = m.size();
        if (isVisited[x][y]) return false;
        isVisited[x][y] = true;
        
        if (x==n-1 && y==n-1) {
            ans.push_back(path);
            return true;
        }
        bool canReach = false;
        if (isValid(x+1, y, n) && m[x+1][y] == 1) {
            path += "D";
            canReach = findPaths(m, x+1, y, path, ans, isVisited);
            path.pop_back();
        }
        if (isValid(x, y-1, n) && m[x][y-1] == 1) {
            path += "L";
            canReach |= findPaths(m, x, y-1, path, ans, isVisited);
            path.pop_back();
        }
        if (isValid(x, y+1, n) && m[x][y+1] == 1) {
            path += "R";
            canReach |= findPaths(m, x, y+1, path, ans, isVisited);
            path.pop_back();
        }
        if (isValid(x-1, y, n) && m[x-1][y] == 1) {
            path += "U";
            canReach |= findPaths(m, x-1, y, path, ans, isVisited);
            path.pop_back();
        }
        return canReach;
    }
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        if (m[0][0] == 0) return {};
        vector<string> ans;
        vector<vector<bool>> isVisited(n, vector<bool>(n, false));
        findPaths(m, 0, 0, "", ans, isVisited);
        return ans;
    }
};
