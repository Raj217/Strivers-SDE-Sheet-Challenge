// https://www.codingninjas.com/studio/problems/1095633?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include <bits/stdc++.h>
using namespace std;

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    vector<vector<pair<int, int>>> graph(n+1);
    for (auto edge: g) {
        graph[edge.first.first].push_back({edge.first.second, edge.second});
        graph[edge.first.second].push_back({edge.first.first, edge.second});
    }

    vector<pair<pair<int, int>, int>> mst;
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    pq.push({0,{g[0].first.first, -1}});
    
    vector<bool> didAddToMST(n+1, false);
    while (!pq.empty()) {
        int weight = pq.top().first;
        int node = pq.top().second.first;
        int parent = pq.top().second.second;
        pq.pop();
        if (!didAddToMST[node]) {
            if (parent != -1) mst.push_back({{node, parent}, weight});
            didAddToMST[node] = true;
            for (auto adj: graph[node]) {
                pq.push({adj.second, {adj.first, node}});
            }
        }
    }
    return mst;
}