// https://www.codingninjas.com/studio/problems/2041979?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=1

#include <bits/stdc++.h>
using namespace std;

int floydWarshall(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    vector<vector<int>> graph(n+1, vector<int>(n+1, 1e9));
    for (int node=1; node<=n; node++) {
        graph[node][node] = 0;
    }
    for (auto edge: edges) {
        graph[edge[0]][edge[1]] = edge[2];
    }

    for (int via=1; via<=n; via++) {
        for (int u=1; u<=n; u++) {
            for (int v=1; v<=n; v++) {
                if (graph[u][via] != 1e9 && graph[via][v] != 1e9 && graph[u][v] > graph[u][via]+graph[via][v]) {
                    graph[u][v] = graph[u][via]+graph[via][v];
                }
            }
        }
    }
    return graph[src][dest];
}