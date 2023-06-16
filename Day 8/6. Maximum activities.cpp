// https://www.codingninjas.com/codestudio/problems/1062712?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include <bits/stdc++.h>
using namespace std;

int maximumActivities(vector<int> &start, vector<int> &finish)
{
    int n = start.size();
    vector<pair<int, int>> schedule(n);
    for (int i = 0; i < n; i++)
    {
        schedule[i] = {finish[i], start[i]};
    }

    sort(schedule.begin(), schedule.end());

    int end = 0;
    int nActivities = 0;
    for (int i = 0; i < n; i++)
    {
        if (end <= schedule[i].second)
        {
            nActivities++;
            end = max(end, schedule[i].first);
        }
    }
    return nActivities;
}