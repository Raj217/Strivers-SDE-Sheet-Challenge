// https://www.codingninjas.com/codestudio/problems/aggressive-cows_1082559?utm_source=striver&utm_medium=website&utm_campaign=codestudio_a_zcourse&leftPanelTab=0

#include <bits/stdc++.h>
using namespace std;

bool calcCows(vector<int> &stalls, int minDist, int cows)
{
    int nCows = 1, i = 0, j = 1;
    for (; j < stalls.size(); j++)
    {
        if (stalls[j] - stalls[i] >= minDist)
        {
            nCows++;
            i = j;
        }
        if (nCows == cows)
            return true;
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    int low = 1, high = 1e9, val;
    sort(stalls.begin(), stalls.end());
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (calcCows(stalls, mid, k))
        {
            val = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return val;
}
