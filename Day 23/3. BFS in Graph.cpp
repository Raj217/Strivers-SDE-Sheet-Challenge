// https://www.codingninjas.com/studio/problems/bfs-in-graph_973002?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include <bits/stdc++.h>
using namespace std;

vector<int> bfs(vector<set<int>> &graph, int node, vector<bool> &isVisited) {
    isVisited[node] = true;
    queue<int> q;
    q.push(node);
    vector<int> v;
    while (!q.empty()) {
        int curr = q.front();q.pop();
        v.push_back(curr);
        for (int adj: graph[curr]) {
            if (!isVisited[adj]) {
                q.push(adj);
                isVisited[adj] = true;
            }
        }
    }
    return v;
}

vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    vector<set<int>> graph(vertex);
    for (auto edge: edges) {
        graph[edge.first].insert(edge.second);
        graph[edge.second].insert(edge.first);
    }

    vector<bool> isVisited(vertex, false);
    vector<int> ans;
    for (int node=0; node<vertex; node++) {
        if (!isVisited[node]) {
            vector<int> v =  bfs(graph, node, isVisited);
            ans.insert(ans.end(), v.begin(), v.end());
        }
    }
    return ans;
}