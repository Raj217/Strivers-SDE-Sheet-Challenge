// https://www.codingninjas.com/studio/problems/982938?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=1

#include <bits/stdc++.h>
using namespace std;

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    vector<vector<int>> graph(v);
    for (auto edge: edges) {
        graph[edge[0]].push_back(edge[1]);
    }

    vector<int> indegree(v, 0);
    for (auto node: graph) {
        for (auto adj: node) {
            indegree[adj]++;
        }
    }
    queue<int> q;
    for (int node=0; node<v; node++) {
        if (indegree[node] == 0) q.push(node);
    }

    vector<int> topo;
    while (!q.empty()) {
        int curr = q.front(); q.pop();
        topo.push_back(curr);
        for (int adj: graph[curr]) {
            indegree[adj]--;
            if (indegree[adj] == 0) q.push(adj);
        }
    }
    return topo;
}