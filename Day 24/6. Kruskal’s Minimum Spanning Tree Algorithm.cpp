// https://www.codingninjas.com/studio/problems/1082553?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=1

#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
	vector<int> rank;
	vector<int> parent;
public: 
	DisjointSet(int n) {
		rank.resize(n, 0);
		parent.resize(n, 0);
		for (int i=0; i<n; i++) parent[i] = i;
	}

	int find(int node) {
		if (node == parent[node]) return node;
		return parent[node] = find(parent[node]);
	}

	void makeUnion(int u, int v) {
		int pU = find(u);
		int pV = find(v);

		if (pU == pV) return;
		if (rank[pU] > rank[pV]) {
			parent[pV] = pU;
		} else if (rank[pU] < rank[pV]) {
			parent[pU] = pV;
		} else {
			rank[pU]++;
			parent[pV] = pU;
		}
	}
};

int kruskalMST(int n, int m, vector<vector<int>> &graph) {
	sort(graph.begin(), graph.end(), [](vector<int> const &a, vector<int> const &b) {
		return a[2] == b[2] ? (a[0]<b[0]) : (a[2] < b[2]);
	});

	DisjointSet dj(n+1);

	int sum = 0;
	for (int i=0; i<m; i++) {
		int u = graph[i][0];
		int v = graph[i][1];
		int wt = graph[i][2];
		if (dj.find(u) != dj.find(v)) {
			sum += wt;
			dj.makeUnion(u, v);
		}
	}
	return sum;
}