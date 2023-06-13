// https://leetcode.com/problems/powx-n/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double myPow(double x, int n)
    {
        long long p = abs(n);
        double ans = 1;
        while (p > 0)
        {
            if (p % 2 == 0)
            {
                x *= x;
                p /= 2;
            }
            else
            {
                ans *= x;
                p--;
            }
        }
        if (n < 0)
            return 1 / ans;
        return ans;
    }
};