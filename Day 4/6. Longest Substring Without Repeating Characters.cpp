#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char, int> freq;

        int maxLen = 0, len = 0;
        int left = 0, right = 0;
        while (right < s.size())
        {
            freq[s[right]]++;
            len++;
            while (freq[s[right]] == 2)
            {
                freq[s[left++]]--;
                len--;
            }
            maxLen = max(len, maxLen);
            right++;
        }
        return maxLen;
    }
};