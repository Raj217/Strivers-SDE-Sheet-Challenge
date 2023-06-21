// https://leetcode.com/problems/valid-parentheses/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st;
        for (char c : s)
        {
            if (c == '(')
                st.push(c);
            else if (c == ')')
            {
                if (st.empty())
                    return false;
                if (st.top() == '(')
                {
                    st.pop();
                }
                else
                    return false;
            }
            else if (c == '[')
                st.push(c);
            else if (c == ']')
            {
                if (st.empty())
                    return false;
                if (st.top() == '[')
                {
                    st.pop();
                }
                else
                    return false;
            }
            else if (c == '{')
                st.push(c);
            else if (c == '}')
            {
                if (st.empty())
                    return false;
                if (st.top() == '{')
                {
                    st.pop();
                }
                else
                    return false;
            }
        }
        return st.empty();
    }
};