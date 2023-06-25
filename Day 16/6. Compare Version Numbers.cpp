// https://leetcode.com/problems/compare-version-numbers/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    int next(string &version, int &i) {
        int ver = 0;
        for (; i<version.size() && version[i] != '.'; i++) {
            ver = ver*10+(version[i]-'0');
        }
        i++;
        return ver;
    }
public:
    int compareVersion(string version1, string version2) {
       int i1 = 0, i2 = 0;
       while (i1<version1.size() || i2<version2.size()) {
           int v1 = next(version1, i1);
           int v2 = next(version2, i2);
           if (v1 < v2) return -1;
           if (v1 > v2) return 1;
       }
       return 0;
    }
};