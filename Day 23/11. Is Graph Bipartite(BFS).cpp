// https://leetcode.com/problems/is-graph-bipartite/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);

        queue<int> q;
        for (int node=0; node<n; node++) {
            if (graph[node].size() && color[node] == -1) {
                q.push(node);      
                color[node] = 0;
                while (!q.empty()) {
                    int curr = q.front(); q.pop();
                    for (int adj: graph[curr]) {
                        if (color[adj] == -1) {
                            color[adj] = !color[curr];
                            q.push(adj);
                        } else if (color[adj] == color[curr]) return false;
                    }
                }
            }
        }
        return true;
    }
};