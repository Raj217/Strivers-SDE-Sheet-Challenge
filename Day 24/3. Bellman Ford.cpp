// https://www.codingninjas.com/studio/problems/2041977?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=1

#include <bits/stdc++.h>
using namespace std;

int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges) {
   vector<int> dist(n+1, 1e9);
   dist[src] = 0;
   vector<vector<pair<int, int>>> graph(n+1);
   for (int node=1; node<n; node++) {
       bool didRelax = false;
        for (auto edge: edges) {
           int u = edge[0];
           int v = edge[1];
           int w = edge[2];
           if (dist[u] != 1e9 && dist[v] > dist[u]+w) {
               dist[v] = dist[u]+w;
               didRelax = true;
           }
       }
       if (!didRelax) return dist[dest];
   }
   return dist[dest];
}