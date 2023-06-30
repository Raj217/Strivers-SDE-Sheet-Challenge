// https://www.codingninjas.com/studio/problems/920469?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include <bits/stdc++.h>
using namespace std;


vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    vector<int> dist(vertices, INT_MAX);

    vector<vector<pair<int, int>>> graph(vertices);
    for (vector<int> edge: vec) {
        graph[edge[0]].push_back({edge[1], edge[2]});
        graph[edge[1]].push_back({edge[0], edge[2]});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source});
    dist[source] = 0;
    while (!pq.empty()) {
        int node = pq.top().second; pq.pop();
        for (auto adj: graph[node]) {
            if (dist[adj.first] > dist[node]+adj.second) {
                dist[adj.first] = dist[node]+adj.second;
                pq.push({dist[adj.first], adj.first});
            }
        }
    }
    return dist;
}
