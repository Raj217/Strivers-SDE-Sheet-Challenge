// https://www.codingninjas.com/studio/problems/1062670?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include <bits/stdc++.h>
using namespace std;

bool containsLoop(vector<vector<int>> &graph, int node, vector<bool> &isVisited) {
    isVisited[node] = true;
    queue<pair<int, int>> q;
    q.push({node, -1});
    while (!q.empty()) {
        int curr = q.front().first;
        int parent = q.front().second;
        q.pop();
        for (int adj: graph[curr]) {
            if (isVisited[adj] && adj != parent) return true;
            else if (!isVisited[adj]) {
                isVisited[adj] = true;
                q.push({adj, curr});
            }
        }
    }
    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    vector<vector<int>> graph(n+1);
    for (auto edge: edges) {
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    }

    vector<bool> isVisited(n, false);
    for (int node=0; node<n; node++) {
        if (!isVisited[node]) {
            if (containsLoop(graph, node, isVisited)) {
                return "Yes";
            }
        }
    }
    return "No";
}