// https://www.codingninjas.com/codestudio/problems/975286?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include <bits/stdc++.h>
using namespace std;

double maximumValue(vector<pair<int, int>> &items, int n, int w)
{
    vector<pair<double, int>> value(n);
    for (int i = 0; i < n; i++)
    {
        value[i] = {items[i].second / (1.0 * items[i].first), i};
    }
    sort(value.begin(), value.end(), greater<pair<double, int>>());

    double totalVal = 0, val;
    for (int i = 0; i < n; i++)
    {
        int wt = items[value[i].second].first;
        int v = items[value[i].second].second;
        if (w >= wt)
        {
            totalVal += v;
            w -= wt;
        }
        else
        {
            totalVal += v * (w / (1.0 * wt));
            break;
        }
    }
    return totalVal;
}