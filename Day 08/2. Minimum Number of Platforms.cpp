// https://www.codingninjas.com/codestudio/problems/799400?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include <bits/stdc++.h>
using namespace std;

int calculateMinPatforms(int at[], int dt[], int n)
{
    sort(at, at + n);
    sort(dt, dt + n);
    int maxPlatforms = 1, platforms = 1;
    int arrival = 1, depart = 0;
    while (arrival < n && depart < n)
    {
        if (at[arrival] <= dt[depart])
        {
            platforms++;
            arrival++;
        }
        else
        {
            platforms--;
            depart++;
        }
        maxPlatforms = max(maxPlatforms, platforms);
    }
    return maxPlatforms;
}