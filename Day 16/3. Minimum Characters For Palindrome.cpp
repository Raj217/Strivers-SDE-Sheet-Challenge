// https://www.codingninjas.com/codestudio/problems/893000?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include <bits/stdc++.h>
using namespace std;

int minCharsforPalindrome(string str)
{
    int n = str.size();
    int low = 0;
    int high = n - 1;
    int e2 = high;
    int cnt = 0;
    while (low < high)
    {
        if (str[low] == str[high])
        {
            low++;
            high--;
        }
        else
        {
            cnt++;
            low = 0;
            e2--;
            high = e2;
        }
    }
    return cnt;
}
