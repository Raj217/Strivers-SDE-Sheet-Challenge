// https://leetcode.com/problems/repeated-string-match/description/

#include <bits/stdc++.h>
using namespace std;


class Solution {
    bool rabinCarp(string a, string b) {
        unsigned long long hashCode=0, targetHash=0;
        unsigned long long MOD = ULLONG_MAX;
        unsigned long long pow = 1;
        int BASE = 26;
        for (int i=0; i<b.size()-1; i++) {
            pow = (pow*BASE)%MOD;
        }
        for (char c: b) {
            targetHash = ((targetHash*BASE)%MOD+c)%MOD;
        }
        int len = b.size();
        int left=0, right=0;
        for (; right<len; right++) {
            hashCode = ((hashCode*BASE)%MOD+a[right])%MOD;
        }
        right--;
        while (right < a.size()) {
            if (hashCode == targetHash && a.substr(left, right-left+1) == b) {
                return true;
            }
            right++;
            left++;
            hashCode -= a[left-1]*pow;
            hashCode = ((hashCode*BASE)%MOD+a[right])%MOD;
        }
        return false;
    }
public:
    int repeatedStringMatch(string a, string b) {
        string str = a;
        int count = 1;
        while (str.size() < b.size()) {
            count++;
            str += a;
        }
        if (rabinCarp(str, b)) return count;
        if (rabinCarp(str+a, b)) return count+1;
        return -1;
    }
};