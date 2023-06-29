// https://www.codingninjas.com/studio/problems/982938?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=1

#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &graph, int node, stack<int> &st, vector<bool> &isVisited) {
    isVisited[node] = true;
    for (int adj: graph[node]) {
        if (!isVisited[adj]) dfs(graph, adj, st, isVisited);
    }
    st.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    vector<vector<int>> graph(v);
    for (auto edge: edges) {
        graph[edge[0]].push_back(edge[1]);
    }
    stack<int> st;
    vector<bool> isVisited(v, false);
    for (int node=0; node<v; node++) {
        if (!isVisited[node]) dfs(graph, node, st, isVisited);
    }
    
    vector<int> topo;
    while (!st.empty()) {
        topo.push_back(st.top());
        st.pop();
    }
    return topo;
}