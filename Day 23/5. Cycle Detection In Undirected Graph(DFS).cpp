// https://www.codingninjas.com/studio/problems/1062670?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include <bits/stdc++.h>
using namespace std;

bool containsLoop(vector<vector<int>> &graph, int node, int parent, vector<bool> &isVisited) {
    isVisited[node] = true;
    for (int adj: graph[node]) {
        if (isVisited[adj] && adj != parent) return true;
        if (!isVisited[adj]) {
            if (containsLoop(graph, adj, node, isVisited)) return true;
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
            if (containsLoop(graph, node, -1, isVisited)) {
                return "Yes";
            }
        }
    }
    return "No";
}