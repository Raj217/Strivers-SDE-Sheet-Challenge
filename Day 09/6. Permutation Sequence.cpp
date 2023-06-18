// https://leetcode.com/problems/permutation-sequence

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int fact(int n)
    {
        int pro = 1;
        while (n > 0)
        {
            pro *= n--;
        }
        return pro;
    }

public:
    string getPermutation(int n, int k)
    {
        int currPos = 0, temp, adder;
        string ans = "";
        vector<bool> isUsed(n + 1, false);

        while (currPos < k - 1)
        {
            temp = 0;
            adder = fact(n - ans.size() - 1);
            for (int num = 1; num <= n; num++)
            {
                if (!isUsed[num])
                {
                    temp += adder;
                    if (currPos + temp >= k)
                    {
                        currPos += temp - adder;
                        ans += num + '0';
                        isUsed[num] = true;
                        break;
                    }
                }
            }
        }
        for (int num = 1; num <= n; num++)
        {
            if (!isUsed[num])
            {
                ans += num + '0';
            }
        }
        return ans;
    }
};