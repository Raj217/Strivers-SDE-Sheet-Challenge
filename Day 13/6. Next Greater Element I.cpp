// https://leetcode.com/problems/next-greater-element-i/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        stack<int> st;
        unordered_map<int, int> maxMap;
        for (int num : nums2)
        {
            while (!st.empty() && st.top() < num)
            {
                maxMap[st.top()] = num;
                st.pop();
            }
            st.push(num);
        }
        vector<int> ans;
        for (int num : nums1)
        {
            ans.push_back(maxMap.find(num) != maxMap.end() ? maxMap[num] : -1);
        }
        return ans;
    }
};