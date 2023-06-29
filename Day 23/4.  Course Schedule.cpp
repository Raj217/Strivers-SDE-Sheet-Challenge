// https://leetcode.com/problems/course-schedule/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for (auto req: prerequisites) {
            graph[req[0]].push_back(req[1]);
        }

        vector<int> indegree(numCourses, 0);
        for (auto node: graph) {
            for (auto adj: node) {
                indegree[adj]++;
            }
        }

        queue<int> q;
        vector<bool> isVisited(numCourses, false);
        for (int node=0; node<numCourses; node++) {
            if (indegree[node] == 0) {
                q.push(node);
            }
        }
        while (!q.empty()) {
            int node = q.front(); q.pop();
            isVisited[node] = true;
            for (int adj: graph[node]) {
                indegree[adj]--;
                if (indegree[adj] == 0) q.push(adj);
            }
        }
        for (int node=0; node<numCourses; node++) {
            if (!isVisited[node]) return false;
        }
        return true;
    }
};