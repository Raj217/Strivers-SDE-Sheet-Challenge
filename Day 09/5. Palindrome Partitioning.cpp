// https://leetcode.com/problems/palindrome-partitioning/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    bool isPalindrome(string &s, int i, int j)
    {
        while (i < j)
        {
            if (s[i++] != s[j--])
                return false;
        }
        return true;
    }
    void gen(string &str, int i, vector<string> &v, vector<vector<string>> &ans)
    {
        if (i == str.size())
        {
            if (v.size() != 0)
            {
                ans.push_back(v);
            }
        }
        for (int j = i + 1; j <= str.size(); j++)
        {
            if (isPalindrome(str, i, j - 1))
            {
                v.push_back(str.substr(i, j - i));
                gen(str, j, v, ans);
                v.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s)
    {
        vector<string> v;
        vector<vector<string>> ans;
        gen(s, 0, v, ans);
        return ans;
    }
};