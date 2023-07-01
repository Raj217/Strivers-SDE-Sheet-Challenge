// https://leetcode.com/problems/maximum-profit-in-job-scheduling/description/

#include <bits/stdc++.h>
using namespace std;

class Task {
public:
    int start;
    int end;
    int profit;
    Task(int start, int end, int profit) : start(start), end(end), profit(profit) {}
    Task() {}
};
class Solution {
    int dp(vector<Task> &tasks, int i, int end, vector<int> &memo) {
        if (i==tasks.size()) return 0;

        if (tasks[i].start < end) return dp(tasks, i+1, end, memo);
        
        if (memo[i] != -1) return memo[i];
        return memo[i] = max(dp(tasks, i+1, end, memo), tasks[i].profit + dp(tasks, i+1, tasks[i].end, memo));
    }
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<Task> tasks(n);
        for (int i=0; i<n; i++) {
            tasks[i] = Task(startTime[i], endTime[i], profit[i]);
        }
        sort(tasks.begin(), tasks.end(), [](Task &a, Task &b) {
            return a.start == b.start ? a.end < b.end : a.start < b.start;
        });
        vector<int> memo(n, -1);
        return dp(tasks, 0, 0, memo);
    }
};