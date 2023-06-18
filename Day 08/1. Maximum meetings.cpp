// https://www.codingninjas.com/codestudio/problems/1062658?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include <bits/stdc++.h>
using namespace std;

vector<int> maximumMeetings(vector<int> &start, vector<int> &end)
{
    int n = start.size();
    vector<pair<int, int>> timeStamps(n);
    for (int i = 0; i < n; i++)
    {
        timeStamps[i] = {end[i], i + 1};
    }
    sort(timeStamps.begin(), timeStamps.end());
    int e = -1;
    vector<int> meetings;
    for (int i = 0; i < n; i++)
    {
        if (e < start[timeStamps[i].second - 1])
        {
            e = timeStamps[i].first;
            meetings.push_back(timeStamps[i].second);
        }
    }
    return meetings;
}