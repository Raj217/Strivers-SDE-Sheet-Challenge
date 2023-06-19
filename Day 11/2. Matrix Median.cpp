// https://www.codingninjas.com/codestudio/problems/873378?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include <bits/stdc++.h>
using namespace std;

int count(vector<vector<int>> &matrix, int n)
{
    int elements = 0;
    int totalElements = 0;
    for (int i = 0; i < matrix.size(); i++)
    {
        int ind = upper_bound(matrix[i].begin(), matrix[i].end(), n) - matrix[i].begin();
        elements += ind;
        totalElements += matrix.size();
    }
    return elements;
}

int getMedian(vector<vector<int>> &matrix)
{
    int low = 1, high = 1e5;
    int m = matrix.size(), n = matrix[0].size();
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int elements = count(matrix, mid);
        if (elements > (m * n) / 2)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return low;
}