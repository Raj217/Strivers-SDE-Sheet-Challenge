// https://www.codingninjas.com/codestudio/problems/1112581?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=1

#include <bits/stdc++.h>
using namespace std;

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    unordered_map<int, int> nextSmallest;
    stack<int> st;
    for (int i = 0; i < arr.size(); i++)
    {
        while (!st.empty() && arr[st.top()] > arr[i])
        {
            nextSmallest[st.top()] = arr[i];
            st.pop();
        }
        st.push(i);
    }
    vector<int> ans(arr.size());
    for (int i = 0; i < arr.size(); i++)
    {
        ans[i] = nextSmallest.find(i) != nextSmallest.end() ? nextSmallest[i] : -1;
    }
    return ans;
}