// https://www.codingninjas.com/studio/problems/920551?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=1

#include <bits/stdc++.h>
using namespace std;

bool isBipartite(vector<vector<int>> &edges, int node, vector<int> &color) {
	for (int adj=0; adj<edges.size(); adj++) {
		if (edges[node][adj] == 1 && color[adj] == -1) {
			color[adj] = !color[node];
			if (!isBipartite(edges, adj, color)) return false;
		} else if (edges[node][adj] == 1 && color[adj] == color[node]) return false;
	}
	return true;
}

bool isGraphBirpatite(vector<vector<int>> &edges) {
	int v = edges.size();
	vector<int> color(v, -1);
	for (int node=0; node<v; node++) {
		for (int adj=0; adj<v; adj++) {
			if (edges[node][adj] == 1 && color[node] == -1) {
				color[node] = 0;
				if (!isBipartite(edges, node, color)) return false;
			}
		}
	}
	return true;
}