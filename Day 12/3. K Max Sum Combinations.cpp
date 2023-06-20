// https://www.codingninjas.com/codestudio/problems/k-max-sum-combinations_975322?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include <bits/stdc++.h>
using namespace std;

vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k)
{
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    priority_queue<vector<int>> pq;

    set<pair<int, int>> usedPos;

    pq.push({a[n - 1] + b[n - 1], n - 1, n - 1});
    usedPos.insert({n - 1, n - 1});

    vector<int> ans;
    for (int count = 0; count < k; count++)
    {
        int sum = pq.top()[0];

        int i = pq.top()[1];
        int j = pq.top()[2];
        pq.pop();

        ans.push_back(sum);

        if (usedPos.find({i - 1, j}) == usedPos.end())
        {
            pq.push({a[i - 1] + b[j], i - 1, j});
            usedPos.insert({i - 1, j});
        }
        if (usedPos.find({i, j - 1}) == usedPos.end())
        {
            pq.push({a[i] + b[j - 1], i, j - 1});
            usedPos.insert({i, j - 1});
        }
    }
    return ans;
}