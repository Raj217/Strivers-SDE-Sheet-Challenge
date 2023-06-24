// https://leetcode.com/problems/string-to-integer-atoi/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool isBounded(long long n) {
        return n>=INT_MIN && n<=INT_MAX;
    }
public:
    int myAtoi(string s) {
        long long num = 0;
        int i=0, n = s.size();
        while (i<n && s[i] == ' ') i++;
        int sign = 1;
        if (s[i] == '+') i++;
        else if (s[i] == '-') {
            sign = -1;
            i++;
        }
        while (isdigit(s[i])) {
            int dig = s[i]-'0';
            i++;
            num = num*10+dig;
            if (!isBounded(num*sign)) {
                if (sign == -1) return INT_MIN;
                return INT_MAX;
            }
        }
        return sign*num;
    }
};