// https://leetcode.com/problems/largest-rectangle-in-histogram/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    vector<int> nextSmallestArray(vector<int> &heights)
    {
        int n = heights.size();
        vector<int> arr(n);
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && heights[st.top()] > heights[i])
            {
                arr[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        while (!st.empty())
        {
            arr[st.top()] = n;
            st.pop();
        }
        return arr;
    }
    vector<int> prevSmallestArray(vector<int> &heights)
    {
        int n = heights.size();
        vector<int> arr(n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && heights[st.top()] > heights[i])
            {
                arr[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        while (!st.empty())
        {
            arr[st.top()] = -1;
            st.pop();
        }
        return arr;
    }

public:
    int largestRectangleArea(vector<int> &heights)
    {
        stack<int> st;
        int n = heights.size();
        vector<int> nextSmallest = nextSmallestArray(heights);
        vector<int> prevSmallest = prevSmallestArray(heights);

        int maxArea = 0;
        for (int i = 0; i < n; i++)
        {
            int height = heights[i];
            int base = max(nextSmallest[i] - prevSmallest[i] - 1, 1);
            maxArea = max(maxArea, height * base);
        }
        return maxArea;
    }
};