// https://leetcode.com/problems/longest-palindromic-substring/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size(), start = 0, end = 1;
        for (int i=0; i<n; i++) {
            int left = i, right = i;
            while (right < n-1 && s[right+1] == s[right]) {
                right++;
            } 
            while (left > 0 && right < n && s[left-1] == s[right+1]) {
                left--;
                right++;
            }
            if (right - left + 1> end-start) {
                end = right+1;
                start = left;
            }
        }
        return s.substr(start, end-start);
    }
};