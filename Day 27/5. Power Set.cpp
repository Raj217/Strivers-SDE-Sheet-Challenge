// https://www.codingninjas.com/studio/problems/1062667?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include <bits/stdc++.h>
using namespace std;

void gen(vector<int> &v, int i, vector<vector<int>> &ans, vector<int> &temp) {
    if (i == v.size()) {
        ans.push_back(temp);
        return;
    }

    gen(v, i+1, ans, temp);
    temp.push_back(v[i]);
    gen(v, i+1, ans, temp);
    temp.pop_back();
}
vector<vector<int>> pwset(vector<int>v)
{
    sort(v.begin(), v.end());

    vector<vector<int>> ans;
    vector<int> temp;
    gen(v, 0, ans, temp);
    return ans;
}