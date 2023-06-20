// https://www.codingninjas.com/codestudio/problems/merge-k-sorted-arrays_975379?leftPanelTab=0

#include <bits/stdc++.h>
using namespace std;

vector<int> mergeKSortedArrays(vector<vector<int>> &kArrays, int k)
{
    vector<int> ans;
    vector<int> indices(k, 0);
    int elementsLeft = 0;
    for (auto v : kArrays)
    {
        elementsLeft += v.size();
    }
    while (elementsLeft--)
    {
        int minIndVec = -1;
        for (int ind = 0; ind < kArrays.size(); ind++)
        {
            if (indices[ind] < kArrays[ind].size() && (minIndVec == -1 || kArrays[ind][indices[ind]] < kArrays[minIndVec][indices[minIndVec]]))
            {
                minIndVec = ind;
            }
        }
        ans.push_back(kArrays[minIndVec][indices[minIndVec]]);
        indices[minIndVec]++;
    }
    return ans;
}
