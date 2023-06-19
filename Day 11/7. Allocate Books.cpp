// https://www.codingninjas.com/codestudio/problems/ayush-gives-ninjatest_1097574?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include <bits/stdc++.h>
using namespace std;

long long calcDays(vector<int> time, long long hoursPerDay)
{
    long long nDays = 1, hours = 0;
    for (int t : time)
    {
        if (hours + t >= hoursPerDay)
        {
            nDays++;
            hours = 0;
        }
        if (t >= hoursPerDay)
            return INT_MAX;
        hours += t;
    }
    return nDays;
}
long long ayushGivesNinjatest(int n, int m, vector<int> time)
{
    long long low = 1, high = 1e13;
    while (low <= high)
    {
        long long mid = low + (high - low) / 2;
        long long nDays = calcDays(time, mid);
        if (nDays <= m && nDays <= n)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return high;
}