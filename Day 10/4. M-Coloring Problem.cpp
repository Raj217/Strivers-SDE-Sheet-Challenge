// https://www.codingninjas.com/codestudio/problems/981273?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include <bits/stdc++.h>
using namespace std;

bool isValid(vector<vector<int>> &mat, int node, int color, vector<int> nodeColor)
{
    for (int ind = 0; ind < mat[node].size(); ind++)
    {
        if (mat[node][ind] == 1 && nodeColor[ind] == color)
            return false;
    }
    return true;
}
bool canColor(vector<vector<int>> &mat, int m, int node, vector<int> nodeColor)
{
    if (node == mat.size())
    {
        for (int c : nodeColor)
        {
            if (c == 0)
                return false;
        }
        return true;
    }
    for (int c = 1; c <= m; c++)
    {
        if (isValid(mat, node, c, nodeColor))
        {
            nodeColor[node] = c;
            if (canColor(mat, m, node + 1, nodeColor))
                return true;
            nodeColor[node] = 0;
        }
    }
    return false;
}
string graphColoring(vector<vector<int>> &mat, int m)
{
    int n = mat.size();
    vector<int> nodeColor(n, 0);
    return canColor(mat, m, 0, nodeColor) == true ? "YES" : "NO";
}