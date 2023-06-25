// https://leetcode.com/problems/count-and-say/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    string say(string s) {
        int n = s.size();
        string str;
        int freq = 1, dig = s[0];
        for (int i=1; i<n; i++) {
            if (dig == s[i]) freq++;
            else {
                str += to_string(freq)+to_string(dig-'0');
                freq=1;
                dig = s[i];
            }
        } 
        str += to_string(freq)+to_string(dig-'0');
        return str;
    }
public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        return say(countAndSay(n-1));
    }
};