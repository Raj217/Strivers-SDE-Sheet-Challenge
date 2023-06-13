// https://www.codingninjas.com/codestudio/problems/1115652?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website

#include <bits/stdc++.h>
using namespace std;

int subarraysXor(vector<int> &arr, int x)
{
    unordered_map<int, int> pfxCount;
    int count = 0, xr = 0;
    pfxCount[0] = 1;
    
    for (int i=0; i<arr.size(); i++) {
        xr = xr^arr[i];
        count += pfxCount[xr^x];
        pfxCount[xr]++;
    }
    return count;
}