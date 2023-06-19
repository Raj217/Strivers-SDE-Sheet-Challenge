// https://www.codingninjas.com/codestudio/problems/1062679?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include <bits/stdc++.h>
using namespace std;

int NthRoot(int n, int m)
{
    int low = 0, high = m;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        double val = pow(mid, n);
        if (val == m)
            return mid;
        else if (val > m)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
}