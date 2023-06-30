// https://www.codingninjas.com/studio/problems/985311?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website

#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &graph, int node, vector<int> &v, vector<bool> &isVisited) {
    isVisited[node] = true;
    v.push_back(node);
    for (int adj: graph[node]) {
        if (!isVisited[adj]) {
            dfs(graph, adj, v, isVisited);
        }
    }
}

void findFinishTime(vector<vector<int>> &graph, int node, stack<int> &st, vector<bool> &isVisited) {
    isVisited[node] = true;
    for (int adj: graph[node]) {
        if (!isVisited[adj]) {
            findFinishTime(graph, adj, st, isVisited);
        }
    }
    st.push(node);
}
vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &edges)
{
    stack<int> st;
    vector<vector<int>> graph(n);
    vector<vector<int>> revGraph(n);
    for (auto edge: edges) {
        graph[edge[0]].push_back(edge[1]);
        revGraph[edge[1]].push_back(edge[0]);
    }
    vector<bool> isVisited(n, false);
    for (int node=0; node<n; node++) {
        if (!isVisited[node]) findFinishTime(graph, node, st, isVisited);
    }
    vector<vector<int>> components;
    isVisited = vector<bool>(n, false);
    while (!st.empty()) {
        int node = st.top(); st.pop();
        if (!isVisited[node]) {
            vector<int> v;
            dfs(revGraph, node, v, isVisited);
            components.push_back(v);
        }
    }
    return components;
}