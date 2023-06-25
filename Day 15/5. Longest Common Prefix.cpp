// https://leetcode.com/problems/longest-common-prefix/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        string prefix;
        int i = 0;
        int n = INT_MAX;
        for (string str : strs)
        {
            if (n > str.size())
                n = str.size();
        }
        for (int i = 0; i < n; i++)
        {
            char c = strs[0][i];
            for (string str : strs)
            {
                if (c != str[i])
                {
                    return prefix;
                }
            }
            prefix.push_back(c);
        }
        return prefix;
    }
};