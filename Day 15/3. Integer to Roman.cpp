// https://leetcode.com/problems/integer-to-roman/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    unordered_map<char, int> numMapping = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };
    int next(string &s, int &i) {
        if (s[i] == 'I') {
            if (i==s.size()-1) return numMapping[s[i]];
            else if (s[i+1] == 'V' || s[i+1] == 'X') {
                return numMapping[s[i+1]]-numMapping[s[i++]];
            }
        }
        if (s[i] == 'X') {
            if (i==s.size()-1) return numMapping[s[i]];
            else if (s[i+1] == 'L' || s[i+1] == 'C') {
                return numMapping[s[i+1]]-numMapping[s[i++]];
            }
        }
        if (s[i] == 'C') {
            if (i==s.size()-1) return numMapping[s[i]];
            else if (s[i+1] == 'D' || s[i+1] == 'M') {
                return numMapping[s[i+1]]-numMapping[s[i++]];
            }
        }
        int j = i;
        while (i<s.size()-1 && s[i] == s[i+1]) i++;
        int count = i-j+1;
        return numMapping[s[j]]*count;
    }
public:
    int romanToInt(string s) {
        int num = 0;
        for (int i=0; i<s.size(); i++) {
            int val = next(s, i);
            num = num + val;
        }
        return num;
    }
};