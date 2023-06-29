// https://www.codingninjas.com/studio/problems/1062626?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=1

#include <bits/stdc++.h>
using namespace std;

bool containsCycle(vector<vector<int>> &graph, int node, vector<bool> &isVisited, vector<bool> pathVisited) {
  isVisited[node] = true;
  pathVisited[node] = true;
  for (int adj: graph[node]) {
    if (!isVisited[adj]) {
      if (containsCycle(graph, adj, isVisited, pathVisited)) return true;
    } else {
      if (pathVisited[adj]) return true;
    }
  }
  return false;
}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  vector<vector<int>> graph(n+1);
  for (auto edge: edges) {
    graph[edge.first].push_back(edge.second);
  }

  vector<bool> isVisited(n, false), pathVisited(n, false);
  for (int node=0; node<n; node++) {
    if (!isVisited[node]) {
      if (containsCycle(graph, node, isVisited, pathVisited)) return true;
    }
  }
  return false;
}