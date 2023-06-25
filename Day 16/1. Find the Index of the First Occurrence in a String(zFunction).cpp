// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/

#include <bits/stdc++.h>
using namespace std;

class Solution { 
    void calcZ(string &s, int &left, int &right, vector<int> &z) {
        int n = s.size();
        while (right < n && s[right] == s[right-left]) {
            right++;
        }
        z[left] = right-left;
        right--;
    }
    int zfunction(string s, int patternSize) {
        int n = s.size();
        vector<int> z(n, 0);

        int left=0, right=0;
        for (int k=1; k<n; k++) {
            // We are dealing with a single element
            if (k>right) {
                left = right = k;
                calcZ(s, left, right, z);
            } else {
                // We are dealing with the box
                int nLeft = k-left;
                if (z[nLeft] + k <= right) {
                    z[k] = z[nLeft]; 
                } else {
                    left = k;
                    calcZ(s, left, right, z);
                }
            }
            if (z[k] == patternSize) return k-patternSize-1;
        }
        return -1;
    }
public:
    int strStr(string haystack, string needle) {
        string s = needle+'$'+haystack;
        return zfunction(s, needle.size());
    }
};