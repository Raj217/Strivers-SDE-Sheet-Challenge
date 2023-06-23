// https://www.codingninjas.com/codestudio/problems/max-of-min_982935?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=1

#include <bits/stdc++.h>
using namespace std;

vector<int> prevSmaller(vector<int> &nums) {
    int n = nums.size();
    vector<int> ans(n, -1);
    stack<int> st;
    for (int i=n-1; i>=0; i--) {
        while (!st.empty() && nums[st.top()] > nums[i]) {
            ans[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    return ans;
}
vector<int> nextSmaller(vector<int> &nums) {
    int n = nums.size();
    vector<int> ans(n, n);
    stack<int> st;
    for (int i=0; i<n; i++) {
        while (!st.empty() && nums[st.top()] > nums[i]) {
            ans[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    return ans;
}
vector<int> maxMinWindow(vector<int> a, int n) {
    vector<int> nextSmallerArr = nextSmaller(a);
    vector<int> prevSmallerArr = prevSmaller(a);

    vector<int> ans(n, INT_MIN);
    for (int i = 0; i<n; i++) {
        int len = nextSmallerArr[i] - prevSmallerArr[i] - 2;
        ans[len] = max(ans[len], a[i]);
    }
    for (int i=n-2; i>=0; i--) {
        ans[i] = max(ans[i], ans[i+1]);
    }
    return ans;
}