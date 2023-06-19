// https://www.codingninjas.com/codestudio/problems/1112629?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include <bits/stdc++.h>
using namespace std;

int ninjaAndLadoos(vector<int> &row1, vector<int> &row2, int m, int n, int k)
{
    int n1 = row1.size(), n2 = row2.size();
    if (n2 < n1)
        return ninjaAndLadoos(row2, row1, n, m, k);
    int low = max(0, k - n2), high = min(k, n1), cut1, cut2;

    while (low <= high)
    {
        cut1 = low + (high - low) / 2;
        cut2 = k - cut1;

        int left1 = cut1 == 0 ? INT_MIN : row1[cut1 - 1];
        int left2 = cut2 == 0 ? INT_MIN : row2[cut2 - 1];
        int right1 = cut1 == n1 ? INT_MAX : row1[cut1];
        int right2 = cut2 == n2 ? INT_MAX : row2[cut2];

        if (left1 <= right2 && left2 <= right1)
        {
            return max(left1, left2);
        }
        else if (left1 > right2)
        {
            high = cut1 - 1;
        }
        else
        {
            low = cut1 + 1;
        }
    }
}