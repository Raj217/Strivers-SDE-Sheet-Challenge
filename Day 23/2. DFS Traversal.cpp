// https://www.codingninjas.com/studio/problems/dfs-traversal_630462?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &graph, int node, vector<int> &v,vector<bool> &isVisited) {
    if (isVisited[node]) return;
    isVisited[node]=true;
    v.push_back(node);
    for (int adj: graph[node]) {
        dfs(graph, adj, v, isVisited);
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    vector<vector<int>> graph(V);
    for (auto edge: edges) {
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    }
    vector<vector<int>> ans;
    vector<bool> isVisited(V, false);
    for (int i=0; i<V; i++) {
        if (!isVisited[i]) {
            vector<int> traverse;
            dfs(graph, i, traverse, isVisited);
            ans.push_back(traverse);
        }
    }
    return ans;
}